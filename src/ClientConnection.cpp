
#include <functional>


#include "ClientConnection.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "MsgSvrManager.hpp"
#include "MsgStruct.hpp"
#include "DbSvrConnection.hpp"
#include "LoginUser.hpp"
#include "UserManager.hpp"


#include "login.pb.h"
#include "validate.pb.h"

#include <google/protobuf/message.h>


ClientConn::ClientConn(io_service& io_)
  :Connection(io_)
{
}


void ClientConn::on_connect()
{

    m_dispatcher.register_message_callback((int)C2L::USER_LOGIN,
        bind(&ClientConn::handle_user_login, this, std::placeholders::_1));

    // 开始读取信息
    read_head();
}



void ClientConn::on_recv_msg(int type_, pb_message_ptr p_message_)
{
    cout << "Recv msg type: " << type_ << endl;
    m_dispatcher.on_message(type_, p_message_);
}




void ClientConn::on_disconnect()
{
    // 找到玩家
    bool result = UserManager::get_instance()->delete_related_user(get_conn_id());
}




/*********************************************************
 *
 *
 */


void ClientConn::handle_user_login(pb_message_ptr p_msg)
{
    try
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;
        using namespace google::protobuf;


        auto descriptor = p_msg->GetDescriptor();
        const Reflection* rf = p_msg->GetReflection();
        const FieldDescriptor* f_id = descriptor->FindFieldByName("id");
        const FieldDescriptor* f_passwd = descriptor->FindFieldByName("passwd");


        assert(f_id && f_id->type()==FieldDescriptor::TYPE_INT64);
        assert(f_passwd && f_passwd->type()==FieldDescriptor::TYPE_STRING);


        int64_t id = rf->GetInt64(*p_msg, f_id);
        cout << "id: " << id  << endl;

        string passwd = rf->GetString(*p_msg, f_passwd);
        cout << "passwd: " << passwd << endl;


        LoginUser* pLoginUser = UserManager::get_instance()->get_user(id);

        if (pLoginUser == nullptr)
        {
            // add
            pLoginUser = new LoginUser;
            auto self = shared_from_this();

            pLoginUser->set_conn(self);
            pLoginUser->set_id(id);
            pLoginUser->set_conn_id(self->get_conn_id());

            UserManager::get_instance()->insert(pLoginUser);
        }

        IM::Account account;
        account.set_id(id);
        account.set_passwd(passwd);

        CMsg packet;
        packet.encode((int)L2D::VERIFICATION, account);
        send_to_db (packet);


    }
    catch (exception& e)
    {
        cout << "# ERR: exception in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
    }
}






