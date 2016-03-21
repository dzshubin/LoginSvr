#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <set>
#include "LoginUser.hpp"

using namespace std;
class UserManager
{
    UserManager();

public:
    static UserManager* get_instance();
    ~UserManager();

    LoginUser*  get_user(int64_t);
    void insert(LoginUser*);

    bool free_conn_in_user(int conn_id);
private:
    set<LoginUser*> m_users;
};

#endif // USERMANAGER_H
