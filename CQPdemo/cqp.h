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

#define EVENT_IGNORE 0        //�¼�_����
#define EVENT_BLOCK 1         //�¼�_����

#define REQUEST_ALLOW 1       //����_ͨ��
#define REQUEST_DENY 2        //����_�ܾ�

#define REQUEST_GROUPADD 1    //����_Ⱥ���
#define REQUEST_GROUPINVITE 2 //����_Ⱥ����

#define CQLOG_DEBUG 0           //���� ��ɫ
#define CQLOG_INFO 10           //��Ϣ ��ɫ
#define CQLOG_INFOSUCCESS 11    //��Ϣ(�ɹ�) ��ɫ
#define CQLOG_INFORECV 12       //��Ϣ(����) ��ɫ
#define CQLOG_INFOSEND 13       //��Ϣ(����) ��ɫ
#define CQLOG_WARNING 20        //���� ��ɫ
#define CQLOG_ERROR 30          //���� ��ɫ
#define CQLOG_FATAL 40          //�������� ���


/*
* ����˽����Ϣ��Auth=106
* QQIDΪĿ��QQ�ţ�msgΪ��Ϣ����
*/
CQAPI(int32_t) CQ_sendPrivateMsg(int32_t AuthCode, int64_t QQID, const char *msg);

/*
* ����Ⱥ��Ϣ��Auth=101
* groupidΪȺ�ţ�msgΪ��Ϣ����
*/
CQAPI(int32_t) CQ_sendGroupMsg(int32_t AuthCode, int64_t groupid, const char *msg);

/*
* ������������Ϣ��Auth=103
* discussidΪ������ţ�msgΪ��Ϣ����
*/
CQAPI(int32_t) CQ_sendDiscussMsg(int32_t AuthCode, int64_t discussid, const char *msg);

/*
* ����1���ޣ�Auth=110 �����ֻ���
* QQIDΪQQ��
*/
CQAPI(int32_t) CQ_sendLike(int32_t AuthCode, int64_t QQID);

/*
* ��ȺԱ�Ƴ���Auth=120
* groupidΪĿ��Ⱥ��QQIDΪQQ�ţ�rejectaddrequest ���Ϊ�棬�򡰲��ٽ��մ��˼�Ⱥ���롱�������á�����Ϊ��
*/
CQAPI(int32_t) CQ_setGroupKick(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL rejectaddrequest);

/*
* ��ȺԱ���ԣ�Auth=121
* groupidΪĿ��Ⱥ��QQIDΪQQ�ţ�duration ���Ե�ʱ�䣬��λΪ�롣���Ҫ�����������д0
*/
CQAPI(int32_t) CQ_setGroupBan(int32_t AuthCode, int64_t groupid, int64_t QQID, int64_t duration);

/*
* ��Ⱥ����Ա��Auth=122
* groupidΪĿ��Ⱥ��QQIDΪQQ�ţ�setadmin ��/���ù���Ա ��/ȡ������Ա
*/
CQAPI(int32_t) CQ_setGroupAdmin(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL setadmin);

/*
* ��ȫȺ���ԣ�Auth=123
* groupidΪĿ��Ⱥ��enableban ��/���� ��/�ر�
*/
CQAPI(int32_t) CQ_setGroupWholeBan(int32_t AuthCode, int64_t groupid, CQBOOL enableban);

/*
* ������ȺԱ���ԣ�Auth=124
* groupidΪĿ��Ⱥ��anomymousΪȺ��Ϣ�¼��յ��ġ�����������
* durationΪ���Ե�ʱ�䣬��λΪ�롣��֧�ֽ��
*/
CQAPI(int32_t) CQ_setGroupAnonymousBan(int32_t AuthCode, int64_t groupid, const char *anomymous, int64_t duration);

/*
* ��Ⱥ�������ã�Auth=125
* groupidΪĿ��Ⱥ��enableanomymousΪ�Ƿ�������
*/
CQAPI(int32_t) CQ_setGroupAnonymous(int32_t AuthCode, int64_t groupid, CQBOOL enableanomymous);

/*
* ��Ⱥ��Ա��Ƭ��Auth=126
* groupidΪĿ��Ⱥ��QQIDΪĿ��QQ��newcardΪ����Ƭ(�ǳ�)
*/
CQAPI(int32_t) CQ_setGroupCard(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newcard);

/*
* ��Ⱥ�˳���Auth=127 ����,�˽ӿ���Ҫ�ϸ���Ȩ
* groupidΪĿ��Ⱥ
* isdismissΪ�Ƿ��ɢ����/��ɢ��Ⱥ(Ⱥ��) ��/�˳���Ⱥ(����Ⱥ��Ա)
*/
CQAPI(int32_t) CQ_setGroupLeave(int32_t AuthCode, int64_t groupid, CQBOOL isdismiss);

/*
* ��Ⱥ��Աר��ͷ�Σ�Auth=128 ��Ⱥ��Ȩ��
* groupidΪĿ��Ⱥ��QQIDΪĿ��QQ��newspecialtitleΪͷ�Σ����Ҫɾ����������գ�
* durationΪר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1
*/
CQAPI(int32_t) CQ_setGroupSpecialTitle(int32_t AuthCode, int64_t groupid, int64_t QQID, const char *newspecialtitle, int64_t duration);

/*
* ���������˳���Auth=140
* discussidΪĿ���������
*/
CQAPI(int32_t) CQ_setDiscussLeave(int32_t AuthCode, int64_t discussid);

/*
* �ú����������Auth=150
* responseflagΪ�����¼��յ��ġ�������ʶ������
* responseoperationΪ REQUEST_ALLOW �� REQUEST_DENY
* remarkΪ��Ӻ�ĺ��ѱ�ע
*/
CQAPI(int32_t) CQ_setFriendAddRequest(int32_t AuthCode, const char *responseflag, int32_t responseoperation, const char *remark);

/*
* ��Ⱥ�������Auth=151
* responseflagΪ�����¼��յ��ġ�������ʶ������
* requesttype���������¼������������� REQUEST_GROUPADD �� REQUEST_GROUPINVITE
* responseoperationΪ REQUEST_ALLOW �� REQUEST_DENY
* reasonΪ�������ɣ��� REQUEST_GROUPADD �� REQUEST_DENY ʱ����
*/
CQAPI(int32_t) CQ_setGroupAddRequestV2(int32_t AuthCode, const char *responseflag, int32_t requesttype, int32_t responseoperation, const char *reason);

/*
* ȡȺ��Ա��Ϣ��Auth=130
* groupidΪĿ��QQ����Ⱥ��QQIDΪĿ��QQ�ţ�nocacheΪ�Ƿ�ʹ�û���
*/
CQAPI(const char *) CQ_getGroupMemberInfoV2(int32_t AuthCode, int64_t groupid, int64_t QQID, CQBOOL nocache);

/*
* ȡİ������Ϣ��Auth=131
* QQIDΪĿ��QQ��nocacheΪ�Ƿ�ʹ�û���
*/
CQAPI(const char *) CQ_getStrangerInfo(int32_t AuthCode, int64_t QQID, CQBOOL nocache);

/*
* ��־(���Ƽ�ʹ�ñ���������ʹ��CQ_addLog*����)
* priorityΪ���ȼ���categoryΪ���ͣ�contentΪ����
*/
CQAPI(int32_t) CQ_addLog(int32_t AuthCode, int32_t priority, const char *category, const char *content);

/*
* ȡCookies
* Auth=20 ����,�˽ӿ���Ҫ�ϸ���Ȩ
*/
CQAPI(const char *) CQ_getCookies(int32_t AuthCode);

/*
* ȡCsrfToken
* Auth=20 ��QQ��ҳ�õ���bkn/g_tk�� ����,�˽ӿ���Ҫ�ϸ���Ȩ
*/
CQAPI(int32_t) CQ_getCsrfToken(int32_t AuthCode);

/*
* ȡ��¼QQ��
*/
CQAPI(int64_t) CQ_getLoginQQ(int32_t AuthCode);

/*
* ȡ��¼QQ�ǳ�
*/
CQAPI(const char *) CQ_getLoginNick(int32_t AuthCode);

/*
* ȡӦ��Ŀ¼�����ص�·��ĩβ��"\"
*/
CQAPI(const char *) CQ_getAppDirectory(int32_t AuthCode);

/*
* ������������ʾ
* errorinfoΪ������Ϣ
*/
CQAPI(int32_t) CQ_setFatal(int32_t AuthCode, const char *errorinfo);

/*
* ��������
* Auth=30 ������Ϣ�е�����(record),���ر����� \data\record\ Ŀ¼�µ��ļ���
* FilenameΪ�յ���Ϣ�е������ļ���(file)
* RequiredFormatΪӦ������������ļ���ʽ��Ŀǰ֧�� mp3,amr,wma,m4a,spx,ogg,wav,flac
*/
CQAPI(const char *) CQ_getRecord(int32_t AuthCode, const char *Filename, const char *RequiredFormat);

/*
* ����1~10���ޣ�Auth=110 �����ֻ���
* QQIDΪQQ��
*/
CQAPI(int32_t) CQ_sendLikeV2(int32_t AuthCode, int64_t QQID, int32_t times);

/*
*ȡȺ��Ա�б�
*groupidΪĿ��Ⱥ
*/
CQAPI(const char *) CQ_getGroupMemberList(int32_t AuthCode, int64_t groupid);

/*
* ��־(����)
* categoryΪ���ͣ�contentΪ����
*/
int32_t CQ_addLogError(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_ERROR, category, content);
};

/*
* ��־(����)
* categoryΪ���ͣ�contentΪ����
*/
int32_t CQ_addLogWarning(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_WARNING, category, content);
};

/*
* ��־(����)
* categoryΪ���ͣ�contentΪ����
*/
int32_t CQ_addLogDebug(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_DEBUG, category, content);
};

/*
* ��־(��Ϣ)
* categoryΪ���ͣ�contentΪ����
*/
int32_t CQ_addLogInfo(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_INFO, category, content);
};

/*
* ��־(��������)
* categoryΪ���ͣ�contentΪ����
*/
int32_t CQ_addLogFatal(int32_t AuthCode, const char *category, const char *content) {
	return CQ_addLog(AuthCode, CQLOG_FATAL, category, content);
};
