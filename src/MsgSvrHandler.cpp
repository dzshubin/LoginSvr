#include "MsgSvrHandler.h"
#include "MsgStruct.hpp"
#include "ClientMsgTypeDefine.hpp"


MsgSvrHandler::MsgSvrHandler(ip::tcp::socket sock_)
  :Handler(std::move(sock_))
{
    //ctor
}


void MsgSvrHandler::start()
{
    std::cout << "msgsvrhandler start " << std::endl;
    read_head();
}

void MsgSvrHandler::process_msg(int type_,string buf_)
{
    std::cout << "type: " << type_ << std::endl;
    switch (type_)
    {
    case (int)M2L::Register:
        handle_register(buf_);
        break;
    case (int)M2L::UpdateMsgSvr:
        handle_update_msgsvr(buf_);
        break;
    }
}


void MsgSvrHandler::handle_register(string buf_)
{
    Msg_msgsvr_register msgsvr;
    deserialization(msgsvr, buf_);

    std::cout<< "register port: " << msgsvr.m_port << std::endl;
    MsgSvrManager::get_instance()->insert_msgsvr(this, msgsvr.m_port);

}

void MsgSvrHandler::handle_update_msgsvr(string buf_)
{
    Msg_update_count update;
    deserialization(update, buf_);

    std::cout<< "new count: " << update.m_user_count << std::endl;
    MsgSvrManager::get_instance()->set_user_count(this, update.m_user_count);
}
