#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace boost::asio;

class Server
{

public:
   Server(io_service& io, unsigned short msgsvr_port, unsigned short client_port);

private:

    // 初始化
    void initialization ();
    //异步接受客户端的连接
    void wait_client_accpet ();
    //异步接受msgsvr的连接
    void wait_msgsvr_accept ();
    //异步连接到dbsvr
    void connect_to_DB ();


private:
    ip::tcp::socket   m_ClientSock;
    ip::tcp::socket   m_MsgSock;
    ip::tcp::socket   m_DBSock;

    ip::tcp::acceptor m_msgsvrAcc;
    ip::tcp::acceptor m_ClientAcc;
};



#endif // SERVER_HPP_INCLUDED
