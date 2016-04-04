#include "UserManager.hpp"

#include <algorithm>

UserManager::UserManager()
{
    //ctor
}

UserManager::~UserManager()
{
    for_each(m_users.begin(), m_users.end(),
        [] (LoginUser* user)
        {
            delete user;
        });
}


/////////////
UserManager* UserManager::get_instance()
{
    static UserManager u;
    return &u;
}


LoginUser* UserManager::get_user(int64_t id_)
{
    auto it = find_if(m_users.begin(), m_users.end(),
        [&] (LoginUser* user)
        {
            return user->get_id() == id_;
        });

    return it == m_users.end() ? nullptr : *it;
}


void UserManager::insert(LoginUser* pUser)
{
    m_users.insert(pUser);
}



bool UserManager::free_conn(int user_id_)
{

    auto it = find_if(m_users.begin(), m_users.end(),
        [&] (LoginUser* pUser)
        {
            return pUser->get_id() == user_id_;
        });


    if (it == m_users.end())
    {
        return false;
    }

    else
    {
        /// 释放内存
        (*it)->free_conn();
        delete (*it);

        m_users.erase(it);
        return true;
    }
}



bool UserManager::delete_related_user(int conn_id_)
{
    auto it = find_if(m_users.begin(), m_users.end(),
        [&] (LoginUser* user)
        {
            return user->get_conn_id() == conn_id_;
        });


    if (it != m_users.end())
    {
        // find
        (*it)->free_conn();
        delete (*it);

        m_users.erase(it);
        return true;
    }

    else
    {
        return false;
    }
}













