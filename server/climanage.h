/*-------------------------------------------------------------------------
FileName     : climanage.h
Description  : 客户端连接管理类
remark       : 
Modification :
--------------------------------------------------------------------------
   1、Date  2018-01-23       create     hejl 
-------------------------------------------------------------------------*/
#ifndef _CLIMANAGE_H_
#define _CLIMANAGE_H_
#include "comm/public.h"
#include "iohand.h"
#include <cstdarg>
#include <map>
#include <list>
#include <string>

using std::map;
using std::list;
using std::string;

class CliMgr
{
    SINGLETON_CLASS2(CliMgr)

    struct CliInfo
    {
        time_t t0, t1, t2; // 连接时间，活动时间，关闭时间
        map<string, bool> aliasName; // 客户端的别名，其他人可以通过该别人找到此对象
        map<string, string>* cliProp; // 客户属性

        CliInfo(void): t0(0),t1(0),t2(0),cliProp(NULL){}
    };

    enum { CLIOPLOG_SIZE = 200 };

public:
    // 别名引用相关的操作
    int addChild( IOHand* child );
    int addAlias2Child( const string& asname, IOHand* ptr );
    void removeAliasChild( const string& asname );
    void removeAliasChild( IOHand* ptr, bool rmAll );
    IOHand* getChildBySvrid( int svrid );
    map<IOHand*, CliInfo>* getAllChild() { return m_children; }

    // 自定义属性的操作
    void setProperty( IOHand* dst, const string& key, const string& val );
    string getProperty( IOHand* dst, const string& key );

    // 获取连接中的客户端属性信息
    int pickupCliProfile( string& json, int svrid, const string& key );
    // 获取已掉线的客户信息
    int pickupCliCloseLog( string& json );
    // 获取客户行为日志信息
    int pickupCliOpLog( string& json, int nSize );
    // 获取所有告警状态的客户机信息
    int pickupWarnCliProfile( string& json, const string& filter_key, const string& filter_val );

    // 网监业务相关方法
    int onChildEvent( int evtype, va_list ap );
    void setCloseLog( int svrid, const string& cloLog );
    void rmCloseLog( int svrid );
    void appendCliOpLog( const string& logstr );
    /////////////
    void setWarnMsg( const string& taskkey, IOHand* ptr );
    void clearWarnMsg( const string& taskkey );

    // 退出处理
    int progExitHanele( int flg );

private:
    CliMgr(void);
    ~CliMgr(void);

protected:
    map<IOHand*, CliInfo> m_children;
    map<string, IOHand*> m_aliName2Child;
    map<string, IOHand*> m_warnLog; // 客户机告警的任务
    map<int, string> m_closeLog; // 记录掉线了的客户机信息
    list<string> m_cliOpLog; // 客户机的操作行为记录
    int m_opLogSize;
    IOHand* m_waitRmPtr;
};

#endif
