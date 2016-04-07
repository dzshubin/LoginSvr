#include <iostream>
#include <string>
#include <thread>

#include "ClientConn.hpp"
#include "MsgSvrConn.hpp"
#include "DbSvrConn.hpp"
#include "Server.hpp"

#include <boost/bind.hpp>
#include <boost/asio/connect.hpp>



Server* g_app = nullptr;
int Server::g_count = 1;


Server::Server(unsigned short msgsvr_port, unsigned short client_port)
  :m_io_service(),
   m_msgsvrAcc (m_io_service, ip::tcp::endpoint(ip::tcp::v4(), msgsvr_port)),
   m_ClientAcc (m_io_service, ip::tcp::endpoint(ip::tcp::v4(), client_port))

{

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

int Server::allocate_conn_id()
{
    return (g_count++) % 65535;
}





void Server::wait_client_accept()
{

    m_client_conn.reset(new ClientConn(m_io_service));

    m_ClientAcc.async_accept(m_client_conn->socket(), [this] (const err_code& ec)
        {
            if(!ec)
            {
                cout << "ADDRESS: " << m_client_conn->socket().remote_endpoint().address().to_string()
                     << "PORT: "    << m_client_conn->socket().remote_endpoint().port()    << endl;

                int conn_id = allocate_conn_id();
                m_client_conn->connect(conn_id);

            }
            wait_client_accept();
        });
}

void Server::wait_msgsvr_accept()
{
    m_msgsvr_conn.reset(new MsgSvrConn(m_io_service));

    m_msgsvrAcc.async_accept(m_msgsvr_conn->socket(), [this] (const err_code& ec)
        {
            if(!ec)
            {
                cout << "address: " << m_msgsvr_conn->socket().remote_endpoint().address().to_string()
                     << "port: "    << m_msgsvr_conn->socket().remote_endpoint().port()    << endl;

                int conn_id = allocate_conn_id();
                m_msgsvr_conn->connect(conn_id);

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


    m_db_conn.reset(new DBSvrConn(m_io_service));

    async_connect(m_db_conn->socket(), it,
        [this] (const err_code& ec, ip::tcp::resolver::iterator it )
        {
            if (!ec)
            {
                cout << "connect db!" << endl;
                int conn_id = allocate_conn_id();
                m_db_conn->connect(conn_id);

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

