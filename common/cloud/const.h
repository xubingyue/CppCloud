/*
 * file : cloud/const.h
 * 项目中通用常量定义
*/

#ifndef __CONST__H__
#define __CONST__H__

const char MYSERVNAME[] = "serv";
const char CONNTERID_KEY[] = "svrid";
const char CLISOCKET_KEY[] = "localsock";
const char CLIENT_TYPE_KEY[] = "clitype";
const char OBJECT_TYPE_KEY[] = "objtype";
const char SERV_ALIAS_PREFIX[] = "serv_";
const char SERV_IN_ALIAS_PREFIX[] = "serv_I";
const char SERV_OUT_ALIAS_PREFIX[] = "serv_o";
const char OUTERCLI_ALIAS_PREFIX[] = "oc"; // oc_[servid]_[appid]
const char LAST_REQ_SERVMTIME[] = "lastreqall_mtime";

const char CLI_PREFIX_KEY_TIMEOUT[] = "atime_";
const char CLI_PREFIX_KEY_SERV[] = "dserv";
const char EXCLUDE_SVRID_LIST[] = "haspass";
const char ROUTE_PATH[] = "act_path";

const char BROARDCAST_KEY_FROM[] = "from";
const char BROARDCAST_KEY_PASS[] = "pass";
const char BROARDCAST_KEY_TRAIL[] = "path";
const char BROARDCAST_KEY_JUMP[] = "jump";

const char ROUTE_MSG_KEY_FROM[] = "from";
const char ROUTE_MSG_KEY_TO[] = "to";
const char ROUTE_MSG_KEY_BEGORETO[] = "bto";
const char ROUTE_MSG_KEY_REFPATH[] = "refer_path";
const char ROUTE_MSG_KEY_TRAIL[] = "path";

const int SERV_CLITYPE_ID = 1;
const int CLI_KEEPALIVE_TIME_SEC = 60*10;
const int CLI_DEAD_TIME_SEC = 60*20;
const int BROADCASTCLI_INTERVAL_SEC = 60*2;
const int REMOTESERV_EXIST_CHKTIME = 500*1000; // ms unit
const int REMOTESERV_NOEXIST_CHKTIME = 20*1000; // ms unit

#endif