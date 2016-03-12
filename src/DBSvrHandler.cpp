


#include "DBSvrHandler.hpp"
#include "MsgStruct.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "ConnManager.hpp"
#include "MsgSvrManager.hpp"

#include <string>

#include "validate.pb.h"

DBSvrHandler* g_db_handler = nullptr;


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

DBSvrHandler::DBSvrHandler(boost::asio::ip::tcp::socket sock_)
  :Handler(std::move(sock_))
{


}



void DBSvrHandler::start()
{
    g_db_handler = this;
    read_head();
}


void DBSvrHandler::process_msg(int type_,string buf_)
{
    switch (type_)
    {
    case (int)L2D::Verification:
        handle_verification(buf_);
        break;

    default:
        cout << "invalid type!" <<endl;
        break;

    }

}



void DBSvrHandler::handle_verification (string buf_)
{

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    Msg_validate_result s2s_validate;
    deserialization(s2s_validate, buf_);


    IM::ValidateResult s2c_validate;
    int32_t result = static_cast<int32_t>(s2s_validate.m_bResult ?
                                          VALIDATE_STATUS::SUCCESS :
                                          VALIDATE_STATUS::FAIL);
    s2c_validate.set_result(result);


    // 如果验证通过
    if (s2s_validate.m_bResult)
    {
        // 获得人数最少的服务器端口
        auto svr_info = MsgSvrManager::get_instance()->get_best_svr();


        if (std::get<1>(svr_info))
        {
            int nAllocatePort = std::get<0>(svr_info);
            std::cout << "allocate msgsvr port: " <<  nAllocatePort << std::endl;

            s2c_validate.set_port(to_string(nAllocatePort));
            s2c_validate.set_ip("192.168.1.22");

        }
        else
        {
            std::cout << "Msgsvr端口分配失败 " << std::endl;
            s2c_validate.set_result(static_cast<int32_t>(VALIDATE_STATUS::NO_SVR));
            s2c_validate.set_ip("");
            s2c_validate.set_port("");
        }
    }
    else
    {
        // 验证失败
    }

//
    CMsg packet;
    packet.set_msg_type(static_cast<int>(L2D::Verification));
    packet.serialization_data_protobuf(s2c_validate);


    Conn_t* conn_ = ConnManager::get_instance()->get_conn(s2s_validate.m_nUserId);
    if (conn_ != nullptr)
    {
        send(packet, conn_->m_socket);
    }
    else
    {
        cout << "invalid conn!" << endl;
    }

    //google::protobuf::ShutdownProtobufLibrary();
}




void send_to_db (CMsg& packet_)
{
    if (g_db_handler)
        g_db_handler->send(packet_);
}




