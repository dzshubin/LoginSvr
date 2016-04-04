

#include "MsgSvrManager.hpp"
#include <algorithm>
#include <iostream>


MsgSvrManager::MsgSvrManager()
{

}

MsgSvrManager::~MsgSvrManager()
{

    for_each(m_svrs.begin(), m_svrs.end(),
        [] (CMsgSvr* pUser)
        {
            delete pUser;
        });
}

MsgSvrManager* MsgSvrManager::get_instance()
{
    static MsgSvrManager manager;
    return &manager;
}

void MsgSvrManager::insert(CMsgSvr* pMsgsvr)
{
    std::cout <<"size: " << m_svrs.size() << std::endl;
    m_svrs.insert(pMsgsvr);

    std::cout <<"size: " << m_svrs.size() << std::endl;
}


bool MsgSvrManager::remove(int id_)
{

    auto it = find_if(m_svrs.begin(), m_svrs.end(),
        [&] (CMsgSvr* svr_)
        {
            return svr_->get_conn()->get_conn_id() == id_;
        } );

    if (it == m_svrs.end())
    {
        return false;
    }
    else
    {
        m_svrs.erase(it);
        (*it)->free_conn();
        delete (*it);

        return true;
    }
}


std::tuple<int, bool> MsgSvrManager::get_best_svr()
{
    auto it = std::min_element(m_svrs.begin(), m_svrs.end());

    if (it == m_svrs.end())
    {
        // error
        // no msgsvr
        return std::make_tuple(0, false);
    }
    return std::make_tuple( (*it)->get_port(), true);
}


CMsgSvr* MsgSvrManager::get_svr(int conn_id_)
{

    auto it = find_if(m_svrs.begin(), m_svrs.end(),
        [&] (CMsgSvr* pSvr)
        {
            return pSvr->get_conn()->get_conn_id() == conn_id_;
        });

    return it == m_svrs.end() ? nullptr : *it;
}


