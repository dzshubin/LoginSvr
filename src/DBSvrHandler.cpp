


#include "DBSvrHandler.hpp"
#include "MsgStruct.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "ConnManager.hpp"
#include "MsgSvrManager.hpp"

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


void DBSvrHandler::process_msg(int type_,string /**/)
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

    // 如果验证通过
    if (validate_result.m_bResult)
    {
        // 获得人数最少的服务器端口
        auto svr_info = MsgSvrManager::get_instance()->get_best_svr();


        if (std::get<1>(svr_info))
        {
            int nAllocatePort = std::get<0>(svr_info);
            std::cout << "allocate msgsvr port: " <<  nAllocatePort << std::endl;

            validate.set_port(to_string(nAllocatePort));
            validate.set_ip("127.0.0.1");
        }
        else
        {
            std::cout << "Msgsvr端口分配失败 " << std::endl;
            return ;
        }
    }
    else
    {

    }

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
}




void send_to_db (CMsg& packet_)
{
    if (g_db_handler)
        g_db_handler->send_msg(packet_);
}




