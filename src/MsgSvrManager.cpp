

#include "MsgSvrManager.hpp"
#include <algorithm>
#include <iostream>


MsgSvrManager::MsgSvrManager()
{

}


MsgSvrManager* MsgSvrManager::get_instance()
{
    static MsgSvrManager manager;
    return &manager;
}

void MsgSvrManager::insert_msgsvr(void* context_, int port_)
{
    std::cout << "insert port: " << port_ << "size: " << m_svrs.size() << std::endl;
    m_svrs.emplace_back(context_, port_);
    std::cout << "insert port: " << port_ << "size: " << m_svrs.size() << std::endl;
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
    return std::make_tuple(it->get_port(), true);
}

bool MsgSvrManager::set_user_count(void* context_, int count_)
{
    auto it = std::find_if(m_svrs.begin(), m_svrs.end(),
                         [=] (CMsgSvr& svr)
                         {
                            return svr.get_context() == context_;
                         });

    return it == m_svrs.end() ? false : (it->set_user_count(count_), true);
}
