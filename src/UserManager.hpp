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

    bool free_conn(int user_id);

    bool delete_related_user(int conn_id_);

private:
    set<LoginUser*> m_users;
};

#endif // USERMANAGER_H
