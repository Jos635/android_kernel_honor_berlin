/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : NasMtaInterface.h
  �� �� ��   : ����
  ��    ��   : z60575
  ��������   : 2013��07��19��
  ����޸�   :
  ��������   :
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��07��19��
    ��    ��   : z60575
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __NAS_MTA_INTERFACE_H__
#define __NAS_MTA_INTERFACE_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"
#include "AppNasComm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)


/*****************************************************************************
  2 �궨��
*****************************************************************************/

#define MTA_LNAS_MSG_TYPE_BASE          (0x0100)                               /*MTAģ����LNASģ�����Ϣ����*/
#define LNAS_MTA_MSG_TYPE_BASE          (0x0200)                               /*LNASģ����MTAģ�����Ϣ����*/

#define MTA_MMC_MSG_TYPE_BASE          (0x0300)                               /* MTAģ����MMCģ�����Ϣ���� */
#define MMC_MTA_MSG_TYPE_BASE          (0x0400)                               /* MMCģ����MTAģ�����Ϣ���� */

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
 �ṹ����: NAS_MTA_MSG_TYPE_ENUM_UINT32
 �ṹ˵��: MTA��NAS֮���ԭ��
*****************************************************************************/
enum NAS_MTA_MSG_TYPE_ENUM
{
    ID_NAS_MTA_AREA_LOST_IND           = 0x0001,          /* _H2ASN_MsgChoice NAS_MTA_AREA_LOST_IND_STRU */

    ID_NAS_MTA_CS_SERVICE_CONN_CHG_IND = 0x0002,                                /* _H2ASN_MsgChoice NAS_MTA_CS_SERVICE_CONN_STATUS_CHG_IND_STRU */

    ID_NAS_MTA_TIME_INFO_IND     = 0x0003,                                /* _H2ASN_MsgChoice ID_NAS_MTA_MODEM_TIME_INFO_IND_STRU */

    ID_MTA_LNAS_SET_UE_CENTER_REQ      = MTA_LNAS_MSG_TYPE_BASE + 0x01,        /* _H2ASN_MsgChoice MTA_LNAS_SET_UE_CENTER_REQ_STRU */

    ID_LNAS_MTA_SET_UE_CENTER_CNF      = LNAS_MTA_MSG_TYPE_BASE + 0x01,        /* _H2ASN_MsgChoice LNAS_MTA_SET_UE_CENTER_CNF_STRU */

    ID_MTA_LNAS_QRY_UE_CENTER_REQ      = MTA_LNAS_MSG_TYPE_BASE + 0x02,        /* _H2ASN_MsgChoice MTA_LNAS_QRY_UE_CENTER_REQ_STRU */

    ID_LNAS_MTA_QRY_UE_CENTER_CNF      = LNAS_MTA_MSG_TYPE_BASE + 0x02,        /* _H2ASN_MsgChoice LNAS_MTA_QRY_UE_CENTER_CNF_STRU */
    ID_MTA_MMC_GET_NAS_CHR_INFO_REQ    = MTA_MMC_MSG_TYPE_BASE + 0x01,        /* _H2ASN_MsgChoice MTA_MMC_GET_NAS_INFO_REQ_STRU */
    ID_MTA_MMC_QRY_FRAT_IGNITION_REQ   = MTA_MMC_MSG_TYPE_BASE + 0x02,        /* _H2ASN_MsgChoice MTA_MMC_FRAT_IGNITION_QRY_REQ_STRU */
    ID_MTA_MMC_SET_FRAT_IGNITION_REQ   = MTA_MMC_MSG_TYPE_BASE + 0x03,        /* _H2ASN_MsgChoice MTA_MMC_FRAT_IGNITION_SET_REQ_STRU */
    

    ID_MMC_MTA_GET_NAS_CHR_INFO_CNF    = MMC_MTA_MSG_TYPE_BASE + 0x01,        /* _H2ASN_MsgChoice MMC_MTA_GET_NAS_INFO_CNF_STRU */
    
    ID_MMC_MTA_QRY_FRAT_IGNITION_CNF   = MMC_MTA_MSG_TYPE_BASE + 0x02,        /* _H2ASN_MsgChoice MMC_MTA_FRAT_IGNITION_QRY_CNF_STRU */
    ID_MMC_MTA_SET_FRAT_IGNITION_CNF   = MMC_MTA_MSG_TYPE_BASE + 0x03,        /* _H2ASN_MsgChoice MMC_MTA_FRAT_IGNITION_SET_CNF_STRU */    

    ID_NAS_MTA_MSG_TYPE_BUTT
};
typedef VOS_UINT32 NAS_MTA_MSG_TYPE_ENUM_UINT32;

/*****************************************************************************
 ö����    : MTA_LMM_RESULT_ENUM
 �ṹ˵��  : MTAģ����LMM��Ľ����ö��

  1.��    ��   : 2015��09��09��
    ��    ��   : lwx277467
    �޸�����   : ����
*****************************************************************************/
enum MTA_LMM_RESULT_ENUM
{
    MTA_LMM_RESULT_NO_ERROR                     = 0x000000,                     /* ��Ϣ�������� */
    MTA_LMM_RESULT_ERROR,                                                       /* ��Ϣ������� */

    MTA_LMM_RESULT_BUTT
};
typedef VOS_UINT32 MTA_LMM_RESULT_ENUM_UINT32;

/*****************************************************************************
 ö����    : MMA_MTA_CS_SERVICE_STATES_ENUM
 �ṹ˵��  : MMA֪ͨMTA��CS����״̬ö��

  1.��    ��   : 2016��03��10��
    ��    ��   : h00360002
    �޸�����   : ����
*****************************************************************************/
enum MMA_MTA_CS_SERVICE_STATES_ENUM
{
    MMA_MTA_CS_SRV_NO_EXIST                     = 0x00,                         /* ������ */
    MMA_MTA_CS_SRV_EXIST,                                                       /* ������ */

    MMA_MTA_CS_SRV_BUTT
};
typedef VOS_UINT8 MMA_MTA_CS_SERVICE_STATES_ENUM_UINT8;

/*****************************************************************************
 ö����    : MTA_MMC_RESULT_ENUM_UINT32
 ö��˵��  : MTA��MMC��֮��Ľ����

  1.��    ��   : 2016��4��20��
    ��    ��   : c00318887
    �޸�����   : ����
*****************************************************************************/
enum MTA_MMC_RESULT_ENUM
{
    MTA_MMC_RESULT_NO_ERROR             = 0x0000,                               /* ��Ϣ�������� */
    MTA_MMC_RESULT_ERROR,

    MTA_MMC_RESULT_BUTT
};
typedef VOS_UINT32  MTA_MMC_RESULT_ENUM_UINT32;

/*****************************************************************************
 ö����    : MTA_MMC_FRAT_IGNITION_STATE_ENUM_UNIT8
 ö��˵��  : MTA��MMC��֮��ĵ��״̬

  1.��    ��   : 2016��4��20��
    ��    ��   : c00318887
    �޸�����   : ����
*****************************************************************************/
enum MTA_MMC_FRAT_IGNITION_STATE_ENUM
{
    MTA_MMC_FRAT_IGNITION_STATE_OFF,
    MTA_MMC_FRAT_IGNITION_STATE_ON,
    MTA_MMC_FRAT_IGNITION_STATE_BUTT
};
typedef VOS_UINT8  MTA_MMC_FRAT_IGNITION_STATE_ENUM_UNIT8;

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
/*******************************************************************************
 �ṹ��    : NAS_MTA_AREA_LOST_IND_STRU
 �ṹ˵��  : MMA����MTA�Ķ���ָʾ
 1.��    ��   : 2013��07��19��
   ��    ��   : z60575
   �޸�����   : Added for PA_STAR
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                             stMsgHeader;                    /*_H2ASN_Skip*/

    VOS_UINT8                                   aucRsv[4];                      /* ����λ */
}NAS_MTA_AREA_LOST_IND_STRU;

/*****************************************************************************
 �ṹ��    : MMA_MTA_TIME_INFO_IND_STRU
 �ṹ˵��  : ʱ����Ϣ
 1.��    ��   : 2016��5��5��
   ��    ��   : z00359541
   �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    TIME_ZONE_TIME_STRU                 stTimeInfo;
}MMA_MTA_TIME_INFO_IND_STRU;

/*******************************************************************************
 �ṹ��    : NAS_MTA_CS_SERVICE_CONN_STATUS_CHG_IND_STRU
 �ṹ˵��  : MMA����MTA��CS��������״̬�ı�ָʾ
 1.��    ��   : 2016��03��10��
   ��    ��   : h00360002
   �޸�����   : LCS��Ŀ����
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                             stMsgHeader;                    /*_H2ASN_Skip*/

    MMA_MTA_CS_SERVICE_STATES_ENUM_UINT8        enCsServiceStates;
    VOS_UINT8                                   aucReserved[3];
}NAS_MTA_CS_SERVICE_CONN_STATUS_CHG_IND_STRU;

/*******************************************************************************
 �ṹ��    : MTA_LNAS_SET_UE_CENTER_REQ_STRU
 �ṹ˵��  : ����UEģʽ�������Ϣ�ṹ
 1.��    ��   : 2015��09��07��
   ��    ��   : lwx277467
   �޸�����   :
*******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                                  ulMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT32                                  ulOpId;
    LNAS_LMM_UE_CENTER_ENUM_UINT32              enUeCenter;
}MTA_LNAS_SET_UE_CENTER_REQ_STRU;

/*******************************************************************************
 �ṹ��    : LNAS_MTA_SET_UE_CENTER_CNF_STRU
 �ṹ˵��  : ����UEģʽ����ظ�����Ϣ�ṹ
 1.��    ��   : 2015��09��07��
   ��    ��   : lwx277467
   �޸�����   :
*******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                                  ulMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT32                                  ulOpId;
    VOS_UINT32                                  ulRslt;                         /*0�ɹ���1ʧ��*/
}LNAS_MTA_SET_UE_CENTER_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LNAS_UE_CENTER_QRY_REQ_STRU
 �ṹ˵��  : MTA��LNAS��ѯUEģʽ����ID_MTA_LNAS_TRANSMODE_QRY_REQ�ṹ��

  1.��    ��   : 2015��9��7��
    ��    ��   : lwx277467
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LNAS_QRY_UE_CENTER_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LNAS_MTA_UE_CENTER_QRY_CNF_STRU
 �ṹ˵��  : LNAS�ظ�MTA UEģʽ��ѯ���ID_LRRC_MTA_TRANSMODE_QRY_CNF�ṹ��

  1.��    ��   : 2015��9��7��
    ��    ��   : lwx277467
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    VOS_UINT32                          enResult;                               /*��ѯ�������*/
    VOS_UINT32                          enUeCenter;                             /*UEģʽ*/
} LNAS_MTA_QRY_UE_CENTER_CNF_STRU;

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/

/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    NAS_MTA_MSG_TYPE_ENUM_UINT32        enMsgID;                                /*_H2ASN_MsgChoice_Export NAS_MTA_MSG_TYPE_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          NAS_MTA_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}NAS_MTA_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    NAS_MTA_MSG_DATA                     stMsgData;
} NasMtaInterface_MSG;

/*****************************************************************************
 �ṹ��    : MTA_NAS_CHR_INFO_QRY_REQ_STRU
 �ṹ˵��  : MTA����MMC��NAS info��ѯ����

  1.��    ��   : 2015��12��01��
    ��    ��   : ������ g00322017
    �޸�����   : ����, for ˫������
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                      /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    VOS_UINT8                           aucReserved[4];                 /* ����λ */
} MTA_NAS_CHR_INFO_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MMC_MTA_NAS_CHR_INFO_CNF_STRU
 �ṹ˵��  : MMC����MTA��NAS INFO��ѯ���

  1.��    ��   : 2015��12��01��
    ��    ��   : ������ g00322017
    �޸�����   : ����, for ˫������
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT8                           ucIsExsitRrcConn;
    VOS_UINT8                           aucRsv[3];
} MMC_MTA_NAS_CHR_INFO_CNF_STRU;


/*****************************************************************************
 �ṹ��    : MTA_MMC_FRAT_IGNITION_QRY_REQ_STRU
 �ṹ˵��  : MTA����MMC��frat ignition��ѯ����

  1.��    ��   : 2016��4��21��
    ��    ��   : c00318887
    �޸�����   : FRAT IGNITION project �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                      /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                        /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    VOS_UINT8                           aucReserved[4];                 /* ����λ */
} MTA_MMC_FRAT_IGNITION_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MMC_MTA_NAS_CHR_INFO_CNF_STRU
 �ṹ˵��  : MMC����MTA��frat ignition��ѯ���

  1.��    ��   : 2016��4��21��
    ��    ��   : c00318887
    �޸�����   : FRAT IGNITION project �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                                              ulMsgName;          /*_H2ASN_Skip*/
    VOS_UINT32                                              ulOpId;
    MTA_MMC_RESULT_ENUM_UINT32                              enResult;           /* ������� */
    MTA_MMC_FRAT_IGNITION_STATE_ENUM_UNIT8                  enFratIgnitionState;
    VOS_UINT8                                               aucRsv[3];
} MMC_MTA_FRAT_IGNITION_QRY_CNF_STRU;

/*******************************************************************************
 �ṹ��    : MTA_LNAS_SET_UE_CENTER_REQ_STRU
 �ṹ˵��  : MTA ��mmc �� frat ignition ��������

1.��    ��   : 2016��4��21��
  ��    ��   : c00318887
  �޸�����   : FRAT IGNITION project �½�
*******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                                              ulMsgName;                                
    VOS_UINT32                                              ulOpId;
    MTA_MMC_FRAT_IGNITION_STATE_ENUM_UNIT8                  enIgnitionState;
    VOS_UINT8                                               aucRsv[3];
}MTA_MMC_FRAT_IGNITION_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MMC_MTA_FRAT_IGNITION_SET_CNF_STRU
 �ṹ˵��  : MMC����MTA��frat ignition ���� ���

  1.��    ��   : 2016��4��21��
    ��    ��   : c00318887
    �޸�����   : FRAT IGNITION project �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulOpId;
    MTA_MMC_RESULT_ENUM_UINT32          enResult;                               /* ������� */
    VOS_UINT8                           aucRsv[4];
} MMC_MTA_FRAT_IGNITION_SET_CNF_STRU;


/*****************************************************************************
  10 ��������
*****************************************************************************/




#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif



#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif
