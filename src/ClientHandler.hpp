#ifndef CLIENTHANDLER_HPP_INCLUDED
#define CLIENTHANDLER_HPP_INCLUDED

#include "Handler.hpp"
#include <boost/asio/ip/tcp.hpp>

class ClientHandler :public Handler
{
public:
    ClientHandler (boost::asio::ip::tcp::socket);

public:
    virtual void start() override;
    virtual void process_msg(int) override;


public:
    void handle_UserLogin();
};


void send_to_client(uint64_t, CMsg&);

#endif // CLIENTHANDLER_HPP_INCLUDED
