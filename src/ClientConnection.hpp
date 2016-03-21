#ifndef ClientConnection_HPP_INCLUDED
#define ClientConnection_HPP_INCLUDED

#include "Connection.hpp"
#include <boost/asio/ip/tcp.hpp>


class ClientConnection :public Connection
{
public:
    ClientConnection (io_service& );

public:
    virtual void start() override;
    virtual void process_msg(int, string) override;


    virtual void stop_after() override;

public:
    void handle_user_login(string);
};


void send_to_client(uint64_t, CMsg&);

#endif // ClientConnection_HPP_INCLUDED
