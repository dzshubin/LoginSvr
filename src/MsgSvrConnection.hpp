#ifndef MSGSVRHANDLER_H
#define MSGSVRHANDLER_H


#include "Handler.hpp"
#include "MsgSvrManager.hpp"

class MsgSvrHandler :public Handler
{
public:
    MsgSvrHandler(ip::tcp::socket);

    virtual void start() override;
    virtual void process_msg(int,string) override;


public:
    void handle_register(string);
    void handle_update_msgsvr(string);

};

#endif // MSGSVRHANDLER_H
