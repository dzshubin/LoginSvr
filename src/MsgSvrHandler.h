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



    void handle_register();
    void handle_UpdateMsgSvr();

};

#endif // MSGSVRHANDLER_H
