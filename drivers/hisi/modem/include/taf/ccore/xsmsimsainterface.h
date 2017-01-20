/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : xsmsimsainterface.h
  �� �� ��   : ����
  ��    ��   : z00316370
  ��������   : 2016��2��19��
  ��������   : XSMS��IMSA�ӿ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2016��2��19��
    ��    ��   : z00316370
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef  XSMS_IMSA_INTERFACE_H
#define  XSMS_IMSA_INTERFACE_H

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "NasSms.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

#define XSMS_IMSA_MAX_ADDR_LEN          (48)
#define XSMS_IMSA_MAX_USER_DATA_LEN     (255)
#define TAF_XSMS_IMSA_XSMS_BASE         (0)

/*****************************************************************************
  2 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
ö����    : XSMS_IMSA_XSMS_TYPE_ENUM
�ṹ˵��  : XSMS��IMSA��֮�����Ϣ

  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   : ����XSMS��IMSA֮��Ľӿ���Ϣ
*****************************************************************************/

enum XSMS_IMSA_XSMS_TYPE_ENUM
{
    ID_XSMS_IMSA_TPDU_DATA_REQ      =   TAF_XSMS_IMSA_XSMS_BASE,            /* _H2ASN_XSMSChoice XSMS_IMSA_TPDU_DATA_REQ_STRU */
    ID_XSMS_IMSA_TL_ACK_REPORT_REQ,                                         /* _H2ASN_XSMSChoice XSMS_IMSA_TL_ACK_REPORT_REQ_STRU */

    ID_IMSA_XSMS_TPDU_DATA_IND      =   TAF_XSMS_IMSA_XSMS_BASE+0x100,      /* _H2ASN_XSMSChoice IMSA_XSMS_TPDU_DATA_IND_STRU */
    ID_IMSA_XSMS_TL_ACK_REPORT_IND,                                         /* _H2ASN_XSMSChoice IMSA_XSMS_TL_ACK_REPORT_IND_STRU */

    ID_IMSA_XSMS_TYPE_BUTT
};
typedef  VOS_UINT32  XSMS_IMSA_XSMS_TYPE_ENUM_UINT32;

/*****************************************************************************
ö����    : XSMS_IMSA_TL_ACK_WAIT_NEED_ENUM
�ṹ˵��  : XSMS��IMSA��֮�� MO �����Ƿ���Ҫ�ȴ������TL_ACK

  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   :
*****************************************************************************/
enum XSMS_IMSA_TL_ACK_WAIT_NEED_ENUM
{
    XSMS_IMSA_TL_ACK_NOT_NEED_WAIT       = 0,
    XSMS_IMSA_TL_ACK_WAIT_NEEDED         = 1,

    XSMS_IMSA_TL_ACK_WAIT_NEED_BUTT

};

typedef  VOS_UINT8  XSMS_IMSA_TL_ACK_WAIT_NEED_ENUM_UINT8;

/*****************************************************************************
ö����    : XSMS_IMSA_TL_ACK_WAIT_NEED_ENUM
�ṹ˵��  : XSMS��IMSA��֮�� MT �����Ƿ���Ҫ�o�����TL_ACK

  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   :
*****************************************************************************/
enum XSMS_IMSA_TL_ACK_SND_NEED_ENUM
{
    XSMS_IMSA_TL_ACK_NOT_NEED_SND       = 0,
    XSMS_IMSA_TL_ACK_SND_NEEDED         = 1,

    XSMS_IMSA_TL_ACK_SND_NEED_BUTT

};

typedef  VOS_UINT8  XSMS_IMSA_TL_ACK_SND_NEED_ENUM_UINT8;

/*****************************************************************************
ö����    : IMS_SMS_PROTOCOL_TYPE_ENUM
�ṹ˵��  : IMS �յ����ŵ�Э���ʽ

  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   :
*****************************************************************************/
enum IMS_SMS_PROTOCOL_TYPE_ENUM
{
    IMS_SMS_PROTOCOL_TYPE_3GPP       = 0,
    IMS_SMS_PROTOCOL_TYPE_3GPP2      = 1,

    IMS_SMS_PROTOCOL_TYPE_BUTT

};

typedef  VOS_UINT8  IMS_SMS_PROTOCOL_TYPE_ENUM_UINT8;


/*****************************************************************************
ö����    : IMSA_XSMS_SIP_CAUSE_CODE_ENUM
�ṹ˵��  : IMSA �ϱ��Ķ��ŷ��ͽ��

  1.��    ��   : 2016��7��12��
    ��    ��   : z00316370
    �޸�����   :
*****************************************************************************/
enum IMSA_XSMS_SIP_CAUSE_CODE_ENUM
{
    IMSA_XSMS_SIP_CAUSE_TRYING                               = 100,
    IMSA_XSMS_SIP_CAUSE_CALL_IS_BEING_FORWARDED              = 181,      /* ������·�ɵ�����һ��Ŀ�ĵ� */
    IMSA_XSMS_SIP_CAUSE_QUEUED                               = 182,      /* callee��ǰ�ǲ��ɻ�õ� */
    IMSA_XSMS_SIP_CAUSE_SESSION_PROGRESS                     = 183,      /* ����Ƶ�δ��� */
    IMSA_XSMS_SIP_CAUSE_SUCCESS                              = 200,      /* �ɹ� */
    IMSA_XSMS_SIP_CAUSE_MULTIPLE_CHOICES                     = 300,      /* ���еĵ�ַ�������ɶ����ַ */
    IMSA_XSMS_SIP_CAUSE_MOVED_PERMANENTLY                    = 301,      /* ָ����ַ���û�����Զ������ */
    IMSA_XSMS_SIP_CAUSE_MOVED_TEMPORARITY                    = 302,      /* ָ����ַ���û���ʱ������ */
    IMSA_XSMS_SIP_CAUSE_USER_PROXY                           = 305,      /* caller ����ʹ��һ��proxy������callee */
    IMSA_XSMS_SIP_CAUSE_ALTERNATIVE_SERVICE                  = 380,      /* caller �����ã����ǿ�ѡ�������ķ��� */
    IMSA_XSMS_SIP_CAUSE_BAD_REQUEST                          = 400,      /* �Ƿ���ʽ�������ܱ���� */
    IMSA_XSMS_SIP_CAUSE_UNAUTHORISED                         = 401,      /* ��Ҫ�û���֤ */
    IMSA_XSMS_SIP_CAUSE_PAYMENT_REQUIRED                     = 402,      /* ��ɻỰ��Ҫ�û����� */
    IMSA_XSMS_SIP_CAUSE_FORBIDDEN                            = 403,      /* ���񱻾� */
    IMSA_XSMS_SIP_CAUSE_NOT_FOUND                            = 404,         /* ָ���������û������� */
    IMSA_XSMS_SIP_CAUSE_METHOD_NOT_ALLOWED                   = 405,         /* ������ָ���ķ���ʱ��������ģ�������һ������ķ����б� */
    IMSA_XSMS_SIP_CAUSE_HEADER_NOT_ACCEPTABLE                = 406,         /* header ��ָ�������󲻽��� */
    IMSA_XSMS_SIP_CAUSE_PROXY_AUTHENTICATION_REQUIRED        = 407,         /* ��Ҫ��proxy����֤ */
    IMSA_XSMS_SIP_CAUSE_REQUEST_TIMEOUT                      = 408,         /* ��timeout����ǰ��server���ܲ�����Ӧ  */
    IMSA_XSMS_SIP_CAUSE_CONFLICT                             = 409,         /* ��Դ��ͻ�������ܱ����� */
    IMSA_XSMS_SIP_CAUSE_GONE                                 = 410,         /* ������Դ�����ã�Ҳû��ת���ĵ�ַ */
    IMSA_XSMS_SIP_CAUSE_LENGTH_REQUIRED                      = 411,         /* �û��ܾ�û�ж���content���ȵ����� */
    IMSA_XSMS_SIP_CAUSE_REQUEST_ENTITY_TOO_LARGE             = 413,         /* ����server�ܴ���Ĵ�С  */
    IMSA_XSMS_SIP_CAUSE_REQUEST_URI_TOO_LONG                 = 414,         /* �����URI̫�� */
    IMSA_XSMS_SIP_CAUSE_UNSUPPORTED_MEDIA                    = 415,         /* body��ʽ����Ŀ���ն�֧�� */
    IMSA_XSMS_SIP_CAUSE_BAD_EXTENSION                        = 420,         /* server�������header�е���չЭ�� */
    IMSA_XSMS_SIP_CAUSE_TEMPORARILY_UNAVAILABLE              = 480,         /* callee����ϵ�ϣ�����ʱ������ */
    IMSA_XSMS_SIP_CAUSE_CALL_NOT_EXIST                       = 481,         /* server���ں������� */
    IMSA_XSMS_SIP_CAUSE_LOOP_DETECTED                        = 482,         /* �յ�һ���������Լ�·�������� */
    IMSA_XSMS_SIP_CAUSE_TOO_MANY_HOPSS                       = 483,         /* hop̫�� */
    IMSA_XSMS_SIP_CAUSE_ADDRESS_INCOMPLETE                   = 484,         /* ��ַ������ */
    IMSA_XSMS_SIP_CAUSE_AMBIGUOUS                            = 485,         /* ��ַ����ȷ */
    IMSA_XSMS_SIP_CAUSE_BUSY_HERE                            = 486,         /* æµ */
    IMSA_XSMS_SIP_CAUSE_SERVER_INTERNAL_ERROR                = 500,         /* server��gateway�������� */
    IMSA_XSMS_SIP_CAUSE_NOT_IMPLEMENTED                      = 501,         /* ��֧�� */
    IMSA_XSMS_SIP_CAUSE_BAD_GATEWAY                          = 502,         /* �Ƿ���Ӧ */
    IMSA_XSMS_SIP_CAUSE_SERVICE_UNAVAILABLE                  = 503,         /* ������ */
    IMSA_XSMS_SIP_CAUSE_GATEWAY_TIMEOUT                      = 504,         /* û��ʱ��Ӧ */
    IMSA_XSMS_SIP_CAUSE_VERSION_NOT_SUPPORTED                = 505,         /* SIP�汾��֧�� */
    IMSA_XSMS_SIP_CAUSE_BUSY_EVERYWHERE                      = 600,         /* æµ�� */
    IMSA_XSMS_SIP_CAUSE_DECLINE                              = 603,         /* ���ܼ���CALL */
    IMSA_XSMS_SIP_CAUSE_DOES_NOT_EXIST_ANYWHERE              = 604,         /* CALLEE���������� */
    IMSA_XSMS_SIP_CAUSE_SESSION_NOT_ACCEPTABLE               = 606,         /* session�������� */

    IMSA_XSMS_SIP_CAUSE_BUTT

};
typedef  VOS_UINT32  IMSA_XSMS_SIP_CAUSE_CODE_ENUM_UINT32;



/*****************************************************************************
  3 ���Ͷ���
*****************************************************************************/
/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/
/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/
/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/
/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulDataLen;                              /*�û����ݵĳ���*/
    VOS_UINT8                           aucData[4];                           /*�û����ݵ�ַ*/
}XSMS_IMSA_DATA_STRU;

/*****************************************************************************
 �ṹ��  : XSMS_IMSA_TPDU_DATA_REQ_STRU,
 �ṹ˵��: MO��TL DATA��Ϣ

 �޸���ʷ      :
  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   : �����ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*��Ϣͷ*/
    VOS_UINT32                                              ulMsgName;
    XSMS_IMSA_TL_ACK_WAIT_NEED_ENUM_UINT8                   enIsNwTlackNeeded;
    IMS_SMS_PROTOCOL_TYPE_ENUM_UINT8                        enProtocolType;
    VOS_UINT16                                              usDestAddrLen;      /* Ŀ���ַ�ĳ���  */
    VOS_UINT8                                               aucDestAddr[XSMS_IMSA_MAX_ADDR_LEN];      /* Ŀ���ַ ASCII���ʽ��󳤶�48 */
    XSMS_IMSA_DATA_STRU                                     stSmsData;
}XSMS_IMSA_TPDU_DATA_REQ_STRU;

/*****************************************************************************
 �ṹ��  : XSMS_IMSA_REPORT_REQ_STRU
 �ṹ˵��: MT��TL_ACKȷ����Ϣ

 �޸���ʷ      :
  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   : �����ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*��Ϣͷ*/
    VOS_UINT32                                              ulMsgName;
    XSMS_IMSA_TL_ACK_SND_NEED_ENUM_UINT8                    enTlAckSndNeeded;
    IMS_SMS_PROTOCOL_TYPE_ENUM_UINT8                        enProtocolType;
    VOS_UINT16                                              usDestAddrLen;      /* Ŀ���ַ�ĳ���  */
    VOS_UINT8                                               aucDestAddr[XSMS_IMSA_MAX_ADDR_LEN];      /* Ŀ���ַ ASCII���ʽ��󳤶�48 */
    XSMS_IMSA_DATA_STRU                                     stSmsData;
} XSMS_IMSA_TL_ACK_REPORT_REQ_STRU;

/*****************************************************************************
 �ṹ��  : IMSA_XSMS_DATA_IND_STRU
 �ṹ˵��: MT��TL DATA��Ϣ

 �޸���ʷ      :
  1.��    ��   : 2016��2��19��
    ��    ��   : c00299064
    �޸�����   : �����ṹ
*****************************************************************************/
typedef SMT_SMR_DATA_STRU IMSA_XSMS_TPDU_DATA_IND_STRU;

/*****************************************************************************
 �ṹ��    : IMSA_XSMS_TL_ACK_REPORT_IND_STRU
 �ṹ˵��  : IMSA��XSMS�ϱ��Ķ��ŷ��ͽ����Ϣ�ṹ��
             ulMsgName   ��Ϣ��
             ulRslt      ���ŷ��ͽ����VOS_TRUE �ɹ�  VOS_FALSE �ɹ�
  1.��    ��   : 2016��7��12��
    ��    ��   : z00316370
    �޸�����   : �´���
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                              /*��Ϣͷ*/
    VOS_UINT32                                              ulMsgName;
    IMSA_XSMS_SIP_CAUSE_CODE_ENUM_UINT32                    enCauseCode;            /* ���ԭ��ֵ */
}IMSA_XSMS_TL_ACK_REPORT_IND_STRU;

/*****************************************************************************
  8 UNION����
*****************************************************************************/
/*****************************************************************************
  9 OTHERS����
*****************************************************************************/

/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    XSMS_IMSA_XSMS_TYPE_ENUM_UINT32     enMsgId;

    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_XSMSChoice_When_Comment          XSMS_IMSA_XSMS_TYPE_ENUM_UINT32
    ****************************************************************************/
}XSMS_IMSA_XSMS_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    XSMS_IMSA_XSMS_DATA                 stMsgData;
}XsmsImsaInterface_XSMS;


/*****************************************************************************
  10 ��������
*****************************************************************************/


#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* XSMS_IMSA_INTERFACE_H */
