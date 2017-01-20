

#ifndef __TLL2ErrorLog_H__
#define __TLL2ErrorLog_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include "product_config.h"
#include "omnvinterface.h"
#include "omerrorlog.h"
#include "omringbuffer.h"
#include "SysNvId.h"
#include "LPSCommon.h"

#include "LrrcErrLogInterface.h"

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 macro
*****************************************************************************/
#define TLL2_LTE_RING_BUFFER_SIZE    (1024 * 4)  /* TLL2_LTE errlog ����buffer�Ĵ�С */
#define TLL2_TDS_RING_BUFFER_SIZE    (1024 * 4)  /* TLL2_TDS errlog ����buffer�Ĵ�С */

#define LTE_ERRLOG_L2_STAT_RPT_MAX_NUM         10   /*ͳ��������ϱ�10��*/

/* Modem errlog report, TDS correlative event report for example begin. */
#define TLL2_CORRELATIVE_EVENT_NUM  (10)
/* Modem errlog report, TDS correlative event report for example end. */

#define  TLL2_LMAC_MAX_PREAMBLE_SPEC_NOT_MATCH_RECORED_NUM      (8)
/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

/*****************************************************************************
  4 Enum
*****************************************************************************/

/*****************************************************************************
 ö����    : TLL2_ERRLOG_MODEM_ID_ENUM
 ö��˵��  : TLL2 MODEM_ID
*****************************************************************************/
enum TLL2_ERRLOG_MODEM_ID_ENUM
{
    TLL2_ERRLOG_MODEM_ID_0        = 0x00 ,      /* ���� */
    TLL2_ERRLOG_MODEM_ID_1        = 0x01 ,      /* ���� */
    TLL2_ERRLOG_MODEM_ID_REV1     = 0x02 ,      /* ���� */
    TLL2_ERRLOG_MODEM_ID_REV2     = 0x03 ,      /* ���� */

    TLL2_ERRLOG_MODEM_ID_BUTT
};
typedef VOS_UINT16 TLL2_ERRLOG_MODEM_ID_ENUM_UINT16;

/*****************************************************************************
 ö����    : TLL2_ERRLOG_ALM_LEVEL_ENUM
 ö��˵��  : TLL2�澯����
*****************************************************************************/
enum TLL2_ERRLOG_ALM_LEVEL_ENUM
{
    TLL2_ERRLOG_ALM_LEVEL_CRITICAL   = 0x01,        /*����*/
    TLL2_ERRLOG_ALM_LEVEL_MAJOR      = 0x02,        /*��Ҫ*/
    TLL2_ERRLOG_ALM_LEVEL_MINOR      = 0x03,        /*��Ҫ*/
    TLL2_ERRLOG_ALM_LEVEL_WARNING    = 0x04,        /*��ʾ*/

    TLL2_ERRLOG_ALM_LEVEL_BUTT
};
typedef VOS_UINT16  TLL2_ERRLOG_ALM_LEVEL_ENUM_UINT16;

/*****************************************************************************
 ö����    : TLL2_ERRLOG_ALM_TYPE_ENUM
 ö��˵��  : TLL2�澯 ����
*****************************************************************************/
enum TLL2_ERRLOG_ALM_TYPE_ENUM
{
    TLL2_ERRLOG_ALM_TYPE_COMMUNICATION          = 0x00,     /* ͨ��*/
    TLL2_ERRLOG_ALM_TYPE_QUALITY_OF_SERVICE     = 0x01,     /* ҵ������*/
    TLL2_ERRLOG_ALM_TYPE_PROCESS_ERROR          = 0x02,     /* �������*/
    TLL2_ERRLOG_ALM_TYPE_EQUIPMENT_ERROR        = 0x03,     /* �豸����*/
    TLL2_ERRLOG_ALM_TYPE_ENVIRONMENTAL_ERROR    = 0x04,     /* ��������*/
    TLL2_ERRLOG_ALM_TYPE_MODEM_ERROR            = 0x06,     /* ֱͨ����*/

    TLL2_ERRLOG_ALM_TYPE_BUTT
};
typedef VOS_UINT16  TLL2_ERRLOG_ALM_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : TLL2_LTE_ERROR_ALARM_ID_ENUM
 ö��˵��  : TLL2_LTE �澯ID
*****************************************************************************/
enum TLL2_LTE_ERROR_ALARM_ID_ENUM
{
    TLL2_LTE_ALM_INFO = 1,                  /*LTE L2�澯*/
    TLL2_LTE_STAT_INFO,                     /*L2ͳ����*/
    TLL2_LTE_THR_INFO,                      /*L2����*/
    TLL2_LTE_ERRLOG_ALARM_ID_BUTT
};
typedef VOS_UINT16 TLL2_LTE_ERROR_ALARM_ID_ENUM_UINT16;

/*****************************************************************************
 ö����    : TLL2_LTE_ERROR_TYPE_ENUM
 ö��˵��  : TLL2_LTE �澯����
*****************************************************************************/
enum TLL2_LTE_ERROR_TYPE_ENUM
{
    TLL2_LMAC_RAR_NOTMATCH = 1,
    TLL2_LMAC_RAR_TIMEOUT,
    TLL2_LMAC_CONTENT_TIMEOUT,
    TLL2_LMAC_CONTENT_NOTMATCH,
    TLL2_LMAC_OVER_PBL_MAX_TXNUM,
    TLL2_LMAC_MSG3_FAIL,
    TLL2_LMAC_TA_TIMEOUT,
    TLL2_LMAC_OVER_MAX_SR_SEND,
    TLL2_LRLC_UL_AM_MAX_RETXNUM,
    TLL2_LRLC_DL_TBMEM_FULL,
    TLL2_LPDCP_ERROR_INTEGRITY_VERIFY,
    TLL2_LMAC_DSDS_NO_RF_RA,
    TLL2_LMAC_DSDS_NO_RF_TIMEOUT,
    TLL2_LPDCP_UL_LOSS,                     /*PDCP���ж���*/
    TLL2_LPDCP_UL_MAX_BUFFTIME,             /*PDCP����PDU����ʱ�����*/
    TLL2_LPDCP_DL_LOSS,                     /*PDCP���ж���*/
    TLL2_LMAC_DL_TB_CHECK_ERR,              /*��������*/
    TLL2_LPDCP_UL_SIG_PAS,                  /*���е�ͨ*/
    TLL2_IMS_VOICE_STOP,                    /*VoLTE��������*/
    TLL2_LTE_ERROR_TYPE_BUTT
};
typedef VOS_UINT16 TLL2_LTE_ERROR_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : TLL2_TDS_ERROR_ALARM_ID_ENUM
 ö��˵��  : TLL2_TDS �澯ID
*****************************************************************************/
enum TLL2_TDS_ERROR_ALARM_ID_ENUM
{
    TLL2_TMAC_OUT_OF_SYNC = 1,
    TLL2_TMAC_QUEUE_FULL,
    TLL2_TMAC_SENDMSG_FAIL,
    TLL2_TRLC_RST,
    TLL2_TRLC_UL_BUFFER_FULL,
    TLL2_TPDCP_FAIL,
    TLL2_TMAC_HSUPA_INFO,
    TLL2_TMAC_HSDPA_INFO,
    TLL2_TRLC_UL_TRANS_INFO,
    TLL2_TRLC_DL_TRANS_INFO,
    TLL2_TRLC_STATICS_INFO,

    TLL2_TDS_BUFFER_OVERFLOW,
    TLL2_TDS_ERRLOG_ALARM_ID_BUTT
};
typedef VOS_UINT16 TLL2_TDS_ERROR_ALARM_ID_ENUM_UINT8;

/*****************************************************************************
 ö����    : TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_RESULT_ENUM
 ö��˵��  : LMAC�������ʧ��preamble��ƥ��ʱ�Ľ��
*****************************************************************************/
enum TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_RESULT_ENUM
{
    PREAMBLE_CONSECUTIVE_LESS1_AND_RA_FAIL,  /*���뵽����RAR��preamble�ȷ���preambleС1����,��С���뾶����볡��,�����ս���ʧ���� */
    PREAMBLE_CONSECUTIVE_LESS1_AND_RA_SUCC,  /*���뵽����RAR��preamble�ȷ���preambleС1����,��С���뾶����볡��,�����ս���ɹ��� */
    PREAMBLE_SPEC_NOT_MATCH_BUTT
};
typedef VOS_UINT8 TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_RESULT_ENUM_UINT8;


/*****************************************************************************
   5 STRUCT
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : TLL2_ERRLOG_BUFFER_OVERFLOW_STRU
 �ṹ˵��  : ���������
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /* ERR LOG��Ϣͷ */

    VOS_UINT32                          ulCount;        /* ������������� */
}TLL2_ERRLOG_BUFFER_OVERFLOW_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_CDS_STAT_INFO_STRU
 �ṹ˵��  : LTE CDSͳ����
*****************************************************************************/
typedef struct
{
    /*IPFͳ����*/
    VOS_UINT32                          ulULIpfRxRDNum;
    VOS_UINT32                          ulULIpfFilterErrNum;
    VOS_UINT32                          ulULADQCfgAdNum;
    VOS_UINT32                          ulUlAdqEmptyIntNum;
    VOS_UINT32                          ulDLIpfCfgHaveNoBD;
    VOS_UINT32                          ulDLIpfCfgBDSucc;

    /*����ͳ����*/
    VOS_UINT32                          ulULASRxIpPktNum;
    VOS_UINT32                          ulULLTERxPktNum;
    VOS_UINT32                          ulULLTESendToLPdcpNum;
    VOS_UINT32                          ulULLTEFcFreePktNum;
    VOS_UINT32                          ulULBuffSoftFilterFail;
    VOS_UINT32                          ulULBuffFreePktNum;

    /*����ͳ����*/
    VOS_UINT32                          ulDLLteRxSduNum;
    VOS_UINT32                          ulDLLteEnQueSucc;
    VOS_UINT32                          ulDLLteRxImsNum;
    VOS_UINT32                          ulDLLteFcFreeSduNum;

    /*IMSͳ����*/
    VOS_UINT32                          ulImsULRxNicPktNum;
    VOS_UINT32                          ulImsULSoftFilterFail;
    VOS_UINT32                          ulImsDLSendToNicSucc;
}LTE_ERRLOG_CDS_STAT_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_PDCP_RB_STAT_INFO_STRU
 �ṹ˵��  : LTE L2 PDCPͳ����
*****************************************************************************/
typedef struct
{
    /*����ͳ����*/
    VOS_UINT32                          ulUlRxSduCnt;
    VOS_UINT32                          ulUlTxPduCnt;
    VOS_UINT32                          ulUlAckedSduCnt;
    VOS_UINT32                          ulUlDisSduCnt;
    VOS_UINT32                          ulUlOtherDisSduCnt;
    VOS_UINT32                          ulCompFailCnt;

    /*����ͳ����*/
    VOS_UINT32                          ulDlRxPduCnt;
    VOS_UINT32                          ulDlTxSduCnt;
    VOS_UINT32                          ulDlOutofWinDiscPduCnt;
    VOS_UINT32                          ulDeCompFailCnt;

    /*Cipherͳ����*/
    VOS_UINT32                          ulThrChRxSduCnt;
    VOS_UINT32                          ulThrChEnQueSucc;
    VOS_UINT32                          ulThrChHaveNoBDCnt;
    VOS_UINT32                          ulThrChCfgBdNum;
    VOS_UINT32                          ulNonThrRxSduCnt;
    VOS_UINT32                          ulNonThrEnqueSucc;
    VOS_UINT32                          ulNonThrChHaveNoBDCnt;
    VOS_UINT32                          ulNonThrChCfgBdNum;

}LTE_ERRLOG_PDCP_STAT_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_RLC_RB_STAT_INFO_STRU
 �ṹ˵��  : LTE L2 RLCͳ����
*****************************************************************************/
typedef struct
{
    /*����ͳ����*/
    VOS_UINT32                          ulRxPdcpSdu;
    VOS_UINT32                          ulTxPduToMac;
    VOS_UINT32                          ulTxDataPdu;
    VOS_UINT32                          ulTxCtrlPdu;
    VOS_UINT32                          ulTotalDropSdu;
    VOS_UINT32                          ulTotalRetxPdu;

    /*����ͳ����*/
    VOS_UINT32                          ulRxMacPdu;
    VOS_UINT32                          ulTxSduToPdcpSucc;
    VOS_UINT32                          ulRxDataPdu;
    VOS_UINT32                          ulRxCtrlPdu;

}LTE_ERRLOG_RLC_STAT_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_MAC_STAT_INFO_STRU
 �ṹ˵��  : LTE L2 MACͳ����
*****************************************************************************/

typedef struct
{
    /*����ͳ����*/
    VOS_UINT32                          ulMacRecvRlcPduTotal;
    VOS_UINT32                          ulMacSchedMacPduSuccNum;
    VOS_UINT32                          ulMacSchedFailNum;
    VOS_UINT32                          ulRecvUlGrantNum;
    VOS_UINT32                          ulBuffLen;
    VOS_UINT32                          ulTaTimeOutNum;

    /*����ͳ����*/
    VOS_UINT32                          ulDlMacGetDlTbNum;
    VOS_UINT32                          ulActSendRlcNum;
    VOS_UINT32                          ulDlTbCheckErr;
    VOS_UINT32                          ulRecvScellActivation;

}LTE_ERRLOG_MAC_STAT_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_L2_STAT_INFO_STRU
 �ṹ˵��  : LTE L2����ͳ����Ϣ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCurInd;
    VOS_UINT8                           ucRsv[3];
    LTE_ERRLOG_CDS_STAT_INFO_STRU       astCDSStatInfo[LTE_ERRLOG_L2_STAT_RPT_MAX_NUM];
    LTE_ERRLOG_PDCP_STAT_INFO_STRU      astLPDCPStatInfo[LTE_ERRLOG_L2_STAT_RPT_MAX_NUM];
    LTE_ERRLOG_RLC_STAT_INFO_STRU       astLRLCStatInfo[LTE_ERRLOG_L2_STAT_RPT_MAX_NUM];
    LTE_ERRLOG_MAC_STAT_INFO_STRU       astLMACStatInfo[LTE_ERRLOG_L2_STAT_RPT_MAX_NUM];
}LTE_ERRLOG_L2_STAT_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_L2_SINGLE_THR_INFO_STRU
 �ṹ˵��  : LTE L2����ͳ����Ϣ�洢��Ԫ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulAppUlRate;           /*APP��������*/
    VOS_UINT32                          ulAppDlRate;           /*APP��������*/
    VOS_UINT32                          ulPdcpUlRate;          /*PDCP��������*/
    VOS_UINT32                          ulPdcpDlRate;          /*PDCP��������*/
    VOS_UINT32                          ulRlcUlRate;           /*RLC��������*/
    VOS_UINT32                          ulRlcDlRate;           /*RLC��������*/
    VOS_UINT32                          ulMacUlRate;           /*MAC��������*/
    VOS_UINT32                          ulMacDlRate;           /*MAC��������*/
}LTE_ERRLOG_L2_SINGLE_THR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_L2_THR_INFO_RPT_STRU
 �ṹ˵��  : LTE L2����ͳ����Ϣ�洢�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucCurInd;
    VOS_UINT8                                   ucRsv[3];
    LTE_ERRLOG_L2_SINGLE_THR_INFO_STRU          astL2ThrInfo[LTE_ERRLOG_L2_STAT_RPT_MAX_NUM];
}LTE_ERRLOG_L2_THR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_L2_ALM_INFO_RPT_STRU
 �ṹ˵��  : LTE L2�쳣�����ϱ��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /*ERR LOG��Ϣͷ*/

    TLL2_LTE_ERROR_TYPE_ENUM_UINT16     enErrType;      /*�쳣����*/
    VOS_UINT8                           ucRbId;         /*��������ID*/
    VOS_UINT8                           ucRabId;        /*�ǽ�������ID*/
    VOS_UINT8                           ucIsIms;        /*IMSҵ��ָʾ��0:��IMS��1:IMS*/
    VOS_UINT8                           ucRsv[3];       /*4�ֽڶ���*/
}LTE_ERRLOG_L2_ALM_INFO_RPT_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_L2_STAT_INFO_RPT_STRU
 �ṹ˵��  : LTE L2ͳ�����ϱ��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /*ERR LOG��Ϣͷ*/

    LTE_ERRLOG_L2_STAT_INFO_STRU        stL2StatInfo;   /*ͳ����*/
}LTE_ERRLOG_L2_STAT_INFO_RPT_STRU;

/*****************************************************************************
 �ṹ��    : LTE_ERRLOG_L2_THR_INFO_RPT_STRU
 �ṹ˵��  : LTE L2�����ϱ��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /*ERR LOG��Ϣͷ*/

    LTE_ERRLOG_L2_THR_INFO_STRU         stL2ThrInfo;    /*����*/
}LTE_ERRLOG_L2_THR_INFO_RPT_STRU;

/* Modem errlog report, TDS correlative event report for example begin. */
typedef struct
{
    VOS_UINT8                                   uccause;              /*T312 expired��0��T313 expired��1*/
    VOS_UINT8                                   ucinActivationTime;
    VOS_UINT8                                   uctfcsIdentity;
    VOS_UINT8                                   ucReserved;
}TLL2_OOS_INFO_STRU;

typedef struct
{
    VOS_UINT16                                   usFaultID;
    VOS_UINT16                                   usAlarmID;
    LPS_32K_TIMESTAMP                            stTimeStamp;
    VOS_UINT32                                   ulDataLen;
    VOS_UINT8                                    *pdata;
}TLL2_RELATION_EVENT_RECORD_STRU;

typedef struct
{
     VOS_UINT32                                  ulIndex;
     TLL2_RELATION_EVENT_RECORD_STRU             stErrLogEventRecord[TLL2_CORRELATIVE_EVENT_NUM];
}TLL2_RELATION_EVENT_POOL_STRU;
/* Modem errlog report, TDS correlative event report for example end. */
/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_MAC_OUTOFSYNC_INFO
 �ṹ˵��  : MACʧ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;           /* ERR LOG��Ϣͷ */
    VOS_UINT8                           cause;              /*T312 expired��0��T313 expired��1*/
    VOS_UINT8                           inActivationTime;
    VOS_UINT8                           tfcsIdentity;
    VOS_UINT8                           aucRev;             /*4�ֽڶ���*/
}TDS_ERRLOG_MAC_OUTOFSYNC_INFO;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_MAC_QUEUEFULL_INFO
 �ṹ˵��  : MAC�������ṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /* ERR LOG��Ϣͷ */
    VOS_UINT32                          LossMsgID;
}TDS_ERRLOG_MAC_QUEUEFULL_INFO;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_MAC_SENDMSGFAIL_INFO
 �ṹ˵��  : MAC��Ϣ����ʧ�ܽṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /* ERR LOG��Ϣͷ */
    VOS_UINT32                          FailMsgID;
}TDS_ERRLOG_MAC_SENDMSGFAIL_INFO;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_RLC_RST_INFO
 �ṹ˵��  : RLC RST��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /* ERR LOG��Ϣͷ */
    VOS_UINT8                           rbIdentity;
    VOS_UINT8                           aucRev[3];      /*4�ֽڶ���*/
}TDS_ERRLOG_RLC_RST_INFO;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_RLC_UL_BUFFERFULL_INFO
 �ṹ˵��  : RLC UL buffer ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /* ERR LOG��Ϣͷ */
    VOS_UINT8                           rbIdentity;
    VOS_UINT8                           aucRev[3];      /*4�ֽڶ���*/
}TDS_ERRLOG_RLC_UL_BUFFERFULL_INFO;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_PDCP_FAIL_INFO
 �ṹ˵��  : pdcp������Ϣ�ϱ�����
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;       /* ERR LOG��Ϣͷ */
    VOS_UINT32                          failCause;
}TDS_ERRLOG_PDCP_FAIL_INFO;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_MAC_HSUPA_INFO_STRU
 �ṹ˵��  TDS MAC HSUPA��Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;

    VOS_UINT16                          usSysFramNo;    /*ϵͳ֡��*/
    VOS_UINT16                          usTbSize;       /*MAC UPA������Ȩ��С*/

    VOS_UINT8                           ucSnpl;         /*MAC UPA SNPL ����·��ֵ*/
    VOS_UINT8                           ucUph;          /*MAC UPA UPH*/
    VOS_UINT8                           ucTebs;         /*MAC UPA TEBS*/
    VOS_UINT8                           ucPrri;         /*MAC UPA PRRI*/

    VOS_UINT8                           ucTrri;         /*MAC UPA TRRI*/
    VOS_UINT8                           ucCrri;         /*MAC UPA CRRI*/
    VOS_UINT8                           ucRscpLevel;    /*MAC ����С��RSCPֵ*/
    VOS_UINT8                           ucRsv;          /*����*/

}TDS_ERRLOG_MAC_HSUPA_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_MAC_HSDPA_INFO_STRU
 �ṹ˵��  TDS MAC HSDPA��Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;
    VOS_UINT16                          usSysFramNo;    /*ϵͳ֡��*/
    VOS_UINT16                          usTsn;          /*MAC HSDPA ����SNֵ*/
    VOS_UINT16                          usExpectedSn;   /*MAC HSDPA �ڴ�����һ��SN*/
    VOS_UINT16                          usTbSize;       /*MAC HSDPA ������Ȩ��С*/

}TDS_ERRLOG_MAC_HSDPA_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_L2_STATICS_INFO_STRU
 �ṹ˵��  TDS L2����ͳ����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;

    VOS_UINT16                          usSysFramNo;    /*ϵͳ֡��*/
    VOS_UINT16                          usRsv;

    VOS_UINT8                           ucMacState;     /*MAC��ǰ״̬*/
    VOS_UINT8                           ucHsupaFlag;    /*MAC HSUPA�Ƿ���Ч*/
    VOS_UINT8                           ucHsdpaFlag;    /*MAC HSDPA�Ƿ���Ч*/
    VOS_UINT8                           ucRbId;         /*RB IDֵ*/

    VOS_UINT32                          ulPdcpUlRxNum;  /*PDCP���д�RABM���յ���SDU��Ŀ*/
    VOS_UINT32                          ulPdcpUlTxNum;  /*PDCP�����з������ݰ�����*/
    VOS_UINT32                          ulRlcUlTxNum;   /*RLC�����з������ݰ�����*/
    VOS_UINT32                          ulMacUlTxNum;   /*MAC�����з������ݰ�����*/

    VOS_UINT32                          ulPdcpDlTxNum;  /*PDCP���з��͸�RABM��SDU��Ŀ*/
    VOS_UINT32                          ulPdcpDlRxNum;  /*PDCP�����н������ݰ�����*/
    VOS_UINT32                          ulRlcDlRxNum;   /*RLC�����н������ݰ�����*/
    VOS_UINT32                          ulMacDlRxNum;   /*MAC�����н������ݰ�����*/

}TDS_ERRLOG_L2_STATICS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_RLC_UL_TRANS_INFO_STRU
 �ṹ˵��  TDS L2 RLC����������Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU              stHeader;

    VOS_UINT16                          usSysFramNo;    /*ϵͳ֡��*/
    VOS_UINT16                          usUlSendSn;     /*RLC�����з��͵�PDU SNֵ*/

    VOS_UINT8                           ucRbId;         /*RB ID*/
    VOS_UINT8                           ucPduSize;      /*RLC ��PDU ��С����λbyte*/
    VOS_UINT8                           ucPduNum;       /*һ�����RLC PDU����*/
    VOS_UINT8                           ucRsv;

    VOS_UINT32                          ulRlcBo;        /*RLC �㻺����ͳ��*/
    VOS_UINT32                          ulPdcpBo;       /*PDCP �㻺����ͳ��*/

    VOS_UINT16                          usVTs;          /*RLC �㴰�ڱ���VTS*/
    VOS_UINT16                          usVTa;          /*RLC �㴰�ڱ���VTA*/

}TDS_ERRLOG_RLC_UL_TRANS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_RLC_DL_TRANS_INFO_STRU
 �ṹ˵��  TDS L2 RLC����������Ϣ�ṹ��
*****************************************************************************/
typedef struct
{

    OM_ERR_LOG_HEADER_STRU              stHeader;

    VOS_UINT16                          usSysFramNo;    /*ϵͳ֡��*/
    VOS_UINT16                          usDlRecvSn;     /*RLC�����з��͵�PDU SNֵ*/


    VOS_UINT8                           ucRbId;         /*RB ID*/
    VOS_UINT8                           ucPduSize;      /*RLC ��PDU ��С����λbyte*/
    VOS_UINT8                           ucPduNum;       /*һ�����RLC PDU����*/
    VOS_UINT8                           ucRsv;

    VOS_UINT16                          usVRr;          /*RLC �㴰�ڱ���VR(R)*/
    VOS_UINT16                          usVRh;          /*RLC �㴰�ڱ���VR(H)*/

}TDS_ERRLOG_RLC_DL_TRANS_INFO_STRU;


/*****************************************************************************
 �ṹ��    : TLL2_OM_ERR_LOG_IND_STRU
 �ṹ˵��  : Balongƽ̨�ڲ������������ϱ�Fault���ݽṹ
*****************************************************************************/

typedef OM_FAULT_ERR_LOG_IND_STRU TLL2_OM_ERR_LOG_IND_STRU;

/*****************************************************************************
Description    : TLL2_DIRECT_CHR_COMMON_STRUֱͨCHR���������ϱ����ݽṹģ��
�޸���ʷ :
 1.��    ��    : 2016��7��27��
   ��    ��    : n00181501
   �޸�����    : modem chrֱͨ�½��ṹ
*****************************************************************************/

typedef struct
{
    OM_ERR_LOG_HEADER_STRU                              stOmHead;
    MODEM_ERR_LOG_HEADER_STRU                           StModemHead;
    VOS_UINT8                                           aucMsgContent[4];
}TLL2_DIRECT_CHR_COMMON_STRU;

/*****************************************************************************
 �ṹ��    :LMAC_OM_PRACH_CONFIG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucPrachConfigIndex;                     /*�Ѿ�ȷ��:Prach-ConfigurationIndex,0-63*/
    VOS_UINT8                           ucPrachFormat;
    VOS_UINT8                           ucHighSpeedFlag;
    VOS_UINT8                           ucZeroCorrelationZoneConfig;
}LMAC_OM_PRACH_CONFIG_STRU;

/*****************************************************************************
�ṹ��    : TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU
Э����  :
ASN.1���� :
�ṹ˵��  : һ��preamble��ƥ���¼����ϸ����
*****************************************************************************/
typedef struct
{
    TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_RESULT_ENUM_UINT8 enRaResult; /*���յ�ע���� */
    VOS_UINT8               ucRsv;
    VOS_UINT16              usSelfAdjTaTimes; /*����TA�Ĵ�����ͳ�Ʒ���PHY��selfAdjTaFlag�Ĵ��� */
    LRRC_OM_SCELL_ID        stCellInfo;       /*����С����Ϣ */
    LMAC_OM_PRACH_CONFIG_STRU stPrachConfig;    /*prach���ò��� */
}TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU;

/*****************************************************************************
�ṹ��    : LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU
Э����  :
ASN.1���� :
�ṹ˵��  : ����OM��preamble��ƥ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8  ucRecordNum;
    VOS_UINT8  aucRsv[3];
    TLL2_LMAC_PREAMBLE_SPEC_NOT_MATCH_LOG_STRU astPblSpecNotMatchLog[TLL2_LMAC_MAX_PREAMBLE_SPEC_NOT_MATCH_RECORED_NUM];
}LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU;

/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/
extern TLL2_RELATION_EVENT_POOL_STRU             g_stTL2ErrLogPool;


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

#endif /* end of TLL2ErrorLog.h */
