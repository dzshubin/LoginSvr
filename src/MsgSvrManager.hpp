#ifndef MSGSVRMANAGER_HPP_INCLUDED
#define MSGSVRMANAGER_HPP_INCLUDED

#include <set>
#include <tuple>

#include "CMsgSvr.hpp"

using namespace std;

class MsgSvrManager
{
public:
    static MsgSvrManager* get_instance ();
    ~MsgSvrManager();


    // 添加一个msgsvr
    void insert(CMsgSvr*);
    bool remove(int id_);

    // 获取服务器信息
    CMsgSvr* get_svr(int conn_id_);
    //获取在线人数最少的服务器端口
    std::tuple<int,bool> get_best_svr ();

private:
    MsgSvrManager ();

private:
    set<CMsgSvr*> m_svrs;
};







#endif // MSGSVRMANAGER_HPP_INCLUDED
