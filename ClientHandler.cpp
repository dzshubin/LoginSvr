

#include "ClientHandler.hpp"
#include "ClientMsgTypeDefine.hpp"
#include "MsgSvrManager.hpp"
#include "MsgStruct.hpp"

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

    // 获得人数最少的服务器端口
    auto svr_info = MsgSvrManager::get_instance()->get_best_svr();


    if (std::get<1>(svr_info))
    {
        int nAllocatePort = std::get<0>(svr_info);
        std::cout << "allocate msgsvr port: " <<  nAllocatePort << std::endl;
        Msg_msgsvr_allocate allocate;
        allocate.m_port = nAllocatePort;

        CMsg port_allocate;
        port_allocate.set_msg_type((int)C2L::UserLogin);
        port_allocate.set_send_data(allocate);

        send_msg(port_allocate);
    }
    else
    {
        std::cout << "error." << std::endl;
    }
}
