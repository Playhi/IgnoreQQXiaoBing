/*
* CoolQ SDK for VC++
* Based on Api Version 9
* Written by Coxxs & Thanks for the help of orzFly
* Modified by Playhi
*/

#pragma once

#define CQAPIVER 9
#define CQAPIVERTEXT "9"

#ifndef CQAPI
#define CQAPI(ReturnType) extern "C" __declspec(dllimport) ReturnType __stdcall
#endif

#define CQEVENT(ReturnType, Name, Size) __pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size))\
 extern "C" __declspec(dllexport) ReturnType __stdcall Name

typedef int32_t CQBOOL;

#define EVENT_IGNORE 0        //事件_忽略
#define EVENT_BLOCK 1         //事件_拦截

#define REQUEST_ALLOW 1       //请求_通过
#define REQUEST_DENY 2        //请求_拒绝

#define REQUEST_GROUPADD 1    //请求_群添加
#define REQUEST_GROUPINVITE 2 //请求_群邀请

#define CQLOG_DEBUG 0           //调试 灰色
#define CQLOG_INFO 10           //信息 黑色
#define CQLOG_INFOSUCCESS 11    //信息(成功) 紫色
#define CQLOG_INFORECV 12       //信息(接收) 蓝色
#define CQLOG_INFOSEND 13       //信息(发送) 绿色
#define CQLOG_WARNING 20        //警告 橙色
#define CQLOG_ERROR 30          //错误 红色
#define CQLOG_FATAL 40          //致命错误 深红


/*
* 发送私聊消息，Auth=106
* QQID为目标QQ号，msg为消息内容
*/
CQAPI(int32_t) CQ_sendPrivateMsg(int32_t AuthCode, int64_t QQID, const char *msg);

/*
* 发送群消息，Auth=101
* groupid为群号，msg为消息内容
*/
CQAPI(int32_t) CQ_sendGroupMsg(int32_t AuthCode, int64_t groupid, const char *msg);

/*
* 发送讨论组消息，Auth=103
* discussid为讨论组号，msg为消息内容
*/
CQAPI(int32_t) CQ_sendDiscussMsg(int32_t AuthCode, int64_t discussid, const char *msg);

/*
* 发送1个赞，Auth=110 发送手机赞
* QQID为QQ号
*/
CQAPI(int32_t) CQ_sendLike(int32_t AuthCode, int64_t QQID);

/*
* 置群员移除，Auth=120
* groupid为目标群，QQID为QQ号，rejectaddrequest 如果为真，则“不再接收此人加群申请”，请慎用。留空为假
*/
CQAPI(int32_t) CQ_setGroupKick(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);

/*
* 置群员禁言，Auth=121
* groupid为目标群，QQID为QQ号，duration 禁言的时间，单位为秒。如果要解禁，这里填写0
*/
CQAPI(int32_t) CQ_setGroupBan(int32_t AuthCode, int64_t groupid, int64_t QQID, int64_t duration);

/*
* 置群管理员，Auth=122
* groupid为目标群，QQID为QQ号，setadmin 真/设置管理员 假/取消管理员
*/
CQAPI(int32_t) CQ_setGroupAdmin(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL setadmin);

/*
* 置全群禁言，Auth=123
* groupid为目标群，enableban 真/开启 假/关闭
*/
CQAPI(int32_t) CQ_setGroupWholeBan(int32_t AuthCode, int64_t groupid, CQBOOL enableban);

/*
* 置匿名群员禁言，Auth=124
* groupid为目标群，anomymous为群消息事件收到的“匿名”参数
* duration为禁言的时间，单位为秒。不支持解禁
*/
CQAPI(int32_t) CQ_setGroupAnonymousBan(int32_t AuthCode, int64_t groupid, const char *anomymous, int64_t duration);

/*
* 置群匿名设置，Auth=125
* groupid为目标群，enableanomymous为是否开启匿名
*/
CQAPI(int32_t) CQ_setGroupAnonymous(int32_t AuthCode, int64_t groupid, CQBOOL enableanomymous);

/*
* 置群成员名片，Auth=126
* groupid为目标群，QQID为目标QQ，newcard为新名片(昵称)
*/
CQAPI(int32_t) CQ_setGroupCard(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newcard);

/*
* 置群退出，Auth=127 慎用,此接口需要严格授权
* groupid为目标群
* isdismiss为是否解散，真/解散本群(群主) 假/退出本群(管理、群成员)
*/
CQAPI(int32_t) CQ_setGroupLeave(int32_t AuthCode, int64_t groupid, CQBOOL isdismiss);

/*
* 置群成员专属头衔，Auth=128 需群主权限
* groupid为目标群，QQID为目标QQ，newspecialtitle为头衔（如果要删除，这里填空）
* duration为专属头衔有效期，单位为秒。如果永久有效，这里填写-1
*/
CQAPI(int32_t) CQ_setGroupSpecialTitle(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newspecialtitle, int64_t duration);

/*
* 置讨论组退出，Auth=140
* discussid为目标讨论组号
*/
CQAPI(int32_t) CQ_setDiscussLeave(int32_t AuthCode, int64_t discussid);

/*
* 置好友添加请求，Auth=150
* responseflag为请求事件收到的“反馈标识”参数
* responseoperation为 REQUEST_ALLOW 或 REQUEST_DENY
* remark为添加后的好友备注
*/
CQAPI(int32_t) CQ_setFriendAddRequest(int32_t AuthCode, const char *responseflag, int32_t responseoperation, const char *remark);

/*
* 置群添加请求，Auth=151
* responseflag为请求事件收到的“反馈标识”参数
* requesttype根据请求事件的子类型区分 REQUEST_GROUPADD 或 REQUEST_GROUPINVITE
* responseoperation为 REQUEST_ALLOW 或 REQUEST_DENY
* reason为操作理由，仅 REQUEST_GROUPADD 且 REQUEST_DENY 时可用
*/
CQAPI(int32_t) CQ_setGroupAddRequestV2(int32_t AuthCode, const char *responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);

/*
* 取群成员信息，Auth=130
* groupid为目标QQ所在群，QQID为目标QQ号，nocache为是否不使用缓存
*/
CQAPI(const char *) CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache);

/*
* 取陌生人信息，Auth=131
* QQID为目标QQ，nocache为是否不使用缓存
*/
CQAPI(const char *) CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQBOOL nocache);

/*
* 日志(不推荐使用本函数，请使用CQ_addLog*函数)
* priority为优先级，category为类型，content为内容
*/
CQAPI(int32_t) CQ_addLog(int32_t AuthCode, int32_t priority, const char *category, const char *content);

/*
* 取Cookies
* Auth=20 慎用,此接口需要严格授权
*/
CQAPI(const char *) CQ_getCookies(int32_t AuthCode);

/*
* 取CsrfToken
* Auth=20 即QQ网页用到的bkn/g_tk等 慎用,此接口需要严格授权
*/
CQAPI(int32_t) CQ_getCsrfToken(int32_t AuthCode);

/*
* 取登录QQ号
*/
CQAPI(int64_t) CQ_getLoginQQ(int32_t AuthCode);

/*
* 取登录QQ昵称
*/
CQAPI(const char *) CQ_getLoginNick(int32_t AuthCode);

/*
* 取应用目录，返回的路径末尾带"\"
*/
CQAPI(const char *) CQ_getAppDirectory(int32_t AuthCode);

/*
* 置致命错误提示
* errorinfo为错误信息
*/
CQAPI(int32_t) CQ_setFatal(int32_t AuthCode, const char *errorinfo);

/*
* 接收语音
* Auth=30 接收消息中的语音(record),返回保存在 \data\record\ 目录下的文件名
* Filename为收到消息中的语音文件名(file)
* RequiredFormat为应用所需的语音文件格式，目前支持 mp3,amr,wma,m4a,spx,ogg,wav,flac
*/
CQAPI(const char *) CQ_getRecord(int32_t AuthCode, const char *Filename, const char *RequiredFormat);

/*
* 发送1~10个赞，Auth=110 发送手机赞
* QQID为QQ号
*/
CQAPI(int32_t) CQ_sendLikeV2(int32_t AuthCode, int64_t QQID, int32_t times);

/*
*取群成员列表
*groupid为目标群
*/
CQAPI(const char *) CQ_getGroupMemberList(int32_t AuthCode, int64_t groupid);

/*
* 日志(错误)
* category为类型，content为内容
*/
int32_t CQ_addLogError(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_ERROR, category, content);
};

/*
* 日志(警告)
* category为类型，content为内容
*/
int32_t CQ_addLogWarning(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_WARNING, category, content);
};

/*
* 日志(调试)
* category为类型，content为内容
*/
int32_t CQ_addLogDebug(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_DEBUG, category, content);
};

/*
* 日志(信息)
* category为类型，content为内容
*/
int32_t CQ_addLogInfo(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_INFO, category, content);
};

/*
* 日志(致命错误)
* category为类型，content为内容
*/
int32_t CQ_addLogFatal(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_FATAL, category, content);
};
