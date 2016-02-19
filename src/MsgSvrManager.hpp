#ifndef MSGSVRMANAGER_HPP_INCLUDED
#define MSGSVRMANAGER_HPP_INCLUDED

#include <vector>
#include <tuple>

#include "CMsgSvr.hpp"


class MsgSvrManager
{
public:
    static MsgSvrManager* get_instance ();

    // 添加一个msgsvr
    void insert_msgsvr (void*, int);
    //获取在线人数最少的服务器端口
    std::tuple<int,bool> get_best_svr ();
    //设置指定上下文的服务器的在线人数
    bool set_user_count (void*, int);

private:
    MsgSvrManager ();

private:
    std::vector<CMsgSvr> m_svrs;
};







#endif // MSGSVRMANAGER_HPP_INCLUDED
