

#include "ClientHandler.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "MsgSvrManager.hpp"
#include "MsgStruct.hpp"
#include "ConnManager.hpp"
#include "DBSvrHandler.hpp"


#include "login.pb.h"

ClientHandler::ClientHandler(boost::asio::ip::tcp::socket sock_)
  :Handler(std::move(sock_))
{

}


void ClientHandler::start()
{
    read_head_from_socket();
}


void ClientHandler::process_msg(int type_)
{
    switch (type_)
    {
    case (int)C2L::UserLogin:
        handle_UserLogin();
        break;
    default:
        std::cout << "invalid msg type!" << std::endl;
        break;
    }
}



void ClientHandler::handle_UserLogin()
{

    // 账号密码验证
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    IM::LoginAccount account;
    parse_pb_message(account, m_rBuf);


    ConnManager::get_instance()->insert_conn(account.id(), m_sock);

    Msg_login login_info;
    login_info.m_nId = account.id();
    login_info.m_passwd = account.passwd();

    CMsg packet;
    packet.set_msg_type(static_cast<int>(L2D::Verification));
    packet.set_send_data(login_info);

    send_to_db (packet);

    google::protobuf::ShutdownProtobufLibrary();
}



/*****************************
 *
 *
 */


void send_to_client(uint64_t id_, CMsg& packet_)
{
    Conn_t* conn = ConnManager::get_instance()->get_conn(id_);
    if (conn != nullptr)
    {

    }

    else
    {
        cout << "not found id!" << endl;
    }

}

