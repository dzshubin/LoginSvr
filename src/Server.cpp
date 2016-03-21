#include <iostream>
#include <string>
#include <thread>

#include "ClientConnection.hpp"
#include "MsgSvrConnection.hpp"
#include "DbSvrConnection.hpp"
#include "Server.hpp"

#include <boost/bind.hpp>
#include <boost/asio/connect.hpp>


Server::Server(unsigned short msgsvr_port, unsigned short client_port)
  :m_io_service(),
   m_msgsvrAcc (m_io_service, ip::tcp::endpoint(ip::tcp::v4(), msgsvr_port)),
   m_ClientAcc (m_io_service, ip::tcp::endpoint(ip::tcp::v4(), client_port))

{
    initialization();
}



void Server::initialization ()
{
    wait_client_accept();
    wait_msgsvr_accept();
    connect_to_DB();
}


void Server::run()
{
    // 线程池大小
    std::size_t threads_pool_size = 4;


    vector<shared_ptr<std::thread>> threads;
    for(int i = 0; i < threads_pool_size; i++)
    {
        shared_ptr<std::thread> thread(new std::thread(
            boost::bind(&io_service::run, &m_io_service)));
        threads.push_back(thread);
    }


    // 等待所有线程结束
    for_each(threads.begin(), threads.end(),
        [] (shared_ptr<std::thread> ptr)
        {
            ptr->join();
        });
}

void Server::wait_client_accept()
{

    m_client_conn.reset(new ClientConnection(m_io_service));

    m_ClientAcc.async_accept(m_client_conn->socket(), [this] (const boost::system::error_code& ec)
        {
            if(!ec)
            {
                cout << "ADDRESS: " << m_client_conn->socket().remote_endpoint().address().to_string()
                     << "PORT: "    << m_client_conn->socket().remote_endpoint().port()    << endl;

                m_client_conn->on_connect();

            }
            wait_client_accept();
        });
}

void Server::wait_msgsvr_accept()
{
    m_msgsvr_conn.reset(new MsgSvrConnection(m_io_service));

    m_msgsvrAcc.async_accept(m_msgsvr_conn->socket(), [this] (const boost::system::error_code& ec)
        {
            if(!ec)
            {
                cout << "address: " << m_msgsvr_conn->socket().remote_endpoint().address().to_string()
                     << "port: "    << m_msgsvr_conn->socket().remote_endpoint().port()    << endl;
                m_msgsvr_conn->on_connect();

            }

            wait_msgsvr_accept();
        });
}

void Server::connect_to_DB()
{
    string address = "127.0.0.1";
    string port  = "11000";

    ip::tcp::resolver resolver(m_io_service);
    ip::tcp::resolver::iterator it = resolver.resolve({address, port});


    m_db_conn.reset(new DbSvrConnection(m_io_service));

    async_connect(m_db_conn->socket(), it,
        [this] (const boost::system::error_code& ec, ip::tcp::resolver::iterator it )
        {
            if (!ec)
            {
                cout << "connect db!" << endl;
                m_db_conn->on_connect();

            }
            else
            {
                cout << "error. try connect db..." << endl;
                boost::asio::deadline_timer t(m_io_service, boost::posix_time::seconds(5));
                t.wait();
                connect_to_DB();
            }
        });
}

