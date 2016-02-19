

#include "CMsgSvr.hpp"


CMsgSvr::CMsgSvr(void* context_, int port_)
  :m_context(context_), m_port(port_), m_user_count(0)
{

}





int CMsgSvr::get_user_count()
{
    return m_user_count;
}


void CMsgSvr::set_user_count(int count_)
{
    m_user_count = count_;
}



void* CMsgSvr::get_context()
{

    return m_context;
}


int CMsgSvr::get_port()
{
    return m_port;
}


bool CMsgSvr::operator<(CMsgSvr& other_)
{

    return m_user_count < other_.get_user_count();
}
