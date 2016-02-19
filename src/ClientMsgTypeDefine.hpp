#ifndef CLIENTMSGTYPEDEFINE_HPP_INCLUDED
#define CLIENTMSGTYPEDEFINE_HPP_INCLUDED

/*********************************************************************************
 *Copyright(C),2010-2011,Your Company
 *FileName: // 文件名
 *Author: shub//作者
 *Version: //版本
 *Date: 2015-1-21//创建日期
 *Description: 消息协议定义//用于主要说明此程序文件完成的主要功能
 *********************************************************************************/


//
//

/*
 * 客户端发给服务器的消息类型编号
 * 服务器返回给客户端的消息编号一致
 *
 * 注释格式:
 * 消息用途
 * @parm    客户端请求的消息参数_: 参数意思
 * @return  服务器返回的消息参数 : 参数意思
 */


enum class M2L
{
    Register                        = 7000,
    UpdateMsgSvr                    = 7001,     // 更新当前消息服务器总人数
};


/*
 * 客户端与loginsvr的消息定义
 */

enum class C2L
{
    /*
     *      用户登陆
     *
     * @parm    id  : 用户登陆id
     * @return  port: 分配的消息服务器监听端口
     */
    UserLogin                       = 1000,
};



#endif // CLIENTMSGTYPEDEFINE_HPP_INCLUDED