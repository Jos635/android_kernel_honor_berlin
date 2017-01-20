/******************************************************************************


        @(#)Copyright(C)2013,Hisilicon Co. LTD.

 ******************************************************************************
    File name   : ImsaLPdcpInterface.h
    Description : �ڲ�ģ���ӿ�ͷ�ļ�
    History     :
      1.leixiantiao 00258641    2016-07-02  Draft Enact


******************************************************************************/

#ifndef __IMSALPDCPINTERFACE_H__
#define __IMSALPDCPINTERFACE_H__

/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include    "vos.h"


/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
#pragma pack(*)    �����ֽڶ��뷽ʽ
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 macro
*****************************************************************************/


#define IMSA_LPDCP_MSG_ID_HEADER        0
#define LPDCP_IMSA_MSG_ID_HEADER        10

#define IMSA_LPDCP_MAX_IMS_BEARER_NUM     (8)


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

/*****************************************************************************
 ö����    : IMSA_LPDCP_MSG_ID_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : IMSA��LPDCP֮�����Ϣ
*****************************************************************************/
enum    IMSA_LPDCP_MSG_ID_ENUM
{
    /* IMSA����LPDCP����Ϣԭ�� */
    ID_IMSA_LPDCP_VOLTE_BEARER_NOTIFY           = 0x00 + IMSA_LPDCP_MSG_ID_HEADER,    /* _H2ASN_MsgChoice IMSA_LPDCP_VOLTE_BEARER_NOTIFY_STRU */
    ID_IMSA_LPDCP_CALL_STATUS_NOTIFY            = 0x01 + IMSA_LPDCP_MSG_ID_HEADER,    /* _H2ASN_MsgChoice IMSA_LPDCP_CALL_STATUS_NOTIFY_STRU */

    ID_IMSA_LPDCP_MSG_ID_ENUM_BUTT
};
typedef VOS_UINT32 IMSA_LPDCP_MSG_ID_ENUM_UINT32;


/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 ö����    : IMSA_LPDCP_IMS_BEARER_TYPE_ENUM
 ö��˵��  : ��������ö��
*****************************************************************************/
enum IMSA_LPDCP_IMS_BEARER_TYPE_ENUM
{
    IMSA_LPDCP_IMS_BEARER_TYPE_SIGNAL           = 0x00, /* IMS������� */
    IMSA_LPDCP_IMS_BEARER_TYPE_VOICE            = 0x01, /* IMS�������� */
    IMSA_LPDCP_IMS_BEARER_TYPE_VIDEO            = 0x02, /* IMS��Ƶ���� */

    IMSA_LPDCP_IMS_BEARER_TYPE_BUTT             = 0xFF
};
typedef VOS_UINT8 IMSA_LPDCP_IMS_BEARER_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : IMSA_LPDCP_CALL_STATUS_ENUM
 ö��˵��  : �绰��ͣ״̬ö��
*****************************************************************************/
enum IMSA_LPDCP_CALL_STATUS_ENUM
{
    IMSA_LPDCP_CALL_STATUS_INIT                 = 0x00, /* �绰��ʼ:���*/
    IMSA_LPDCP_CALL_STATUS_START                = 0x01, /* �绰����:����*/
    IMSA_LPDCP_CALL_STATUS_ACTIVE               = 0x02, /* �绰��ͨ */
    IMSA_LPDCP_CALL_STATUS_END                  = 0x03, /* �绰ֹͣ */

    IMSA_LPDCP_CALL_STATUS_BUTT
};
typedef VOS_UINT8 IMSA_LPDCP_CALL_STATUS_ENUM_UINT8;

/*****************************************************************************
  5 STRUCT
*****************************************************************************/
/*****************************************************************************
 �ṹ��    : IMSA_LPDCP_IMS_BEARER_STRU
 �ṹ˵��  : IMS���ؽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucEpsbId;
    IMSA_LPDCP_IMS_BEARER_TYPE_ENUM_UINT8   enBearerType;
    VOS_UINT8                               aucReserved[2];
} IMSA_LPDCP_IMS_BEARER_STRU;

/*****************************************************************************
 �ṹ��    : IMSA_LPDCP_IMS_BEARER_NOTIFY_STRU
 �ṹ˵��  : IMSA֪ͨLPDCP������Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    VOS_UINT32                              ulImsBearerNum;
    IMSA_LPDCP_IMS_BEARER_STRU              astImsBearerArray[IMSA_LPDCP_MAX_IMS_BEARER_NUM];
} IMSA_LPDCP_VOLTE_BEARER_NOTIFY_STRU;

/*****************************************************************************
 �ṹ��    : IMSA_LPDCP_CALL_STATUS_NOTIFY_STRU
 �ṹ˵��  : IMSA֪ͨLPDCP�绰��ͣ(����ʱֻ�ڵ�һ·�绰ʱ֪ͨ,����ʱֻ�����е绰�Ҷ�ʱ֪ͨ)
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                              ulMsgId;
    IMSA_LPDCP_CALL_STATUS_ENUM_UINT8       enCallStatus;
    VOS_UINT8                               auRsv[3];
}IMSA_LPDCP_CALL_STATUS_NOTIFY_STRU;

typedef struct
{
    IMSA_LPDCP_MSG_ID_ENUM_UINT32         enMsgId;            /*_H2ASN_MsgChoice_Export IMSA_LPDCP_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                             aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          IMSA_LPDCP_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}IMSA_LPDCP_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    IMSA_LPDCP_INTERFACE_MSG_DATA         stMsgData;
} ImsaLPDCPInterface_MSG;



/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/

/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif




#ifdef __cplusplus
    #if __cplusplus
            }
    #endif
#endif

#endif /* end of ImsaLPDCPInterface.h */

