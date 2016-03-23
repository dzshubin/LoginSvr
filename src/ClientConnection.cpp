

#include "ClientConnection.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "MsgSvrManager.hpp"
#include "MsgStruct.hpp"
#include "DbSvrConnection.hpp"
#include "LoginUser.hpp"
#include "UserManager.hpp"


#include "login.pb.h"
#include "validate.pb.h"

ClientConnection::ClientConnection(io_service& io_)
  :Connection(io_)
{

}


void ClientConnection::start()
{
    read_head();
}



void ClientConnection::process_msg(int type_, string buf_)
{
    switch (type_)
    {
    case (int)C2L::USER_LOGIN:
        handle_user_login(buf_);
        break;
    default:
        std::cout << "invalid msg type!" << std::endl;
        break;
    }
}



void ClientConnection::handle_user_login(string trans_data)
{

    // 账号密码验证
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    using namespace google::protobuf;

    cout << "buf: " << trans_data.c_str() << "size：" << trans_data.size()<<endl;

    // namelen
    int32_t name_len = AsInt32(trans_data.c_str());
    cout << "name_len: " << name_len << endl;

    // type name
    const char* chr_name = trans_data.c_str() + sizeof(int32_t);
    string type_name = string(chr_name, name_len);
    cout << "type_name: " << type_name << endl;

    shared_ptr<google::protobuf::Message> p_ms = CreateMessage(type_name);

    if (p_ms == nullptr)
    {
        cout << "fail!" << endl;
        return;
    }

    // 反序列化
    int size = trans_data.size();
    p_ms->ParseFromArray(trans_data.c_str() + sizeof(int32_t) + name_len,
                       size - sizeof(int32_t)-name_len);


    const Reflection* rf = p_ms->GetReflection();
    const FieldDescriptor* f_id = p_ms->GetDescriptor()->FindFieldByName("id");
    const FieldDescriptor* f_passwd = p_ms->GetDescriptor()->FindFieldByName("passwd");


    int64_t id;
    string passwd;

    try
    {
        id = rf->GetInt64(*p_ms, f_id);
        cout << id  << endl;

        passwd = rf->GetString(*p_ms, f_passwd);
        cout << passwd << endl;
    }
    catch (exception& e)
    {
        cout << "# ERR: exception in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
    }



    LoginUser* pLoginUser = UserManager::get_instance()->get_user(id);

    if (pLoginUser == nullptr)
    {
        // add
        pLoginUser = new LoginUser;
        auto self = shared_from_this();

        pLoginUser->set_conn(self);
        pLoginUser->set_id(id);
        pLoginUser->set_conn_id(self->get_id());

        UserManager::get_instance()->insert(pLoginUser);
    }


    Msg_login login_info;
    login_info.m_nId = id;
    login_info.m_passwd = passwd;

    CMsg packet;
    packet.set_msg_type(static_cast<int>(L2D::VERIFICATION));
    packet.serialization_data_Asio(login_info);
    send_to_db (packet);
}



/*****************************
 *
 *
 */

void ClientConnection::stop_after()
{

}

