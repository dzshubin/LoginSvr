#ifndef MsgSvrConnection_H
#define MsgSvrConnection_H


#include "Connection.hpp"
#include "MsgSvrManager.hpp"

class MsgSvrConnection: public Connection
{
public:
    MsgSvrConnection(io_service& io_);

    virtual void start() override;
    virtual void process_msg(int,string) override;


    virtual void stop_after() override;
public:
    void handle_register(string);
    void handle_update_msgsvr(string);

};

#endif // MsgSvrConnection_H
