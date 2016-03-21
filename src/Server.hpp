#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/noncopyable.hpp>


#include "Connection.hpp"


using namespace std;
using namespace boost::asio;

class Server: private boost::noncopyable
{
public:
   explicit Server(unsigned short msgsvr_port, unsigned short client_port);

public:
    // 初始化
    void initialization ();
    //异步接受客户端的连接
    void wait_client_accept ();
    //异步接受msgsvr的连接
    void wait_msgsvr_accept ();
    //异步连接到dbsvr
    void connect_to_DB ();

    void run();


private:
    io_service m_io_service;


    connection_ptr m_msgsvr_conn;
    connection_ptr m_db_conn;
    connection_ptr m_client_conn;

    ip::tcp::acceptor m_msgsvrAcc;
    ip::tcp::acceptor m_ClientAcc;
};



#endif // SERVER_HPP_INCLUDED
