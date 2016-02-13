#include <iostream>
#include <string>

#include "ClientHandler.hpp"
#include "MsgSvrHandler.h"
#include "Server.hpp"



Server::Server(io_service& io, unsigned short msgsvr_port, unsigned short client_port)
  :m_ClientSock (io), m_MsgSock (io), m_DBSock (io),
   m_msgsvrAcc (io, ip::tcp::endpoint(ip::tcp::v4(), msgsvr_port)),
   m_ClientAcc (io, ip::tcp::endpoint(ip::tcp::v4(), client_port))

{
    initialization();
}



void Server::initialization ()
{
    wait_client_accpet();
    wait_msgsvr_accept();
    //connect_to_DB();
}


void Server::wait_client_accpet()
{
    m_ClientAcc.async_accept(m_ClientSock,
            [this] (const boost::system::error_code& ec)
            {
                if(!ec)
                {
                    std::cout << "address: " << m_ClientSock.remote_endpoint().address().to_string()
                              << "port: "    << m_ClientSock.remote_endpoint().port()    << std::endl;

                    // start for client
                    std::make_shared<ClientHandler>(std::move(m_ClientSock))->start();

                }
                else
                {
                    std::cerr << "client accept error." << std::endl;
                }

                wait_client_accpet();
            });
}

void Server::wait_msgsvr_accept()
{
    m_msgsvrAcc.async_accept(m_MsgSock,
        [this] (boost::system::error_code ec)
        {
            if(!ec)
            {
                std::cout << "address: " << m_MsgSock.remote_endpoint().address().to_string()
                          << "port: "    << m_MsgSock.remote_endpoint().port()    << std::endl;

                // start for msgsvr
                std::make_shared<MsgSvrHandler>(std::move(m_MsgSock))->start();

            }
            else
            {
                std::cerr << "client accept error." << std::endl;
            }

            wait_msgsvr_accept();
        });
}

void Server::connect_to_DB()
{
    std::string address = "127.0.0.1";
    std::string port  = "9700";

    ip::tcp::resolver resolver(m_ClientSock.get_io_service());
    ip::tcp::endpoint ep = *resolver.resolve({address, port});

    m_DBSock.async_connect(ep,
            [this] (const boost::system::error_code& ec )
            {
                if (!ec)
                {
                    // start for db
                }
                else
                {
                    std::cout << "error. try connect db..." << std::endl;
                    boost::asio::deadline_timer t(m_ClientSock.get_io_service(), boost::posix_time::seconds(5));
                    t.wait();
                    connect_to_DB();
                }
            });
}

