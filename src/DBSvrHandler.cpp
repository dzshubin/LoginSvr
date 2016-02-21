


#include "DBSvrHandler.hpp"
#include "MsgStruct.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "ConnManager.hpp"

#include <string>

#include "validate.pb.h"

DBSvrHandler* g_db_handler = nullptr;


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
    read_head_from_socket();
}


void DBSvrHandler::process_msg(int type_)
{
    switch (type_)
    {
    case (int)L2D::Verification:
        handle_verification();
        break;

    default:
        cout << "invalid type!" <<endl;
        break;

    }

}



void DBSvrHandler::handle_verification ()
{
    Msg_validate_result validate_result;
    deserialization(validate_result, m_rBuf);


    IM::Validate validate;
    validate.set_result(validate_result.m_bResult);
    validate.set_ip(validate_result.m_strIp);
    validate.set_port(validate_result.m_strPort);


    string validate_info;
    validate.SerializeToString(&validate_info);

    CMsg packet;
    packet.set_msg_type(static_cast<int>(L2D::Verification));
    packet.set_serialize_string(validate_info);


    Conn_t* conn_ = ConnManager::get_instance()->get_conn(validate_result.m_nUserId);
    if (conn_ != nullptr)
    {
        send_msg(conn_->m_socket, packet);
    }
    else
    {
        cout << "invalid conn!" << endl;
    }


//    // 获得人数最少的服务器端口
//    auto svr_info = MsgSvrManager::get_instance()->get_best_svr();
//
//
//    if (std::get<1>(svr_info))
//    {
//        int nAllocatePort = std::get<0>(svr_info);
//        std::cout << "allocate msgsvr port: " <<  nAllocatePort << std::endl;
//        Msg_msgsvr_allocate allocate;
//        allocate.m_port = nAllocatePort;
//
//        CMsg port_allocate;
//        port_allocate.set_msg_type((int)C2L::UserLogin);
//        port_allocate.set_send_data(allocate);
//
//        send_msg(port_allocate);
//    }
//    else
//    {
//        std::cout << "error." << std::endl;
//    }
}




void send_to_db (CMsg& packet_)
{
    if (g_db_handler)
        g_db_handler->send_msg(packet_);
}




