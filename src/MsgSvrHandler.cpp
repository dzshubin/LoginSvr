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
    read_head_from_socket();
}

void MsgSvrHandler::process_msg(int type_,string)
{
    std::cout << "type: " << type_ << std::endl;
    switch (type_)
    {
    case (int)M2L::Register:
        handle_register();
        break;
    case (int)M2L::UpdateMsgSvr:
        handle_UpdateMsgSvr();
        break;
    }
}


void MsgSvrHandler::handle_register()
{
    Msg_msgsvr_register register_msg;
    deserialization(register_msg, m_rBuf);

    std::cout<< "register port: " << register_msg.m_port << std::endl;
    MsgSvrManager::get_instance()->insert_msgsvr(this, register_msg.m_port);
}

void MsgSvrHandler::handle_UpdateMsgSvr()
{
    Msg_update_count update;
    deserialization(update, m_rBuf);

    std::cout<< "new count: " << update.m_user_count << std::endl;
    MsgSvrManager::get_instance()->set_user_count(this, update.m_user_count);
}
