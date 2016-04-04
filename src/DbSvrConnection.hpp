#ifndef DbSvrConnection_HPP_INCLUDED
#define DbSvrConnection_HPP_INCLUDED

#include "Connection.hpp"
#include "CMsg.hpp"
#include "MessageDispatcher.h"

#include <boost/asio/ip/tcp.hpp>

using namespace std;



class DBSvrConn: public Connection
{
public:
    DBSvrConn(io_service&);

public:
    virtual void on_connect() override;
    virtual void on_recv_msg(int, pb_message_ptr) override;
    virtual void on_disconnect() override;


private:
    void handle_verification(pb_message_ptr);

private:
    MessageDispatcher m_dispatcher;

};


void send_to_db (CMsg&);

#endif // DbSvrConnection_HPP_INCLUDED
