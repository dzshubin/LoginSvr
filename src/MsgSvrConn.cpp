#include "MsgSvrConn.hpp"
#include "MsgStruct.hpp"
#include "MsgSvrManager.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "LoginUser.hpp"
#include "UserManager.hpp"
#include "DbSvrConn.hpp"


#include <google/protobuf/message.h>

#include "login.pb.h"
#include "validate.pb.h"

MsgSvrConn* g_msgsvr_handler = nullptr;

MsgSvrConn::MsgSvrConn(io_service& io_)
  :Connection(io_)
{
    //ctor

}


void MsgSvrConn::on_connect()
{

    m_dispatcher.register_message_callback((int)M2L::REGISTER,
        bind(&MsgSvrConn::handle_register, this, std::placeholders::_1));

    m_dispatcher.register_message_callback((int)M2L::UPDATE_SVR_COUNT,
        bind(&MsgSvrConn::handle_update_msgsvr, this, std::placeholders::_1));

    m_dispatcher.register_message_callback((int)M2L::LOOKUP,
        bind(&MsgSvrConn::handle_lookup, this, std::placeholders::_1));



    g_msgsvr_handler = this;
    read_head();
}


void MsgSvrConn::on_disconnect()
{
    // 删除这个msg服务器
    bool result = MsgSvrManager::get_instance()->remove(get_conn_id());

}


void MsgSvrConn::on_recv_msg(int type_, pb_message_ptr p_msg_)
{
    std::cout << "Recv msg type: " << type_ << std::endl;
    m_dispatcher.on_message(type_, p_msg_);
}


void MsgSvrConn::handle_register(pb_message_ptr p_msg)
{
    try
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;
        using namespace google::protobuf;


        auto descriptor = p_msg->GetDescriptor();
        const Reflection* rf = p_msg->GetReflection();
        const FieldDescriptor* f_port = descriptor->FindFieldByName("port");


        assert(f_port && f_port->type()==FieldDescriptor::TYPE_INT32);


        int32_t port = rf->GetInt32(*p_msg, f_port);
        cout<< "register port: " << port << endl;


        CMsgSvr* pSvr = MsgSvrManager::get_instance()->get_svr(port);
        if (pSvr == nullptr)
        {
            pSvr = new CMsgSvr;
            pSvr->set_port(port);
            pSvr->set_conn(shared_from_this());

            MsgSvrManager::get_instance()->insert(pSvr);
        }

    }
    catch (exception& e)
    {
        cout << "# ERR: exception in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
    }
}

void MsgSvrConn::handle_update_msgsvr(pb_message_ptr p_msg)
{
    try
    {

        GOOGLE_PROTOBUF_VERIFY_VERSION;
        using namespace google::protobuf;


        auto descriptor = p_msg->GetDescriptor();
        const Reflection* rf = p_msg->GetReflection();
        const FieldDescriptor* f_count = descriptor->FindFieldByName("count");


        assert(f_count && f_count->type()==FieldDescriptor::TYPE_INT32);



        int32_t nCount = rf->GetInt32(*p_msg, f_count);
        cout<< "update! New count: " << nCount << endl;


        CMsgSvr* pSvr = MsgSvrManager::get_instance()->get_svr(get_conn_id());
        if (pSvr == nullptr)
        {
            cout << "Cant find msgsvr! conn_id: " << get_conn_id() << endl;
            return ;
        }
        else
        {
            pSvr->set_user_count(nCount);
        }

    }
    catch (exception& e)
    {
        cout << "# ERR: exception in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
    }

}


void MsgSvrConn::handle_lookup(pb_message_ptr p_msg_)
{

    TRY

        auto descriptor = p_msg_->GetDescriptor();
        const Reflection* rf = p_msg_->GetReflection();
        const FieldDescriptor* f_id = descriptor->FindFieldByName("id");
        const FieldDescriptor* f_logined = descriptor->FindFieldByName("is_logined");


        assert(f_id && f_id->type()==FieldDescriptor::TYPE_INT64);
        assert(f_logined && f_logined->type()==FieldDescriptor::TYPE_INT32);


        int64_t id = rf->GetInt64(*p_msg_, f_id);
        int32_t is_logined = rf->GetInt32(*p_msg_, f_logined);




        LoginUser* pLoginUser = UserManager::get_instance()->get_user(id);
        if (pLoginUser == nullptr)
        {
            // error
            cout << "error! cant find user! id: " << id << endl;
            return ;
        }

        /// 已经登陆
        if (is_logined == 1)
        {
            cout << "user id: " << id << "is logined!" <<  endl;

            IM::ValidateResult result;
            result.set_result(3);

            CMsg packet;
            packet.encode((int)L2D::VERIFICATION, result);


        // 获得指定用户的连接
        // 发送数据包到指定socket
        // 然后关闭连接
            send_and_shutdown(packet, pLoginUser->get_conn()->socket());

        }
        else
        {
            IM::Account account;
            account.set_id(id);
            account.set_passwd(pLoginUser->passwd());

            CMsg packet;
            packet.encode((int)L2D::VERIFICATION, account);
            send_to_db (packet);
        }



    CATCH

}







void send_to_msgsvr(CMsg& packet)
{
    if (g_msgsvr_handler)
    {
        g_msgsvr_handler->send(packet);
    }

}












