#ifndef CLIENTCONN_HPP_INCLUDED
#define CLIENTCONN_HPP_INCLUDED

#include "Connection.hpp"
#include "MessageDispatcher.h"
#include <boost/asio/ip/tcp.hpp>


class ClientConn :public Connection
{
public:
    ClientConn (io_service& );

public:
    virtual void on_connect() override;
    virtual void on_recv_msg(int, pb_message_ptr) override;
    virtual void on_disconnect() override;

public:
    void handle_user_login(pb_message_ptr);


private:
    MessageDispatcher m_dispatcher;
};


#endif // CLIENTCONN_HPP_INCLUDED
