


#include "DbSvrConnection.hpp"
#include "MsgStruct.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "MsgSvrManager.hpp"
#include "UserManager.hpp"
#include "LoginUser.hpp"



#include <string>
#include <google/protobuf/message.h>




#include "validate.pb.h"

DBSvrConn* g_db_handler = nullptr;


enum class VALIDATE_STATUS
{
    SUCCESS = 0,
    FAIL    = 1,
    NO_SVR  = 2,
};



/***********************************
 *
 *
 */

DBSvrConn::DBSvrConn(io_service& io_)
  :Connection(io_)
{

}



void DBSvrConn::on_connect()
{
    m_dispatcher.register_message_callback((int)L2D::VERIFICATION,
        bind(&DBSvrConn::handle_verification, this, std::placeholders::_1));

    g_db_handler = this;
    read_head();
}


void DBSvrConn::on_recv_msg(int type_, pb_message_ptr p_msg_)
{
    cout << "Recv msg type: " << type_ << endl;
    m_dispatcher.on_message(type_, p_msg_);
}



void DBSvrConn::handle_verification (pb_message_ptr p_msg_)
{
    try
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;
        using namespace google::protobuf;

        auto descriptor = p_msg_->GetDescriptor();
        const Reflection* rf = p_msg_->GetReflection();
        const FieldDescriptor* f_id = descriptor->FindFieldByName("id");
        const FieldDescriptor* f_result = descriptor->FindFieldByName("result");



        assert(f_id && f_id->type()==FieldDescriptor::TYPE_INT64);
        assert(f_result && f_result->type()==FieldDescriptor::TYPE_BOOL);


        int64_t id = rf->GetInt64(*p_msg_, f_id);
        bool bResult = rf->GetBool(*p_msg_, f_result);

        cout << "id: " << id << "validate res: " << bResult << endl;

        IM::ValidateResult validte;
        int32_t nResult = bResult ? (int)VALIDATE_STATUS::SUCCESS : (int)VALIDATE_STATUS::FAIL;
        validte.set_result(nResult);



        // 如果验证通过
        if (bResult)
        {
            // 获得人数最少的服务器端口
            auto svr_info = MsgSvrManager::get_instance()->get_best_svr();


            if (std::get<1>(svr_info))
            {
                int nAllocatePort = std::get<0>(svr_info);
                std::cout << "allocate msgsvr port: " <<  nAllocatePort << std::endl;

                validte.set_port(to_string(nAllocatePort));
                validte.set_ip("192.168.1.22");

            }
            else
            {
                cout << "Msgsvr端口分配失败 " << endl;
                validte.set_result(static_cast<int32_t>(VALIDATE_STATUS::NO_SVR));
                validte.set_ip("");
                validte.set_port("");
            }
        }
        else
        {
            // 验证失败
        }


        CMsg packet;
        packet.encode((int)L2D::VERIFICATION, validte);


        // 获得指定用户的连接
        // 发送数据包到指定socket
        // 然后关闭连接
        LoginUser* pLoginUser = UserManager::get_instance()->get_user(id);
        if (pLoginUser == nullptr)
        {
            // error
            cout << "error! cant find user! id: " << id << endl;
            return ;
        }
        else
        {
            send_and_shutdown(packet, pLoginUser->get_conn()->socket());
        }

    }
    catch (exception& e)
    {
        cout << "# ERR: exception in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what() << endl;
    }

}


void DBSvrConn::on_disconnect()
{

}




void send_to_db (CMsg& packet_)
{
    if (g_db_handler)
        g_db_handler->send(packet_);
}




