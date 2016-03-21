

#include "CMsgSvr.hpp"


CMsgSvr::CMsgSvr()
  :m_port(0), m_user_count(0)
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


void CMsgSvr::set_port(int port_)
{
    m_port = port_;
}

int CMsgSvr::get_port()
{
    return m_port;
}

connection_ptr CMsgSvr::get_conn ()
{
    return m_conn;
}


void CMsgSvr::set_conn(connection_ptr conn_)
{
    m_conn = conn_;
}


void CMsgSvr::free_conn()
{
    m_conn.reset();
}



bool CMsgSvr::operator<(CMsgSvr& other_)
{

    return m_user_count < other_.get_user_count();
}
