#ifndef MSGSVRCONN_HPP_INCLUDED
#define MSGSVRCONN_HPP_INCLUDED


#include "Connection.hpp"
#include "MessageDispatcher.h"

class MsgSvrConn: public Connection
{
public:
    MsgSvrConn(io_service& io_);

    virtual void on_connect() override;
    virtual void on_recv_msg(int, pb_message_ptr) override;
    virtual void on_disconnect() override;



private:
    void handle_register(pb_message_ptr);
    void handle_update_msgsvr(pb_message_ptr);
    // 查询玩家是否已经在线
    void handle_lookup(pb_message_ptr);


private:
    MessageDispatcher m_dispatcher;

};


void send_to_msgsvr(CMsg&);

#endif // MSGSVRCONN_HPP_INCLUDED
