/******************************************************************************

    Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
  File Name       : LRrcLPhyInterface.h
  Description     : LRRC��LRTT�ӿ��ļ�
  History         :
     1.lidui 143774       2011-2-14     Draft Enact
     2.lishangfeng  55206 2011-09-11 DTS2011091100356:����Ϣά�����ԸĽ��������ܹ�֧�ֶ�Bandʱ��ά��
******************************************************************************/
#ifndef __LRRCLPHYINTERFACE_H__
#define __LRRCLPHYINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#ifndef LPS_RTT
#include "vos.h"
#include "LPSCommon.h"
#endif
#include "TLPhyInterface.h"

/**/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif


#ifdef LPS_RTT
#define VOS_MSG_HEADER
#endif


/*****************************************************************************
  2 macro
*****************************************************************************/
/* MBMS begin */
#define LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA                        8
#define LRRC_LPHY_MAX_NUM_OF_MBSFN_ALLOC                       8
#define LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN                   15
/* MBMS end */
/* Э��ջ�·�����������ĺ�С����Ŀ */
#define    LRRC_LPHY_MAX_CANDIDATE_CELL_NUM                   32

/* һ����ཨ�������ͷŵ��ŵ����� */
#define    LRRC_LPHY_MAX_CHANNEL_NUM                          8

/* UE֧�ֵ�ͬƵ����ƵС�������Ŀ */
#define    LRRC_LPHY_MAX_FREQ_CELL_NUM                        33

#define    LRRC_LPHY_REPORT_MAX_FREQ_CELL_NUM                 18


/* V7R5֮ǰ�İ汾��:
   ��ģ��LTEģʱ��UE֧�ֵ���Ƶ�������Ŀ��4��
   ��ģΪLTEģʱ��UE֧�ֵ���Ƶ�������Ŀ��3 */
/* V7R5�Լ�֮��İ汾:
   ��ģ��LTEģʱ��UE֧�ֵ���Ƶ�������Ŀ��9��
   ��ģΪLTEģʱ��UE֧�ֵ���Ƶ�������Ŀ��8 */
#define    LRRC_LPHY_MAX_ADDITIONAL_CARRIER_NUM               9

/* UE ���� SI ��Ϣ�������Ŀ */
#define LRRC_LPHY_MAX_SI_CONFIG_NUM                           32

/* Э��ջ���õ����N1_PUCCH_AN_PERSISTENT��Ŀ */
#define LRRC_LPHY_MAX_N1_PUCCH_AN_PERSISTENT_NUM              4

/* V7R2֧�����е� CA,V7R5֧������3 CC, �Լ�����CA */
#if (FEATURE_ON == FEATURE_LTE_R13)
#define LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM                   4
#elif ((FEATURE_ON == FEATURE_LTE_R11)&&(!defined(TL_PHY_ASIC_V850)))
#define LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM                   3
#else
#define LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM                   1
#endif

#define LRRC_LPHY_MAX_UTRAN_CARRIER_NUM                       9

#define LRRC_LPHY_MAX_N3_PUCCH_AN_LIST_NUM                    4
#define LRRC_LPHY_MAX_N3_PUCCH_AN_LIST_P1_NUM                 4
#define LRRC_LPHY_MAX_N1_PUCCH_AN_CS_LIST_NUM                 2
#define LRRC_LPHY_MAX_N1_PUCCH_AN_CS_NUM                      4
#define LRRC_LPHY_MAX_SRS_CFG_AP_DCI_FORMAT4_NUM              3


/* ������ϱ�ɨƵ��������Ƶ���� */
#define LRRC_LPHY_MAX_SCAN_FREQ_NUM                           100

/* Maximum number of MBSFN frame allocations with different offset */
#define LRRC_LPHY_MAX_MBSFN_ALLOCATIONS_NUM                   8

/* BSIC������б� */
#define LRRC_LPHY_MAX_BSIC_NUM                                8

/* ��ַ��BUF����¼����Ϣ���� */
#define LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_BUF_MAX               16

/* ���Ƶ�ַ������¼����Ϣ���� */
#define LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_MAX   3

/* LCS Begin */
#define LRRC_LPHY_ECID_MAX_NEIGHBOUR_CELL_NUM               32
#define LRRC_LPHY_OTDOA_MAX_NEIGHBOUR_CELL_NUM              (3 * 24)            /*OTDOA����������Ϣ�������б������������*/
#define LRRC_LPHY_OTDOA_MAX_FREQ_LAYER_NUM                  4                   /*RSTD����������Ϣ������Ƶ�ʲ���*/
#define LRRC_LPHY_OTDOA_MAX_NEIGHBOUR_CELL_NUM_PER_LAYER    24                  /*ÿ��Ƶ�ʲ�����ھ�С����*/
#define LRRC_LPHY_OTDOA_MAX_RSTD_FREQ_NUM                   3                   /*����RSTD��Ƶ����Ƶ����*/
#define LRRC_LPHY_RF_DCOC_RPT_DATA_SIZE                     12
#define LRRC_LPHY_RF_TXIQ_RPT_DATA_SIZE                     4
#define LRRC_LPHY_QUERY_SELF_ADJUST_PARA_MAX_BAND_NUM       3


/* LCS End */
/* TCXo */
#define LRRC_LPHY_TCX0_RSRP_THRESHOLD                            (-120 * 8)
/* ��ģ�·����䳤�ȣ���λ:��,2.5Kword */
#define LRRC_LPHY_SLAVE_DOWN_MAILBOX_MSG_LEN ((LPHY_MAILBOX_LHPA_DOWN_SIZE - sizeof(LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU))/4)

/* ��ģ�ϱ����䳤�ȣ���λ:��,1.5Kword */
#define LRRC_LPHY_SLAVE_UP_MAILBOX_MSG_LEN  ((LPHY_MAILBOX_LHPA_UP_SIZE - sizeof(LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU))/4)

#define ERRC_LPHY_MSG_HDR                (0x000008C0)         /* PS_MSG_ID_ERRC_TO_LPHY_BASE begin with 2240 */
#define LPHY_ERRC_MSG_HDR                (0x00000900)         /* PS_MSG_ID_LPHY_TO_ERRC_BASE begin with 2304 */
#define ERMM_LPHY_MSG_HDR                (0x00000940)         /* PS_MSG_ID_ERMM_TO_LPHY_BASE begin with 2368 */
#define LPHY_ERMM_MSG_HDR                (0x00000980)         /* PS_MSG_ID_LPHY_TO_ERMM_BASE begin with 2432 */

/*Ѱ����������begin*/
#define LRRC_LPHY_MAX_NUM_OF_IMSI_DSP      21
/* sunyanjie begin */
#define LRRC_LPHY_MAX_CELL_NUM            5
/* sunyanjie end */

/*�����һ������д��NV������*/
#define LRRC_LPHY_MAX_NV_WRITE_NUM        4

#define LRRC_LPHY_MAX_CELL_REPORT_NUM                         8

#define LRRC_LPHY_MAX_RE_MAP_QCL_NUM                          4

#if (FEATURE_ON == FEATURE_LTE_R13)
#define LRRC_LPHY_MAX_CSI_RS_NZP_NUM                          3 /* R13Э��ֵ24��Ŀǰ���ǰ���ʵ��ʵ��R12���� */
#else
#define LRRC_LPHY_MAX_CSI_RS_NZP_NUM                          3
#endif

#define LRRC_LPHY_MAX_CSI_RS_ZP_NUM                           4

#define LRRC_LPHY_MAX_CQI_PROC_EXT_NUM                        3

#if (FEATURE_ON == FEATURE_LTE_R13)
#define LRRC_LPHY_MAX_CSI_IM_NUM                              4 /* R13Э��ֵ24��Ŀǰ���ǰ���ʵ��ʵ��R12���� */
#else
#define LRRC_LPHY_MAX_CSI_IM_NUM                              3
#endif

#define LRRC_LPHY_MAX_CSI_PROC_NUM                            4

#define LRRC_LPHY_MAX_STAG_NUM                                3

#define LRRC_LPHY_MAX_N1_PUCCH_AN_CS_LIST_P1_NUM              4

#define LRRC_LPHY_FREQ_RSSI_MAX_SCAN_NUM                      64

#define LRRC_LPHY_MAX_NUM_OF_BANDS                           (64)

#if (FEATURE_ON == FEATURE_LTE_R13)
#define LRRC_LPHY_MAX_NUM_OF_CSI_RS                          (32)

#define LRRC_LPHY_MAX_NUM_OF_DS_ZTP_CSI_RS                    5

/* DS����֧�ֵ������Ƶ�ĸ��� */
#define LRRC_LPHY_MAX_ADDITIONAL_DS_CC_NUM                    (LRRC_LPHY_MAX_ADDITIONAL_CARRIER_NUM - 1)

/* һ��Ƶ������ϱ���CSI�ĸ��� */
#define LRRC_LPHY_REPORT_MAX_FREQ_DS_CSI_NUM                  18

#define LRRC_LPHY_MAX_NUM_OF_CSI_IM_CONFIG_ID                  2

#define LRRC_LPHY_MAX_NUM_OF_IRAT_MEAS_PRIO                    9
#endif
#define LRRC_LPHY_MAX_RX_ANT_NUM                              4
#if (FEATURE_ON == FEATURE_LTE_R13)
#define LRRC_LPHY_APRDC_CQI_MAX_TRIG_NUM                      6

#define LRRC_LPHY_NAICS_MAX_NEIGH_CELL_NUM                    8

#define LRRC_LPHY_MAX_PA_PER_NEIGH_CELL                       3
#define LRRC_LPHY_MAX_NZP_RS_NUM                              2
#define LRRC_LPHY_MAX_PC_CBSR_NUM                             2
#define LRRC_LPHY_MAX_NZP_ID_NUM                              7
#define LRRC_LPHY_MAX_P_C_AND_CBSR_PER_RS_CFG_NUM             1 /* R13Э����8����ǰboston��ʵ�ִ˹��ܣ�Ϊ�˼���ԭ���С��������1.1k������ʱ����Ϊ1 ��ʵ��ʱ�ٻظ�Ϊ8*/
#define LRRC_LPHY_MAX_ACE_FOR_4TX_NUM                         7
#define LRRC_LPHY_MAX_CE_LVL_NUM                              4
#define LRRC_LPHY_MAX_FRMT4_RSR_NUM                           4
#define LRRC_LPHY_MAX_FRMT4_MUL_CSI_RSR_NUM                   2
#define LRRC_LPHY_MAX_FRMT5_RSR_NUM                           4
#define LRRC_LPHY_MAX_MPDCCH_NARROW_BAND_TO_MON_NUM           4
#define LRRC_LPHY_MAX_RSRP_THRES_PRACH_NUM                    3
#define LRRC_LPHY_MAX_LAA_CC_NUM                              8
#endif

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 ö����    : LRRC_LPHY_MSG_ID_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : LRRC -> LPHY �ӿ���ϢID
*****************************************************************************/
enum LRRC_LPHY_MSG_ID_ENUM
{
    /* RRC����������ԭ�� */
    ID_LRRC_LPHY_CELL_SEARCHING_REQ               = (ERMM_LPHY_MSG_HDR + 0x00), /* _H2ASN_MsgChoice LRRC_LPHY_CELL_SEARCHING_REQ_STRU */
    ID_LRRC_LPHY_CAMPED_MAINCELL_REQ              = (ERRC_LPHY_MSG_HDR + 0x01), /* _H2ASN_MsgChoice LRRC_LPHY_CAMPED_MAINCELL_REQ_STRU */
    ID_LRRC_LPHY_RL_SETUP_REQ                     = (ERRC_LPHY_MSG_HDR + 0x02), /* _H2ASN_MsgChoice LRRC_LPHY_RL_SETUP_REQ_STRU */
    ID_LRRC_LPHY_RL_RELEASE_REQ                   = (ERRC_LPHY_MSG_HDR + 0x03), /* _H2ASN_MsgChoice LRRC_LPHY_RL_RELEASE_REQ_STRU */
    ID_LRRC_LPHY_MEAS_IN_IDLE_REQ                 = (ERMM_LPHY_MSG_HDR + 0x04), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_IN_IDLE_REQ_STRU */
    ID_LRRC_LPHY_MEAS_IN_CONNECTED_REQ            = (ERMM_LPHY_MSG_HDR + 0x05), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_IN_CONNECTED_REQ_STRU */
    ID_LRRC_LPHY_MEAS_GAP_CONFIG_REQ              = (ERMM_LPHY_MSG_HDR + 0x06), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_GAP_CONFIG_REQ_STRU */
    ID_LRRC_LPHY_REL_ALL_REQ                      = (ERRC_LPHY_MSG_HDR + 0x07), /* _H2ASN_MsgChoice LRRC_LPHY_RELALL_REQ_STRU */
    ID_LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_REQ      = (ERRC_LPHY_MSG_HDR + 0x08), /* _H2ASN_MsgChoice LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_REQ_STRU */
    ID_LRRC_LPHY_SRS_CONFIG_REQ                   = (ERRC_LPHY_MSG_HDR + 0x09), /* _H2ASN_MsgChoice LRRC_LPHY_SRS_CONFIG_REQ_STRU */
    ID_LRRC_LPHY_HO_REQ                           = (ERRC_LPHY_MSG_HDR + 0x0a), /* _H2ASN_MsgChoice LRRC_LPHY_HO_REQ_STRU */
    ID_LRRC_LPHY_CQI_CONFIG_REQ                   = (ERRC_LPHY_MSG_HDR + 0x0b), /* _H2ASN_MsgChoice LRRC_LPHY_CQI_CONFIG_REQ_STRU */
    ID_LRRC_LPHY_UPLINK_MAXTXPWR_REQ              = (ERRC_LPHY_MSG_HDR + 0x0c), /* _H2ASN_MsgChoice LRRC_LPHY_UPLINK_MAXTXPWR_REQ_STRU */
    ID_LRRC_LPHY_SYNC_REQ                         = (ERRC_LPHY_MSG_HDR + 0x0d), /* _H2ASN_MsgChoice LRRC_LPHY_SYNC_REQ_STRU */
    ID_LRRC_LPHY_SI_CONFIG_REQ                    = (ERMM_LPHY_MSG_HDR + 0x0e), /* _H2ASN_MsgChoice LRRC_LPHY_SI_CONFIG_REQ_STRU */

    /* ID_LRRC_LPHY_DRX_GATECLOCK_INDû��ʹ�ã�����ɾ�� */
    ID_LRRC_LPHY_DRX_GATECLOCK_IND                = (ERRC_LPHY_MSG_HDR + 0x0f), /* _H2ASN_MsgChoice LRRC_LPHY_CONFIG_DRX_GATECLOCK_IND_STRU */

    ID_LRRC_LPHY_TCXO_QUERY_REQ                   = (ERMM_LPHY_MSG_HDR + 0x10), /* _H2ASN_MsgChoice LRRC_LPHY_TCXO_QUERY_REQ_STRU */
    ID_LRRC_LPHY_BAND_SCAN_REQ                    = (ERMM_LPHY_MSG_HDR + 0x11), /* _H2ASN_MsgChoice LRRC_LPHY_BAND_SCAN_REQ_STRU */
    ID_LRRC_LPHY_SET_WORK_MODE_REQ                = (ERRC_LPHY_MSG_HDR + 0x12), /* _H2ASN_MsgChoice LRRC_LPHY_SET_WORK_MODE_REQ_STRU */
    ID_LRRC_LPHY_BSIC_VERIFY_REQ                  = (ERMM_LPHY_MSG_HDR + 0x13), /* _H2ASN_MsgChoice LRRC_LPHY_BSIC_VERIFY_REQ_STRU */
    /* MBMS Begin */
    ID_LRRC_LPHY_MBSFN_MCCH_CFG_REQ               = (ERRC_LPHY_MSG_HDR + 0x14), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_MCCH_CFG_REQ_STRU*/
    ID_LRRC_LPHY_MBSFN_NOTIFY_CFG_REQ             = (ERRC_LPHY_MSG_HDR + 0x15), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_NOTIFY_CFG_REQ_STRU*/
    ID_LRRC_LPHY_MBSFN_PMCH_CFG_REQ               = (ERRC_LPHY_MSG_HDR + 0x16), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_PMCH_CFG_REQ_STRU*/
    ID_LRRC_LPHY_MBSFN_SUBFRAME_CFG_REQ           = (ERRC_LPHY_MSG_HDR + 0x17), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_SUBFRAME_CFG_REQ_STRU*/
    /* MBMS End */

    /* LCS Begin */
    ID_LRRC_LPHY_OTDOA_REQ                        = (ERMM_LPHY_MSG_HDR + 0x18), /* _H2ASN_MsgChoice LRRC_LPHY_OTDOA_REQ_STRU */
    /* LCS End */

    ID_LRRC_LPHY_SWTICH_IND                       = (ERRC_LPHY_MSG_HDR + 0x1a), /* _H2ASN_MsgChoice LRRC_LPHY_SWITCH_IND_STRU */

    /* lishangfeng bg search begin */
    ID_LRRC_LPHY_BG_SEARCH_START_REQ              = (ERMM_LPHY_MSG_HDR + 0x1b), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_START_REQ_STRU */
    ID_LRRC_LPHY_BG_SEARCH_STOP_REQ               = (ERMM_LPHY_MSG_HDR + 0x1c), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_STOP_REQ_STRU */
    ID_LRRC_LPHY_BG_SEARCH_SUSPEND_REQ            = (ERMM_LPHY_MSG_HDR + 0x1d), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_SUSPEND_REQ_STRU */
    ID_LRRC_LPHY_BG_SEARCH_RESUME_REQ             = (ERMM_LPHY_MSG_HDR + 0x1e), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_RESUME_REQ_STRU */

    /* lishangfeng bg search end */

    /* lishangfeng Anr search begin */
    ID_LRRC_LPHY_ANR_START_REQ                    = (ERMM_LPHY_MSG_HDR + 0x1f), /* _H2ASN_MsgChoice LRRC_LPHY_ANR_START_REQ_STRU */
    ID_LRRC_LPHY_ANR_STOP_REQ                     = (ERMM_LPHY_MSG_HDR + 0x20), /* _H2ASN_MsgChoice LRRC_LPHY_ANR_STOP_REQ_STRU */
    /* lishangfeng Anr search end */

    ID_LRRC_LPHY_QUERY_SELF_ADJUST_PARA_REQ      = (ERRC_LPHY_MSG_HDR + 0x21), /* _H2ASN_MsgChoice LRRC_LPHY_QUERY_SELF_ADJUST_PARA_REQ_STRU */

    /*Ѱ����������begin*/
    ID_LRRC_LPHY_PAGING_INFO_REQ                 = (ERRC_LPHY_MSG_HDR + 0x22), /* _H2ASN_MsgChoice LRRC_LPHY_PAGING_INFO_REQ_STRU */
    /*Ѱ����������end*/

    ID_LRRC_LPHY_NOTCH_REQ                       = (ERRC_LPHY_MSG_HDR + 0x23), /* _H2ASN_MsgChoice LRRC_LPHY_NOTCH_REQ_STRU */

    ID_LRRC_LPHY_DPDT_CMD_REQ                   = (ERRC_LPHY_MSG_HDR + 0x24),

    ID_LRRC_LPHY_NV_WRITE_RSP                      = (ERRC_LPHY_MSG_HDR + 0x25),

    ID_LRRC_LPHY_STAG_CONFIG_REQ                  = (ERRC_LPHY_MSG_HDR + 0x26), /* _H2ASN_MsgChoice LRRC_LPHY_STAG_CONFIG_REQ_STRU */
    /*begin: hifi sync switch */
    ID_LRRC_LPHY_HIFI_SYNC_SWITCH_IND             = (ERRC_LPHY_MSG_HDR + 0x28),   /* _H2ASN_MsgChoice LRRC_LPHY_HIFI_SYNC_SWITCH_IND_STRU */
    /*end: hifi sync switch */
    ID_LRRC_LPHY_FREQ_RSSI_SCAN_REQ               = (ERMM_LPHY_MSG_HDR + 0x29),   /* _H2ASN_MsgChoice LRRC_LPHY_FREQ_RSSI_SCAN_REQ_STRU */

    ID_LRRC_LPHY_MBMS_ENABLE_REQ                  = (ERRC_LPHY_MSG_HDR + 0x27), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_ENABLE_REQ_STRU */
    ID_LRRC_LPHY_MBMS_DISABLE_REQ                 = (ERRC_LPHY_MSG_HDR + 0x2a), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_DISABLE_REQ_STRU */
    ID_LRRC_LPHY_MBMS_PMCH_ACTIVE_REQ             = (ERRC_LPHY_MSG_HDR + 0x2b), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_PMCH_ACTIVE_REQ_STRU */
    ID_LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_REQ       = (ERRC_LPHY_MSG_HDR + 0x2c), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_REQ_STRU */
    ID_LRRC_LPHY_MBMS_MRS_MEAS_IND                = (ERRC_LPHY_MSG_HDR + 0x2d), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_MRS_MEAS_IND_STRU */
    ID_LRRC_LPHY_MBMS_RCV_ALL_MCCH_IND            = (ERRC_LPHY_MSG_HDR + 0x2e), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_RCV_ALL_MCCH_IND_STRU */
    ID_LRRC_LPHY_CONNECTED_TO_IDLE_REQ            = (ERRC_LPHY_MSG_HDR + 0x2f), /* _H2ASN_MsgChoice LRRC_LPHY_CONNECTED_TO_IDLE_REQ_STRU */

    ID_LRRC_LPHY_RLF_PARA_NOTIFY                  = (ERRC_LPHY_MSG_HDR + 0x30), /* _H2ASN_MsgChoice LRRC_LPHY_RLF_PARA_NOTIFY_STRU */
    ID_LRRC_LPHY_FREQ_RSSI_SCAN_STOP_REQ          = (ERMM_LPHY_MSG_HDR + 0x31),    /* _H2ASN_MsgChoice LRRC_LPHY_FREQ_RSSI_SCAN_STOP_REQ_STRU */

    ID_LRRC_LPHY_SUSPEND_NTF                      = (ERMM_LPHY_MSG_HDR + 0x32), /* _H2ASN_MsgChoice LRRC_LPHY_SUSPEND_NTF_STRU */
    ID_LRRC_LPHY_RESUME_NTF                       = (ERMM_LPHY_MSG_HDR + 0x33), /* _H2ASN_MsgChoice LRRC_LPHY_RESUME_NTF_STRU */
#if (FEATURE_ON == FEATURE_LTE_R13)
    ID_LRRC_LPHY_SCG_DRX_CONFIG_IN_CONNECTED_REQ  = (ERRC_LPHY_MSG_HDR + 0x34), /* _H2ASN_MsgChoice LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_REQ_STRU */
    ID_LRRC_LPHY_MBSFN_LOG_REQ                    = (ERRC_LPHY_MSG_HDR + 0x35), /* _H2ASN_MsgChoice LRRC_LPHY_MBSFN_LOG_REQ_STRU */
    ID_LRRC_LPHY_DS_MEAS_INTRA_REQ                = (ERMM_LPHY_MSG_HDR + 0x36), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_INTRA_REQ_STRU */
    ID_LRRC_LPHY_DS_MEAS_INTER_REQ                = (ERMM_LPHY_MSG_HDR + 0x37), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_INTER_REQ_STRU */
    ID_LRRC_LPHY_DS_MEAS_SECOND_FREQ_REQ          = (ERMM_LPHY_MSG_HDR + 0x38), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_SECOND_FREQ_REQ_STRU */
    ID_LRRC_LPHY_COMM_MEAS_CONFIG_REQ             = (ERMM_LPHY_MSG_HDR + 0x39), /* _H2ASN_MsgChoice LRRC_LPHY_COMM_MEAS_CONFIG_REQ_STRU */
    ID_LRRC_LPHY_SCELL_RL_RELEASE_REQ             = (ERRC_LPHY_MSG_HDR + 0x3a), /* _H2ASN_MsgChoice LRRC_LPHY_SCELL_RL_RELEASE_REQ_STRU */
    ID_LRRC_LPHY_SCG_RLF_PARA_NOTIFY              = (ERRC_LPHY_MSG_HDR + 0x3b), /* _H2ASN_MsgChoice LRRC_LPHY_SCG_RLF_PARA_NOTIFY_STRU */
    /* ˫LTE����˫���л����ԣ�begin */
    ID_LRRC_LPHY_MODEM_START_STATE_INFO_REQ       = (ERRC_LPHY_MSG_HDR + 0x3e), /* _H2ASN_MsgChoice LRRC_LPHY_MODEM_START_STATE_INFO_REQ_STRU */
    /* ˫LTE����˫���л����ԣ�end */
#endif

    /* ����㷢��RRC��ԭ�� */
    ID_LRRC_LPHY_CELL_SEARCHING_IND               = (LPHY_ERMM_MSG_HDR + 0x00), /* _H2ASN_MsgChoice LRRC_LPHY_CELL_SEARCHING_IND_STRU */
    ID_LRRC_LPHY_CAMPED_MAINCELL_CNF              = (LPHY_ERRC_MSG_HDR + 0x01), /* _H2ASN_MsgChoice LRRC_LPHY_CAMPED_MAINCELL_CNF_STRU */
    ID_LRRC_LPHY_RL_SETUP_CNF                     = (LPHY_ERRC_MSG_HDR + 0x02), /* _H2ASN_MsgChoice LRRC_LPHY_RL_SETUP_CNF_STRU */
    ID_LRRC_LPHY_RL_RELEASE_CNF                   = (LPHY_ERRC_MSG_HDR + 0x03), /* _H2ASN_MsgChoice LRRC_LPHY_RL_RELEASE_CNF_STRU */
    ID_LRRC_LPHY_SYNC_IND                         = (LPHY_ERRC_MSG_HDR + 0x04), /* _H2ASN_MsgChoice LRRC_LPHY_SYNC_IND_STRU */
    ID_LRRC_LPHY_MEAS_IN_IDLE_CNF                 = (LPHY_ERMM_MSG_HDR + 0x05), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_IN_IDLE_CNF_STRU */
    ID_LRRC_LPHY_MEAS_IN_IDLE_IND                 = (LPHY_ERMM_MSG_HDR + 0x06), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_IN_IDLE_IND_STRU */
    ID_LRRC_LPHY_MEAS_IN_CONNECTED_CNF            = (LPHY_ERMM_MSG_HDR + 0x07), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_IN_CONNECTED_CNF_STRU */
    ID_LRRC_LPHY_MEAS_IN_CONNECTED_IND            = (LPHY_ERMM_MSG_HDR + 0x08), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_IN_CONNECTED_IND_STRU */
    ID_LRRC_LPHY_REL_ALL_CNF                      = (LPHY_ERRC_MSG_HDR + 0x09), /* _H2ASN_MsgChoice LRRC_LPHY_RELALL_CNF_STRU */
    ID_LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_CNF      = (LPHY_ERRC_MSG_HDR + 0x0a), /* _H2ASN_MsgChoice LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_CNF_STRU */
    ID_LRRC_LPHY_SRS_CONFIG_CNF                   = (LPHY_ERRC_MSG_HDR + 0x0b), /* _H2ASN_MsgChoice LRRC_LPHY_SRS_CONFIG_CNF_STRU */
    ID_LRRC_LPHY_HO_CNF                           = (LPHY_ERRC_MSG_HDR + 0x0c), /* _H2ASN_MsgChoice LRRC_LPHY_HO_CNF_STRU */
    ID_LRRC_LPHY_CQI_CONFIG_CNF                   = (LPHY_ERRC_MSG_HDR + 0x0d), /* _H2ASN_MsgChoice LRRC_LPHY_CQI_CONFIG_CNF_STRU */
    ID_LRRC_LPHY_MEAS_GAP_CONFIG_CNF              = (LPHY_ERMM_MSG_HDR + 0x0e), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_GAP_CONFIG_CNF_STRU */
    ID_LRRC_LPHY_OUT_OF_SYNC_IND                  = (LPHY_ERRC_MSG_HDR + 0x0f), /* _H2ASN_MsgChoice LRRC_LPHY_OUT_OF_SYNC_IND_STRU */
    ID_LRRC_LPHY_SYNC_CNF                         = (LPHY_ERRC_MSG_HDR + 0x10), /* _H2ASN_MsgChoice LRRC_LPHY_SYNC_CNF_STRU */
    ID_LRRC_LPHY_SI_CONFIG_CNF                    = (LPHY_ERMM_MSG_HDR + 0x11), /* _H2ASN_MsgChoice LRRC_LPHY_SI_CONFIG_CNF_STRU */
    ID_LRRC_LPHY_TCXO_QUERY_CNF                   = (LPHY_ERMM_MSG_HDR + 0x12), /* _H2ASN_MsgChoice LRRC_LPHY_TCXO_QUERY_CNF_STRU */
    ID_LRRC_LPHY_BAND_SCAN_IND                    = (LPHY_ERMM_MSG_HDR + 0x13), /* _H2ASN_MsgChoice LRRC_LPHY_BAND_SCAN_IND_STRU */
    ID_LRRC_LPHY_SET_WORK_MODE_CNF                = (LPHY_ERRC_MSG_HDR + 0x14), /* _H2ASN_MsgChoice LRRC_LPHY_SET_WORK_MODE_CNF_STRU */
    ID_LRRC_LPHY_BSIC_VERIFY_CNF                  = (LPHY_ERMM_MSG_HDR + 0x15), /* _H2ASN_MsgChoice LRRC_LPHY_BSIC_VERIFY_CNF_STRU */
    ID_LRRC_LPHY_ERROR_IND                        = (LPHY_ERRC_MSG_HDR + 0x16), /* _H2ASN_MsgChoice LRRC_LPHY_ERROR_IND_STRU */
    /* MBMS Begin */
    ID_LRRC_LPHY_MBSFN_MCCH_CFG_CNF               = (LPHY_ERRC_MSG_HDR + 0x17), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_MCCH_CFG_CNF_STRU*/
    ID_LRRC_LPHY_MBSFN_NOTIFY_CFG_CNF             = (LPHY_ERRC_MSG_HDR + 0x18), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_NOTIFY_CFG_CNF_STRU*/
    ID_LRRC_LPHY_MBSFN_PMCH_CFG_CNF               = (LPHY_ERRC_MSG_HDR + 0x19), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_PMCH_CFG_CNF_STRU*/
    ID_LRRC_LPHY_MBSFN_NOTIFY_IND                 = (LPHY_ERRC_MSG_HDR + 0x1a), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_NOTIFY_IND_STRU*/
    ID_LRRC_LPHY_MBSFN_SUBFRAME_CFG_CNF           = (LPHY_ERRC_MSG_HDR + 0x1b), /* _H2ASN_MsgChoice  LRRC_LPHY_MBSFN_SUBFRAME_CFG_CNF_STRU*/
    /* MBMS End */

    /* LCS Begin */
    ID_LRRC_LPHY_OTDOA_CNF                        = (LPHY_ERMM_MSG_HDR + 0x1c), /* _H2ASN_MsgChoice LRRC_LPHY_OTDOA_CNF_STRU */
    ID_LRRC_LPHY_OTDOA_IND                        = (LPHY_ERMM_MSG_HDR + 0x1d), /* _H2ASN_MsgChoice LRRC_LPHY_OTDOA_IND_STRU */
    ID_LRRC_LPHY_LCS_GAP_REQ                      = (LPHY_ERMM_MSG_HDR + 0x1e), /* _H2ASN_MsgChoice LRRC_LPHY_LCS_GAP_REQ_STRU */
    /* LCS End */

    /* lishangfeng bg search begin */
    ID_LRRC_LPHY_BG_SEARCH_START_CNF              = (LPHY_ERMM_MSG_HDR + 0x1f), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_START_CNF_STRU */
    ID_LRRC_LPHY_BG_SEARCH_STOP_CNF               = (LPHY_ERMM_MSG_HDR + 0x20), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_STOP_CNF_STRU */
    ID_LRRC_LPHY_BG_SEARCH_SUSPEND_CNF            = (LPHY_ERMM_MSG_HDR + 0x21), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_SUSPEND_CNF_STRU */
    ID_LRRC_LPHY_BG_SEARCH_RESUME_CNF             = (LPHY_ERMM_MSG_HDR + 0x22), /* _H2ASN_MsgChoice LRRC_LPHY_BG_SEARCH_RESUME_CNF_STRU */
    /* lishangfeng bg search end */

    /* lishangfeng Anr search begin */
    ID_LRRC_LPHY_ANR_START_CNF                    = (LPHY_ERMM_MSG_HDR + 0x23), /* _H2ASN_MsgChoice LRRC_LPHY_ANR_START_CNF_STRU */
    ID_LRRC_LPHY_ANR_STOP_CNF                     = (LPHY_ERMM_MSG_HDR + 0x24), /* _H2ASN_MsgChoice LRRC_LPHY_ANR_STOP_CNF_STRU */
    /* lishangfeng Anr search end */

    ID_LRRC_LPHY_QUERY_SELF_ADJUST_PARA_CNF       = (LPHY_ERRC_MSG_HDR + 0x25), /* _H2ASN_MsgChoice LRRC_LPHY_QUERY_SELF_ADJUST_PARA_CNF_STRU */

    /* NMR begin */
    ID_LRRC_LPHY_MEAS_INFO_IND                    = (LPHY_ERMM_MSG_HDR + 0x26), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_INFO_IND_STRU */
    /* NMR end */

    /* sunyanjie begin */
    ID_LRRC_LPHY_ERROR_LOG_IND                    = (LPHY_ERMM_MSG_HDR + 0x27), /* _H2ASN_MsgChoice LRRC_LPHY_ERROR_LOG_INFO_IND_STRU */
    /* sunyanjie end */

    ID_LRRC_LPHY_DPDT_CMD_IND                     = (LPHY_ERRC_MSG_HDR + 0x28),

    ID_LRRC_LPHY_NV_WRITE_IND                     = (LPHY_ERRC_MSG_HDR + 0x29),

    ID_LRRC_LPHY_NORF_INFO_IND                    = (LPHY_ERRC_MSG_HDR + 0x2A),   /* _H2ASN_MsgChoice LRRC_LPHY_NORF_INFO_IND  */

    ID_LRRC_LPHY_STAG_CONFIG_CNF                  = (LPHY_ERRC_MSG_HDR + 0x2b), /* _H2ASN_MsgChoice LRRC_LPHY_STAG_CONFIG_CNF_STRU */
    /*begin: hifi sync switch */
    ID_LRRC_LPHY_VOICE_SYNC_IND                  = (LPHY_ERRC_MSG_HDR + 0x2d),   /* _H2ASN_MsgChoice LRRC_LPHY_VOICE_SYNC_IND_STRU */
    /*end: hifi sync switch */
    ID_LRRC_LPHY_FREQ_RSSI_SCAN_IND              = (LPHY_ERMM_MSG_HDR + 0x2e),    /* _H2ASN_MsgChoice LRRC_LPHY_FREQ_RSSI_SCAN_IND_STRU */
    ID_LRRC_LPHY_MBMS_ENABLE_CNF                  = (LPHY_ERRC_MSG_HDR + 0x2c), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_ENABLE_CNF_STRU */
    ID_LRRC_LPHY_MBMS_DISABLE_CNF                 = (LPHY_ERRC_MSG_HDR + 0x2f), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_DISABLE_CNF_STRU */
    ID_LRRC_LPHY_MBMS_PMCH_ACTIVE_CNF             = (LPHY_ERRC_MSG_HDR + 0x30), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_PMCH_ACTIVE_CNF_STRU */
    ID_LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_CNF       = (LPHY_ERRC_MSG_HDR + 0x31), /* _H2ASN_MsgChoice LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_CNF_STRU */
    ID_LRRC_LPHY_CONNECTED_TO_IDLE_CNF            = (LPHY_ERRC_MSG_HDR + 0x32), /* _H2ASN_MsgChoice LRRC_LPHY_CONNECTED_TO_IDLE_CNF_STRU */
#if (FEATURE_ON == FEATURE_LTE_R13)
    ID_LRRC_LPHY_SCG_DRX_CONFIG_IN_CONNECTED_CNF  = (LPHY_ERRC_MSG_HDR + 0x33), /* _H2ASN_MsgChoice LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_CNF_STRU */
    ID_LRRC_LPHY_MBSFN_LOG_CNF                    = (LPHY_ERRC_MSG_HDR + 0x34), /* _H2ASN_MsgChoice LRRC_LPHY_MBSFN_LOG_CNF_STRU */
    ID_LRRC_LPHY_MBSFN_LOG_ENERGY_IND             = (LPHY_ERRC_MSG_HDR + 0x35), /* _H2ASN_MsgChoice LRRC_LPHY_MBSFN_LOG_ENERGY_IND_STRU */
    ID_LRRC_LPHY_MBSFN_LOG_BLER_IND               = (LPHY_ERRC_MSG_HDR + 0x36), /* _H2ASN_MsgChoice LRRC_LPHY_MBSFN_LOG_BLER_IND_STRU */
    ID_LRRC_LPHY_SCELL_RL_RELEASE_CNF             = (LPHY_ERRC_MSG_HDR + 0x05), /* _H2ASN_MsgChoice LRRC_LPHY_SCELL_RL_RELEASE_CNF_STRU */

    ID_LRRC_LPHY_DS_MEAS_INTRA_CNF                = (LPHY_ERMM_MSG_HDR + 0x01), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_INTRA_CNF_STRU */
    ID_LRRC_LPHY_DS_MEAS_INTRA_IND                = (LPHY_ERMM_MSG_HDR + 0x02), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_INTRA_IND_STRU */
    ID_LRRC_LPHY_DS_MEAS_INTER_CNF                = (LPHY_ERMM_MSG_HDR + 0x03), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_INTER_CNF_STRU */
    ID_LRRC_LPHY_DS_MEAS_INTER_IND                = (LPHY_ERMM_MSG_HDR + 0x04), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_INTER_IND_STRU */
    ID_LRRC_LPHY_DS_MEAS_SECOND_FREQ_CNF          = (LPHY_ERMM_MSG_HDR + 0x09), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_SECOND_FREQ_CNF_STRU */
    ID_LRRC_LPHY_DS_MEAS_SECOND_FREQ_IND          = (LPHY_ERMM_MSG_HDR + 0x0a), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_SECOND_FREQ_IND_STRU */
    ID_LRRC_LPHY_DS_MEAS_MCG_PCELL_IND            = (LPHY_ERMM_MSG_HDR + 0x0b), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_MCG_PCELL_IND_STRU */
    ID_LRRC_LPHY_DS_MEAS_SCG_PSCELL_IND           = (LPHY_ERMM_MSG_HDR + 0x0c), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_SCG_PSCELL_IND_STRU */
    ID_LRRC_LPHY_DS_MEAS_SCG_PSCELL_INTRA_IND     = (LPHY_ERMM_MSG_HDR + 0x0d), /* _H2ASN_MsgChoice LRRC_LPHY_DS_MEAS_SCG_PSCELL_INTRA_IND_STRU */
    ID_LRRC_LPHY_MEAS_LAA_RSSI_IND                = (LPHY_ERMM_MSG_HDR + 0x0f), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_LAA_RSSI_IND_STRU */
    ID_LRRC_LPHY_MEAS_SSTD_IND                    = (LPHY_ERMM_MSG_HDR + 0x10), /* _H2ASN_MsgChoice LRRC_LPHY_MEAS_SSTD_IND_STRU */
    ID_LRRC_LPHY_COMM_MEAS_CONFIG_CNF             = (LPHY_ERMM_MSG_HDR + 0x14), /* _H2ASN_MsgChoice LRRC_LPHY_COMM_MEAS_CONFIG_CNF_STRU */
    /* ˫LTE����˫���л����ԣ�begin */
    ID_LRRC_LPHY_MODEM_START_STATE_INFO_CNF       = (LPHY_ERRC_MSG_HDR + 0x37), /* _H2ASN_MsgChoice LRRC_LPHY_MODEM_START_STATE_INFO_CNF_STRU */
    /* ˫LTE����˫���л����ԣ�end */
#endif
    ID_LRRC_LPHY_BUTT =  (LPHY_ERMM_MSG_HDR + 0x40)                             /*��Ϣ�ṹֻ�ܵ� 0x40*/

};
typedef VOS_UINT32    LRRC_LPHY_MSG_ID_ENUM_UINT32;


/*****************************************************************************
 ö����    : LRRC_LPHY_CELL_SEARCH_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : Э��ջָʾ�����С����������
*****************************************************************************/
enum LRRC_LPHY_CELL_SEARCH_TYPE_ENUM
{
    LRRC_LPHY_CELL_SEARCH_FREQ            = 0,                /* Ƶ����ϢС������������*/
    LRRC_LPHY_CELL_SEARCH_CANDIDATE,                          /* ������Ϣ(Ƶ��+С��ID)С������ */
    LRRC_LPHY_CELL_SEARCH_FREQ_BAND,                          /* Ƶ������ */
    LRRC_LPHY_CELL_SEARCH_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CELL_SEARCH_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SEARCH_CELL_RESULT_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : С���������
*****************************************************************************/
enum LRRC_LPHY_SEARCH_CELL_RESULT_ENUM
{
    LRRC_LPHY_SEARCH_CELL_INVALID         = 0,                /* С�����������Ч */
    LRRC_LPHY_SEARCH_CELL_VALID ,                             /* С�����������Ч */
    LRRC_LPHY_SEARCH_CELL_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SEARCH_CELL_RESULT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_ANTANNA_PORT_ENUM
 Э����  : MobilityControlInformation->RadioResourceConfigCommon->AntennaInformationCommon
 ASN.1���� :
 ö��˵��  : ���߶˿���
*****************************************************************************/
enum LRRC_LPHY_ANTANNA_PORT_ENUM
{
    LRRC_LPHY_ANTANNA_PORT_1              = 0,                /* ���߶˿�Ϊ1 */
    LRRC_LPHY_ANTANNA_PORT_2,                                 /* ���߶˿�Ϊ2 */
    LRRC_LPHY_ANTANNA_PORT_4,                                 /* ���߶˿�Ϊ4 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_ANTANNA_PORT_8,                                 /* ���߶˿�Ϊ8 */
#endif
    LRRC_LPHY_ANTANNA_PORT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_ANTANNA_PORT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CSI_ANTANNA_PORT_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : CSI���߶˿���
*****************************************************************************/
enum LRRC_LPHY_CSI_ANTANNA_PORT_ENUM
{
    LRRC_LPHY_CSI_ANTANNA_PORT_1              = 0,                /* ���߶˿�Ϊ1 */
    LRRC_LPHY_CSI_ANTANNA_PORT_2,                                 /* ���߶˿�Ϊ2 */
    LRRC_LPHY_CSI_ANTANNA_PORT_4,                                 /* ���߶˿�Ϊ4 */
    LRRC_LPHY_CSI_ANTANNA_PORT_8,                                 /* ���߶˿�Ϊ8 */
    LRRC_LPHY_CSI_ANTANNA_PORT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CSI_ANTANNA_PORT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SRS_ANTANNA_PORT_ENUM
 Э����  : SRS-AntennaPort
 ASN.1���� :
 ö��˵��  : SRS���߶˿���
*****************************************************************************/
enum LRRC_LPHY_SRS_ANTANNA_PORT_ENUM
{
    LRRC_LPHY_SRS_ANTANNA_PORT_1              = 0,                /* ���߶˿�Ϊ1 */
    LRRC_LPHY_SRS_ANTANNA_PORT_2,                                 /* ���߶˿�Ϊ2 */
    LRRC_LPHY_SRS_ANTANNA_PORT_4,                                 /* ���߶˿�Ϊ4 */
    LRRC_LPHY_SRS_ANTANNA_PORT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SRS_ANTANNA_PORT_ENUM_UINT16;


/*****************************************************************************
 ö����    : LRRC_LPHY_BAND_WIDTH_ENUM
 Э����  : MasterInformationBlock->dl-Bandwidth
 ASN.1���� :
 ö��˵��  : ����ö��(��������ϵͳ������������)
*****************************************************************************/
enum LRRC_LPHY_BAND_WIDTH_ENUM
{
    LRRC_LPHY_BAND_WIDTH_6RB              = 0,                /* ����Ϊ6RB */
    LRRC_LPHY_BAND_WIDTH_15RB,                                /* ����Ϊ15RB */
    LRRC_LPHY_BAND_WIDTH_25RB,                                /* ����Ϊ25RB */
    LRRC_LPHY_BAND_WIDTH_50RB,                                /* ����Ϊ50RB */
    LRRC_LPHY_BAND_WIDTH_75RB,                                /* ����Ϊ75RB */
    LRRC_LPHY_BAND_WIDTH_100RB,                               /* ����Ϊ100RB */
    LRRC_LPHY_BAND_WIDTH_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_BAND_WIDTH_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SUBFRAME_ASSIGNMENT_ENUM
 Э����  : TDD-Configuration->subframeAssignment
 ASN.1���� :
 ö��˵��  : subframeAssignment
*****************************************************************************/
enum LRRC_LPHY_SUBFRAME_ASSIGNMENT_ENUM
{
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_0       = 0,                /* subframeAssignment-sa0 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_1,                          /* subframeAssignment-sa1 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_2,                          /* subframeAssignment-sa2 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_3,                          /* subframeAssignment-sa3 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_4,                          /* subframeAssignment-sa4 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_5,                          /* subframeAssignment-sa5 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_6,                          /* subframeAssignment-sa6 */
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_SUBFRAME_ASSIGNMENT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_ENUM
 Э����  : TDD-Configuration->specialSubframePatterns
 ASN.1���� :
 ö��˵��  : specialSubframePatterns
*****************************************************************************/
enum LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_ENUM
{
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_0  = 0,                /* specialSubframePatterns-ssp0 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_1,                     /* specialSubframePatterns-ssp1 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_2,                     /* specialSubframePatterns-ssp2 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_3,                     /* specialSubframePatterns-ssp3 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_4,                     /* specialSubframePatterns-ssp4 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_5,                     /* specialSubframePatterns-ssp5 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_6,                     /* specialSubframePatterns-ssp6 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_7,                     /* specialSubframePatterns-ssp7 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_8,                     /* specialSubframePatterns-ssp8 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_9,                     /* specialSubframePatterns-ssp9 */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_RESULT_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : �����ԭ�����������ݽṹ
*****************************************************************************/
enum LRRC_LPHY_RESULT_ENUM
{
    LRRC_LPHY_RESULT_SUCC                 = 0,                /* �����ɹ� */
    LRRC_LPHY_RESULT_FAIL ,                                   /* ����ʧ�� */
    LRRC_LPHY_RESULT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_RESULT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CHANNEL_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : �����ŵ�������
*****************************************************************************/
enum LRRC_LPHY_CHANNEL_TYPE_ENUM
{
    LRRC_LPHY_CHANNEL_PBCH                = 0,                /* �㲥�ŵ� */
    LRRC_LPHY_CHANNEL_PDSCH_BCH,                              /* ��㲥�����й����ŵ� */
    LRRC_LPHY_CHANNEL_PDSCH_PCH,                              /* ��Ѱ�������й����ŵ� */
    LRRC_LPHY_CHANNEL_PDSCH_RACH,                             /* �����������Ӧ�����й����ŵ�*/
    LRRC_LPHY_CHANNEL_PDSCH_DSCH,                             /* �����ݵ����й����ŵ� */
    LRRC_LPHY_CHANNEL_PUCCH,                                  /* ���п����ŵ� */
    LRRC_LPHY_CHANNEL_PUSCH,                                  /* ���й����ŵ� */
    LRRC_LPHY_CHANNEL_PRACH,                                  /* ��������ŵ� */
    LRRC_LPHY_CHANNEL_PDSCH_SCELL,                            /* SCELL���й����ŵ� */
    LRRC_LPHY_CHANNEL_PUSCH_SCELL,                            /* SCELL���й����ŵ� */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_CHANNEL_PRACH_SCELL,                            /* SCELL��������ŵ� */

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CHANNEL_PUCCH_SCELL,                             /* SCELL���п����ŵ� */
    LRRC_LPHY_CHANNEL_PDSCH_PSCELL,                            /* PSCELL��������ŵ� */
    LRRC_LPHY_CHANNEL_PUSCH_PSCELL,                            /* PSCELL��������ŵ� */
    LRRC_LPHY_CHANNEL_PRACH_PSCELL,                            /* PSCELL��������ŵ� */
    LRRC_LPHY_CHANNEL_PUCCH_PSCELL,
#endif

#endif
    LRRC_LPHY_CHANNEL_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16;


/*****************************************************************************
 ö����    : LRRC_LPHY_CQI_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : CQI���õ�����
*****************************************************************************/
enum LRRC_LPHY_CQI_TYPE_ENUM
{
    LRRC_LPHY_CQI_PCELL                  = 0,                /* PCELL��CQI���� */
    LRRC_LPHY_CQI_SCELL,                                     /* SCELL��CQI���� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CQI_SCG_PSCELL,                                /* SCG��PSCELL��CQI���� */
    LRRC_LPHY_CQI_SCG_SCELL,                                 /* SCG��SCELL��CQI���� */
#endif
    LRRC_LPHY_CQI_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CQI_TYPE_ENUM_UINT16;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 ö����    : LRRC_LPHY_SRS_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : SRS���õ�����
*****************************************************************************/
enum LRRC_LPHY_SRS_TYPE_ENUM
{
    LRRC_LPHY_SRS_PCELL                  = 0,                /* PCELL��SRS���� */
    LRRC_LPHY_SRS_SCELL,                                     /* SCELL��SRS���� */
    LRRC_LPHY_SRS_PSCELL,                                    /* PSCELL��SRS���� */
    LRRC_LPHY_SRS_SCG_SCELL,                                 /* SCG SCELL��SRS����, ����LRRC_LPHY_SRS_SCELL��MCG��SCELL */
    LRRC_LPHY_SRS_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SRS_TYPE_ENUM_UINT16;
#endif

/*****************************************************************************
 ö����    : LRRC_LPHY_MBSFN_SF_CFG_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : MBSFN��֡���õ�����
*****************************************************************************/
enum LRRC_LPHY_MBSFN_SF_CFG_TYPE_ENUM
{
    LRRC_LPHY_MBSFN_SF_CFG_PCELL          = 0,                /* PCELL��MBSFN��֡���� */
    LRRC_LPHY_MBSFN_SF_CFG_SCELL,                             /* SCELL��MBSFN��֡���� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_MBSFN_SF_CFG_PSCELL,                            /* PSCELL��MBSFN��֡���� */
#endif
    LRRC_LPHY_MBSFN_SF_CFG_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_MBSFN_SF_CFG_TYPE_ENUM_UINT16;


/*****************************************************************************
 ö����    : LRRC_LPHY_PDSCH_SETUP_FLAG_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : �Ƿ�Ҫ����PDSCH�����ŵ��ı�־
*****************************************************************************/
enum LRRC_LPHY_PDSCH_SETUP_FLAG_ENUM
{
    LRRC_LPHY_PDSCH_SETUP                = 0,                /* ��������PDSCH�ŵ� */
    LRRC_LPHY_PDSCH_NOTSETUP,                            /* ����������PDSCH�ŵ� */
    LRRC_LPHY_PDSCH_BUTT
};
typedef VOS_INT16    LRRC_LPHY_PDSCH_SETUP_FLAG_ENUM_INT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PDSCH_TM_MODE_ENUM
 Э����  : RadioResourceConfigDedicated->PhysicalConfigDedicated->
             AntennaInformationDedicated->transmissionMode
 ASN.1���� :
 ö��˵��  : PDSCH�ŵ�����ģʽ����
*****************************************************************************/
enum LRRC_LPHY_PDSCH_TM_MODE_ENUM
{
    LRRC_LPHY_PDSCH_TM1                   = 0,                /* ��ӦΪ����ģʽ1 */
    LRRC_LPHY_PDSCH_TM2,                                      /* ��ӦΪ����ģʽ2 */
    LRRC_LPHY_PDSCH_TM3,                                      /* ��ӦΪ����ģʽ3 */
    LRRC_LPHY_PDSCH_TM4,                                      /* ��ӦΪ����ģʽ4 */
    LRRC_LPHY_PDSCH_TM5,                                      /* ��ӦΪ����ģʽ5 */
    LRRC_LPHY_PDSCH_TM6,                                      /* ��ӦΪ����ģʽ6 */
    LRRC_LPHY_PDSCH_TM7,                                      /* ��ӦΪ����ģʽ7 */
    LRRC_LPHY_PDSCH_TM8,                                      /* ��ӦΪ����ģʽ8 */
    LRRC_LPHY_PDSCH_TM9,                                      /* ��ӦΪ����ģʽ9 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_PDSCH_TM10,                                     /* ��ӦΪ����ģʽ10 */
#endif
    LRRC_LPHY_PDSCH_TM_MODE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PDSCH_TM_MODE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CODE_BOOK_TYPE_ENUM
 Э����  : RadioResourceConfigDedicated->PhysicalConfigDedicated->
             AntennaInformationDedicated->codebookSubsetRestriction
 ASN.1���� :
 ö��˵��  : codebookSubsetRestriction
*****************************************************************************/
enum LRRC_LPHY_CODE_BOOK_TYPE_ENUM
{
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM3        = 0,                /* n2TxAntenna-tm3 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM3,                           /* n4TxAntenna-tm3 */
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM4,                           /* n2TxAntenna-tm4 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM4,                           /* n4TxAntenna-tm4 */
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM5,                           /* n2TxAntenna-tm5 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM5,                           /* n4TxAntenna-tm5 */
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM6,                           /* n2TxAntenna-tm6 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM6,                           /* n4TxAntenna-tm6 */
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM8,                           /* n2TxAntenna-tm8 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM8,                           /* n4TxAntenna-tm8 */
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM9,                           /* n2TxAntenna-tm9 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM9,                           /* n4TxAntenna-tm9 */
    LRRC_LPHY_CODE_BOOK_TYPE_N8TM9,                           /* n8TxAntenna-tm9 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_CODE_BOOK_TYPE_N2TM10,                          /* n2TxAntenna-tm10 */
    LRRC_LPHY_CODE_BOOK_TYPE_N4TM10,                          /* n4TxAntenna-tm10 */
    LRRC_LPHY_CODE_BOOK_TYPE_N8TM10,                          /* n8TxAntenna-tm10 */
#endif
    LRRC_LPHY_CODE_BOOK_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CODE_BOOK_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_ANTENNA_SELECT_ENUM
 Э����  : RadioResourceConfigDedicated->PhysicalConfigDedicated->
             AntennaInformationDedicated->ue-TransmitAntennaSelection
 ASN.1���� :
 ö��˵��  : ��������ѡ��
*****************************************************************************/
enum LRRC_LPHY_ANTENNA_SELECT_ENUM
{
    LRRC_LPHY_ANTENNA_SELECT_ENABLE_CLOSEDLOOP      = 0,      /* UEѡ��������ΪCLOSELOOP */
    LRRC_LPHY_ANTENNA_SELECT_ENABLE_OPENLOOP,                 /* UEѡ��������ΪOPENLOOP */
    LRRC_LPHY_ANTENNA_SELECT_DISABLE,                         /* UE����ѡ�������� */
    LRRC_LPHY_ANTENNA_SELECT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_ANTENNA_SELECT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PDSCH_PA_ENUM
 Э����  : PDSCH-Configuration->PDSCH-ConfigDedicated->p-a
 ASN.1���� :
 ö��˵��  : PA����ö��
*****************************************************************************/
enum LRRC_LPHY_PDSCH_PA_ENUM
{
    LRRC_LPHY_PDSCH_PA_NEGATIVE_6         = 0,                /* PAΪ-6dB */
    LRRC_LPHY_PDSCH_PA_NEGATIVE_4DOT77,                       /* PAΪ-4.77dB */
    LRRC_LPHY_PDSCH_PA_NEGATIVE_3,                            /* PAΪ-3dB */
    LRRC_LPHY_PDSCH_PA_NEGATIVE_1DOT77,                       /* PAΪ-1.77dB */
    LRRC_LPHY_PDSCH_PA_0,                                     /* PAΪ0dB */
    LRRC_LPHY_PDSCH_PA_1,                                     /* PAΪ1dB */
    LRRC_LPHY_PDSCH_PA_2,                                     /* PAΪ2dB */
    LRRC_LPHY_PDSCH_PA_3,                                     /* PAΪ3dB */
    LRRC_LPHY_PDSCH_PA_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PDSCH_PA_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PDSCH_PB_ENUM
 Э����  : PDSCH-Configuration->PDSCH-ConfigCommon->p-b
 ASN.1���� :
 ö��˵��  : PB����ö��
*****************************************************************************/
enum LRRC_LPHY_PDSCH_PB_ENUM
{
    LRRC_LPHY_PDSCH_PB_0         = 0,                         /* PBΪ0 */
    LRRC_LPHY_PDSCH_PB_1,                                     /* PAΪ1 */
    LRRC_LPHY_PDSCH_PB_2,                                     /* PAΪ2 */
    LRRC_LPHY_PDSCH_PB_3,                                     /* PAΪ3 */
    LRRC_LPHY_PDSCH_PB_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PDSCH_PB_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PARA_VALID_FLAG_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����ָʾר�ò����Ƿ���Ч
*****************************************************************************/
enum LRRC_LPHY_PARA_VALID_FLAG_ENUM
{
    LRRC_LPHY_PARA_INVALID                = 0,                /* ������Ч */
    LRRC_LPHY_PARA_VALID ,                                    /* ������Ч */
    LRRC_LPHY_PARA_FLG_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DELTA_PUCCH_SHITF_ENUM
 Э����  : PUCCH-ConfigCommon->deltaPUCCH-Shift
 ASN.1���� :
 ö��˵��  : deltaPUCCH-Shift
*****************************************************************************/
enum LRRC_LPHY_DELTA_PUCCH_SHITF_ENUM
{
    LRRC_LPHY_DELTA_PUCCH_SHITF_1         = 1,                /* deltaPUCCH-ShiftΪ1 */
    LRRC_LPHY_DELTA_PUCCH_SHITF_2 ,                           /* deltaPUCCH-ShiftΪ2 */
    LRRC_LPHY_DELTA_PUCCH_SHITF_3 ,                           /* deltaPUCCH-ShiftΪ3 */
    LRRC_LPHY_DELTA_PUCCH_SHITF_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_DELTA_PUCCH_SHITF_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_REPETITION_FACTOR_ENUM
 Э����  : PUCCH-ConfigDedicated->ackNackRepetition
 ASN.1���� :
 ö��˵��  : ackNackRepetition
*****************************************************************************/
enum LRRC_LPHY_REPETITION_FACTOR_ENUM
{
    LRRC_LPHY_REPETITION_FACTOR_ENABLE_N2  = 0,                /* ackNackRepetitionΪN2 */
    LRRC_LPHY_REPETITION_FACTOR_ENABLE_N4 ,                    /* ackNackRepetitionΪN4 */
    LRRC_LPHY_REPETITION_FACTOR_ENABLE_N6 ,                    /* ackNackRepetitionΪN6 */
    LRRC_LPHY_REPETITION_FACTOR_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_REPETITION_FACTOR_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_TDD_FEEDBACK_MODE_ENUM
 Э����  : PUCCH-ConfigDedicated->tddAckNackFeedbackMode
 ASN.1���� :
 ö��˵��  : tddAckNackFeedbackMode
*****************************************************************************/
enum LRRC_LPHY_TDD_FEEDBACK_MODE_ENUM
{
    LRRC_LPHY_TDD_FEEDBACK_MODE_BUNDLING  = 0,                /* tddAckNackFeedbackModeΪbundling */
    LRRC_LPHY_TDD_FEEDBACK_MODE_MULTIPLEXING ,                /* tddAckNackFeedbackModeΪmultiplexing */
    LRRC_LPHY_TDD_FEEDBACK_MODE_INVALID,                      /* tddAckNackFeedbackModeΪ��Ч */
    LRRC_LPHY_TDD_FEEDBACK_MODE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_TDD_FEEDBACK_MODE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DSR_TRANS_MAX_ENUM
 Э����  : PhysicalConfigDedicated->SchedulingRequest-Configuration->dsr-TransMax
 ASN.1���� :
 ö��˵��  : dsr-TransMax
*****************************************************************************/
enum LRRC_LPHY_DSR_TRANS_MAX_ENUM
{
    LRRC_LPHY_DSR_TRANS_MAX_N4            = 0,                /* deltaPUCCH-ShiftΪN4 */
    LRRC_LPHY_DSR_TRANS_MAX_N8 ,                              /* deltaPUCCH-ShiftΪN8 */
    LRRC_LPHY_DSR_TRANS_MAX_N16 ,                             /* deltaPUCCH-ShiftΪN16 */
    LRRC_LPHY_DSR_TRANS_MAX_N32 ,                             /* deltaPUCCH-ShiftΪN32 */
    LRRC_LPHY_DSR_TRANS_MAX_N64 ,                             /* deltaPUCCH-ShiftΪN64 */
    LRRC_LPHY_DSR_TRANS_MAX_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_DSR_TRANS_MAX_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PUSCH_HOPPING_MODE_ENUM
 Э����  : PUSCH-Configuration->PUSCH-ConfigCommon->n-SB
 ASN.1���� :
 ö��˵��  : PUSCH Hoppingģʽ
*****************************************************************************/
enum LRRC_LPHY_PUSCH_HOPPING_MODE_ENUM
{
    LRRC_LPHY_PUSCH_HOPPING_MODE_INTER_SUBFRAME               = 0, /* interSubFrame */
    LRRC_LPHY_PUSCH_HOPPING_MODE_INTER_INTRA_SUBFRAME,             /* intraAndInterSubFrame */
    LRRC_LPHY_PUSCH_HOPPING_MODE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PUSCH_HOPPING_MODE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PUSCH_HOPPING_MODE_ENUM
 Э����  : PUSCH-Configuration->PUSCH-ConfigCommon->hoppingMode
 ASN.1���� :
 ö��˵��  : PUSCH N SB
*****************************************************************************/
enum LRRC_LPHY_PUSCH_N_SB_ENUM
{
    LRRC_LPHY_PUSCH_N_SB_1                = 0,                /* N SBΪNSB1 */
    LRRC_LPHY_PUSCH_N_SB_2,                                   /* N SBΪNSB2 */
    LRRC_LPHY_PUSCH_N_SB_3,                                   /* N SBΪNSB3 */
    LRRC_LPHY_PUSCH_N_SB_4,                                   /* N SBΪNSB4 */
    LRRC_LPHY_PUSCH_N_SB_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PUSCH_N_SB_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM
 Э����  : PUSCH-Configuration->PUSCH-ConfigCommon->hoppingMode
 ASN.1���� :
 ö��˵��  : PUSCH N SB
*****************************************************************************/
enum LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM
{
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_NORMAL = 0,                /* Normal */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_EXTEND,                    /* Extended */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PARA_ENABLE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����ʹ�ܱ�ʶ
*****************************************************************************/
enum LRRC_LPHY_PARA_ENABLE_ENUM
{
    LRRC_LPHY_PARA_DISABLE                = 0,                /* ��ʹ�� */
    LRRC_LPHY_PARA_ENABLE,                                    /* ʹ�� */
    LRRC_LPHY_PARA_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_MAX_HARQ_TX_ENUM
 Э����  : ul-SCH-Config->maxHARQ-Tx
 ASN.1���� :
 ö��˵��  : maxHARQ-Tx
*****************************************************************************/
enum LRRC_LPHY_MAX_HARQ_TX_ENUM
{
    LRRC_LPHY_N1_MAX_HARQ_TX           = 0,              /* 1 */
    LRRC_LPHY_N2_MAX_HARQ_TX,                            /* 2 */
    LRRC_LPHY_N3_MAX_HARQ_TX,                            /* 3 */
    LRRC_LPHY_N4_MAX_HARQ_TX,                            /* 4 */
    LRRC_LPHY_N5_MAX_HARQ_TX,                            /* 5 */
    LRRC_LPHY_N6_MAX_HARQ_TX,                            /* 6 */
    LRRC_LPHY_N7_MAX_HARQ_TX,                            /* 7 */
    LRRC_LPHY_N8_MAX_HARQ_TX,                            /* 8 */
    LRRC_LPHY_N10_MAX_HARQ_TX,                           /* 10 */
    LRRC_LPHY_N12_MAX_HARQ_TX,                           /* 12 */
    LRRC_LPHY_N16_MAX_HARQ_TX,                           /* 16 */
    LRRC_LPHY_N20_MAX_HARQ_TX,                           /* 20 */
    LRRC_LPHY_N24_MAX_HARQ_TX,                           /* 24 */
    LRRC_LPHY_N28_MAX_HARQ_TX,                           /* 28 */
    LRRC_LPHY_MAX_HARQ_TX_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_MAX_HARQ_TX_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PWR_CTRL_ALPHA_ENUM
 Э����  : RadioResourceConfigCommonSIB->UplinkPowerControlCommon->alpha
             RadioResourceConfigCommon->UplinkPowerControlCommon->alpha
 ASN.1���� :
 ö��˵��  : alpha
*****************************************************************************/
enum LRRC_LPHY_PWR_CTRL_ALPHA_ENUM
{
    LRRC_LPHY_PWR_CTRL_ALPHA_0            = 0,                /* 0 */
    LRRC_LPHY_PWR_CTRL_ALPHA_0DOT4,                           /* 0.4 */
    LRRC_LPHY_PWR_CTRL_ALPHA_0DOT5,                           /* 0.5 */
    LRRC_LPHY_PWR_CTRL_ALPHA_0DOT6,                           /* 0.6 */
    LRRC_LPHY_PWR_CTRL_ALPHA_0DOT7,                           /* 0.7 */
    LRRC_LPHY_PWR_CTRL_ALPHA_0DOT8,                           /* 0.8 */
    LRRC_LPHY_PWR_CTRL_ALPHA_0DOT9,                           /* 0.9 */
    LRRC_LPHY_PWR_CTRL_ALPHA_1,                               /* 1 */
    LRRC_LPHY_PWR_CTRL_ALPHA_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PWR_CTRL_ALPHA_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DELTAF_FORMAT_ENUM
 Э����  : RadioResourceConfigCommonSIB->UplinkPowerControlCommon->DeltaFList-PUCCH
             RadioResourceConfigCommon->UplinkPowerControlCommon->DeltaFList-PUCCH
 ASN.1���� :
 ö��˵��  : alpha
*****************************************************************************/
enum LRRC_LPHY_DELTAF_FORMAT_ENUM
{
    LRRC_LPHY_DELTAF_FORMAT_NEGATIVE_2    = 0,                /* -2 */
    LRRC_LPHY_DELTAF_FORMAT_0,                                /* 0 */
    LRRC_LPHY_DELTAF_FORMAT_1,                                /* 1 */
    LRRC_LPHY_DELTAF_FORMAT_2,                                /* 2 */
    LRRC_LPHY_DELTAF_FORMAT_3,                                /* 3 */
    LRRC_LPHY_DELTAF_FORMAT_5,                                /* 5 */
    LRRC_LPHY_DELTAF_FORMAT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_DELTAF_FORMAT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_FILTER_COEFF_ENUM
 Э����  : PhysicalConfigDedicated->uplinkPowerControlDedicated->filterCoefficient
 ASN.1���� :
 ö��˵��  : FilterCoefficient
*****************************************************************************/
enum LRRC_LPHY_FILTER_COEFF_ENUM
{
    LRRC_LPHY_FC0_FILTER_COEFF          = 0,      /* k = 0 */
    LRRC_LPHY_FC1_FILTER_COEFF,                   /* k = 1 */
    LRRC_LPHY_FC2_FILTER_COEFF,                   /* k = 2 */
    LRRC_LPHY_FC3_FILTER_COEFF,                   /* k = 3 */
    LRRC_LPHY_FC4_FILTER_COEFF,                   /* k = 4 */
    LRRC_LPHY_FC5_FILTER_COEFF,                   /* k = 5 */
    LRRC_LPHY_FC6_FILTER_COEFF,                   /* k = 6 */
    LRRC_LPHY_FC7_FILTER_COEFF,                   /* k = 7 */
    LRRC_LPHY_FC8_FILTER_COEFF,                   /* k = 8 */
    LRRC_LPHY_FC9_FILTER_COEFF,                   /* k = 9 */
    LRRC_LPHY_FC11_FILTER_COEFF,                  /* k = 11 */
    LRRC_LPHY_FC13_FILTER_COEFF,                  /* k = 13 */
    LRRC_LPHY_FC15_FILTER_COEFF,                  /* k = 15 */
    LRRC_LPHY_FC17_FILTER_COEFF,                  /* k = 17 */
    LRRC_LPHY_FC19_FILTER_COEFF,                  /* k = 19 */
    LRRC_LPHY_FILTER_COEFF_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_FILTER_COEFF_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_INDEX_FORMAT_TYPE_ENUM
 Э����  : PhysicalConfigDedicated->TPC-PDCCH-Configuration->TPC-Index
 ASN.1���� :
 ö��˵��  : TPC-Index
*****************************************************************************/
enum LRRC_LPHY_INDEX_FORMAT_TYPE_ENUM
{
    LRRC_LPHY_INDEX_FORMAT_TYPE_3         = 0,                /* indexOfFormat3 */
    LRRC_LPHY_INDEX_FORMAT_TYPE_3A,                           /* indexOfFormat3A */
    LRRC_LPHY_INDEX_FORMAT_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_INDEX_FORMAT_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PERSIST_SCHED_INTERVAL_ENUM
 Э����  : RadioResourceConfigDedicated->SPS-Configuration
 ASN.1���� :
 ö��˵��  : SPS-Configuration->semiPersistSchedIntervalDL/semiPersistSchedIntervalUL
*****************************************************************************/
enum LRRC_LPHY_PERSIST_SCHED_INTERVAL_ENUM
{
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_10         = 0,          /* 10 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_20,                      /* 20 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_32,                      /* 32 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_40,                      /* 40 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_64,                      /* 64 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_80,                      /* 80 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_128,                     /* 128 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_160,                     /* 160 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_320,                     /* 320 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_640,                     /* 640 */
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PERSIST_SCHED_INTERVAL_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_IMPLICIT_REL_AFTER_ENUM
 Э����  : RadioResourceConfigDedicated->SPS-Configuration->semiPersistSchedIntervalUL
 ASN.1���� :
 ö��˵��  : implicitReleaseAfter
*****************************************************************************/
enum LRRC_LPHY_IMPLICIT_REL_AFTER_ENUM
{
    LRRC_LPHY_IMPLICIT_REL_AFTER_E2       = 0,                /* e2 */
    LRRC_LPHY_IMPLICIT_REL_AFTER_E3,                          /* e3 */
    LRRC_LPHY_IMPLICIT_REL_AFTER_E4,                          /* e4 */
    LRRC_LPHY_IMPLICIT_REL_AFTER_E8,                          /* e8 */
    LRRC_LPHY_IMPLICIT_REL_AFTER_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_IMPLICIT_REL_AFTER_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PHICH_DURATION_ENUM
 Э����  : PHICH-Configuration->phich-Duration
 ASN.1���� :
 ö��˵��  : phich-Duration
*****************************************************************************/
enum LRRC_LPHY_PHICH_DURATION_ENUM
{
    LRRC_LPHY_PHICH_DURATION_NORMAL       = 0,                  /* Normal */
    LRRC_LPHY_PHICH_DURATION_EXTENDED,                          /* extended */
    LRRC_LPHY_PHICH_DURATION_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PHICH_DURATION_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PHICH_RESOURCE_ENUM
 Э����  : PHICH-Configuration->phich-Resource
 ASN.1���� :
 ö��˵��  : phich-Resource
*****************************************************************************/
enum LRRC_LPHY_PHICH_RESOURCE_ENUM
{
    LRRC_LPHY_PHICH_RESOURCE_ONE_SIXTH    = 0,                /* 1/6 */
    LRRC_LPHY_PHICH_RESOURCE_HALF,                            /* 1/2 */
    LRRC_LPHY_PHICH_RESOURCE_ONE,                             /* 1 */
    LRRC_LPHY_PHICH_RESOURCE_TWO,                             /* 2 */
    LRRC_LPHY_PHICH_RESOURCE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PHICH_RESOURCE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DRX_PAGE_T_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : Ѱ������
*****************************************************************************/
enum LRRC_LPHY_DRX_PAGE_T_ENUM
{
    LRRC_LPHY_DRX_PAGE_32                 =0,
    LRRC_LPHY_DRX_PAGE_64,
    LRRC_LPHY_DRX_PAGE_128,
    LRRC_LPHY_DRX_PAGE_256,
    LRRC_LPHY_DRX_PAGE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DRX_PAGE_T_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DRX_PAGE_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : Ѱ����
*****************************************************************************/
enum LRRC_LPHY_DRX_PAGE_TYPE_ENUM
{
    LRRC_LPHY_DRX_PAGING_GROUP_0          = 0,                                    /* 0����ʾ4��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_1,                                                 /* 1����ʾ2��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_2,                                                 /* 2����ʾ1��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_3,                                                 /* 3����ʾ1/2��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_4,                                                 /* 4����ʾ1/4��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_5,                                                 /* 5����ʾ1/8��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_6,                                                 /* 6����ʾ1/16��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_7,                                                 /* 7����ʾ1/32��DRX���� */
    LRRC_LPHY_DRX_PAGING_GROUP_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_DRX_PAGE_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_MEAS_COMMAND_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ������������
*****************************************************************************/
enum LRRC_LPHY_MEAS_COMMAND_ENUM
{
    LRRC_LPHY_MEAS_COMMAND_REL            = 0,                /* �ͷŲ��� */
    LRRC_LPHY_MEAS_COMMAND_SETUP ,                            /* �������� */
    LRRC_LPHY_MEAS_COMMAND_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_IDLE_MEAS_REPORT_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : IDLE״̬�µ����ϱ�����
*****************************************************************************/
enum LRRC_LPHY_IDLE_MEAS_REPORT_TYPE_ENUM
{
    LRRC_LPHY_IDLE_MEAS_REPORT_SERVE      = 31,               /* IDLE������С���ϱ� */
    LRRC_LPHY_IDLE_MEAS_REPORT_INTRA,                         /* IDLE����ͬƵ��С���ϱ� */
    LRRC_LPHY_IDLE_MEAS_REPORT_INTER,                         /* IDLE������Ƶ��С���ϱ� */
    LRRC_LPHY_IDLE_MEAS_REPORT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_IDLE_MEAS_REPORT_TYPE_ENUM_UNIT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CONN_MEAS_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : Connected״̬�²�����������
*****************************************************************************/
enum LRRC_LPHY_CONN_MEAS_TYPE_ENUM
{
    LRRC_LPHY_CONN_MEAS_TYPE_INTRA        = 41,              /* Connected����ͬƵ������Primary freq��Secondary freqs����С�� */
    LRRC_LPHY_CONN_MEAS_TYPE_INTER,                          /* Connected������Ƶ����ͬ������Serving freqs��Ƶ�㣩��С�� */
    LRRC_LPHY_CONN_MEAS_TYPE_IRAT,                           /* Connected������ϵͳС�� */
    LRRC_LPHY_CONN_MEAS_TYPE_SECOND_FREQ,                    /* Connected������ƵС��(������SCELL��Ƶ��) */
    LRRC_LPHY_CONN_MEAS_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CONN_MEAS_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CONN_MEAS_REPORT_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����״̬�²����ϱ�����
*****************************************************************************/
enum LRRC_LPHY_CONN_MEAS_REPORT_TYPE_ENUM
{
    LRRC_LPHY_CONN_MEAS_REPORT_INTRA     = 51,               /* Connected����ͬƵ��С���ϱ� */
    LRRC_LPHY_CONN_MEAS_REPORT_INTER,                        /* Connected������Ƶ��С���ϱ� */
    LRRC_LPHY_CONN_MEAS_REPORT_SECOND_FREQ,                  /* Connected����Secondary Freqs������С���ϱ�������SCELL������������ */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CONN_MEAS_REPORT_MCG_PCELL,
    LRRC_LPHY_CONN_MEAS_REPORT_SCG_PSCELL,
    LRRC_LPHY_CONN_MEAS_REPORT_SCG_PSCELL_INTRA,
#endif
    LRRC_LPHY_CONN_MEAS_REPORT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CONN_MEAS_REPORT_TYPE_ENUM_UNIT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_MEAS_GAP_TYPE_ENUM
 Э����  : MeasGapConfig->gapActivation->activate->gapPattern
 ASN.1���� :
 ö��˵��  : GAP����
*****************************************************************************/
enum LRRC_LPHY_MEAS_GAP_TYPE_ENUM
{
    LRRC_LPHY_MEAS_GAP_TYPE_1             = 0,                /* gp1 */
    LRRC_LPHY_MEAS_GAP_TYPE_2,                                /* gp2 */
    LRRC_LPHY_MEAS_GAP_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_MEAS_GAP_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CQI_MODEA_PERIODIC_ENUM
 Э����  : PhysicalConfigDedicated->CQI-Reporting->cqi-ReportingModeAperiodic
 ASN.1���� :
 ö��˵��  : cqi-ReportingModeAperiodic
*****************************************************************************/
enum LRRC_LPHY_CQI_MODEA_PERIODIC_ENUM
{
    LRRC_LPHY_CQI_MODEA_PERIODIC_12  = 0,                     /* MODE 1-2 */
    LRRC_LPHY_CQI_MODEA_PERIODIC_20,                          /* MODE 2-0 */
    LRRC_LPHY_CQI_MODEA_PERIODIC_22,                          /* MODE 2-2 */
    LRRC_LPHY_CQI_MODEA_PERIODIC_30,                          /* MODE 3-0 */
    LRRC_LPHY_CQI_MODEA_PERIODIC_31,                          /* MODE 3-1 */
    LRRC_LPHY_CQI_MODEA_PERIODIC_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CQI_MODEA_PERIODIC_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_FORMATE_PERIODIC_ENUM
 Э����  : PhysicalConfigDedicated->CQI-Reporting->CQI-ReportingPeriodic->cqi-FormatIndicatorPeriodic
 ASN.1���� :
 ö��˵��  : cqi-FormatIndicatorPeriodic
*****************************************************************************/
enum LRRC_LPHY_CQI_FORMATE_IND_TYPE_ENUM
{
    LRRC_LPHY_CQI_FORMATE_IND_TYPE_WIDEBAN  = 0,               /* widebandCQI  */
    LRRC_LPHY_CQI_FORMATE_IND_TYPE_SUBBAND,                    /* subbandCQI */
    LRRC_LPHY_CQI_FORMATE_IND_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CQI_FORMATE_IND_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM
 Э����  : SoundingRsUl-ConfigCommon->srsBandwidthConfiguration
 ASN.1���� :
 ö��˵��  : SRS�Ĵ���
*****************************************************************************/
enum LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM
{
    LRRC_LPHY_SRS_BANDWIDTH_0             = 0,
    LRRC_LPHY_SRS_BANDWIDTH_1,
    LRRC_LPHY_SRS_BANDWIDTH_2,
    LRRC_LPHY_SRS_BANDWIDTH_3,
    LRRC_LPHY_SRS_BANDWIDTH_4,
    LRRC_LPHY_SRS_BANDWIDTH_5,
    LRRC_LPHY_SRS_BANDWIDTH_6,
    LRRC_LPHY_SRS_BANDWIDTH_7,
    LRRC_LPHY_SRS_BANDWIDTH_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SRS_SUBFRAME_TYPE_ENUM
 Э����  : SoundingRsUl-ConfigCommon->srsSubframeConfiguration
 ASN.1���� :
 ö��˵��  : srsSubframeConfiguration
*****************************************************************************/
enum LRRC_LPHY_SRS_SUBFRAME_TYPE_ENUM
{
    LRRC_LPHY_SRS_SUB_FRAME_0             = 0,
    LRRC_LPHY_SRS_SUB_FRAME_1,
    LRRC_LPHY_SRS_SUB_FRAME_2,
    LRRC_LPHY_SRS_SUB_FRAME_3,
    LRRC_LPHY_SRS_SUB_FRAME_4,
    LRRC_LPHY_SRS_SUB_FRAME_5,
    LRRC_LPHY_SRS_SUB_FRAME_6,
    LRRC_LPHY_SRS_SUB_FRAME_7,
    LRRC_LPHY_SRS_SUB_FRAME_8,
    LRRC_LPHY_SRS_SUB_FRAME_9,
    LRRC_LPHY_SRS_SUB_FRAME_10,
    LRRC_LPHY_SRS_SUB_FRAME_11,
    LRRC_LPHY_SRS_SUB_FRAME_12,
    LRRC_LPHY_SRS_SUB_FRAME_13,
    LRRC_LPHY_SRS_SUB_FRAME_14,
    LRRC_LPHY_SRS_SUB_FRAME_15,
    LRRC_LPHY_SRS_SUB_FRAME_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SRS_SUBFRAME_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SRS_HOPPING_BANDWIDTH_ENUM
 Э����  : SoundingRsUl-ConfigDedicated->srsHoppingBandwidth
 ASN.1���� :
 ö��˵��  : srsHoppingBandwidth
*****************************************************************************/
enum LRRC_LPHY_SRS_HOPPING_BANDWIDTH_ENUM
{
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_0          = 0,
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_1,
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_2,
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_3,
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CYCLIC_SHIFT_ENUM
 Э����  : SoundingRsUl-ConfigDedicated->cyclicShift
 ASN.1���� :
 ö��˵��  : cyclicShift
*****************************************************************************/
enum LRRC_LPHY_CYCLIC_SHIFT_ENUM
{
    LRRC_LPHY_CYCLIC_SHIFT_0              = 0,
    LRRC_LPHY_CYCLIC_SHIFT_1,
    LRRC_LPHY_CYCLIC_SHIFT_2,
    LRRC_LPHY_CYCLIC_SHIFT_3,
    LRRC_LPHY_CYCLIC_SHIFT_4,
    LRRC_LPHY_CYCLIC_SHIFT_5,
    LRRC_LPHY_CYCLIC_SHIFT_6,
    LRRC_LPHY_CYCLIC_SHIFT_7,
    LRRC_LPHY_CYCLIC_SHIFT_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CYCLIC_SHIFT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DURATION_TIMER_ENUM
 Э����  : MAC-MainConfiguration->drx-Configuration->onDurationTimer
 ASN.1���� :
 ö��˵��  : onDurationTimer
*****************************************************************************/
enum LRRC_LPHY_DURATION_TIMER_ENUM
{
    LRRC_LPHY_DURATION_TIMER_1          = 0,
    LRRC_LPHY_DURATION_TIMER_2,
    LRRC_LPHY_DURATION_TIMER_3,
    LRRC_LPHY_DURATION_TIMER_4,
    LRRC_LPHY_DURATION_TIMER_5,
    LRRC_LPHY_DURATION_TIMER_6,
    LRRC_LPHY_DURATION_TIMER_8,
    LRRC_LPHY_DURATION_TIMER_10,
    LRRC_LPHY_DURATION_TIMER_20,
    LRRC_LPHY_DURATION_TIMER_30,
    LRRC_LPHY_DURATION_TIMER_40,
    LRRC_LPHY_DURATION_TIMER_50,
    LRRC_LPHY_DURATION_TIMER_60,
    LRRC_LPHY_DURATION_TIMER_80,
    LRRC_LPHY_DURATION_TIMER_100,
    LRRC_LPHY_DURATION_TIMER_200,
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_DURATION_TIMER_300,
    LRRC_LPHY_DURATION_TIMER_400,
    LRRC_LPHY_DURATION_TIMER_500,
    LRRC_LPHY_DURATION_TIMER_600,
    LRRC_LPHY_DURATION_TIMER_800,
    LRRC_LPHY_DURATION_TIMER_1000,
    LRRC_LPHY_DURATION_TIMER_1200,
    LRRC_LPHY_DURATION_TIMER_1600,
#endif
    LRRC_LPHY_DURATION_TIMER_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_DURATION_TIMER_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_INACTIVE_TIMER_ENUM
 Э����  : MAC-MainConfiguration->drx-Configuration->drx-InactivityTimer
 ASN.1���� :
 ö��˵��  : drx-InactivityTimer
*****************************************************************************/
enum LRRC_LPHY_INACTIVE_TIMER_ENUM
{
    LRRC_LPHY_INACTIVE_TIMER_1            = 0,
    LRRC_LPHY_INACTIVE_TIMER_2,
    LRRC_LPHY_INACTIVE_TIMER_3,
    LRRC_LPHY_INACTIVE_TIMER_4,
    LRRC_LPHY_INACTIVE_TIMER_5,
    LRRC_LPHY_INACTIVE_TIMER_6,
    LRRC_LPHY_INACTIVE_TIMER_8,
    LRRC_LPHY_INACTIVE_TIMER_10,
    LRRC_LPHY_INACTIVE_TIMER_20,
    LRRC_LPHY_INACTIVE_TIMER_30,
    LRRC_LPHY_INACTIVE_TIMER_40,
    LRRC_LPHY_INACTIVE_TIMER_50,
    LRRC_LPHY_INACTIVE_TIMER_60,
    LRRC_LPHY_INACTIVE_TIMER_80,
    LRRC_LPHY_INACTIVE_TIMER_100,
    LRRC_LPHY_INACTIVE_TIMER_200,
    LRRC_LPHY_INACTIVE_TIMER_300,
    LRRC_LPHY_INACTIVE_TIMER_500,
    LRRC_LPHY_INACTIVE_TIMER_750,
    LRRC_LPHY_INACTIVE_TIMER_1280,
    LRRC_LPHY_INACTIVE_TIMER_1920,
    LRRC_LPHY_INACTIVE_TIMER_2560,
    LRRC_LPHY_INACTIVE_TIMER_0,
    LRRC_LPHY_INACTIVE_TIMER_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_INACTIVE_TIMER_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_RETRANS_TIMER_ENUM
 Э����  : MAC-MainConfiguration->drx-Configuration->drx-RetransmissionTimer
 ASN.1���� :
 ö��˵��  : drx-RetransmissionTimer
*****************************************************************************/
enum LRRC_LPHY_RETRANS_TIMER_ENUM
{
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_RETRANS_TIMER_0             = 0,
    LRRC_LPHY_RETRANS_TIMER_1,
#else
    LRRC_LPHY_RETRANS_TIMER_1             = 0,
#endif
    LRRC_LPHY_RETRANS_TIMER_2,
    LRRC_LPHY_RETRANS_TIMER_4,
    LRRC_LPHY_RETRANS_TIMER_6,
    LRRC_LPHY_RETRANS_TIMER_8,
    LRRC_LPHY_RETRANS_TIMER_16,
    LRRC_LPHY_RETRANS_TIMER_24,
    LRRC_LPHY_RETRANS_TIMER_33,
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_RETRANS_TIMER_40,
    LRRC_LPHY_RETRANS_TIMER_64,
    LRRC_LPHY_RETRANS_TIMER_80,
    LRRC_LPHY_RETRANS_TIMER_96,
    LRRC_LPHY_RETRANS_TIMER_112,
    LRRC_LPHY_RETRANS_TIMER_128,
    LRRC_LPHY_RETRANS_TIMER_160,
    LRRC_LPHY_RETRANS_TIMER_320,
#endif
    LRRC_LPHY_RETRANS_TIMER_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_RETRANS_TIMER_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_LONG_DRX_OFFSET_ENUM
 Э����  : MAC-MainConfiguration->drx-Configuration->longDRX-CycleStartOffset
 ASN.1���� :
 ö��˵��  : longDRX-CycleStartOffset
*****************************************************************************/
enum LRRC_LPHY_LONG_DRX_OFFSET_ENUM
{
    LRRC_LPHY_LONG_DRX_OFFSET_10    = 0,
    LRRC_LPHY_LONG_DRX_OFFSET_20,
    LRRC_LPHY_LONG_DRX_OFFSET_32,
    LRRC_LPHY_LONG_DRX_OFFSET_40,
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_LONG_DRX_OFFSET_60,
    LRRC_LPHY_LONG_DRX_OFFSET_70,
#endif
    LRRC_LPHY_LONG_DRX_OFFSET_64,
    LRRC_LPHY_LONG_DRX_OFFSET_80,
    LRRC_LPHY_LONG_DRX_OFFSET_128,
    LRRC_LPHY_LONG_DRX_OFFSET_160,
    LRRC_LPHY_LONG_DRX_OFFSET_256,
    LRRC_LPHY_LONG_DRX_OFFSET_320,
    LRRC_LPHY_LONG_DRX_OFFSET_512,
    LRRC_LPHY_LONG_DRX_OFFSET_640,
    LRRC_LPHY_LONG_DRX_OFFSET_1024,
    LRRC_LPHY_LONG_DRX_OFFSET_1280,
    LRRC_LPHY_LONG_DRX_OFFSET_2048,
    LRRC_LPHY_LONG_DRX_OFFSET_2560,
    LRRC_LPHY_LONG_DRX_OFFSET_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_LONG_DRX_OFFSET_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SHORT_DRX_CYCLE_ENUM
 Э����  : MAC-MainConfiguration->drx-Configuration->shortDRX->shortDRX-Cycle
 ASN.1���� :
 ö��˵��  : shortDRX-Cycle
*****************************************************************************/
enum LRRC_LPHY_SHORT_DRX_CYCLE_ENUM
{
    LRRC_LPHY_SHORT_DRX_CYCLE_2    = 0,
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_SHORT_DRX_CYCLE_4,
#endif
    LRRC_LPHY_SHORT_DRX_CYCLE_5,
    LRRC_LPHY_SHORT_DRX_CYCLE_8,
    LRRC_LPHY_SHORT_DRX_CYCLE_10,
    LRRC_LPHY_SHORT_DRX_CYCLE_16,
    LRRC_LPHY_SHORT_DRX_CYCLE_20,
    LRRC_LPHY_SHORT_DRX_CYCLE_32,
    LRRC_LPHY_SHORT_DRX_CYCLE_40,
    LRRC_LPHY_SHORT_DRX_CYCLE_64,
    LRRC_LPHY_SHORT_DRX_CYCLE_80,
    LRRC_LPHY_SHORT_DRX_CYCLE_128,
    LRRC_LPHY_SHORT_DRX_CYCLE_160,
    LRRC_LPHY_SHORT_DRX_CYCLE_256,
    LRRC_LPHY_SHORT_DRX_CYCLE_320,
    LRRC_LPHY_SHORT_DRX_CYCLE_512,
    LRRC_LPHY_SHORT_DRX_CYCLE_640,
    LRRC_LPHY_SHORT_DRX_CYCLE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SHORT_DRX_CYCLE_ENUM_UINT16;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 ö����    : LRRC_LPHY_LONG_DRX_OFFSET_ENUM
 Э����  : MAC-MainConfiguration->drx-Configuration->eDRX-Config-CycleStartOffset-r13
 ASN.1���� :
 ö��˵��  : longDRX-CycleStartOffset
*****************************************************************************/
enum LRRC_LPHY_EDRX_OFFSET_ENUM
{
    LRRC_LPHY_EDRX_OFFSET_5120    = 0,
    LRRC_LPHY_EDRX_OFFSET_10240,
    LRRC_LPHY_EDRX_OFFSET_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_EDRX_OFFSET_ENUM_UINT16;
#endif

/*****************************************************************************
 ö����    : LRRC_LPHY_DRX_INDICATOR_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : DRX�����Ƿ��
*****************************************************************************/
enum LRRC_LPHY_DRX_INDICATOR_ENUM
{
    LRRC_LPHY_DRX_INDICATOR_INVALID = 0,       /*DRX��ʹ�� */
    LRRC_LPHY_DRX_INDICATOR_VALID,             /* DRXʹ��*/
    LRRC_LPHY_DRX_INDICATOR_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DRX_INDICATOR_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_GATECLOCK_INDICATOR_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ʱ���ſ��Ƿ�ʹ��
*****************************************************************************/
enum LRRC_LPHY_GATECLOCK_INDICATOR_ENUM
{
    LRRC_LPHY_GATECLOCK_INDICATOR_INVALID = 0,                /*�ſ��Ӳ�ʹ�� */
    LRRC_LPHY_GATECLOCK_INDICATOR_VALID,                    /* �ſ���ʹ��*/
    LRRC_LPHY_GATECLOCK_INDICATOR_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_GATECLOCK_INDICATOR_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SI_WINDOW_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : SI��Ϣ��Window
*****************************************************************************/
enum LRRC_LPHY_SI_WINDOW_ENUM
{
    LRRC_LPHY_SI_WINDOW_MS01 = 0,
    LRRC_LPHY_SI_WINDOW_MS02,
    LRRC_LPHY_SI_WINDOW_MS05,
    LRRC_LPHY_SI_WINDOW_MS10,
    LRRC_LPHY_SI_WINDOW_MS15,
    LRRC_LPHY_SI_WINDOW_MS20,
    LRRC_LPHY_SI_WINDOW_MS40
};
typedef VOS_UINT16 LRRC_LPHY_SI_WINDOW_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SI_WINDOW_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : SI��Ϣ��Periodicty
*****************************************************************************/
enum LRRC_LPHY_SI_PERIOD_ENUM
{
    LRRC_LPHY_SI_PERIOD_RF008 = 0,
    LRRC_LPHY_SI_PERIOD_RF016,
    LRRC_LPHY_SI_PERIOD_RF032,
    LRRC_LPHY_SI_PERIOD_RF064,
    LRRC_LPHY_SI_PERIOD_RF128,
    LRRC_LPHY_SI_PERIOD_RF256,
    LRRC_LPHY_SI_PERIOD_RF512
};
typedef VOS_UINT16 LRRC_LPHY_SI_PERIOD_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : mbsfn radioframe allocation period
*****************************************************************************/
enum LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_ENUM
{
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_N1 = 0,
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_N2,
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_N4,
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_N8,
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_N16,
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_N32,
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_MBSFN_ALLOCATION_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : mbsfn allocation type
*****************************************************************************/
enum LRRC_LPHY_MBSFN_ALLOCATION_TYPE_ENUM
{
    LRRC_LPHY_MBSFN_ALLOCATION_TYPE_ONE = 0,
    LRRC_LPHY_MBSFN_ALLOCATION_TYPE_FOUR
};
typedef VOS_UINT16 LRRC_LPHY_MBSFN_ALLOCATION_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CGI_ACQUISITION_METHOD_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : CGI acquisition method
             0:������CGI��ȡ,������̬�����̬������ͨ��ϵͳ��Ϣ����
             1:��ʾ����̬������AUTONOMOUS GAPS��ȡ����ϵͳ��Ϣ
             2:��ʾ����̬�����ÿ���DRX���ڻ�ȡ����ϵͳ��Ϣ
*****************************************************************************/
enum LRRC_LPHY_CGI_ACQUISITION_METHOD_ENUM
{
    LRRC_LPHY_CGI_ACQUISITION_METHOD_NONE = 0,
    LRRC_LPHY_CGI_ACQUISITION_METHOD_AUTONOMOUS_GAPS,
    LRRC_LPHY_CGI_ACQUISITION_METHOD_IDLE_PERIODS,
    LRRC_LPHY_CGI_ACQUISITION_METHOD_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_CGI_ACQUISITION_METHOD_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_BAND_SCAN_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : ɨƵ����
*****************************************************************************/
enum LRRC_LPHY_BAND_SCAN_TYPE_ENUM
{
    LRRC_LPHY_BAND_SCAN_TYPE_INIT                  = 0,                         /* ��ʼɨƵ */
    LRRC_LPHY_BAND_SCAN_TYPE_CONT                  = 1,                         /* ����ɨƵ */
    LRRC_LPHY_BAND_SCAN_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_BAND_SCAN_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_HO_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : �л�����
*****************************************************************************/
enum LRRC_LPHY_HO_TYPE_ENUM
{
    LRRC_LPHY_HO_TYPE_INTRA_LTE                   = 0,                          /* LTE���л� */
    LRRC_LPHY_HO_TYPE_IRAT                        = 1,                          /* IRAT->LTE�л� */
    LRRC_LPHY_HO_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_HO_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_WORK_MODE_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : LTE RTT����ģʽ
*****************************************************************************/
enum LRRC_LPHY_WORK_MODE_TYPE_ENUM
{
    LRRC_LPHY_WORK_MODE_TYPE_ACTIVE                = 0,                         /* LTE���ڹ���̬ */
    LRRC_LPHY_WORK_MODE_TYPE_INACTIVE              = 1,                         /* LTE���ڲ���̬ */
    LRRC_LPHY_TEST_MODE_TYPE_ACTIVE                = 2,                         /* LTE���ڲ���̬ */
    LRRC_LPHY_TEST_MODE_TYPE_INACTIVE              = 3,                         /* LTE����ͣ����̬ */
    LRRC_LPHY_WORK_MODE_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_WORK_MODE_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SET_WORK_MODE_REASON_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : ��ģԭ��
*****************************************************************************/
enum LRRC_LPHY_SET_WORK_MODE_REASON_ENUM
{
    LRRC_LPHY_SET_WORK_MODE_REASON_POWEROFF              = 1,                   /* �ػ����� */
    LRRC_LPHY_SET_WORK_MODE_REASON_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_SET_WORK_MODE_REASON_ENUM_UINT16;


/*****************************************************************************
 ö����    : LRRC_LPHY_RAT_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : ϵͳ��������
*****************************************************************************/
enum LRRC_LPHY_RAT_TYPE_ENUM
{
    LRRC_LPHY_RAT_TYPE_LTE                    = 0,                              /* LTE */
    LRRC_LPHY_RAT_TYPE_GSM                    = 1,                              /* GSM */
    LRRC_LPHY_RAT_TYPE_WCDMA                  = 2,                              /* WCDMA */
    LRRC_LPHY_RAT_TYPE_TD_SCDMA               = 3,                              /* TD-SCDMA */
    LRRC_LPHY_RAT_TYPE_CDMA                   = 4,                              /* CDMA */

    LRRC_LPHY_RAT_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_RAT_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_GERAN_BAND_IND_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : GERAN��Ƶ��ָʾ
*****************************************************************************/
enum LRRC_LPHY_GERAN_BAND_IND_ENUM
{
    LRRC_LPHY_GERAN_BAND_IND_DCS1800          = 0,
    LRRC_LPHY_GERAN_BAND_IND_PCS1900,
    LRRC_LPHY_GERAN_BAND_IND_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_GERAN_BAND_IND_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : LTEģʽ����
*****************************************************************************/
enum LRRC_LPHY_LTE_MODE_TYPE_ENUM
{
    LRRC_LPHY_LTE_MODE_TYPE_FDD                = 0,                             /* LTE FDD ��ʽ */
    LRRC_LPHY_LTE_MODE_TYPE_TDD                = 1,                             /* LTE TDD ��ʽ */
    LRRC_LPHY_LTE_MODE_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_WCDMA_STATE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : WCDMAЭ��״̬����
*****************************************************************************/
enum LRRC_LPHY_WCDMA_STATE_ENUM
{
    LRRC_LPHY_WCDMA_STATE_CELL_PCH            = 0,                              /* CELL PCH */
    LRRC_LPHY_WCDMA_STATE_URA_PCH             = 1,                              /* URA PCH */
    LRRC_LPHY_WCDMA_STATE_CELL_FACH           = 2,                              /* CELL FACH */
    LRRC_LPHY_WCDMA_STATE_CELL_DCH            = 3,                              /* CELL DCH */
    LRRC_LPHY_WCDMA_STATE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_WCDMA_STATE_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_BAND_IND_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : LTE Bandָʾö��
**********************************************************/
enum LRRC_LPHY_BAND_IND_ENUM
{
    LRRC_LPHY_BAND_IND_NONE,
    LRRC_LPHY_BAND_IND_1                   = 1 ,
    LRRC_LPHY_BAND_IND_2,
    LRRC_LPHY_BAND_IND_3,
    LRRC_LPHY_BAND_IND_4,
    LRRC_LPHY_BAND_IND_5,
    LRRC_LPHY_BAND_IND_6,
    LRRC_LPHY_BAND_IND_7,
    LRRC_LPHY_BAND_IND_8,
    LRRC_LPHY_BAND_IND_9,
    LRRC_LPHY_BAND_IND_10,
    LRRC_LPHY_BAND_IND_11,
    LRRC_LPHY_BAND_IND_12,
    LRRC_LPHY_BAND_IND_13,
    LRRC_LPHY_BAND_IND_14,
    LRRC_LPHY_BAND_IND_15,
    LRRC_LPHY_BAND_IND_16,
    LRRC_LPHY_BAND_IND_17                = 17,
    LRRC_LPHY_BAND_IND_18,
    LRRC_LPHY_BAND_IND_19,
    LRRC_LPHY_BAND_IND_20,
    LRRC_LPHY_BAND_IND_21,
    LRRC_LPHY_BAND_IND_22,
    LRRC_LPHY_BAND_IND_23,
    LRRC_LPHY_BAND_IND_24,
    LRRC_LPHY_BAND_IND_25,
    LRRC_LPHY_BAND_IND_26,
    LRRC_LPHY_BAND_IND_27,
    LRRC_LPHY_BAND_IND_28,
    LRRC_LPHY_BAND_IND_29,
    LRRC_LPHY_BAND_IND_30,
    LRRC_LPHY_BAND_IND_31,
    LRRC_LPHY_BAND_IND_32,
    LRRC_LPHY_BAND_IND_33                = 33,
    LRRC_LPHY_BAND_IND_34,
    LRRC_LPHY_BAND_IND_35,
    LRRC_LPHY_BAND_IND_36,
    LRRC_LPHY_BAND_IND_37,
    LRRC_LPHY_BAND_IND_38,
    LRRC_LPHY_BAND_IND_39,
    LRRC_LPHY_BAND_IND_40,
    LRRC_LPHY_BAND_IND_41,
    LRRC_LPHY_BAND_IND_42,
    LRRC_LPHY_BAND_IND_43,
    LRRC_LPHY_BAND_IND_64                = 64,

    /* �Ǳ�Ƶ��begin */
    LRRC_LPHY_BAND_IND_101  = 101,
    LRRC_LPHY_BAND_IND_102  = 102,
    LRRC_LPHY_BAND_IND_103  = 103,
    LRRC_LPHY_BAND_IND_104  = 104,
    LRRC_LPHY_BAND_IND_105  = 105,
    LRRC_LPHY_BAND_IND_106  = 106,
    LRRC_LPHY_BAND_IND_107  = 107,
    LRRC_LPHY_BAND_IND_108  = 108,
    LRRC_LPHY_BAND_IND_109  = 109,
    LRRC_LPHY_BAND_IND_110  = 110,
    LRRC_LPHY_BAND_IND_111  = 111,
    LRRC_LPHY_BAND_IND_112  = 112,
    LRRC_LPHY_BAND_IND_113  = 113,
    LRRC_LPHY_BAND_IND_114  = 114,
    LRRC_LPHY_BAND_IND_115  = 115,
    LRRC_LPHY_BAND_IND_116  = 116,
    /* �Ǳ�Ƶ��end */

    LRRC_LPHY_BAND_IND_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_BAND_IND_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_ERR_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����㷢�����������ö��
**********************************************************/
enum LRRC_LPHY_ERR_TYPE_ENUM
{
    LRRC_LPHY_ERR_TYPE_TIMING_ERR       = 0 ,                                   /* ��ʱ���� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_ERR_TYPE_SCG_MIB_ERR      = 1 ,                                   /* scg���� */
#endif

    LRRC_LPHY_ERR_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_ERR_TYPE_ENUM_UINT16;

/* MBMS Begin */
/*********************************************************
 ö����    : LRRC_LPHY_MCCH_REPET_PERIOD_R9_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : MCCH�ظ�����
**********************************************************/
enum LRRC_LPHY_MCCH_REPET_PERIOD_R9_ENUM
{
    LRRC_LPHY_RF32_MCCH_REPET_PERIOD_R9                = 0,
    LRRC_LPHY_RF64_MCCH_REPET_PERIOD_R9                = 1,
    LRRC_LPHY_RF128_MCCH_REPET_PERIOD_R9               = 2,
    LRRC_LPHY_RF256_MCCH_REPET_PERIOD_R9               = 3,
    LRRC_LPHY_MCCH_REPET_PERIOD_R9_BUTT
};
typedef VOS_UINT8 LRRC_LPHY_MCCH_REPET_PERIOD_R9_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_LRRC_LPHY_MCCH_OFFSET_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : MCCH offsetֵ(0..10)
**********************************************************/
enum LRRC_LPHY_LRRC_LPHY_MCCH_OFFSET_ENUM
{
    LRRC_LPHY_MCCH_OFFSET_0,
    LRRC_LPHY_MCCH_OFFSET_1,
    LRRC_LPHY_MCCH_OFFSET_2,
    LRRC_LPHY_MCCH_OFFSET_3,
    LRRC_LPHY_MCCH_OFFSET_4,
    LRRC_LPHY_MCCH_OFFSET_5,
    LRRC_LPHY_MCCH_OFFSET_6,
    LRRC_LPHY_MCCH_OFFSET_7,
    LRRC_LPHY_MCCH_OFFSET_8,
    LRRC_LPHY_MCCH_OFFSET_9,
    LRRC_LPHY_MCCH_OFFSET_10,
    LRRC_LPHY_MCCH_OFFSET_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_LRRC_LPHY_MCCH_OFFSET_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_MCCH_MODIFY_PERIOD_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : MCCH modify����(0..10)
**********************************************************/
enum LRRC_LPHY_MCCH_MODIFY_PERIOD_ENUM
{
    LRRC_LPHY_MCCH_MODIFY_PERIOD_RF_512,
    LRRC_LPHY_MCCH_MODIFY_PERIOD_RF_1024,
    LRRC_LPHY_MCCH_MODIFY_PERIOD_RF_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_MCCH_MODIFY_PERIOD_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_SIG_MCS_R9_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : MCCH Signal MCS������Ϣ
**********************************************************/
enum LRRC_LPHY_SIG_MCS_R9_ENUM
{
    LRRC_LPHY_N2_SIG_MCS_R9                            = 0,
    LRRC_LPHY_N7_SIG_MCS_R9                            = 1,
    LRRC_LPHY_N13_SIG_MCS_R9                           = 2,
    LRRC_LPHY_N19_SIG_MCS_R9                           = 3,
    LRRC_LPHY_SIG_MCS_R9_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_SIG_MCS_R9_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_NON_MBSF_NREGION_LEN_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_NON_MBSF_NREGION_LEN_ENUM
{
    LRRC_LPHY_NON_MBSF_NREGION_LEN_1,
    LRRC_LPHY_NON_MBSF_NREGION_LEN_2,
    LRRC_LPHY_NON_MBSF_NREGION_LEN_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_NON_MBSF_NREGION_LEN_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_NON_MBSF_NREGION_LEN_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_CONIG_VALID_FLG_ENUM
{
    LRRC_LPHY_CONIG_FLG_INVALID  = 0,
    LRRC_LPHY_CONIG_FLG_VALID    = 1
};
typedef VOS_UINT8 LRRC_LPHY_CONIG_VALID_FLG_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_NOTIFICATION_OFFSET_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_NOTIFICATION_OFFSET_ENUM
{
    LRRC_LPHY_NOTIFICATION_OFFSET_0,
    LRRC_LPHY_NOTIFICATION_OFFSET_1,
    LRRC_LPHY_NOTIFICATION_OFFSET_2,
    LRRC_LPHY_NOTIFICATION_OFFSET_3,
    LRRC_LPHY_NOTIFICATION_OFFSET_4,
    LRRC_LPHY_NOTIFICATION_OFFSET_5,
    LRRC_LPHY_NOTIFICATION_OFFSET_6,
    LRRC_LPHY_NOTIFICATION_OFFSET_7,
    LRRC_LPHY_NOTIFICATION_OFFSET_8,
    LRRC_LPHY_NOTIFICATION_OFFSET_9,
    LRRC_LPHY_NOTIFICATION_OFFSET_10,
    LRRC_LPHY_NOTIFICATION_OFFSET_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_NOTIFICATION_OFFSET_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_NOTIFICATION_OFFSET_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_NOTIFICATION_REPET_COEFF_R9_ENUM
{
    LRRC_LPHY_N2_NOTIFICATION_REPET_COEFF_R9           = 0,
    LRRC_LPHY_N4_NOTIFICATION_REPET_COEFF_R9           = 1,
    LRRC_LPHY_NOTIFICATION_REPET_COEFF_R9_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_NOTIFICATION_REPET_COEFF_R9_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_NOTIFICATION_OFFSET_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_NOTIFICATION_SF_INDEX_ENUM
{
    LRRC_LPHY_NOTIFICATION_SF_INDEX_1 = 1,
    LRRC_LPHY_NOTIFICATION_SF_INDEX_2,
    LRRC_LPHY_NOTIFICATION_SF_INDEX_3,
    LRRC_LPHY_NOTIFICATION_SF_INDEX_4,
    LRRC_LPHY_NOTIFICATION_SF_INDEX_5,
    LRRC_LPHY_NOTIFICATION_SF_INDEX_6,
    LRRC_LPHY_NOTIFICATION_SF_INDEX_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_NOTIFICATION_SF_INDEX_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_NOTIFICATION_OFFSET_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_MCH_SCHDL_PERIOD_R9_ENUM
{
    LRRC_LPHY_RF8_MCH_SCHDL_PERIOD_R9                  = 0,
    LRRC_LPHY_RF16_MCH_SCHDL_PERIOD_R9                 = 1,
    LRRC_LPHY_RF32_MCH_SCHDL_PERIOD_R9                 = 2,
    LRRC_LPHY_RF64_MCH_SCHDL_PERIOD_R9                 = 3,
    LRRC_LPHY_RF128_MCH_SCHDL_PERIOD_R9                = 4,
    LRRC_LPHY_RF256_MCH_SCHDL_PERIOD_R9                = 5,
    LRRC_LPHY_RF512_MCH_SCHDL_PERIOD_R9                = 6,
    LRRC_LPHY_RF1024_MCH_SCHDL_PERIOD_R9               = 7,
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_RF4_MCH_SCHDL_PERIOD_R9                  = 8,                     /* R12Э�鿪��ʱ��չ */
#endif
    LRRC_LPHY_MCH_SCHDL_PERIOD_R9_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_MCH_SCHDL_PERIOD_R9_ENUM_UINT8;

/*********************************************************
 ö����    : LRRC_LPHY_COMM_SF_ALLOC_PERIOD_R9_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_COMM_SF_ALLOC_PERIOD_R9_ENUM
{
    LRRC_LPHY_RF4_MBSFN                                      = 0,
    LRRC_LPHY_RF8_MBSFN                                      = 1,
    LRRC_LPHY_RF16_MBSFN                                     = 2,
    LRRC_LPHY_RF32_MBSFN                                     = 3,
    LRRC_LPHY_RF64_MBSFN                                     = 4,
    LRRC_LPHY_RF128_MBSFN                                    = 5,
    LRRC_LPHY_RF256_MBSFN                                    = 6,
    LRRC_LPHY_MBSFN_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_COMM_SF_ALLOC_PERIOD_R9_ENUM_UINT8;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*********************************************************
 ö����    : LRRC_LPHY_NOTIFICATION_OFFSET_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :non-MBSFNregionLength
**********************************************************/
enum LRRC_LPHY_MCH_DATA_MCS_TYPE_ENUM
{
    LRRC_LPHY_MCH_DATA_MCS_NORMAL                             = 0,
    LRRC_LPHY_MCH_DATA_MCS_HIGH_ORDER                         = 1,
    LRRC_LPHY_MCH_DATA_MCS_BUFF
};
typedef VOS_UINT8 LRRC_LPHY_MCH_DATA_MCS_TYPE_ENUM_UINT8;
#endif

/* LCS Begin */

/*****************************************************************************
 ö����    : LRRC_LPHY_OTDOA_ENABLE_SIGNAL_ENUM
 Э����  : �ϱ�������࣬�Ƿ����㹻��gap���ͷ�gap
 ASN.1���� :
 ö��˵��  : LRRC_LPHY_OTDOA_ENABLE_SIGNAL_ENUM
*****************************************************************************/
enum LRRC_LPHY_OTDOA_ENABLE_SIGNAL_ENUM
{
    LRRC_LPHY_OTDOA_ENABLE_STOP,
    LRRC_LPHY_OTDOA_ENABLE_START,
    LRRC_LPHY_OTDOA_ENABLE_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_OTDOA_ENABLE_SIGNAL_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_POSITION_OTDOA_MEAS_REQ_ENUM
 Э����  : ������ָֹͣʾOTDOA����
 ASN.1���� :
 ö��˵��  : LRRC_LPHY_POSITION_OTDOA_MEAS_REQ_ENUM
*****************************************************************************/
enum LRRC_LPHY_POSITION_OTDOA_MEAS_REQ_ENUM
{
    LRRC_LPHY_POSITION_OTDOA_MEAS_REL,
    LRRC_LPHY_POSITION_OTDOA_MEAS_SETUP,
    LRRC_LPHY_POSITION_OTDOA_MEAS_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_POSITION_OTDOA_MEAS_REQ_ENUM_UINT16;

/*****************************************************************************
 ö����    : OTDOA_TARGET_DEVICE_ERROR_CAUSES_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : OTDOA_TARGET_DEVICE_ERROR_CAUSES_ENUM_UINT16
*****************************************************************************/
enum LRRC_LPHY_OTDOA_TARGET_DEVICE_ERROR_CAUSES_ENUM
{
    LRRC_LPHY_OTDOA_MEAS_NO_ERROR,
    LRRC_LPHY_OTDOA_TARGET_DEVICE_UNDEFINED,
    LRRC_LPHY_OTDOA_ASSISTANCE_DATA_MISSING,
    LRRC_LPHY_OTDOA_UNABLE_TO_MEASURE_REF_CELL,
    LRRC_LPHY_OTDOA_UNABLE_TO_MEASURE_ANY_NEIGHBOUR_CELL,
    LRRC_LPHY_OTDOA_ATTEMPTED_BUT_UNABLE_TO_MEASURE_SOME_NEIGHBOUR_CELLS,
    LRRC_LPHY_OTDOA_TARGET_DEVICE_ERROR_CAUSES_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_OTDOA_TARGET_DEVICE_ERROR_CAUSES_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_ECID_TARGET_DEVICE_ERROR_CAUSES_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : LRRC_LPHY_ECID_TARGET_DEVICE_ERROR_CAUSES_ENUM
*****************************************************************************/
enum LRRC_LPHY_ECID_TARGET_DEVICE_ERROR_CAUSES_ENUM
{
    LRRC_LPHY_ECID_MEAS_NO_ERROR,
    LRRC_LPHY_ECID_TARGET_DEVICE_UNDEFINED,
    LRRC_LPHY_ECID_REQUESTED_MEASUREMENT_NOT_AVAILABLE,
    LRRC_LPHY_ECID_NOT_ALL_REQUESTED_MEASUREMENTS_POSSIBLE,
    LRRC_LPHY_ECID_TARGET_DEVICE_ERROR_CAUSES_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_ECID_TARGET_DEVICE_ERROR_CAUSES_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_LTE_CP_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_LTE_CP_TYPE_ENUM
{
    LRRC_LPHY_LTE_CP_TYPE_NORMAL = 0,
    LRRC_LPHY_LTE_CP_TYPE_EXTENDED,
    LRRC_LPHY_LTE_CP_TYPE_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_LTE_CP_TYPE_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_OTDOA_ANT_PORT_CFG_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_OTDOA_ANT_PORT_CFG_ENUM
{
    LRRC_LPHY_OTDOA_ANT_PORTS_1_OR_2 = 1,
    LRRC_LPHY_OTDOA_ANT_PORTS_4      = 4,
    LRRC_LPHY_OTDOA_ANT_PORTS_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_OTDOA_ANT_PORT_CFG_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_OTDOA_PRS_CRS_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_OTDOA_PRS_CRS_TYPE_ENUM
{
    LRRC_LPHY_OTDOA_PRS_TYPE,
    LRRC_LPHY_OTDOA_CRS_TYPE,
    LRRC_LPHY_OTDOA_PRS_CRS_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_OTDOA_PRS_CRS_TYPE_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_OTDOA_DL_SUBFRAME_NUM_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_OTDOA_DL_SUBFRAME_NUM_ENUM
{
    LRRC_LPHY_OTDOA_DL_SF_1,
    LRRC_LPHY_OTDOA_DL_SF_2,
    LRRC_LPHY_OTDOA_DL_SF_4,
    LRRC_LPHY_OTDOA_DL_SF_6,
    LRRC_LPHY_OTDOA_DL_SF_BUFF
};
typedef VOS_UINT16 LRRC_LPHY_OTDOA_DL_SUBFRAME_NUM_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_OTDOA_DL_SUBFRAME_NUM_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_LTE_BAND_WIDTH_ENUM
{
    LRRC_LPHY_LTE_BAND_WIDTH_1D4M = 0,
    LRRC_LPHY_LTE_BAND_WIDTH_3M,
    LRRC_LPHY_LTE_BAND_WIDTH_5M,
    LRRC_LPHY_LTE_BAND_WIDTH_10M,
    LRRC_LPHY_LTE_BAND_WIDTH_15M,
    LRRC_LPHY_LTE_BAND_WIDTH_20M,
    LRRC_LPHY_LTE_BAND_WIDTH_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_LTE_BAND_WIDTH_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_OTDOA_RPRT_INTERVAL_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_OTDOA_RPRT_INTERVAL_ENUM
{
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_1 = 0,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_2,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_4,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_8,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_10,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_16,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_20,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_32,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_SECOND_64,
    LRRC_LPHY_OTDOA_RPRT_INTERVAl_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_OTDOA_RPRT_INTERVAL_ENUM_UINT16;


/* LCS End */

/*********************************************************
 ö����    : LRRC_LPHY_DELTAF_PUCCH_FORMAT3_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_DELTAF_PUCCH_FORMAT3_ENUM
{
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_NEGATIVE_1 = 0,                          /* deltaF-1 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_0,                                       /* deltaF0 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_1,                                       /* deltaF1 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_2,                                       /* deltaF2 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_3,                                       /* deltaF3 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_4,                                       /* deltaF4 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_5,                                       /* deltaF5 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_6,                                       /* deltaF6 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DELTAF_PUCCH_FORMAT3_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_ENUM
{
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_1,                                        /* deltaF1 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_2,                                        /* deltaF2 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_SPARE2,                                   /* spare2 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_SPARE1,                                   /* spare1 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_ENUM_UINT16;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*********************************************************
 ö����    : LRRC_LPHY_DELTAF_PUCCH_FORMAT4_ENUM
 Э����  :
 ASN.1���� : deltaF-PUCCH-Format4-r13 ENUMERATED {deltaF16, deltaF15, deltaF14,deltaF13, deltaF12,deltaF11, deltaF10, spare1}
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_DELTAF_PUCCH_FORMAT4_ENUM
{
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_16,                                          /* deltaF16 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_15,                                          /* deltaF15 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_14,                                          /* ... */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_13,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_12,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_11,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_10,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_SPARE1,
    LRRC_LPHY_DELTAF_PUCCH_FORMA4_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DELTAF_PUCCH_FORMAT4_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_DELTAF_PUCCH_FORMAT5_ENUM
 Э����  :
 ASN.1���� : deltaF-PUCCH-Format5-13 ENUMERATED { deltaF13, deltaF12, deltaF11, deltaF10, deltaF9,deltaF8, deltaF7, spare1
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_DELTAF_PUCCH_FORMAT5_ENUM
{
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_13,                                          /* deltaF13 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_12,                                          /* deltaF12 */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_11,                                          /* ... */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_10,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_9,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_8,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_7,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_SPARE1,
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DELTAF_PUCCH_FORMAT5_ENUM_UINT16;
#endif

/*********************************************************
 ö����    : LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM
{
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_DB_0,                                       /* dB 0 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_DB_NEGATIVE_1,                              /* dB -1 */
#endif
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_DB_NEGATIVE_2,                              /* dB -2 */
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM_UINT16;

/*********************************************************
 ö����    : LRRC_LPHY_PUCCH_FORMAT_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
**********************************************************/
enum LRRC_LPHY_PUCCH_FORMAT_TYPE_ENUM
{
    LRRC_LPHY_PUCCH_FORMAT_TYPE_FORMAT3,                                        /* format3-r10 */
    LRRC_LPHY_PUCCH_FORMAT_TYPE_CHANNEL_SEL,                                    /* channelSelection-r10 */
    LRRC_LPHY_PUCCH_FORMAT_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_PUCCH_FORMAT_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SUBFRAME_PATTERN_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_SUBFRAME_PATTERN_TYPE_ENUM
{
    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_FDD,                                        /* subframePatternFDD-r10 */
    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_TDD_1_5,                                    /* subframeConfig1-5-r10 */
    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_TDD_0,                                      /* subframeConfig0-r10 */
    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_TDD_6,                                      /* subframeConfig6-r10 */
    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PERIODIC_FACTOR_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_PERIODIC_FACTOR_ENUM
{
    LRRC_LPHY_PERIODIC_FACTOR_N2,                                               /* n2  */
    LRRC_LPHY_PERIODIC_FACTOR_N4,                                               /* n4 */
    LRRC_LPHY_PERIODIC_FACTOR_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PERIODIC_FACTOR_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CQI_REPORT_MODE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_CQI_REPORT_MODE_ENUM
{
    LRRC_LPHY_CQI_REPORT_MODE_SUBMODE1,                                         /* submode1 */
    LRRC_LPHY_CQI_REPORT_MODE_SUBMODE2,                                         /* submode2 */
    LRRC_LPHY_CQI_REPORT_MODE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_CQI_REPORT_MODE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_TRANSMISSION_MODE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_TRANSMISSION_MODE_ENUM
{
    LRRC_LPHY_TRANSMISSION_MODE_TM1,
    LRRC_LPHY_TRANSMISSION_MODE_TM2,
    LRRC_LPHY_TRANSMISSION_MODE_SPARE6,
    LRRC_LPHY_TRANSMISSION_MODE_SPARE5,
    LRRC_LPHY_TRANSMISSION_MODE_SPARE4,
    LRRC_LPHY_TRANSMISSION_MODE_SPARE3,
    LRRC_LPHY_TRANSMISSION_MODE_SPARE2,
    LRRC_LPHY_TRANSMISSION_MODE_SPARE1,
    LRRC_LPHY_TRANSMISSION_MODE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_TRANSMISSION_MODE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PATHLOSS_REF_LINK_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_PATHLOSS_REF_LINK_ENUM
{
    LRRC_LPHY_PATHLOSS_REF_LINK_PCELL,
    LRRC_LPHY_PATHLOSS_REF_LINK_SCELL,
    LRRC_LPHY_PATHLOSS_REF_LINK_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_PATHLOSS_REF_LINK_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_SCHEDUL_CELL_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_SCHEDUL_CELL_TYPE_ENUM
{
    LRRC_LPHY_SCHEDUL_CELL_TYPE_OWN,                                            /* No cross carrier scheduling */
    LRRC_LPHY_SCHEDUL_CELL_TYPE_OTHER,                                          /* Cross carrier scheduling */
    LRRC_LPHY_SCHEDUL_CELL_TYPE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_SCHEDUL_CELL_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_MEAS_CYCLE_SCELL_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum LRRC_LPHY_MEAS_CYCLE_SCELL_ENUM
{
    LRRC_LPHY_MEAS_CYCLE_SF_160,
    LRRC_LPHY_MEAS_CYCLE_SF_256,
    LRRC_LPHY_MEAS_CYCLE_SF_320,
    LRRC_LPHY_MEAS_CYCLE_SF_512,
    LRRC_LPHY_MEAS_CYCLE_SF_640,
    LRRC_LPHY_MEAS_CYCLE_SF_1024,
    LRRC_LPHY_MEAS_CYCLE_SF_1280,
    LRRC_LPHY_MEAS_CYCLE_SPARE1,
    LRRC_LPHY_MEAS_CYCLE_BUTT
};
typedef VOS_UINT16    LRRC_LPHY_MEAS_CYCLE_SCELL_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DSDS_RFSHARED_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :DSDS����������RF shared�Ƿ�ʹ��
*****************************************************************************/
enum LRRC_LPHY_DSDS_RFSHARED_ENUM
{
    LRRC_LPHY_DSDS_RFSHARED_DISABLE           = 0,    /* ������ */
    LRRC_LPHY_DSDS_RFSHARED_ENABLE            = 1,    /* ���� */
    LRRC_LPHY_DSDS_RFSHARED_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_DSDS_RFSHARED_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_NOTCH_STATE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :  ֪ͨ���������NOTCH ͨ��ָʾ
*****************************************************************************/

enum LRRC_LPHY_NOTCH_STATE_ENUM
{
    LRRC_LPHY_NOTCH_OPEN_FLAG_FALSE          = 0,    /* ������ */
    LRRC_LPHY_NOTCH_OPEN_FLAG_TRUE           = 1,    /* ���� */
    LRRC_LPHY_NOTCH_OPEN_FLAG_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_NOTCH_STATE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_DPDT_CMD_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : ����DPST����Ĺ���
*****************************************************************************/

enum LRRC_LPHY_DPDT_CMD_ENUM
{
    LRRC_LPHY_SET_SWITCH           = 0,    /*���� */
    LRRC_LPHY_SET_VALUE            = 1,    /* ����ֵ */
    LRRC_LPHY_DPDT_VALUE_QRY               /*��ѯ*/
};
typedef VOS_UINT16  LRRC_LPHY_DPDT_CMD_ENUM_UINT16;

#if (FEATURE_ON == FEATURE_LTE_R11)
/*****************************************************************************
 ö����    : LRRC_LPHY_QCL_OPERATION_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/

enum LRRC_LPHY_QCL_OPERATION_ENUM
{
    LRRC_LPHY_QCL_OPERATION_TYPEA           = 0,
    LRRC_LPHY_QCL_OPERATION_TYPEB           = 1
};
typedef VOS_UINT16  LRRC_LPHY_QCL_OPERATION_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_CRS_PORTS_COUNT_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/

enum LRRC_LPHY_CRS_PORTS_COUNT_ENUM
{
    LRRC_LPHY_CRS_PORTS_N1,
    LRRC_LPHY_CRS_PORTS_N2,
    LRRC_LPHY_CRS_PORTS_N4,
    LRRC_LPHY_CRS_PORTS_SPARE1,
    LRRC_LPHY_CRS_PORTS_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_CRS_PORTS_COUNT_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_PDSCH_START_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/

enum LRRC_LPHY_PDSCH_START_ENUM
{
    LRRC_LPHY_PDSCH_START_RESERVED,
    LRRC_LPHY_PDSCH_START_N1,
    LRRC_LPHY_PDSCH_START_N2,
    LRRC_LPHY_PDSCH_START_N3,
    LRRC_LPHY_PDSCH_START_N4,
    LRRC_LPHY_PDSCH_START_ASSIGNED,
    LRRC_LPHY_PDSCH_START_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_PDSCH_START_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_TRANSMISSION_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/

enum LRRC_LPHY_TRANSMISSION_TYPE_ENUM
{
    LRRC_LPHY_TRANSMISSION_TYPE_LOCALISED                 = 0,                  /*localised*/
    LRRC_LPHY_TRANSMISSION_TYPE_DISTRIBUTED ,                                   /*distributed*/
    LRRC_LPHY_TRANSMISSION_TYPE_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_TRANSMISSION_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : LRRC_LPHY_NUMBERPRB_PAIRS_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/

enum LRRC_LPHY_NUMBERPRB_PAIRS_ENUM
{
    LRRC_LPHY_NUMBERPRB_PAIRS_N2                 = 0,                           /*N2*/
    LRRC_LPHY_NUMBERPRB_PAIRS_N4 ,                                              /*N4*/
    LRRC_LPHY_NUMBERPRB_PAIRS_N8 ,                                              /*N8*/
    LRRC_LPHY_NUMBERPRB_PAIRS_BUTT
};
typedef VOS_UINT16  LRRC_LPHY_NUMBERPRB_PAIRS_ENUM_UINT16;
#endif

/*****************************************************************************
 ö����    : LRRC_LPHY_BGSCFG_TYPE_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : DSDS����������ָʾ��������������������������ʵ������
*****************************************************************************/
enum LRRC_LPHY_BGSCFG_TYPE_ENUM
{
    LRRC_LPHY_BGSCFG_TYPE_BGS                    = 0,
    LRRC_LPHY_BGSCFG_TYPE_DSDS                   = 1,
    LRRC_LPHY_BGSCFG_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_BGSCFG_TYPE_ENUM_UINT16;
/* begin,���������Ż�, l00277963 */
/*****************************************************************************
 ö����    : LRRC_LPHY_BG_SEARCH_PRIORITY_ENUM
 Э����  :
 ASN.1���� :
 ö��˵��  : �������������ȼ�ö��
*****************************************************************************/
enum LRRC_LPHY_BG_SEARCH_PRIORITY_ENUM
{
    LRRC_LPHY_BG_SEARCH_PRIORITY_LOW                    = 0,
    LRRC_LPHY_BG_SEARCH_PRIORITY_MIDDLE                 = 1,
    LRRC_LPHY_BG_SEARCH_PRIORITY_HIGH                   = 2,

    LRRC_LPHY_BG_SEARCH_PRIORITY_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_BG_SEARCH_PRIORITY_ENUM_UNIT16;
/* end,���������Ż�, l00277963 */

/*****************************************************************************
 ö����    : LRRC_LPHY_DSDS_NORF_TYPE_ENUMs
 Э����  :
 ASN.1���� :
 ö��˵��  : DSDS�����������ϱ�NORF�ĳ���
*****************************************************************************/
enum LRRC_LPHY_DSDS_NORF_TYPE_ENUM
{
    LRRC_LPHY_DSDS_NORF_TYPE_OUTOFSYNC             = 0,   /*ͬʧ������*/
    LRRC_LPHY_DSDS_NORF_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_DSDS_NORF_TYPE_ENUM_UINT16;

/* Begin: 2016/1/4 cr develop */
/*****************************************************************************
 ö����    : LRRC_LPHY_ANTENNA_MAX_LAYERS_MIMO_ENUM
 Э����  : RadioResourceConfigDedicated->PhysicalConfigDedicated->
             AntennaInformationDedicated_v10i0
 ASN.1���� :
 ö��˵��  : ����
*****************************************************************************/
enum LRRC_LPHY_ANTENNA_MAX_LAYERS_MIMO_ENUM
{
    LRRC_LPHY_ANTENNA_TWO_LAYERS      = 0,      /* UE MIMO����2�� */
    LRRC_LPHY_ANTENNA_FOUR_LAYERS,              /* UE MIMO����4�� */
    LRRC_LPHY_ANTENNA_EIGHT_LAYERS,             /* UE MIMO����8�� */
    LRRC_LPHY_ANTENNA_MAX_LAYERS_BUTT           /* ֵ��Ч��PHY��ΪIE��Ч */
};
typedef VOS_UINT16    LRRC_LPHY_ANTENNA_MAX_LAYERS_MIMO_UINT16;
/* End: 2016/1/4 cr develop */


#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : MeasScaleFactor
 Э����  :
 ASN.1���� : MeasScaleFactor-r12 ::= ENUMERATED {sf-EUTRA-cf1, sf-EUTRA-cf2}
 ö��˵��  : ��������
*****************************************************************************/
enum LRRC_LPHY_MEAS_SCAL_FAC_TYPE_ENUM
{
    LRRC_LPHY_MEAS_SCAL_FAC_CF1                = 0,
    LRRC_LPHY_MEAS_SCAL_FAC_CF2                   ,

    LRRC_LPHY_MEAS_SCAL_FAC_BUTT
};
typedef VOS_UINT8 LRRC_LPHY_MEAS_SCAL_FAC_TYPE_ENUM_UINT8;


/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef enum
{
    LRRC_LPHY_SF10_EIMTA_CMD_PERIOD                = 0,
    LRRC_LPHY_SF20_EIMTA_CMD_PERIOD                = 1,
    LRRC_LPHY_SF40_EIMTA_CMD_PERIOD                = 2,
    LRRC_LPHY_SF80_EIMTA_CMD_PERIOD                = 3,
    LRRC_LPHY_BUTT_EIMTA_CMD_PERIOD
}LRRC_LPHY_EIMTA_CMD_PERIOD_R12_ENUM;
typedef VOS_UINT8                 LRRC_LPHY_EIMTA_CMD_PERIOD_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef enum
{
    LRRC_LPHY_SA2_EIMTA_HARQ_REF_CONFIG            = 0,
    LRRC_LPHY_SA4_EIMTA_HARQ_REF_CONFIG            = 1,
    LRRC_LPHY_SA5_EIMTA_HARQ_REF_CONFIG            = 2,
    LRRC_LPHY_BUTT_EIMTA_HARQ_REF_CONFIG
}LRRC_LPHY_EIMTA_HARQ_REF_CONFIG_ENUM;
typedef VOS_UINT8   LRRC_LPHY_EIMTA_HARQ_REF_CONFIG_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef enum
{
    LRRC_LPHY_ALL_SUBFRAMES_ALT_CQI_TABLE          = 0,
    LRRC_LPHY_CSI_SUBFRAME_SET1_ALT_CQI_TABLE      = 1,
    LRRC_LPHY_CSI_SUBFRAME_SET2_ALT_CQI_TABLE      = 2,
    LRRC_LPHY_SPARE1_ALT_CQI_TABLE                 = 3,
    LRRC_LPHY_BUTT_ALT_CQI_TABLE
}LRRC_LPHY_ALT_CQI_TABLE_ENUM;
typedef VOS_UINT8     LRRC_LPHY_ALT_CQI_TABLE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_TBS_INDEX_ALT_ENUM
{
    LRRC_LPHY_A26                                      = 0,
    LRRC_LPHY_A33                                      = 1,
    LRRC_LPHY_TBS_INDEX_ALT_BUTT
};
typedef VOS_UINT16   LRRC_LPHY_TBS_INDEX_ALT_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_TRIG_SUBFRAME_SET_IND_ENUM
{
    LRRC_LPHY_S1                                       = 0,
    LRRC_LPHY_S2                                       = 1,
    LRRC_LPHY_TRIG_SUBFRAME_SET_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_TRIG_SUBFRAME_SET_IND_ENUM_UINT8;

/*****************************************************************************
 ö����    : LRRC_LPHY_CELL_TYPE_ENUM_UINT8
 Э����  :
 ASN.1���� :
 ö��˵��  : С�����ͣ�Ŀǰ����ͬ��ʧ����Ϣ
*****************************************************************************/
enum LRRC_LPHY_CELL_TYPE_ENUM
{
    LRRC_LPHY_TYPE_PCELL          = 0,
    LRRC_LPHY_TYPE_PSCELL,
    LRRC_LPHY_TYPE_MCG_SCELL,
    LRRC_LPHY_TYPE_SCG_SCELL,
    LRRC_LPHY_TYPE_BUTT
};
typedef VOS_UINT8  LRRC_LPHY_CELL_TYPE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CG_ENUM
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_CG_ENUM
{
    LRRC_LPHY_MCG                           = 0,
    LRRC_LPHY_SCG                           = 1,
    LRRC_LPHY_CG_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_CG_ENUM_UINT8;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CG_ENUM
 Э����  :
 ASN.1���� :

 LoggingInterval-r10 ::=         ENUMERATED {
                                     ms1280, ms2560, ms5120, ms10240, ms20480,
                                     ms30720, ms40960, ms61440}
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_MBSFN_LOG_INTERVAL_ENUM
{
    LRRC_LPHY_MBSFN_LOG_INTVL_1280MS        = 0,
    LRRC_LPHY_MBSFN_LOG_INTVL_2560MS        = 1,
    LRRC_LPHY_MBSFN_LOG_INTVL_5120MS        = 2,
    LRRC_LPHY_MBSFN_LOG_INTVL_10240MS       = 3,
    LRRC_LPHY_MBSFN_LOG_INTVL_20480MS       = 4,
    LRRC_LPHY_MBSFN_LOG_INTVL_30720MS       = 5,
    LRRC_LPHY_MBSFN_LOG_INTVL_40960MS       = 6,
    LRRC_LPHY_MBSFN_LOG_INTVL_61440MS       = 7,
    LRRC_LPHY_MBSFN_LOG_INTERVAL_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_MBSFN_LOG_INTERVAL_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CG_ENUM
 Э����  :
 ASN.1���� :
 dmtc-PeriodOffset-r12 CHOICE {
             ms40-r12   INTEGER(0..39),
             ms80-r12   INTEGER(0..79),
             ms160-r12  INTEGER(0..159),
             ...
        },
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_DMTC_PERIOD_ENUM
{
    LRRC_LPHY_DMTC_PERIOD_40MS        = 0,
    LRRC_LPHY_DMTC_PERIOD_80MS        = 1,
    LRRC_LPHY_DMTC_PERIOD_160MS       = 2,
    LRRC_LPHY_DMTC_PERIOD_TYPE_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_DMTC_PERIOD_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CDM_TYPE_ENUM
 Э����  :
 ASN.1���� : cdmType-r13 ENUMERATED {cdm2, cdm4}
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_CDM_TYPE_ENUM
{
    LRRC_LPHY_CDM_2                 = 0,
    LRRC_LPHY_CDM_4                 = 1,
    LRRC_LPHY_CDM_TYPE_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_CDM_TYPE_ENUM_UINT8;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_EMIMO_TYPE_ENUM
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_CSI_RS_EMIMO_TYPE_ENUM
{
    LRRC_LPHY_CSI_RS_EMIMO_NON_PRECODE  = 0,
    LRRC_LPHY_CSI_RS_EMIMO_BM_FRM       = 1,
    LRRC_LPHY_CSI_RS_EMIMO_TYPE_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_CSI_RS_EMIMO_TYPE_ENUM_UINT8;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CBSR_TYPE_ENUM_UINT8
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_CBSR_TYPE_ENUM
{
    LRRC_LPHY_CBSR_NON_PRCDE            = 0,
    LRRC_LPHY_CBSR_BM_FRM_K1A           = 1,
    LRRC_LPHY_CBSR_BM_FRM_KN            = 2,
    LRRC_LPHY_CBSR_TYPE_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_CBSR_TYPE_ENUM_UINT8;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MPDCCH_SF_CSS_RA_ENUM_UINT16
 Э����  :
 ASN.1���� : mpdcch-startSF-CSS-RA-r13
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_MPDCCH_SF_CSS_RA_ENUM
{
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V1         = 0,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V1_DOT_5,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V2,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V2_DOC_5,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V4,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V5,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V8,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V10,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_V20,
    LRRC_LPHY_MPDCCH_SF_CSS_RA_BUTT
};
typedef VOS_UINT16   LRRC_LPHY_MPDCCH_SF_CSS_RA_ENUM_UINT16;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MPDCCH_SF_UESS_ENUM_UINT16
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_MPDCCH_SF_UESS_ENUM
{
    LRRC_LPHY_MPDCCH_SF_UESS_V1         = 0,
    LRRC_LPHY_MPDCCH_SF_UESS_V1_DOT_5,
    LRRC_LPHY_MPDCCH_SF_UESS_V2,
    LRRC_LPHY_MPDCCH_SF_UESS_V2_DOC_5,
    LRRC_LPHY_MPDCCH_SF_UESS_V4,
    LRRC_LPHY_MPDCCH_SF_UESS_V5,
    LRRC_LPHY_MPDCCH_SF_UESS_V8,
    LRRC_LPHY_MPDCCH_SF_UESS_V10,
    LRRC_LPHY_MPDCCH_SF_UESS_V20,
    LRRC_LPHY_MPDCCH_SF_UESS_BUTT
};
typedef VOS_UINT16   LRRC_LPHY_MPDCCH_SF_UESS_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_MODEB_ENUM
{
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R16  =0,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R32,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R192,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R256,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R384,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R512,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R768,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R1024,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R1536,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_R2048,
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_BUTT,
};
typedef VOS_UINT16   LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_ENUM_UINT16
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_ENUM
{
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R8,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R16,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R32,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R192,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R256,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R384,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R512,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R768,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R1024,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R1536,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_R2048,
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_BUTT,
};
typedef VOS_UINT16   LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_ENUM_UINT16
 Э����  :
 ASN.1���� : mpdcch-NumRepetition-RA-r13
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_ENUM
{
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R1,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R2,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R4,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R8,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R16,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R32,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R64,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R128,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_R256,
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_BUTT
};
typedef VOS_UINT16   LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM
{
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_N1 = 0,
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_N2,
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_N4,
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_N8,
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_N16,
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_N32,
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_ENUM
{
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_R1 = 0,
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_R2,
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_R4,
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_R8,
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_R16,
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_R32,
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_ENUM_UINT8
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_ENUM
{
    LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_DAI   = 0,
    LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_CC,
    LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_ENUM_UINT8;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_ENUM_UINT8
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_CE_MODE_ENUM
{
    LRRC_LPHY_CE_MODE_A   = 0,
    LRRC_LPHY_CE_MODE_B,
    LRRC_LPHY_CE_MODE_BUTT
};
typedef VOS_UINT8   LRRC_LPHY_CE_MODE_ENUM_UINT8;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PHR_MODE_OTHER_CG_ENUM
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
enum LRRC_LPHY_PHR_MODE_OTHER_CG_ENUM
{
    LRRC_LPHY_PHR_MODE_OTHER_CG_REAL        = 0,
    LRRC_LPHY_PHR_MODE_OTHER_CG_VIRTUAL     = 1,
    LRRC_LPHY_PHR_MODE_OTHER_CG_BUTT
};
typedef VOS_UINT8 LRRC_LPHY_PHR_MODE_OTHER_CG_ENUM_UINT8;

/* ˫LTE����˫���л����ԣ�begin */
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MODEM_START_STATE_TYPE_ENUM
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MODEM��������ö��
*****************************************************************************/
enum LRRC_LPHY_MODEM_START_STATE_TYPE_ENUM
{
    LRRC_LPHY_MODEM_START_STATE_SIGNLE             = 0, /* ��MODEM���� */
    LRRC_LPHY_MODEM_START_STATE_DOUBLE             = 1, /* ˫MODEM���� */
    LRRC_LPHY_MODEM_START_STATE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_MODEM_START_STATE_TYPE_ENUM_UINT16;
/* ˫LTE����˫���л����ԣ�end */

#endif

/*****************************************************************************
 ö����    : PS_BAND_ENUM
 ö��˵��  : ����������ͬband��NV�б�
*****************************************************************************/
#if defined (TL_PHY_ASIC_K3V5)
enum PS_BAND_ENUM
{
    PS_BAND_7,
    PS_BAND_38,
    PS_BAND_20,
    PS_BAND_40,
    PS_BAND_41,
    PS_BAND_3,
    PS_BAND_1,
    PS_BAND_5,
    PS_BAND_8,
    PS_BAND_39,
    PS_BAND_19,
    PS_BAND_21,
    PS_BAND_2,
    PS_BAND_4,
    PS_BAND_6,
    PS_BAND_9,
    PS_BAND_10,
    PS_BAND_11,
    PS_BAND_12,
    PS_BAND_13,
    PS_BAND_14,
    PS_BAND_17,
    PS_BAND_18,
    PS_BAND_22,
    PS_BAND_23,
    PS_BAND_24,
    PS_BAND_25,
    PS_BAND_26,
    PS_BAND_33,
    PS_BAND_34,
    PS_BAND_35,
    PS_BAND_36,
    PS_BAND_37,
    PS_BAND_42,
    PS_BAND_43,
    PS_BAND_28,
    PS_BAND_128,
    PS_BAND_27,
    PS_BAND_29,
    PS_BAND_30,
    PS_BAND_44,
    PS_BAND_32,
    PS_BAND_103,
    PS_BAND_104,
    PS_BAND_105,
    PS_BAND_106,
    PS_BAND_107,
    PS_BAND_108,
    PS_BAND_109,
    PS_BAND_110,
    PS_BAND_111,
    PS_BAND_112,
    PS_BAND_113,
    PS_BAND_114,
    PS_BAND_115,
    PS_BAND_116,
    PS_BAND_BUTT
};
#else
enum PS_BAND_ENUM
{
    PS_BAND_7,
    PS_BAND_38,
    PS_BAND_20,
    PS_BAND_40,
    PS_BAND_41,
    PS_BAND_3,
    PS_BAND_1,
    PS_BAND_5,
    PS_BAND_8,
    PS_BAND_39,

    PS_BAND_19,
    PS_BAND_21,

    PS_BAND_2,
    PS_BAND_4,
    PS_BAND_6,
    PS_BAND_9,
    PS_BAND_10,
    PS_BAND_11,
    PS_BAND_12,
    PS_BAND_13,
    PS_BAND_14,
    PS_BAND_17,

    PS_BAND_18,
    PS_BAND_22,
    PS_BAND_23,
    PS_BAND_24,
    PS_BAND_25,
    PS_BAND_33,
    PS_BAND_34,
    PS_BAND_35,
    PS_BAND_36,
    PS_BAND_37,

    PS_BAND_42,
    PS_BAND_43,
    PS_BAND_28,
    PS_BAND_26, /* ADDED BY DK */
    /* �Ǳ�Ƶ��begin */
    //PS_BAND_101,
/*BEGIN DTS2014041603793 c00203521 modify for B28ȫƵ������*/
    PS_BAND_128,
/*END DTS2014041603793 c00203521 modify for B28ȫƵ������*/
/* BEGIN  l00279357 modify for B140Ƶ������ */
    PS_BAND_140,
/*END   l00279357 modify for B140Ƶ������*/
    PS_BAND_29,
    PS_BAND_32,
    PS_BAND_30,
    PS_BAND_103,
    PS_BAND_104,
    PS_BAND_105,
    PS_BAND_106,
    PS_BAND_107,
    PS_BAND_108,
    PS_BAND_109,
    PS_BAND_110,
    PS_BAND_111,
    PS_BAND_112,
    PS_BAND_113,
    PS_BAND_114,
    PS_BAND_115,
    PS_BAND_116,
    /* �Ǳ�Ƶ��end */

    PS_BAND_BUTT
};
#endif
typedef VOS_UINT8 PS_BAND_ENUM_UINT8;

enum LRRC_LPHY_SWITCH_IND_TYPE_ENUM
{
    LRRC_LPHY_ANTEN_SWITCH_MSG_TYPE       = 0,
    LRRC_LPHY_SAR_REDUCTION_PRI_MSG_TYPE
};
typedef VOS_UINT16 LRRC_LPHY_SWITCH_IND_TYPE_ENUM_UNIT16;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_EUTRAN_MODE_TYPE_ENUM_UINT16
 Э����  :
 ASN.1���� :
 ö��˵��  : ��ģʱLTE��ʽ����
*****************************************************************************/
enum LRRC_LPHY_EUTRAN_MODE_TYPE_ENUM
{
    LRRC_LPHY_EUTRAN_MODE_TYPE_GUTL            = 0,                              /* GUTL */
    LRRC_LPHY_EUTRAN_MODE_TYPE_SVLTE           = 1,                              /* CL SVLTE */
    LRRC_LPHY_EUTRAN_MODE_TYPE_SRLTE           = 2,                              /* CL SRLTE */
    LRRC_LPHY_EUTRAN_MODE_TYPE_BUTT
};
typedef VOS_UINT16 LRRC_LPHY_EUTRAN_MODE_TYPE_ENUM_UINT16;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_TYPE_ENUM_UINT8
 Э����  :
 ASN.1���� :
 ö��˵��  : ��������
*****************************************************************************/
enum LRRC_LPHY_MEAS_TYPE_ENUM
{
    LRRC_LPHY_MEAS_TYPE_CONTINUOUS            = 0,                              /* �������� */
    LRRC_LPHY_MEAS_TYPE_SINGLE                = 1,                              /* ���β�����������ϱ������IND���Լ����в����ͷ� */

    LRRC_LPHY_MEAS_TYPE_BUTT
};
typedef VOS_UINT8 LRRC_LPHY_MEAS_TYPE_ENUM_UINT8;

/*sunyanjie begin*/
/*****************************************************************************
 ö����    :
 Э����  :
 ASN.1���� :
 ö��˵��  : ERROE LOG �ϱ�
*****************************************************************************/
typedef struct
{
    VOS_UINT32                     ulAckCnt;
    VOS_UINT32                     ulNackCnt;
}PUSCH_BLER_STRU;

typedef struct
{
    VOS_UINT16                     ausCWInitTotal[2];
    VOS_UINT16                     ausCWInitError[2];
    VOS_UINT16                     ausCWReTotal[2];
    VOS_UINT16                     ausCWReError[2];
}PDSCH_BLER_STRU;

typedef struct
{
    VOS_UINT32                     ulDlGrantCnt;
    VOS_UINT32                     ulUlGrantCnt;
}PDCCH_BLER_STRU;

typedef struct
{
    VOS_INT16                      sPuschTxPwr;
    VOS_INT16                      sPucchTxPwr;
    VOS_INT16                      sSrsTxPwr;
    VOS_UINT16                     usReserved;
    PUSCH_BLER_STRU                stPuschBlerCnt;
    PDSCH_BLER_STRU                stPdschBlerCnt;
    PDCCH_BLER_STRU                stPdcchBlerCnt;
}TRANS_ERROR_LOG_RPT_STRU;

typedef struct
{
    VOS_UINT32                     ulValidNum;
    TRANS_ERROR_LOG_RPT_STRU       stTransErrorLog[LRRC_LPHY_MAX_CELL_NUM];
}TRANS_ERROR_LOG_INFO_RPT_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_INFO_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                     /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                    enMsgId;           /*_H2ASN_Skip*/
    VOS_UINT16                                      usOpId;
    VOS_UINT16                                      usReserved;
    TRANS_ERROR_LOG_INFO_RPT_STRU                   stTransErrorLogInfo;
}LRRC_LPHY_ERROR_LOG_INFO_IND_STRU;

/*****************************************************************************
 �ṹ��    : RRC_PHY_NOTCH_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RRC͸��MTC NOTCH ������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                          /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgID;            /*_H2ASN_Skip*/  /* ԭ������*/
    VOS_UINT16                          usOPID;             /* ������ʶ */
    LRRC_LPHY_NOTCH_STATE_ENUM_UINT16   enStartFlag;        /* ������ʶ */
}LRRC_LPHY_NOTCH_REQ_STRU;

/*****************************************************************************
   5 STRUCT
*****************************************************************************/
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CANDIDATE_CELL_INFO_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ���顢��С������Ϣ�б����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulCellNum;
    VOS_UINT16                          ausCellId[LRRC_LPHY_MAX_CANDIDATE_CELL_NUM];
}LRRC_LPHY_CANDIDATE_CELL_INFO_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_FREQ_BAND_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Ƶ����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usLowBand;
    VOS_UINT16                          usHighBand;
}LRRC_LPHY_FREQ_BAND_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CELL_SEARCHING_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջָʾ�����С���������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                                    usOpId;                       /* ������ʶ�� */
    VOS_UINT16                                    usFreqInfo;                   /* Ƶ����Ϣ */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                enBandInd;                    /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16           enLteModeType;                /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_INT16                                     sRsrpThreshold;               /* С������������Ҫ���RSRP������� */
    LRRC_LPHY_CELL_SEARCH_TYPE_ENUM_UINT16        enUnionStructSelChoice;       /* enCellSearchType С���������� */
    union
    {
        LRRC_LPHY_CANDIDATE_CELL_INFO_LIST_STRU   stBarredCellList;             /* ��barС����Ϣ */
        LRRC_LPHY_CANDIDATE_CELL_INFO_LIST_STRU   stCandidateCellList;          /* ������Ϣ���ݽṹ */
        LRRC_LPHY_FREQ_BAND_INFO_STRU             stFreqBandInfo;               /* Ƶ����Ϣ */
    }u;
}LRRC_LPHY_CELL_SEARCHING_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CELL_SEARCHING_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����ָʾС������������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                                    usOpId;                       /* ������ʶ�� */
    LRRC_LPHY_SEARCH_CELL_RESULT_ENUM_UINT16      enValidInd;                   /* ���Ƶ���ϵ���ǿС���Ƿ���Ч */
    VOS_UINT16                                    usFreqInfo;                   /* ��������С����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                enBandInd;                    /* Ƶ��ָʾ */
    VOS_UINT16                                    usCellId;                     /* С��ID */
    VOS_INT16                                     sRsrp;                        /* RSRP����ֵ */
    VOS_INT16                                     sRsrq;                        /* RSRQ����ֵ */
    VOS_UINT16                                    usNoRfValid;                  /* DSDS����NoRFָʾ */

    VOS_UINT8                                     ucFakeCellInd;                /*��С��ָʾ,�ϱ��ļ�С��ʱΪ1 */
    VOS_UINT8                                     ucReserved[3];                /* �����ֶ� */

}LRRC_LPHY_CELL_SEARCHING_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BAND_SCAN_RESULT_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ɨƵ������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_BAND_IND_ENUM_UINT16                enBandInd;                    /* Ƶ��ָʾ */
    VOS_UINT16                                    usBandNum;                    /* ������ϱ���Band��Ŀ */
    LRRC_LPHY_FREQ_BAND_INFO_STRU                 astBandScanResult[LRRC_LPHY_MAX_SCAN_FREQ_NUM];          /* Ƶ����Ϣ */
}LRRC_LPHY_BAND_SCAN_RESULT_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BAND_SCAN_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջָʾ�����ɨƵ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                                    usOpId;                       /* ������ʶ�� */
    LRRC_LPHY_BAND_SCAN_TYPE_ENUM_UINT16          enBandScanType;               /* ɨƵ���� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                enBandInd;                    /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16           enLteModeType;                /* ָʾƵ����������ʽ����, FDD��TDD */
    LRRC_LPHY_FREQ_BAND_INFO_STRU                 stFreqBandInfo;               /* Ƶ����Ϣ */
}LRRC_LPHY_BAND_SCAN_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BAND_SCAN_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����ָʾɨƵ������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                                    usOpId;                       /* ������ʶ�� */
    VOS_UINT16                                    usNoRfValid;                  /* DSDS����NORFָʾ */
    LRRC_LPHY_BAND_SCAN_RESULT_LIST_STRU          stBandScanResult;             /* ɨƵ��� */
}LRRC_LPHY_BAND_SCAN_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_FREQ_RSSI_MEAS_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջָʾ�����ɨ��ָ���ĸ�������Ƶ��1.4M�����RSSI�ľ���Ƶ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usFreqInfo;                   /* ��������С����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                enBandInd;                    /* Ƶ��ָʾ */
    VOS_INT16                                     sRssi;                        /* RSRP����ֵ */
    VOS_UINT16                                    usHighPriFlg;
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16           enLteModeType;
    VOS_UINT16                                    usPssRatio;
}LRRC_LPHY_FREQ_RSSI_MEAS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_FREQ_RSSI_SCAN_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջָʾ�����ɨ��ָ���ĸ�������Ƶ��1.4M�����RSSI
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                                    usOpId;                       /* ������ʶ�� */
    LRRC_LPHY_LTE_BAND_WIDTH_ENUM_UINT16          enScanBandWith;
    VOS_UINT16                                    usNoRfValid;
    VOS_UINT16                                    usRsv;
    VOS_UINT32                                    ulValidNum;
    LRRC_LPHY_FREQ_RSSI_MEAS_INFO_STRU            astMeasInfo[LRRC_LPHY_FREQ_RSSI_MAX_SCAN_NUM];
}LRRC_LPHY_FREQ_RSSI_SCAN_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_TDD_CONFIG_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : TDD������Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SUBFRAME_ASSIGNMENT_ENUM_UINT16               enSa;               /* TDD-Configuration->subframeAssignment */
    LRRC_LPHY_SPECIAL_SUBFRAME_PATTERN_ENUM_UINT16          enSsp;              /* TDD-Configuration->specialSubframePatterns */
}LRRC_LPHY_TDD_CONFIG_INFO_STRU;

/*Ѱ����������begin*/
/*********************************************************************
* ASN �ı� :S-TMSI
*********************************************************************/
typedef struct
{
    VOS_UINT8                     ucMmec;
    VOS_UINT8                     aucRev[3];
    VOS_UINT32                    ulMTmsi;
}LRRC_LPHY_S_TMSI_STRU;

/*********************************************************************
* ASN �ı� :IMSI
*********************************************************************/
typedef struct
{
    VOS_UINT16                    usCnt;    /*(0, 6..UU_MAX_NUM_OF_IMSI_DSP)*/
    VOS_UINT8                     aucItem[LRRC_LPHY_MAX_NUM_OF_IMSI_DSP];
    VOS_UINT8                     ucRev;
}LRRC_LPHY_IMSI_STRU;

/*********************************************************************
�ṹ��    : PAGING_UE_ID_STRU_DSP
Э����  :
ASN.1���� :
�ṹ˵��  : UE ID���ݽṹ

*********************************************************************/
typedef struct
{
    VOS_UINT8                       ucSTmsiFlag;
    VOS_UINT8                       ucImsiFlag;
    VOS_UINT8                       aucRev[2];

    LRRC_LPHY_S_TMSI_STRU           stSTmsi;
    LRRC_LPHY_IMSI_STRU             stImsi;

}LRRC_LPHY_PAGING_UE_ID_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_UE_ID_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : UE ID���ݽṹ
*****************************************************************************/

typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32     enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */

    VOS_UINT8                        ucCapAccessRel;
    VOS_UINT8                        aucRev[3];
    LRRC_LPHY_PAGING_UE_ID_STRU      stPagingUeId;

}LRRC_LPHY_PAGING_INFO_REQ_STRU;
/*Ѱ����������end*/
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CAMPED_MAINCELL_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : С��פ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usFreqInfo;                             /* С����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16 enLteModeType;                          /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                          usCellId;                               /* С��ID */
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16    enDlBandWidth;                          /* ���д���,��Ӧ�տ�MasterInformationBlock->dl-Bandwidth�ֶ� */
    LRRC_LPHY_ANTANNA_PORT_ENUM_UINT16  enAntennaPortsCount;                    /* ������������,��Ӧ�տ�antennaPortsCount�ֶ� */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
    LRRC_LPHY_TDD_CONFIG_INFO_STRU      stTddConfigInfo;                        /* TDD������Ϣ,��Ӧ�տ�TDD-Configuration�ֶ�  */
}LRRC_LPHY_CAMPED_MAINCELL_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CAMPED_MAINCELL_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : С��פ�����ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    LRRC_LPHY_RESULT_ENUM_UINT16        enResult;                               /* �����0��ʾ�ɹ���1��ʾʧ�� */
    VOS_UINT16                          usNoRfValid;
    VOS_UINT16                          usRsved;
}LRRC_LPHY_CAMPED_MAINCELL_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_UPLINK_MAXTXPWR_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����书���������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_INT16                           sMaxTxPwr;                              /* ����书�� */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
}LRRC_LPHY_UPLINK_MAXTXPWR_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PBCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : PBCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16             enPhyChannelType;            /* �����ŵ����� */
    LRRC_LPHY_CGI_ACQUISITION_METHOD_ENUM_UINT16   enAcqMethod;                 /* ָʾCGI��ȡ��ʽ,0��ʾ������CGI��ȡ,1��ʾ����AUTONOMOUS GAP,2��ʾ����IDLE PERIODS */
}LRRC_LPHY_PBCH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANTENNA_COMM_INFO_STRU
 Э����  : MobilityControlInformation->RadioResourceConfigCommon->AntennaInformationCommon
 ASN.1���� :
 �ṹ˵��  : �������������Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_ANTANNA_PORT_ENUM_UINT16    enAntennaPortsCount;                  /* ���߿����� */
    VOS_UINT16                            usReserved;
}LRRC_LPHY_ANTENNA_COMM_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANTENNA_DEDICATED_INFO_STRU
 Э����  : RadioResourceConfigDedicated->PhysicalConfigDedicated->AntennaInformationDedicated
 ASN.1���� :
 �ṹ˵��  : ר�����������Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PDSCH_TM_MODE_ENUM_UINT16   enTransmitMode;                       /* ����ģʽ */
    LRRC_LPHY_ANTENNA_SELECT_ENUM_UINT16  enAntennaSelect;                      /* UE��������ѡ��2��ʾdisable,0/1��ʾenable */
    /* Begin: 2016/1/4 cr develop */
    LRRC_LPHY_ANTENNA_MAX_LAYERS_MIMO_UINT16    usMaxLayersMIMO;                /* ָʾ���MIMO���� 0:2�� 1:4�� 2:8�� 3:butt��Ч  */
    /* End: 2016/1/4 cr develop */

    LRRC_LPHY_CODE_BOOK_TYPE_ENUM_UINT16  enCodeBookType;                       /* ָʾ��ǰʹ�õ�������Ӽ��������� */
    /* add TM9 n2/n4/n8��n8TM9�����Ҫ109BITS */
	
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enAlternativeCodebookEnabledFor4Tx;   /* ָʾcode book�Ƿ��������Ƶ�CSI�����ͱ��� */
    VOS_UINT16                            usReserved;
#endif
    VOS_UINT32                            aulCodebookSubsetRestriction[4];      /* ������Ӽ�����,Little-Endian�ֽ��� */

}LRRC_LPHY_ANTENNA_DEDICATED_INFO_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_SUBFRAME_CFG_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Radio-frames that contain MBSFN subframes occur when equation SFN
 mod radioFrameAllocationPeriod = radioFrameAllocationOffset is satisfied.
 Value n1 for radioframeAllocationPeriod denotes value 1, n2 denotes value 2,
 and so on. When fourFrames is used for subframeAllocation, the equation defines
 the first radio frame referred to in the description below. Values n1 and n2 are
 not applicable when fourFrames is used.

 case LRRC_LPHY_MBSFN_ALLOCATION_TYPE_ONE:
 ulSfnAllocationBitmap:the lower 6 bits are used.
 "1" denotes that the corresponding subframe is allocated for MBSFN.
 The following mapping applies:
 FDD: The first/leftmost bit defines the MBSFN allocation for subframe #1,
      the second bit for #2, third bit for #3 , fourth bit for #6, fifth bit for #7, sixth bit for #8.
 TDD: The first/leftmost bit defines the allocation for subframe #3,
      the second bit for #4, third bit for #7, fourth bit for #8, fifth bit for #9.
      Uplink subframes are not allocated. The last bit is not used.

 case LRRC_LPHY_MBSFN_ALLOCATION_TYPE_FOUR:
 ulSfnAllocationBitmap:the lower 24 bits are used.
 A bit-map indicating MBSFN subframe allocation in four consecutive radio frames,
 "1" denotes that the corresponding subframe is allocated for MBSFN.
 The bitmap is interpreted as follows:
 FDD: Starting from the first radioframe and from the first/leftmost bit in the bitmap,
      the allocation applies to subframes #1, #2, #3 , #6, #7, and #8 in the sequence of the four radio-frames.
 TDD: Starting from the first radioframe and from the first/leftmost bit in the bitmap,
      the allocation applies to subframes #3, #4, #7, #8, and #9 in the sequence of the four radio-frames.
      The last four bits are not used. Uplink subframes are not allocated
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_MBSFN_ALLOCATION_PERIOD_ENUM_UINT16  enRfAllocationPeriod;        /* MBSFN ����֡�������� */
    VOS_UINT16                                     usRfAllocationOffset;        /* MBSFN ����֡����ƫ�� */
    VOS_UINT16                                     usReserved;
    LRRC_LPHY_MBSFN_ALLOCATION_TYPE_ENUM_UINT16    enRfAllocationType;          /* MBSFN ����֡�������� */
    VOS_UINT32                                     ulSfnAllocationBitmap;       /* MBSFN ��֡����Bitmap,ָʾ��Ӧ��֡�Ƿ񱻷��䣬1:��ʾ����֡������,0:��ʾδ������ */
}LRRC_LPHY_MBSFN_SUBFRAME_CFG_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MBSFN����֡����֡Ԥ����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16         enMbsfnCfgEnabled;                /* ����ָʾMBSFN�����Ƿ���Ч */
    VOS_UINT16                                usCnt;
    LRRC_LPHY_MBSFN_SUBFRAME_CFG_INFO_STRU    stSubframecfg[LRRC_LPHY_MAX_MBSFN_ALLOCATIONS_NUM];
}LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_COMM_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����PDSCH��Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PDSCH_PA_ENUM_UINT16          enP_A;                              /* ����PDSCH���书����Ϣ,Ĭ��ֵΪ0 */
    LRRC_LPHY_PDSCH_PB_ENUM_UINT16          enP_B;                              /* PDSCH��Դ��ƫ��,Ĭ��ֵΪ0 */
    VOS_INT16                               sRefSignalPwr;                      /* �ο��źŹ��� */
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16        enDlBandWidth;                      /* ���д���,��Ӧ�տ�MasterInformationBlock->dl-Bandwidth�ֶ� */
    LRRC_LPHY_PHICH_DURATION_ENUM_UINT16    enPhichDuration;                    /* PHICH-DURATION */
    LRRC_LPHY_PHICH_RESOURCE_ENUM_UINT16    enPhichResOurce;                    /* PHICH-RESOURCE */
    LRRC_LPHY_TDD_CONFIG_INFO_STRU          stTddConfigInfo;                    /* TDD������Ϣ,��Ӧ�տ�TDD-Configuration�ֶ�  */
    LRRC_LPHY_ANTENNA_COMM_INFO_STRU        stAntennaCommInfo;                  /* ����������Ϣ */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enRpttnCeModeAFlag;                 /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_ENUM_UINT16  enPdschMaxNumRpttnCeModeA;    /* pdsch-maxNumRepetitionCEmodeA-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enRpttnCeModeBFlag;                 /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_PDSCH_MAX_NUM_RPTTN_CE_ENUM_UINT16  enPdschMaxNumRpttnCeModeB;    /* pdsch-maxNumRepetitionCEmodeB-r13 */
#endif
}LRRC_LPHY_PDSCH_COMM_INFO_STRU;

#if (FEATURE_ON == FEATURE_LTE_R11)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DMRS_CONFIG_STRU
 Э����  : DMRS-Config-r11
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                               usScramblingId;                    /* scramblingIdentity-r11		INTEGER (0..503) */
    VOS_UINT16                               usScramblingId2;                   /* scramblingIdentity2-r11		INTEGER (0..503) */
#if (FEATURE_ON == FEATURE_LTE_R13)
    /* dmrs-tableAlt-r13, The field indicates whether to use an alternative table for DMRS upon PDSCH transmission, see TS 36.213 [23].  0:no use; 1:use */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enDmrsTblAlt;
    VOS_UINT16                              usReserved;
#endif
}LRRC_LPHY_DMRS_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OPTIONAL_SET_OF_FIELDS_STRU
 Э����  : optionalSetOfFields-r11
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CRS_PORTS_COUNT_ENUM_UINT16   enCRSPortsCount;                    /* crs-PortsCount-r11 */
    VOS_UINT16                              usCRSFreqShift;                     /* crs-FreqShift-r11 */
    LRRC_LPHY_PDSCH_START_ENUM_UINT16       enPdschStart;                       /* pdsch-Start-r11 */
    VOS_UINT16                              usReserved;

    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU  stMbsfnCfgInfo;                     /* mbsfn-SubframeConfigList-r11 --Need ON */
}LRRC_LPHY_OPTIONAL_SET_OF_FIELDS_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RE_MAP_QCL_CONFIG_STRU
 Э����  : PDSCH-RE-MappingQCL-Config-r11
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usPdschReMapQclConfigId;            /* pdsch-RE-MappingQCL-ConfigId-r11 INTEGER (1..maxRE-MapQCL-r11) */
    VOS_UINT16                              usCsiRSConfigZPId;                  /* csi-RS-ConfigZPId-r11 INTEGER (1..maxCSI-RS-ZP-r11) */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enCsiRSConfigNZPIdEnabled;          /* qcl-CSI-RS-ConfigNZPId-r11������Ч��ʶ */
    VOS_UINT16                              usCsiRSConfigNZPId;                 /* qcl-CSI-RS-ConfigNZPId-r11 --Need OR INTEGER (1..maxCSI-RS-NZP-r11) */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enOptionalSetOfFieldsFlag;          /* optionalSetOfFields-r11������Ч��ʶ */
    VOS_UINT16                              usReserved;

    LRRC_LPHY_OPTIONAL_SET_OF_FIELDS_STRU   stOptionalSetOfFields;              /* optionalSetOfFields-r11 --Need OP */
}LRRC_LPHY_RE_MAP_QCL_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RE_MAP_QCL_CONFIG_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usPdschReMapQclConfigNum;           /* pdsch-RE-MappingQCL-ConfigId-r11����  (1..maxRE-MapQCL-r11) */
    VOS_UINT16                              usReserved;
    LRRC_LPHY_RE_MAP_QCL_CONFIG_STRU        astPdschReMapQclConfig[LRRC_LPHY_MAX_RE_MAP_QCL_NUM];
}LRRC_LPHY_RE_MAP_QCL_CONFIG_LIST_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_DEDICATED_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ר��PDSCH��Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enDMRSConfigEnabled;                /* stDMRSConfigPdsch������Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enQclOperationEnabled;              /* qcl-Opration������Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enReMapQclConfigEnabled;            /* PDSCH-RE-MappingQCL-Config-r11������Ч��ʶ */

    LRRC_LPHY_QCL_OPERATION_ENUM_UINT16     enQclOperation;                     /* qcl-Opration */
    LRRC_LPHY_DMRS_CONFIG_STRU              stDMRSConfigPdsch;                  /* dmrs-ConfigPDSCH-r11 */
    LRRC_LPHY_RE_MAP_QCL_CONFIG_LIST_STRU   stReMapQclConfig;                   /* PDSCH-RE-MappingQCL-Config-r11 */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enTbsIndexAltValidFlg;
    LRRC_LPHY_TBS_INDEX_ALT_ENUM_UINT16     enTbsIndexAlt;                      /* tbsIndexAlt-r12 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enCeModeValidFlg;                   /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_CE_MODE_ENUM_UINT8            enCeMode;
    VOS_UINT8                               aucRsv[1];                          /* ce-Mode-r13 */
#endif
}LRRC_LPHY_PDSCH_DEDICATED_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_QCL_CRS_INFO_STRU
 Э����  : qcl-CRS-Info-r11
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usQclScramblingId;                  /* qcl-ScramblingIdentity-r11 (0..503) */
    LRRC_LPHY_CRS_PORTS_COUNT_ENUM_UINT16   enCRSPortsCount;                    /* crs-PortsCount-r11 */

    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU  stMbsfnCfgInfo;                     /* mbsfn-SubframeConfigList-r11 --Need ON */
}LRRC_LPHY_QCL_CRS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_CONFIG_NZP_INFO_STRU
 Э����  : CSI-RS-ConfigNZP-r11
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usCsiRSConfigNZPId;         /* csi-RS-ConfigNZPId-r11 INTEGER (1..maxCSI-RS-NZP-r11) */
    LRRC_LPHY_ANTANNA_PORT_ENUM_UINT16              enAntennaPortsCountR11;     /* antennaPortsCount-r11 */
    VOS_UINT16                                      usResourceConfig;           /* resourceConfig-r11 (0..31)*/
    VOS_UINT16                                      usSubframeConfig;           /* subframeConfig-r11 (0..154) */
    VOS_UINT16                                      usScramblingId;             /* scramblingIdentity-r11 (0..503) */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enQclCRSInfoFlag;           /* stQclCRSInfo������Ч��ʶ */

    LRRC_LPHY_QCL_CRS_INFO_STRU                     stQclCRSInfo;               /* qcl-CRS-Info-r11 -- Need ON */
}LRRC_LPHY_CSI_RS_CONFIG_NZP_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_CONFIG_NZP_INFO_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usCsiRSConfigNZPNum;                /* CSI-RS-ConfigNZP-r11���� */
    VOS_UINT16                              usReserved;
    LRRC_LPHY_CSI_RS_CONFIG_NZP_INFO_STRU   astCsiRSConfigNZP[LRRC_LPHY_MAX_CSI_RS_NZP_NUM];
}LRRC_LPHY_CSI_RS_CONFIG_NZP_INFO_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_CONFIG_ZP_INFO_STRU
 Э����  : CSI-RS-ConfigZP-r11
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usCsiRSConfigZPId;                  /* csi-RS-ConfigZPId-r11 INTEGER (1..maxCSI-RS-ZP-r11) */
    VOS_UINT16                              usResourceConfigList;               /* resourceConfigList-r11 BIT STRING (SIZE (16))*/
    VOS_UINT16                              usSubframeConfig;                   /* subframeConfig-r11 (0..154) */
    VOS_UINT16                              usReserved;
}LRRC_LPHY_CSI_RS_CONFIG_ZP_INFO_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_CONFIG_ZP_INFO_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usCsiRSConfigZPNum;                 /* CSI-RS-ConfigZP-r11���� */
    VOS_UINT16                              usReserved;
    LRRC_LPHY_CSI_RS_CONFIG_ZP_INFO_STRU    astCsiRSConfigZP[LRRC_LPHY_MAX_CSI_RS_ZP_NUM];
}LRRC_LPHY_CSI_RS_CONFIG_ZP_INFO_LIST_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_BCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��㲥��PDSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16             enPhyChannelType;            /* �����ŵ����� */
    LRRC_LPHY_CGI_ACQUISITION_METHOD_ENUM_UINT16   enAcqMethod;                 /*ָʾCGI��ȡ��ʽ��0��ʾ������CGA��ȡ��1��ʾ����AUTONOMOUS,2��ʾ����IDLE PERIODS*/
    LRRC_LPHY_PDSCH_COMM_INFO_STRU                 stPdschCommInfo;             /* PDSCH������Ϣ */
}LRRC_LPHY_PDSCH_BCH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_IDLE_DRX_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : IDLE״̬��DRX�������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DRX_PAGE_T_ENUM_UINT16      enPaging_DRX_T;                       /* Ѱ������ */
    LRRC_LPHY_DRX_PAGE_TYPE_ENUM_UINT16   enPaging_Group_Count;                 /* Ѱ������� */
    VOS_UINT16                            usUeId;                               /* UE ID */
    VOS_UINT16                            usReserved;
}LRRC_LPHY_IDLE_DRX_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_PCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��Ѱ����PDSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16    enPhyChannelType;                     /* �����ŵ����� */
    VOS_UINT16                            usReserved;
    LRRC_LPHY_PDSCH_COMM_INFO_STRU        stPdschCommInfo;                      /* PDSCH������Ϣ */
    LRRC_LPHY_IDLE_DRX_INFO_STRU          stIdleDrxInfo;                        /* IDLE̬�µ�DRX���� */
}LRRC_LPHY_PDSCH_PCH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_RACH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����������Ӧ��PDSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef LRRC_LPHY_PDSCH_BCH_PARA_STRU LRRC_LPHY_PDSCH_RACH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_N1_PUCCH_AN_PERSISTENT_LIST_STRU
 Э����  : SPS-Configuration->SPS-ConfigurationDL->setup->n1-PUCCH-AN-PersistentList
 ASN.1���� :
 �ṹ˵��  : N1_PUCCH_AN_PERSISTENT�б�
*****************************************************************************/
typedef struct
{
    VOS_UINT16               usReserved;
    VOS_UINT16               usCnt;                                             /*(1..4)*/
    VOS_UINT16               ausItem[LRRC_LPHY_MAX_N1_PUCCH_AN_PERSISTENT_NUM]; /* n1Pucch-AN-Persistent:INTEGER (0..2047) */
}LRRC_LPHY_N1_PUCCH_AN_PERSISTENT_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SPS_CONFIG_DL_STRU
 Э����  : RadioResourceConfigDedicated->SPS-Configuration->SPS-ConfigurationDL
 ASN.1���� :
 �ṹ˵��  : SPS-ConfigurationDL
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_ENUM_UINT16    enDlPersistSchedInterval;   /* semiPersistSchedIntervalDL */
    VOS_UINT16                                      usNumOfSpsProcess;          /* numberOfConfSPS-Processes */
    LRRC_LPHY_N1_PUCCH_AN_PERSISTENT_LIST_STRU      stN1Pucch_An_PersistentList;/* n1-PUCCH-AN-PersistentList */
    LRRC_LPHY_N1_PUCCH_AN_PERSISTENT_LIST_STRU      stN1Pucch_An_PersistentListP1;/* n1PUCCH-AN-PersistentListP1-r10 */
}LRRC_LPHY_SPS_CONFIG_DL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU���ݽṹ
             aulSFCfgBitStr[0]: bit0��ʾ���λ��
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SUBFRAME_PATTERN_TYPE_ENUM_UINT16   enSFPatternType;
    VOS_UINT16                                    usReserved;
    VOS_UINT32                                    aulSFCfgBitStr[3];
}LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_RS_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CSI_ANTANNA_PORT_ENUM_UINT16        enAntennaPortsCount;          /* antennaPortsCount-r10 */
    VOS_UINT16                                    usResourceConfig;             /* resourceConfig-r10 */
    VOS_UINT16                                    usSubFrameConfig;             /* subframeConfig-r10 */
    VOS_INT16                                     sPC;                          /* p-C-r10 */
}LRRC_LPHY_CSI_RS_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ZERO_TX_POWER_CSI_RS_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ZERO_TX_POWER_CSI_RS_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usZeroTxPowerResCfgList;      /* zeroTxPowerResourceConfigList-r10 */
    VOS_UINT16                                    usZeroTxPowerSfCfg;           /* zeroTxPowerSubframeConfig-r10 */
}LRRC_LPHY_ZERO_TX_POWER_CSI_RS_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPRT_APRDC_PROC_TRIG_BIT_STRU
 Э����  :
 ASN.1���� : CQI-ReportAperiodicProc-v1310
 �ṹ˵��  : LRRC_LPHY_CQI_RPRT_APRDC_PROC_TRIG_BIT_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                      bitTrig001:1;               /* trigger001-r13 */
    VOS_UINT32                                      bitTrig010:1;               /* trigger010-r13 */
    VOS_UINT32                                      bitTrig011:1;
    VOS_UINT32                                      bitTrig100:1;
    VOS_UINT32                                      bitTrig101:1;
    VOS_UINT32                                      bitTrig110:1;
    VOS_UINT32                                      bitTrig111:1;
    VOS_UINT32                                      bitSpare:25;
}LRRC_LPHY_CQI_RPRT_APRDC_PROC_TRIG_BIT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_IM_ID_LIST_STRU
 Э����  :
 ASN.1���� : csi-IM-ConfigIdList-r13 SEQUENCE (SIZE (1..8)) OF CSI-IM-ConfigId-r13
 �ṹ˵��  : LRRC_LPHY_CSI_IM_ID_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucNum;
    VOS_UINT8                                       aucRsv[3];
    VOS_UINT8                                       aucCsiImCfgId[LRRC_LPHY_MAX_CSI_IM_NUM];                  /* CSI-IM-ConfigId-r13 */
}LRRC_LPHY_CSI_IM_ID_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NZP_RS_CFG_LIST_STRU
 Э����  :
 ASN.1���� : nzp-resourceConfigList-r13 SEQUENCE (SIZE (1..2)) OF NZP-ResourceConfig-r13
 �ṹ˵��  : LRRC_LPHY_NZP_RS_CFG_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucNum;
    VOS_UINT8                                       aucRsv[1];
    VOS_UINT8                                       aucRsCfg[LRRC_LPHY_MAX_NZP_RS_NUM]; /* ResourceConfig-r13 ::=INTEGER (0..31) */
}LRRC_LPHY_NZP_RS_CFG_LIST_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_CFG_NZP_EMIMO_STRU
 Э����  :
 ASN.1���� : CSI-RS-ConfigNZP-EMIMO-r13
 �ṹ˵��  : LRRC_LPHY_CSI_RS_CFG_NZP_EMIMO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_NZP_RS_CFG_LIST_STRU                  stNzpRsCfgList;             /* nzp-resourceConfigList-r13 */
    LRRC_LPHY_CDM_TYPE_ENUM_UINT8                   enCmdType;                  /* cdmType-r13 */
    VOS_UINT8                                       aucRsv[3];
}LRRC_LPHY_CSI_RS_CFG_NZP_EMIMO_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : nonPrecoded-r13
 �ṹ˵��  : ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       aucCdbkSbstRstrctn1[65];    /* codebookSubsetRestriction1-r13 ,36.213,���65byte*/
    VOS_UINT8                                       aucCdbkSbstRstrctn2[7];     /* codebookSubsetRestriction2-r13, 36.213,���56bit */
}LRRC_LPHY_CBSR_NON_PRCDE_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : beamformedK1a-r13
 �ṹ˵��  : ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       aucCdbkSbstRstrctn3[8];     /* codebookSubsetRestriction3-r13 36.213,���60bit*/
}LRRC_LPHY_CBSR_BM_FRM_K1A_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : beamformedKN-r13
 �ṹ˵��  : ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       aucCdbkSbstRstrctn[16];     /* codebookSubsetRestriction-r13 36.213,���109bit*/
}LRRC_LPHY_CBSR_BM_FRM_KN_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_P_C_AND_CBSR_R13_STRU
 Э����  :
 ASN.1���� : P-C-AndCBSR-PerResourceConfig-r13 ::=SEQUENCE (SIZE (1..2)) OF P-C-AndCBSR-r13
 �ṹ˵��  : LRRC_LPHY_P_C_AND_CBSR_R13_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                                       sPC;                        /* p-C-r13 INTEGER (-8..15), */
    VOS_UINT8                                       aucRsv[1];
    LRRC_LPHY_CBSR_TYPE_ENUM_UINT8                  enUnionStructSelChoice;
    union
    {
        LRRC_LPHY_CBSR_NON_PRCDE_STRU               stCbsrNonPrcde;
        LRRC_LPHY_CBSR_BM_FRM_K1A_STRU              stCbsrBmFrmK1a;
        LRRC_LPHY_CBSR_BM_FRM_KN_STRU               stCbsrBmFrmKn;
    }u;
}LRRC_LPHY_P_C_AND_CBSR_R13_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_CFG_NZP_ID_LIST_STRU
 Э����  :
 ASN.1���� : csi-RS-ConfigNZPIdListExt-r13 SEQUENCE (SIZE (1..7)) OF CSI-RS-ConfigNZPId-r13
 �ṹ˵��  : LRRC_LPHY_CSI_CFG_NZP_ID_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucNum;
    VOS_UINT8                                       aucNzpId[LRRC_LPHY_MAX_NZP_ID_NUM];
}LRRC_LPHY_CSI_CFG_NZP_ID_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_P_C_AND_CBSR_LIST_R13_STRU
 Э����  :
 ASN.1���� : P-C-AndCBSR-PerResourceConfig-r13 ::=SEQUENCE (SIZE (1..2)) OF P-C-AndCBSR-r13
 �ṹ˵��  : LRRC_LPHY_PC_CBSR_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       aucRsv[3];
    VOS_UINT8                                       ucNum;
    LRRC_LPHY_P_C_AND_CBSR_R13_STRU                 astPcCbsr[LRRC_LPHY_MAX_PC_CBSR_NUM];
}LRRC_LPHY_P_C_AND_CBSR_LIST_R13_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_BM_FRM_STRU
 Э����  :
 ASN.1���� : CSI-RS-ConfigBeamformed-r13
 �ṹ˵��  : LRRC_LPHY_CSI_RS_BM_FRM_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                      bitCsiCfgNzpIdLstPrsnt:1;
    VOS_UINT32                                      bitCsiImCfgIdLstPrsnt:1;
    VOS_UINT32                                      bitSpare:30;

    LRRC_LPHY_CSI_CFG_NZP_ID_LIST_STRU              stCsiCfgNzpIdLst;           /* csi-RS-ConfigNZPIdListExt-r13 */
    LRRC_LPHY_CSI_IM_ID_LIST_STRU                   stCsiImCfgIdLst;            /* csi-IM-ConfigIdList-r13 */

    VOS_UINT8                                       ucPcCbsrNum;
    VOS_UINT8                                       ucAceFor4TxNum;
    VOS_UINT8                                       aucRsv[2];
    LRRC_LPHY_P_C_AND_CBSR_LIST_R13_STRU            astPcCbsrPerRsCfg[LRRC_LPHY_MAX_P_C_AND_CBSR_PER_RS_CFG_NUM];/* p-C-AndCBSR-PerResourceConfigList-r13 SEQUENCE (SIZE (1..8)) OF P-C-AndCBSR-PerResourceConfig-r13 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               aenAceFor4TxPerRsCfg[LRRC_LPHY_MAX_ACE_FOR_4TX_NUM];/* ace-For4Tx-PerResourceConfigList-r13 */

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enAltCdBkEnblBmFrmd;        /* alternativeCodebookEnabledBeamformed-r13 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enChnnlMeasRstrctn;         /* channelMeasRestriction-r13 */
    VOS_UINT16                                      usRsv1;
}LRRC_LPHY_CSI_RS_BM_FRM_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_NON_PRCDE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_RS_NON_PRCDE_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                      bitPcAndCbsrPrsnt:1;
    VOS_UINT32                                      bitCodeOverSampRateCfg1Prsnt:1;
    VOS_UINT32                                      bitCodeOverSampRateCfg2Prsnt:1;
    VOS_UINT32                                      bitCsiImIdLstPrsnt:1;
    VOS_UINT32                                      bitCsiRsCfgNzpEmimoPrsnt:1;
    VOS_UINT32                                      bitSpare:27;

    LRRC_LPHY_P_C_AND_CBSR_LIST_R13_STRU            stPcCbsrList;               /* P-C-AndCBSR-PerResourceConfig-r13 */
    VOS_UINT8                                       ucCodeBookCfgN1;            /* codebookConfigN1-r13,��Χ{1,2,3,4,8} */
    VOS_UINT8                                       ucCodeBookCfgN2;            /* codebookConfigN2-r13,��Χ{1,2,3,4,8} */
    VOS_UINT8                                       ucCodeOverSampRateCfg1;     /* codebookOverSamplingRateConfig-O1-r13 */
    VOS_UINT8                                       ucCodeOverSampRateCfg2;     /* codebookOverSamplingRateConfig-O2-r13 */
    VOS_UINT8                                       ucCodeBookCfg;              /* codebookConfig-r13 */
    VOS_UINT8                                       aucRsv[3];
    LRRC_LPHY_CSI_IM_ID_LIST_STRU                   stCsiImCfgIdList;           /* csi-IM-ConfigIdList-r13 */
    LRRC_LPHY_CSI_RS_CFG_NZP_EMIMO_STRU             stCsiRsCfgNzpEmimo;         /* csi-RS-ConfigNZP-EMIMO-r13 */
}LRRC_LPHY_CSI_RS_NON_PRCDE_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DS_ZTP_CSI_RS_CONFIG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_DS_ZTP_CSI_RS_CONFIG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usCount;
    VOS_UINT8                                     aucReserved[2];
    LRRC_LPHY_ZERO_TX_POWER_CSI_RS_STRU           astZeroTxPowerCsiRS[LRRC_LPHY_MAX_NUM_OF_DS_ZTP_CSI_RS];  /* ZeroTxPowerCSI-RS-r12 */

}LRRC_LPHY_DS_ZTP_CSI_RS_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_EMIMO_STRU
 Э����  : eMIMO-Type-r13  CSI-RS-ConfigEMIMO-r13
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_RS_EMIMO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       aucRsv[3];
    LRRC_LPHY_CSI_RS_EMIMO_TYPE_ENUM_UINT8          enUnionStructSelChoice;
    union
    {
        LRRC_LPHY_CSI_RS_NON_PRCDE_STRU             stNoPrecode;                /* CSI-RS-ConfigNonPrecoded-r13 */
        LRRC_LPHY_CSI_RS_BM_FRM_STRU                stBmFrm;                    /* CSI-RS-ConfigBeamformed-r13 */
    }u;
}LRRC_LPHY_CSI_RS_EMIMO_STRU;

#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_RS_CONFIG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_RS_CONFIG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiRSValidFlg;              /* stCsiRS�Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enZeroTxPowerCsiRSValidFlg;   /* stZeroTxPowerCsiRS�Ƿ���Ч */
    LRRC_LPHY_CSI_RS_STRU                         stCsiRS;                      /* csi-RS-r10 */
    LRRC_LPHY_ZERO_TX_POWER_CSI_RS_STRU           stZeroTxPowerCsiRS;           /* zeroTxPowerCSI-RS-r10 */

#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiRSCfgNZPInfoListFlg;     /* stCsiRSCfgNZPInfoList�Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiRSCfgZPInfoListFlg;      /* stCsiRSCfgZPInfoList�Ƿ���Ч */
    LRRC_LPHY_CSI_RS_CONFIG_NZP_INFO_LIST_STRU    stCsiRSCfgNZPInfoList;        /* csi-RS-ConfigNZPToAddModList-r11 */
    LRRC_LPHY_CSI_RS_CONFIG_ZP_INFO_LIST_STRU     stCsiRSCfgZPInfoList;         /* csi-RS-ConfigZPToAddModList-r11 */
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enZeroTxPowerCsiRS2ValidFlg;  /* stZeroTxPowerCsiRS2�Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enDsZtpCsiRsValidFlg;         /* stDsCsiRs�Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiRsEMimoValidFlg;         /* CSI-RS-Config-v1310�Ƿ���Ч, BostonĬ�ϲ�֧��  */
    VOS_UINT16                                    usRsv;

    LRRC_LPHY_ZERO_TX_POWER_CSI_RS_STRU           stZeroTxPowerCsiRS2;          /* zeroTxPowerCSI-RS2-r12 */
    LRRC_LPHY_DS_ZTP_CSI_RS_CONFIG_STRU           stDsZtpCsiRs;                 /* ds-ZeroTxPowerCSI-RS-r12 */

    LRRC_LPHY_CSI_RS_EMIMO_STRU                   stCsiRsEMimo;                 /* CSI-RS-Config-v1310 */
#endif
}LRRC_LPHY_CSI_RS_CONFIG_STRU;

#if (FEATURE_ON == FEATURE_LTE_R11)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CRS_ASSIST_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CRS_ASSIST_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usPhyCellId;                  /* physCellId-r11 */
    LRRC_LPHY_ANTANNA_PORT_ENUM_UINT16            enAntennaPortsCountR11;       /* antennaPortsCount-r11 */
    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU        stMBSFNSfCfgList;             /* mbsfn-SubframeConfigList-r11 */
}LRRC_LPHY_CRS_ASSIST_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CRS_ASSIST_INFO_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CRS_ASSIST_INFO_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                               usCellReportNum;                   /* С������ (1..maxCellReport) */
    VOS_UINT16                               usResered;
    LRRC_LPHY_CRS_ASSIST_INFO_STRU           astCRSAssistInfo[LRRC_LPHY_MAX_CELL_REPORT_NUM]; /* CRS-AssistanceInfo-r11 */
}LRRC_LPHY_CRS_ASSIST_INFO_LIST_STRU;

/*****************************************************************************
 �ṹ��    :LRRC_LPHY_RESOURCEBLOCK_ASSIGNMENT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_NUMBERPRB_PAIRS_ENUM_UINT16       enNumberPRBPairs;               /*numberPRB-Pairs-r11*/
    VOS_UINT16                                  usReserved;
    VOS_UINT16                                  usBitCnt;                       /* 4..38 ��Чbitλ*/
    VOS_UINT16                                  ausResBlockAssignment[3];       /*resourceBlockAssignment-r11*/
}LRRC_LPHY_RESOURCEBLOCK_ASSIGNMENT_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :LRRC_LPHY_MPDCCH_CFG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                  usCiNumRpttnCE;                 /* csi-NumRepetitionCE-r13 ENUMERATED {v1, v2, v4, v8, v16, v32},��ö��ת��ʵ�ʵĴ�С */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enMPdcchPdschHopCfg;            /* mpdcch -pdsch-HoppingConfig-r13 */

    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16         enLteModeType;                  /* ָʾenMPdcchStartSfUeSS��������ʽ����, FDD��TDD */
    LRRC_LPHY_MPDCCH_SF_UESS_ENUM_UINT16        enMPdcchStartSfUeSS;            /* mpdcch-StartSF-UESS-r13 */
    VOS_UINT16                                  usMPdcchNumRpttn;               /* mpdcch-NumRepetition-r13,�ѿտ�ת��ʵ�ʴ�С��1~256 */
    VOS_UINT16                                  usMPdcchNarrowBand;             /* mpdcch-Narrowband-r13,1~`6 */
}LRRC_LPHY_MPDCCH_CFG_STRU;
#endif
/*****************************************************************************
 �ṹ��    :LRRC_LPHY_EPDCCH_SET_CFG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                  usSetConfigId;                  /*SetConfigId-r11*/
    LRRC_LPHY_TRANSMISSION_TYPE_ENUM_UINT16     enTransmissionType;             /*transmissionType-r11*/
    LRRC_LPHY_RESOURCEBLOCK_ASSIGNMENT_STRU     stResBlockAssignment;           /*resourceBlockAssignment-r11*/
    VOS_UINT16                                  usDmrsScramblingSequenceInt;    /*dmrs-ScramblingSequenceInt-r11 INTEGER (0..503)*/
    VOS_UINT16                                  usPucchResStartOffset;          /*pucch-ResourceStartOffset-r11 INTEGER (0..2047)*/
    VOS_UINT16                                  usReMappingQCLConfigId;         /*��ѡ�� re-MappingQCL-ConfigId-r11 0xFFFF��ʶ��Ч */
    VOS_UINT16                                  usReserved;

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enCsiRsCfgZpidValidFlg;         /* ָʾucCsiRsCfgZpid�Ƿ���Ч */
    VOS_UINT8                                   ucCsiRsCfgZpid;                 /* maxCSI-RS-ZP-r11 (1..4) */
    VOS_UINT8                                   aucReserved[3];

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enMPdcchValidFlg;               /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_MPDCCH_CFG_STRU                   stMPdcchCfg;                    /* mpdcch-config-r13 */
#endif

}LRRC_LPHY_EPDCCH_SET_CFG_STRU;

/*****************************************************************************
 �ṹ��    :LRRC_LPHY_EPDCCH_SET_CFG_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usEpdcchSetCfgNum;                  /*ָʾSetConfigList��Ŀ*/
    VOS_UINT16                              usReserved;                         /*��ѡ�� ���� ����*/

    LRRC_LPHY_EPDCCH_SET_CFG_STRU           astEpdcchSetCfgList[LRRC_LPHY_MAX_RE_MAP_QCL_NUM];     /*��ѡ��EPDCCH-SetConfigToAddModList*/
}LRRC_LPHY_EPDCCH_SET_CFG_LIST_STRU;

/*****************************************************************************
 �ṹ��    :LRRC_LPHY_EPDCCH_CONFIG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enSfPatternCfgEnabled;              /*SfPatternCfg������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enEpdcchSetCfgListFlag;             /*ָʾstEpdcchSetCfgList�Ƿ���Ч*/
    VOS_UINT16                              usStartSymbol;                      /*��ѡ�� startSymbol-r11 INTEGER (1..4) 0xFFFFָʾ��Чֵ */
    VOS_UINT16                              usReserved;

    LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU    stSfPatternCfg;                     /*��ѡ�� subframePatternConfig-r11*/
    LRRC_LPHY_EPDCCH_SET_CFG_LIST_STRU      stEpdcchSetCfgList;                 /*��ѡ��EPDCCH-SetConfigToAddModList*/
}LRRC_LPHY_EPDCCH_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_R11_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM_UINT16 enDeltaTxDOffsetPucchFormat1bCS; /* deltaTxD-OffsetPUCCH-Format1bCS-r11 */
    VOS_UINT16                                  usReserved;
}LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_R11_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_N_PUCCH_PARAM_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usNPucchId;                 /* nPUCCH-Identity-r11 INTEGER (0..503) */
    VOS_UINT16                                      usN1PucchAN;                /* n1PUCCH-AN-r11 INTEGER (0..2047)*/
}LRRC_LPHY_N_PUCCH_PARAM_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_DMRS_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usNPucchId;                 /* nPUSCH-Identity-r11    INTEGER (0..509) */
    VOS_UINT16                                      usNDmrsCshId;               /* nDMRS-CSH-Identity-r11 INTEGER (0..509) */
}LRRC_LPHY_PUSCH_DMRS_STRU;
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 EIMTA-MainConfig-r12 ::=    CHOICE {
     release                         NULL,
     setup                           SEQUENCE {
         eimta-RNTI-r12              C-RNTI,
         eimta-CommandPeriodicity-r12    ENUMERATED {sf10, sf20, sf40, sf80},
         eimta-CommandSubframeSet-r12    BIT STRING (SIZE(10))
     }
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_EIMTA_CMD_PERIOD_ENUM_UINT8   enEimtaCmdPeriod;
    VOS_UINT8                               aucRsv[3];
    VOS_UINT16                              usEimtaRnti;
    VOS_UINT16                              usEimtaCmdSubframeSet;           /* BIT STRING (SIZE(10)) */
}LRRC_LPHY_EIMTA_MAIN_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 EIMTA-MainConfigServCell-r12 ::=    CHOICE {
     release                             NULL,
     setup                               SEQUENCE {
         eimta-UL-DL-ConfigIndex-r12             INTEGER (1..5),
         eimta-HARQ-ReferenceConfig-r12      ENUMERATED {sa2,sa4,sa5},
         mbsfn-SubframeConfigList-v1250      CHOICE {
                 release                             NULL,
                 setup                               SEQUENCE {
                 subframeConfigList-r12              MBSFN-SubframeConfigList
                 }
         }
     }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                   ucEimtaUlDlCfgIndex;       /*(1..5)*/
    LRRC_LPHY_EIMTA_HARQ_REF_CONFIG_ENUM_UINT8  enEimtaHarqRefCfg;
    VOS_UINT8                                   aucRsv[2];
    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU      stMbsfnSubframeCfgList;    /* �˲�����SIB2�е�MBSFN SF CFG��Э�������� */
}LRRC_LPHY_EIMTA_MAIN_CONFIG_SERV_CELL_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NEIGH_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_NEIGH_CELL_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usPhyCellId;
    LRRC_LPHY_PDSCH_PB_ENUM_UINT16          enPB;                               /* p-b-r12 INTEGER (0..3), */
    LRRC_LPHY_CRS_PORTS_COUNT_ENUM_UINT16   enCRSPortsCount;

    VOS_UINT16                              usRsv;
    VOS_UINT16                              usPaNum;
    LRRC_LPHY_PDSCH_PA_ENUM_UINT16          aenPA[LRRC_LPHY_MAX_PA_PER_NEIGH_CELL];/* p-aList-r12 */
    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU  stMbsfnCfgInfo;                     /* mbsfn-SubframeConfig-r12 MBSFN-SubframeConfigList OPTIONAL,- Need ON */
    VOS_UINT16                              usTMList;                           /* transmissionModeList-r12 */
    VOS_UINT16                              usResAllcGrnlrt;                    /* resAllocGranularity-r12 */
}LRRC_LPHY_NEIGH_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NAICS_ASSIST_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_NAICS_ASSIST_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enServCellPaValidFlg;
    LRRC_LPHY_PDSCH_PA_ENUM_UINT16          enServCellPA;           /* servCellp-a-r12 */
    VOS_UINT8                               ucNeighCellNum;
    VOS_UINT8                               aucRsv[3];
    LRRC_LPHY_NEIGH_CELL_INFO_STRU          astNeighCellInfo[LRRC_LPHY_NAICS_MAX_NEIGH_CELL_NUM];
}LRRC_LPHY_NAICS_ASSIST_INFO_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : PDCCH-CandidateReductions-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{

    VOS_UINT16                                      usPdcchCndRdctnAL1;         /* pdcch-candidateReductionAL */
    VOS_UINT16                                      usPdcchCndRdctnAL2;
    VOS_UINT16                                      usPdcchCndRdctnAL3;
    VOS_UINT16                                      usPdcchCndRdctnAL4;
    VOS_UINT16                                      usPdcchCndRdctnAL5;
    VOS_UINT16                                      usRsv;
}LRRC_LPHY_PDCCH_CAND_REDUCT_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : FreqHoppingParameters-r1 3
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usMPdcchPdschHopNb;         /*mpdcch-pdsch-HoppingNB-r13 */
    VOS_UINT16                                      usIntvlDlHopCfgCmmCModeA;   /* interval-DLHoppingConfigCommonModeA-r13 */
    VOS_UINT16                                      usIntvlDlHopCfgCmmCModeB;   /* interval-DLHoppingConfigCommonModeB-r13 */
    VOS_UINT16                                      usIntvlUlHopCfgCmmCModeA;   /* interval-ULHoppingConfigCommonModeA-r13 */
    VOS_UINT16                                      usIntvlUlHopCfgCmmCModeB;   /* interval-ULHoppingConfigCommonModeB-r13 */
    VOS_UINT16                                      usMPdcchPdschHopOffset;     /* mpdcch-pdsch-HoppingOffset-r13 */
}LRRC_LPHY_FREQ_HOP_PARA_STRU;

#endif


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_DSCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����ݵ�PDSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16    enPhyChannelType;                     /* �����ŵ����� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enSemiPersistSchedCRntiValidFlg;      /* ָʾsemiPersistSchedC-RNTI�Ƿ���Ч */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enSpsConfigDlEnabled;                 /* stSpsConfigDl��Ч��ʶ */
    VOS_UINT16                            usSemiPersistSchedCRnti;              /* semiPersistSchedC-RNTI */
    LRRC_LPHY_PDSCH_COMM_INFO_STRU        stPdschCommInfo;                      /* PDSCH������Ϣ */
    LRRC_LPHY_ANTENNA_DEDICATED_INFO_STRU stAntennaDedicatedInfo;               /* ר��������Ϣ */
    LRRC_LPHY_SPS_CONFIG_DL_STRU          stSpsConfigDl;                        /* SPS-ConfigurationDL */
    LRRC_LPHY_CSI_RS_CONFIG_STRU          stCsiRSConfig;                        /* csi-RS-Config-r10 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enCifPresence;                        /* cif-Presence-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enMeasSfPatternPCellValidFlg;
    LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU  stMeasSfPatternPCell;                 /* measSubframePatternPCell */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                            usReserved;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enCRSAssistInfoListEnabled;           /* stCRSAssistInfoList������Ч��ʶ */
    LRRC_LPHY_CRS_ASSIST_INFO_LIST_STRU   stCRSAssistInfoList;                  /* CRS-AssistanceInfoList-r11 */
    LRRC_LPHY_EPDCCH_CONFIG_STRU          stEPdcchConfig;                       /* EPDCCH-Config-r11 */
    LRRC_LPHY_PDSCH_DEDICATED_INFO_STRU   stPdschDedicatedInfo;                 /* pdsch-ConfigDedicated-v1130 */
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enEimtaMainCfgValidFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enEimtaMainCfgSrvCellValidFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPdcchCandReductValidFlg;            /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enFreqHopParaValidFlg;

    LRRC_LPHY_EIMTA_MAIN_CONFIG_STRU      stEimtaMainCfg;                       /* EIMTA��С�������� */
    LRRC_LPHY_EIMTA_MAIN_CONFIG_SERV_CELL_STRU  stEimtaMainCfgSrvCell;          /* EIMTA����С�������� */
    LRRC_LPHY_NAICS_ASSIST_INFO_STRU      stNaicsAssistInfo;                     /* NAICS-AssistanceInfo-r12 */
    LRRC_LPHY_PDCCH_CAND_REDUCT_STRU      stPdcchCandReduct;                    /* PDCCH-CandidateReductions-r13 */

    LRRC_LPHY_FREQ_HOP_PARA_STRU          stFreqHopPara;                        /* FreqHoppingParameters-r13 */
#endif

}LRRC_LPHY_PDSCH_DSCH_PARA_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : N1PUCCH-AN-InfoList-r13 ::= SEQUENCE (SIZE(1..maxCE-Level-r13)) OF INTEGER (0..2047)
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucNum;
    VOS_UINT8                           aucRsv[3];
    VOS_UINT16                          ausVal[LRRC_LPHY_MAX_CE_LVL_NUM];
}LRRC_LPHY_N1_PUCCH_AN_INFO_LIST_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_COMM_CE_INFO_STRU
 Э����  :
 ASN.1���� : PUCCH-ConfigCommon-v131 0
 �ṹ˵��  : ����PUCCH�����ŵ�CE�������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                  bitN1PucchAnInfoPrsnt:1;
    VOS_UINT32                                  bitPucchRpttnCeMsg4Lvl0Prsnt:1;
    VOS_UINT32                                  bitPucchRpttnCeMsg4Lvl1Prsnt:1;
    VOS_UINT32                                  bitPucchRpttnCeMsg4Lvl2Prsnt:1;
    VOS_UINT32                                  bitPucchRpttnCeMsg4Lvl3Prsnt:1;
    VOS_UINT32                                  bitSpare:27;


    LRRC_LPHY_N1_PUCCH_AN_INFO_LIST_STRU        stN1PucchAnInfoList;            /* N1PUCCH-AN-InfoList-r13 */
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8 enPucchCeMsg4Lvl0;             /* pucch-NumRepetitionCE-Msg4-Level0-r13 */
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8 enPucchCeMsg4Lvl1;             /* pucch-NumRepetitionCE-Msg4-Level1-r13 */
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8 enPucchCeMsg4Lvl2;             /* pucch-NumRepetitionCE-Msg4-Level2-r13 */
    LRRC_LPHY_PUCCH_RPTTN_CE_MSG4_LVL_ENUM_UINT8 enPucchCeMsg4Lvl3;             /* pucch-NumRepetitionCE-Msg4-Level3-r13 */
}LRRC_LPHY_PUCCH_COMM_CE_INFO_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_COMM_INFO_STRU
 Э����  : RadioResourceConfigCommonSIB->PUCCH-ConfigCommon��
             RadioResourceConfigCommon->PUCCH-ConfigCommon
 ASN.1���� :
 �ṹ˵��  : ����PUCCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DELTA_PUCCH_SHITF_ENUM_UINT16       enDeltaShift;                 /* PUCCH-ConfigCommon->deltaPUCCH-Shift */
    VOS_UINT16                                    usNrb_Cqi;                    /* PUCCH-ConfigCommon->nRB-CQI */
    VOS_UINT16                                    usNcs_An;                     /* PUCCH-ConfigCommon->nCS-AN */
    VOS_UINT16                                    usN1Pucch_An;                 /* PUCCH-ConfigCommon->n1PUCCH-AN */
}LRRC_LPHY_PUCCH_COMM_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ACK_NACK_REPET_STRU
 Э����  : PUCCH-ConfigDedicated->ackNackRepetition
 ASN.1���� :
 �ṹ˵��  : ACK NACK Repetitiond�����ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_REPETITION_FACTOR_ENUM_UINT16       enAckNackRepetitionFactor;  /* PUCCH-ConfigDedicated->ackNackRepetition->repetitionFactor */
    VOS_UINT16                                    usN1PucchAnRep;               /* PUCCH-ConfigDedicated->ackNackRepetition->n1PUCCH-AN-Rep*/
}LRRC_LPHY_ACK_NACK_REPET_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_FORMAT3_STRU
 Э����  : PUCCH-ConfigDedicated-v1020->format3-r10
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usN3PucchAnListCnt;         /* ָʾausN3PucchAnListʵ��ʹ�ø��� */
    VOS_UINT16                                      usN3PucchAnListP1Cnt;       /* ָʾausN3PucchAnListP1ʵ��ʹ�ø��� */
    VOS_UINT16                                      ausN3PucchAnList[LRRC_LPHY_MAX_N3_PUCCH_AN_LIST_NUM];        /* n3PUCCH-AN-List-r10 */
    VOS_UINT16                                      ausN3PucchAnListP1[LRRC_LPHY_MAX_N3_PUCCH_AN_LIST_P1_NUM];        /* n3PUCCH-AN-ListP1-r10 */
}LRRC_LPHY_PUCCH_FORMAT3_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_N1_PUCCH_AN_CS_STRU
 Э����  : PUCCH-ConfigDedicated-v1020->channelSelection-r10
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usN1PucchAnCsCnt;         /* ָʾausN3PucchAnListʵ��ʹ�ø��� */
    VOS_UINT16                                      ausN1PucchAnCs[LRRC_LPHY_MAX_N1_PUCCH_AN_CS_NUM];        /* n3PUCCH-AN-List-r10 */
    VOS_UINT16                                      usReserved;
}LRRC_LPHY_N1_PUCCH_AN_CS_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_CHANNEL_SEL_STRU
 Э����  : PUCCH-ConfigDedicated-v1020->channelSelection-r10
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usN1PucchAnCsListCnt;       /* ָʾausN3PucchAnListʵ��ʹ�ø��� */
    VOS_UINT16                                      usReserved;
    LRRC_LPHY_N1_PUCCH_AN_CS_STRU                   astN1PucchAnCsList[LRRC_LPHY_MAX_N1_PUCCH_AN_CS_LIST_NUM];        /* n1PUCCH-AN-CS-List-r10 */
}LRRC_LPHY_PUCCH_CHANNEL_SEL_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_FORMAT4_RESOURCE_STRU
 Э����  :
 ASN.1���� : Format4-resource-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucStartPrbFrmt4;            /* startingPRB-format4-r13 */
    VOS_UINT8                                       ucNumOfPrbFrmt4;            /* numberOfPRB-format4-r13 */
    VOS_UINT8                                       aucRsv[2];
}LRRC_LPHY_PUCCH_FORMAT4_RESOURCE_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_FORMAT5_RESOURCE_STRU
 Э����  :
 ASN.1���� : Format5-resource-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucStartPrbFrmt5;            /* startingPRB-format5-r13 */
    VOS_UINT8                                       ucCdmIndexFrmt5;            /* cdm-index-format5-r13 */
    VOS_UINT8                                       aucRsv[2];
}LRRC_LPHY_PUCCH_FORMAT5_RESOURCE_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_FORMAT4_STRU
 Э����  :
 ASN.1���� : format4-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PUCCH_FORMAT4_RESOURCE_STRU           astFrmt4RsrCfg[LRRC_LPHY_MAX_FRMT4_RSR_NUM];    /* format4-resourceConfiguration-r13 SEQUENCE (SIZE (4)) OF Format4-resource-r13 */

    VOS_UINT8                                       aucRsv[3];
    VOS_UINT8                                       ucFrmt4MulCsiRsrCfgNum;     /* ucFrmt4MulCsiRsrCfgNum����0����ʾ format4-MultiCSI-resourceConfiguration-r13������ */
    LRRC_LPHY_PUCCH_FORMAT4_RESOURCE_STRU           astFrmt4MulCsiRsrCfg[LRRC_LPHY_MAX_FRMT4_MUL_CSI_RSR_NUM];   /* format4-MultiCSI-resourceConfiguration-r13 SEQUENCE (SIZE (1..2)) OF Format4-resource-r13 */
}LRRC_LPHY_PUCCH_FORMAT4_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_FORMAT5_STRU
 Э����  :
 ASN.1���� : format5-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PUCCH_FORMAT5_RESOURCE_STRU           astFrmt5RsrCfg[LRRC_LPHY_MAX_FRMT5_RSR_NUM];  /* format5-resourceConfiguration-r13 SEQUENCE (SIZE (4)) OF Format5-resource-r13 */

    VOS_UINT8                                       aucRsv[2];
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enFrmt5MulCsiRsrCfgFlg;
    LRRC_LPHY_PUCCH_FORMAT5_RESOURCE_STRU           stFrmt5MulCsiRsrCfg;        /* format5-MultiCSI-resourceConfiguration-r13 Format5-resource-r13 */
}LRRC_LPHY_PUCCH_FORMAT5_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_NUM_REPETITION_CE_MODE_A_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_ENUM_UINT8        enFrmt1;                    /* pucch-NumRepetitionCE-format1-r13 */
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_ENUM_UINT8        enFrmt2;                    /* pucch-NumRepetitionCE-format2-r13 */
    VOS_UINT8                                       aucRsv[2];
}LRRC_LPHY_PUCCH_NUM_REPETITION_CE_MODE_A_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_NUM_REPETITION_CE_MODE_B_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_ENUM_UINT8        enFrmt1;                    /* pucch-NumRepetitionCE-format1-r13 */
    LRRC_LPHY_PUCCH_RPTTN_CE_FRMT_ENUM_UINT8        enFrmt2;                    /* pucch-NumRepetitionCE-format2-r13 */
    VOS_UINT8                                       aucRsv[2];
}LRRC_LPHY_PUCCH_NUM_REPETITION_CE_MODE_B_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_NUM_REPETITION_CE_STRU
 Э����  :
 ASN.1���� : pucch-NumRepetitionCE-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       aucRsv[3];
    LRRC_LPHY_CE_MODE_ENUM_UINT8                    enCeMode;
    union
    {
        LRRC_LPHY_PUCCH_NUM_REPETITION_CE_MODE_A_STRU   stModeA;
        LRRC_LPHY_PUCCH_NUM_REPETITION_CE_MODE_B_STRU   stModeB;
    }u;
}LRRC_LPHY_PUCCH_NUM_REPETITION_CE_STRU;

#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_DEDICATED_INFO_STRU
 Э����  : PhysicalConfigDedicated->PUCCH-ConfigDedicated
 ASN.1���� :
 �ṹ˵��  : ר��PUCCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enAckNackRepetitionEnabled; /* AckNackRepetition������Ч��ʶ */
    LRRC_LPHY_TDD_FEEDBACK_MODE_ENUM_UINT16         enTddAckNackFeedbackMode;   /* PUCCH-ConfigDedicated->tddAckNackFeedbackMode */
    LRRC_LPHY_ACK_NACK_REPET_STRU                   stAckNackRepetition;        /* PhysicalConfigDedicated->PUCCH-ConfigDedicated */
    VOS_UINT16                                      usReserved;
    LRRC_LPHY_PUCCH_FORMAT_TYPE_ENUM_UINT16         enPucchFormatType;          /* ���û��PUCCH FORMAT�������˴�������BUTT */
    union
    {
        LRRC_LPHY_PUCCH_FORMAT3_STRU                stPucchFormat3;
        LRRC_LPHY_PUCCH_CHANNEL_SEL_STRU            stPucchChannelSel;
    }u;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enTwoAntennaPortActPucchFormat1a1b; /* twoAntennaPortActivatedPUCCH-Format1a1b-r10 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enSimulPucchPusch;          /* simultaneousPUCCH-PUSCH-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enN1PucchAnRepP1ValidFlg;   /* usN1PucchAnRepP1��Ч��ʶ */
    VOS_UINT16                                      usN1PucchAnRepP1;           /* n1PUCCH-AN-RepP1-r10 INTEGER (0..2047)*/
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enN1PucchAnCSEnabled;       /* stN1PucchAnCSListP1 ��Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enNPucchParamEnabled;       /* stNPucchParam ��Ч��ʶ */
    LRRC_LPHY_N1_PUCCH_AN_CS_STRU                   stN1PucchAnCSListP1;        /* n1PUCCH-AN-CS-ListP1-r11 --Need ON */
    LRRC_LPHY_N_PUCCH_PARAM_STRU                    stNPucchParam;              /* nPUCCH-Param-r11 --Need ON */
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enNkaPucchEnabled;
    VOS_UINT16                                      usNkaPucchAn;               /* 0...2047 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPucchFrmt4Flg;            /* ��r13�Ľṹ����Ĭ�ϴ��ڣ����ڰ汾������ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPucchFrmt5Flg;            /* ��r13�Ľṹ����Ĭ�ϴ��ڣ����ڰ汾������ */
    LRRC_LPHY_PUCCH_FORMAT4_STRU                    stPucchFrmt4;               /* format4-r13 */
    LRRC_LPHY_PUCCH_FORMAT5_STRU                    stPucchFrmt5;               /* format5-r13 */

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enSptlBndlPucch;            /* spatialBundlingPUCCH-r13 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enSptlBndlPusch;            /* spatialBundlingPUSCH-r13 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enHarqTmTdd;                /* harq-TimingTDD-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCdBkSizeDtrmnFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enMaxPyldCdrtFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPucchNumRpttnCeFlg;       /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_CODE_BOOK_SIZE_DETERMIN_ENUM_UINT8    enCdBkSizeDtrmn;            /* codebooksizeDetermination-r13 */
    VOS_UINT8                                       ucMaxPyldCdr;               /* maximumPayloadCoderate-r13 */
    VOS_UINT8                                       aucRsv[2];

    LRRC_LPHY_PUCCH_NUM_REPETITION_CE_STRU          stPucchNumRpttnCe;          /* pucch-NumRepetitionCE-r13  */
#endif

}LRRC_LPHY_PUCCH_DEDICATED_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SR_CONFIG_INFO_STRU
 Э����  : PhysicalConfigDedicated->SchedulingRequest-Configuration
 ASN.1���� :
 �ṹ˵��  : ��������������Ϣ�������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usSrPucchResIdx;              /* SchedulingRequest-Configuration->sr-PUCCH-ResourceIndex */
    VOS_UINT16                                    usSrConfigIdx;                /* SchedulingRequest-Configuration->sr-ConfigurationIndex */
    LRRC_LPHY_DSR_TRANS_MAX_ENUM_UINT16           enDsrTransMax;                /* SchedulingRequest-Configuration->dsr-TransMax */
    /* v7r2 interface begin */
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enSrPucchResourceIndexP1ValidFlg;   /* usSrPucchResourceIndexP1��Ч��ʶ */
    VOS_UINT16                                    usSrPucchResourceIndexP1;     /* sr-PUCCH-ResourceIndexP1-r10*/
    /* v7r2 interface end */
}LRRC_LPHY_SR_CONFIG_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : PUCCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;             /* �����ŵ����� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDedicatedInfoValidFlag;     /* ר��PUCCH�ŵ�������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enSrConfigInfoValidFlag;      /* SR�������ò�����Ч��ʶ */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16      enUlCPLen;                    /* ����CP���� */
    LRRC_LPHY_PUCCH_COMM_INFO_STRU                  stPucchCommInfo;              /* ����PUCCH�ŵ����� */
    LRRC_LPHY_PUCCH_DEDICATED_INFO_STRU             stDedicatedInfo;              /* ר��PUCCH�ŵ����� */
    LRRC_LPHY_SR_CONFIG_INFO_STRU                   stSrConfigInfo;               /* SchedulingRequest-Configuration���� */

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPucchCommCeValidFlag;       /* BostonĬ�ϲ�֧�� */
    VOS_UINT16                                      usRsv;
    LRRC_LPHY_PUCCH_COMM_CE_INFO_STRU               stPucchCommCe;                /* PUCCH-ConfigCommon-v1310 */
#endif
}LRRC_LPHY_PUCCH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_BASIC_CONFIG_STRU
 Э����  : PUSCH-Configuration->PUSCH-ConfigCommon->pusch-ConfigBasic
 ASN.1���� :
 �ṹ˵��  : PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PUSCH_N_SB_ENUM_UINT16              enNSb;                        /* n-SB */
    LRRC_LPHY_PUSCH_HOPPING_MODE_ENUM_UINT16      enHoppingMode;                /* hoppingMode */
    VOS_UINT16                                    usHoppingOffset;              /* pusch-HoppingOffset */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enEnable64Qam;                /* enable64Qam,1:enable��0:disable */
}LRRC_LPHY_PUSCH_BASIC_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_UL_REF_SIGNAL_STRU
 Э����  : PUSCH-Configuration->PUSCH-ConfigCommon->UL-ReferenceSignalsPUSCH
 ASN.1���� :
 �ṹ˵��  : PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16   usGroupHoppingEnabled;                  /* groupHoppingEnabled */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16   usSequenceHoppingEnabled;               /* sequenceHoppingEnabled */
    VOS_UINT16                          usGroupAssignmentPUSCH;                 /* groupAssignmentPUSCH */
    VOS_UINT16                          usCyclicShift;                          /* cyclicShift */
}LRRC_LPHY_PUSCH_UL_REF_SIGNAL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_BETA_OFFSET_MC_STRU
 Э����  : PUSCH-Configuration->PUSCH-ConfigDedicated
 ASN.1���� :
 �ṹ˵��  : ר��PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                            usOffsetAckIdxMc;                     /* betaOffset-ACK-Index-MC-r10 */
    VOS_UINT16                            usOffsetRiIdxMc;                      /* betaOffset-RI-Index-MC-r10 */
    VOS_UINT16                            usOffsetCqiIdxMc;                     /* betaOffset-CQI-Index-MC-r10 */
    VOS_UINT16                            usReserved;
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enOffset2AckIdxMcFlg;
    VOS_UINT16                            usOffset2AckIdxMc;                    /* betaOffset2-ACK-Index-MC-r13 (betaOffset2-ACK-Index-MC-SubframeSet2-r13)  */
#endif
}LRRC_LPHY_PUSCH_BETA_OFFSET_MC_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_COMM_INFO_STRU
 Э����  : PUSCH-Configuration->PUSCH-ConfigCommon
 ASN.1���� :
 �ṹ˵��  : ����PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                            usMaxHarqMsg3Tx;                      /* maxHARQ-Msg3Tx */
    VOS_UINT16                            usReserved;
    LRRC_LPHY_PUSCH_BASIC_CONFIG_STRU     stPuschBasicConfig;                   /* PUSCH����������Ϣ */
    LRRC_LPHY_PUSCH_UL_REF_SIGNAL_STRU    stPuschUlRefSignal;                   /* ���вο��ź�PUSCH���� */
#if (FEATURE_ON == FEATURE_LTE_R13)

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPuschMaxNumRpttnCeModeAFlg;         /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_ENUM_UINT16   enPuschMaxNumRpttnCeModeA;      /* pusch-maxNumRepetitionCEmodeA-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPuschMaxNumRpttnCeModeBFlg;         /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_PUSCH_MAX_NUM_RPTTN_ENUM_UINT16   enPuschMaxNumRpttnCeModeB;      /* pusch-maxNumRepetitionCEmodeB-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enHoppingOffsetFlg;
    VOS_UINT16                            usHoppingOffset;                      /* pusch-HoppingOffset-v1310 */
#endif
}LRRC_LPHY_PUSCH_COMM_INFO_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                            usOffsetAckIdxMcSfmSet2;              /* betaOffset-ACK-Index-MC-SubframeSet2-r12 */
    VOS_UINT16                            usOffsetRiIdxMcSfmSet2;               /* betaOffset-RI-Index-MC-SubframeSet2-r12 */
    VOS_UINT16                            usOffsetCqiIdxMcSfmSet2;              /* betaOffset-CQI-Index-MC-SubframeSet2-r12 */
    VOS_UINT16                            usReserved;
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enOffset2AckIdxMcSfmSet2Flg;
    VOS_UINT16                            usOffset2AckIdxMcSfmSet2;             /* betaOffset2-ACK-Index-MC-SubframeSet2-r13 */
#endif
}LRRC_LPHY_PUSCH_BETA_OFFSET_MC_SFM_SET_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 PUSCH-ConfigDedicated-v1250::=          SEQUENCE {
     uciOnPUSCH              CHOICE {
         release                 NULL,
         setup                   SEQUENCE {
             betaOffset-ACK-Index-SubframeSet2-r12               INTEGER (0..15),
             betaOffset-RI-Index-SubframeSet2-r12                INTEGER (0..15),
             betaOffset-CQI-Index-SubframeSet2-r12               INTEGER (0..15),
             betaOffsetMC-r12                    SEQUENCE {
                 betaOffset-ACK-Index-MC-SubframeSet2-r12            INTEGER (0..15),
                 betaOffset-RI-Index-MC-SubframeSet2-r12         INTEGER (0..15),
                 betaOffset-CQI-Index-MC-SubframeSet2-r12            INTEGER (0..15)
             }                                                               OPTIONAL    -- Need OR
         }
     }
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{


    VOS_UINT16                            usOffsetAckIdxSfmSet2;     /* betaOffset-ACK-Index-SubframeSet2-r12 */
    VOS_UINT16                            usOffsetRiIdxSfmSet2;      /* betaOffset-RI-Index-SubframeSet2-r12 */
    VOS_UINT16                            usOffsetCqiIdxSfmSet2;     /* betaOffset-CQI-Index-SubframeSet2-r12 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enOffset2AckIdxSfmSet2Flg;
    VOS_UINT16                            usOffset2AckIdxSfmSet2;   /* betaOffset2-ACK-Index-SubframeSet2-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPuschBetaOffsetMc2Flg;
    LRRC_LPHY_PUSCH_BETA_OFFSET_MC_SFM_SET_STRU   stPuschBetaOffsetMc2;
}LRRC_LPHY_PUSCH_TPC_SFM_SET_STRU;
#endif
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_DEDICATED_INFO_STRU
 Э����  : PUSCH-Configuration->PUSCH-ConfigDedicated
 ASN.1���� :
 �ṹ˵��  : ר��PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                            usOffsetAckIdx;     /* deltaOffset-ACK-Index */
    VOS_UINT16                            usOffsetRiIdx;      /* deltaOffset-RI-Index */
    VOS_UINT16                            usOffsetCqiIdx;     /* deltaOffset-CQI-Index */
    LRRC_LPHY_MAX_HARQ_TX_ENUM_UINT16     enUlMaxHarqTxNum;   /* maxHARQ-Tx */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enTtiBundlingFlg;   /* ttiBundling */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPuschBetaOffsetMcValidFlg;
    LRRC_LPHY_PUSCH_BETA_OFFSET_MC_STRU   stPuschBetaOffsetMc;                  /* betaOffsetMC-r10 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enGroupHopDisabled;                   /* groupHoppingDisabled-r10 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enDmrsWithOccActivated;               /* dmrs-WithOCC-Activated-r10 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                            usReserved;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enPuschDMRSEnabled;                   /* stPuschDMRS�Ƿ���Ч */
    LRRC_LPHY_PUSCH_DMRS_STRU             stPuschDMRS;                          /* pusch-DMRS-r11 */
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    /* pusch-ConfigDedicated-v1250
      E-UTRAN configures pusch-ConfigDedicated-v1250 only if tpc-SubframeSet is configured. */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPuschTpcSfmSetFlg;
    VOS_UINT16                            usReserved1;
    LRRC_LPHY_PUSCH_TPC_SFM_SET_STRU      stTpcSfmSet;

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enOffset2AckIdxFlg;
    VOS_UINT16                            usOffset2AckIdx;                      /* betaOffset2-ACK-Index-r13 */

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enPuschHopCfg;                        /* pusch-HoppingConfig-r13 */
    VOS_UINT16                            usReserved2;
#endif
}LRRC_LPHY_PUSCH_DEDICATED_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUCCH_DELTAF_LIST_STRU
 Э����  : RadioResourceConfigCommonSIB->UplinkPowerControlCommon->deltaFList-PUCCH
              RadioResourceConfigCommon->UplinkPowerControlCommon->deltaFList-PUCCH
 ASN.1���� :
 �ṹ˵����ר��PUSCH������ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DELTAF_FORMAT_ENUM_UINT16   enFormat1;          /* deltaF-PUCCH-Format1 */
    LRRC_LPHY_DELTAF_FORMAT_ENUM_UINT16   enFormat1b;         /* deltaF-PUCCH-Format1b */
    LRRC_LPHY_DELTAF_FORMAT_ENUM_UINT16   enFormat2;          /* deltaF-PUCCH-Format2 */
    LRRC_LPHY_DELTAF_FORMAT_ENUM_UINT16   enFormat2a;         /* deltaF-PUCCH-Format2a */
    LRRC_LPHY_DELTAF_FORMAT_ENUM_UINT16   enFormat2b;         /* deltaF-PUCCH-Format2b */
    VOS_UINT16                            usReserved;
}LRRC_LPHY_PUCCH_DELTAF_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_POWER_CTRL_COMM_INFO_SCELL_STRU
 Э����  : RadioResourceConfigCommon->UplinkPowerControlCommonSCell-r10
 ASN.1���� :
 �ṹ˵��  : ����PUSCH�����ŵ����ʿ��Ʋ������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                                       sPuschP0Nominal;            /* p0-NominalPUSCH */
    LRRC_LPHY_PWR_CTRL_ALPHA_ENUM_UINT16            enAlpha;                    /* ��*/
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enDeltaPreambleMsg3Enabled; /* sDeltaPreambleMsg3s �Ƿ���� */
    VOS_INT16                                       sDeltaPreambleMsg3;         /* deltaPreambleMsg3-r11  */
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPucchP0NominalValidFlg;       /* BostonĬ�ϲ�֧�� */
    VOS_INT16                                       sPucchP0Nominal;                /* p0-NominalPUCCH */

    VOS_UINT16                                      usRsv;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPucchDeltaFlistValidFlg;      /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_PUCCH_DELTAF_LIST_STRU                stPucchDeltaFlist;              /* deltaFList-PUCCH */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat3ValidFlg;   /* enDeltaFPucchFormat3�Ƿ���Ч��ʶ * BostonĬ�ϲ�֧�� */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_ENUM_UINT16      enDeltaFPucchFormat3;           /* deltaF-PUCCH-Format3-r10 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat1bCsValidFlg;/* enDeltaFPucchFormat1bCs�Ƿ���Ч��ʶ  BostonĬ�ϲ�֧�� */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_ENUM_UINT16   enDeltaFPucchFormat1bCs;        /* deltaF-PUCCH-Format1bCS-r10 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat4ValidFlg;   /* deltaF-PUCCH-Format4-r13�Ƿ���Ч��ʶ  BostonĬ�ϲ�֧�� */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_ENUM_UINT16      enDeltaFPucchFormat4;           /* deltaF-PUCCH-Format4-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat5ValidFlg;   /* deltaF-PUCCH-Format5-r13�Ƿ���Ч��ʶ  BostonĬ�ϲ�֧�� */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_ENUM_UINT16      enDeltaFPucchFormat5;           /* deltaF-PUCCH-Format5-13 */
#endif

}LRRC_LPHY_POWER_CTRL_COMM_INFO_SCELL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_STRU
 Э����  : PhysicalConfigDedicated->UplinkPowerControlDedicated->DeltaTxD-OffsetListPUCCH-r10
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM_UINT16 enDeltaTxDOffsetPucchFormat1;    /* deltaTxD-OffsetPUCCH-Format1-r10 */
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM_UINT16 enDeltaTxDOffsetPucchFormat1a1b; /* deltaTxD-OffsetPUCCH-Format1a1b-r10 */
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM_UINT16 enDeltaTxDOffsetPucchFormat22a2b;/* deltaTxD-OffsetPUCCH-Format22a2b-r10 */
    LRRC_LPHY_DELTATXD_OFFSET_PUCCH_ENUM_UINT16 enDeltaTxDOffsetPucchFormat3;    /* deltaTxD-OffsetPUCCH-Format3-r10 */
}LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_POWER_CTRL_COMM_INFO_STRU
 Э����  : RadioResourceConfigCommonSIB->UplinkPowerControlCommon
              RadioResourceConfigCommon->UplinkPowerControlCommon
 ASN.1���� :
 �ṹ˵��  : ����PUSCH�����ŵ����ʿ��Ʋ������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                                       sPuschP0Nominal;                /* p0-NominalPUSCH */
    LRRC_LPHY_PWR_CTRL_ALPHA_ENUM_UINT16            enAlpha;                        /* ��*/
    VOS_INT16                                       sPucchP0Nominal;                /* p0-NominalPUCCH */
    VOS_INT16                                       sDeltaPreambleMsg3;             /* deltaPreambleMsg3 */
    LRRC_LPHY_PUCCH_DELTAF_LIST_STRU                stPucchDeltaFlist;              /* deltaFList-PUCCH */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat3ValidFlg;   /* enDeltaFPucchFormat3�Ƿ���Ч��ʶ */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT3_ENUM_UINT16      enDeltaFPucchFormat3;           /* deltaF-PUCCH-Format3-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat1bCsValidFlg;/* enDeltaFPucchFormat1bCs�Ƿ���Ч��ʶ */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT1BCS_ENUM_UINT16   enDeltaFPucchFormat1bCs;        /* deltaF-PUCCH-Format1bCS-r10 */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat4ValidFlg;   /* deltaF-PUCCH-Format4-r13�Ƿ���Ч��ʶ */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT4_ENUM_UINT16      enDeltaFPucchFormat4;           /* deltaF-PUCCH-Format4-r13 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaFPucchFormat5ValidFlg;   /* deltaF-PUCCH-Format5-r13�Ƿ���Ч��ʶ */
    LRRC_LPHY_DELTAF_PUCCH_FORMAT5_ENUM_UINT16      enDeltaFPucchFormat5;           /* deltaF-PUCCH-Format5-13 */
#endif
}LRRC_LPHY_POWER_CTRL_COMM_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_STRU
 Э����  : PhysicalConfigDedicated->UplinkPowerControlDedicated
 ASN.1���� :
 �ṹ˵��  : ר��PUSCH�����ŵ����ʿ��Ʋ������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                             sPuschP0Ue;                                     /* p0-UePUSCH */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enDeltaMcsEnabled;                              /* deltaMCS-Enabled */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enAccumlatEnabled;                              /* accumulationEnabled */
    VOS_INT16                             sPucchP0Ue;                                     /* p0-uePUCCH */
    VOS_UINT16                            usPsrsOffset;                                   /* pSRS-Offset */
    LRRC_LPHY_FILTER_COEFF_ENUM_UINT16    enFilterCoeff;                                  /* FilterCoefficient */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPSrsOffsetApValidFlg;               /* pSRS-OffsetAp-r10  �Ƿ���Ч��ʶ */
    VOS_UINT16                                      usPSrsOffsetAp;                       /* pSRS-OffsetAp-r10 INTEGER (0..15)*/
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaTxDOffsetListPucchValidFlg;    /* DeltaTxD-OffsetListPUCCH-r10 �Ƿ���Ч��ʶ  */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDeltaTxDOffsetListPucchR11ValidFlg; /* DeltaTxD-OffsetListPUCCH-r11 �Ƿ���Ч��ʶ  */
#else
    VOS_UINT16                                      usReserved;
#endif
    LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_STRU        stDeltaTxDOffsetListPucch;
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_R11_STRU    stDeltaTxDOffsetListPucchR11;         /* DeltaTxD-OffsetListPUCCH-v1130 */
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPsrsOffsetR11;                      /* ָʾʹ��pSRS-Offset-v1130 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPsrsOffsetApR11;                    /* ָʾʹ�� pSRS-OffsetAp-v1130 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enPwrCtrlSet2ValidFlg;                /* set2PowerControlParameter�Ƿ���Ч��ʶ */
    VOS_UINT16                                      usTpcSubframeSet;                     /* tpc-SubframeSet-r12 */
    VOS_INT16                                       sPuschP0NominalSet2;                  /* p0-NominalPUSCH-SubframeSet2-r12 */
    LRRC_LPHY_PWR_CTRL_ALPHA_ENUM_UINT16            enAlphaSet2;                          /* alpha-SubframeSet2-r12 */
    VOS_INT16                                       sPuschP0UeSet2;                       /* p0-UE-PUSCH-SubframeSet2-r12 */
    VOS_UINT16                                      usReserved2;
#endif
}LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_TPC_PDCCH_CONFIG_STRU
 Э����  : PhysicalConfigDedicated->TPC-PDCCH-Configuration
 ASN.1���� :
 �ṹ˵��  : TPC-PDCCH-Configuration
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usTpc_Rnti;                   /* tpc-RNTI */
    LRRC_LPHY_INDEX_FORMAT_TYPE_ENUM_UINT16       enTpcFormatType;              /* tpc-Index->choice */
    VOS_UINT16                                    usTpcIdx;                     /* tpc-Index->indexOfFormat3/indexOfFormat3A */
    VOS_UINT16                                    usReserved;
}LRRC_LPHY_TPC_PDCCH_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_P0_PERSISTENT_STRU
 Э����  : RadioResourceConfigDedicated->SPS-Configuration->SPS-ConfigurationUL
 ASN.1���� :
 �ṹ˵��  : p0-Persistent
*****************************************************************************/
typedef struct
{
    VOS_INT16                            sP0NominalPuschPersistent;             /* p0-NominalPUSCH-Persistent */
    VOS_INT16                            sP0UePuschPersistent;                  /* p0-UePUSCH-Persistent */
}LRRC_LPHY_P0_PERSISTENT_STRU;
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_INT16                           sP0NmnlPuschPrsstntSubFrmSet2;          /* p0-NominalPUSCH-PersistentSubframeSet2-r12 */
    VOS_INT16                           sP0UePuschPrsstntSubFrmSet2;            /* p0-UE-PUSCH-PersistentSubframeSet2-r12 */
}LRRC_LPHY_P0_PERSIST_SUB_FRAME_SET2_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SPS_CONFIG_UL_STRU
 Э����  : RadioResourceConfigDedicated->SPS-Configuration->SPS-ConfigurationUL
 ASN.1���� :
 �ṹ˵��  : SPS-ConfigurationUL
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PERSIST_SCHED_INTERVAL_ENUM_UINT16    enUlPersistSchedInterval;     /* semiPersistSchedIntervalUL */
    LRRC_LPHY_IMPLICIT_REL_AFTER_ENUM_UINT16        enImplicitRelAfter;           /* implicitReleaseAfter */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enTwoIntervalsCfgValidFlg;    /* twoIntervalsConfig */
    VOS_UINT16                                      usReserved;
    LRRC_LPHY_P0_PERSISTENT_STRU                    stP0Persistent;               /* p0-Persistent */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enP0PersistSubFrameSet2ValidFlg;
    VOS_UINT16                                      usRsv1;
    LRRC_LPHY_P0_PERSIST_SUB_FRAME_SET2_STRU        stP0PersistSubFrameSet2;      /* p0-PersistentSubframeSet2-r12 */
#endif
}LRRC_LPHY_SPS_CONFIG_UL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANTENNA_INFO_UL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ANTENNA_INFO_UL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enTransmissionModeULValidFlg; /* transmissionModeUL-r10�Ƿ���Ч */
    LRRC_LPHY_TRANSMISSION_MODE_ENUM_UINT16       enTransmissionModeUL;         /* transmissionModeUL-r10 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             en4AntennaPortActivated;      /* fourAntennaPortActivated-r10 1: setup, Activated only if transmissionModeUL is set to tm2*/
    VOS_UINT16                                    usReserved;
}LRRC_LPHY_ANTENNA_INFO_UL_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LMAC_DC_PHR_STRU
 Э����  :
 ASN.1���� :

 dualConnectivityPHR                 CHOICE {
             release                             NULL,
             setup                               SEQUENCE {
                 phr-ModeOtherCG-r12                 ENUMERATED {real, virtual}
             }
         }
 �ṹ˵��  : Ϊ��ʱ��Ŀ��ǣ����������ͬʱ��Я����MAC��LPHY
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PHR_MODE_OTHER_CG_ENUM_UINT8  enPhrModeOtherCg;                   /* phr-ModeOtherCG-r12                 ENUMERATED {real, virtual} */
    VOS_UINT8                               aucRsv[3];
}LRRC_LPHY_DC_PHR_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDedicatedPuschInfoValidFlag;/* ר��PUSCH�ŵ�������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDedicatedPwrCtrlValidFlag;  /* ר��Pwr Ctrl������Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPucchTpcConfigEnabled;      /* TPC PUCCH������Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPuschTpcConfigEnabled;      /* TPC PUSCH������Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enSpsConfigUlEnabled;         /* SPS-ConfigurationUL��Ч��ʶ */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16      enUlCPLen;                    /* ����CP���� */
    VOS_UINT16                                      usUlFreqInfo;                 /* ����Ƶ��, ��Ӧ�տ�SystemInformationBlockType2->ul-EARFCN, ȱʡʱ����36.101���м��� */
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16                enUlBandWidth;                /* ���д���,��Ӧ�տ�SystemInformationBlockType2->ul-Bandwidth��ȱʡʱ��д���д��� */
    VOS_UINT16                                      usAdditionalSpecEmission;     /* ��Ӧ�տ�SystemInformationBlockType2->additionalSpectrumEmission, �����ֶ� */
    LRRC_LPHY_PUSCH_COMM_INFO_STRU                  stPuschCommInfo;              /* ����PUSCH���ò��� */
    LRRC_LPHY_PUSCH_DEDICATED_INFO_STRU             stPuschDedicatedInfo;         /* ר��PUSCH���ò��� */
    LRRC_LPHY_POWER_CTRL_COMM_INFO_STRU             stPwrCtrlCommInfo;            /* �������ʿ�����Ϣ */
    LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_STRU        stPwrCtrlDedicatedInfo;       /* ר�й��ʿ�����Ϣ */
    LRRC_LPHY_TPC_PDCCH_CONFIG_STRU                 stPucchTpcConfig;             /* tpc-PDCCH-ConfigPUCCH */
    LRRC_LPHY_TPC_PDCCH_CONFIG_STRU                 stPuschTpcConfig;             /* tpc-PDCCH-ConfigPUSCH */
    LRRC_LPHY_SPS_CONFIG_UL_STRU                    stSpsConfigUl;                /* SPS-Configuration->SPS-ConfigurationUL */
    LRRC_LPHY_ANTENNA_INFO_UL_STRU                  stAntennaInfoUL;              /* antennaInfoUL-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enAdditSpecEmissionPCellFlg;  /* usAdditSpecEmissionPCell�Ƿ���Ч��ʾ */
    VOS_UINT16                                      usAdditSpecEmissionPCell;     /* additionalSpectrumEmissionPCell */

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDcPhrFlg;
    VOS_UINT16                                      usRsv;
    LRRC_LPHY_DC_PHR_STRU                           stDcPhr;                    /* MCG ��DC PHY */
#endif
}LRRC_LPHY_PUSCH_PARA_STRU;
#if (FEATURE_ON == FEATURE_LTE_R13)

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                      bitPrachStartSubFrmPresent:1;
    VOS_UINT32                                      bitsMaxNumPreambleAttemptCEPresent:1;
    VOS_UINT32                                      bitSpare:30;


    VOS_UINT16                                      usConfigIndex;                /* PRACH-Configuration->prach-ConfigurationIndex */
    VOS_UINT16                                      usFrequencyOffset;            /* prach-FrequencyOffset */
    VOS_UINT16                                      usPrachStartSubFrm;           /* prach-StartingSubframe-r13 */
    VOS_UINT16                                      usMaxNumPreambleAttemptCE;    /* maxNumPreambleAttemptCE-r13 */

    VOS_UINT16                                      usNumRpttnPerPreamblAttemp;   /* numRepetitionPerPreambleAttempt-r13 */

    VOS_UINT16                                      usMPdcchNrrwBndToMntrNum;

    VOS_UINT16                                      ausMPdcchNrrwBndToMntr[LRRC_LPHY_MAX_MPDCCH_NARROW_BAND_TO_MON_NUM]; /* mpdcch-NarrowbandsToMonitor-r13 */
    LRRC_LPHY_MPDCCH_NUM_RPTTN_RA_ENUM_UINT16       enMpdcchNumRpttnRa;         /* mpdcch-NumRepetition-RA-r13 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPrachHopCfg;              /* prach-HoppingConfig-r13 */
}LRRC_LPHY_PRACH_PARA_CE_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : RSRP-ThresholdsPrachInfoList-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucNum;
    VOS_UINT8                                       aucRsv[1];
    VOS_INT16                                       asRsrpThres[LRRC_LPHY_MAX_RSRP_THRES_PRACH_NUM];
}LRRC_LPHY_RSRP_THRES_INFO_LIST_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucNum;
    VOS_UINT8                                       aucRsv[3];
    LRRC_LPHY_PRACH_PARA_CE_STRU                    astPrachParaCe[LRRC_LPHY_MAX_CE_LVL_NUM];
}LRRC_LPHY_PRACH_PARA_LIST_CE_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_CONFIG_CE_STRU
 Э����  : RadioResourceConfigCommonSIB->PRACH-ConfigSIB-v1310
              RadioResourceConfigCommon->PRACH-Config-v1310
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                      bitRsrpThresInfoListPresent:1;
    VOS_UINT32                                      bitMpdcchSfCssRaPresent:1;
    VOS_UINT32                                      bitPrachHopOffsetPresent:1;
    VOS_UINT32                                      bitPrachParaListCePresent:1;
    VOS_UINT32                                      bitInitCeLvlPresent:1;
    VOS_UINT32                                      bitSpare:27;

    LRRC_LPHY_RSRP_THRES_INFO_LIST_STRU             stRsrpThresInfoList;          /* rsrp-ThresholdsPrachInfoList-r13 */

    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16             enLteMode;
    LRRC_LPHY_MPDCCH_SF_CSS_RA_ENUM_UINT16          enMpdcchSfCssRa;              /* mpdcch-startSF-CSS-RA-r13 */
    VOS_UINT16                                      usPrachHopOffset;             /* prach-HoppingOffset-r13 */
    VOS_UINT16                                      usInitCeLvl;                  /* initial-CE-level-r13 */
    LRRC_LPHY_PRACH_PARA_LIST_CE_STRU               stPrachParaListCe;            /* prach-ParametersListCE-r13 */

}LRRC_LPHY_PRACH_CONFIG_CE_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_CONFIG_STRU
 Э����  : RadioResourceConfigCommonSIB->PRACH-ConfigurationSIB
              RadioResourceConfigCommon->PRACH-Configuration
 ASN.1���� :
 �ṹ˵��  : PRACH�����ŵ����ò������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usRootSequenceIndex;          /* PRACH-Configuration->rootSequenceIndex */
    VOS_UINT16                                    usConfigIndex;                /* PRACH-Configuration->prach-ConfigurationIndex */
    VOS_UINT16                                    usHighSpeedFlg;               /* PRACH-Configuration->highSpeedFlag */
    VOS_UINT16                                    usZeroCorrelationZoneConfig;  /* zeroCorrelationZoneConfig */
    VOS_UINT16                                    usFrequencyOffset;            /* prach-FrequencyOffset */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16    enUlCPLen;                    /* ����CP���� */
}LRRC_LPHY_PRACH_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : PRACH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16    enPhyChannelType;
    VOS_UINT16                            usReserved;
    LRRC_LPHY_PRACH_CONFIG_STRU           stPrachInfo;
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enPrachCfgCeFlg;                      /* BostonĬ�ϲ�֧�� */
    VOS_UINT16                            usReserved1;
    LRRC_LPHY_PRACH_CONFIG_CE_STRU        stPrachCfgCe;
#endif
}LRRC_LPHY_PRACH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_SETUP_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ������������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usFreqInfo;                             /* С����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16 enLteModeType;                          /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                          usCellId;                               /* С��ID */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    /* ����֡�ţ���֡�� */
    VOS_UINT16                          usFrameNo;                              /* 0-1023, 0xFFFF��ʾ��Ч */
    VOS_UINT8                           ucSubFrameNo;                           /* 0-9, 0xFFFF��ʾ��Ч */
    VOS_UINT8                           ucRsv1;
#endif
    VOS_UINT16                          usPhyChannelNum;                        /* ָʾ���ν������ŵ����� */
    VOS_UINT16                          usParaSize;                             /* ָʾ���ν������ŵ��������ܳ��� */
    VOS_UINT8                           aucPhyChannelPara[4];                   /* �����ŵ����ò��� */
}LRRC_LPHY_RL_SETUP_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_SETUP_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ������ظ�������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16    enPhyChannelType;
    LRRC_LPHY_RESULT_ENUM_UINT16          enRlConfigResult;
}LRRC_LPHY_RL_CONFIG_RESULT;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_SETUP_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ������ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usFreqInfo;                             /* С����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    VOS_UINT16                          usCellId;                               /* С��ID */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
    VOS_UINT16                          usPhyChannelNum;
    LRRC_LPHY_RL_CONFIG_RESULT          astRlSetupRslt[LRRC_LPHY_MAX_CHANNEL_NUM];
}LRRC_LPHY_RL_SETUP_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_RELEASE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ������������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16    enPhyChannelType;
    LRRC_LPHY_PDSCH_SETUP_FLAG_ENUM_INT16 enPdschSetupFlag;
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                            usSCellIdx;                           /* SCELL����, 0��ʶPCELL */
    VOS_UINT16                            usReserved;
#endif
}LRRC_LPHY_RL_RELEASE_CHANNAL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_RELEASE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ��ͷ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    VOS_UINT16                              usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;                          /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16     enLteModeType;                      /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                              usCellId;
    VOS_UINT16                              usPhyChannelNum;
    LRRC_LPHY_RL_RELEASE_CHANNAL_INFO_STRU  astChannelInfo[LRRC_LPHY_MAX_CHANNEL_NUM];
}LRRC_LPHY_RL_RELEASE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_RELEASE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ��ͷŻظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;
    VOS_UINT16                          usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    VOS_UINT16                          usCellId;
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
    VOS_UINT16                          usPhyChannelNum;
    LRRC_LPHY_RL_CONFIG_RESULT          astRlReleaseRslt[LRRC_LPHY_MAX_CHANNEL_NUM];
}LRRC_LPHY_RL_RELEASE_CNF_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usSCellIndex;
    VOS_UINT16                              usRsv;
}LRRC_LPHY_SCELL_RL_RELEASE_INFO_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;


    VOS_UINT16                              usSCellNum;
    LRRC_LPHY_SCELL_RL_RELEASE_INFO_STRU    astScellRlRelInfo[LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM];
}LRRC_LPHY_SCELL_RL_RELEASE_REQ_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RL_RELEASE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ŵ��ͷŻظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;

    LRRC_LPHY_RESULT_ENUM_UINT16        enRlConfigResult;
}LRRC_LPHY_SCELL_RL_RELEASE_CNF_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SYNC_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ���������ͬ���������ݽṹ,Ŀǰֻ�Ǳ���ԭ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;
    VOS_UINT16                          usEnableFlg;                            /* 0����ʾֹͣͬ��ָʾ�ϱ�
                                                                                   1����ʾ����ͬ��ָʾ�ϱ�
                                                                                   2����ʾ����ʧ��ָʾ�ϱ� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CG_ENUM_UINT8             enCgType;
    VOS_UINT8                           aucRsv[3];
#endif
}LRRC_LPHY_SYNC_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SYNC_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ���������ͬ������ظ����ݽṹ,Ŀǰֻ�Ǳ���ԭ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;
    VOS_UINT16                          usRsd;
}LRRC_LPHY_SYNC_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SYNC_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ϱ�ͬ�����ݽṹ,Ŀǰֻ�Ǳ���ԭ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CG_ENUM_UINT8               enCgType;
    VOS_UINT8                             aucResverd[3];
#endif
}LRRC_LPHY_SYNC_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OUT_OF_SYNC_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ������ϱ�ʧ������ظ����ݽṹ,Ŀǰֻ�Ǳ���ԭ��
*****************************************************************************/
typedef LRRC_LPHY_SYNC_IND_STRU LRRC_LPHY_OUT_OF_SYNC_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_SF_PATTERN_CFG_NEIGH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MEAS_SF_PATTERN_CFG_NEIGH_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU  stMeasSfPattern;
    /* CEll IDλͼ,ÿһBit��Ӧһ��CellId, ��ĳbitΪ1����ʾ���ø�С��
      ulMeasSfCellBmp[0]�� bit0 : ��ʾCellIdΪ  0 ��С��
      ulMeasSfCellBmp[0]�� bit31: ��ʾCellIdΪ 31 ��С��
      ulMeasSfCellBmp[1]�� bit0 : ��ʾCellIdΪ 32 ��С��
      ......
      ......
      */
    VOS_UINT32                            aulMeasSfCellBmp[16];
}LRRC_LPHY_MEAS_SF_PATTERN_CFG_NEIGH_STRU;
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 MeasRSSI-Config-r13 ::= CHOICE {
     release                             NULL,
     setup                               SEQUENCE {
         rmtc-Period-r13                 ENUMERATED {ms40, ms80, ms160, ms320, ms640},
         rmtc-SubframeOffset-r13         INTEGER(0..639)                 OPTIONAL,       -- Need ON
         measDuration-r13                ENUMERATED {sym1, sym14, sym28, sym42, sym70}
     }
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulRmtcPeriod;                       /*��λ: ms */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enRmtcSubframeOffsetValidFlg;
    VOS_UINT16                              usRmtcSubframeOffset;               /* 0~639 */
    VOS_UINT8                               ucMeasDuration;                     /*��λ:sym����*/
    VOS_UINT8                               aucRsv[3];
}LRRC_LPHY_LAA_MEAS_RSSI_CFG_STRU;
#endif
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SCELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SCELL_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    /* SCELL stru including SCellIndex and phyCellId
    and measCycleSCell and bit-indicator if SCELL is configured */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enSCellInfoValidFlg;                /* ָʾ���������Ƿ���Ч */
    VOS_UINT16                              usSCellIdx;                         /* ��Χ1~7 */
    VOS_UINT16                              usSCellId;                          /* SCELL������С��ID*/
    LRRC_LPHY_MEAS_CYCLE_SCELL_ENUM_UINT16  enMeasCycleSCell;                   /* MeasCycleSCell-r10 */
}LRRC_LPHY_SCELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SINGLE_FREQ_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����Ƶ��С����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                  usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16              enBandInd;                      /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16         enLteModeType;                  /* ָʾƵ����������ʽ����, FDD��TDD */
    /*neighCellConfig:
      Provides information related to MBSFN and TDD UL/DL configuration of neighbour cells of this frequency
      00: Not all neighbour cells have the same MBSFN subframe allocation as serving cell
      10: The MBSFN subframe allocations of all neighbour cells are identical to or subsets of that in the serving cell
      01: No MBSFN subframes are present in all neighbour cells
      11: Different UL/DL allocation in neighbouring cells for TDD compared to the serving cell
      For TDD, 00, 10 and 01 are only used for same UL/DL allocation in neighbouring cells compared to the serving cell.*/
    VOS_UINT16                                  usNeighCellConfigBitmap;        /* �����λ��Ч */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enPresenceAntennaPort1;
    VOS_UINT16                                  usDetectedCellMeasInd;
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16            enMeasBandWidth;
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                                  usPriorSel;                     /* Ƶ��������ȼ���IDLE̬��Ч ��CONNECT̬���� */
#else
    VOS_UINT16                                  usReserved;                     /* �����ֶ� */
#endif
    VOS_UINT16                                  usCellNum;
    VOS_UINT16                                  ausCellIdList[LRRC_LPHY_MAX_FREQ_CELL_NUM]; /* ������������û�����ò���С������������������SCELL, ��Ҫ��SCELL������б�*/

    /* v7r2 interface begin */
    VOS_UINT16                                  usReserved1;                    /* �����ֶ� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enMeasSfPatternNeighValidFlg;
    LRRC_LPHY_MEAS_SF_PATTERN_CFG_NEIGH_STRU    stMeasSfPatternNeigh;           /* MeasSubframePatternConfigNeigh-r10 */

#if (FEATURE_ON == FEATURE_LTE_R13)

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enReducedMeasPerformance;       /* IDLE̬:��Ƶ��Ч������Ƶ����Ч��CONNECT̬:����Ƶ�����Ƶ����Ч */

    /* IDLE̬��Ч��CONN̬��Ч��CONN̬��ʹ��MEAS_IN_CONNECTED_REQ����Ĳ�����
       ��ΪIDLE̬����Ƶ�㻮��,CONN̬������: If this field is present and supported by the UE, the UE shall,
       when performing RSRQ measurements, perform RSRQ measurement on all OFDM symbols in accordance with TS 36.214 [48]. NOTE 1. */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enRsrqOnAllSymbol;

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enRsSinr;                       /* reportQuantity-v13xy, �Ƿ��rs sinr�Ĳ��� */

    /* flag���ͷŵĶ���.���flgΪinvalid����ҪPHY����ǰ������rssi����ֹͣ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enLaaMeasRssiFlg;

    /*LAA �ã�����ÿ��Ƶ�㶼�У�ֻ��unlisence��Ƶ����. ����ľͲ���phy����*/
    LRRC_LPHY_LAA_MEAS_RSSI_CFG_STRU            stLaaMeasRssiCfg;

    /* PSCellͬƵ��־ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enPSCellIntraFreqFlg;
    VOS_UINT8                                   aucReserved2[2];
#endif
    /* v7r2 interface end */
}LRRC_LPHY_SINGLE_FREQ_CELL_INFO_STRU;
typedef LRRC_LPHY_SINGLE_FREQ_CELL_INFO_STRU LRRC_LPHY_INTRA_FREQ_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SECOND_SINGLE_FREQ_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����SCELLƵ��С����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SINGLE_FREQ_CELL_INFO_STRU     stSingleFreqInfo;
    LRRC_LPHY_SCELL_INFO_STRU                stSCellInfo;                       /* SCELL��Ϣ */
}LRRC_LPHY_SECOND_SINGLE_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_INTER_FREQ_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��ƵС����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usInterFreqNum;                         /* ��Ƶ����Ŀ */
    VOS_UINT16                          usHighPriorFreqNum;                     /* �����ȼ�Ƶ����Ŀ */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                          usHighestPrior;                         /* ����Ƶ�������ȼ���ߵ����ȼ���IDLE̬��Ч��CONNECT̬��Ч*/
    VOS_UINT16                          usReserved;
#endif
    /* ����ǰusHighPriorFreqNum��������Ÿ����ȼ�Ƶ����Ϣ��usInterFreqNum-usHighPriorFreqNumΪ�����ȼ��͵����ȼ�Ƶ����Ϣ */
    LRRC_LPHY_SINGLE_FREQ_CELL_INFO_STRU  astInterCellList[LRRC_LPHY_MAX_ADDITIONAL_CARRIER_NUM];
}LRRC_LPHY_INTER_FREQ_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_UTRAN_CARRIER_MEAS_PARAM_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : UtranƵ���������
*****************************************************************************/
typedef struct
{
    VOS_UINT16                            usUtraArfcn;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enReducedMeasPerformance;               /* 3G TDD/FDD��Ч��GSM,CDMA��Ч */
}LRRC_LPHY_UTRAN_CARRIER_MEAS_PARAM_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_IRAT_FREQ_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��ϵͳƵ����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usArfcnNum;                             /* ��Ƶ����Ŀ */
    VOS_UINT16                          usHighPriorArfcnNum;                    /* �����ȼ�Ƶ����Ŀ��usArfcnNum-usHighPriorArfcnNumΪ�����ȼ�Ƶ����Ŀ */
    VOS_UINT16                          usMgsmNum;                              /* GSM�ز�������������̬��Ч��IDLE̬���ֶα��� */
    LRRC_LPHY_RAT_TYPE_ENUM_UINT16      enMeasRatType;
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                          usHighestPrior;                         /* ����Ƶ�������ȼ���ߵ����ȼ���IDLE̬��Ч��CONNECT̬��Ч*/
    VOS_UINT16                          usReserved;
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_UTRAN_CARRIER_MEAS_PARAM_STRU     astUtraCarrierMeasParam[LRRC_LPHY_MAX_UTRAN_CARRIER_NUM];
    VOS_UINT8                                   aucMeasPrior[LRRC_LPHY_MAX_NUM_OF_IRAT_MEAS_PRIO];  /* ÿ�����ȼ��м���Ƶ�� , IDLE̬��Ч��CONNECT̬��Ч */
    VOS_UINT8                                   aucReserved1[3];
#endif
}LRRC_LPHY_IRAT_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SECOND_FREQ_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��ƵС����Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usSecondFreqNum;                    /* ��Ƶ����Ŀ */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT8                               ucAllowInterruptions;               /* allowInterruptions: Value TRUE indicates that the UE is allowed to cause interruptions
                                                                                   to serving cells when performing measurements of deactivated SCell carriers for measCycleSCell
                                                                                   of less than 640ms, as specified in TS 36.133 [16]. E-UTRAN enables this field only when an SCell
                                                                                   is configured.*/
    VOS_UINT8                               ucReserved;
#else
    VOS_UINT16                              usReserved;
#endif
    LRRC_LPHY_SECOND_SINGLE_FREQ_INFO_STRU  astFreqList[LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM];
}LRRC_LPHY_SECOND_FREQ_INFO_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 ds-OccasionDuration-r12     CHOICE {
             durationFDD-r12                 INTEGER(1..maxDS-Duration-r12),
             durationTDD-r12                 INTEGER(2..maxDS-Duration-r12)
         },
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16     usModType;
    VOS_UINT16                              usDuration;                         /* ��λ: subframe */
}LRRC_LPHY_MEAS_DS_OCCA_DURAT_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usPhyCellId;
    VOS_UINT16                              usScrambleId;
    VOS_UINT8                               ucMeasCsiRsId;
    VOS_INT8                                cCsiRsIndividualOffset;             /*Q-OffsetRange:-24db~24db*/
    VOS_UINT8                               ucRsrcCfg;
    VOS_UINT8                               ucSubfrmOffset;
}LRRC_LPHY_MEAS_CSI_RS_CFG_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 dmtc-PeriodOffset-r12           CHOICE {
             ms40-r12                        INTEGER(0..39),
             ms80-r12                        INTEGER(0..79),
             ms160-r12                       INTEGER(0..159),
             ...
         },
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DMTC_PERIOD_ENUM_UINT8        enDmtcPeriodType;
    VOS_UINT8                               ucRsv;
    VOS_UINT16                              usDmtcPeriodOffset;                 /* ��λ:ms */
}LRRC_LPHY_MEAS_DMTC_PERIOD_OFFSET_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :ÿ������Ƶ�㶼���Զ�Ӧһ��DS����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;

    LRRC_LPHY_MEAS_DS_OCCA_DURAT_STRU       stDsOccaDuration;
    LRRC_LPHY_MEAS_DMTC_PERIOD_OFFSET_STRU  stDmtcPeriod;

    VOS_UINT16                              usRsv;
    VOS_UINT16                              usCsiCellNum;                       /* astCsiRsCfg�ĸ���.���ֻ��Ҫ��DMTC����Ϣ��������㣬�˲�������Ϊ0 */
    LRRC_LPHY_MEAS_CSI_RS_CFG_STRU          astCsiRsCfg[LRRC_LPHY_MAX_NUM_OF_CSI_RS];
}LRRC_LPHY_MEAS_DS_SINGLE_FREQ_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 MeasResultCSI-RS-r12 ::=        SEQUENCE {
     measCSI-RS-Id-r12               MeasCSI-RS-Id-r12,
     csi-RSRP-Result-r12             CSI-RSRP-Range-r12,
     ...
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucMeasCsiRsId;
    VOS_UINT8                               aucRsv[1];
    VOS_UINT16                              usPhyCellId;
    VOS_UINT16                              usRsv;
    VOS_INT16                               sCsiRsrp;                           /* ��λ: 0.125dbm */
}LRRC_LPHY_MEAS_DS_CELL_RESULT_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;

    VOS_UINT16                              usTotalCellNum;
    VOS_UINT16                              usRsv;

    LRRC_LPHY_MEAS_DS_CELL_RESULT_STRU      astDsCellRslt[LRRC_LPHY_REPORT_MAX_FREQ_DS_CSI_NUM];
}LRRC_LPHY_MEAS_DS_SINGLE_FREQ_RESULT_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 MeasResultForRSSI-r13 ::=           SEQUENCE {
     rssi-Result-r13                         RSSI-Range-r13,
     channelOccupancy-r13                    INTEGER (0..100)
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;

    VOS_INT16                               sRssi;
    VOS_UINT8                               ucChnnlOccup;                  /* ��Χ 0~100 */
    VOS_UINT8                               ucRsv;
}LRRC_LPHY_MEAS_RSSI_RESULT_STRU;

#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_IRAT_IDLE_FREQ_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : IDLE��ϵͳ���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_IRAT_FREQ_INFO_STRU         stIratGsmFreqInfo;
    LRRC_LPHY_IRAT_FREQ_INFO_STRU         stIratUtraFreqInfo;
    LRRC_LPHY_IRAT_FREQ_INFO_STRU         stIratCdmaFreqInfo;    /* CDMA��ϵͳ������Ϣ */
}LRRC_LPHY_IRAT_IDLE_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_IRAT_CONN_FREQ_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CONN��ϵͳ���ݽṹ
*****************************************************************************/
typedef LRRC_LPHY_IRAT_IDLE_FREQ_INFO_STRU  LRRC_LPHY_IRAT_CONN_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_IN_IDLE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : IDLE�������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16    enCommand;                            /* �������� */
    LRRC_LPHY_RAT_TYPE_ENUM_UINT16        enRatType;                            /* ָʾ��ǰ��ģ���� */
    LRRC_LPHY_MEAS_TYPE_ENUM_UINT8        enMeasType;                           /* �������ͣ�0������������1�����β��� */
    VOS_UINT8                             ucRsvd;
    LRRC_LPHY_INTRA_FREQ_CELL_INFO_STRU   stIntraFreqCell;                      /* Ƶ�ڲ�����Ϣ */
    LRRC_LPHY_INTER_FREQ_CELL_INFO_STRU   stInterFreqCell;                      /* LTE����Ƶ������GU->LTE����ʱ,ͨ�����б����ò�����Ϣ */
    LRRC_LPHY_IRAT_IDLE_FREQ_INFO_STRU    stIratFreqInfo;                       /* LTE->GU����ʱ����ϵͳ������Ϣ */
}LRRC_LPHY_MEAS_IN_IDLE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_IN_IDLE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : IDLE�²����ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_MEAS_IN_IDLE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CELL_MEAS_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : С���������
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usCellId;
    VOS_INT16                           sRsrp;                                  /* RSRP����ֵ */
    VOS_INT16                           sRsrq;                                  /* RSRQ����ֵ */
    VOS_INT16                           sRssi;                                  /* RSSI����ֵ */
#if (FEATURE_ON == FEATURE_LTE_R13)
    VOS_UINT16                          usRsv;
    VOS_INT16                           sRsSinr;                                /* ��λ:0.25db.���û�в���SINR��LPHY�˲�����дRS SINR����Сֵ */
#endif
}LRRC_LPHY_CELL_MEAS_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_IDLE_SERV_CELL_MEAS_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : IDLE̬����С���������
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqInfo;                             /* ����С��Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    LRRC_LPHY_CELL_MEAS_RESULT_STRU     stMeasRslt;
}LRRC_LPHY_IDLE_SERV_CELL_MEAS_RESULT_STRU;
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 MeasResultForRSSI-r13 ::=           SEQUENCE {
     rssi-Result-r13                         RSSI-Range-r13,
     channelOccupancy-r13                    INTEGER (0..100)
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */

    VOS_INT16                           sRssi;                                  /*��λ:0.125dbm RSSI����ֵ */
    VOS_UINT16                          usRsv;
}LRRC_LPHY_LAA_SINGLE_FREQ_RSSI_RSLT_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                              usFreqNum;
    VOS_UINT16                              usRsv;

    LRRC_LPHY_LAA_SINGLE_FREQ_RSSI_RSLT_STRU astSnglFreqRssi[LRRC_LPHY_MAX_LAA_CC_NUM];
}LRRC_LPHY_LAA_RSSI_RSLT_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 MeasResultSSTD-r13 ::=                      SEQUENCE {
     sfn-OffsetResult-r13                        INTEGER (0..1023),
     frameBoundaryOffsetResult-r13               INTEGER (-4..5),
     subframeBoundaryOffsetResult-r13            INTEGER (0..63)
 }

 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usSfnOffsetRslt;
    VOS_INT16                           sFrmBndryOffsetRslt;
    VOS_INT16                           sSubfrmBndryOffsetRslt;                 /* ��λ: Ts,  PS���� 36.133ת��0~63�� */
    VOS_UINT16                          usRsv;
}LRRC_LPHY_SSTD_RSLT_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SINGLE_FREQ_MEAS_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����Ƶ��С���������
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    VOS_UINT16                          usTotalCellNum;
    VOS_UINT16                          usDetectedCellNum;

    VOS_UINT16                          usUeRxTxTimeDiffValidFlag;
    VOS_UINT16                          usUeRxTxTimeDiff;                        /* 0-4095 */
    VOS_UINT16                          usSfn;                                   /* 0-1023 ����RxTxʱ��SFNֵ*/
    VOS_UINT16                          usReserved;

    LRRC_LPHY_CELL_MEAS_RESULT_STRU     astCellMeasResult[LRRC_LPHY_REPORT_MAX_FREQ_CELL_NUM];/* SCELL���ڵ�һ����λ�� */
}LRRC_LPHY_SINGLE_FREQ_MEAS_RESULT_STRU;
typedef LRRC_LPHY_SINGLE_FREQ_MEAS_RESULT_STRU LRRC_LPHY_INTRA_FREQ_MEAS_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_INTER_FREQ_MEAS_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��ƵС���������
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usInterFreqNum;
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_SINGLE_FREQ_MEAS_RESULT_STRU        astInterFreqResultList[LRRC_LPHY_MAX_ADDITIONAL_CARRIER_NUM];
}LRRC_LPHY_INTER_FREQ_MEAS_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SECOND_FREQ_MEAS_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Secondary freqs С���������
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usSecondFreqNum;
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_SINGLE_FREQ_MEAS_RESULT_STRU        astSecondFreqResultList[LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM];
}LRRC_LPHY_SECOND_FREQ_MEAS_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_IN_IDLE_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : IDLE��������ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                    enMsgId;                    /*_H2ASN_Skip*/
    VOS_UINT16                                      usOpId;
    LRRC_LPHY_IDLE_MEAS_REPORT_TYPE_ENUM_UNIT16     enUnionStructSelChoice;     /* enReportType for ELF */
    union
    {
        LRRC_LPHY_IDLE_SERV_CELL_MEAS_RESULT_STRU   stServingCellResult;
        LRRC_LPHY_INTRA_FREQ_MEAS_RESULT_STRU       stIntraFreqResult;
        LRRC_LPHY_INTER_FREQ_MEAS_RESULT_STRU       stInterFreqResult;
    }u;

    VOS_UINT16                                      usNoRfValid;               /*DSDS�������� ��NORFָʾ*/
    VOS_UINT16                                      usRsved;
}LRRC_LPHY_MEAS_IN_IDLE_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_IN_CONNECTED_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CONNECTED�������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16    enCommand;
    LRRC_LPHY_RAT_TYPE_ENUM_UINT16        enRatType;                            /* ָʾ��ǰ��ģ���� */
    LRRC_LPHY_WCDMA_STATE_ENUM_UINT16     enWrrcState;                          /* WCDMA->LTE����ʱ,ָʾ��ǰWRRC��Э��״̬,CELL_PCH��URA_PCH״̬LTE RTT��Ҫ����IDLE̬��ʽ���в���,������������̬��ʽ */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT8                             enMeasGapFlg;                         /* ָʾ��Ƶ�����Ƿ���ҪGap */
    LRRC_LPHY_MEAS_TYPE_ENUM_UINT8        enMeasType;                           /* �������ͣ�0������������1�����β��� */

#else
    VOS_UINT8                             ucReserved;
    LRRC_LPHY_MEAS_TYPE_ENUM_UINT8        enMeasType;                           /* �������ͣ�0������������1�����β��� */
#endif

    LRRC_LPHY_CONN_MEAS_TYPE_ENUM_UINT16  enUnionStructSelChoice;               /* enMeasureType */
    union
    {
        LRRC_LPHY_INTRA_FREQ_CELL_INFO_STRU    stIntraFreqCell;                 /* PCELL�ŵ�����Ϊ0�ĵط� */
        LRRC_LPHY_INTER_FREQ_CELL_INFO_STRU    stInterFreqCell;                 /* LTE����Ƶ������GU->LTE����ʱ,ͨ�����б����ò�����Ϣ */
        LRRC_LPHY_IRAT_CONN_FREQ_INFO_STRU     stIratFreqInfo;                  /* LTE->GU����ʱ����ϵͳ������Ϣ */
        LRRC_LPHY_SECOND_FREQ_INFO_STRU        stSecondFreqInfo;                /* ���������PSCELL��Ӧ��Ƶ�㣬PSCELL�ŵ���ӦƵ���С���б�����Ϊ0�ĵط� */
    }u;
}LRRC_LPHY_MEAS_IN_CONNECTED_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_IN_CONNECTED_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CONNECTED�²����ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_MEAS_IN_CONNECTED_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_IN_CONNECTED_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CONNECTED��������ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                      enMsgId;                  /*_H2ASN_Skip*/
    VOS_UINT16                                        usOpId;

    /* BOSTON��ʼ��enReportType ����ȡȥ��ö��ֵ������ʹ�õĽṹ��:
      1.ΪLRRC_LPHY_CONN_MEAS_REPORT_INTRAʱ�� ʹ��stIntraFreqResult�ϱ�����ͬƵ��С���������ȥPCELL��С��;
      2.ΪLRRC_LPHY_CONN_MEAS_REPORT_MCG_PCELLʱ�� ʹ��stIntraFreqResult�ϱ�PCELL��С��������Я��С������Ϊ1;
      3.ΪLRRC_LPHY_CONN_MEAS_REPORT_INTERʱ��ʹ��stInterFreqResult�ϱ�������ƵС��������;
      4.ΪLRRC_LPHY_CONN_MEAS_REPORT_SECOND_FREQʱ��ʹ��stSecondFreqResult�ϱ�����second cc��С���������� ��ȥPSCELL���ڵ�Ƶ��;
      5.ΪLRRC_LPHY_CONN_MEAS_REPORT_SCG_PSCELLʱ��ʹ��stSecondFreqResult�ϱ�PSCELLС��������;stSecondFreqResultƵ����Ϊ1��С������Ϊ1;
      6.ΪLRRC_LPHY_CONN_MEAS_REPORT_SCG_PSCELL_INTRAʱ��ʹ��stSecondFreqResult�ϱ�PSCELLС������Ƶ��ĸ���С��������;��ȥPSCELL֮��*/
    LRRC_LPHY_CONN_MEAS_REPORT_TYPE_ENUM_UNIT16       enUnionStructSelChoice;   /* enReportType */
    union
    {
        LRRC_LPHY_INTRA_FREQ_MEAS_RESULT_STRU         stIntraFreqResult;
        LRRC_LPHY_INTER_FREQ_MEAS_RESULT_STRU         stInterFreqResult;
        LRRC_LPHY_SECOND_FREQ_MEAS_RESULT_STRU        stSecondFreqResult;
    }u;
}LRRC_LPHY_MEAS_IN_CONNECTED_IND_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_TX_PWR_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : TXPOWER���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16     sPuschPwr;
    VOS_INT16     sPucchPwr;
    VOS_INT16     sSrsPwr;
    VOS_INT16     sPrachPwr;
}LRRC_LPHY_TX_PWR_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MCS_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MCS���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16     usUlMcs;
    VOS_UINT16     usDlMcs[2];
    VOS_UINT8      aucRes[2];
}LRRC_LPHY_MCS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RX_ANT_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RxAnt���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                       ucRxANTNum;        /* �������� */
    VOS_UINT8                                       aucRev[3];
    VOS_INT16                                       asRsrpRx[LRRC_LPHY_MAX_RX_ANT_NUM];       /* 1/8db���� */
    VOS_INT32                                       alSINRRx[LRRC_LPHY_MAX_RX_ANT_NUM];       /* 1db���� */
} LRRC_LPHY_RX_ANT_INFO_STRU;

/*NMR begin*/
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CQIs���ݽṹ
*****************************************************************************/
typedef struct
{   VOS_UINT16                                      ausCQI[2];
    VOS_UINT16                                      usRI;
    VOS_UINT8                                       aucRes[2];
} LRRC_LPHY_CQI_INFO_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_INFO_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����ϱ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                     /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                    enMsgId;           /*_H2ASN_Skip*/
    VOS_UINT16                                      usOpId;
    VOS_UINT16                                      usTa;
    VOS_INT32                                       lSINR;
    LRRC_LPHY_CQI_INFO_STRU                         stCQI;
    LRRC_LPHY_TX_PWR_INFO_STRU                      stTxPwrInfo;
    LRRC_LPHY_MCS_INFO_STRU                         stMcsInfo;
    LRRC_LPHY_RX_ANT_INFO_STRU                      stRxAntInfo;
}LRRC_LPHY_MEAS_INFO_IND_STRU;
/*NMR end*/

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_GAP_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MEAS GAP������Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enMeasGapEnabled;                     /* 0:��ʾdeactivate,1:��ʾactivate��ͬʱ���������Ч */
    LRRC_LPHY_MEAS_GAP_TYPE_ENUM_UINT16   enMeasGapType;                        /* 0:��ʾgp1,1:��ʾgp2*/
    VOS_UINT16                            usMeasGapOffset;                      /* ���ӦenMeasGapType���͵�gapOffset */
    VOS_UINT16                            usMeasPeriod;                         /* �������� */
    VOS_UINT16                            usMinIntraCellNum;                    /* ͬƵС����,����36.133���� */
}LRRC_LPHY_MEAS_GAP_CONFIG_REQ_STRU;


#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_SCAL_FACTOR_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Scale Factor ������Ϣ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enMeasScaleFactorValidFlg;
    LRRC_LPHY_MEAS_SCAL_FAC_TYPE_ENUM_UINT8     enMeasScaleFactorSetup;
    VOS_UINT8                                   ucRsv;
}LRRC_LPHY_MEAS_SCAL_FACTOR_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_COMM_MEAS_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MEAS COMM������Ϣ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    VOS_UINT16                              usRsv;

    VOS_UINT32                              bitScaleFactorConfigPresent:1;      /* 1:��ʾstMeasScaleFactor��Ч;0��ʾstMeasScaleFactor��Ч */
    VOS_UINT32                              bitAllSymbolsConfigPresent:1;       /* 1:��ʾenMeasRSRQOnAllSymbols��Ч;0��ʾenMeasRSRQOnAllSymbols��Ч */
    VOS_UINT32                              bitSstdPresent:1;                   /* 1:��ʾenSstd��Ч;0��ʾenSstd��Ч */
    VOS_UINT32                              bitSpare:29;

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enMeasRSRQOnAllSymbols;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enSstd;                             /* reportSSTD-Meas-r13, �Ƿ��SSTD�Ĳ��� */
    LRRC_LPHY_MEAS_SCAL_FACTOR_STRU         stMeasScaleFactor;
}LRRC_LPHY_COMM_MEAS_CONFIG_REQ_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MEAS_GAP_CONFIG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MEAS GAP���ûظ���Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_MEAS_GAP_CONFIG_CNF_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
typedef LRRC_LPHY_MEAS_GAP_CONFIG_CNF_STRU LRRC_LPHY_COMM_MEAS_CONFIG_CNF_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RELALL_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ָʾɾ������������ŵ���Ϣ���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    VOS_UINT16                            usReserved;
}LRRC_LPHY_RELALL_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RELALL_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ɾ��������ŵ��ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_RELALL_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_CONFIG_INDEX_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usCqiPmiConfigIdx2;           /* cqi-pmi-ConfigIndex2-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enRiConfigIdx2ValidFlg;       /* ri-ConfigIndex2-r10�Ƿ���Ч��ʾ */
    VOS_UINT16                                    usRiConfigIdx2;               /* ri-ConfigIndex2-r10 */
    VOS_UINT16                                    usReserved;
}LRRC_LPHY_CSI_CONFIG_INDEX_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_SUBBAND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_SUBBAND_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usCqiSubBand_k;               /* k */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPeriodicFactorValidFlg;
    LRRC_LPHY_PERIODIC_FACTOR_ENUM_UINT16         enPeriodicFactor;             /* periodicityFactor-r10 */
    VOS_UINT16                                    usReserved;
}LRRC_LPHY_CQI_SUBBAND_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CRI_RPRT_CFG_INDEX_STRU
 Э����  :
 ASN.1���� : CRI-ReportConfig-r13
 �ṹ˵��  : LRRC_LPHY_CRI_RPRT_CFG_INDEX_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                  usCriCfgIndex;                  /*  cri-ConfigIndex-r13 CRI-ConfigIndex-r13, */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enCriCfgIndex2Flg;
    VOS_UINT16                                  usCriCfgIndex2;                 /*  cri-ConfigIndex2-r13 CRI-ConfigIndex-r13 OPTIONAL-- Need OR */
    VOS_UINT16                                  usRsv;
}LRRC_LPHY_CRI_RPRT_CFG_INDEX_STRU;
#endif

#if (FEATURE_ON == FEATURE_LTE_R11)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usCqiRptPeriodProcExtId;      /* cqi-ReportPeriodicProcExtId-r11 INTEGER (1..maxCQI-ProcExt-r11) */
    VOS_UINT16                                    usCqiPmiConfigIndex;          /* cqi-pmi-ConfigIndex-r11			INTEGER (0..1023) */
    LRRC_LPHY_CQI_FORMATE_IND_TYPE_ENUM_UINT16    enCqiFormatIndPeriodic;       /* cqi-FormatIndicatorPeriodic-r11 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiWideBandCsiRptModeValidFlg;        /* enCqiWideBandCsiRptMode�Ƿ���Ч */
    LRRC_LPHY_CQI_REPORT_MODE_ENUM_UINT16         enCqiWideBandCsiRptMode;                /* widebandCQI-r11 */
    VOS_UINT16                                    usRiConfigIndex;              /* ri-ConfigIndex-r11 --Need OR	INTEGER (0..1023) 0xFFFF��Чֵ */
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiConfigIdxValidFlg;       /* csi-ConfigIndex-r11 �Ƿ���Ч */
    LRRC_LPHY_CSI_CONFIG_INDEX_STRU               stCsiConfigIdx;               /* csi-ConfigIndex-r11 --Need ON */
    LRRC_LPHY_CQI_SUBBAND_STRU                    stCqiSubBand;                 /* subbandCQI-r11 */

#if (FEATURE_ON == FEATURE_LTE_R13)
    VOS_UINT16                                    usRsv;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCriRprtCfgIndexFlg;
    LRRC_LPHY_CRI_RPRT_CFG_INDEX_STRU             stCriRprtCfgIndex;              /* CRI-ReportConfig-r13 */
#endif
}LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usCqiProcExtNum;                   /* С������ (1..maxCQI-ProcExt-r11) */
    VOS_UINT16                                      usResered;
    LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_STRU     astCqiProcExtInfo[LRRC_LPHY_MAX_CQI_PROC_EXT_NUM]; /* CQI-ReportPeriodicProcExt-r11 */
}LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_IM_CONFIG_STRU
 Э����  : CSI-IM-Config-r11
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_IM_CONFIG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usCsiIMCfgId;               /* csi-IM-ConfigId-r11 */
    VOS_UINT16                                      usResourcecfg;              /* resourceConfig-r11 (0..31) */
    VOS_UINT16                                      usSfCfg;                    /* subframeConfig-r11 (0..154) */

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enIntrfrncMeasRstrctn;      /* interferenceMeasRestriction-r13 BostonĬ�ϲ�֧�� */
#else
    VOS_UINT16                                      usResered;
#endif
}LRRC_LPHY_CSI_IM_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_IM_CONFIG_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_IM_CONFIG_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usCsiIMCfgNum;              /* С������ (1..maxCSI-IM-r11) */
    VOS_UINT16                                      usResered;
    LRRC_LPHY_CSI_IM_CONFIG_STRU                    astCsiIMCfg[LRRC_LPHY_MAX_CSI_IM_NUM]; /* CSI-IM-Config-r11 */
}LRRC_LPHY_CSI_IM_CONFIG_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_P_C_AND_CBSR_STRU
 Э����  : p-C-AndCBSR-r11
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_P_C_AND_CBSR_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_INT16                                       sPC;                        /* p-C-r11 INTEGER (-8..15) */
    LRRC_LPHY_CODE_BOOK_TYPE_ENUM_UINT16            enCodeBookType;             /* ָʾ��ǰʹ�õ�������Ӽ��������� */
    /* 36.213 Table 7.2-1b TM10 n2/n4/n8�����Ҫ109BITS */
    VOS_UINT32                                      aulCodebookSubsetRestriction[4]; /* ������Ӽ�����,Little-Endian�ֽ��� */
}LRRC_LPHY_P_C_AND_CBSR_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_P_C_AND_CBSR_LIST_STRU
 Э����  : p-C-AndCBSRList-r11
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_P_C_AND_CBSR_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usPCAndCBSRNum;             /* ���� (1..2) */
    VOS_UINT16                                      usResered;
    LRRC_LPHY_P_C_AND_CBSR_STRU                     astPCAndCBSR[2];            /* P-C-AndCBSR-r11 */
}LRRC_LPHY_P_C_AND_CBSR_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_BOTH_PROC_STRU
 Э����  : CQI-ReportBothProc-r11
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_BOTH_PROC_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enRiRefCSIProcIdEnabled;    /* usRiRefCSIProcId �Ƿ�ʹ�� */
    VOS_UINT16                                      usRiRefCSIProcId;           /* ri-Ref-CSI-ProcessId-r11 --Need OR */
    VOS_UINT16                                      usResered;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPmiRIReportEnabled;       /* pmi-RI-Report-r11 --Need OR */
}LRRC_LPHY_CQI_REPORT_BOTH_PROC_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_APERIODIC_PROC_R11_STRU
 Э����  : CQI-ReportAperiodicProc-r11
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_APERIODIC_PROC_R11_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CQI_MODEA_PERIODIC_ENUM_UINT16        enCqiRptModeAperiodic;      /* cqi-ReportModeAperiodic-r11 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enTrigger01Enabled;         /* trigger01-r11 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enTrigger10Enabled;         /* trigger10-r11 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enTrigger11Enabled;         /* trigger11-r11 */
}LRRC_LPHY_CQI_REPORT_APERIODIC_PROC_R11_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_PROCESS_STRU
 Э����  : CSI-Process-r11
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_PROCESS_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usCsiProcId;                /* csi-ProcessId-r11 */
    VOS_UINT16                                      usCsiRSCfgNZPId;            /* csi-RS-ConfigNZPId-r11 */
#if (FEATURE_ON == FEATURE_LTE_R13)
    VOS_UINT16                                      usCsiIMCfgNum;              /* csi-IM-ConfigIdList-r12 */
    VOS_UINT16                                      ausCsiIMCfgId[LRRC_LPHY_MAX_NUM_OF_CSI_IM_CONFIG_ID]; /* csi-IM-ConfigIdList-r12 */
#else
    VOS_UINT16                                      usCsiIMCfgId;               /* csi-IM-ConfigId-r11 */
#endif
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCqiRptPeriodProcIdValidFlg;/* usCqiRptPeriodProcId �Ƿ���Ч */
    VOS_UINT16                                      usCqiRptPeriodProcId;       /* cqi-ReportPeriodicProcId-r11 --Need OR */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCqiRptBothProcValidFlg;   /* stCqiRptBothProc �Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCqiRptAperiodProcR11ValidFlg;/* stCqiRptAperiodProcR11 �Ƿ���Ч */
    VOS_UINT16                                      usResered;

    LRRC_LPHY_CQI_REPORT_BOTH_PROC_STRU             stCqiRptBothProc;           /* cqi-ReportBothProc-r11 --Need OR */
    LRRC_LPHY_CQI_REPORT_APERIODIC_PROC_R11_STRU    stCqiRptAperiodProcR11;     /* cqi-ReportAperiodicProc-r11 --Need OR */
    LRRC_LPHY_P_C_AND_CBSR_LIST_STRU                stPCAndCBSRList;            /* p-C-AndCBSRList-r11 */

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enAlternativeCodebookEnabledFor4TxProc; /* alternativeCodebookEnabledFor4TXProc-r12 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCqiRptAperiodProcFlg;     /* cqi-ReportAperiodicProc2-r12 �Ƿ���Ч */
    LRRC_LPHY_CQI_REPORT_APERIODIC_PROC_R11_STRU    stCqiRptAperiodProc;        /* cqi-ReportAperiodicProc2-r12 ����r11�Ľṹ��һ�� */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCqiRprtAprdcProcFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCqiRprtAprdcProc2Flg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enCsiRsEMimoFlg;            /* BostonĬ�ϲ�֧�� */
    VOS_UINT16                                      usRsv1;
    LRRC_LPHY_CQI_RPRT_APRDC_PROC_TRIG_BIT_STRU     stCqiRprtAprdcProcTrigBit;  /* cqi-ReportAperiodicProc-v1310 */
    LRRC_LPHY_CQI_RPRT_APRDC_PROC_TRIG_BIT_STRU     stCqiRprtAprdcProc2TrigBit; /* cqi-ReportAperiodicProc2-v1310->cqi-ReportAperiodicProc-v1310 */
    LRRC_LPHY_CSI_RS_EMIMO_STRU                     stCsiRsEMimo;               /* eMIMO-Type-r13 CSI-RS-ConfigEMIMO-r13 */

#endif
}LRRC_LPHY_CSI_PROCESS_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CSI_PROCESS_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CSI_PROCESS_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usCsiProcNum;               /* С������ (1..maxCSI-Proc-r11) */
    VOS_UINT16                                      usResered;
    LRRC_LPHY_CSI_PROCESS_STRU                      astCsiProc[LRRC_LPHY_MAX_CSI_PROC_NUM]; /* CSI-Process-r11 */
}LRRC_LPHY_CSI_PROCESS_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_BOTH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_BOTH_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enCsiIMCfgListFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enCsiProcListFlg;

    LRRC_LPHY_CSI_IM_CONFIG_LIST_STRU     stCsiIMCfgList;                       /* csi-IM-ConfigToAddModList-r11 */
    LRRC_LPHY_CSI_PROCESS_LIST_STRU       stCsiProcList;                        /* csi-ProcessToAddModList-r11 */
}LRRC_LPHY_CQI_REPORT_BOTH_STRU;
#endif


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_PERIODIC_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_PERIODIC_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usCqiPucchResIdx;             /* cqi-PUCCH-ResourceIndex */
    VOS_UINT16                                    usCqiPmiConfigIdx;            /* cqi-pmi-ConfigIndex */
    VOS_UINT16                                    usRiConfigIdx;                /* ri-ConfigIndex */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAnAndCqiValidFlg;           /* simultaneousAckNackAndCQI */
    LRRC_LPHY_CQI_FORMATE_IND_TYPE_ENUM_UINT16    enCqiFormatIndPeriodic;       /* cqi-FormatIndicatorPeriodic */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiPucchResIdxP1ValidFlg;   /* usCqiPucchResIdxP1_r10�Ƿ���Ч */
    VOS_UINT16                                    usCqiPucchResIdxP1;           /* cqi-PUCCH-ResourceIndexP1-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiConfigIdxValidFlg;       /* csi-ConfigIndex-r10 */
    LRRC_LPHY_CSI_CONFIG_INDEX_STRU               stCsiConfigIdx;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiWideBandCsiRptModeValidFlg;        /* enCqiWideBandCsiRptMode�Ƿ���Ч */
    LRRC_LPHY_CQI_REPORT_MODE_ENUM_UINT16         enCqiWideBandCsiRptMode;                /* widebandCQI-r10:csi-ReportMode-r10 */
    LRRC_LPHY_CQI_SUBBAND_STRU                    stCqiSubBand;                 /* subbandCQI-r10 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16                   enSimultAckNackAndCqiFormat3Enabled; /* simultaneousAckNackAndCQI-Format3-r11 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16               enCqiRptPeriodProcExtListFlg; /* stCqiRptPeriodProcExtList��Ч��ʶ */
    LRRC_LPHY_CQI_REPORT_PERIODIC_PROC_EXT_LIST_STRU    stCqiRptPeriodProcExtList;
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16           enSimAckNackAndCqiFrm4Frm5;     /* simultaneousAckNackAndCQI-Format4-Format5-r13 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16       enCriRprtCfgIndexFlg;
    LRRC_LPHY_CRI_RPRT_CFG_INDEX_STRU           stCriRprtCfgIndex;              /* CRI-ReportConfig-r13 */
#endif
}LRRC_LPHY_CQI_REPORT_PERIODIC_INFO_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPRT_APRDC_SFM_SET_IND_STRU
 Э����  :
 ASN.1���� :

 CQI-ReportAperiodic-v1250   ::=     CHOICE {
     release                             NULL,
     setup                               SEQUENCE {
         aperiodicCSI-Trigger-v1250          SEQUENCE {
             trigger-SubframeSetIndicator-r12    ENUMERATED {s1, s2},
             trigger1-SubframeSetIndicator-r12   BIT STRING (SIZE (8)),
             trigger2-SubframeSetIndicator-r12   BIT STRING (SIZE (8))
         }
     }
 }
 �ṹ˵��  : LRRC_LPHY_CQI_RPRT_APRDC_SFM_SET_IND_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_TRIG_SUBFRAME_SET_IND_ENUM_UINT8  enTrigSubframeSetInd;
    VOS_UINT8                                   ucTrig1SubframeSetInd;
    VOS_UINT8                                   ucTrig2SubframeSetInd;
    VOS_UINT8                                   ucReserved;
}LRRC_LPHY_CQI_RPRT_APRDC_SFM_SET_IND_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_REPORT_APERIODIC_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_REPORT_APERIODIC_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CQI_MODEA_PERIODIC_ENUM_UINT16      enCqiRptModeAType;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiAperiodicTrigValidFlg; /* aperiodicCSI-Trigger-r10�Ƿ���Ч */
    VOS_UINT16                                    ausTrigger[2];
}LRRC_LPHY_CQI_REPORT_APERIODIC_STRU;
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG_STRU
 Э����  :
 ASN.1���� :
 aperiodicCSI-Trigger-v1310          SEQUENCE {
             trigger1-r13                    BIT STRING (SIZE (32)),
             trigger2-r13                    BIT STRING (SIZE (32)),
             ......
 �ṹ˵��  : LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                    aulTrig[LRRC_LPHY_APRDC_CQI_MAX_TRIG_NUM];
}LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG2_STRU
 Э����  :
 ASN.1���� : aperiodicCSI-Trigger2-r13
 �ṹ˵��  : LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG2_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                    aulTrigSfrmSetInd[LRRC_LPHY_APRDC_CQI_MAX_TRIG_NUM];
}LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG2_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPRT_APRDC_R13_STRU
 Э����  :
 ASN.1���� : CQI-ReportAperiodic-v1310
 �ṹ˵��  : LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAperiodicCsiTrigFlg;        /* aperiodicCSI-Trigger-v1310�Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAperiodicCsiTrig2Flg;       /* aperiodicCSI-Trigger2-r13�Ƿ���Ч */

    LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG_STRU        stAperiodicCsiTrig;           /* CQI-ReportAperiodic-v1310----> aperiodicCSI-Trigger-v1310 */
    LRRC_LPHY_CQI_RPRT_APRDC_CSI_TRIG2_STRU       stAperiodicCsiTrig2;          /* CQI-ReportAperiodic-v1310----> aperiodicCSI-Trigger2-r13 */
}LRRC_LPHY_CQI_RPRT_APRDC_R13_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPT_CONFIG_PCELL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_RPT_CONFIG_PCELL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CQI_TYPE_ENUM_UINT16                enCqiType;                    /* CQI���� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiRptModeAperiodicValidFlg;/* stCqiRptAperiodic�Ƿ���Ч */
    VOS_INT16                                     sNomPdschRsEpreOffset;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enCqiRptPeriodicEnabled;      /* 0:��ʾstCqiRptPeriodicInfo��Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiMaskValidFlg;            /* 0:��ʾ�ò�����Ч��1:��ʾ�ò�����Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPmiRiReportValidFlg;        /* 0:��ʾ�ò�����Ч��1:��ʾ�ò�����Ч */
    LRRC_LPHY_CQI_REPORT_PERIODIC_INFO_STRU       stCqiRptPeriodicInfo;
    LRRC_LPHY_CQI_REPORT_APERIODIC_STRU           stCqiRptAperiodic;            /* CQI-ReportAperiodic-r10 */
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiSFPatCfgValidFlg;        /* astCsiMeasSFSet�Ƿ���Ч */
    LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU          astCsiMeasSFSet[2];
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_CQI_REPORT_BOTH_STRU                stCqiRptBoth;                 /* CQI-ReportBoth-r11 */
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiMeasSubframeSetsValidFlg;/* usCsiMeasSubframeSets�Ƿ���Ч */
    VOS_UINT16                                    usCsiMeasSubframeSets;        /* csi-MeasSubframeSets-r12 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAltCqiTableValidFlg;        /* usCsiMeasSubframeSets�Ƿ���Ч */
    LRRC_LPHY_ALT_CQI_TABLE_ENUM_UINT8            enAltCqiTable;                /* altCQI-Table-r12 */
    VOS_UINT8                                     aucReserved[1];

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAperiodicSubFrameSetFlg;    /* stAperiodicSubFrameSetInd�Ƿ���Ч */
    VOS_UINT16                                    usRsv;
    LRRC_LPHY_CQI_RPRT_APRDC_SFM_SET_IND_STRU     stAperiodicSubFrameSetInd;    /* aperiodicCSI-Trigger-v1250  */

    LRRC_LPHY_CQI_RPRT_APRDC_R13_STRU             stCqiRprtAprdcR13;            /* CQI-ReportAperiodic-v1310 */

#endif
}LRRC_LPHY_CQI_RPT_CONFIG_PCELL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPT_CONFIG_SCELL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_RPT_CONFIG_SCELL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CQI_TYPE_ENUM_UINT16                enCqiType;                    /* CQI���� */
    VOS_UINT16                                    usSCellIdx;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiRptModeAperiodicValidFlg;/* enCqiRptModeAType�Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiRptPeriodicValidFlg;     /* stCqiRptPeriodicInfoSCell�Ƿ���Ч */
    LRRC_LPHY_CQI_REPORT_APERIODIC_STRU           stCqiRptAperiodic;            /* CQI-ReportAperiodic-r10 */
    LRRC_LPHY_CQI_REPORT_PERIODIC_INFO_STRU       stCqiRptPeriodicInfo;         /* cqi-ReportPeriodicSCell-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiMaskValidFlg;            /* 0:��ʾ�ò�����Ч��1:��ʾ�ò�����Ч */
    VOS_INT16                                     sNomPdschRsEpreOffset;        /* nomPDSCH-RS-EPRE-Offset-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPmiRiReportValidFlg;        /* 0:��ʾ�ò�����Ч��1:��ʾ�ò�����Ч */
    VOS_UINT16                                    usReserved;
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_CQI_REPORT_BOTH_STRU                stCqiRptBoth;                 /* CQI-ReportBoth-r11 */
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiMeasSubframeSetsValidFlg;/* usCsiMeasSubframeSets�Ƿ���Ч */
    VOS_UINT16                                    usCsiMeasSubframeSets;        /* csi-MeasSubframeSets-r12 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAltCqiTableValidFlg;        /* usCsiMeasSubframeSets�Ƿ���Ч */
    LRRC_LPHY_ALT_CQI_TABLE_ENUM_UINT8            enAltCqiTable;                /* altCQI-Table-r12 */
    VOS_UINT8                                     aucReserved[1];

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAperiodicSubFrameSetFlg;    /* stAperiodicSubFrameSetInd�Ƿ���Ч */
    VOS_UINT16                                    usRsv;
    LRRC_LPHY_CQI_RPRT_APRDC_SFM_SET_IND_STRU     stAperiodicSubFrameSetInd;    /* aperiodicCSI-Trigger-v1250  */

    LRRC_LPHY_CQI_RPRT_APRDC_R13_STRU             stCqiRprtAprdcR13;            /* CQI-ReportAperiodic-v1310 */
#endif

}LRRC_LPHY_CQI_RPT_CONFIG_SCELL_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_RPT_CONFIG_PCELL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_RPT_CONFIG_PCELL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CQI_TYPE_ENUM_UINT16                enCqiType;                    /* CQI���� */
    VOS_UINT16                                    usSCellIdx;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiRptModeAperiodicValidFlg;/* stCqiRptAperiodic�Ƿ���Ч */
    VOS_INT16                                     sNomPdschRsEpreOffset;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enCqiRptPeriodicEnabled;      /* 0:��ʾstCqiRptPeriodicInfo��Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCqiMaskValidFlg;            /* 0:��ʾ�ò�����Ч��1:��ʾ�ò�����Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPmiRiReportValidFlg;        /* 0:��ʾ�ò�����Ч��1:��ʾ�ò�����Ч */
    LRRC_LPHY_CQI_REPORT_PERIODIC_INFO_STRU       stCqiRptPeriodicInfo;
    LRRC_LPHY_CQI_REPORT_APERIODIC_STRU           stCqiRptAperiodic;            /* CQI-ReportAperiodic-r10 */
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiSFPatCfgValidFlg;        /* astCsiMeasSFSet�Ƿ���Ч */
    LRRC_LPHY_MEAS_SUBFRAME_PATTERN_STRU          astCsiMeasSFSet[2];
    LRRC_LPHY_CQI_REPORT_BOTH_STRU                stCqiRptBoth;                 /* CQI-ReportBoth-r11 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCsiMeasSubframeSetsValidFlg;/* usCsiMeasSubframeSets�Ƿ���Ч */
    VOS_UINT16                                    usCsiMeasSubframeSets;        /* csi-MeasSubframeSets-r12 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAltCqiTableValidFlg;        /* usCsiMeasSubframeSets�Ƿ���Ч */
    LRRC_LPHY_ALT_CQI_TABLE_ENUM_UINT8            enAltCqiTable;                /* altCQI-Table-r12 */
    VOS_UINT8                                     aucReserved[1];

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enAperiodicSubFrameSetFlg;    /* stAperiodicSubFrameSetInd�Ƿ���Ч */
    VOS_UINT16                                    usRsv;
    LRRC_LPHY_CQI_RPRT_APRDC_SFM_SET_IND_STRU     stAperiodicSubFrameSetInd;    /* aperiodicCSI-Trigger-v1250  */

    LRRC_LPHY_CQI_RPRT_APRDC_R13_STRU             stCqiRprtAprdcR13;            /* CQI-ReportAperiodic-v1310 */

}LRRC_LPHY_CQI_RPT_CONFIG_PSCELL_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CQI�����������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
    VOS_UINT16                          usCqiCfgNum;                            /* ָʾ���ν�����CQI�������� */
    VOS_UINT16                          usParaSize;                             /* ָʾ���ν�����CQI���ò������ܳ��� */
    VOS_UINT8                           aucCqiCfgPara[4];                       /* CQI���ò��� */
}LRRC_LPHY_CQI_CONFIG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CQI_CONFIG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CQI_CONFIG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_CQI_CONFIG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_COMM_INFO_STRU
 Э����  : RadioResourceConfigCommonSIB->SoundingRsUl-ConfigCommon
             RadioResourceConfigCommon->SoundingRsUl-ConfigCommon
 ASN.1���� :
 �ṹ˵��  : ���ù���SRS���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM_UINT16        enSrsBandWidth;               /* srsBandwidthConfiguration */
    LRRC_LPHY_SRS_SUBFRAME_TYPE_ENUM_UINT16         enSrsSubFrame;                /* srsSubframeConfiguration */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enAnSrsTransValidFlg;         /* ackNackSrsSimultaneousTransmission */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enSrsMaxUpPtsValidFlg;        /* srsMaxUpPts */
}LRRC_LPHY_SRS_COMM_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_DEDICATED_INFO_STRU
 Э����  : PhysicalConfigDedicated->SoundingRsUl-ConfigDedicated
 ASN.1���� :
 �ṹ˵��  : ����ר��SRS���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM_UINT16        enSrsBandWidth;               /* srsBandwidth */
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_ENUM_UINT16     enSrsHoppingBandWidth;        /* srsHoppingBandwidth */
    VOS_UINT16                                      usFreqDomainPos;              /* frequencyDomainPosition */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDurationValidFlg;           /* duration */
    VOS_UINT16                                      usSrsConfigIdx;               /* srs-ConfigurationIndex */
    VOS_UINT16                                      usTransComb;                  /* transmissionComb */
    LRRC_LPHY_CYCLIC_SHIFT_ENUM_UINT16              enCyclicShift;                /* cyclicShift */
    VOS_UINT16                                      usReserved;
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enTransCombNumValidFlg;
    VOS_UINT16                                      usTransCombNum;             /* transmissionCombNum-r13 */
#endif
}LRRC_LPHY_SRS_DEDICATED_INFO_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_DEDICATED_UP_PTS_STRU
 Э����  : PhysicalConfigDedicated->SoundingRS-UL-ConfigDedicatedUpPTsExt
 ASN.1���� : SoundingRS-UL-ConfigDedicatedUpPTsExt-r13
 �ṹ˵��  : ����ר��SRS���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usSrsUpPtsAdd;                /* srs-UpPtsAdd-r13 */
    LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM_UINT16        enSrsBandWidth;               /* srsBandwidth */
    LRRC_LPHY_SRS_HOPPING_BANDWIDTH_ENUM_UINT16     enSrsHoppingBandWidth;        /* srsHoppingBandwidth */
    VOS_UINT16                                      usFreqDomainPos;              /* frequencyDomainPosition */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDurationValidFlg;           /* duration */
    VOS_UINT16                                      usSrsConfigIdx;               /* srs-ConfigurationIndex */
    VOS_UINT16                                      usTransComb;                  /* transmissionComb */
    LRRC_LPHY_CYCLIC_SHIFT_ENUM_UINT16              enCyclicShift;                /* cyclicShift */


    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enTransCombNumValidFlg;
    VOS_UINT16                                      usTransCombNum;             /* transmissionCombNum-r13 */

}LRRC_LPHY_SRS_DEDICATED_UP_PTS_STRU;

#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_CONFIG_AP_STRU
 Э����  : SRS-ConfigAp-r10
 ASN.1���� :
 �ṹ˵��  : ����ר��SRS���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SRS_ANTANNA_PORT_ENUM_UINT16          enSrsAntennaPortAp;         /* srs-AntennaPortAp-r10 */
    LRRC_LPHY_SRS_BANDWIDTH_TYPE_ENUM_UINT16        enSrsBandWidthAp;           /* srs-BandwidthAp-r10 */
    VOS_UINT16                                      usFreqDomainPositionAp;     /* freqDomainPositionAp-r10 */
    VOS_UINT16                                      usTransCombAp;              /* transmissionCombAp-r10 */
    LRRC_LPHY_CYCLIC_SHIFT_ENUM_UINT16              enCyclicShiftAp;            /* cyclicShiftAp-r10 */
    VOS_UINT16                                      usReserved;
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enTransCombNumValidFlg;
    VOS_UINT16                                      usTransCombNum;             /* transmissionCombNum-r13 */
#endif
}LRRC_LPHY_SRS_CONFIG_AP_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_DEDICATED_INFO_STRU
 Э����  : PhysicalConfigDedicated->SoundingRS-UL-ConfigDedicatedAperiodic-r10
 ASN.1���� :
 �ṹ˵��  : ����ר�з�����SRS���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usSrsCfgIndexAp;         /* srs-ConfigIndexAp-r10 */
    VOS_UINT16                                      usSrsCfgApDciFormat4Cnt; /* astSrsConfigApDciFormat4���� */
    LRRC_LPHY_SRS_CONFIG_AP_STRU                    astSrsCfgApDciFormat4[LRRC_LPHY_MAX_SRS_CFG_AP_DCI_FORMAT4_NUM];
    VOS_UINT16                                      usReserved;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enSrsCfgApDciFormat0And1ValidFlg; /* stSrsConfigApDciFormat0��stSrsConfigApDciFormat1a2b2c�Ƿ���Ч */
    LRRC_LPHY_SRS_CONFIG_AP_STRU                    stSrsCfgApDciFormat0;
    LRRC_LPHY_SRS_CONFIG_AP_STRU                    stSrsCfgApDciFormat1a2b2c;
}LRRC_LPHY_SRS_DEDI_APERIOD_INFO_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_DEDI_APRD_UP_PTS_STRU
 Э����  : PhysicalConfigDedicated->SoundingRS-UL-ConfigDedicatedAperiodicUpPTsExt-r13
 ASN.1���� :
 �ṹ˵��  : ����ר�з�����SRS���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                      usSrsUpPtsAdd;              /* srs-UpPtsAdd-r13 */
    VOS_UINT16                                      usSrsCfgIndexAp;            /* srs-ConfigIndexAp-r10 */
    VOS_UINT16                                      usRsv;
    VOS_UINT16                                      usSrsCfgApDciFormat4Cnt;    /* astSrsConfigApDciFormat4���� */
    LRRC_LPHY_SRS_CONFIG_AP_STRU                    astSrsCfgApDciFormat4[LRRC_LPHY_MAX_SRS_CFG_AP_DCI_FORMAT4_NUM];
    VOS_UINT16                                      usReserved;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enSrsCfgApDciFormat0And1ValidFlg; /* stSrsConfigApDciFormat0��stSrsConfigApDciFormat1a2b2c�Ƿ���Ч */
    LRRC_LPHY_SRS_CONFIG_AP_STRU                    stSrsCfgApDciFormat0;
    LRRC_LPHY_SRS_CONFIG_AP_STRU                    stSrsCfgApDciFormat1a2b2c;
}LRRC_LPHY_SRS_DEDI_APRD_UP_PTS_STRU;
#endif
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_CONFIG_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����SRS���ݽṹ.PCELL��SCELL�ṹ��ͬ��ͨ��usSCellIdx���֡�
*****************************************************************************/
typedef struct
{
    VOS_UINT16                            usSCellIdx;                                 /* 0��ʾPCELL */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_SRS_TYPE_ENUM_UINT16        enSrsType;                                  /* SRS����,R12������������ */
#else
    VOS_UINT16                            usReserved1;
#endif
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enSrsCommInfoValidFlg;                      /* ����SRS�����Ƿ���Ч */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enSrsDedicatedInfoValidFlg;                 /* ר��SRS�����Ƿ���Ч */
    LRRC_LPHY_SRS_COMM_INFO_STRU          stSrsCommInfo;
    LRRC_LPHY_SRS_DEDICATED_INFO_STRU     stSrsDedicatedInfo;
    VOS_UINT16                            usReserved2;                                /* �����ֶ� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enSrsAntennaPortValidFlg;                   /* R10ר��SRS����enSrsAntennaPort�Ƿ���Ч */
    LRRC_LPHY_SRS_ANTANNA_PORT_ENUM_UINT16    enSrsAntennaPort;                       /* SRS���߿����� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enSrsDedicatedAperiodicInfoValidFlg;        /* R10 ������ר��SRS�����Ƿ���Ч */
    LRRC_LPHY_SRS_DEDI_APERIOD_INFO_STRU  stSrsDedicatedAperiodicInfo;                /* R10 ������ר��SRS���� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enstSrsDediUpPtsValidFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enSrsDedicatedAperiodicUpPtsInfoValidFlg;   /*  ������ר��SRS�����Ƿ���Ч */

    LRRC_LPHY_SRS_DEDICATED_UP_PTS_STRU   stSrsDediUpPts;
    LRRC_LPHY_SRS_DEDI_APRD_UP_PTS_STRU   stSrsDedicatedAperiodicUpPtsInfo;           /*  ������ר��SRS���� */
#endif
}LRRC_LPHY_SRS_CONFIG_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : SRS�����������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
    VOS_UINT16                          usSrsCfgNum;                            /* ָʾ���ν�����SRS�������� */
    VOS_UINT16                          usParaSize;                             /* ָʾ���ν�����SRS���ò������ܳ��� */
    VOS_UINT8                           aucSrsCfgPara[4];                       /* SRS���ò��� */
}LRRC_LPHY_SRS_CONFIG_REQ_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SRS_CONFIG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����SRS�ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_SRS_CONFIG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_HO_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �л��������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;
    VOS_UINT16                          usFreqInfo;
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16 enLteModeType;                          /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                          usCellId;
    LRRC_LPHY_HO_TYPE_ENUM_UINT16       enHoType;
#if (FEATURE_ON == FEATURE_LTE_R13)
    /* ����֡�ţ���֡�� */
    VOS_UINT16                          usFrameNo;                              /* 0-1023, 0xFFFF��ʾ��Ч */
    VOS_UINT8                           ucSubFrameNo;                           /* 0-9, 0xFFFF��ʾ��Ч */
    VOS_UINT8                           ucRsv1;
#endif
    VOS_UINT16                          usPhyChannelNum;
    VOS_UINT16                          usParaSize;
    VOS_UINT8                           aucPhyChannelPara[4];
}LRRC_LPHY_HO_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_HO_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �л��ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16        enResult;
    VOS_UINT16                          usNoRfValid;                            /*DSDS�������� ��NORFָʾ*/
    VOS_UINT16                          usRsved;
}LRRC_LPHY_HO_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DRX_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : DRX�����������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_DURATION_TIMER_ENUM_UINT16  enDurationTimer;                        /* onDurationTimer */
    LRRC_LPHY_INACTIVE_TIMER_ENUM_UINT16  enInactiveTimer;                        /* drx-InactivityTimer */
    LRRC_LPHY_RETRANS_TIMER_ENUM_UINT16   enReTransTimer;                         /* drx-RetransmissionTimer */
    LRRC_LPHY_LONG_DRX_OFFSET_ENUM_UINT16 enLongDrxOffsetType;                    /* longDRX-CycleStartOffset���� */
    VOS_UINT16                            usLongDrxStartOffse;                    /* longDRX-CycleStartOffset */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enShortDrxEnabled;                      /* 0:��ʾshortDRX��Ч */
    LRRC_LPHY_SHORT_DRX_CYCLE_ENUM_UINT16 enShortDrxCycle;                        /* shortDRX->shortDRX-Cycle */
    VOS_UINT16                            usShortDrxCycleTimer;                   /* shortDRX->drxShortCycleTimer,0��ʾ��ֵ��Ч */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enDrxUlReTransTimerFlg;
    VOS_UINT16                            usDrxUlReTransTimer;                    /* drx-ULRetransmissionTimer-r13,0~320 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16 enEdrxStartOffsetFlg;                  /* BostonĬ�ϲ�֧�� */
    LRRC_LPHY_EDRX_OFFSET_ENUM_UINT16     enEdrxOffsetType;                     /* eDRX-Config-CycleStartOffset-r13 */
    VOS_UINT16                            usEdrxStartOffset;
    VOS_UINT16                            usRsv;
#endif
}LRRC_LPHY_CONNECTED_DRX_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CONNECTED̬��DRX�����������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16     enConnDrxEnabled;                     /* ָʾCONNECTED̬��DRX�Ƿ���Ч */
    LRRC_LPHY_CONNECTED_DRX_INFO_STRU     stConnDrxInfo;
}LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : DRX�������ûظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
}LRRC_LPHY_DRX_CONFIG_IN_CONNECTED_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SI_CONFIG_ITEM_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : SI��Ϣ��������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                        usSiOrder;
    LRRC_LPHY_SI_PERIOD_ENUM_UINT16   enSiPeriod;
} LRRC_LPHY_SI_CONFIG_ITEM_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SI_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_LPHY_MSG_ID_ENUM_UINT32      enMsgId;
    VOS_UINT16                        usOpId;
    LRRC_LPHY_SI_WINDOW_ENUM_UINT16   enSiWindow;
    VOS_UINT16                        usSiNum;
    VOS_UINT8                         aucReserved[2];
    LRRC_LPHY_SI_CONFIG_ITEM_STRU     astSiConfigItem[LRRC_LPHY_MAX_SI_CONFIG_NUM];
} LRRC_LPHY_SI_CONFIG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SI_CONFIG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_LPHY_MSG_ID_ENUM_UINT32      enMsgId;
    VOS_UINT16                        usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16      enResult;
} LRRC_LPHY_SI_CONFIG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CONFIG_DRX_GATECLOCK_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CONFIG_DRX_GATECLOCK_IND_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32      enMsgId;                                  /*_H2ASN_Skip*/
    VOS_UINT16                        usOpId;
    VOS_UINT16                        usRsvd;

    LRRC_LPHY_DRX_INDICATOR_ENUM_UINT16                 enDrxIndicator;
    LRRC_LPHY_GATECLOCK_INDICATOR_ENUM_UINT16           enGateClockIndicator;
} LRRC_LPHY_CONFIG_DRX_GATECLOCK_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_TCXO_QUERY_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_TCXO_QUERY_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32      enMsgId;                                  /*_H2ASN_Skip*/
    VOS_UINT16                        usOpId;
    VOS_UINT16                        usRsvd;
}LRRC_LPHY_TCXO_QUERY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_TCXO_QUERY_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_TCXO_QUERY_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32    enMsgId;                                    /*_H2ASN_Skip*/
    VOS_UINT16                      usOpId;
    VOS_UINT16                      usFlg;                                      /* 0����Ч��������Ч����ЧʱusDynamicTcxoֵ������ */
    VOS_UINT16                      usDynamicTcxo;
    VOS_UINT16                      usRsvd;
}LRRC_LPHY_TCXO_QUERY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SET_WORK_MODE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SET_WORK_MODE_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32              enMsgId;                          /*_H2ASN_Skip*/
    VOS_UINT16                                usOpId;
    LRRC_LPHY_WORK_MODE_TYPE_ENUM_UINT16      enWorkModeType;                   /* ָʾLTE����ģʽ��0:���ڹ���̬��1:���ڲ���̬ */
    LRRC_LPHY_SET_WORK_MODE_REASON_ENUM_UINT16  enSetWorkModeReason;            /*��ģԭ��*/
    LRRC_LPHY_DSDS_RFSHARED_ENUM_UINT16       enDsdsRfShardFlg;
    LRRC_LPHY_EUTRAN_MODE_TYPE_ENUM_UINT16    enLteEutanModeType;               /*����ģʱ��LTE��ʽ:SVLTE,SRLTE,GUTL*/
    VOS_UINT16                                usRcv;           /*����λ*/
}LRRC_LPHY_SET_WORK_MODE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SET_WORK_MODE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SET_WORK_MODE_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32              enMsgId;                          /*_H2ASN_Skip*/
    VOS_UINT16                                usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16              enWorkModeCfgRslt;
}LRRC_LPHY_SET_WORK_MODE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BSIC_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BSIC_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                usArfcn;
    LRRC_LPHY_GERAN_BAND_IND_ENUM_UINT16      enBandInd;
}LRRC_LPHY_BSIC_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BSIC_VERIFY_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BSIC_VERIFY_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32              enMsgId;                          /*_H2ASN_Skip*/
    VOS_UINT16                                usOpId;
    VOS_UINT16                                usBsicNum;
    LRRC_LPHY_BSIC_INFO_STRU                  astBsicList[LRRC_LPHY_MAX_BSIC_NUM];
}LRRC_LPHY_BSIC_VERIFY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BSIC_VERIFY_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BSIC_VERIFY_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32              enMsgId;                          /*_H2ASN_Skip*/
    VOS_UINT16                                usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16              enBsicCfgRslt;
}LRRC_LPHY_BSIC_VERIFY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ERROR_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ERROR_IND_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32              enMsgId;                          /*_H2ASN_Skip*/
    LRRC_LPHY_ERR_TYPE_ENUM_UINT16            enErrType;
    VOS_UINT16                                usReserved;
}LRRC_LPHY_ERROR_IND_STRU;

/* LCS Begin */
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_INTER_FREQ_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_INTER_FREQ_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                usFreqInfo;                       /* Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16            enBandInd;                        /* Ƶ��ָʾ */
    VOS_UINT16                                usMeasPrsOffset;                  /* 0-39 */
    VOS_UINT8                                 aucReserved[2];
}LRRC_LPHY_OTDOA_INTER_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_LCS_GAP_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_LCS_GAP_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32              enMsgId;                          /*_H2ASN_Skip*/
    LRRC_LPHY_OTDOA_ENABLE_SIGNAL_ENUM_UINT16 enInterRSTDMeasInd;
    VOS_UINT16                                usRSTDFreqNum;
    LRRC_LPHY_OTDOA_INTER_FREQ_INFO_STRU      astRSTDInterFreqInfoList[LRRC_LPHY_OTDOA_MAX_RSTD_FREQ_NUM];
}LRRC_LPHY_LCS_GAP_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_PRS_MUTING_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_PRS_MUTING_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usValidBitNum;
    VOS_UINT16                                              usMutingBitInfo;
}LRRC_LPHY_OTDOA_PRS_MUTING_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_PRS_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_PRS_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_LTE_BAND_WIDTH_ENUM_UINT16                    enPRSBandwidth;
    VOS_UINT16                                              usPRSCfgIndex;
    LRRC_LPHY_OTDOA_DL_SUBFRAME_NUM_ENUM_UINT16             enDLSubframeNum;
    VOS_UINT8                                               aucReservered[2];
    LRRC_LPHY_OTDOA_PRS_MUTING_INFO_STRU                    stPRSMutingInfo;
}LRRC_LPHY_OTDOA_PRS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_PRS_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_PRS_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usPhysCellId;
    VOS_UINT16                                              usFreqInfoRef;      /* Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                          enBandInd;          /* Ƶ��ָʾ */
    LRRC_LPHY_OTDOA_ANT_PORT_CFG_ENUM_UINT16                enAntPortCfg;
    LRRC_LPHY_LTE_CP_TYPE_ENUM_UINT16                       enCpLength;
    LRRC_LPHY_OTDOA_PRS_CRS_TYPE_ENUM_UINT16                enPRSCRSIndication;

    LRRC_LPHY_OTDOA_PRS_INFO_STRU                           stPRSInfo;
}LRRC_LPHY_OTDOA_REF_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usPhysCellId;
    VOS_UINT16                                              usFreqInfoNeighbour;/* Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                          enBandInd;          /* Ƶ��ָʾ */
    LRRC_LPHY_OTDOA_ANT_PORT_CFG_ENUM_UINT16                enAntPortCfg;
    LRRC_LPHY_LTE_CP_TYPE_ENUM_UINT16                       enCpLength;
    LRRC_LPHY_OTDOA_PRS_CRS_TYPE_ENUM_UINT16                enPRSCRSIndication;
    LRRC_LPHY_OTDOA_PRS_INFO_STRU                           stPRSInfo;
    VOS_UINT8                                               ucSlotNumberOffsetFlg; /* ָʾusSlotNumberOffset�Ƿ���ڣ�0:�����ڣ�1:���� */
    VOS_UINT8                                               ucPRSSubframeOffsetFlg;/* ָʾusPRSSubframeOffset�Ƿ���ڣ�0:�����ڣ�1:���� */
    VOS_UINT8                                               aucReservered[2];
    VOS_UINT16                                              usSlotNumberOffset;
    VOS_UINT16                                              usPRSSubframeOffset;
    VOS_UINT16                                              usExpectedRSTD;
    VOS_UINT16                                              usExpectedRSTDUncertainty;
}LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usNeighbourCellNum;
    VOS_UINT8                                               aucReservered[2];
    LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_LIST_STRU           astNeighbourCellInfoList[LRRC_LPHY_OTDOA_MAX_NEIGHBOUR_CELL_NUM_PER_LAYER];
}LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usFreqLayersNum;
    VOS_UINT8                                               aucReservered[2];
    LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU                astNeighbourCellLayersInfoList[LRRC_LPHY_OTDOA_MAX_FREQ_LAYER_NUM - 1];
}LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_LAYERS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                               ucRefCellInfoFlg;
    VOS_UINT8                                               ucNeighbourCellLayersInfoFlg;
    VOS_UINT8                                               aucReserved[2];

    LRRC_LPHY_OTDOA_REF_CELL_INFO_STRU                      stRefCellInfo;
    LRRC_LPHY_OTDOA_NEIGHBOUR_CELL_LAYERS_INFO_STRU         stNeighbourCellLayersInfo;
}LRRC_LPHY_OTDOA_ASSISTANCE_DATA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_LCS_MBX_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_LCS_MBX_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usActiveFlag;
    VOS_UINT16                                              usProtectWord;
    LRRC_LPHY_OTDOA_ASSISTANCE_DATA_STRU                    stOtdoaAssistanceData;
}LRRC_LPHY_LCS_MBX_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                            enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    LRRC_LPHY_POSITION_OTDOA_MEAS_REQ_ENUM_UINT16           enRSTDMeasReqType;
    LRRC_LPHY_OTDOA_RPRT_INTERVAL_ENUM_UINT16               enOtdoaRprtInterval;/* ��enRSTDMeasReqTypeָʾΪOTDOA��������ʱ��Ч */
    VOS_UINT8                                               aucReserved[2];
}LRRC_LPHY_OTDOA_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : OTDOA�ظ����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16        enResult;
}LRRC_LPHY_OTDOA_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_MEAS_QUALITY_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_MEAS_QUALITY_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usErrorResolution;
    VOS_UINT16                                              usErrorValue;
    VOS_UINT16                                              usErrorNumSamples;
    VOS_UINT8                                               aucReservered[2];
}LRRC_LPHY_OTDOA_MEAS_QUALITY_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_LIST_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usPhyCellIdNeighbour;/* 0-503 */
    VOS_UINT16                                              usFreqInfoNeighbour;/* Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                          enBandInd;          /* Ƶ��ָʾ */
    VOS_UINT16                                              usRSTDResult;       /* 0-12711 */

    LRRC_LPHY_OTDOA_MEAS_QUALITY_STRU                       stRSTDQuality;
}LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_LIST_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usNeighbourCellNum;
    VOS_UINT8                                               aucReservered[2];
    LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_LIST_STRU                astNeighbourCellMeasList[LRRC_LPHY_OTDOA_MAX_NEIGHBOUR_CELL_NUM];
}LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_SIGNAL_MEAS_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_SIGNAL_MEAS_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                              usSFN;
    VOS_UINT16                                              usPhyCellIdRef;
    VOS_UINT16                                              usFreqInfoRef;
    LRRC_LPHY_BAND_IND_ENUM_UINT16                          enBandInd;          /* Ƶ��ָʾ */

    LRRC_LPHY_OTDOA_MEAS_QUALITY_STRU                       stRefQuality;
    LRRC_LPHY_OTDOA_NEIGHBOUR_MEAS_STRU                     stNeighbourCellMeasurement;
}LRRC_LPHY_OTDOA_SIGNAL_MEAS_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_PROVIDE_LOCATION_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_PROVIDE_LOCATION_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_OTDOA_TARGET_DEVICE_ERROR_CAUSES_ENUM_UINT16  enError;
    VOS_UINT8                                               aucReservered[2];
    LRRC_LPHY_OTDOA_SIGNAL_MEAS_INFO_STRU                   stSignalMeasInfo;
}LRRC_LPHY_OTDOA_PROVIDE_LOCATION_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_OTDOA_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_OTDOA_IND_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                            enMsgId;            /*_H2ASN_Skip*/
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReservered[2];
    LRRC_LPHY_OTDOA_PROVIDE_LOCATION_INFO_STRU              stOtdoaMeasInfo;
}LRRC_LPHY_OTDOA_IND_STRU;


/* LCS End */
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MSG_DATA
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MSG_DATA���ݽṹ,����ΪRRCר�ã�DSP��ʹ��
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgID;        /*_H2ASN_MsgChoice_Export LRRC_LPHY_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                             aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          LRRC_LPHY_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}LRRC_LPHY_MSG_DATA;

/*_H2ASN_Length UINT32*/

/*****************************************************************************
 �ṹ��    : LrrcLphyInterface_MSG
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LrrcLphyInterface_MSG���ݽṹ,����ΪRRCר�ã�DSP��ʹ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_LPHY_MSG_DATA                    stMsgData;
}LrrcLphyInterface_MSG;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_ELEMENT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_ELEMENT_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32              *pulMsgAddr;                                        /*��Ϣ��ʼ��ַ*/
    VOS_UINT32              ulMsgLen;                                           /*��Ϣ���ȣ���λ˫��*/
}LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_ELEMENT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                  usProtectWord;                  /* ���䱣���� */
    VOS_UINT16                                  usFatalErrorInd;                /* 0:��ʾ���ֶ���Ч, 1:�ؼ���Ϣ��ʧ, 2:�ǹؼ���Ϣ��ʧ */
    LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_ELEMENT_STRU stMsgAddrQue[LRRC_LPHY_MBX_SLAVE_ADDR_QUEUE_BUF_MAX];
} LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SLAVE_DOWN_MAILBOX_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SLAVE_DOWN_MAILBOX_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU       stMailBoxHead;                      /* ����ͷ*/
    VOS_UINT32                              aulMessage[LRRC_LPHY_SLAVE_DOWN_MAILBOX_MSG_LEN];/* ��Ϣ֡,���ڴ洢ԭ��*/
} LRRC_LPHY_SLAVE_DOWN_MAILBOX_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SLAVE_UP_MAILBOX_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SLAVE_UP_MAILBOX_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_SLAVE_MAILBOX_HEAD_STRU       stMailBoxHead;                      /* ����ͷ*/
    VOS_UINT32                              aulMessage[LRRC_LPHY_SLAVE_UP_MAILBOX_MSG_LEN];/* ��Ϣ֡,���ڴ洢ԭ��*/
} LRRC_LPHY_SLAVE_UP_MAILBOX_STRU;

/* MBMS Begin */
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MCCH_CONFIG_R9_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MCCH_CONFIG_R9_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_MCCH_REPET_PERIOD_R9_ENUM_UINT8           enMcchRptPeriod;            /*rf32,rf64,rf128,rf256*/
    LRRC_LPHY_LRRC_LPHY_MCCH_OFFSET_ENUM_UINT8          enMcchOffset;               /*0..10*/
    LRRC_LPHY_MCCH_MODIFY_PERIOD_ENUM_UINT8             enMcchModPeriod;            /*rf512,rf1024*/
    VOS_UINT8                                           ucSfAlloc;                  /* rrc���տտڵĸ�ʽ�������� */
    LRRC_LPHY_SIG_MCS_R9_ENUM_UINT8                     enSignalMcs;                /*n2,n7,n13,n19*/
    VOS_UINT8                                           aucReservered[3];
}LRRC_LPHY_MCCH_CONFIG_R9_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_AREA_INFO_R9_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_AREA_INFO_R9_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                           ucAreaId;
    LRRC_LPHY_NON_MBSF_NREGION_LEN_ENUM_UINT8           enNonMbsfnRegionLen;
    VOS_UINT8                                           ucNotiIndicator;
    VOS_UINT8                                           ucReservered;
    LRRC_LPHY_MCCH_CONFIG_R9_STRU                       stMcchCfgPara;
}LRRC_LPHY_MBSFN_AREA_INFO_R9_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_AREA_INFO_LIST_R9_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_AREA_INFO_LIST_R9_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                          usValidAreaNum;
    VOS_UINT8                                           aucReservered[2];
    LRRC_LPHY_MBSFN_AREA_INFO_R9_STRU                   astMcchAreaInfo[LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA];
}LRRC_LPHY_MBSFN_AREA_INFO_LIST_R9_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_MCCH_CFG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_MCCH_CFG_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
    LRRC_LPHY_MBSFN_AREA_INFO_LIST_R9_STRU              stMbsfnAreaInfoList;
}LRRC_LPHY_MBSFN_MCCH_CFG_REQ_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_MCCH_CFG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_MCCH_CFG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBSFN_MCCH_CFG_CNF_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MCCH_NOTIFICATION_CFG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MCCH_NOTIFICATION_CFG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_NOTIFICATION_REPET_COEFF_R9_ENUM_UINT8     enNotificationRptCoeff;
    LRRC_LPHY_NOTIFICATION_OFFSET_ENUM_UINT8             enNotificationOffset;
    LRRC_LPHY_NOTIFICATION_SF_INDEX_ENUM_UINT8           enNotificationSfINdex;
    VOS_UINT8                                            ucReservered;
}LRRC_LPHY_MCCH_NOTIFICATION_CFG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_NOTIFY_CFG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_NOTIFY_CFG_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_CONIG_VALID_FLG_ENUM_UINT8                enMRNTIValidFlg;        /* ָʾnotify�Ƿ���Ҫ�����ı�־ */
    LRRC_LPHY_MCCH_MODIFY_PERIOD_ENUM_UINT8             enMinNotificationRptPeriod; /* ��rrc����С��mcchmodify���� */
    LRRC_LPHY_MCCH_NOTIFICATION_CFG_STRU                stMcchNotificationCfg;  /* R13����:��MIB�� dl-Bandwidth Ϊn6��LPHYҪ���Ե�NotificationCfg���� */
}LRRC_LPHY_MBSFN_NOTIFY_CFG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_NOTIFY_CFG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_NOTIFY_CFG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBSFN_NOTIFY_CFG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PMCH_CONFIG_R9_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_PMCH_CONFIG_R9_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CONIG_VALID_FLG_ENUM_UINT8                enPmchValidFlg;
    LRRC_LPHY_MCH_SCHDL_PERIOD_R9_ENUM_UINT8            enMchSchedPeriod;
    VOS_UINT16                                          usSfAllocEnd;           /*0..1535*/
    VOS_UINT16                                          usDataMcs;              /* 0..28 (R12:Normal:0..28 or higerOrder 0..27) */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT8                                           ucPmchIndex;            /*0-LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN-1*/
    VOS_UINT8                                           aucReservered[1];
#else
    VOS_UINT8                                           aucReservered[2];
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_MCH_DATA_MCS_TYPE_ENUM_UINT8              enMchDataMcsType;
    VOS_UINT8                                           aucReservered1[3];
#endif

}LRRC_LPHY_PMCH_CONFIG_R9_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PMCH_INFO_LIST_R9_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_PMCH_INFO_LIST_R9_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                          usPmchNum;
    VOS_UINT8                                           aucReservered[2];
    LRRC_LPHY_PMCH_CONFIG_R9_STRU                       astPmchInfo[LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN];
}LRRC_LPHY_PMCH_INFO_LIST_R9_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_AREA_CFG_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_AREA_CFG_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                           ucAreaId;
    LRRC_LPHY_COMM_SF_ALLOC_PERIOD_R9_ENUM_UINT8        enComSfAllocPeriod;
    LRRC_LPHY_NON_MBSF_NREGION_LEN_ENUM_UINT8           enNonMbsfnRegionLen;
    LRRC_LPHY_SIG_MCS_R9_ENUM_UINT8                     enSignalMcs;
    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU              stMbsfnCfgInfo;
    LRRC_LPHY_PMCH_INFO_LIST_R9_STRU                    stPmchInfoList;
}LRRC_LPHY_MBSFN_AREA_CFG_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_PMCH_CFG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_PMCH_CFG_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT16                                          usAreaNum;              /* �������Ϊ0��Ϊ�ͷ����� */
    LRRC_LPHY_MBSFN_AREA_CFG_INFO_STRU                  astMbsfnAreaInfo[LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA];
}LRRC_LPHY_MBSFN_PMCH_CFG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_PMCH_CFG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_PMCH_CFG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBSFN_PMCH_CFG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_PMCH_CFG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_PMCH_CFG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT16                                          usCurrentSfn;
    VOS_UINT8                                           ucMcchChgInd;
    VOS_UINT8                                           ucReservered[3];
}LRRC_LPHY_MBSFN_NOTIFY_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_SUBFRAME_CFG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_SUBFRAME_CFG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usSCellIdx;                   /* 0��ʾPCELL */
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_MBSFN_SUBFRAME_CFG_LIST_STRU        stMbsfnSFCfgList;             /* MBSFN��֡������Ϣ */
}LRRC_LPHY_MBSFN_SUBFRAME_CFG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_SUBFRAME_CFG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵����LRRC_LPHY_MBSFN_SUBFRAME_CFG_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];

    VOS_UINT16                                          usMbsfnSfCfgNum;        /* ָʾ����MBSFN��֡�������� */
    VOS_UINT16                                          usParaSize;             /* ָʾ����MBSFN��֡���ò������ܳ��� */
    VOS_UINT8                                           aucMbsfnSfCfgPara[4];   /* MBSFN��֡���ò��� */

}LRRC_LPHY_MBSFN_SUBFRAME_CFG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBSFN_SUBFRAME_CFG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBSFN_SUBFRAME_CFG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                              /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBSFN_SUBFRAME_CFG_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SWITCH_IND_STRU
 Э����  : rrc��Phy֮��Ľӿ� ,����״̬.ucSARSwitch: 0��ʾ���ߣ�1��ʾ����
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_SWITCH_IND_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    LRRC_LPHY_SWITCH_IND_TYPE_ENUM_UNIT16               ulMsgType;
    VOS_UINT16                                          usSarReductionPri;      /*���ʻ��˵ȼ�*/
    VOS_UINT8                                           ucAntenSwitch;          /*����״̬*/
    VOS_UINT8                                           ucRev[3];
}LRRC_LPHY_SWITCH_IND_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_START_REQ_STRU
 Э����  :
 ASN.1���� : �ڱ���������ʼʱ�·���ԭ�dsp��rrc�ظ�cnf��rrc�ٽ���bg����
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_START_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RAT_TYPE_ENUM_UINT16                      enStartBGSearchRat;     /* L��ģʱ���˴���дBG���ĸ�ģʽ��L��ģʱ���˴��̶���дΪLģ */
    LRRC_LPHY_BGSCFG_TYPE_ENUM_UINT16                   enBsgCfgType;            /*DSDS����*/
    /* begin,���������Ż�, l00277963 */
    LRRC_LPHY_BG_SEARCH_PRIORITY_ENUM_UNIT16            enBgSearchPriority;
    /* end,���������Ż�, l00277963 */
}LRRC_LPHY_BG_SEARCH_START_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_START_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_START_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_BG_SEARCH_START_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_STOP_REQ_STRU
 Э����  : �ڱ������������Ǳ�����������ʱ��dsp�յ����������Ҫֹͣ��������
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_STOP_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_BG_SEARCH_STOP_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_STOP_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_STOP_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_BG_SEARCH_STOP_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_SUSPEND_REQ_STRU
 Э����  : �ڱ�������ʱ��rrcʹ�ø�ԭ�����dsp bg��������
             rrc������BGƵ��������Ƶ��������ɨƵ�ڼ��·���ԭ��·��������DSP��Ҫ����
             Ƶ��������ɨƵ����������Ϣ������dsp�ָ�����������Ϣ
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_SUSPEND_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_BG_SEARCH_SUSPEND_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_SUSPEND_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_SUSPEND_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_BG_SEARCH_SUSPEND_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_RESUME_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_RESUME_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_BG_SEARCH_RESUME_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_BG_SEARCH_RESUME_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_BG_SEARCH_RESUME_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_BG_SEARCH_RESUME_CNF_STRU;





/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANR_START_REQ_STRU
 Э����  :
 ASN.1���� : DSP����anr����
 �ṹ˵��  : LRRC_LPHY_ANR_START_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RAT_TYPE_ENUM_UINT16                      enStartAnrRat;
    LRRC_LPHY_CGI_ACQUISITION_METHOD_ENUM_UINT16        enAcqMethod;            /* ָʾCGI��ȡ��ʽ,0��ʾ������CGI��ȡ,1��ʾ����AUTONOMOUS GAP,2��ʾ����IDLE PERIODS */
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_ANR_START_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANR_START_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ANR_START_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_ANR_START_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANR_STOP_REQ_STRU
 Э����  : ��anrʱ��dsp�յ����������Ҫֹͣanr����
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ANR_STOP_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_ANR_STOP_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ANR_STOP_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ANR_STOP_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_ANR_STOP_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RF_IIP2_DATA_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_RF_IIP2_DATA_PARA_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                          usIIP2IQWord;/*IQУ׼����*/
    VOS_INT16                                           sCorIMD2;/*IQУ׼���ֶ�Ӧ��IMD2У׼���*/
}LRRC_LPHY_RF_IIP2_DATA_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RF_IIP2_CAL_BAND_SPEC_VAL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_RF_IIP2_CAL_BAND_SPEC_VAL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_RF_IIP2_DATA_PARA_STRU                    stRfIIP2CalVar;
    VOS_UINT32                                          ulSuccFlag;
}LRRC_LPHY_RF_IIP2_CAL_BAND_SPEC_VAL_STRU;
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RF_IIP2_CAL_BAND_SPEC_VAL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_RF_IIP2_CAL_BAND_SPEC_VAL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                          usBand;
    VOS_UINT8                                           aucReserve[2];
    VOS_UINT32                                          aulDcocCal[LRRC_LPHY_RF_DCOC_RPT_DATA_SIZE];/*��̬DCOCУ׼ֵ���ֱ��Ӧ12����λ��ÿ�����ݷֱ��������ͨ����I��Q*/
    VOS_UINT32                                          aulTXIQCal[LRRC_LPHY_RF_TXIQ_RPT_DATA_SIZE];/*TXIQУ׼������A��P��I��Q*/
    LRRC_LPHY_RF_IIP2_CAL_BAND_SPEC_VAL_STRU            stRfIIP2CalVar;
}LRRC_LPHY_RF_HI6360_INIT_CALDATA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ADJUST_PARA_QUERY_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ADJUST_PARA_QUERY_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_QUERY_SELF_ADJUST_PARA_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_ADJUST_PARA_QUERY_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_ADJUST_PARA_QUERY_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT16                                          usBandNum;
    LRRC_LPHY_RF_HI6360_INIT_CALDATA_STRU               stRfCalData[LRRC_LPHY_QUERY_SELF_ADJUST_PARA_MAX_BAND_NUM];
}LRRC_LPHY_QUERY_SELF_ADJUST_PARA_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CROSS_CARR_SCHEDUL_CFG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CROSS_CARR_SCHEDUL_CFG_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    /* ����С�����͡�������Ϊownʱ��enCifPresenceFlg��Ч��
       ������Ϊotherʱ��usSchedulCellIdx��usPdschStart��Ч */
    LRRC_LPHY_SCHEDUL_CELL_TYPE_ENUM_UINT16       enSchedulCellType;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enCifPresence;                /* cif-Presence-r10 */
    VOS_UINT16                                    usSchedulCellIdx;             /* schedulingCellId-r10  */
    VOS_UINT16                                    usPdschStart;                 /* pdsch-Start-r10 */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enCifInSchdlCellFlg;
    VOS_UINT16                                    usCifInSchdlCell;             /* cif-InSchedulingCell-r13 */
#endif
}LRRC_LPHY_CROSS_CARR_SCHEDUL_CFG_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_DEDICATED_SCELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_PUSCH_DEDICATED_SCELL_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enGroupHopDisabled;           /* groupHoppingDisabled-r10�Ƿ���Ч */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enDmrsWithOCCActivated;       /* dmrs-WithOCC-Activated-r10�Ƿ���Ч */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                                    usReserved;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enPuschDMRSEnabled;           /* stPuschDMRS�Ƿ���Ч */
    LRRC_LPHY_PUSCH_DMRS_STRU                     stPuschDMRS;                  /* pusch-DMRS-r11 */
#endif
}LRRC_LPHY_PUSCH_DEDICATED_SCELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_SCELL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_INT16                                     sPuschP0Ue;                   /* p0-UE-PUSCH-r10	 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enDeltaMcsEnabled;            /* deltaMCS-Enabled-r10 */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16             enAccumlatEnabled;            /* accumulationEnabled-r10 */
    VOS_UINT16                                    usPsrsOffset;                 /* pSRS-Offset-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPsrsOffsetApValidFlg;       /* usPsrsOffsetAp�Ƿ���Ч */
    VOS_UINT16                                    usPsrsOffsetAp;               /* pSRS-OffsetAp-r10 */
    LRRC_LPHY_FILTER_COEFF_ENUM_UINT16            enFilterCoeff;                /* FilterCoefficient-r10 */
    LRRC_LPHY_PATHLOSS_REF_LINK_ENUM_UINT16       enPathLossRefLink;            /* athlossReferenceLinking-r10 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    VOS_UINT16                                    usResverd;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enDeltaTxDOffsetListPucchR11ValidFlg; /* DeltaTxD-OffsetListPUCCH-r11 �Ƿ���Ч��ʶ  */
    LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_R11_STRU  stDeltaTxDOffsetListPucchR11;        /* DeltaTxD-OffsetListPUCCH-v1130 */
#endif

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPsrsOffsetR11;              /* ָʾʹ��pSRS-Offset-v1130 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPsrsOffsetApR11;            /* ָʾʹ�� pSRS-OffsetAp-v1130 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enP0UePucchValidFlg;          /* UplinkPowerControlDedicatedSCell-v1310->p0-UE-PUCCH  BostonĬ�ϲ�֧�� */
    VOS_INT16                                     sPucchP0Ue;
    VOS_UINT16                                    usResverd1;

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enDeltaTxDOffsetListPucchValidFlg; /* UplinkPowerControlDedicatedSCell-v1310->deltaTxD-OffsetListPUCCH-r10  BostonĬ�ϲ�֧�� */
    LRRC_LPHY_DELTATXD_OFFSETLIST_PUCCH_STRU      stDeltaTxDOffsetListPucch;
#endif
}LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_SCELL_STRU;
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_TPC_PDCCH_CONFIG_SCELL_STRU
 Э����  : PhysicalConfigDedicated->TPC-PDCCH-Configuration
 ASN.1���� : TPC-PDCCH-ConfigSCell-r13
 �ṹ˵��  : TPC-PDCCH-Configuration
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_INDEX_FORMAT_TYPE_ENUM_UINT16       enTpcFormatType;              /* tpc-Index->choice */
    VOS_UINT16                                    usTpcIdx;                     /* tpc-Index->indexOfFormat3/indexOfFormat3A */
}LRRC_LPHY_TPC_PDCCH_CONFIG_SCELL_STRU;
#endif
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PUSCH_SCELL_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : PUSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;
    VOS_UINT16                                      usScellIdx;
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CG_ENUM_UINT8                         enCgType;
    VOS_UINT8                                       aucRsv[3];
#endif
    VOS_UINT16                                      usUlFreqInfo;               /* ����Ƶ��, ��Ӧ�տ�ul-FreqInfo-r10->ul-CarrierFreq-r10, ȱʡʱ����36.101���м��� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                  enBandInd;                  /* Ƶ��ָʾ */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16             enLteModeType;              /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                                      usPhyCellId;
    VOS_UINT16                                      usStagId;                   /* stag-Id-r11 */
#else
    VOS_UINT16                                      usReserved;
#endif
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16                enUlBandWidth;              /* ���д���,��Ӧ�տ�ul-FreqInfo-r10->ul-Bandwidth-r10��ȱʡʱ��д���д��� */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16      enUlCPLen;                  /* ����CP���� */
    VOS_INT16                                       sMaxTxPwr;                  /* ����书�� p-Max-r10 */
    LRRC_LPHY_PUSCH_COMM_INFO_STRU                  stPuschCommInfo;            /* ����PUSCH���ò��� */
    LRRC_LPHY_POWER_CTRL_COMM_INFO_SCELL_STRU       stPwrCtrlCommInfo;          /* �������ʿ�����Ϣ */
    LRRC_LPHY_ANTENNA_INFO_UL_STRU                  stAntennaInfoUL;            /* antennaInfoUL-r10 */
    LRRC_LPHY_PUSCH_DEDICATED_SCELL_INFO_STRU       stPuschCfgDedicateSCell;    /* pusch-ConfigDedicatedSCell-r10 */
    VOS_UINT16                                      usReserved1;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enUlPowerCtlDedicSCellValidFlg;  /* stUlPowerCtlDedicSCell�Ƿ���Ч */
    LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_SCELL_STRU  stUlPowerCtlDedicSCell;          /* uplinkPowerControlDedicatedSCell-r10 */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enAdditSpecEmissionSCellValidFlg;
    VOS_UINT16                                      usAdditSpecEmissionSCell;   /* additionalSpectrumEmissionSCell-r10 */
#if (FEATURE_ON == FEATURE_LTE_R13)
    VOS_UINT16                                      usReserved2;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPucchTpcConfigEnabled;    /* TPC PUCCH������Ч��ʶ  BostonĬ�ϲ�֧�� */
    LRRC_LPHY_TPC_PDCCH_CONFIG_SCELL_STRU           stPucchTpcConfig;           /* tpc-PDCCH-ConfigPUCCH-SCell-r13 */
#endif
}LRRC_LPHY_PUSCH_SCELL_PARA_STRU;

#if (FEATURE_ON == FEATURE_LTE_R11)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_CONFIG_SCELL_INFO_R11_STRU
 Э����  : RadioResourceConfigCommonSCell-r10->prach-ConfigSCell-r11
 ASN.1���� :
 �ṹ˵��  : PRACH�����ŵ����ò������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usReserved;
    VOS_UINT16                                    usHighSpeedFlg;               /* PRACH-Configuration->highSpeedFlag */
    VOS_UINT16                                    usZeroCorrelationZoneConfig;  /* zeroCorrelationZoneConfig */
    VOS_UINT16                                    usFrequencyOffset;            /* prach-FrequencyOffset */
}LRRC_LPHY_PRACH_CONFIG_SCELL_INFO_R11_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_CONFIG_STRU
 Э����  :  RadioResourceConfigCommonSCell-r10->prach-ConfigSCell-r11
 ASN.1���� :
 �ṹ˵��  : PRACH�����ŵ����ò������ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                    usRootSequenceIndex;          /* PRACH-Configuration->rootSequenceIndex */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPrachCfgSCellInfoR11ValidFlg;
    LRRC_LPHY_PRACH_CONFIG_SCELL_INFO_R11_STRU    stPrachCfgSCellInfoR11;
}LRRC_LPHY_PRACH_CONFIG_SCELL_R11_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_CONFIG_STRU
 Э����  : PRACH-ConfigSCell-r10
             prach-ConfigSCell-r11
 ASN.1���� :
 �ṹ˵��  : PRACH�����ŵ����ò������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enPrachSCellCfgR11ValidFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16         enConfigIndexValidFlg;
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16    enUlCPLen;                    /* ����CP���� */
    VOS_UINT16                                    usConfigIndex;                /* PRACH-Config->prach-ConfigInfo->prach-ConfigIndex or prach-ConfigIndex-r10 */
    LRRC_LPHY_PRACH_CONFIG_SCELL_R11_STRU         stPrachSCellCfgR11;           /* PRACH-Config�г���prach-ConfigIndex֮�����*/
}LRRC_LPHY_PRACH_CONFIG_SCELL_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PRACH_SCELL_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : PRACH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;
    VOS_UINT16                                      usScellIdx;

#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CG_ENUM_UINT8                         enCgType;
    VOS_UINT8                                       aucRsv[3];
#endif

    VOS_UINT16                                      usUlFreqInfo;               /* ����Ƶ��, ��Ӧ�տ�ul-FreqInfo-r10->ul-CarrierFreq-r10, ȱʡʱ����36.101���м��� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                  enBandInd;                  /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16             enLteModeType;              /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                                      usPhyCellId;
    LRRC_LPHY_PRACH_CONFIG_SCELL_STRU               stPrachInfo;
}LRRC_LPHY_PRACH_SCELL_PARA_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : pucch-SCell
 �ṹ˵��  : boston��ʵ��
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;             /* �����ŵ����� */
    VOS_UINT16                                      usScellIdx;                   /* PSCellIndex */
    VOS_UINT16                                      usRsv;

    LRRC_LPHY_PUCCH_COMM_INFO_STRU                  stPucchCommInfo;

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDedicatedInfoValidFlag;     /* ר��PUCCH�ŵ�������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enSrConfigInfoValidFlag;      /* SR�������ò�����Ч��ʶ */

    LRRC_LPHY_PUCCH_DEDICATED_INFO_STRU             stDedicatedInfo;              /* ר��PUCCH�ŵ����� */
    LRRC_LPHY_SR_CONFIG_INFO_STRU                   stSrConfigInfo;               /* SchedulingRequestConfigSCell-r13 */

}LRRC_LPHY_PUCCH_SCELL_PARA_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� : PDCCH-ConfigSCell-r13
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enSkipMntrngDciFrmt01A;     /* skipMonitoringDCI-format0-1A-r13 */
    VOS_UINT16                                      usRsv;
}LRRC_LPHY_PDCCH_SCELL_PARA_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_STAG_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_STAG_CONFIG_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                                          usStagIdNum;            /*����ausStagId����Ч����������ǰʵ�ʴ��ڵ�stag id��Ŀ.0:����ǰʵ�ʴ��ڵ�stag id��ĿΪ0�����ͷ����д��ڵ�stag id*/
    VOS_UINT16                                          ausStagId[LRRC_LPHY_MAX_STAG_NUM];
}LRRC_LPHY_STAG_INFO_STRU;
#endif
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_STAG_CONFIG_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_STAG_CONFIG_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
#if (FEATURE_ON == FEATURE_LTE_R13)
    VOS_UINT16                                          usReserved;
    LRRC_LPHY_STAG_INFO_STRU                            stMcgStagInfo;
    LRRC_LPHY_STAG_INFO_STRU                            stScgStagInfo;
#else
    VOS_UINT16                                          usStagIdNum;            /*����ausStagId����Ч����������ǰʵ�ʴ��ڵ�stag id��Ŀ.0:����ǰʵ�ʴ��ڵ�stag id��ĿΪ0�����ͷ����д��ڵ�stag id*/
    VOS_UINT16                                          ausStagId[LRRC_LPHY_MAX_STAG_NUM];
    VOS_UINT16                                          usReserved;
#endif

}LRRC_LPHY_STAG_CONFIG_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_STAG_CONFIG_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_STAG_CONFIG_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_STAG_CONFIG_CNF_STRU;
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_LAA_SCELL_STRU
 Э����  :
 ASN.1���� :

 LAA-SCellConfiguration-r13 ::=          SEQUENCE {
     subframeStartPosition               ENUMERATED {s0, s07},
     laa-SCellSubframeConfig             BIT STRING (SIZE(8))
 }
 �ṹ˵��  : LRRC_LPHY_LAA_SCELL_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               enSubFrameStartPos;
    VOS_UINT8                               usLaaSCellSubframeConfig;
    VOS_UINT8                               aucRsv[2];
}LRRC_LPHY_LAA_SCELL_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_PDSCH_SCELL_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : �����ݵ�PDSCH�����ŵ��������ݽṹ
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16      enPhyChannelType;
    VOS_UINT16                              usSCellIdx;                         /* SCELL���� */
#if (FEATURE_ON == FEATURE_LTE_R13)
    LRRC_LPHY_CG_ENUM_UINT8                 enCgType;
    VOS_UINT8                               aucRsv[3];
#endif
    VOS_UINT16                              usDlFreqInfo;                       /* SCELL����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;                          /* Ƶ��ָʾ */
    VOS_UINT16                              usPhyCellId;
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16     enLteModeType;                      /* ָʾƵ����������ʽ����, FDD��TDD */
#else
    VOS_UINT16                              usReserved1;
#endif
    LRRC_LPHY_PDSCH_COMM_INFO_STRU          stPdschCommInfoSCell;               /* SCELL��PDSCH������Ϣ */
    LRRC_LPHY_ANTENNA_DEDICATED_INFO_STRU   stAntennaDedicatedInfo;             /* ר��������Ϣ */
    VOS_UINT16                              usReserved2;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enCrossCarrSchedulCfgValidFlg;      /* stCrossCarrSchedulCfg�Ƿ���Ч */
    LRRC_LPHY_CROSS_CARR_SCHEDUL_CFG_STRU   stCrossCarrSchedulCfg;              /* crossCarrierSchedulingConfig-r10 */
    LRRC_LPHY_CSI_RS_CONFIG_STRU            stCsiRSConfig;                      /* csi-RS-Config-r10 */
#if (FEATURE_ON == FEATURE_LTE_R11)
    LRRC_LPHY_EPDCCH_CONFIG_STRU            stEPdcchConfig;                     /* EPDCCH-Config-r11 */
    LRRC_LPHY_PDSCH_DEDICATED_INFO_STRU     stPdschDedicatedSCell;              /* pdsch-ConfigDedicated-v1130 */
#endif
#if (FEATURE_ON == FEATURE_LTE_R13)

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enEimtaMainCfgSrvCellValidFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enLaaScellFlg;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enCRSAssistInfoListEnabled;         /* stCRSAssistInfoList������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enPdcchScellValidFlg;               /* BostonĬ�ϲ�֧�� */

    LRRC_LPHY_EIMTA_MAIN_CONFIG_SERV_CELL_STRU  stEimtaMainCfgSrvCell;          /* EIMTA����С�������� */
    LRRC_LPHY_LAA_SCELL_STRU                stLaaScell;                         /* MeasRSSI-Config-r13  */
    LRRC_LPHY_CRS_ASSIST_INFO_LIST_STRU     stCRSAssistInfoList;                /* CRS-AssistanceInfoList-r13 */

    LRRC_LPHY_NAICS_ASSIST_INFO_STRU        sNaicsAssistInfo;                   /* NAICS-AssistanceInfo-r12 */

    LRRC_LPHY_PDCCH_SCELL_PARA_STRU         stPdcchScell;                       /* pdcch-ConfigSCell-r13 */
#endif
}LRRC_LPHY_PDSCH_SCELL_PARA_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    /*----------------------------------------common �� scell��*/
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16      enPhyChannelType;
    VOS_UINT16                              usSCellIdx;                         /* SCELL IDNEX */
    VOS_UINT16                              usDlFreqInfo;                       /* SCELL FREQ */
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;
    VOS_UINT16                              usPhyCellId;

    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16     enLteModeType;                      /* ָʾƵ����������ʽ����, FDD��TDD */
    LRRC_LPHY_PDSCH_COMM_INFO_STRU          stPdschCommInfoSCell;               /* SCELL PDSCH */

    /*------------------------------------dedicated �� pscell��*/
    VOS_UINT16                              usReserved2;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enCrossCarrSchedulCfgValidFlg;      /* stCrossCarrSchedulCfg */
    LRRC_LPHY_CROSS_CARR_SCHEDUL_CFG_STRU   stCrossCarrSchedulCfg;              /* crossCarrierSchedulingConfig-r10 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enSemiPersistSchedCRntiValidFlg;      /* semiPersistSchedC-RNTI */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enSpsConfigDlEnabled;                 /* stSpsConfigDl???? */
    VOS_UINT16                              usSemiPersistSchedCRnti;              /* semiPersistSchedC-RNTI */

    LRRC_LPHY_ANTENNA_DEDICATED_INFO_STRU   stAntennaDedicatedInfo;               /* antennal dedicated */
    LRRC_LPHY_SPS_CONFIG_DL_STRU            stSpsConfigDl;                        /* SPS-ConfigurationDL */
    LRRC_LPHY_CSI_RS_CONFIG_STRU            stCsiRSConfig;                        /* csi-RS-Config-r10 */

    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enCifPresence;                        /* cif-Presence-r10 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enEPdcchConfigVldFlg;

    LRRC_LPHY_EPDCCH_CONFIG_STRU            stEPdcchConfig;                       /* EPDCCH-Config-r11 */
    LRRC_LPHY_PDSCH_DEDICATED_INFO_STRU     stPdschDedicatedInfo;                 /* pdsch-ConfigDedicated-v1130 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enEimtaMainCfgValidFlg;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enEimtaMainCfgSrvCellValidFlg;
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16       enCRSAssistInfoListEnabled;         /* stCRSAssistInfoList������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enPdcchCandReductValidFlg;          /* BostonĬ�ϲ�֧�� */

    LRRC_LPHY_EIMTA_MAIN_CONFIG_STRU        stEimtaMainCfg;                     /* EIMTA��С�������� */
    LRRC_LPHY_EIMTA_MAIN_CONFIG_SERV_CELL_STRU  stEimtaMainCfgSrvCell;          /* EIMTA����С�������� */
    LRRC_LPHY_CRS_ASSIST_INFO_LIST_STRU     stCRSAssistInfoList;                /* CRS-AssistanceInfoList-r13 */

    LRRC_LPHY_NAICS_ASSIST_INFO_STRU        stNaicsAssistInfo;                   /* NAICS-AssistanceInfo-r12 */
    LRRC_LPHY_PDCCH_CAND_REDUCT_STRU        stPdcchCandReduct;                  /* PDCCH-CandidateReductions-r13 */
}LRRC_LPHY_PDSCH_PSCELL_STRU;
#endif
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DPDT_CMD_REQ_STRUs
 Э����  :
 ASN.1���� :
 �ṹ˵����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_DPDT_CMD_ENUM_UINT16                      enCmdIndex;           /*�ж�ָ��*/
    VOS_UINT8                                           ucSwitchFlag;      /*0�� 1��*/
    VOS_UINT8                                           ucRev[3];
    VOS_UINT32                                          ulDpdtValue;
}LRRC_LPHY_DPDT_CMD_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_DPDT_CMD_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           ucRev[2];
    VOS_UINT32                                          ulDpdtValue;
}LRRC_LPHY_DPDT_CMD_IND_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NV_ITEM_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��Ҫ�洢��NV�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT16          usNvId;
    VOS_UINT16        usNvItemLength;    /* ����д��NV���ݳ���*/
    VOS_UINT32        ulNvItemAddress;        /* ��д��NV TCM��ַ*/
} LRRC_LPHY_NV_ITEM_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NV_WRITE_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : DSP����RRC�洢NV��Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_LPHY_MSG_ID_ENUM_UINT32       enMsgId;
    VOS_UINT16                         usOpId;
    VOS_UINT16                         usNvItemNum;
    LRRC_LPHY_NV_ITEM_STRU             astNvItems[LRRC_LPHY_MAX_NV_WRITE_NUM];
} LRRC_LPHY_NV_WRITE_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NV_WRITE_RSP_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RRC���NV�洢��ظ�DSP��Ϣ�ṹ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    LRRC_LPHY_MSG_ID_ENUM_UINT32          enMsgId;
    VOS_UINT16                            usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16          enResult;
} LRRC_LPHY_NV_WRITE_RSP_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_NORF_INFO_IND
 Э����  :
 ASN.1���� :
 �ṹ˵��  : DSDS���Դ�����£�RTT��RRC�ϱ�NORFָʾ����ָʾ�ϱ�NORFʱ�ĳ���
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                               /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_DSDS_NORF_TYPE_ENUM_UINT16                enNorfScene;
    VOS_UINT32                                          ulRsv;
}LRRC_LPHY_NORF_INFO_IND;

#if (FEATURE_ON == FEATURE_LTE_R11)
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_ENABLE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_ENABLE_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_MBMS_ENABLE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_ENABLE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_ENABLE_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBMS_ENABLE_CNF_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_DISABLE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_DISABLE_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_MBMS_DISABLE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_DISABLE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_DISABLE_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBMS_DISABLE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_PMCH_ACTIVE_CFG_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_PMCH_ACTIVE_CFG_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                           ucAreaId;
    VOS_UINT8                                           ucPmchNum;              /*1-LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN*/
    VOS_UINT8                                           aucPmchIndex[LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN];/*0-LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN-1*/
    VOS_UINT8                                           aucReservered[3];
}LRRC_LPHY_MBMS_PMCH_ACTIVE_CFG_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_PMCH_ACTIVE_REQ_STRU
 Э����  :
 ASN.1���� : ȫ��������
 �ṹ˵��  : LRRC_LPHY_MBMS_PMCH_ACTIVE_REQ_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT16                                          usAreaNum;              /*1 ~ LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA*/
    LRRC_LPHY_MBMS_PMCH_ACTIVE_CFG_INFO_STRU            astMbmsPmchActiveInfo[LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA];
}LRRC_LPHY_MBMS_PMCH_ACTIVE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_PMCH_ACTIVE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_PMCH_ACTIVE_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBMS_PMCH_ACTIVE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_INFO_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_UINT8                                           aucReservered[2];
}LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_MBMS_ALL_PMCH_INACTIVE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MBMS_MRS_MEAS_IND
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_MBMS_MRS_MEAS_IND���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    VOS_INT16                                           sRsrp;                  /* RSRP����ֵ */
    VOS_INT32                                           lSINR;                  /* ��Χ:(-10,40db),1X���� */
}LRRC_LPHY_MBMS_MRS_MEAS_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RCV_ALL_MCCH_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RRCָʾPHY�յ������е�MCCH��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT8                           aucResv[2];
}LRRC_LPHY_MBMS_RCV_ALL_MCCH_IND_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CONNECTED_IDLE_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : С��������̬������ֱ̬��פ�����ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/     /* ԭ����ϢID */
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usFreqInfo;                             /* С����Ƶ�� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16      enBandInd;                              /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16 enLteModeType;                          /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                          usCellId;                               /* С��ID */
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16    enDlBandWidth;                          /* ���д���,��Ӧ�տ�MasterInformationBlock->dl-Bandwidth�ֶ� */
    LRRC_LPHY_ANTANNA_PORT_ENUM_UINT16  enAntennaPortsCount;                    /* ������������,��Ӧ�տ�antennaPortsCount�ֶ� */
    VOS_UINT16                          usReserved;                             /* �����ֶ� */
    LRRC_LPHY_TDD_CONFIG_INFO_STRU      stTddConfigInfo;                        /* TDD������Ϣ,��Ӧ�տ�TDD-Configuration�ֶ�  */
}LRRC_LPHY_CONNECTED_TO_IDLE_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CONNECTED_TO_IDLE_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRC_LPHY_CONNECTED_TO_IDLE_CNF_STRU���ݽṹ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                                          usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                        enResult;
}LRRC_LPHY_CONNECTED_TO_IDLE_CNF_STRU;


/*begin: hifi sync switch */
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_HIFI_SYNC_SWITCH_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ֪ͨLDSP HIFIͬ������ָʾ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT8                                           ucHifiSyncEnabled;      /* 0: �ر�; 1: ��; */
    VOS_UINT8                                           ucPowerState;           /* Modem1 ���ػ�״̬��0 : ��ʾ�ر� 1: ��ʾ��  */
    VOS_UINT8                                           aucReserved[2];
}LRRC_LPHY_HIFI_SYNC_SWITCH_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_VOICE_SYNC_IND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : VoLTE����ҵ��������LPHY���͸���ϢLHPA��LHPAת����CODEC����ʱ��ͬ��
            |------------------|-------------------|-----OnDuration-----|
            |                  |<--uhwSendOffset-->|
            |<---uhwWakeUpOffset------------------>|
            |                  |                   |
            |                  |                   |
            HIFI����ʱ��       HIFI����������ʱ��  CDRX OnDuration��ʼʱ��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/
    VOS_UINT16                          usOpId;                                 /* ������ʶ�� */
    VOS_UINT16                          usForceSyncFlag;                        /*ǿ��ͬ����ʶ*/

    VOS_UINT32                          ulOnDurationSlice;                      /* LPHY������LTE CDRX OnDuration��ʼʱ��*/
    VOS_UINT16                          usWakeUpOffset;                         /* ��uwOnDurationSliceΪ���㣬HIFI������ǰ��*/
    VOS_UINT16                          usSendOffset;                           /* ��uwOnDurationSliceΪ���㣬HIFI����������ǰ�� */
}LRRC_LPHY_VOICE_SYNC_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RLF_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RLF�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulGcfTestModeInd;                       /*0:��ͨģʽ,1:GCF����ģʽ */
    VOS_UINT32                          ulN310;                                 /*ȡֵ��Χ[1,2,3,4,6,8,10,20]*/
    VOS_UINT32                          ulT310;                                 /*��λms,ö�ټ�36.331  6.3.2*/
    VOS_UINT32                          ulN311;                                 /*ȡֵ��Χ[1,2,3,4,5,6,8,10]*/
    VOS_UINT32                          ulT311;                                 /*��λms,ö�ټ�36.331  6.3.2*/
}LRRC_LPHY_RLF_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RLF_PARA_NOTIFY_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RLF����֪ͨ�ṹ,LPHY���ݲ�ͬ����������,�������ֲ�ͬ��ͬʧ������
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                        enMsgId;                /*_H2ASN_Skip*/

    LRRC_LPHY_RLF_PARA_STRU                             stRlfPara;
}LRRC_LPHY_RLF_PARA_NOTIFY_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SCG_RLF_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RLF�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulGcfTestModeInd;                       /*0:��ͨģʽ,1:GCF����ģʽ */
    VOS_UINT32                          ulT313;                                 /*��λms,ö�ټ�36.331  6.3.2*/
    VOS_UINT32                          ulN313;                                 /*ȡֵ��Χ[1,2,3,4,6,8,10,20]*/
    VOS_UINT32                          ulN314;                                 /*ȡֵ��Χ[1,2,3,4,5,6,8,10]*/
}LRRC_LPHY_SCG_RLF_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SCG_RLF_PARA_NOTIFY_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : SCG RLF����֪ͨ�ṹ,LPHY���ݲ�ͬ����������,�������ֲ�ͬ��ͬʧ������
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32        enMsgId;                                /*_H2ASN_Skip*/

    LRRC_LPHY_SCG_RLF_PARA_STRU         stScgRlfPara;
}LRRC_LPHY_SCG_RLF_PARA_NOTIFY_STRU;
#endif

/*****************************************************************************
 �ṹ��    : LTE_RRC_EXTBANDINFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Band28ȫƵ����������NV
             ucflag:1��ʾ��չBAND���ܴ򿪣�0��ʾ�ر�
             ucBandnum:��ʾ�м���BAND��Ҫ�õ���չBAND��
             aucRsv[]:Ԥ��
             aucBandInd[]:��Ҫ��չBAND�ŵ�BAND�б�
*****************************************************************************/
typedef struct
{
    VOS_UINT8          ucflag;
    VOS_UINT8          ucBandnum;
    VOS_UINT8          aucRsv[2];
    VOS_UINT8          aucBandInd[8];
}LTE_RRC_EXTBANDINFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_UE_CAP_SUPP_EUTRA_BAND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : UE EUTRA������RF->Band����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucEutraBand;
    VOS_UINT8                           enHalfDuplex;
    VOS_UINT8                           aucReserved[2];
} LRRC_LPHY_UE_CAP_SUPP_EUTRA_BAND_STRU;

/*****************************************************************************
 �ṹ��    : RRC_UE_CAP_RF_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : UE EUTRA������RF����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                 aucReserved[2];
    VOS_UINT16                                usCnt;
    LRRC_LPHY_UE_CAP_SUPP_EUTRA_BAND_STRU     astSuppEutraBandList[LRRC_LPHY_MAX_NUM_OF_BANDS];
} LRRC_LPHY_UE_CAP_RF_PARA_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_INIT_RECFG_INFO_STRUs
 Э����  :
 ASN.1���� :
 �ṹ˵��  : DSP���ع�������������ѡ��Ȳ���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                            ucUeCapUl;
    VOS_UINT8                            ucUeCapDl;
    VOS_UINT8                            ucAntSelect;
    VOS_UINT8                            ucNvLteDefaultBandIdx;
    VOS_UINT32                           ulGcfConnDrxStubFlag;
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16  enLteMode;
    VOS_UINT8                            aucReserved[2];
    LTE_RRC_EXTBANDINFO_STRU             stExtBandInfo;
    LRRC_LPHY_UE_CAP_RF_PARA_STRU        stRfCap;
} LRRC_LPHY_INIT_RECFG_INFO_STRU;


typedef LRRC_LPHY_FREQ_RSSI_SCAN_REQ_STRU LRRC_LPHY_FREQ_RSSI_SCAN_IND_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_CHR_SRVING_CELL_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��ǰ����С����Ϣ:����GCI��Tac��PlmnId
*****************************************************************************/
typedef struct
{
    VOS_UINT32               ulSrvCellIdentity;         /*Sib1�е�Gci*/
    VOS_UINT16               usSrvCellTrackAreaCode;    /*Sib1�е�Tac*/
    VOS_UINT16               usReserved;
    VOS_UINT32               ulMcc;
    VOS_UINT32               ulMnc;
}LRRC_LPHY_CHR_SRVING_CELL_INFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_FREQ_RSSI_SCAN_STOP_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջָʾ�����ֹͣɨ��RSSI
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
}LRRC_LPHY_FREQ_RSSI_SCAN_STOP_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_SUSPEND_NTF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRCָʾ��������RCM��Դ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
}LRRC_LPHY_SUSPEND_NTF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_RESUME_NTF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LRRCָʾ�������RCM��Դ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                  enMsgId;                      /*_H2ASN_Skip*/     /* ԭ����ϢID */
}LRRC_LPHY_RESUME_NTF_STRU;

#if (FEATURE_ON == FEATURE_LTE_R13)
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucPMeNb;                            /* ��Χ:0~15,����36.213 table5.1.4.2-1. PS�ѿտڵļ�1�ٸ���LPHY */
    VOS_UINT8                               ucPSeNb;                            /* ��Χ:0~15,����36.213 table5.1.4.2-1. PS�ѿտڵļ�1�ٸ���LPHY */
    VOS_UINT8                               ucPwrCtrlMod;
    VOS_UINT8                               ucRsv;
}LRRC_LPHY_MCG_POWER_COORDIN_STRU;



/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/

typedef struct
{
    /*common �� scell��*/
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;
    VOS_UINT16                                      usScellIdx;
    VOS_UINT16                                      usUlFreqInfo;               /* ����Ƶ��, ��Ӧ�տ�ul-FreqInfo-r10->ul-CarrierFreq-r10, ȱʡʱ����36.101���м��� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                  enBandInd;                  /* Ƶ��ָʾ */
    VOS_INT16                                       sMaxTxPwr;                  /* ����书�� p-Max-r10*/
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16      enUlCPLen;                  /* ����CP���� */
    LRRC_LPHY_BAND_WIDTH_ENUM_UINT16                enUlBandWidth;              /* ul-Bandwidth-r10 */
    VOS_UINT16                                      usReserved;

    LRRC_LPHY_PUSCH_COMM_INFO_STRU                  stPuschCommInfo;
    LRRC_LPHY_POWER_CTRL_COMM_INFO_SCELL_STRU       stPwrCtrlCommInfo;          /* �������ʿ�����Ϣ����R13��PSCELL ��SCELL�Ĳ�����һ��*/
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enAdditSpecEmissionSCellValidFlg;
    VOS_UINT16                                      usAdditSpecEmissionSCell;   /* additionalSpectrumEmissionSCell-r10 */

    /*----------------dedicated �� pscell��*/
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enSpsConfigUlEnabled;         /* SPS-ConfigurationUL��Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPucchTpcConfigEnabled;      /* TPC PUCCH������Ч��ʶ */
    LRRC_LPHY_PARA_ENABLE_ENUM_UINT16               enPuschTpcConfigEnabled;      /* TPC PUSCH������Ч��ʶ */
    VOS_UINT16                                      usReserved2;

    LRRC_LPHY_PUSCH_DEDICATED_INFO_STRU             stPuschDedicatedInfo;         /* PUSCH dedicated */
    LRRC_LPHY_POWER_CTRL_DEDICATED_INFO_STRU        stPwrCtrlDedicatedInfo;       /* power control dedicated */
    LRRC_LPHY_TPC_PDCCH_CONFIG_STRU                 stPucchTpcConfig;             /* tpc-PDCCH-ConfigPUCCH */
    LRRC_LPHY_TPC_PDCCH_CONFIG_STRU                 stPuschTpcConfig;             /* tpc-PDCCH-ConfigPUSCH */
    LRRC_LPHY_SPS_CONFIG_UL_STRU                    stSpsConfigUl;                /* SPS-Configuration->SPS-ConfigurationUL */
    LRRC_LPHY_ANTENNA_INFO_UL_STRU                  stAntennaInfoUL;              /* antennaInfoUL-r10 */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDcPhrFlg;
    VOS_UINT16                                      usReserved3;
    LRRC_LPHY_DC_PHR_STRU                           stDcPhr;                    /* SCG ��DC PHY */
}LRRC_LPHY_PUSCH_PSCELL_STRU;


/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;             /* �����ŵ����� */
    VOS_UINT16                                      usScellIdx;                   /* PSCellIndex */
    VOS_UINT16                                      usRsv;
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enDedicatedInfoValidFlag;     /* ר��PUCCH�ŵ�������Ч��ʶ */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enSrConfigInfoValidFlag;      /* SR�������ò�����Ч��ʶ */
    LRRC_LPHY_UL_CYCLIC_PREFIX_LEN_ENUM_UINT16      enUlCPLen;                    /* ����CP���� */
    LRRC_LPHY_PUCCH_COMM_INFO_STRU                  stPucchCommInfo;              /* ����PUCCH�ŵ����� */
    LRRC_LPHY_PUCCH_DEDICATED_INFO_STRU             stDedicatedInfo;              /* ר��PUCCH�ŵ����� */
    LRRC_LPHY_SR_CONFIG_INFO_STRU                   stSrConfigInfo;               /* SchedulingRequest-Configuration���� */

    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16           enMcgPwrCoordinValidFlg;
    VOS_UINT16                                      usRsv3;
    LRRC_LPHY_MCG_POWER_COORDIN_STRU                stMcgPwrCoordin;
}LRRC_LPHY_PUCCH_PSCELL_PARA_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    LRRC_LPHY_CHANNEL_TYPE_ENUM_UINT16              enPhyChannelType;
    VOS_UINT16                                      usScellIdx;
    VOS_UINT16                                      usUlFreqInfo;               /* ����Ƶ��, ��Ӧ�տ�ul-FreqInfo-r10->ul-CarrierFreq-r10, ȱʡʱ����36.101���м��� */
    LRRC_LPHY_BAND_IND_ENUM_UINT16                  enBandInd;                  /* Ƶ��ָʾ */
    LRRC_LPHY_LTE_MODE_TYPE_ENUM_UINT16             enLteModeType;              /* ָʾƵ����������ʽ����, FDD��TDD */
    VOS_UINT16                                      usPhyCellId;
    LRRC_LPHY_PRACH_CONFIG_SCELL_STRU               stPrachInfo;
}LRRC_LPHY_PRACH_PSCELL_PARA_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;

    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16      enCommand;
    LRRC_LPHY_MEAS_DS_SINGLE_FREQ_STRU      stDsFreqInfo;
}LRRC_LPHY_DS_MEAS_INTRA_REQ_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    VOS_UINT16                              usRsv;
    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16      enCommand;

    VOS_UINT16                              usFreqNum;
    LRRC_LPHY_MEAS_DS_SINGLE_FREQ_STRU      astDsFreqInfo[LRRC_LPHY_MAX_ADDITIONAL_DS_CC_NUM];
}LRRC_LPHY_DS_MEAS_INTER_REQ_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    VOS_UINT16                              usRsv;
    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16      enCommand;

    VOS_UINT16                              usFreqNum;
    LRRC_LPHY_MEAS_DS_SINGLE_FREQ_STRU      astDsFreqInfo[LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM];
}LRRC_LPHY_DS_MEAS_SECOND_FREQ_REQ_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16            enResult;
}LRRC_LPHY_DS_MEAS_INTRA_CNF_STRU;

typedef LRRC_LPHY_DS_MEAS_INTRA_CNF_STRU LRRC_LPHY_DS_MEAS_INTER_CNF_STRU;
typedef LRRC_LPHY_DS_MEAS_INTRA_CNF_STRU LRRC_LPHY_DS_MEAS_SECOND_FREQ_CNF_STRU;


/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                enMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT16                                  usOpId;
    VOS_UINT16                                  usRsv;

    LRRC_LPHY_MEAS_DS_CELL_RESULT_STRU          stDsCellRslt;
}LRRC_LPHY_DS_MEAS_MCG_PCELL_IND_STRU;

typedef LRRC_LPHY_DS_MEAS_MCG_PCELL_IND_STRU LRRC_LPHY_DS_MEAS_SCG_PSCELL_IND_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MCG��PCELL ��ͬƵ�������С���Ĳ������������PCELL��
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                enMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT16                                  usOpId;
    VOS_UINT16                                  usRsv;

    LRRC_LPHY_MEAS_DS_SINGLE_FREQ_RESULT_STRU   stDsSingleFreqRslt;
}LRRC_LPHY_DS_MEAS_INTRA_IND_STRU;

/* SCG��PSCELL ��ͬƵ�������С���Ĳ������������PSCELL�� */
typedef LRRC_LPHY_DS_MEAS_INTRA_IND_STRU LRRC_LPHY_DS_MEAS_SCG_PSCELL_INTRA_IND_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                enMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT16                                  usOpId;

    VOS_UINT8                                   ucDsFreqNum;
    VOS_UINT8                                   aucRsv[1];
    LRRC_LPHY_MEAS_DS_SINGLE_FREQ_RESULT_STRU   astDsSingleFreqRslt[LRRC_LPHY_MAX_ADDITIONAL_DS_CC_NUM];
}LRRC_LPHY_DS_MEAS_INTER_IND_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����PSCELL֮���SECOND_FREQ�Ĳ������
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                enMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT16                                  usOpId;

    VOS_UINT8                                   ucDsFreqNum;
    VOS_UINT8                                   aucRsv[1];
    LRRC_LPHY_MEAS_DS_SINGLE_FREQ_RESULT_STRU   astDsSingleFreqRslt[LRRC_LPHY_MAX_SECONDARY_CARRIER_NUM];
}LRRC_LPHY_DS_MEAS_SECOND_FREQ_IND_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 TargetMBSFN-Area-r12 ::=                SEQUENCE {
     mbsfn-AreaId-r12                    MBSFN-AreaId-r12        OPTIONAL,   -- Need OR
     carrierFreq-r12                     ARFCN-ValueEUTRA-r9,
     ...
 }
 �ṹ˵��  :����mbsfn log������area��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulFreq;
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;

    /*  �տ�ucAreaId���ܲ����� */
    LRRC_LPHY_PARA_VALID_FLAG_ENUM_UINT16   enAreaIdFlg;
    VOS_UINT8                               ucAreaId;
    VOS_UINT8                               aucRsv[3];
}LRRC_LPHY_MBSFN_TARGET_AREA_INFO_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 mbsfn-Area-r12                          SEQUENCE {
         mbsfn-AreaId-r12                        MBSFN-AreaId-r12,
         carrierFreq-r12                         ARFCN-ValueEUTRA-r9
     },

 ARFCN-ValueEUTRA-r9 ::=             INTEGER (0..maxEARFCN2)

 maxEARFCN2                  INTEGER ::= 262143  -- Highest value extended EARFCN range

 �ṹ˵��  : PHY�ϱ�MBSFN�������ʱʹ�õ�
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulFreq;
    LRRC_LPHY_BAND_IND_ENUM_UINT16          enBandInd;
    VOS_UINT16                              usRsv1;
    /*  PHY �ϱ�ʱ��ucAreaId�����ϱ� */
    VOS_UINT8                               ucAreaId;
    VOS_UINT8                               aucRsv[3];
}LRRC_LPHY_MBSFN_AREA_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    LRRC_LPHY_MEAS_COMMAND_ENUM_UINT16      enCmd;

    LRRC_LPHY_MBSFN_LOG_INTERVAL_ENUM_UINT8 enInterval;
    VOS_UINT8                               ucMbsfnAreaNum;
    VOS_UINT8                               aucRsv[2];
    LRRC_LPHY_MBSFN_TARGET_AREA_INFO_STRU   astMbsfnAreaInfo[LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA];
}LRRC_LPHY_MBSFN_LOG_REQ_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16            enResult;
}LRRC_LPHY_MBSFN_LOG_CNF_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 BLER-Result-r12 ::=                 SEQUENCE {
     bler-r12                                    BLER-Range-r12,
     blocksReceived-r12                      SEQUENCE {
         n-r12                                   BIT STRING (SIZE (3)),
         m-r12                                   BIT STRING (SIZE (8))
     }
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    /*  ��λ:0.001. ���ӣ� bler��0.123%ʱ���˲���ulBler=123;  bler��100%ʱ���˲���ulBler=100 000  */
    VOS_UINT32                              ulBler;

    VOS_UINT32                              ulBlockRcvN;        /*ԭʼ�ĸ�����С*/
    VOS_UINT8                               ucBlockRcvM;        /*ԭʼ�ĸ�����С*/
    VOS_UINT8                               aucRsv[3];
}LRRC_LPHY_MBSFN_BLER_RSLT_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 DataBLER-MCH-Result-r12 ::=             SEQUENCE {
     mch-Index-r12                           INTEGER (1..maxPMCH-PerMBSFN),
     dataBLER-Result-r12                     BLER-Result-r12
 }

 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucPmchIndex;                       /* 0-LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN-1 */
    VOS_UINT8                               aucRsv[3];

    LRRC_LPHY_MBSFN_BLER_RSLT_STRU          stDataBler;
}LRRC_LPHY_MBSFN_DATA_BLER_MCH_RSLT_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 MeasResultMBSFN-r12 ::=             SEQUENCE {
     mbsfn-Area-r12                          SEQUENCE {
         mbsfn-AreaId-r12                        MBSFN-AreaId-r12,
         carrierFreq-r12                         ARFCN-ValueEUTRA-r9
     },
     rsrpResultMBSFN-r12                     RSRP-Range,
     rsrqResultMBSFN-r12                     MBSFN-RSRQ-Range-r12,
     signallingBLER-Result-r12               BLER-Result-r12             OPTIONAL,
     dataBLER-MCH-ResultList-r12             DataBLER-MCH-ResultList-r12 OPTIONAL,
     ...
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    /* rsrp,rsrq,rssi  ͬʱ�ϱ���  ulSignalBler��tDataBlerMchͬʱ�ϱ��� ��������ϱ����ڲ�ͬ */

    LRRC_LPHY_MBSFN_AREA_STRU               stMbsfnArea;

    VOS_INT16                               sMbsfnRsrp;     /* ��λ:0.125dbm */
    VOS_INT16                               sMbsfnRsrq;     /* ��λ:0.125db */

    /* ��ͬƵ��ĸ���mbsfn area��rssi��Сһ��.��λ:0.125dbm */
    VOS_INT16                               sMbsfnRssi;
    VOS_UINT16                              usRsv;
}LRRC_LPHY_MBSFN_LOG_ENERGY_AREA_RSLT_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :

 MeasResultMBSFN-r12 ::=             SEQUENCE {
     mbsfn-Area-r12                          SEQUENCE {
         mbsfn-AreaId-r12                        MBSFN-AreaId-r12,
         carrierFreq-r12                         ARFCN-ValueEUTRA-r9
     },
     rsrpResultMBSFN-r12                     RSRP-Range,
     rsrqResultMBSFN-r12                     MBSFN-RSRQ-Range-r12,
     signallingBLER-Result-r12               BLER-Result-r12             OPTIONAL,
     dataBLER-MCH-ResultList-r12             DataBLER-MCH-ResultList-r12 OPTIONAL,
     ...
 }
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    /* rsrp,rsrq,rssi  ͬʱ�ϱ���  ulSignalBler��tDataBlerMchͬʱ�ϱ��� ��������ϱ����ڲ�ͬ */
    LRRC_LPHY_MBSFN_AREA_STRU               stMbsfnArea;

    LRRC_LPHY_MBSFN_BLER_RSLT_STRU          stSignalBler;

    VOS_UINT8                               ucDataBlerMchNum;
    VOS_UINT8                               aucRsv[3];
    LRRC_LPHY_MBSFN_DATA_BLER_MCH_RSLT_STRU astDataBlerMch[LRRC_LPHY_MAX_NUM_OF_PMCH_PER_MBSFN];
}LRRC_LPHY_MBSFN_LOG_BLER_AREA_RSLT_STRU;


/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                enMsgId;                        /*_H2ASN_Skip*/
    VOS_UINT16                                  usOpId;


    VOS_UINT8                                   ucMbsfnAreaNum;
    VOS_UINT8                                   aucRsv[1];
    LRRC_LPHY_MBSFN_LOG_ENERGY_AREA_RSLT_STRU   astAreaEnergyRslt[LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA];
}LRRC_LPHY_MBSFN_LOG_ENERGY_IND_STRU;

/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;


    VOS_UINT8                               ucMbsfnAreaNum;
    VOS_UINT8                               aucRsv[1];
    LRRC_LPHY_MBSFN_LOG_BLER_AREA_RSLT_STRU astAreaBLerRslt[LRRC_LPHY_MAX_NUM_OF_MBSFN_AREA];
}LRRC_LPHY_MBSFN_LOG_BLER_IND_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    VOS_UINT16                              usRsv;

    LRRC_LPHY_LAA_RSSI_RSLT_STRU            stLaaRssiRslt;
}LRRC_LPHY_MEAS_LAA_RSSI_IND_STRU;
/*****************************************************************************
 �ṹ��    :
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32            enMsgId;                            /*_H2ASN_Skip*/
    VOS_UINT16                              usOpId;
    VOS_UINT16                              usRsv;

    LRRC_LPHY_SSTD_RSLT_STRU                stSstdRslt;
}LRRC_LPHY_MEAS_SSTD_IND_STRU;


/* ˫LTE����˫���л����ԣ�begin */
/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MODEM_START_STATE_INFO_REQ_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MODEM����״ָ̬ʾ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                    enMsgId;    /*_H2ASN_Skip*/
    VOS_UINT16                                      usOpId;
    LRRC_LPHY_MODEM_START_STATE_TYPE_ENUM_UINT16    enModemStartState;
}LRRC_LPHY_MODEM_START_STATE_INFO_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_LPHY_MODEM_START_STATE_INFO_CNF_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MODEM����״ָ̬ʾ��Ӧ
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                              /*_H2ASN_Skip*/
    LRRC_LPHY_MSG_ID_ENUM_UINT32                    enMsgId;    /*_H2ASN_Skip*/
    VOS_UINT16                                      usOpId;
    LRRC_LPHY_RESULT_ENUM_UINT16                    enResult;
}LRRC_LPHY_MODEM_START_STATE_INFO_CNF_STRU;
/* ˫LTE����˫���л����ԣ�end */

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
 Function Name   : LPHY_NosignalNvReload
 Description     : ������ģʽ���ڲ��µ����¼���NV��������NV��ʱ��Ч
 Input           : None
 Output          : None
 Return          : None

 History         :

*****************************************************************************/
extern VOS_UINT32  LPHY_EquipNvReload(LRRC_LPHY_UE_CAP_RF_PARA_STRU *pstRfCap,
                                              LTE_RRC_EXTBANDINFO_STRU   *pstExtBandInfo);

/*****************************************************************************
 Function Name   : LPHY_InitNvLoad
 Description     : ��ʼ��ddr��������Ϣ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
*****************************************************************************/
extern VOS_UINT32  LPHY_InitNvLoad(LRRC_LPHY_UE_CAP_RF_PARA_STRU *pstRfCap,
                                        LTE_RRC_EXTBANDINFO_STRU   *pstExtBandInfo);

/*****************************************************************************
 Function Name   : LPHY_InitDspAddr
 Description     : ��ʼ���׶�����PHY�õ��ĵ�ַ
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
****************************************/
extern VOS_UINT32  LPHY_InitDspAddr( void );


/*****************************************************************************
 Function Name   : LPHY_CfgRF6360Info
 Description     : ��ʼ�������м���PHY����NV
 Input           : None
 Output          : None
 Return          : VOS_UINT32

 History         :
    1.Guojiyu      2010-5-17  Draft Enact

*****************************************************************************/
extern VOS_UINT32 LPHY_CfgRF6360Info( void );

/*****************************************************************************
 Function Name   : LHPA_GetReCfgInfo
 Description     : LPHYͨ���ú�����ȡ������Ϣ����
                   1. UE�����ȼ�
                   2. �Ƿ����128�Ǳ�Ƶ�ε�����
                   3. ����ѡ��
                   4. GCF׮
 Input           : None
 Output          : None
 Return          : VOS_VOID

 History         :
    1.Lishangfeng      2011-10-13  Draft Enact

*****************************************************************************/
extern void LHPA_GetReCfgInfo(LRRC_LPHY_INIT_RECFG_INFO_STRU *pstReCfginfo);

/*****************************************************************************
 Function Name   : LHPA_GetBandCount
 Description     : ��ȡĳ��Band�Ƿ���Ҫ���Ǳ���
 Input           : None
 Output          : None
 Return          : VOS_VOID

 History         :
    1.Lishangfeng      2011-10-13  Draft Enact

*****************************************************************************/
extern VOS_UINT16 LHPA_GetBandCount( VOS_UINT8 ucBand );



/*****************************************************************************
 Function Name   : LPHY_GetBtFtmBandCandFreqInfo
 Description     : ����BT��ʽ�£�PSͨ���ú�����ȡ��������Ƶ��NV ID
 Input           : VOS_UINT8 ucBand
 Output          : None
 Return          : 0:SUCC
                   1:FAIL
 History         :
     1.Wang Yangcai 49178       2010-12-27  Draft Enact

*****************************************************************************/
extern VOS_UINT32 LPHY_GetBtFtmBandCandFreqInfo(VOS_UINT32 *pstNVId,VOS_UINT8 ucBand);

/*****************************************************************************
 Function Name   :LRRC_LPHY_GetSrvingCellSibInfo
 Description     :��ȡ��ǰ����С����Cgi\Plmn\Tac��Ϣ
 Input           :
 Output          : pstScellInfo:��ǰ����С��sib1�е������Ϣ
 Return          : 1 ��ȡ��Ϣ�ɹ�;0 ��ȡ��Ϣʧ��
 History         :
    1.w00272217     2015-07-27  Draft Enact
*****************************************************************************/
extern VOS_UINT8 LRRC_LPHY_GetSrvingCellSibInfo(LRRC_LPHY_CHR_SRVING_CELL_INFO_STRU *pstScellInfo);

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

#endif /* end of LRrcLPhyInterface.h */
