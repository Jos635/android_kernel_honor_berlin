

#ifndef __LCSMMINTERFACE_H__
#define __LCSMMINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  #pragma pack(*)    �����ֽڶ��뷽ʽ
*****************************************************************************/
/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include "LPSCommon.h"


#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif



/*****************************************************************************
  2 Macro
*****************************************************************************/
#define PS_MSG_ID_LCS_TO_MM_BASE        (0)
#define PS_MSG_ID_MM_TO_LCS_BASE        (100)
#define LCS_MM_LCS_NW_MSG               (0)
#define LCS_MM_NOT_LCS_NW_MSG           (1)

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 ö����    : LCS_MM_MSG_ID_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : LCS��MM֮�����Ϣö��
*****************************************************************************/
enum LCS_MM_MSG_ID_ENUM
{
    /* LCS����MM����Ϣԭ�� */
    ID_LCS_MM_EST_REQ                   = 0x01 + PS_MSG_ID_LCS_TO_MM_BASE,      /* _H2ASN_MsgChoice LCS_MM_EST_REQ_STRU */
    ID_LCS_MM_DATA_REQ                  = 0x02 + PS_MSG_ID_LCS_TO_MM_BASE,      /* _H2ASN_MsgChoice LCS_MM_DATA_REQ_STRU */
    ID_LCS_MM_REL_REQ                   = 0x03 + PS_MSG_ID_LCS_TO_MM_BASE,      /* _H2ASN_MsgChoice LCS_MM_REL_REQ_STRU */
    ID_LCS_MM_STATUS_NTY                = 0x04 + PS_MSG_ID_LCS_TO_MM_BASE,      /* _H2ASN_MsgChoice LCS_MM_STATUS_NTY_STRU */


    /* MM���͸�LCS����Ϣԭ��*/
    ID_MM_LCS_EST_CNF                   = 0x01 + PS_MSG_ID_MM_TO_LCS_BASE,      /* _H2ASN_MsgChoice MM_LCS_EST_CNF_STRU */
    ID_MM_LCS_DATA_IND                  = 0x02 + PS_MSG_ID_MM_TO_LCS_BASE,      /* _H2ASN_MsgChoice MM_LCS_DATA_IND_STRU */
    ID_MM_LCS_REL_IND                   = 0x03 + PS_MSG_ID_MM_TO_LCS_BASE,      /* _H2ASN_MsgChoice MM_LCS_REL_IND_STRU */

    ID_LCS_MM_MSG_ID_ENUM_BUTT
};
typedef VOS_UINT32 LCS_MM_MSG_ID_ENUM_UINT32;

/*****************************************************************************
 ö����    : NAS_LCS_STATUS_ENUM_UINT8
 �ṹ˵��  : LCS����״̬

  1.��    ��   : 2015��12��9��
    ��    ��   : l00198894
    �޸�����   : LCS������Ŀ
*****************************************************************************/
enum NAS_LCS_STATUS_ENUM
{
    NAS_LCS_STATUS_SETUP_SUCC,                                                  /* ���ӽ����ɹ� */
    NAS_LCS_STATUS_SETUP_FAIL,                                                  /* ���ӽ���ʧ�� */
    NAS_LCS_STATUS_BUTT
};
typedef VOS_UINT8 NAS_LCS_STATUS_ENUM_UINT8;



/*****************************************************************************
  5 STRUCT
*****************************************************************************/
/*****************************************************************************
 �ṹ����: LCS_MM_EST_REQ_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��:LCS����MM����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulTi;/*MOʱ��ֵΪ8-14��MTʱ��ֵΪ0-6����ֵ���տڵ�TI������ȫһ��*/
} LCS_MM_EST_REQ_STRU;

/*****************************************************************************
 �ṹ����: MM_LCS_EST_CNF_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��:MM��SS�Ľ����ظ����ظ�����Ϣ����Ϊ�Ž����ɹ�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulTi;
} MM_LCS_EST_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LCS_MM_AIR_MSG_STRU
 �ṹ˵��  : LCS�տ���Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                         ulLcsMsgSize;       /* ���Ȳ�����256                    */
    VOS_UINT8                          aucLcsMsg[4];       /* ��Ϣ��ǰ�ĸ��ֽ�����             */
    /*************************************************************************
        _H2ASN_Array2String
    *************************************************************************/
}LCS_MM_AIR_MSG_STRU;

/*****************************************************************************
 �ṹ����: LCS_MM_DATA_REQ_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��:LCS�������ݷ���
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulTi;

    LCS_MM_AIR_MSG_STRU                 stLcsMsg;
} LCS_MM_DATA_REQ_STRU;

/*****************************************************************************
 �ṹ����: MM_LCS_DATA_IND_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��:���෢�͵�LCS�տ���Ϣ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulTi;

    LCS_MM_AIR_MSG_STRU                 stLcsMsg;
} MM_LCS_DATA_IND_STRU;

/*****************************************************************************
 �ṹ����: LCS_MM_REL_REQ_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��:LCS֪ͨMMʵ���ͷ�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulTi;
} LCS_MM_REL_REQ_STRU;

/*****************************************************************************
 �ṹ����: MM_LCS_REL_IND_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��: MM֪ͨLCS��·�ͷ�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    VOS_UINT32                          ulTi;

    VOS_UINT32                          ulRelCause;
} MM_LCS_REL_IND_STRU;

/*****************************************************************************
 �ṹ����: LCS_MM_STATUS_NTY_STRU
 Э����:
 ASN.1 ����:
 �ṹ˵��: LCS����״ָ̬ʾ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;            /*_H2ASN_Skip*/
    NAS_LCS_STATUS_ENUM_UINT8           enLcsStatus;
    VOS_UINT8                           ucReserved[3];
} LCS_MM_STATUS_NTY_STRU;



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
Function Name  : NAS_LCS_IsLcsNwMsg
Description    : �жϿտ���Ϣ�Ƿ�ΪLCS�տ�,���ڵ�MMģ���յ��տ���ϢΪPDΪ0xBʱ
                 �ж��Ƿ�ÿտ���ϢΪLCS�տ���Ϣ
Input          : pucMsg----------------�տ���Ϣ����
                 ulMsgLen--------------�տ���Ϣ��������
Output         : NULL
Return Value   : �жϽ��,LCS_MM_NOT_LCS_NW_MSG:�ÿտ���Ϣ����LCS�տ���Ϣ
                          LCS_MM_LCS_NW_MSG    :�ÿտ���ϢʱLCS�տ���Ϣ

History        :
  leixiantiao 00258641 2015-10-08  �¿���
*****************************************************************************/
extern VOS_UINT32 NAS_LCS_IsLcsNwMsg(VOS_UINT8 *pucMsg, VOS_UINT32 ulMsgLen);
/*****************************************************************************
  9 OTHERS
*****************************************************************************/
/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    LCS_MM_MSG_ID_ENUM_UINT32           ulMsgId;                                /*_H2ASN_MsgChoice_Export LCS_MM_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          LCS_MM_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}LCS_MM_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    LCS_MM_MSG_DATA                     stMsgData;
}LcsMmInterface_MSG;










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

#endif /* end of LcsMmInterface.h */


