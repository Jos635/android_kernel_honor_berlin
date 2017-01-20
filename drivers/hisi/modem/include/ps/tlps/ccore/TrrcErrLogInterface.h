

#ifndef __TRRCERRLOGINTERFACE_H__
#define __TRRCERRLOGINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include "omerrorlog.h"
#pragma pack(4)

/*****************************************************************************
  2 macro
*****************************************************************************/
#include  "vos.h"
#include "omerrorlog.h"
#include "omringbuffer.h"
#include "LPsOm.h"

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/
/* TDS���������������ϱ���ǿ3������ */
#define TRRC_APP_MAX_NCELL_NUM                              (3)
#define TRRC_OM_MAX_TDS_CELLS_NUM_WITHOUT_LTE_NCELL         (5)

#if (FEATURE_ON == FEATURE_PTM)
/*TRRC����ʧ��ʱ���ﵽ�ϱ�CHR�Ĵ���*/
#define TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM                  (2)

#define MAX_TDS_FREQ_NUM                                    (50)

/* Modem errlog report, TDS correlative event report for example begin. */
/* TRRC �����¼����� */
#define TRRC_CORRELATIVE_EVENT_MAX_NUM                      (10)
#define TRRC_FaultIDRPT_MAX_NUM                             (10)
/* Modem errlog report, TDS correlative event report for example end. */

#endif
/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 ö����    : TRRC_ERRORLOG_ALARM_ID_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : ERRORLOG ALARM_ID����
*****************************************************************************/
enum TRRC_ERRORLOG_ALARM_ID_ENUM
{
    TRRC_ERRORLOG_ALARM_ID_EST_FAIL           =1,   /* ����ʧ��*/
    TRRC_ERRORLOG_ALARM_ID_RB_FAIL,                 /* RB����ʧ�� */
    TRRC_ERRORLOG_ALARM_ID_RBREC_FAIL,              /* RB������ʧ�� */
    TRRC_ERRORLOG_ALARM_ID_CELLUPDATE_FAIL,         /* CELLUPDATEʧ�� */
    TRRC_ERRORLOG_ALARM_ID_AREA_LOST,               /* ���� */
    TRRC_ERRORLOG_ALARM_ID_INTEGRITY_FAIL,          /* ��������֤ʧ��*/
    TRRC_ERRORLOG_ALARM_ID_ASN_RSLT_FAIL,           /* asn������� */
    TRRC_ERRORLOG_ALARM_ID_MEAS_CTRL_FAIL,          /* �������ô��� */
    TRRC_ERRORLOG_ALARM_ID_CS_HO_FAIL,              /* CS�л�ʧ�ܸ澯 */
    TRRC_ERRORLOG_ALARM_ID_CS_HO_EXP,               /* CS�л���ʱ�澯 */
    TRRC_ERRORLOG_ALARM_ID_RL_FAIL,                 /* ������·ʧ�ܸ澯 */
    TRRC_ERRORLOG_ALARM_ID_BUFF_OVER_FLOW,          /* ��������澯*/
    TRRC_ERRORLOG_ALARM_ID_NOT_TO_LTE,              /* ��ʱ�䲻��LTE�澯*/
    TRRC_ERRORLOG_ALARM_ID_CS_SIGNAL_REL,           /* cs�ͷŸ澯*/
    TRRC_ERRORLOG_ALARM_ID_CS_NO_RB_SETUP,          /* TRRC CS���绰ʱ��û��RB SETUP����� */
    TRRC_ERRORLOG_ALARM_ID_CS_T2G_CCO,              /* TRRC CS���绰ʱ��������T��G��CCO���� */
    TRRC_ERRORLOG_ALARM_ID_RSVD_MSG_MAX,            /* TRRC����װ��RRC CONN SETUP COMPLETE�����CNF̬,��ʱ�յ�����
                                                       UM_DATA_IND��ʹ����ﵽ���ֵ��CONN TO IDLE���� */
    TRRC_ERRORLOG_ALARM_ID_PRACH_CCODE_INFO,              /*˫�����Ϣ�����*/
    TRRC_ERRORLOG_ALARM_ID_OUT_OF_SYNC,             /* TRRC������ʧ������ */
    TRRC_ERRORLOG_ALARM_ID_OUT_OF_SYNC_CELL_UPDATE, /* TRRC��ʧ����Ȼ��������CELL UPDATE���� */
    TRRC_ERRORLOG_ALARM_ID_CS_ASY_CELL_UPDATE,      /* ��绰�����У�TRRC��ʧ����Ȼ��������CELL UPDATE���� */
    TRRC_ERRORLOG_ALARM_ID_COLLECT_TDS_FREQ_REPORT,                             /* �ռ�TDSƵ����Ϣ�ϱ� */
    TRRC_ERRORLOG_ALARM_ID_NOT_TO_EUTRA,
    TRRC_ERRORLOG_ALARM_ID_BUTT
};
typedef VOS_UINT16  TRRC_ERRORLOG_ALARM_ID_ENUM_UINT16;

/*****************************************************************************
 ö����    : TRRC_ERRORLOG_ALARM_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : ���ø澯����ö�ٶ���
*****************************************************************************/
enum TRRC_ERRORLOG_ALARM_TYPE_ENUM
{
    TRRC_ERRORLOG_ALARM_TYPE_COMMUNICATION             = 1 ,      /* ��ʾͨ��: ����ȷ�ϴ�1��ʼ��GUTL�ֱ����*/
    TRRC_ERRORLOG_ALARM_TYPE_TRANSACTION_QULITY            ,      /* ��ʾҵ������ */
    TRRC_ERRORLOG_ALARM_TYPE_PROCESS_ERROR                 ,      /* ��ʾ������� */
    TRRC_ERRORLOG_ALARM_TYPE_EQIPMENT_ERROR                ,      /* ��ʾ�豸���� */
    TRRC_ERRORLOG_ALARM_TYPE_ENVIR_ERROR                   ,      /* ��ʾ�������� */

    /* Modem errlog report, modem chr to ap interface alarmtype define begin */
    TRRC_ERRORLOG_ALARM_TYPE_MODEM_ERROR               = 6 ,      /* ��ʾModemֱͨ */
    /* Modem errlog report, modem chr to ap interface alarmtype define end */

    TRRC_ERRORLOG_ALARM_TYPE_BUTT
};
typedef VOS_UINT16  TRRC_ERRORLOG_ALARM_TYPE_ENUM_UINT16;


/*****************************************************************************
 ö����    : RRC_APP_ERROR_CODE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : RRC����������
*****************************************************************************/
enum TRRC_APP_ERROR_CODE_ENUM
{
    TRRC_APP_RB_PROTOCOL_CHECK_ERR            = 0,   /* RB����ʧ��--Protocol���ʧ�� */
    TRRC_APP_RB_TRANSACTION_CHECK_ERR,               /* RB����ʧ��--Transaction ID���ʧ�� */
    TRRC_APP_RB_INTEGRITY_CHECK_ERR,                 /* RB����ʧ��--Integrity���ʧ�� */

    TRRC_APP_RBREC_PROTOCOL_CHECK_ERR         = 10,  /* RB������ʧ��--Protocol���ʧ�� */
    TRRC_APP_RBREC_TRANSACTION_CHECK_ERR,            /* RB������ʧ��--Transaction ID���ʧ�� */
    TRRC_APP_RBREC_INTEGRITY_CHECK_ERR,              /* RB������ʧ��--Integrity���ʧ�� */

    TRRC_APP_CELLUPDATECNF_PROTOCOL_CHECK_ERR     =20,  /* С������ʧ��--Protocol���ʧ�� */
    TRRC_APP_CELLUPDATECNF_TRANSACTION_CHECK_ERR,       /* С������ʧ��--Transaction ID���ʧ�� */
    TRRC_APP_CELLUPDATECNF_INTEGRITY_CHECK_ERR,         /* С������ʧ��--Integrity���ʧ�� */

    TRRC_APP_EST_T300_ERR                         =30,  /* ��������N300ʱ��¼ */
    TRRC_APP_EST_CS_ACC_PROBABILITY_ERR,                /* CS����AC�ȼ��ж�ʧ�� */
    TRRC_APP_EST_PS_ACC_PROBABILITY_ERR,                /* PS����AC�ȼ��ж�ʧ�� */

    TRRC_APP_EST_AREA_LOST_ERR                    =40,  /* RRC���� */
    TRRC_APP_ASN_RLST_ERR,                              /* ASN�������� */
    TRRC_APP_AM_INTEGRITY_CHECK_ERR,                    /* AM���������Լ��ʧ�� */
    TRRC_APP_UM_INTEGRITY_CHECK_ERR,                    /* UM���������Լ��ʧ�� */

    TRRC_APP_MEAS_CTRL_PROTOCOL_CHECK_ERR         =50,  /* ��������ʧ��--Protocol���ʧ�� */
    TRRC_APP_MEAS_CTRL_TRANSACTION_CHECK_ERR,           /* ��������ʧ��--Transaction ID���ʧ�� */

    TRRC_APP_HO_FAIL_ERR                          =60,  /* �л�ʧ�� */
    TRRC_APP_HO_TIMER_EXP_ERR,                          /* �л���ʱ */

    TRRC_APP_RL_FAIL_ERR                          =70,  /* ������·ʧ�� */

    TRRC_APP_CS_SIGINAL_REL                       =80,  /* cs����·�ͷ� */
    TRRC_APP_CS_NOFLOW_OUTOFSYNC                  = 90, /*TRRC CS���绰ʱ������û���յ����߷��ͳɹ�ĳ�����̣����º���UE������ʧ������*/
    TRRC_APP_CS_OUTOFSYNC_NOFLOW                  = 91, /*TRRC CS���绰ʱ������UE�ȷ�����ʧ�����̣�����û���յ����߷��ͳɹ�ĳ������*/
    TRRC_APP_CS_NOFLOW_RRCCONNREL                 = 92, /*TRRC CS���绰ʱ��UE��һ��ʱ���� û���յ����߷��ͳɹ�ĳ�����̣�Ȼ�������·���RRC CONN REL*/
    TRRC_APP_CS_NOFLOW_SIGNALCONNREL              = 93, /*TRRC CS���绰ʱ��UE��һ��ʱ���� û���յ����߷��ͳɹ�ĳ������P��Ȼ�������·���SIGNAL CONN REL*/
    TRRC_APP_CS_NOFLOW_GURELREQ                   = 94, /*TRRC CS���绰ʱ��UE��һ��ʱ���� û���յ����߷��ͳɹ�ĳ�����̣�Ȼ��GU �·���REL REQ*/
    TRRC_APP_CS_NOFLOW_GUTRANSNTFY                = 95, /*TRRC CS���绰ʱ��UE��һ��ʱ���� û���յ����߷��ͳɹ�ĳ�����̣�Ȼ��GU �·���TRANS STATUS NOTIFY������Я����ԭ��ֵΪTRANS_FAIL*/
    TRRC_APP_CS_NOFLOW_OTHER                      = 96, /*TRRC CS���绰ʱ��UE��һ��ʱ���� û���յ����߷��ͳɹ�ĳ�����̣�������ERR CODE ԭ��ֵ*/
    TRRC_APP_CS_T2G_CCO                           = 97, /*TRRC CS���绰ʱ��������T��G��CCO����*/
    TRRC_APP_RRC_CONNSETUP_RSVD_MSG_MAX           = 98, /*TRRC����װ��RRC CONN SETUP COMPLETE�����CNF̬,��ʱ�յ�����
                                                          UM_DATA_IND��ʹ����ﵽ���ֵ��CONN TO IDLE����*/
    TRRC_APP_PRACH_CODE_INFO_ERR                  = 100, /*˫�����Ϣ�Ĵ�����*/
    TRRC_APP_OUT_OF_SYNC                          = 99, /*TRRC������ʧ������*/
    TRRC_APP_OUT_OF_SYNC_CELL_UPDATE              = 101,/*TRRC�ȷ���ʧ�����̣�Ȼ��������CELL UPDATE����*/
    TRRC_APP_CS_OUT_OF_SYNC_CELL_UPDATE           = 102,/*CS CALLʱ��TRRC�ȷ���ʧ�����̣�Ȼ��������CELL UPDATE����*/
    TRRC_APP_COLLECT_TDS_FREQ_REPORT              = 103,                        /* �ռ�TDSƵ����Ϣ�ϱ� */
    TRRC_APP_NOT_TO_EUTRA                         = 103,/*��ʱ�䲻��4G*/
    TRRC_APP_ERR_CODE_BUTT
};
typedef VOS_UINT8 TRRC_APP_ERROR_CODE_ENUM_UINT8;

/*****************************************************************************
 ö����    : TRRC_APP_FTM_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����ģʽ�ϱ����ͣ����������ϱ������º��ϱ���
*****************************************************************************/
enum TRRC_APP_FTM_TYPE_ENUM
 {
    TRRC_APP_FTM_PERIOD_INFO,     /* �������ϱ��Ĺ���ģʽ��Ϣ��ĿǰIdle״̬�ϱ�����ΪDRX���ڣ�Connected״̬������Ϊ1�� */
    TRRC_APP_FTM_CHANGE_INFO,     /* ���º��ϱ��͵Ĺ���ģʽ��Ϣ������ϱ����������� */
    TRRC_APP_FTM_INFO_BUIT
 };
 typedef VOS_UINT32 TRRC_APP_FTM_TYPE_ENUM_UINT32;

 /*********************************************************
 ö����    : TRRC_APP_FTM_CHANGE_INFO_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����ϱ�����ģʽ���Ͷ���
**********************************************************/
 enum TRRC_APP_FTM_CHANGE_INFO_TYPE_ENUM
 {
     TRRC_APP_FTM_CHANGE_CELL_INFO,      /* RRCפ��С����Ϣ���仯���ϱ����л�����ѡ��ɺ��ϱ� */
     TRRC_APP_FTM_CHANGE_STATE_INFO,     /* RRC״̬��Ϣ���仯���ϱ� */

     TRRC_APP_FTM_CHANGE_BUTT
 };
  typedef VOS_UINT32 TRRC_APP_FTM_CHANGE_INFO_TYPE_ENUM_UINT32;

 /*****************************************************************************
  ö����    : TRRC_APP_PROTOCOL_STATE_ENUM
  Э����  :
  ASN.1���� :
  ö��˵��  : TRRCЭ��״̬
 *****************************************************************************/
 enum TRRC_APP_PROTOCOL_STATE_ENUM
 {
     TRRC_APP_PROTOCOL_STATE_IDLE                           = 0,                /* IDLE̬ */
     TRRC_APP_PROTOCOL_STATE_CELL_PCH                          ,                /* CELL_PCH̬ */
     TRRC_APP_PROTOCOL_STATE_URA_PCH                           ,                /* URA_PCH̬ */
     TRRC_APP_PROTOCOL_STATE_CELL_FACH                         ,                /* CELL_FACH̬ */
     TRRC_APP_PROTOCOL_STATE_CELL_DCH                          ,                /* CELL_DCH̬ */

     TRRC_APP_PROTOCOL_STATE_BUTT
 };
 typedef VOS_UINT8 TRRC_APP_PROTOCOL_STATE_ENUM_UINT8;

 /*****************************************************************************
  ö����     :TRRC_APP_GRR_BANDINDICATOR_ENUM
  Э����  :
  ASN.1����   :
  ö��˵�� : 2GС��Ƶ��ָʾ
 *****************************************************************************/
 enum TRRC_APP_GRR_BANDINDICATOR_ENUM
 {
     TRRC_APP_GRR_BANDINDICATOR_DCS1800       = 0,
     TRRC_APP_GRR_BANDINDICATOR_PCS1900       ,

     TRRC_APP_GRR_BANDINDICATOR_BUTT
 };
 typedef VOS_UINT16    TRRC_APP_GRR_BANDINDICATOR_ENUM_UINT16;

  /*****************************************************************************
  ö����     :TRRC_APP_RRC_STATE_ENUM
  Э����  :
  ASN.1����   :
  ö��˵�� : RRC״̬���ڲ�״̬����Э��״̬
 *****************************************************************************/
 enum TRRC_APP_RRC_STATE_ENUM
 {
    TRRC_APP_NUL,   // 0x00  /* TTRRC_APP_CHANGE FOR ע��: ����ǰ���Ͷ�ʧ����*/
    TRRC_APP_SEL,   // 0x01
    TRRC_APP_IDL,   // 0x02
    TRRC_APP_RES,   // 0x03
    TRRC_APP_ACC,   // 0x04
    TRRC_APP_FCH,   // 0x05
    TRRC_APP_DCH,   // 0x06
    TRRC_APP_PCH,   // 0x07
    TRRC_APP_WCA,   // 0x08
    TRRC_APP_REL,   // 0x09
    TRRC_APP_CNF,   // 0x0A
    TRRC_APP_LIM,   // 0x0b
    TRRC_APP_SNW,   // 0x0c
    TRRC_APP_INACTIVE,//0x0d PDM100 200909 for dual mode
    TRRC_APP_PREDEF,  //PDM100 200909 for SIB16
    TRRC_APP_PEND,    //PDM100 200909 for inter-RAT res and CCO
    TRRC_APP_RATHO,   //PDM100 200909 for inter-RAT HO
    TRRC_APP_WAIT,
    TRRC_APP_POWEROFF
 };
typedef VOS_UINT8 TRRC_APP_RRC_STATE_ENUM_UINT8;
/*****************************************************************************
 ö����    : TRRC_FLOW_CTRL_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ���̿�������ö��
             �޸�ö��ʱ��Ҫע�⣬ʧ������ȡֵ = ��������ȡֵ+1
 ����: LRRC_FLOW_CTRL_TYPE_G2L_RESEL_FAIL = LRRC_FLOW_CTRL_TYPE_G2L_START_RESEL + 1
*****************************************************************************/
enum TRRC_APP_FLOW_CTRL_TYPE_ENUM
{
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL            = 0,     /* TDS�����̱߽� */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL_IDL_SYS_UPDATA,     /* TDS������IDL̬ϵͳ��Ϣ���²����������� */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL_PCH_SYS_UPDATA,     /* TDS������PCH̬ϵͳ��Ϣ���²����������� */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL_ENTER_PCH,          /* TDS�����̴�����״̬��DCH/FACH->PCH̬ת������ */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL_ENTER_FCH,          /* TDS�����̴�����״̬��IDL->FCH̬ת������ */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL_ENTER_DCH,          /* TDS�����̴�����״̬��IDL->DCH̬ת������ */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_RES_ENTER_FCH,             /* TDS��������ѡ�����FCH״̬���� */
    /* TL RESEL PHASE2 begin */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NAS_SUSPEND,               /* TDS������NAS�������� */
    /* TL RESEL PHASE2 end */
    TRRC_APP_FLOW_CTRL_TYPE_T2T_NORMAL_END,                /* TDS�����̱߽� */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_START_RESEL,               /* G->T��ʼ��ѡ */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_RESEL_FAIL,                /* G->T��ѡʧ�� */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_STOP_RESEL,                /* G->Tֹͣ��ѡ */

    TRRC_APP_FLOW_CTRL_TYPE_T2G_START_RESEL,               /* T->G��ʼ��ѡ */
    TRRC_APP_FLOW_CTRL_TYPE_T2G_RESEL_FAIL,                /* T->G��ѡʧ�� */

    TRRC_APP_FLOW_CTRL_TYPE_G2T_MEAS,                      /* G->T �������� */
    /* TL RESEL BEGIN */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_START_RESEL,               /* L->T��ʼ��ѡ */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_RESEL_FAIL,                /* L->T��ѡʧ�� */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_STOP_RESEL,                /* L->Tֹͣ��ѡ */

    TRRC_APP_FLOW_CTRL_TYPE_L2T_IDLE_MEAS,                 /* L->T IDLE�������� */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_CONN_MEAS,                 /* L->T CONN�������� */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_RELALL,                    /* L->T RELALL */

    TRRC_APP_FLOW_CTRL_TYPE_T2L_START_RESEL,               /* T->L��ʼ��ѡ */
    TRRC_APP_FLOW_CTRL_TYPE_T2L_RESEL_FAIL,                /* T->L��ѡʧ�� */

	/* TOER_HO BEGIN */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_START_CCO,                 /* G->T��ʼCCO */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_CCO_FAIL,                  /* G->T CCOʧ�� */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_STOP_CCO,                  /* G->TֹͣCCO */

    TRRC_APP_FLOW_CTRL_TYPE_T2G_START_CCO,                 /* T->G��ʼCCO */
    TRRC_APP_FLOW_CTRL_TYPE_T2G_CCO_FAIL,                  /* T->G CCOʧ�� */

    TRRC_APP_FLOW_CTRL_TYPE_T2L_START_HO,                  /* T->L��ʼ�л� */
    TRRC_APP_FLOW_CTRL_TYPE_T2L_HO_FAIL,                   /* T->L�л�ʧ�� */

    TRRC_APP_FLOW_CTRL_TYPE_L2T_START_HO,                  /* L->T��ʼHO */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_HO_FAIL,                   /* L->T HOʧ�� */
    TRRC_APP_FLOW_CTRL_TYPE_L2T_STOP_HO,                   /* L->TֹͣHO */

    TRRC_APP_FLOW_CTRL_TYPE_T2G_START_HO,                  /* T->G��ʼ�л� */
    TRRC_APP_FLOW_CTRL_TYPE_T2G_HO_FAIL,                   /* T->G�л�ʧ�� */

    TRRC_APP_FLOW_CTRL_TYPE_G2T_START_HO,                  /* G->T��ʼHO */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_HO_FAIL,                   /* G->T HOʧ�� */
    TRRC_APP_FLOW_CTRL_TYPE_G2T_STOP_HO,                   /* G->TֹͣHO */
    /* TOER_HO END */

    TRRC_APP_FLOW_CTRL_TYPE_T2T_SYSCFG_SUSPEND,            /* TDS���������ҹ������� */
    /* TL RESEL end */
    /* TL Redir begin */
    TRRC_APP_FLOW_CTRL_TYPE_T2L_REDIR,                     /* T->L�ض��� */
    /* TL Redir end */
    LRRC_APP_FLOW_CTRL_TYPE_L2T_REDIR_FAIL,                /* L->W�ض���ʧ�� */

    TRRC_APP_FLOW_CTRL_TYPE_L2T_STOP_REDIR,                /* L->T�ض���ֹͣ */

    /*׼FR����begin*/
    TRRC_APP_FLOW_CTRL_TYPE_T2G_REDIR,                     /* T->G�ض��� */

    TRRC_APP_FLOW_CTRL_TYPE_G2T_REDIR_FAIL,                /* G->T�ض���ʧ�� */

    TRRC_APP_FLOW_CTRL_TYPE_G2T_STOP_REDIR,                /* G->T�ض���ֹͣ */
    /*׼FR����end*/

    TRRC_APP_FLOW_CTRL_TYPE_BUTT
};
typedef VOS_UINT16 TRRC_APP_FLOW_CTRL_TYPE_ENUM_UINT16;
/*****************************************************************************
 ö����    : TRRC_APP_EST_SIGNALLING_TYPE
 Э����  :
 ASN.1���� :
 ö��˵��  : ��·����
*****************************************************************************/

enum  TRRC_APP_EST_SIGNALLING_TYPE
{
  TRRC_APP_NO_SIGNALLING_CONNECTION = 0,
  TRRC_APP_SIGNALLING_CONNECTION_ESTABLISHING,
  TRRC_APP_SIGNALLING_CONNECTION_ESTABLISHED
};

typedef VOS_UINT32 TRRC_APP_EST_SIGNALLING_TYPE_UINT32;
/*****************************************************************************
 ö����    : TRRC_APP_EST_CAUSE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : RRMM_EST_REQ_STRU��Ϣ�е�enEstCause����25.331Э�鶨�屣��һ��
*****************************************************************************/
enum TRRC_APP_EST_CAUSE_ENUM
{
    TRRC_APP_EST_CAUSE_ORIGIN_CONVERSAT_CALL             = 0,
    TRRC_APP_EST_CAUSE_ORIGIN_STREAM_CALL                = 1,
    TRRC_APP_EST_CAUSE_ORIGIN_INTERACT_CALL              = 2,
    TRRC_APP_EST_CAUSE_ORIGIN_BACKGROUND_CALL            = 3,
    TRRC_APP_EST_CAUSE_ORIGIN_SUBSCRIB_TRAFFIC_CALL      = 4,
    TRRC_APP_EST_CAUSE_TERMINAT_CONVERSAT_CALL           = 5,
    TRRC_APP_EST_CAUSE_TERMINAT_STREAM_CALL              = 6,
    TRRC_APP_EST_CAUSE_TERMINAT_INTERACT_CALL            = 7,
    TRRC_APP_EST_CAUSE_TERMINAT_BACKGROUND_CALL          = 8,
    TRRC_APP_EST_CAUSE_EMERGENCY_CALL                    = 9,
    TRRC_APP_EST_CAUSE_INTER_RAT_CELL_RESELECT           = 10,
    TRRC_APP_EST_CAUSE_INTER_RAT_CELL_CHANGE_ORDER       = 11,
    TRRC_APP_EST_CAUSE_REGISTRATION                      = 12,
    TRRC_APP_EST_CAUSE_DETACH                            = 13,
    TRRC_APP_EST_CAUSE_ORIGIN_HIGH_PRIORITY_SIGNAL       = 14,
    TRRC_APP_EST_CAUSE_ORIGIN_LOW_PRIORITY_SIGNAL        = 15,
    TRRC_APP_EST_CAUSE_CALL_RE_ESTABLISH                 = 16,
    TRRC_APP_EST_CAUSE_TERMINAT_HIGH_PRIORITY_SIGNAL     = 17,
    TRRC_APP_EST_CAUSE_TERMINAT_LOW_PRIORITY_SIGNAL      = 18,
    TRRC_APP_EST_CAUSE_TERMINAT_CAUSE_UNKNOWN            = 19,
    TRRC_APP_EST_CAUSE_BUTT
};
typedef VOS_UINT32 TRRC_APP_EST_CAUSE_ENUM_UINT32;

/* ErrorLog����������Ϣbegin */
/*****************************************************************************
 ö����    : TDS_APP_FREQ_BAND_LIST_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : TDS band��Ϣö��ֵ
*****************************************************************************/
enum TDS_APP_FREQ_BAND_LIST_ENUM
{
    TDS_APP_FREQ_BAND_NONE      = 0x00,
    TDS_APP_FREQ_BAND_A         = 0x01,         /* Ƶ�㷶Χ: 9504~9596  10054~10121 */
    TDS_APP_FREQ_BAND_B         = 0x02,         /* Ƶ�㷶Χ: 9254~9546  9654~9946 */
    TDS_APP_FREQ_BAND_C         = 0x04,         /* Ƶ�㷶Χ: 9554~9646 */
    TDS_APP_FREQ_BAND_D         = 0x08,         /* Ƶ�㷶Χ: 12854~13096 */
    TDS_APP_FREQ_BAND_E         = 0x10,         /* Ƶ�㷶Χ: 11504~11996 */
    TDS_APP_FREQ_BAND_F         = 0x20,         /* Ƶ�㷶Χ: 9404~9596 */
    TDS_APP_FREQ_BAND_BUTT
};
typedef VOS_UINT8  TDS_APP_FREQ_BAND_LIST_ENUM_UINT8;

/*****************************************************************************
 ö����    : TDS_APP_ERR_LOG_RAT_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ���뼼��ö��ֵ�����ݼ������GUTL���Զ��嵫���ָ���ʽ˳��һ��
*****************************************************************************/
enum TDS_APP_ERR_LOG_RAT_TYPE_ENUM
{
    TDS_APP_ERR_LOG_RAT_TYPE_GSM      = 1,      /* GSM ���뼼��*/
    TDS_APP_ERR_LOG_RAT_TYPE_WCDMA,             /* WCDMA ���뼼��*/
    TDS_APP_ERR_LOG_RAT_TYPE_LTE,               /* LTE ���뼼��*/
    TDS_APP_ERR_LOG_RAT_TYPE_TDS,               /* TDS ���뼼��*/
    TDS_APP_ERR_LOG_RAT_TYPE_BUTT
};
typedef VOS_UINT8  TDS_APP_ERR_LOG_RAT_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : TDS_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : �����ϱ�ԭ��ֵ
*****************************************************************************/
enum TDS_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM
{
    TDS_APP_ERR_LOG_AREA_LOST_BUTT = 1         /* ��ǰԤ����ö��ֵ*/
};
typedef VOS_UINT8  TDS_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM_UINT8;
/* ErrorLog����������Ϣend */
/* Seattle Begin */
/*****************************************************************************
 ö����    : TDS_ERR_LOG_CS_HANDOVER_FAIL_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : �л�ʧ�ܵ�ԭ��ֵ
*****************************************************************************/
enum TDS_ERR_LOG_CS_HANDOVER_FAIL_ENUM
{
    ERR_TRRC_GRR_HANDOVER_RESULT_FREQ_NOT_IMPLEMENTED =1,
    ERR_TRRC_GRR_HANDOVER_RESULT_CONFIG_UNKNOW,
    ERR_TRRC_GRR_HANDOVER_RESULT_INVALID_CONFIG,
    ERR_TRRC_GRR_HANDOVER_RESULT_RRC_CONNECT_FAILURE,
    ERR_TRRC_GRR_HANDOVER_RESULT_PROTOCOL_ERROR,
    ERR_TRRC_GRR_HANDOVER_RESULT_UNSUPORTED_CONFIGURATION,
    ERR_TRRC_GRR_HANDOVER_RESULT_PHY_CHANNEL_FAIL,
    ERR_TRRC_GRR_HANDOVER_RESULT_MESSAGE_INVALID,
    ERR_TRRC_GRR_HANDOVER_RESULT_UNSPECIFIC,
    ERR_TRRC_GRR_HANDOVER_RESULT_BUTT
};
typedef VOS_UINT16 TDS_ERR_LOG_CS_HANDOVER_FAIL_ENUM_UINT16;

/*****************************************************************************
 ö����    : TDS_ERR_LOG_CS_LINK_ERROR_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ������·ʧ�ܵ�ԭ��ֵ
*****************************************************************************/
enum TDS_ERR_LOG_CS_LINK_ERROR_ENUM
{
    TDS_CS_LINK_ERROR_T312_TIMEOUT =0,
    TDS_CS_LINK_ERROR_T313_TIMEOUT,
    TDS_CS_LINK_ERROR_BUTT
};
typedef VOS_UINT16 TDS_ERR_LOG_CS_LINK_ERROR_ENUM_UINT16;

/*****************************************************************************
 ö����     :ERR_LOG_GSM_BAND_INDICATOR_ENUM
 Э����  :
 ASN.1����   :
 ö��˵�� : GSMС��Ƶ��ָʾö��
*****************************************************************************/
typedef enum
{
    ERR_LOG_EN_DSC_1800_USED                    = 0,
    ERR_LOG_EN_PDS_1900_USED
}ERR_LOG_GSM_BAND_INDICATOR_ENUM;
typedef VOS_UINT32  ERR_LOG_GSM_BAND_INDICATOR_ENUM_UINT32;

/* Seattle End */
#if (FEATURE_ON == FEATURE_PTM)
/*****************************************************************************
 ö����    : TRRC_CHR_OUT_OF_SYNC_CAUSE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ʧ��ʱ�ϱ��ľ���ԭ��ֵ
*****************************************************************************/
enum TRRC_CHR_OUT_OF_SYNC_CAUSE_ENUM
{
    TRRC_CHR_OUTOFSYNC_NONE                        = 0,
    TRRC_CHR_OUTOFSYNC_INTRAFREQDISTURB            = 1,    /*ͬƵ����*/
    TRRC_CHR_OUTOFSYNC_NETWORKCONFIGUNREASONABLE   = 2,    /*�������ò�����*/
    TRRC_CHR_OUTOFSYNC_BUTT
};
typedef VOS_UINT8  TRRC_CHR_OUT_OF_SYNC_CAUSE_ENUM_UINT8;
#endif

/*****************************************************************************
   5 STRUCT
*****************************************************************************/

/*****************************************************************************
                               ����ģʽ �ϱ����ݽṹ
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : TRRC_APP_CHANGE_CELL_INFO_STRU
 �ṹ˵��  : �仯�ϱ��Ĺ���ģʽ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                usUlFreq;          /* ��������Ƶ�㵥λ:100Khz */
    VOS_UINT16                                usDlFreq;          /* ��������Ƶ�㵥λ:100Khz */
    VOS_UINT32                                ulCellId;          /* TD-SCDMAС��ID��ָRRC���С��ID������������ */
    VOS_UINT16                                usPagingCycle;     /* Ѱ������128,256,512,1024����λms*/
    VOS_UINT16                                usReserved;
}TRRC_APP_CHANGE_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_TDS_NCELL_INFO_STRU
 �ṹ˵��  : TD-SCDMAͬƵ����ƵС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT16                         usFrequency;      /* TD-SCDMA��С����������Ƶ�� ��λ:100Khz */
    VOS_UINT16                         usCellId;         /* TD-SCDMA��С��С��ID */
    VOS_UINT8                          ucRscp;           /* TD-SCDMA��С��Rscp���չ��ʣ���ʵֵ=ucRscp - 116����λdbm */
    VOS_UINT8                          aucReserved[3];
}TRRC_APP_TDS_NCELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_TDS_NCELL_STRU
 �ṹ˵��  : TD-SCDMAͬƵ����ƵС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      ulNCellNumber;
    TRRC_APP_TDS_NCELL_INFO_STRU    stCellMeasInfo[TRRC_APP_MAX_NCELL_NUM];
}TRRC_APP_TDS_NCELL_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_LTE_NCELL_INFO_STRU
 �ṹ˵��  : TD-SCDMA��ϵͳLTEС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usArfcn;
    VOS_UINT16                          usCellId;   /* ����С��ID */
    VOS_INT16                           sRsrp;      /* �������RSRP */
    VOS_INT16                           sRsrq;      /* �������RSRQ */
}TRRC_APP_LTE_NCELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_LTE_NCELL_STRU
 �ṹ˵��  : TD-SCDMA��ϵͳLTEС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      ulNCellNumber;
    TRRC_APP_LTE_NCELL_INFO_STRU    stCellMeasInfo[TRRC_APP_MAX_NCELL_NUM];
}TRRC_APP_LTE_NCELL_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_GERAN_NCELL_INFO_STRU
 �ṹ˵��  : TD-SCDMA��ϵͳGSMС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usArfcn;
    TRRC_APP_GRR_BANDINDICATOR_ENUM_UINT16                  enBandInd;          /* ����T->Gʱ����������Ϣ�е�Ƶ��ָʾһ�� */
    VOS_INT16                                               sRssi;              /* sRssi ȡֵ��Χ[-110 * 8,-48 * 8],��λ:dbm,����1/8 */
    VOS_UINT8                                               ucNcc;              /*  �ƶ�ͨѶGSM����ʶ�����: ����ɫ��(NCC) */
    VOS_UINT8                                               ucBcc;              /*  �ƶ�ͨѶGSM����ʶ�����: ��վɫ��(BCC) */
}TRRC_APP_GERAN_NCELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_GERAN_NCELL_STRU
 �ṹ˵��  : TD-SCDMA��ϵͳGSMС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                        ulNCellNumber;
    TRRC_APP_GERAN_NCELL_INFO_STRU    stCellMeasInfo[TRRC_APP_MAX_NCELL_NUM];
}TRRC_APP_GERAN_NCELL_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_NCELL_INFO_STRU
 �ṹ˵��  : ����С����ͬƵ����Ƶ�Լ���ϵͳ�������
*****************************************************************************/
typedef struct
{
    TRRC_APP_TDS_NCELL_STRU               stIntraFreqInfo;/* ͬƵ������Ϣ*/
    TRRC_APP_TDS_NCELL_STRU               stInterFreqInfo;/* ��Ƶ������Ϣ*/
    TRRC_APP_LTE_NCELL_STRU               stLTENcellInfo; /* LTE��ϵͳ����*/
    TRRC_APP_GERAN_NCELL_STRU             stGeranNcellInfo; /* GERAN��ϵͳ���� */
}TRRC_APP_NCELL_INFO_STRU;

/****************************************************************************
 �ṹ��    : TRRC_APP_FTM_CHANGE_INFO_STRU
 �ṹ˵��  : �仯�ϱ��Ĺ���ģʽ�ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_FTM_CHANGE_INFO_TYPE_ENUM_UINT32     ulFtmChangeInfoType;

    union
    {
        TRRC_APP_CHANGE_CELL_INFO_STRU            stCellInfo;
        TRRC_APP_PROTOCOL_STATE_ENUM_UINT8        enTrrcProtocolState;
    }uchangeInfo;
}TRRC_APP_FTM_CHANGE_INFO_STRU;
/*****************************************************************************
 �ṹ��    : APP_RRC_SINR_INFO_STRU
 �ṹ˵��  : SINR�ṹ
*****************************************************************************/
typedef struct
{
	VOS_UINT16                                     usModuFormat;
	VOS_UINT16                                     usTbiOut;
}TRRC_APP_CQI_INFO_STRU;
/*****************************************************************************
 �ṹ��    : APP_RRC_SINR_INFO_STRU
 �ṹ˵��  : SINR�ṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                              sSinrDB;
    VOS_UINT16                             usRev;
}TRRC_APP_DPCH_SINR_INFO_STRU;
/*****************************************************************************
 �ṹ��    : TDS_ERRLOG_UL_POWER_STRU
 �ṹ˵��  : UE���з��书��
*****************************************************************************/
typedef struct
{
	VOS_INT16 sDpchPwr;
	VOS_INT16 sEpuchPwr;
}TDS_APP_ERRLOG_UL_POWER_STRU;
/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_PERIOD_INFO
 �ṹ˵��  : �����ϱ��Ĺ���ģʽ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                           sCellRSCP;
    VOS_UINT16                          usReserved;
    TDS_APP_ERRLOG_UL_POWER_STRU        stUeTxPower;
    TRRC_APP_DPCH_SINR_INFO_STRU        stSINR;             /* SINR  RS_SNR */
    TRRC_APP_CQI_INFO_STRU              stCQI;              /* CQI�������� */
    TRRC_APP_NCELL_INFO_STRU            stNcellInfo;        /*������Ϣ*/
}TRRC_APP_FTM_PERIOD_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_APP_FTM_INFO_STRU
 �ṹ˵��  : ����ģʽ�ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_FTM_TYPE_ENUM_UINT32             enRrcAppFtmType;

    union
    {
        TRRC_APP_FTM_PERIOD_INFO_STRU         stPeriodInfo;  /* ����ģʽ�£������ϱ����ݣ� Idle״̬�ϱ�����ĿǰΪDRX���ڣ�Connected״̬������Ϊ1�� */
        TRRC_APP_FTM_CHANGE_INFO_STRU         stChangInfo;   /* ����ģʽ�£�������ϱ����� */
    }u;
}TRRC_APP_FTM_INFO_STRU;
/*****************************************************************************
 �ṹ��    : TRRC_OM_FTM_REPROT_CONTENT_STRU
 �ṹ˵��  : ����ģʽ�ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    /* ��ģ��ID */
    OM_ERR_LOG_MOUDLE_ID_ENUM_UINT32    ulMsgModuleID;

    /* 00������, 01������ ,10/11:����  */
    VOS_UINT16                          usModemId;

    VOS_UINT16                          usProjectID;
    VOS_UINT32                          ulLength;

    TRRC_APP_FTM_INFO_STRU               stTrrcFtmInfo;

}TRRC_OM_FTM_REPROT_CONTENT_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_OM_FTM_REPROT_IND_STRU
 �ṹ˵��  : ����ģʽ�ϱ����ݽṹ
*****************************************************************************/
/* ���������ģʽ�����ϱ����� ����� -> OM*/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT32                          ulMsgType;
    VOS_UINT32                          ulMsgSN;
    VOS_UINT32                          ulRptlen;      /* ����ģʽ�ϱ������ݳ���,���ulRptlenΪ0,aucContent���ݳ���ҲΪ0 */
    TRRC_OM_FTM_REPROT_CONTENT_STRU     stTrrcFtmContent;
}TRRC_OM_FTM_REPROT_IND_STRU;

/* Seattle Begin */
/*****************************************************************************
 �ṹ��     :ERR_LOG_SAVE_CELL_INFO_FOR_GAS_ST
 Э����  :
 ASN.1����   :
 �ṹ˵��  :GSMС������Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulNCC;
    VOS_UINT32                          ulBCC;
    VOS_UINT32                          ulBcchArcfn;
    VOS_UINT32                          ulFreqBandInd;
    VOS_UINT32                          ulFlag;                                 /* �ñ������ָʾlFNOffset��ulTimeAlignmt�Ƿ������ݣ�0:��ʾ������ 1: ��ʾ������*/
    VOS_INT32                           lFNOffset;
    VOS_UINT32                          ulTimeAlignmt;
    VOS_INT16                           sRxlev;                                 /* GС���źŵ�ƽ����λ��dBm,û�в⵽�źŵ�ƽʱ��ֵΪRRWRR_INVALID_RXLEV */
    VOS_UINT8                           aucReserve1[2];                         /* 4�ֽڶ��룬���� */

}ERR_LOG_SAVE_CELL_INFO_FOR_GAS_ST;

/*****************************************************************************
 �ṹ��     :TDS_ERR_LOG_CELL_INFO_STRU
 Э����  :
 ASN.1����   :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucCellId;                   /*С��ID*/
    VOS_UINT8                                   ucRscp;                     /*����*/
    VOS_UINT16                                  usFreqId;                   /*����Ƶ��*/
} TDS_ERR_LOG_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��     :TDS_ERR_LOG_GSM_CELL_INFO_STRU
 Э����  :
 ASN.1����   :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    ERR_LOG_SAVE_CELL_INFO_FOR_GAS_ST           stRrcSaveInfoForGas;        /* ע�⣬ֻ��1��С������Ϣ�����л��ӿڲ�ͬs */
    ERR_LOG_GSM_BAND_INDICATOR_ENUM_UINT32      enBandIndictor;             /* Bandָʾ */
} TDS_ERR_LOG_GSM_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��     :TDS_ERR_LOG_EVT_CS_HANDOVER_FAIL_STRU
 Э����  :
 ASN.1����   :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    TDS_ERR_LOG_CS_HANDOVER_FAIL_ENUM_UINT16    enHandoverFailCause;  /* �л�ʧ��ԭ��ֵ*/
    VOS_UINT8                                   aucReserve[2];        /* ����λ */
    TDS_ERR_LOG_CELL_INFO_STRU                  stTdsOrginalCell;     /* �л���TDSԴС����Ϣ */
    TDS_ERR_LOG_GSM_CELL_INFO_STRU              stGsmTargetCell;      /* �л���GSMĿ��С����Ϣ*/
}TDS_ERR_LOG_EVT_CS_HANDOVER_FAIL_STRU;

/*****************************************************************************
 �ṹ��     :TDS_ERR_LOG_EVT_CS_HANDOVER_SLOW_STRU
 Э����  :
 ASN.1����   :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    TDS_ERR_LOG_CELL_INFO_STRU                  stTdsOrginalCell;     /* �л���TDSԴС����Ϣ */
    TDS_ERR_LOG_GSM_CELL_INFO_STRU              stGsmTargetCell;      /* �л���GSM Ŀ��С����Ϣ*/
    VOS_UINT32                                  ulHandoverTime;       /* �л�ʱ��*/
}TDS_ERR_LOG_EVT_CS_HANDOVER_SLOW_STRU;

/*****************************************************************************
 �ṹ��     :TDS_ERR_LOG_EVT_CS_HANDOVER_SLOW_STRU
 Э����  :
 ASN.1����   :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                  ulStatus;           /*��ǰ״̬*/
    TDS_ERR_LOG_CELL_INFO_STRU                  stTdsOrginalCell;   /* �л���TDSԴС����Ϣ */
} TDS_ERR_LOG_STATUS_INFO_STRU;

/*****************************************************************************
 �ṹ��     :TDS_ERR_LOG_EVT_CS_LINK_ERROR_STRU
 Э����  :
 ASN.1����   :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    TDS_ERR_LOG_CS_LINK_ERROR_ENUM_UINT16       enRadioLinkErrorCause;      /*������·�쳣ԭ��*/
    VOS_UINT8                                   aucReserve[2];              /* ����λ */
    TDS_ERR_LOG_STATUS_INFO_STRU                stTdsStatusInfo;            /* TDS ��ǰ״̬��Ϣ��¼*/
}TDS_ERR_LOG_EVT_CS_LINK_ERROR_STRU;
/* Seattle End */

/*****************************************************************************
                               ERROR LOG �ϱ����ݽṹ
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : RRC_APP_STATE_INFO_STRU
 �ṹ˵��  : ERROR LOG RRC״̬��Ϣ������Э��״̬���ڲ�״̬����ϵͳ����
*****************************************************************************/
typedef struct
{
    TRRC_APP_PROTOCOL_STATE_ENUM_UINT8          enTrrcProtocolState;   /* RRCЭ��״̬ */
    TRRC_APP_RRC_STATE_ENUM_UINT8               enRrcState;            /* RRC״̬���ڲ�״̬����Э��״̬ */
    TRRC_APP_FLOW_CTRL_TYPE_ENUM_UINT16         enErrcFlowCtrlType;    /* TD-SCDMA������ϵͳ����ʱ����ϵͳ���̱�ʶ */
}TRRC_APP_STATE_INFO_STRU;
/*������뽨��ʧ��CHR�ϱ� add by lilin 00297133 2015-9-16 begin******************/
/*****************************************************************************
 �ṹ��    : TRRC_APP_ACC_FAIL_INFO_STRU
 �ṹ˵��  : ERROR LOG RRC����ʧ���ϱ���Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                 ulMcc;           /* MCC,3 bytes      */
    VOS_UINT32                                 ulMnc;           /* MNC,2 or 3 bytes */
    VOS_UINT16                                 usFrequency;     /* �������ʧ��ʱ����С������Ƶ�� ��λ:100Khz */
    VOS_UINT16                                 usCellId;        /* �������ʧ��ʱ����С��ID��Ϣ */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8          enBandInfo;      /* �������ʧ��ʱ����С������band��Ϣ */
    VOS_INT8                                   ucRscp;          /* �������ʧ��ʱ����С������ֵ,ʵ��ֵ - 116����λdbm */
    VOS_INT8                                   ucQrxLevMin;     /* �������ʧ��ʱ����С��פ������*/
    VOS_UINT8                                  ucRac;           /* Rac */
    VOS_UINT16                                 usLac;           /* lac */
    VOS_UINT8                                  aucResv[2];      /*����λ*/

}TRRC_APP_ACC_FAIL_INFO_STRU;
/*������뽨��ʧ��CHR�ϱ� add by lilin 00297133 2015-9-16 end******************/
/*****************************************************************************
 �ṹ��    : TRRC_APP_EST_INFO_STRU
 �ṹ˵��  : ERROR LOG RRC������Ϣ
 enEstSignallingType[0]:CS;enEstSignallingType[1]:ps
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];              /* ����λ */
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32        enEstSignallingType[2];  /* ����״̬��Ϣ*/
    TRRC_APP_EST_CAUSE_ENUM_UINT32             enEstCause;              /* ����ԭ�� */
    /*������뽨��ʧ��CHR�ϱ� add by lilin 2015-9-16 begin*/
    TRRC_APP_ACC_FAIL_INFO_STRU                stRrcAppAccFailInfo;
    /*������뽨��ʧ��CHR�ϱ� add by lilin 2015-9-16 end*/
}TRRC_APP_EST_INFO_STRU;

/* ErrorLog����������Ϣbegin */

/*****************************************************************************
 �ṹ��    : TDS_APP_AREA_LOST_INFO_STRU
 �ṹ˵��  : TDS������λ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                 ulTimeStamp;     /* ��¼������ʱ�� */
    VOS_UINT32                                 ulMcc;           /* MCC,3 bytes      */
    VOS_UINT32                                 ulMnc;           /* MNC,2 or 3 bytes */
    VOS_UINT16                                 usFrequency;     /* ����ʱ����С������Ƶ�� ��λ:100Khz */
    VOS_UINT16                                 usCellId;        /* ����ʱ����С��ID��Ϣ */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8          enBandInfo;      /* ����ʱ����С������band��Ϣ */
    VOS_INT8                                   ucRscp;          /* ����ǰ����С������ֵ,ʵ��ֵ - 116����λdbm */
    VOS_INT8                                   ucQrxLevMin;     /* ����ʱ����С��פ������*/
    VOS_UINT8                                  ucRac;           /* Rac */
    VOS_UINT16                                 usLac;           /* lac */
    TDS_APP_ERR_LOG_AREA_LOST_CAUSE_ENUM_UINT8 ucSubCause;      /* ��¼����ԭ��ֵ:��ʱ������������չʹ�� */
    VOS_UINT8                                  ucResv;          /* ���� */
}TDS_APP_AREA_LOST_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_AREA_LOST_INFO_STRU
 �ṹ˵��  : TDS������λ��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    TDS_APP_ERR_LOG_RAT_TYPE_ENUM_UINT8        enRatType;               /* ����������������ʽ */
    VOS_UINT8                                  aucResv[2];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    TDS_APP_AREA_LOST_INFO_STRU                stTdsArealostInfo;       /* ������Ϣ�ṹ */
}TRRC_APP_AREA_LOST_INFO_STRU;

/* ErrorLog����������Ϣend */
/*****************************************************************************
 �ṹ��    : TRRC_APP_CS_HO_FAIL_ERROR_INFO_STRU
 �ṹ˵��  : TDS CS�л�ʧ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                          stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8                  enErrorCode;             /* ������*/
    VOS_UINT8                                       aucResv[3];
    TRRC_APP_STATE_INFO_STRU                        stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    TDS_ERR_LOG_EVT_CS_HANDOVER_FAIL_STRU           stTdsHoFailInfo;         /* �л�ʧ��*/
}TRRC_APP_CS_HO_FAIL_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_CS_HO_EXP_ERROR_INFO_STRU
 �ṹ˵��  : TDS CS�л���ʱ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                          stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8                  enErrorCode;             /* ������*/
    VOS_UINT8                                       aucResv[3];
    TRRC_APP_STATE_INFO_STRU                        stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    TDS_ERR_LOG_EVT_CS_HANDOVER_SLOW_STRU           stTdsHoTimeExpInfo;      /* CS�л���ʱ*/
}TRRC_APP_CS_HO_EXP_ERROR_INFO_STRU;


/*****************************************************************************
 �ṹ��    : TRRC_APP_RL_ERROR_INFO_STRU
 �ṹ˵��  : TDS������·ʧ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    TDS_ERR_LOG_EVT_CS_LINK_ERROR_STRU         stTdsRLErrorInfo;        /* ������·ʧ����Ϣ�ṹ */
}TRRC_APP_RL_ERROR_INFO_STRU;
/* Seattle End */

/*****************************************************************************
 �ṹ��    : TRRC_APP_RB_ERROR_INFO_STRU
 �ṹ˵��  : TDS RB���ô�����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */

}TRRC_APP_RB_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_RBREC_ERROR_INFO_STRU
 �ṹ˵��  : TDS RB�����ô�����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */

}TRRC_APP_RBREC_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_CELLUPDATE_ERROR_INFO_STRU
 �ṹ˵��  : TDS cellupdateconfirm������Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    /*������뽨��ʧ��CHR�ϱ� add by lilin 2015-9-16 begin*/
    TRRC_APP_ACC_FAIL_INFO_STRU                stRrcAppAccFailInfo;
    /*������뽨��ʧ��CHR�ϱ� add by lilin 2015-9-16 end*/
}TRRC_APP_CELLUPDATE_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_INTEGRITY_ERROR_INFO_STRU
 �ṹ˵��  : TDS INTEGRITY fail��Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */

}TRRC_APP_INTEGRITY_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_MEAS_CTRL_ERROR_INFO_STRU
 �ṹ˵��  : TDS MEAS_CTRL������Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */

}TRRC_APP_MEAS_CTRL_ERROR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_ASN_RLST_ERR_INFO_STRU
 �ṹ˵��  : TDS ASN����ʧ����Ϣ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */

}TRRC_APP_ASN_RLST_ERR_INFO_STRU;
/*****************************************************************************
 �ṹ��    : TRRC_APP_BUFF_OVER_FLOW_ERR_INFO_STRU
 �ṹ˵��  : �������
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ*/
    VOS_UINT32                                 ulCount;                 /* ������� */
}TRRC_APP_BUFF_OVER_FLOW_ERR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : OM_ERR_LOG_REPORT_CNF_STRU
 �ṹ˵��  : ERROR LOG ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    VOS_UINT32                          ulMsgType;
    VOS_UINT32                          ulMsgSN;
    VOS_UINT32                          ulRptlen;      /* �������ݳ���,���ulRptlenΪ0,aucContent���ݳ���ҲΪ0 */
    VOS_UINT8                           aucContent[4]; /* �������� */
} TRRC_OM_ERR_LOG_REPORT_CNF_STRU;

/*****************************************************************************
 Structure      : TRRC_OM_TDS_SERV_CELL_INFO_STRU
 Description    : ��ǰע���С����Ϣ
 �޸���ʷ :
  1.��    ��    : 2015��2��27��
    ��    ��    : f00272207
    �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                 ulMcc;           /* MCC,3 bytes      */
    VOS_UINT32                                 ulMnc;           /* MNC,2 or 3 bytes */
    VOS_UINT16                                 usFrequency;     /* ��С������Ƶ�� ��λ:100Khz */
    VOS_UINT16                                 usCellId;        /* ����С��ID��Ϣ */
    VOS_INT8                                   ucRscp;          /* ����С������ֵ,ʵ��ֵ - 116����λdbm */
    VOS_UINT8                                  ucRac;           /* Rac */
    VOS_UINT16                                 usLac;           /* lac */

}TRRC_OM_TDS_SERV_CELL_INFO_STRU;

/*****************************************************************************
 Structure      : TRRC_ OM_TDS_CELLS_LIST_WITHOUT_LTE_NCELL_STRU
 Description    : δ����4G������С���б�ṹ��
 �޸���ʷ :
  1.��    ��     : 2015��2��27��
    ��    ��    :  f00272207
    �޸�����    :  �½��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucTdsCellNum;                   /* δ����4G������TDSС������ */
    VOS_UINT8                                   aucRsv[3];                      /* ���ֽڶ���ı���λ */
    TRRC_OM_TDS_SERV_CELL_INFO_STRU             astCellinfo[TRRC_OM_MAX_TDS_CELLS_NUM_WITHOUT_LTE_NCELL]; /* δ����4G������С���б� */

} TRRC_OM_TDS_CELLS_LIST_WITHOUT_LTE_NCELL_STRU;


/*****************************************************************************
 Structure      : TRRC_ERR_LOG_EVT_NO_T2L_OPERATION_ONE_CYCLE_STRU
 Description    : TRRC��ʱ�䲻��LTE�¼��ϱ��Ľṹ��
 �޸���ʷ :
  1.��    ��    : 2015��2��27��
    ��    ��    : f00272207
    �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                              stHeader;
    TDS_APP_ERR_LOG_RAT_TYPE_ENUM_UINT8                 enRatType;                       /*��ʱ�䲻��LTE������ģʽ*/
    VOS_UINT8                                           ucLteMeasValidFlag;              /*�Ƿ������LTE�źű�־*/
    VOS_INT16                                           sLteMaxRsrp;                     /*T3�����ڲ���������ǿ��LTE�ź�ǿ�� */
    TRRC_OM_TDS_CELLS_LIST_WITHOUT_LTE_NCELL_STRU       stTdsCellListWithoutLteNcell;    /*δ����LTE������С���б�*/
    TRRC_OM_TDS_SERV_CELL_INFO_STRU                     stServCellInfo;                  /*��ǰע��С����Ϣ */

} TRRC_ERR_LOG_EVT_NO_T2L_OPERATION_ONE_CYCLE_STRU;
/*****************************************************************************
 Structure      : TRRC_APP_CS_RELEASE_CELL_INFO_STRU
 Description    : TRR CS��·�ͷŵ�ǰ��������Ϣ
 �޸���ʷ :
  1.��    ��    : 2015��10��25��
    ��    ��    : f00272207
    �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                 usCellId;                /* ����С��ID */
    VOS_UINT16                                 usFrequency;             /* ����Ƶ�� */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8          enBandInfo;              /* ����Ƶ������BAND��Ϣ */
    VOS_INT8                                   cRscp;                   /* ����С������ */
    VOS_UINT8                                  aucResv[2];
}TRRC_APP_CS_RELEASE_CELL_INFO_STRU;

#if (FEATURE_ON == FEATURE_PTM)
/*****************************************************************************
Structure      : TRRC_APP_CS_NO_RBSETUP_INFO_STRU
Description    : ���ⵥDTS2015120803646:TRRC ����װ��RRC CONN SETUP COMPLETE��,TRRC �����ڲ�״̬��RRC_CNF̬,
                 ��ʱ�յ�����UM_DATA_IND���л���,��󻺴�ﵽ���ֵ,TRRC������CONN TO IDLE����CHR TRRC��CHR�ϱ������ݡ�
�޸���ʷ :
 1.��    ��    : 2016��01��12��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                            stHeader;                /* Errorlog��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8                    enErrorCode;             /* ������ */

    TRRC_APP_PROTOCOL_STATE_ENUM_UINT8                enTrrcProtocolState;     /* RRCЭ��״̬ */
    TRRC_APP_RRC_STATE_ENUM_UINT8                     enRrcState;              /* RRC״̬���ڲ�״̬����Э��״̬ */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8                 enBandInfo;              /* ����Ƶ������BAND��Ϣ */

    VOS_UINT16                                        usCellId;                /* ����С��ID */
    VOS_UINT16                                        usFrequency;             /* ����Ƶ�� */
    VOS_UINT16                                        usLac;                   /* ��ǰ���ڵ�Lac */
    VOS_INT16                                         usRscp;                  /* ����С������ */
    VOS_UINT32                                        ulMcc;                   /* ��ǰ����PLMN��Mcc */
    VOS_UINT32                                        ulMnc;                   /* ��ǰ����PLMN��Mnc */

    VOS_UINT32                                        ulFlowControlBitMap;
    VOS_UINT32                                        ulMsgName;
}TRRC_APP_CONN_SETUP_RSVD_MSG_MAX_INFO_STRU;

#endif

/*****************************************************************************
 Structure      : TRRC_APP_CS_RELEASE_INFO_STRU
 Description    : TRRC CS��·�ͷ��ϱ��Ľṹ��
 �޸���ʷ :
  1.��    ��    : 2015��10��25��
    ��    ��    : f00272207
    �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];
    TRRC_APP_STATE_INFO_STRU                   stRrcAppStateInfo;       /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU         stServCellInfo;         /* ����С����Ϣ */
}TRRC_APP_CS_RELEASE_INFO_STRU;

#if (FEATURE_ON == FEATURE_PTM)
/*****************************************************************************
Structure      : TRRC_APP_CS_NO_RBSETUP_INFO_STRU
Description    : CS���ղ��������·���RB SETUPʱ��TRRC�ϱ���CHR����Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                       stHeader;              /* Errorlog ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8               enErrorCode;           /* ������*/

    TRRC_APP_PROTOCOL_STATE_ENUM_UINT8           enTrrcProtocolState;   /* RRCЭ��״̬ */
    TRRC_APP_RRC_STATE_ENUM_UINT8                enRrcState;            /* RRC״̬���ڲ�״̬����Э��״̬ */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8            enBandInfo;            /* ����Ƶ������BAND��Ϣ */
    TRRC_APP_FLOW_CTRL_TYPE_ENUM_UINT16          enErrcFlowCtrlType;    /* TD-SCDMA������ϵͳ����ʱ����ϵͳ���̱�ʶ */

    VOS_UINT16                                   usCellId;              /* ����С��ID */
    VOS_UINT16                                   usFrequency;           /* ����Ƶ�� */
    VOS_UINT16                                   usLac;                 /* ��ǰ���ڵ�Lac */
    VOS_UINT32                                   ulMcc;                 /* ��ǰ����PLMN��Mcc */
    VOS_UINT32                                   ulMnc;                 /* ��ǰ����PLMN��Mnc */
    VOS_INT16                                    usRscp;                /* ����С������ */
    VOS_UINT8                                    aucResv[2];

    VOS_UINT32                                   ulTimeDiff;            /* ��¼û�յ�RB SETUP��һ��������SMC COMPLETE֮���ʱ��� */
    VOS_UINT32                                   ulFlowControlBitMap;
    VOS_UINT32                                   ulErrCodeBitMap;

}TRRC_APP_CS_NO_RBSETUP_INFO_STRU;

/*****************************************************************************
Description    : CS���绰��T2G CCO�����У�TRRC�ϱ���CHR����Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{

    OM_ERR_LOG_HEADER_STRU                         stHeader;             /* Errorlog ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8                 enErrorCode;          /* ������*/

    TRRC_APP_PROTOCOL_STATE_ENUM_UINT8             enTrrcProtocolState;  /* RRCЭ��״̬ */
    TRRC_APP_RRC_STATE_ENUM_UINT8                  enRrcState;           /* RRC״̬���ڲ�״̬����Э��״̬ */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8              enBandInfo;           /* ����Ƶ������BAND��Ϣ */
    TRRC_APP_FLOW_CTRL_TYPE_ENUM_UINT16            enErrcFlowCtrlType;   /* TD-SCDMA������ϵͳ����ʱ����ϵͳ���̱�ʶ */

    VOS_UINT16                                     usCellId;             /* ����С��ID */
    VOS_UINT16                                     usFrequency;          /* ����Ƶ�� */
    VOS_UINT16                                     usLac;                /* ��ǰ���ڵ�Lac*/
    VOS_UINT32                                     ulMcc;                /* ��ǰ����PLMN��Mcc*/
    VOS_UINT32                                     ulMnc;                /* ��ǰ����PLMN��Mnc*/
    VOS_INT16                                      usRscp;               /* ����С������ */
    VOS_UINT8                                      aucResv[2];

    VOS_UINT32                                     ulTimeStamp;          /* ��¼����ִ�е���һ����ʱ���*/
    VOS_UINT32                                     ulFlowControlBitMap;
    VOS_UINT32                                     ulErrCodeBitMap;

}TRRC_APP_CS_T2G_CCO_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰�Ĺ����з���ʧ�����̵��й���Ϣ
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                        stRrcAppStateInfo;    /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU              stServCellInfo;       /* ����С����Ϣ */
    VOS_UINT32                                      ulTimeStamp;          /* ��¼����ִ�е���һ����ʱ���*/
    VOS_UINT32                                      ulCsCallChrFlowBitmap;
    VOS_UINT32                                      ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_OUTOFSYNC_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰�Ĺ����з���ʧ�����̵��й���Ϣ
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;    /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;       /* ����С����Ϣ */
    VOS_UINT32                                       ulTimeStamp;          /* ��¼����ִ�е���һ����ʱ���*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_CONN_REL_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS CALLʱSMC COMP �����йص�CHR��Ϣ
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;
}TRRC_CHR_CS_CALL_SMC_CPL_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS CALLʱSIGNAL CONN RELʱ���й�CHR��Ϣ
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;
}TRRC_CHR_CS_CALL_SIGNAL_REL_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS CALL������GU REL REQʱ���й�CHR��Ϣ
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                          stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                stServCellInfo;        /* ����С����Ϣ */
    VOS_UINT32                                        ulTimeStamp;           /*��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32               enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                        ulCsCallChrFlowBitmap;
    VOS_UINT32                                        ulCsCallChrCodeBitmap;
}TRRC_CHR_CS_CALL_GU_REL_REQ_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS CALL������GU REL REQʱ���й�CHR��Ϣ
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                          stRrcAppStateInfo;      /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                stServCellInfo;         /* ����С����Ϣ */
    VOS_UINT32                                        ulTimeStamp;            /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32               enEstSignallingType[2]; /* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                        ulCsCallChrFlowBitmap;
    VOS_UINT32                                        ulCsCallChrCodeBitmap;
}TRRC_CHR_CS_CALL_GU_TRANS_NTFY_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰EST REQ CHR��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��22��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{

    TRRC_APP_STATE_INFO_STRU                           stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                 stServCellInfo;        /* ����С����Ϣ */
    VOS_UINT32                                         ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_CAUSE_ENUM_UINT32                     enEstCause;            /* ��¼��ǰ������ԭ��ֵ����v_rrc_establishmentCause��ȡ*/
    VOS_UINT32                                         ulCsCallChrFlowBitmap;
    VOS_UINT32                                         ulCsCallChrCodeBitmap;
    VOS_UINT32                                         ulOpId;                /* ������ʶ */

}TRRC_CHR_CS_CALL_EST_REQ_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰RRC CONN REQ ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��22��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                           stRrcAppStateInfo;      /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                 stServCellInfo;         /* ����С����Ϣ */
    VOS_UINT32                                         ulTimeStamp;            /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_CAUSE_ENUM_UINT32                     enEstCause;             /* ��¼��ǰ������ԭ��ֵ����v_rrc_establishmentCause��ȡ*/

    TRRC_APP_EST_SIGNALLING_TYPE_UINT32                enEstSignallingType[2]; /* ����״̬��Ϣ*/
    VOS_UINT32                                         ulCsCallChrFlowBitmap;
    VOS_UINT32                                         ulCsCallChrCodeBitmap;

    VOS_UINT32                                         ulMcc;                  /* ��ǰ����PLMN��Mcc*/
    VOS_UINT32                                         ulMnc;                  /* ��ǰ����PLMN��Mnc*/
    VOS_UINT16                                         usLac;                  /* ��ǰ���ڵ�Lac*/
    VOS_UINT8                                          aucResv[2];

}TRRC_CHR_CS_CALL_CONN_REQ_INFO_STRU;

/*****************************************************************************
Description    : TRRCֱͨ�ϱ���CS���绰RRC CONN REQ ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��8��23��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                           stRrcAppStateInfo;      /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                 stServCellInfo;         /* ����С����Ϣ */
    VOS_UINT32                                         ulTimeStamp;            /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_CAUSE_ENUM_UINT32                     enEstCause;             /* ��¼��ǰ������ԭ��ֵ����v_rrc_establishmentCause��ȡ*/

    VOS_UINT32                                         aulEstSignallingType[2];/* ����״̬��Ϣ*/
    VOS_UINT32                                         ulCsCallChrFlowBitmap;
    VOS_UINT32                                         ulCsCallChrCodeBitmap;

    VOS_UINT32                                         ulMcc;                  /* ��ǰ����PLMN��Mcc*/
    VOS_UINT32                                         ulMnc;                  /* ��ǰ����PLMN��Mnc*/
    VOS_UINT16                                         usLac;                  /* ��ǰ���ڵ�Lac*/
    VOS_UINT8                                          aucResv[2];

}TRRC_CS_CALL_CONN_REQ_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰��PLMN��LAC��RAC��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��8��2��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                         ulMcc;                  /* ��ǰ����PLMN��Mcc*/
    VOS_UINT32                                         ulMnc;                  /* ��ǰ����PLMN��Mnc*/
    VOS_UINT16                                         usLac;                  /* ��ǰ���ڵ�Lac*/
    VOS_UINT8                                          ucRac;                  /* ��ǰ���ڵ�Rac*/
    VOS_UINT8                                          ucResv;                 /* ����λ*/
}TRRC_CS_CALL_MM_INFO_STRU;
/*****************************************************************************
Description    : TRRC���ر����CS���绰�տ���Ϣ�쳣�� ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��8��2��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                           stRrcAppStateInfo;      /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                 stServCellInfo;         /* ����С����Ϣ */
    TRRC_CS_CALL_MM_INFO_STRU                          stMmInfo;               /* PLMN��LAC��RAC��Ϣ*/
    VOS_UINT32                                         ulTimeStamp;            /* ��¼����ִ�е���һ����ʱ���*/
    VOS_UINT32                                         ulCsCallChrFlowBitmap;
    VOS_UINT32                                         ulCsCallChrCodeBitmap;

}TRRC_CS_CALL_AIRMSG_INFO_STRU;
/*****************************************************************************
Description    : TRRC���ر����CS���绰RRC CONN SETUP ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��6��17��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    TRRC_CS_CALL_MM_INFO_STRU                        stMmInfo;              /* PLMN��LAC��RAC��Ϣ*/
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_CONN_SETUP_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰RRC CONN SETUP COMP ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��7��7��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    TRRC_CS_CALL_MM_INFO_STRU                        stMmInfo;               /* PLMN��LAC��RAC��Ϣ*/
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_CONN_SETUP_COMP_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰Initial DirTransfer ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��7��7��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    TRRC_CS_CALL_MM_INFO_STRU                        stMmInfo;               /* PLMN��LAC��RAC��Ϣ*/
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_INIT_DIRTRAN_INFO_STRU;
/*****************************************************************************
Description    : TRRC���ر����CS���绰SMC ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��7��7��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    TRRC_CS_CALL_MM_INFO_STRU                        stMmInfo;              /* PLMN��LAC��RAC��Ϣ*/
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_SMC_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰RB SETUP ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��7��7��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_STATE_INFO_STRU                         stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU               stServCellInfo;        /* ����С����Ϣ */
    TRRC_CS_CALL_MM_INFO_STRU                        stMmInfo;               /* PLMN��LAC��RAC��Ϣ*/
    VOS_UINT32                                       ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ���*/
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32              enEstSignallingType[2];/* ��¼��ǰ������״̬��Ϣ����a_rrc_establishedSigCon[]�л�ȡ*/
    VOS_UINT32                                       ulCsCallChrFlowBitmap;
    VOS_UINT32                                       ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_RB_SETUP_INFO_STRU;

/*****************************************************************************
Description    : TRRCֱͨ�ϱ���CS���绰EST CNF ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��8��20��
   ��    ��    : l00297133
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                          usCellId;                /* ����С��ID */
    VOS_UINT16                                          usFrequency;             /* ����Ƶ�� */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8                   enBandInfo;              /* ����Ƶ������BAND��Ϣ */
    VOS_INT8                                            cRscp;                   /* ����С������ */
    VOS_UINT8                                           aucResv[2];              /* ����λ*/
    VOS_UINT32                                          ulTimeStamp;             /* ��¼����ִ�е���һ����ʱ��� */
    VOS_UINT32                                          ulCsCallChrFlowBitmap;
    VOS_UINT32                                          ulCsCallChrCodeBitmap;
    VOS_UINT32                                          ulOpId;                  /* ������ʶ */
    VOS_UINT32                                          aulEstSignallingType[2]; /* ����״̬��Ϣ*/
    RRC_NAS_EST_RESULT_ENUM_UINT32                      ulResult;                /* ���������ӽ��������ȡֵ��ö�ٶ��� */
}TRRC_CS_CALL_EST_CNF_INFO_STRU;


/*****************************************************************************
Description    : TRRC���ر����CS���绰EST CNF ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                  stServCellInfo;        /* ����С����Ϣ */
    VOS_UINT32                                          ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ��� */
    VOS_UINT32                                          ulCsCallChrFlowBitmap;
    VOS_UINT32                                          ulCsCallChrCodeBitmap;
    VOS_UINT32                                          ulOpId;                /* ������ʶ */
    TRRC_APP_EST_SIGNALLING_TYPE_UINT32                 enEstSignallingType[2];/* ����״̬��Ϣ*/
    RRC_NAS_EST_RESULT_ENUM_UINT32                      ulResult;              /* ���������ӽ��������ȡֵ��ö�ٶ��� */
}TRRC_CHR_CS_CALL_EST_CNF_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰T2G CCOʱ�� ERR LOG��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_APP_CS_RELEASE_CELL_INFO_STRU                  stServCellInfo;        /* ����С����Ϣ */
    TRRC_APP_STATE_INFO_STRU                            stRrcAppStateInfo;     /* ��������ʱ״̬��Ϣ */
    VOS_UINT32                                          ulTimeStamp;           /* ��¼����ִ�е���һ����ʱ��� */
    VOS_UINT32                                          ulCsCallChrFlowBitmap;
    VOS_UINT32                                          ulCsCallChrCodeBitmap;

}TRRC_CHR_CS_CALL_T2G_CCO_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر���������й�CS���绰��һ����Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_CHR_CS_CALL_EST_REQ_INFO_STRU                   stCsCallEstReqInfo;     /* ��绰�����ߵ�EST REQʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_CONN_REQ_INFO_STRU                  stCsCallConnReqInfo;    /* ��绰�����ߵ�CONN REQʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_CONN_SETUP_INFO_STRU                stCsCallConnSetupInfo;    /* ��绰�����ߵ�CONN SETUPʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_CONN_SETUP_COMP_INFO_STRU           stCsCallConnSetupCompInfo;/* ��绰�����ߵ�CONN SETUP COMPʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_INIT_DIRTRAN_INFO_STRU              stCsCallInitDirTranInfo;  /*��绰�����ߵ�InitialDirTransferʱ���ر����CHR��Ϣ*/
    TRRC_CHR_CS_CALL_SMC_INFO_STRU                       stCsCallSmcInfo;        /*��绰�����ߵ�SMCʱ���ر����CHR��Ϣ*/
    TRRC_CHR_CS_CALL_EST_CNF_INFO_STRU                   stCsCallEstCnfInfo;     /* ��绰�����ߵ�CONN REQʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_SMC_CPL_INFO_STRU                   stCsCallSMCCplInfo;     /* ��绰�����ߵ�SMC COMPLETEʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_RB_SETUP_INFO_STRU                  stCsCallRBSetupInfo;    /* ��绰�����ߵ�RB SETUPʱ���ر����CHR��Ϣ*/
    TRRC_CHR_CS_CALL_OUTOFSYNC_INFO_STRU                 stCsCallOutOfSyncInfo;  /* ��绰�����ߵ�OUT OF SYNCʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_CONN_REL_INFO_STRU                  stCsCallConnRelInfo;    /* ��绰�����ߵ�RRC CONN RELʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_SIGNAL_REL_INFO_STRU                stCsCallSignalRelInfo;  /* ��绰�����ߵ�RRC SIGNAL RELʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_GU_REL_REQ_INFO_STRU                stCsCallGuRelReqInfo;   /* ��绰�����ߵ�GU REL REQʱ���ر����CHR��Ϣ */
    TRRC_CHR_CS_CALL_GU_TRANS_NTFY_INFO_STRU             stCsCallGuTransNtfyInfo;/* ��绰�����ߵ�GU TRANS STATUS NOTIFYʱ���ر����CHR��Ϣ */
}TRRC_CHR_CS_CALL_GENERAL_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر����CS���绰�Ĺ������ȷ���ʧ��Ȼ����CELL UPDATE���̵��й���Ϣ
�޸���ʷ :
 1.��    ��    : 2016��2��19��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                              enOutOfSyncCellUpdtFailFlg; /* �ж������Ƿ�������ʧ��Ȼ��������CELL UPDATE*/
    VOS_INT8                                        ucCellUpdateRscp;           /* CELL UPDATEʱ��С������ */
    VOS_INT8                                        ucOutOfSyncRscp;            /* ʧ��ʱ����С�������� */
    PS_BOOL_ENUM_UINT8                              enRrcConnRelFlag;           /* �жϱ��ε�CELL UPDATE FAIL�Ƿ������ڷ�����RRC CONN REL���µ�*/
    VOS_UINT16                                      usOutOfSyncFreq;            /* ʧ��ʱ����С����Ƶ�� */
    VOS_UINT16                                      usOutOfSyncParaId;          /* ʧ��ʱ����С����cellParameters ID */
    VOS_UINT16                                      usCellUpdateFreq;           /* CELL UPDATEʱ��Ƶ�� */
    VOS_UINT16                                      usCellUpdateParaId;         /* CELL UPDATEʱ��С��ID */
    VOS_UINT32                                      ulOutOfSyncIdentityId;      /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                      ulCellUpdtIdentityId;       /* SIB3��Я����cellIdentity ID */

}TRRC_CHR_CS_CALL_OUTOFSYNC_CELLUPDT_INFO_STRU;

/*****************************************************************************
Description    : TRRC���ر���������й�CS���绰��CHR��Ϣ���ݡ�
�޸���ʷ :
 1.��    ��    : 2015��12��20��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    PS_BOOL_ENUM_UINT8                                   enTrrcChrCsCallFlag;    /*��ʶ�Ƿ��Ǵ�绰���̵�FLAG*/
    VOS_UINT8                                            aucResv[3];
    TRRC_CHR_CS_CALL_GENERAL_INFO_STRU                   stCsCallGeneralInfo;    /*��绰���̱��ر����һ��CHR��Ϣ*/
    TRRC_CHR_CS_CALL_T2G_CCO_INFO_STRU                   stCsCallT2GCCOInfo;     /*��绰�����ߵ�T2G CCO����ʱ���ر����CHR��Ϣ*/
    TRRC_CHR_CS_CALL_OUTOFSYNC_CELLUPDT_INFO_STRU        stCsCallOutOfSyncCellUpdtInfo;
}TRRC_CHR_CS_CALL_INFO_STRU;

/*****************************************************************************
Description    : TRRCʧ�������У�TRRC�ϱ���CHR����Ϣ���ݡ�
                 usAsyMsgBitmap��ÿ��BIT�ĺ�������:
                 BIT1~BIT5:   ��ʾʧ����ԭ����T312����T313��ʱ����ʱ(0:T312��ʱ����ʱ��1:T313��ʱ����ʱ)
                 BIT6:        �������õ�1G�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT7:        �������õ�1G�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT8:        �������õ�2A�¼���usedFreqW��ֵ�Ƿ����(0:������1:����)
                 BIT9:        �������õ�2A�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT10:       �������õ�2A�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT11:       �������õ�3A�¼���thresholdOwnSystem��ֵ�Ƿ����(0:������1:����)
                 BIT12:       �������õ�3A�¼���thresholdOtherSystem��ֵ�Ƿ����(0:������1:����)
                 BIT13:       �������õ�3A�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT14:       �������õ�3A�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT15:       �������õ�3C�¼���thresholdOtherSystem��ֵ�Ƿ����(0:������1:����)
                 BIT16:       �������õ�3C�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT17:       �������õ�3C�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT18~BIT32: ����λ

                 usAsyAssistMsgBitmap��ÿ��BIT�ĺ�������:
                 BIT1~BIT5:   ��ʾ�Ƿ�����T312����T313��ʱ����ʱ(1:�����ˣ�0:û�з���)
                 BIT6:        ��ʾ�����Ƿ�������1G�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT7:        ��ʾ�����Ƿ�������1G�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT8:        ��ʾ�����Ƿ�������2A�¼���usedFreqW��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT9:        ��ʾ�����Ƿ�������2A�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT10:       ��ʾ�����Ƿ�������2A�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT11:       ��ʾ�����Ƿ�������3A�¼���thresholdOwnSystem��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT12:       ��ʾ�����Ƿ�������3A�¼���thresholdOtherSystem��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT13:       ��ʾ�����Ƿ�������3A�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT14:       ��ʾ�����Ƿ�������3A�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT15:       ��ʾ�����Ƿ�������3C�¼���thresholdOtherSystem��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT16:       ��ʾ�����Ƿ�������3C�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT17:       ��ʾ�����Ƿ�������3C�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT18~BIT32: ����λ
�޸���ʷ :
 1.��    ��    : 2016��2��19��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{

    OM_ERR_LOG_HEADER_STRU                              stHeader;                                             /* Errorlog ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8                      enErrorCode;                                          /* ������*/
    VOS_UINT8                                           aucResv[3];                                           /* ����λ*/
    TRRC_CHR_OUT_OF_SYNC_CAUSE_ENUM_UINT8               enOutOfSyncCause[TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM]; /* ʧ���ľ���ԭ��ֵ*/
    VOS_INT8                                            ucIntraFreqRscp[TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM];  /* ͬƵС������ */
    VOS_UINT32                                          ulAsyMsgBitmap;                                       /* ��¼ʧ��ʱĳЩ��Ϣ��BIT MAP��������������*/
    VOS_UINT32                                          ulAsyAssistMsgBitmap;                                 /* ������λusAsyMsgBitmap����Ϣ��BIT MAP*/
    VOS_UINT32                                          ulTrrcT314Length;                                     /* UEʹ�õ�T314��ʱ����ʱ�� */
    VOS_UINT32                                          ulTrrcT315Length;                                     /* UEʹ�õ�T315��ʱ����ʱ�� */
    VOS_UINT32                                          ulMcc;                                                /* ��ǰ����С������PLMN��Mcc*/
    VOS_UINT32                                          ulMnc;                                                /* ��ǰ����С������PLMN��Mnc*/
    VOS_UINT16                                          usLac;                                                /* ��ǰ����С�����ڵ�Lac*/
    VOS_UINT16                                          usServFreq;                                           /* ����С��Ƶ�� */
    VOS_UINT16                                          usServParaId;                                         /* ����С����cellParameters ID */
    VOS_INT8                                            ucServRscp[TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM];       /* ����С������ */
    VOS_UINT32                                          ulServIdentityId;                                     /* SIB3��Я����cellIdentity ID */
}TRRC_APP_OUT_OF_SYNC_INFO_STRU;

/*****************************************************************************
Description    : һ�㳡���£�TRRC�ȷ�����ʧ�����̣�Ȼ��������CELL UPDATE���̡����ֳ�����TRRC
                 �ϱ���CHR���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��2��19��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                              stHeader;                 /* ERR LOG��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8                      enErrorCode;              /* ������*/
    VOS_INT8                                            ucCellUpdateRscp;         /* CELL UPDATEʱ��С������ */
    VOS_INT8                                            ucOutOfSyncRscp;          /* ʧ��ʱ����С�������� */
    PS_BOOL_ENUM_UINT8                                  enRrcConnRelFlag;         /* �жϱ��ε�CELL UPDATE FAIL�Ƿ������ڷ�����RRC CONN REL���µ�*/
    VOS_UINT16                                          usOutOfSyncFreq;          /* ʧ��ʱ����С����Ƶ�� */
    VOS_UINT16                                          usOutOfSyncParaId;        /* ʧ��ʱ����С����cellParameters ID */
    VOS_UINT16                                          usCellUpdateFreq;         /* CELL UPDATEʱ��Ƶ�� */
    VOS_UINT16                                          usCellUpdateParaId;       /* CELL UPDATEʱ��С��cellParameters ID */
    VOS_UINT32                                          ulAsyToCellUpdtTimeDiff;  /* OUT OF SYNC����һ��CELL UPDATE��ʱ�� */
    VOS_UINT32                                          ulOutOfSyncIdentityId;    /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                          ulCellUpdtIdentityId;     /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                          ulTrrcT314Length;         /* UEʹ�õ�T314��ʱ����ʱ�� */
    VOS_UINT32                                          ulTrrcT315Length;         /* UEʹ�õ�T315��ʱ����ʱ�� */
}TRRC_APP_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU;

/* Modem errlog report, TRRC voluntarily event report for example begin. */

/*****************************************************************************
Description    : һ�㳡���£�TRRC�ȷ�����ʧ�����̣�Ȼ��������CELL UPDATE���̡����ֳ�����TRRC
                 �ϱ���CHR���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��6��12��
   ��    ��    : q00312157
   �޸�����    : modem chrֱͨ�½��ṹ
*****************************************************************************/
typedef struct
{
    VOS_INT8                                            ucCellUpdateRscp;         /* CELL UPDATEʱ��С������ */
    VOS_INT8                                            ucOutOfSyncRscp;          /* ʧ��ʱ����С�������� */
    PS_BOOL_ENUM_UINT8                                  enRrcConnRelFlag;         /* �жϱ��ε�CELL UPDATE FAIL�Ƿ������ڷ�����RRC CONN REL���µ�*/
    VOS_UINT8                                           Reserved;
    VOS_UINT16                                          usOutOfSyncFreq;          /* ʧ��ʱ����С����Ƶ�� */
    VOS_UINT16                                          usOutOfSyncParaId;        /* ʧ��ʱ����С����cellParameters ID */
    VOS_UINT16                                          usCellUpdateFreq;         /* CELL UPDATEʱ��Ƶ�� */
    VOS_UINT16                                          usCellUpdateParaId;       /* CELL UPDATEʱ��С��cellParameters ID */
    VOS_UINT32                                          ulAsyToCellUpdtTimeDiff;  /* OUT OF SYNC����һ��CELL UPDATE��ʱ�� */
    VOS_UINT32                                          ulOutOfSyncIdentityId;    /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                          ulCellUpdtIdentityId;     /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                          ulTrrcT314Length;         /* UEʹ�õ�T314��ʱ����ʱ�� */
    VOS_UINT32                                          ulTrrcT315Length;         /* UEʹ�õ�T315��ʱ����ʱ�� */
}TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU;

typedef struct
{
    OM_ERR_LOG_HEADER_STRU                              stOmHead;
    MODEM_ERR_LOG_HEADER_STRU                           StModemHead;
    VOS_UINT8                                           aucMsgContent[4];
}TRRC_DIRECT_RPT_OM_PAYLOAD_STRU;

/* Modem errlog report, TRRC voluntarily event report for example end. */


/*****************************************************************************
Description    : CS��TRRC�ȷ�����ʧ�����̣�Ȼ��������CELL UPDATE���̡����ֳ�����TRRC
                 �ϱ���CHR���ݡ�
�޸���ʷ :
 1.��    ��    : 2016��2��19��
   ��    ��    : l00280875
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                              stHeader;                 /* ERR LOG��Ϣͷ*/
    TRRC_APP_ERROR_CODE_ENUM_UINT8                      enErrorCode;              /* ������*/
    VOS_INT8                                            ucCellUpdateRscp;         /* CELL UPDATEʱ��С������ */
    VOS_INT8                                            ucOutOfSyncRscp;          /* ʧ��ʱ����С�������� */
    PS_BOOL_ENUM_UINT8                                  enRrcConnRelFlag;         /* �жϱ��ε�CELL UPDATE FAIL�Ƿ������ڷ�����RRC CONN REL���µ�*/
    VOS_UINT16                                          usOutOfSyncFreq;          /* ʧ��ʱ����С����Ƶ�� */
    VOS_UINT16                                          usOutOfSyncParaId;        /* ʧ��ʱ����С����ID */
    VOS_UINT16                                          usCellUpdateFreq;         /* CELL UPDATEʱ��Ƶ�� */
    VOS_UINT16                                          usCellUpdateParaId;       /* CELL UPDATEʱ��С��ID */
    VOS_UINT32                                          ulOutOfSyncIdentityId;    /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                          ulCellUpdtIdentityId;     /* SIB3��Я����cellIdentity ID */
    VOS_UINT32                                          ulTrrcT314Length;         /* UEʹ�õ�T314��ʱ����ʱ�� */
    VOS_UINT32                                          ulTrrcT315Length;         /* UEʹ�õ�T315��ʱ����ʱ�� */
}TRRC_APP_CS_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_CHR_PRACH_CCODE_INFO_STRU
 �ṹ˵��  : TDS˫�����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                 ulTimeStamp;     /* ��¼ʱ��� */
    VOS_UINT32                                 ulMcc;           /* MCC,3 bytes      */
    VOS_UINT32                                 ulMnc;           /* MNC,2 or 3 bytes */
    VOS_UINT16                                 usFrequency;     /* С������Ƶ�� ��λ:100Khz */
    VOS_UINT16                                 usCellId;        /* С��ID��Ϣ */
    VOS_UINT32                                 ulCellIdentity;  /* ����С��ID */
    VOS_UINT32                                 ulCcodeInfo;     /* ˫���������Ϣ sf4:4 sf8:8 sf16:16*/
    VOS_UINT16                                 usLac;           /* lac */
    VOS_UINT8                                  ucRac;           /* Rac */
    VOS_UINT8                                  ucResv;          /* ����λ*/
}TRRC_CHR_PRACH_CCODE_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_PRACH_CCODE_CHR_INFO_STRU
 �ṹ˵��  : ˫����ϱ��ṹ
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                     stHeader;                /* Errorlog ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8             enErrorCode;             /* ������*/
    VOS_UINT8                                  aucResv[3];              /* ����λ */
    TRRC_CHR_PRACH_CCODE_INFO_STRU             stTrrcPrachCcodeInfo;    /*˫�����Ϣ*/
}TRRC_APP_PRACH_CCODE_CHR_INFO_STRU;


/*****************************************************************************
 �ṹ��    : TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU
 �ṹ˵��  : �ռ���TDSƵ����Ϣ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                 aulFreqList[MAX_TDS_FREQ_NUM];   /* �ռ���TDSƵ����Ϣ */
}TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU;

/* Modem errlog report, TDS correlative event report for example begin. */

/*****************************************************************************
Description    : TRRCʧ�������У�TRRC�ϱ���CHR����Ϣ���ݡ�
                 usAsyMsgBitmap��ÿ��BIT�ĺ�������:
                 BIT1~BIT5:   ��ʾʧ����ԭ����T312����T313��ʱ����ʱ(0:T312��ʱ����ʱ��1:T313��ʱ����ʱ)
                 BIT6:        �������õ�1G�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT7:        �������õ�1G�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT8:        �������õ�2A�¼���usedFreqW��ֵ�Ƿ����(0:������1:����)
                 BIT9:        �������õ�2A�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT10:       �������õ�2A�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT11:       �������õ�3A�¼���thresholdOwnSystem��ֵ�Ƿ����(0:������1:����)
                 BIT12:       �������õ�3A�¼���thresholdOtherSystem��ֵ�Ƿ����(0:������1:����)
                 BIT13:       �������õ�3A�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT14:       �������õ�3A�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT15:       �������õ�3C�¼���thresholdOtherSystem��ֵ�Ƿ����(0:������1:����)
                 BIT16:       �������õ�3C�¼���hysteresis��ֵ�Ƿ����(0:������1:����)
                 BIT17:       �������õ�3C�¼���timeToTrigger��ֵ�Ƿ����(0:������1:����)
                 BIT18~BIT32: ����λ

                 usAsyAssistMsgBitmap��ÿ��BIT�ĺ�������:
                 BIT1~BIT5:   ��ʾ�Ƿ�����T312����T313��ʱ����ʱ(1:�����ˣ�0:û�з���)
                 BIT6:        ��ʾ�����Ƿ�������1G�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT7:        ��ʾ�����Ƿ�������1G�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT8:        ��ʾ�����Ƿ�������2A�¼���usedFreqW��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT9:        ��ʾ�����Ƿ�������2A�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT10:       ��ʾ�����Ƿ�������2A�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT11:       ��ʾ�����Ƿ�������3A�¼���thresholdOwnSystem��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT12:       ��ʾ�����Ƿ�������3A�¼���thresholdOtherSystem��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT13:       ��ʾ�����Ƿ�������3A�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT14:       ��ʾ�����Ƿ�������3A�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT15:       ��ʾ�����Ƿ�������3C�¼���thresholdOtherSystem��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT16:       ��ʾ�����Ƿ�������3C�¼���hysteresis��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT17:       ��ʾ�����Ƿ�������3C�¼���timeToTrigger��ֵ(1:���������˸ò�����0:����û�����øò���)
                 BIT18~BIT32: ����λ
�޸���ʷ :
 1.��    ��    : 2016��6��14��
   ��    ��    : q00312157
   �޸�����    : �½��ṹ
*****************************************************************************/
typedef struct
{
    TRRC_CHR_OUT_OF_SYNC_CAUSE_ENUM_UINT8               enOutOfSyncCause[TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM]; /* ʧ���ľ���ԭ��ֵ*/
    VOS_INT8                                            ucIntraFreqRscp[TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM];  /* ͬƵС������ */
    VOS_UINT32                                          ulAsyMsgBitmap;                                       /* ��¼ʧ��ʱĳЩ��Ϣ��BIT MAP��������������*/
    VOS_UINT32                                          ulAsyAssistMsgBitmap;                                 /* ������λusAsyMsgBitmap����Ϣ��BIT MAP*/
    VOS_UINT32                                          ulTrrcT314Length;                                     /* UEʹ�õ�T314��ʱ����ʱ�� */
    VOS_UINT32                                          ulTrrcT315Length;                                     /* UEʹ�õ�T315��ʱ����ʱ�� */
    VOS_UINT32                                          ulMcc;                                                /* ��ǰ����С������PLMN��Mcc*/
    VOS_UINT32                                          ulMnc;                                                /* ��ǰ����С������PLMN��Mnc*/
    VOS_UINT16                                          usLac;                                                /* ��ǰ����С�����ڵ�Lac*/
    VOS_UINT16                                          usServFreq;                                           /* ����С��Ƶ�� */
    VOS_UINT16                                          usServParaId;                                         /* ����С����cellParameters ID */
    VOS_INT8                                            ucServRscp[TRRC_CHR_OUT_OF_SYNC_REACH_RPT_NUM];       /* ����С������ */
    VOS_UINT32                                          ulServIdentityId;                                     /* SIB3��Я����cellIdentity ID */
}TRRC_OOS_INFO_STRU;

typedef struct
{
    VOS_UINT16                                          usFaultID;
    VOS_UINT16                                          usAlarmID;
    LPS_32K_TIMESTAMP                                   stTimeStamp;
    VOS_UINT32                                          ulDataLen;
    VOS_UINT8                                           *pdata;
}TRRC_RELATION_EVENT_RECORD_STRU;

typedef struct
{
    VOS_UINT32                                           ulIndex;
    TRRC_RELATION_EVENT_RECORD_STRU                      stErrLogEventRecord[TRRC_CORRELATIVE_EVENT_MAX_NUM];
}TRRC_RELATION_EVENT_POOL_STRU;

typedef struct
{
    VOS_UINT16                                           usFaultID;
    VOS_UINT16                                           usModemID;
    LPS_32K_TIMESTAMP                                    stTimeStamp;
}TRRC_FAULTIDDCT_RECORD_STRU;

typedef struct
{
    VOS_UINT32                                           ulIndex;
    TRRC_FAULTIDDCT_RECORD_STRU                          astFaultDCTRrecord[TRRC_FaultIDRPT_MAX_NUM];
}TRRC_FAULTIDDCT_POOL_STRU;

/* Modem errlog report, TDS correlative event report for example end. */

#endif

#if(FEATURE_ON == FEATURE_PTM)

#define MAX_CELL_RECORD_SIZE (10)        /* ����¼���פ����10��TС�� */
#define MAX_FAIL_COUNT (5)               /* ����¼���5�η���������̬������ʧ�� */

/*****************************************************************************
 ö����    : TRRC_APP_TL_RESEL_FALI_CAUSE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : TL��ѡʧ��ԭ��ö��
*****************************************************************************/
enum TRRC_APP_TL_RESEL_FALI_CAUSE_ENUM
{
    TRRC_APP_TL_RESEL_WAIT_CNF_EXPIRED       = 0x00,
    TRRC_APP_TL_RESEL_SIB_RCV_FAIL           = LRRC_GURRC_CELL_RESEL_SIB_RCV_FAIL,         /* ϵͳ��Ϣ����ʧ�� */
    TRRC_APP_TL_RESEL_CELL_BARRED            = LRRC_GURRC_CELL_RESEL_CELL_BARRED,         /* С��BAR */
    TRRC_APP_TL_RESEL_CELL_FORBID            = LRRC_GURRC_CELL_RESEL_CELL_FORBID,         /* С��FORBID */
    TRRC_APP_TL_RESEL_NOT_EPLMNS             = LRRC_GURRC_CELL_RESEL_NOT_EPLMNS,         /* С��PLMN������RPLMN��EPLMNS */
    TRRC_APP_TL_RESEL_ACCESS                 = LRRC_GURRC_CELL_RESEL_ACCESS,         /* С������ */
    TRRC_APP_TL_RESEL_UNSPECIFIC             = LRRC_GURRC_CELL_RESEL_UNSPECIFIC,         /* ����δ������� */
    TRRC_APP_TL_RESEL_CONNECTION_REJECT      = LRRC_GURRC_CELL_RESEL_CONNECTION_REJECT,         /* ����ָ�ɱ��ܻ����ӱ��� */
    TRRC_APP_TL_RESEL_S_OR_C1_CHECK_FAIL     = LRRC_GURRC_CELL_RESEL_S_OR_C1_CHECK_FAIL,         /* ��Ч���� */
    TRRC_APP_TL_RESEL_ARFCN_NOT_SUPPORT      = LRRC_GURRC_CELL_RESEL_ARFCN_NOT_SUPPORT,         /* MFBI��֧�ֵ�Ƶ�� */
    TRRC_APP_TL_RESEL_RESOURCE_OCCUPIED      = 0x10,         /* ����ռ */
    TRRC_APP_TL_RESEL_FAIL_CAUSE_BUTT
};
typedef VOS_UINT8  TRRC_APP_TL_RESEL_FALI_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : TL_RESEL_FAIL_RECORD_STRU;
 �ṹ˵��  : ��¼��ѡʧ�ܵĽṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                     ucFailCount;/* ��ѡʧ�ܴ��� */
    TRRC_APP_TL_RESEL_FALI_CAUSE_ENUM_UINT8       enFailCause;/* ��ѡʧ��ԭ�� */
    VOS_UINT8                                     aucReserved[2];
}TL_RESEL_FAIL_RECORD_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_EUTRA_INFO_STRU;
 �ṹ˵��  : LС�������������ѡ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usArfcn;/* LƵ�� */
    VOS_UINT16                          usCellId;/* LС��ID */
    VOS_INT16                           sRsrp;/* L����ֵ */
    VOS_INT16                           sRsrpThreshOfEutraForResel;/* ��ѡL����ֵ���� */
    VOS_INT16                           sRsrq;/* L�ź����� */
    VOS_INT16                           sRsrqThreshOfEutraForResel;/* ��ѡL�ź��������� */
}TRRC_EUTRA_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_LOW_EUTRA_INFO_STRU;
 �ṹ˵��  : TL�����ȼ���ѡLС�������������ѡ����
*****************************************************************************/
typedef struct
{
    TRRC_EUTRA_INFO_STRU                stEutraInfoForResel;
    VOS_INT16                           sThreshOfServingForResel;/* ��ѡT����ֵ */
    VOS_INT16                           sThreshOfServingForMeas;/* T���L����ֵ */
}TRRC_LOW_PRIOR_EUTRA_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_CELL_INFO_STRU;
 �ṹ˵��  : �ϱ���TDSС����Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulTimeStampHigh;/* ʱ�����32λ */
    VOS_UINT32                          ulTimeStampLow;/* ʱ�����32λ */
    VOS_UINT32                          ulmcc;              /* ��ǰPLMN */
    VOS_UINT32                          ulmnc;              /* ��ǰPLMN */
    VOS_UINT32                          ulCellIdentity;     /* Globale Cell ID */
    VOS_UINT16                          usLac;              /* lac */
    VOS_UINT8                           ucRac;              /* rac */
    TRRC_APP_PROTOCOL_STATE_ENUM_UINT8  enProtocalState;    /* Э��״̬ */
    VOS_UINT16                          usCellParameterID;  /* ����С��ID */
    VOS_UINT16                          usFrequency;        /* Ƶ�� */
    TDS_APP_FREQ_BAND_LIST_ENUM_UINT8   enBand;             /* band��Ϣ */
    VOS_INT8                            cRscp;              /* ����С������ */
    VOS_UINT8                           ucTLReselFailCount; /* ��ѡʧ�ܴ��� */
    TRRC_APP_TL_RESEL_FALI_CAUSE_ENUM_UINT8       enTLReselFailCause;/* ��ѡʧ��ԭ�� */
    PS_BOOL_ENUM_UINT8                  enEqualPriorFlag;   /* �Ƿ���ڵ����ȼ�LTE���� */
    PS_BOOL_ENUM_UINT8                  enHighPriorFlag;    /* �Ƿ���ڸ����ȼ�LTE���� */
    PS_BOOL_ENUM_UINT8                  enLowPriorFlag;     /* �Ƿ���ڵ����ȼ�LTE���� */
    VOS_UINT8                           ucReserved;
    TRRC_EUTRA_INFO_STRU                stHighPriorEutraNerghborInfo; /* �����ȼ�L��������ֵ������ */
    TRRC_LOW_PRIOR_EUTRA_INFO_STRU      stLowPriorEutraNerghborInfo; /* �����ȼ�L��������ֵ������ */
 }TRRC_APP_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_TL_HO_FAIL_CAUSE_ENUM _UINT8;
 �ṹ˵��  : �л�ʧ��ԭ��ö��
*****************************************************************************/
enum TRRC_APP_TL_HO_FAIL_CAUSE_ENUM
{
    TRRC_APP_TL_HO_WAIT_CNF_EXPIRED       = 0x00,
    TRRC_APP_TL_HO_CONF_UNACCEPTABLE      = LRRC_GURRC_HANDOVER_RESULT_CONF_UNACCEPTABLE,         /* ��֧������ */
    TRRC_APP_TL_HO_PHY_CHANNEL_FAIL       = LRRC_GURRC_HANDOVER_RESULT_PHY_CHANNEL_FAIL,         /* �����ŵ�ʧ�� */
    TRRC_APP_TL_HO_IRAT_PROTOCOL_ERR      = LRRC_GURRC_HANDOVER_RESULT_IRAT_PROTOCOL_ERR,         /* Э����� */
    TRRC_APP_TL_HO_UNSPECIFIC             = LRRC_GURRC_HANDOVER_RESULT_UNSPECIFIC,         /* δ������� */
    TRRC_APP_TL_HO_ARFCN_NOT_SUPPORT      = LRRC_GURRC_HANDOVER_RESULT_ARFCN_NOT_SUPPORT,         /* ��֧��Ƶ�� */
    TRRC_APP_TL_HO_RESOURCE_OCCUPIED      = 0x06,         /* ����ռ */
    TRRC_APP_TL_HO_FAIL_CAUSE_BUTT
};
typedef VOS_UINT8  TRRC_APP_TL_HO_FAIL_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : TL_HO_FAIL_INFO_STRU;
 �ṹ˵��  : ��¼�л�ʧ�ܵĽṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                   ulTimeStampHigh;/* ʱ�����32λ */
    VOS_UINT32                                   ulTimeStampLow;/* ʱ�����32λ */
    TRRC_APP_TL_HO_FAIL_CAUSE_ENUM_UINT8         enFailCause; /* ʧ��ԭ�� */
    VOS_UINT8                                    aucReserved[3];
}TL_HO_FAIL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_TL_REDIR_FAIL_CAUSE_ENUM _UINT8;
 �ṹ˵��  : �ض���ʧ��ԭ��ö��
*****************************************************************************/
enum TRRC_APP_TL_REDIR_FAIL_CAUSE_ENUM
{
    TRRC_APP_TL_REDIR_WAIT_CNF_EXPIRED     = 0x00,
    TRRC_APP_TL_REDIR_FAIL                 = LRRC_GURRC_REDIRECTED_FAIL,         /* L�ظ��ض���ʧ�� */
    TRRC_APP_TL_REDIR_ARFCN_NOT_SUPPORT    = LRRC_GURRC_REDIRECTED_ARFCN_NOT_SUPPORT,         /* ��֧��Ƶ�� */
    TRRC_APP_TL_REDIR_RESOURCE_OCCUPIED    = 0x03,         /* ����ռ */
    TRRC_APP_TL_REDIR_FAIL_CAUSE_BUTT
};
typedef VOS_UINT8  TRRC_APP_TL_REDIR_FAIL_CAUSE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : TL_REDIR_FAIL_INFO_STRU;
 �ṹ˵��  : ��¼�л�ʧ�ܵĽṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                   ulTimeStampHigh;/* ʱ�����32λ */
    VOS_UINT32                                   ulTimeStampLow;/* ʱ�����32λ */
    TRRC_APP_TL_REDIR_FAIL_CAUSE_ENUM_UINT8      enFailCause; /*ʧ��ԭ��*/
    VOS_UINT8                                    aucReserved[3];
}TL_REDIR_FAIL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : TRRC_APP_NOT_TO_EUTRA_INFO_STRU;
 �ṹ˵��  : ���ڲ�פ��4G�ϱ���CHR�ṹ��
*****************************************************************************/
typedef struct
{
    OM_ERR_LOG_HEADER_STRU                  stHeader;                /* ��Ϣͷ */
    TRRC_APP_ERROR_CODE_ENUM_UINT8          enErrorCode;             /* ������*/
    VOS_UINT8                               ucServingCellCount;      /* ��¼��С����Ŀ */
    VOS_UINT8                               ucTLHoCount;             /* �л�ʧ�ܴ��� */
    VOS_UINT8                               ucTLRedirCount;          /* �ض���ʧ�ܴ��� */
    TRRC_APP_CELL_INFO_STRU                 astTcellInfo[MAX_CELL_RECORD_SIZE];  /* ����4GС����¼ */
    TL_HO_FAIL_INFO_STRU                    astTLHoInfo[MAX_FAIL_COUNT];      /* TL�л�ʧ�ܼ�¼ */
    TL_REDIR_FAIL_INFO_STRU                 astTLRedirInfo[MAX_FAIL_COUNT];     /* TL�ض���ʧ�ܼ�¼ */
}TRRC_APP_NOT_TO_EUTRA_INFO_STRU;

#endif

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

#endif /* end of TrrcErrLogInterface.h */


