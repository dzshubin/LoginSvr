#include "MsgSvrConnection.hpp"
#include "MsgStruct.hpp"
#include "ClientMsgTypeDefine.hpp"


MsgSvrConnection::MsgSvrConnection(io_service& io_)
  :Connection(io_)
{
    //ctor
}


void MsgSvrConnection::start()
{
    std::cout << "MsgSvrConnection start " << std::endl;
    read_head();
}


void MsgSvrConnection::stop_after()
{

    // 删除这个msg服务器
    bool result = MsgSvrManager::get_instance()->remove(get_id());
}


void MsgSvrConnection::process_msg(int type_,string buf_)
{
    std::cout << "type: " << type_ << std::endl;
    switch (type_)
    {
    case (int)M2L::REGISTER:
        handle_register(buf_);
        break;
    case (int)M2L::UPDATE_SVR_COUNT:
        handle_update_msgsvr(buf_);
        break;
    }
}


void MsgSvrConnection::handle_register(string buf_)
{
    Msg_msgsvr_register msgsvr;
    deserialization(msgsvr, buf_);

    std::cout<< "register port: " << msgsvr.m_port << std::endl;
    //MsgSvrManager::get_instance()->insert_msgsvr(this, msgsvr.m_port);

    CMsgSvr* pSvr = MsgSvrManager::get_instance()->get_svr(msgsvr.m_port);
    if (pSvr == nullptr)
    {
        pSvr = new CMsgSvr;
        pSvr->set_port(msgsvr.m_port);
        pSvr->set_conn(shared_from_this());

        MsgSvrManager::get_instance()->insert(pSvr);
    }
}

void MsgSvrConnection::handle_update_msgsvr(string buf_)
{
    Msg_update_count update;
    deserialization(update, buf_);

    cout<< "new count: " << update.m_user_count << endl;

    CMsgSvr* pSvr = MsgSvrManager::get_instance()->get_svr(get_id());
    if (pSvr == nullptr)
    {
        // error
        return ;
    }
    else
    {
        pSvr->set_user_count(update.m_user_count);
    }
}
