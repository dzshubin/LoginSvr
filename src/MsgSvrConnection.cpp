#include "MsgSvrConnection.hpp"
#include "MsgStruct.hpp"
#include "MsgSvrManager.hpp"
#include "ClientMsgTypeDefine.hpp"



#include <google/protobuf/message.h>


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
