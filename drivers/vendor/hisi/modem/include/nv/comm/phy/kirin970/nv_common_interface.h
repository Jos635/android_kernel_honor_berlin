/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : nv_common_interface
  �� �� ��   : ����
  ��    ��   : s00313518
  ��������   : 2016��4��7��
  ����޸�   :
  ��������   : common NV
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2016��4��7��
    ��    ��   : s00313518
    �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
/*#include  ###*/
#include "type_define_data.h"

#ifndef __NV_COMMON_INTERFACE_H__
#define __NV_COMMON_INTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif



/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define RX_ANTENNA_MIPI_NUM             ( 4 )
#define ANT_TUNER_MIPI_NUM              ( 2 )
#define TX_COUPLER_MIPI_NUM             ( 1 )
#define MAX_TRIG_NUM                    ( 4 )
#define TX_ANT_SEL_MIPI_NUM             ( 4 )
#define PA_MODE_MIPI_NUM                ( 4 )
#define PA_TRIG_NUM                     ( 2 )
#define LPHY_DL_PATH_NUM                     ( 8 )
#define LPHY_UL_PATH_NUM                     ( 8 )
#define DL_CA_BAND_NUM                  ( 5 )
#define UL_CA_BAND_NUM                  ( 2 )
#define CA_COM_ANT_SEL_MIPI_NUM         ( 4 )
#define CA_COM_ANT_TUNER_MIPI_NUM       ( 4 )
#define MAX_RFIC_NUM                    ( 4 )
#define MAX_RFIC_RX_CH_NUM              ( 3 )
#define MAX_RFIC_TX_CH_NUM              ( 2 )
#define MAX_BAND_NUM                    ( 32 )
#define RF_RX_MAX_FREQ_NUM              ( 32 )
#define AGC_MAX_GAIN_NUM                ( 8 )
#define AGC_SWITCH_THRESHOLD_NUM        ( AGC_MAX_GAIN_NUM - 1 )
#define AGC_MAX_TABLE_NUM               ( 10 )
#define MAX_VGA_GAIN_NUM                ( 16 )

#define LNA_SINGLE_GAIN_MIPI_NUM        ( 4 )
#define EXT_LNA_LEVEL_NUM               ( 4 )
#define EXT_LNA_BAND_SEL_NUM            ( 2 )
#define EXT_LNA_OFF_NUM                 ( 2 )
#define LNA_MIPI_TRIG_NUM               ( 8 )
#define EXT_LNA_GIAN_CAL_NUM           ( 2 )



#define MAX_IP2_CAL_FREQ_NUM            ( 3 )

#define RF_TX_GAIN_6363_NUM             ( 20 )
#define RFIC_INIT_REG_NUM               ( 256 )
#define BBGAIN_NUM_PER_RFGAIN           ( 2 )
#define RF_PA_GAIN_NUM                  ( 3 )
#define MAX_TX_ANT_NUM                  ( 2 )
#define MAX_RX_ANT_NUM                  ( 4 )
#define CAL_IP2_FREQ_NUM                ( 3 )

#define MAX_DL_CC_NUM                   ( 5 )
#define MAX_UL_CC_NUM                   ( 2 )
#define MAX_DL_BAND_NUM                 (MAX_DL_CC_NUM)
#define MAX_UL_BAND_NUM                 (MAX_UL_CC_NUM)

#define MAX_TEMP_DEFINE_NUM             (32)
/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  6 STRUCT����
*****************************************************************************/

/****************************RF NV  ����*************************************/
/*****************************************************************************
 �ṹ��    : PHY_MIPIDEV_CMD_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MIPI������ƽṹ��
*****************************************************************************/
typedef struct
{
    UINT32                              bitByteCnt                  :5;          /* 0��ʾ��CMMAND��Ч��ȡֵ0~4 */
    UINT32                              bitMipiPortSel              :3;          /* mipi port 0~7 */
    UINT32                              bitSlaveID                  :4;          /* slave id 0~15 */
    UINT32                              bitRegAddr                  :16;         /* reg addr 0~65535 */
    UINT32                              bitRsv                      :4;          /* ���ֽڶ��� */

} PHY_MIPIDEV_CMD_STRU;

/*****************************************************************************
 �ṹ��    : PHY_MIPIDEV_DATA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MIPI���ݽṹ��
*****************************************************************************/
typedef struct
{
    UINT32                              bitByte0                    :8;          /* ��һ��byte */
    UINT32                              bitByte1                    :8;          /* �ڶ���byte */
    UINT32                              bitByte2                    :8;          /* ������byte */
    UINT32                              bitByte3                    :8;          /* ���ĸ�byte */

} PHY_MIPIDEV_DATA_STRU;

/*****************************************************************************
 �ṹ��    : PHY_MIPIDEV_UNIT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : MIPI������С��Ԫ
*****************************************************************************/
typedef struct
{
    PHY_MIPIDEV_CMD_STRU                stCmd;                                  /*������*/
    PHY_MIPIDEV_DATA_STRU               stData;                                 /*������,һ��MIPIռ��2��UINT32*/

} PHY_MIPIDEV_UNIT_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_OPERATING_BAND_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Ƶ�νṹ��
*****************************************************************************/
typedef struct
{
    UINT16                              bitBand                     :8;         /* Ƶ�κţ�band1:1,band2:2, �������� */
    UINT16                              bitBandExIdx                :2;         /* ������������Band����0��Band 128��1 */
    UINT16                              bitLteNvValidFlag           :1;         /* only for Lte,�ж�NV�Ƿ���Ч */
    UINT16                              bitRsv0                     :3;
    UINT16                              bitRsv1                     :2;

}NV_MODEM_OPERATING_BAND_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_DL_RFIC_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����RFIC����,����RFIC ID,ͨ���ţ������PORT��
*****************************************************************************/
typedef struct
{
    UINT32                              bitRficIdx                  :2;         /* RFIC ID��[0,2]�ֱ��ʾRFIC1��RFIC2��RFIC3 */
    UINT32                              bitRficRxCh                 :2;         /* ����RXͨ���ţ�ÿ��RFIC��3��ͨ�����ֱ���RX1��RX2��RX3; ��������4*4MIMO�̶�ʹ��RX1A1B+RX3A3B,���ǲ���ͬһ��TX_PLL1���ƣ����MIMO��������ѡRXͨ������4����2��ʱ��
                                                                                ֻ����Main��Div Ant,RFIC������RxCh��Ҫ��дʹ�õ�ͨ���ţ����֧��2�ճ�����RxCh��ʾʹ�õ�Rxͨ����;
                                                                                4R ��2R����ͬһ��NV */


    UINT32                              bitRfPortCrossFlag          :1;         /*�������ߵ��ź����ӵ��� RFIC DRX Port�ڣ������Ҫ��CTUͨ�����浽������ֻ֧��2�յĽ���*/
    UINT32                              bitMainAntRxPortSel         :4;         /* ����LNA��RFIC�˿�ѡ�񣬼��ź�ͨ���ĸ��˿����뵽RFIC */
    UINT32                              bitDivAntRxPortSel          :4;         /* �ּ�LNA��RFIC�˿�ѡ�� */
    UINT32                              bitAuxMainAntRxPortSel      :4;         /* ��������LNA��RFIC�˿�ѡ��Ŀǰֻ��LTEʹ�ã�GUC��ʹ�� */
    UINT32                              bitAuxDivAntRxPortSel       :4;         /* �����ּ�LNA��RFIC�˿�ѡ��Ŀǰֻ��LTEʹ�ã�GUC��ʹ�� */
    UINT32                              bitRsv0                     :2;         /* Ԥ��λ */
    UINT32                              bitRsv1                     :2;
    UINT32                              bitRsv2                     :2;
    UINT32                              bitRsv3                     :2;
    UINT32                              bitRsv4                     :3;

} NV_BAND_DL_RFIC_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_UL_RFIC_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����RFIC����,����RFIC ID,ͨ���ţ������PORT��
*****************************************************************************/
typedef struct
{
    UINT32                              bitRficIdx                 :2;          /* ����ͨ�����ڵ�RFIC ID,֧���շ����� */
    UINT32                              bitRficTxCh                :2;          /* ����ͨ���ţ�����MIMO�̶�ʹ��Tx1Ch,��˵���������MIMO�󣬲�ȡ��ͨ������������£���дTx1Iq1,Tx2Iq������2Txת1Tx����NV�����Ժ�Rxһ��*/
    UINT32                              bitMainAntRficTxPortSel    :4;          /* ����PORT��ѡ�� */
    UINT32                              bitDivAntRficTxPortSel     :4;
    UINT32                              bitMainAntRficTxMrxPortSel :1;           /*���л���ͨ����Mrxͨ����ѡ��0: MRX1 RF input selected  1: MRX2 RF input selected*/
    UINT32                              bitDivAntRficTxMrxPortSel  :1;
    UINT32                              bitRsv0                    :2;
    UINT32                              bitRsv1                    :2;
    UINT32                              bitRsv2                    :2;
    UINT32                              bitRsv3                    :2;
    UINT32                              bitRsv4                    :2;
    UINT32                              bitRsv5                    :4;
    UINT32                              bitRsv6                    :4;
}NV_BAND_UL_RFIC_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_DL_CONFIG_TIME_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ʱ��NV�ṹ�����ṹ�嶨��
*****************************************************************************/
typedef struct
{

    UINT16                              usLnaBandSelTime;
    UINT16                              usLnaGainSwitchTime;
    UINT16                              usLnaOffTime;
    UINT16                              usLnaTimeRsv;
}NV_DL_CONFIG_TIME_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_DL_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ÿ��PATH������RFICͨ������
*****************************************************************************/
typedef struct
{
    UINT16                              bitRxAntNum                 :3;         /* ���������� */
    UINT16                              bitMainAntValidFlag         :1;         /* 2��case�£�ʹ�����߷ֲ����������У׼ */
    UINT16                              bitDivAntValidFlag          :1;
    UINT16                              bitAuxMainAntValidFlag      :1;
    UINT16                              bitAuxDivAntValidFlag       :1;
    UINT16                              bitRsv0                     :2;
    UINT16                              bitRsv1                     :7;
    UINT16                              usDlFemPathIdx;                         /* ��ȡ���� FemPath NV��Idx��:0~255��FemPathNV ��ȫ��̬��ѯ������ ���ߺ�����LNAͬʱ��ѯ������Idx����һ��*/

    NV_BAND_DL_RFIC_PARA_STRU           stBandDlRficPara;                       /* ����RFIC���� */
    NV_DL_CONFIG_TIME_PARA_STRU         astLnaTimePara[MAX_RX_ANT_NUM];
} NV_BAND_DL_PATH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_UL_CONFIG_TIME_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����ʱ������
*****************************************************************************/
typedef struct
{
    UINT16                              usPaOpenTime;                           /* PA ��ʱ������ʱ�� */
    UINT16                              usPaUpModeTime;                       /* PA ����������ʱ�� */
    UINT16                              usPaDownModeTime;                        /* PA ����������ʱ�� */
    UINT16                              usPaCloseTime;                          /* PA �ر�������ʱ�� */
    UINT16                              usTxPchApcRficTime;                 /*������Ҫ�����߼������޸�*/
    UINT16                              usTxSrsApcRficTime;                 /*������Ҫ�����߼������޸�*/
}NV_UL_CONFIG_TIME_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_UL_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ÿ��PATH������RFICͨ������
*****************************************************************************/
typedef struct
{
    UINT16                              bitTxAntNum                 :2;         /* ���������� */
    UINT16                              bitMainAntValid             :1;         /* 2��case�£�ʹ�����߷ֲ����������У׼ */
    UINT16                              bitDivAntValid              :1;
    UINT16                              bitAptPdm0PinSel            :3;
    UINT16                              bitAptPdm1PinSel            :3;         /* GUCT ģ������ */
    UINT16                              bitPmuAuxSel                :3;
    UINT16                              bitRsv                      :3;
    UINT16                              usUlFemPathIdx;                         /* ��ȡ���� FemPath NV��Idx��:0~255��FemPathNV ��ȫ��̬��ѯ */

    NV_BAND_UL_RFIC_PARA_STRU           stBandUlRficPara;                       /* RFIC���� */

    NV_UL_CONFIG_TIME_PARA_STRU         stUlCfgTime[MAX_TX_ANT_NUM];
}NV_BAND_UL_PATH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_MODEM_USED_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ÿ��Band�ڵ��ز��Լ�����ʹ�õ�PathIdx,LTE������������
*****************************************************************************/
typedef struct
{
    UINT32                              bitBand                     :8;         /* Ƶ�κţ�band1:1,band2:2, �������� */
    UINT32                              bitBandExIdx                :2;         /* ������������Band����0��Band 128��1 */
    UINT32                              bitLteNvValidFlag           :1;         /* only for Lte,�ж�NV�Ƿ���Ч */
    UINT32                              bitTASSupport               :1;         /* bitBlindSwitchFlag:�Ƿ�֧��TASä��,1��֧�֣�����߶���*/
    UINT32                              bitMASSupport               :2;         /* ֧������ 0-��֧�� 1-֧��������MAS 2-֧��������MAS 3��֧����������MAS*/
    UINT32                              bitRsv3                     :2;

    UINT32                              bitDlPathNum                :4;         /* У׼���� ,���֧��8��,PathNum = 8,��ʾ֧�ֵĸ�����0��ʾ��֧�� */
    UINT32                              bit2AntSingleCcDlPathIdx    :3;         /* Modem0:���ز� 2 ������ѡ���path��� :0~7*/
    UINT32                              bit4AntSingleCcDlPathIdx    :3;         /* Modem0:���ز� 4 ������ѡ���path��� :0~7,��2�պ�4��Pathidx��ͬ�����ز�У׼ֻУ׼һ�Σ��Ұ�4��У׼ */
    UINT32                              bit8by8MimoAddPathIdx       :3;         /* 8�����ӵĶ���Pathidx�� */
    UINT32                              bitListeningDlPathIdx       :3;         /* Modem0:����ͨ����ʶ */

    UINT32                              bitUlPathNum                :4;         /* Modem0:У׼����,���֧��8��,PathNum = 8,��ʾ֧�ֵĸ�����0��ʾ��֧�� */
    UINT32                              bit1AntSingleCcUlPathIdx    :3;         /* Modem0:���ز� ��������ѡ���path���:0~7 */
    UINT32                              bit2AntSingleCcUlPathIdx    :3;         /* Modem0:���ز� ˫������ѡ���path���:0~7 */
    UINT32                              bitListeningUlPathIdx       :3;         /* Modem0:����ͨ����ʶ*/
    UINT32                              bitAntNum                   :3;

    /* Modem1 used path information */
    UINT32                              bitModem1DlPathIdx          :3;         /* Modem1(����)ʹ�õ�����PathIdx :0~7,LTEʹ�ãGGUC������ */
    UINT32                              bitModem1UlPathIdx          :3;         /* Modem1(����)ʹ�õ�����PathIdx :0~7,LTEʹ�ãGGUC������ */
    UINT32                              bitModem1ListenDlPathIdx    :3;         /* Modem1(����)ʹ�õ���������PathIdx :0~7,LTEʹ�ãGGUC������ */
    UINT32                              bitModem1AntNum             :3;
    UINT32                              bitRsv2                     :4;
}NV_BAND_USED_PATH_STRU;
/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_BAND_CONFIG_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LTE��RF BAND ���ã�����ÿ��ģʽ��ÿ��Ƶ�Σ�����GSM���֧��9��Ƶ��
             WCDMA֧��20��Ƶ�Σ�LTE֧��64-9-20=35��Ƶ�Σ�Ŀǰ�ýṹ��LTEʹ�ã�
             GUCģ���������������
*****************************************************************************/
typedef struct
{
    NV_BAND_USED_PATH_STRU             stBandModemInfo;
    NV_BAND_DL_PATH_PARA_STRU           astBandDlPathPara[LPHY_DL_PATH_NUM];         /* ����PATH��ţ�ĿǰDL���֧��6��GUCģֻ��Ҫ1��path */
    NV_BAND_UL_PATH_PARA_STRU           astBandUlPathPara[LPHY_UL_PATH_NUM ];         /* ����PATH��ţ�ĿǰUL���֧��3��GUCģֻ��Ҫ1��path */

}NV_MODEM_RF_BAND_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_DL_GPIO_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ǰ������GPIO���ã��������߿��أ�TUNER�ȣ�֧�����߿��غ�TUNER��������
*****************************************************************************/
typedef struct
{
    UINT32                              ulMainRxAntSel;                         /*ASMͨ·�ϵ��л�����,�����߿��ػ��ȥ*/
    UINT32                              ulMainRxAntSelExt;                      /*ASMͨ·�ϵ��л�����,�����߿��ػ��ȥ*/
    UINT32                              ulDivRxAntSel;
    UINT32                              ulDivRxAntSelExt;
    UINT32                              ulAuxMainRxAntSel;                      /*ASMͨ·�ϵ��л�����*/
    UINT32                              ulAuxMainRxAntSelExt;
    UINT32                              ulAuxDivRxAntSel;
    UINT32                              ulAuxDivRxAntSelExt;
    UINT32                              ulMainRxTunerSel;                       /*ASMͨ·�ϵ��л�����*/
    UINT32                              ulMainRxTunerSelExt;
    UINT32                              ulDivRxTunerSel;
    UINT32                              ulDivRxTunerSelExt;
    UINT32                              ulAuxMainTunerRxSel;                    /*ASMͨ·�ϵ��л�����*/
    UINT32                              ulAuxMainTunerRxSelExt;
    UINT32                              ulAuxDivRxTunerSel;
    UINT32                              ulAuxDivRxTunerSelExt;

} NV_BAND_DL_GPIO_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_DL_MIPI_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ǰ������MIPI���ã��������߿��أ�TUNER�ȣ�֧�����߿��غ�TUNER��������
*****************************************************************************/
typedef struct
{
    PHY_MIPIDEV_UNIT_STRU              astMipiMainAntRxSel[RX_ANTENNA_MIPI_NUM];            /*Ant Mipi num=4,��Ҫ��Ƶ����*/
    PHY_MIPIDEV_UNIT_STRU              astMipiDivAntRxSel[RX_ANTENNA_MIPI_NUM ];
    PHY_MIPIDEV_UNIT_STRU              astMipiAuxMainAntRxSel[RX_ANTENNA_MIPI_NUM ];
    PHY_MIPIDEV_UNIT_STRU              astMipiAuxDivAntRxSel[RX_ANTENNA_MIPI_NUM ];
    PHY_MIPIDEV_UNIT_STRU              astMipiMainTunerRxSel[ANT_TUNER_MIPI_NUM ];
    PHY_MIPIDEV_UNIT_STRU              astMipiDivTunerRxSel[ANT_TUNER_MIPI_NUM ];           /*Tuner Mipi num=2,��Ҫ��Ƶ����*/
    PHY_MIPIDEV_UNIT_STRU              astMipiAuxMainTunerRxSel[ANT_TUNER_MIPI_NUM ];
    PHY_MIPIDEV_UNIT_STRU              astMipiAuxDivTunerRxSel[ANT_TUNER_MIPI_NUM ];
    PHY_MIPIDEV_UNIT_STRU              astMipiAntTrig[MAX_RX_ANT_NUM ];                     /*Ant Mipi Trig*/
    PHY_MIPIDEV_UNIT_STRU              astMipiTunerTrig[MAX_RX_ANT_NUM ];                   /*Tuner Mipi Trig*/
} NV_BAND_DL_MIPI_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_DL_FEM_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ÿ��PATH��ǰ������MIPI���ã��������߿��أ�TUNER�ȣ�
             ֧�����߿��غ�TUNER��������
*****************************************************************************/
typedef struct
{

    NV_BAND_DL_GPIO_PARA_STRU           stBandDlGpioPara;                       /* ÿ��PATH����GPIO���� */
    NV_BAND_DL_MIPI_PARA_STRU           stBandDlMipiPara;                       /* ÿ��PATH����MIPI���� */

}NV_BAND_DL_FEM_PATH_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_DL_FEM_PATH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����PATH��ǰ������MIPI���ã��������߿��أ�TUNER�ȣ�
             ֧�����߿��غ�TUNER��������
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;
    UINT16                              usLteNvValidFalg;
    NV_BAND_DL_FEM_PATH_PARA_STRU       stBandDlFemPathPara;

}NV_MODEM_RF_DL_FEM_PATH_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_UL_GPIO_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����GPIO���ã��������߿��أ�TUNER�ȣ�֧�����߿��غ�TUNER��������
*****************************************************************************/
typedef struct
{
    UINT32                              ulTxAntSel;                             /* �������߿��� */
    UINT32                              ulTxAntSelExt;
    UINT32                              UlTxAntCrossSel;                        /* LTE��վѡ�����UE ���佻�浽�ּ����ߣ�GPIO����;GUCT ������ */
    UINT32                              ulTxTuner;                              /* ����Tuner���� */
    UINT32                              ulTxTunerExt;
    UINT32                              ulPaEnCtrl;                             /* PA�߿ؿ��� */
    UINT32                              ulPaHighModeCtrl;                       /* PA����������� */
    UINT32                              ulPaMidModeCtrl;                        /* PA����������� */
    UINT32                              ulPaLowModeCtrl;                        /* PA����������� */
    UINT32                              ulPaUltraLowModeCtrl;                   /* utralow */

} NV_BAND_UL_GPIO_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_UL_MIPI_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����MIPI���ã��������߿��أ�TUNER�ȣ�֧�����߿��غ�TUNER��������
*****************************************************************************/
typedef struct
{
    PHY_MIPIDEV_UNIT_STRU               astMipiAntSelTx[TX_ANT_SEL_MIPI_NUM];   /* MIPI�������߿���  TX_ANT_SEL_MIPI_NUM =4 */
    PHY_MIPIDEV_UNIT_STRU               astMipiTunerTx[ANT_TUNER_MIPI_NUM];     /* MIPI����TUNER���� ֧���շ������ģʽ��Ҫ���� */


    PHY_MIPIDEV_UNIT_STRU               stMipiPaOnCtrl;                         /* MIPI PA On���� */
    PHY_MIPIDEV_UNIT_STRU               stMipiPaOffCtrl;                        /* MIPI PA OFF���� */
    PHY_MIPIDEV_UNIT_STRU               astMipiPaHighMode[PA_MODE_MIPI_NUM];    /* MIPI PA����������� PA_MODE_MIPI_NUM=4 */
    PHY_MIPIDEV_UNIT_STRU               astMipiPaMidMode[PA_MODE_MIPI_NUM];     /* MIPI PA����������� PA_MODE_MIPI_NUM=4 */
    PHY_MIPIDEV_UNIT_STRU               astMipiPaLowMode[PA_MODE_MIPI_NUM];     /* MIPI PA����������� PA_MODE_MIPI_NUM=4 */
    PHY_MIPIDEV_UNIT_STRU               astMipiPaUltraLowMode[PA_MODE_MIPI_NUM];

} NV_BAND_UL_MIPI_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_UL_FEM_SINGLE_ANTENNA_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ǰ����������
*****************************************************************************/
typedef struct
{
    NV_BAND_UL_GPIO_PARA_STRU           stBandUlGpioPara;                       /* ����GPIO���� */
    NV_BAND_UL_MIPI_PARA_STRU           stBandUlMipiPara;                       /* ����MIPI���� */

}NV_BAND_UL_FEM_SINGLE_ANTENNA_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_UL_FEM_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ǰ���������ã�ÿ��PATH������
*****************************************************************************/
typedef struct
{
    NV_BAND_UL_FEM_SINGLE_ANTENNA_PARA_STRU astBandUlFemPara[MAX_TX_ANT_NUM];   /*������������������FEM �ṹ*/
    PHY_MIPIDEV_UNIT_STRU                   astMipiAntTxTrig[MAX_TX_ANT_NUM];
    PHY_MIPIDEV_UNIT_STRU                   astMipiPaTrig[MAX_TX_ANT_NUM];

}NV_BAND_UL_FEM_PATH_PARA_STRU;

/*****************************************************************************
�ṹ��    : NV_RF_UL_FEM_PATH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ǰ���������ã�����PATH������
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;
    UINT16                              bitLteNvValidFalg     :1;
    UINT16                              bitRsv0               :2;
    UINT16                              bitRsv1               :2;
    UINT16                              bitRsv2               :2;
    UINT16                              bitRsv3               :2;
    UINT16                              bitRsv4               :2;
    UINT16                              bitRsv5               :2;
    UINT16                              bitRsv6               :3;

    NV_BAND_UL_FEM_PATH_PARA_STRU       stBandUlFemPathPara;
}NV_RF_UL_FEM_PATH_STRU;                                                      /* Lģ:����FEM Path,����1��Path 1��NV ID������ģ 1��Path */

/*****************************************************************************
�ṹ��    : NV_BAND_UL_FEM_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LTE ����FEM Path NV ������ع��������� NV,����ģ���ɼ�
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;
    UINT16                              bitLteNvValidFalg     :1;
    UINT16                              bitRsv0               :2;
    UINT16                              bitRsv1               :2;
    UINT16                              bitRsv2               :2;
    UINT16                              bitRsv3               :2;
    UINT16                              bitRsv4               :2;
    UINT16                              bitRsv5               :2;
    UINT16                              bitRsv6               :3;

    NV_BAND_UL_FEM_PATH_PARA_STRU astBandUlFemPathPara[LPHY_UL_PATH_NUM ];
}NV_MODEM_RF_UL_FEM_PATH_STRU;                                                /* ���ʹ�ã������ų�NV*/
/*****************************************************************************
 �ṹ��    : NV_LNA_CTRL_ENUM
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����LNA���÷�ʽ��GPIO��MIPI
*****************************************************************************/
typedef enum __NV_EXT_LNA_CTRL_ENUM__
{
    EXT_NA_CTRL_NOT                        = 0,
    EXT_LNA_GPIO_CTRL                       = 1,
    EXT_LNA_MIPI_CTRL                       = 2,
    EXT_LNA_GPIO_MIPI_CTRL                  = 4,
    EXT_LNA_CTRL_BUTT                       = 5

}NV_EXT_LNA_CTRL_ENUM;

typedef UINT16 NV_EXT_LNA_CTRL_ENUM_UINT16;

/*****************************************************************************
 �ṹ��    : NV_EXT_LNA_ANTINFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : LNA�������
*****************************************************************************/
typedef struct
{

    NV_EXT_LNA_CTRL_ENUM_UINT16         enLnaCtrlInd;                           /* LNA���Ʒ�ʽ */
    UINT16                              usGpioLnaLevelNum;                      /* Lna֧�ֵĵ�λ */

    UINT32                              ulGpioLnaMask;                          /* LNA GPIO�߿� */
    UINT32                              ulGpioLnaMaskExt;

    UINT32                              aulGpioLnaGain[EXT_LNA_LEVEL_NUM];      /* GPIO LNA���� */
    UINT32                              aulGpioLnaGainExt[EXT_LNA_LEVEL_NUM];

    PHY_MIPIDEV_UNIT_STRU               astMipilnaBandSel[EXT_LNA_BAND_SEL_NUM];/* MIPI LAN bandѡ�� */

    PHY_MIPIDEV_UNIT_STRU               astMipiLnaOff[EXT_LNA_OFF_NUM];         /* MIPI LAN OFF */

    PHY_MIPIDEV_UNIT_STRU               astMipiLnaGain0[LNA_SINGLE_GAIN_MIPI_NUM]; /* MIPI LAN GAIN0���� */
    PHY_MIPIDEV_UNIT_STRU               astMipiLnaGain1[LNA_SINGLE_GAIN_MIPI_NUM]; /* MIPI LAN GAIN1���� */
    PHY_MIPIDEV_UNIT_STRU               astMipiLnaGain2[LNA_SINGLE_GAIN_MIPI_NUM]; /* MIPI LAN GAIN2���� */
    PHY_MIPIDEV_UNIT_STRU               astMipiLnaGain3[LNA_SINGLE_GAIN_MIPI_NUM]; /* MIPI LAN GAIN3���� */

    UINT16                              ausNoblockLnaGainIdx[AGC_MAX_GAIN_NUM]; /* ʵ�ʵ�AGC NOBLOCK��λ��������LNA�ĵ�λ */
    UINT16                              ausBlockLnaGainIdx[AGC_MAX_GAIN_NUM];   /* ʵ�ʵ�AGC BLOCK��λ��������LNA�ĵ�λ */
    UINT16                              ausAcsLnaGainIdx[AGC_MAX_GAIN_NUM];     /* ʵ�ʵ�ACS NOBLOCK��λ��������LNA�ĵ�λ */

}NV_EXT_LNA_ANTINFO_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_EXT_LNA_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����LNA��������������ṹ��Ϣ
*****************************************************************************/
typedef struct
{
    NV_EXT_LNA_ANTINFO_STRU                stMainAntLnaInfo;
    NV_EXT_LNA_ANTINFO_STRU                stDivAntLnaInfo;
    NV_EXT_LNA_ANTINFO_STRU                stAuxMainAntLnaInfo;
    NV_EXT_LNA_ANTINFO_STRU                stAuxDivAntLnaInfo;
    PHY_MIPIDEV_UNIT_STRU               astLnaTrig[LNA_MIPI_TRIG_NUM];          /*4RX ��Ӧ��Extra Lna MIPI����ͬʱ��Ч*/

}NV_BAND_EXT_LNA_PATH_PARA_STRU;


/*****************************************************************************
 �ṹ��    : NV_RF_EXT_LNA_PATH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����LNA ���� Path �ܽṹ�����ṹ�嶨�壬����Band�ţ�Path��Ϣ
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;
    UINT16                              bitLteNvValidFalg     :1;
    UINT16                              bitRsv0               :2;
    UINT16                              bitRsv1               :2;
    UINT16                              bitRsv2               :2;
    UINT16                              bitRsv3               :2;
    UINT16                              bitRsv4               :2;
    UINT16                              bitRsv5               :2;
    UINT16                              bitRsv6               :3;

    NV_BAND_EXT_LNA_PATH_PARA_STRU      stExtLnaPathPara;
}NV_RF_EXT_LNA_PATH_STRU;                                                       /*LTE����LNA6��pathռ��6��NV ID,����ģ1��*/


/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_LNA_PATH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ����LNA Lģ����6�� Path �ܽṹ�����ṹ�嶨�壬����NV ����
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;                                 /* ���ʹ�ã������ų�NV*/
    UINT16                              bitLteNvValidFalg     :1;
    UINT16                              bitRsv0               :2;
    UINT16                              bitRsv1               :2;
    UINT16                              bitRsv2               :2;
    UINT16                              bitRsv3               :2;
    UINT16                              bitRsv4               :2;
    UINT16                              bitRsv5               :2;
    UINT16                              bitRsv6               :3;

    NV_RF_EXT_LNA_PATH_STRU         astExtLnaPathPara[LPHY_DL_PATH_NUM];
}NV_MODEM_RF_LNA_PATH_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_DL_PATHUSED_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CA������Band�ţ��Լ�Bandʹ�õ�Path��Ϣ
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;
    UINT16                              bitRxAntNum            :3;               /* 2:2���ߣ�4:4���� */
    UINT16                              bitDlPathIdx           :3;               /* 0~7*/
    UINT16                              bitCompFemPathValidFlg :1;               /* �Ƿ�ʹ���ڻ�׼ͨ��֮�ϵĲ���ͨ����ǣ�װ����Ҫ���ݴ��ж�BT��ʾ*/
    UINT16                              bitRsv0                :4;
    UINT16                              bitRsv1                :3;
    UINT16                              bitRsv2                :2;
    INT16                               sMainRxAntRfILComp;                     /* CA����¿����ڲ���DlPath�����,LTE�ã�GUC���� */
    INT16                               sDivRxAntRfILComp;                      /* CA����¿����ڲ���DlPath�����,LTE�ã�GUC���� */
    INT16                               sAuxMainRxAntRfILComp;                  /* CA����¿����ڲ���DlPath�����,LTE�ã�GUC���� */
    INT16                               sAuxDivRxAntRfILComp;                   /* CA����¿����ڲ���DlPath�����,LTE�ã�GUC���� */

}NV_BAND_DL_PATHUSED_INFO_STRU;


/*****************************************************************************
 �ṹ��    : NV_BAND_UL_PATHUSED_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CA������Band�ţ��Լ�Bandʹ�õ�Path��Ϣ
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        stBand;
    UINT16                              bitTxAntNum            :2;              /* 1:1���ߣ�2:2����;��������������CA����ж�
                                                                                       ������������ͬʹ��PathIdx��ͬ */
    UINT16                              bitUlPathIdx           :3;              /* 0~7*/
    UINT16                              bitCompFemPathValidFlg :1;              /* �Ƿ�ʹ���ڻ�׼ͨ��֮�ϵĲ���ͨ����ǣ�װ����Ҫ���ݴ��ж�BT��ʾ*/
    UINT16                              bitRsv0                :4;
    UINT16                              bitRsv1                :3;
    UINT16                              bitRsv2                :3;
    INT16                               sMainTxAntRfILComp;                     /* CA����¿����ڼ���DlPath������ģ�������׼ͨ�� */
    INT16                               sDivTxAntRfILComp;                      /* CA����¿����ڼ���DlPath������ģ�������׼ͨ�� */
    PHY_MIPIDEV_UNIT_STRU               astInterSubFrmAntSel[RX_ANTENNA_MIPI_NUM];  /*��ʱ϶��ȿ�������*/

}NV_BAND_UL_PATHUSED_INFO_STRU;


/*****************************************************************************
 �ṹ��    : NV_COMBAND_CC_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CA��CC �����Ϣ
*****************************************************************************/
typedef struct
{
    NV_MODEM_OPERATING_BAND_STRU        ausDlBandList[DL_CA_BAND_NUM];          /*DL BandList*/
    NV_MODEM_OPERATING_BAND_STRU        ausUlBandList[UL_CA_BAND_NUM];          /*UL BandList*/
    UINT16                              usRsv0;

}NV_COMBAND_CC_LIST_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_RF_CA_BAND_CONFIG_PATH_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : CA NV �ܽṹ�����ṹ�嶨�壬����Band�ţ�Path��Ϣ
*****************************************************************************/
typedef struct
{
    UINT16                              usDlBandNum;                            /*DL Band Num: CA>1,If BandNum=0,this NV is invalid.*/
    UINT16                              usUlBandNum;
    NV_COMBAND_CC_LIST_STRU             stComBandCcList;
    PHY_MIPIDEV_UNIT_STRU               astMipiCaTuner[ANT_TUNER_MIPI_NUM];
    PHY_MIPIDEV_UNIT_STRU               astCommDSubFrmAntSel[RX_ANTENNA_MIPI_NUM];
    PHY_MIPIDEV_UNIT_STRU               astCommUSubFrmAntSel[RX_ANTENNA_MIPI_NUM];
    NV_BAND_DL_PATHUSED_INFO_STRU       astBandDlPathUsedInfo[DL_CA_BAND_NUM];  /* DL_CA_BAND_NUM = 5*/
    NV_BAND_UL_PATHUSED_INFO_STRU       astBandUlPathUsedInfo[UL_CA_BAND_NUM];  /* UL_CA_BAND_NUM = 2*/

} NV_LTE_RF_CA_BAND_CONFIG_PATH_STRU;

/*****************************************************************************
 �ṹ��    : NV_BAND_CONFIG_TIME_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ʱ��NV�ṹ�����ṹ�嶨��
*****************************************************************************/
typedef struct
{
    UINT16 usBandNum;                                                           /*ÿ��Path��Ч�� Band���� */
    UINT16 usRsv;
    NV_UL_CONFIG_TIME_PARA_STRU         astTimePara[MAX_BAND_NUM];                      /*ÿ��Path���֧��32��Band Time���� */
}NV_BAND_CONFIG_TIME_PARA_STRU;


/*****************************************************************************
 �ṹ��    : NV_LTE_RF_UL_BAND_CONFIG_TIME_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ʱ��NV�ṹ�����ṹ�壬NV��ʾ�ṹ
*****************************************************************************/
typedef struct
{

    NV_BAND_CONFIG_TIME_PARA_STRU       stFeTimePathPara;
}NV_LTE_RF_UL_BAND_CONFIG_TIME_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_UL_BAND_CONFIG_TIME_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ʱ��NV�ṹ�����ṹ�壬NV������ؽṹ
*****************************************************************************/
typedef struct
{

    NV_LTE_RF_UL_BAND_CONFIG_TIME_STRU  astUlFeTimePathPara[LPHY_UL_PATH_NUM ];       /* ���ʹ�ã������ų�NV*/
}NV_MODEM_RF_UL_BAND_CONFIG_TIME_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_DL_BAND_CONFIG_TIME_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ʱ��NV�ṹ�����ṹ�壬NV������ؽṹ
*****************************************************************************/
typedef struct
{

    NV_DL_CONFIG_TIME_PARA_STRU  astDLFeTimePathPara[LPHY_DL_PATH_NUM];       /* ���ʹ�ã������ų�NV*/
}NV_MODEM_RF_DL_BAND_CONFIG_TIME_STRU;

/*****************************************************************************
 �ṹ��    : NV_RF_MIPI_INIT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RFIC ��ʼ���ṹ�����ṹ�嶨��
*****************************************************************************/
typedef struct
{


    UINT32                              bitSlaveId:8;
    UINT32                              bitRegAddr:16;                              /* Reg Addr: 0~65535 ,Extended Write Long MIPI*/
    UINT32                              bitRegData:8;

}NV_RF_MIPI_INIT_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_RFIC_INIT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RFIC ��ʼ���ṹ����NV���ƽṹ�嶨��
*****************************************************************************/
typedef struct
{
    UINT16 usRegNum;                                                            /* Single RFIC Init LUT Reg Num */
    UINT16 usRsv;
    NV_RF_MIPI_INIT_STRU                astUint[RFIC_INIT_REG_NUM];

}NV_MODEM_RF_RFIC_INIT_STRU;

/*****************************************************************************
 �ṹ��    : NV_RFIC_CONNECT_ABB_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RFIC��ABB�����ӹ�ϵ
*****************************************************************************/
typedef struct
{
    UINT16                              usRficChipId;                          /* ͬһ��MIPI����2��RFIC��RFIC chip ID��ֵ��0--chipId������1--chipId����*/
    UINT16                              usRficMipiPortSel;                      /* MIPI Portѡ�� */
    UINT16                              ausRficRxCh[MAX_RFIC_RX_CH_NUM];        /* ��ʾÿ��RFIC��RX1,Rx2,RX3�ֱ���ABBͨ�����������,ʵ����дABB��ͨ����[0,9] */
    UINT16                              ausRficABCrossFlag[MAX_RFIC_RX_CH_NUM]; /* RFIC�����ּ�����ABB��ͨ�����ּ��Ƿ��н��� */
    UINT16                              usMrxCh;                                /* RFIC MRX IQ��ABB IQ���ӹ�ϵ,��ABB MRX IQ�� */

    UINT16                              ausRficTxCh[MAX_RFIC_TX_CH_NUM];        /* ��ʾÿ��RFIC��TX1,TX2�ֱ���ABB TXͨ���������������дABB��TX IQͨ���� */
    UINT16                              ausRficTxChCrossFlag[MAX_RFIC_TX_CH_NUM];/* RFIC TX IQ������ABB�� IQ�����Ƿ��н���,��ȷ��? */
    UINT16                              usRsv;
}NV_RFIC_CONNECT_ABB_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_RF_HW_BASIC_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : RFIC��ABB�����ӹ�ϵ
*****************************************************************************/
typedef struct
{
    UINT16                              usRifcNum;
    UINT16                              usRsv;
    NV_RFIC_CONNECT_ABB_PARA_STRU       astRficConnectAbb[MAX_RFIC_NUM];
}NV_MODEM_RF_HW_BASIC_INFO_STRU;

/*****************************************************************************
 �ṹ��    : NV_RF_RX_CAL_FREQ_LIST_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ��ҪУ׼��Ƶ���б�ÿ��BAND���֧��32��Ƶ�㣬��NV����BAND��
*****************************************************************************/
typedef struct
{
    UINT16                              usValidCalFreqNum;                      /* ��ҪУ׼��Ƶ����� */
    UINT16                              usRsv;
    UINT16                              aulRxCalFreqList[RF_RX_MAX_FREQ_NUM];   /* RF_RX_FREQ_NUM =32 ,GUTL��λ100KHz,CDMA:1KHz*/

}NV_RF_RX_CAL_FREQ_LIST_STRU;


/*****************************************************************************
 �ṹ��    : NV_RX_AGC_GAIN_THRESHOLD_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC�л����ޣ�����BLOCK��NOBLOCK��ACS
*****************************************************************************/
typedef struct
{
    INT16                               asNoBlockInc[AGC_MAX_GAIN_NUM];         /* NOBLOCK�������ޣ�AGC_MAX_GAIN_NUM = 8����λ��1dB */
    INT16                               asNoBlockDec[AGC_MAX_GAIN_NUM];         /* NOBLOCK�������ޣ�AGC_MAX_GAIN_NUM = 8����λ��1dB */
    INT16                               asBlockInc[AGC_MAX_GAIN_NUM];           /* BLOCK�������ޣ�BLOCK��Ϊ8����AGC_MAX_GAIN_NUM = 8����λ��1dB */
    INT16                               asBlockDec[AGC_MAX_GAIN_NUM];           /* BLOCK�������ޣ�BLOCK��Ϊ8����AGC_MAX_GAIN_NUM = 8����λ��1dB */
    INT16                               asAcsInc[AGC_MAX_GAIN_NUM];             /* ACS�������ޣ�GUC���ã�AGC_MAX_GAIN_NUM = 8����λ��1dB */
    INT16                               asAcsDec[AGC_MAX_GAIN_NUM];             /* ACS�������ޣ�GUC���ã�AGC_MAX_GAIN_NUM = 8����λ��1dB */
}NV_RX_AGC_GAIN_THRESHOLD_STRU;

/*****************************************************************************
 �ṹ��    : NV_ALG_RX_AGC_SWITCH_THRESHOLD_TABLE_BANK_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC�л�������Դ�أ����֧��10�ű�����10�ֲ�ͬ��AGC�л�����
*****************************************************************************/
typedef struct
{
    NV_RX_AGC_GAIN_THRESHOLD_STRU       astAgcSwitchTable[AGC_MAX_TABLE_NUM];   /*AGC_MAX_TABLE = 10*/

}NV_ALG_RX_AGC_SWITCH_THRESHOLD_TABLE_BANK_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_GAIN_DEFAULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC��Ĭ��GAINֵ������BLOCK��NOBLOCK��ACS
*****************************************************************************/
typedef struct
{
    UINT16                              ausGainNBlock[AGC_MAX_GAIN_NUM];        /* NOBLOCK��Ĭ��AGC GAINֵ��AGC_MAX_GAIN_NUM = 8����λ:1/8 dB */
    UINT16                              ausGainBlock[AGC_MAX_GAIN_NUM];         /* BLOCK��Ĭ��AGC GAINֵ��֧��8��AGC��AGC_MAX_GAIN_NUM = 8����λ:1/8 dB */
    UINT16                              ausGainAcs[AGC_MAX_GAIN_NUM];           /* ACS��Ĭ��AGC GAINֵ��GUC���ã�AGC_MAX_GAIN_NUM = 8����λ:1/8 dB */

}NV_RX_AGC_GAIN_DEFAULT_STRU;

/*****************************************************************************
 �ṹ��    : NV_RF_RX_AGC_GAIN_TABLE_BANK_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGCĬ��GAINֵ����Դ�أ����֧��10�ű�����10�ֲ�ͬ��AGC DEFAULT GAIN
*****************************************************************************/
typedef struct
{
    NV_RX_AGC_GAIN_DEFAULT_STRU         astAgcGainDefaultTable[AGC_MAX_TABLE_NUM];  /*AGC_MAX_TABLE = 10*/

}NV_RF_RX_AGC_GAIN_TABLE_BANK_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_RFIC_TABLE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC��RFIC�����֣�����BLOCK��NOBLOCK��ACS
*****************************************************************************/
typedef struct
{
    UINT16                              ausRfTableNoBlok[AGC_MAX_GAIN_NUM];     /* NOBLOCK��AGC��RFIC�����֣�AGC_MAX_GAIN_NUM = 8 */
    UINT16                              ausRfTableBlock[AGC_MAX_GAIN_NUM];      /* BLOCK��AGC��RFIC�����֣�֧��8����AGC_MAX_GAIN_NUM = 8 */
    UINT16                              ausRfTableAcs[AGC_MAX_GAIN_NUM];        /* ACS��AGC��RFIC�����֣�GUC���ã�AGC_MAX_GAIN_NUM = 8 */

}NV_RX_AGC_RFIC_TABLE_STRU;

/*****************************************************************************
 �ṹ��    : NV_RF_RX_AGC_RFIC_TABLE_BANK_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC��RFIC��������Դ�أ����֧��10�ű�����10�ֲ�ͬ��RFIC������
*****************************************************************************/
typedef struct
{
    NV_RX_AGC_RFIC_TABLE_STRU           astAgcRficTable[AGC_MAX_TABLE_NUM];     /*AGC_MAX_TABLE = 10*/

}NV_RF_RX_AGC_RFIC_TABLE_BANK_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_TABLE_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ĳһ��PATH��ÿ��������ѡ���AGC TABLE INDEX������INDEXȥ������Ӧ��
 AGC���л����ޡ�AGC DEFAULT GAIN��AGC��RFIC������
*****************************************************************************/
typedef struct
{
    UINT32                              bitMainAntRxAgcTableIdx         :4;     /* �������߶�Ӧ��AGC TABLE INDEX */
    UINT32                              bitDivAntRxAgcTableIdx          :4;     /* �ּ����߶�Ӧ��AGC TABLE INDEX */
    UINT32                              bitAuxMainAntRxAgcTableIdx      :4;     /* GUC���ã������������߶�Ӧ��AGC TABLE INDEX */
    UINT32                              bitAuxDivAntRxAgcTableIdx       :4;     /* GUC���ã������ּ����߶�Ӧ��AGC TABLE INDEX ������4bit�������㣬Ϊ��4�ֽڶ��룬������8bit*/
    UINT32                              bitRsv0                           :4;
    UINT32                              bitRsv1                           :4;
    UINT32                              bitRsv2                           :4;
    UINT32                              bitRsv3                           :4;
}NV_RX_AGC_TABLE_INFO_STRU;

/*****************************************************************************
 �ṹ��    : NV_RF_RX_AGC_TABLE_USED_INFO_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC��TABLE INDEX�����֧��6��PATH��GUCֻ��Ҫʹ��һ��PATH������BAND
*****************************************************************************/
typedef struct
{
    NV_RX_AGC_TABLE_INFO_STRU           astAgcTableInfoDlPath[LPHY_DL_PATH_NUM];

}NV_RF_RX_AGC_TABLE_USED_INFO_STRU;


/*****************************************************************************
 �ṹ��    : NV_RX_PATH_ILOSS_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ĳһ��PATH��ÿ��������ѡ��Ĳ���ֵ
*****************************************************************************/
typedef struct
{
    INT16                               usMainAntRffeIloss;                     /* �������߶�Ӧ�Ĳ���ֵ����λ:1db */
    INT16                               ustDivAntRffeIloss;                     /* �ּ����߶�Ӧ�Ĳ���ֵ����λ:1db */
    INT16                               usAuxMainAntRffeIloss;                  /* GUC���ã������������߶�Ӧ�Ĳ���ֵ����λ:1db */
    INT16                               usAuxDivAntRffeIloss;                  /* GUC���ã������ּ����߶�Ӧ�Ĳ���ֵ����λ:1db��������4bit�������㣬Ϊ��4�ֽڶ��룬������8bit*/

}NV_RX_PATH_ILOSS_STRU;

/*****************************************************************************
 �ṹ��    : NV_RF_RX_RFFE_ILOSS_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ǰ�˵Ĳ���ֵ�����֧��6��PATH��GUCֻ��һ��PATH������BAND
*****************************************************************************/
typedef struct
{
    NV_RX_PATH_ILOSS_STRU               astRffeIlossDlPath[LPHY_DL_PATH_NUM];

}NV_RF_RX_RFFE_ILOSS_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_GAIN_LEVEL_CAL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC��У׼�������������ֵ�����ǲ�����Ƶ��ֵ
*****************************************************************************/
typedef struct
{
    UINT16                              ausGainLevelNoBlock[AGC_MAX_GAIN_NUM];  /* NOBLOCK��AGCУ׼ֵ����λ:1/8dB��AGC_MAX_GAIN_NUM = 8 */
    UINT16                              ausGainLevelBlock[AGC_MAX_GAIN_NUM];    /* BLOCK��AGCУ׼ֵ����λ:1/8dB��AGC_MAX_GAIN_NUM = 8 */
    UINT16                              ausGainLevelAcs[AGC_MAX_GAIN_NUM];      /* GUC���ã�ACS��AGCУ׼ֵ����λ:1/8dB��AGC_MAX_GAIN_NUM = 8 */

}NV_RX_AGC_GAIN_LEVEL_CAL_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_FREQ_COMP_CAL_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGC��Ƶ��У׼���
*****************************************************************************/
typedef struct
{
    INT16                               ausFreqComp[RF_RX_MAX_FREQ_NUM];        /* RF_RX_MAX_FREQ_NUM = 32 */

}NV_RX_AGC_FREQ_COMP_CAL_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_CAL_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGCĳһ�����߶�Ӧ���ܵ�У׼���
*****************************************************************************/
typedef struct
{
    NV_RX_AGC_GAIN_LEVEL_CAL_STRU       stGainLevelCalResult;                   /* ������AGC_GAIN_DEFAULT�Ͳ��𣬵��ǲ�����Ƶ��ֵ��Ƶ����Ҫ������ֵ����*/
    NV_RX_AGC_FREQ_COMP_CAL_STRU        astFreqCalResult[EXT_LNA_GIAN_CAL_NUM]; /* AGC��Ƶ��У׼ֵ */
    INT16                               sRffeIloss;                              /* У׼ʱʹ�õĲ���ֵ */
    INT16                               sRsv;

}NV_RX_AGC_CAL_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_AGC_CAL_RESULT_TABLE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : AGCĳһ��PATH��Ӧ���ܵ�У׼�����GUCֻ��һ��PATH������BAND
*****************************************************************************/
typedef struct
{
    NV_RX_AGC_CAL_RESULT_STRU           astMainAntAgcCalResult;                 /* �������߶�Ӧ��AGCУ׼��� */
    NV_RX_AGC_CAL_RESULT_STRU           astDivAntAgcCalResult;                  /* �ּ����߶�Ӧ��AGCУ׼��� */
    NV_RX_AGC_CAL_RESULT_STRU           astAuxMainAntAgcCalResult;              /* GUC���ã������������߶�Ӧ��AGCУ׼��� */
    NV_RX_AGC_CAL_RESULT_STRU           astAuxDivAntAgcCalResult;               /* GUC���ã������ּ����߶�Ӧ��AGCУ׼��� */

}NV_RX_AGC_CAL_RESULT_TABLE_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_DCOC_COMP_VAlUE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : DCOC��У׼���ֺ�BBP�ϱ��Ĳ���ֱ��ֵ
*****************************************************************************/
typedef struct
{
    UINT16                              usDciCode;                              /* У׼��I·��DCOC���� */
    UINT16                              usDcqCode;                              /* У׼��Q·��DCOC���� */
    INT16                               sRemainDigitalDci;                      /* У׼ʱBBP�ϱ���I·�Ĳ���ֱ��ֵ */
    INT16                               sRemainDigitalDcq;                      /* У׼ʱBBP�ϱ���Q·�Ĳ���ֱ��ֵ */

}NV_RX_DCOC_COMP_VAlUE_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_DCOC_CAL_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ĳһ��PATH��ÿ�����ߵ�DCOC��У׼���������VGA��λУ׼�ģ�������16��
*****************************************************************************/
typedef struct
{
    NV_RX_DCOC_COMP_VAlUE_STRU          astDcocComp[MAX_VGA_GAIN_NUM];

}NV_RX_DCOC_CAL_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_DCOC_CAL_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : ĳһ��PATH��DCOC��У׼���
*****************************************************************************/
typedef struct
{
    NV_RX_DCOC_CAL_RESULT_STRU          astMainAntCalResult;                    /* ������DCOCУ׼��� */
    NV_RX_DCOC_CAL_RESULT_STRU          astDivAntCalResult;                     /* �ּ���DCOCУ׼��� */
    NV_RX_DCOC_CAL_RESULT_STRU          astAuxMainAntCalResult;                 /* GUC���ã�����������DCOCУ׼��� */
    NV_RX_DCOC_CAL_RESULT_STRU          astAuxDivAntCalResult;                  /* GUC���ã������ּ���DCOCУ׼��� */

}NV_RX_PATH_DCOC_CAL_RESULT_STRU;


/*****************************************************************************
 �ṹ��    : NV_LTE_IP2_USE_APC_CODE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    UINT16                              usTxDefaultPowHIdx;                     /*�ɲ�Ʒ����дУ׼Ĭ�Ϲ��ʵ�Index,����㵽Ĭ�ϵ�RFIC Table���в��Ӧʹ�õ�
                                                                                APC Code��default power��APC Codeһһ��Ӧ,��Ҫ����APC�����ʼ�����RFIC��APC code index��*/
    UINT16                              ausFreq[CAL_IP2_FREQ_NUM];

}NV_LTE_IP2_USE_APC_CODE_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_IP2_CAl_PATH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    UINT08                              ucCalDlPathIdx;                         /* Ip2У׼���е�pathIdx */
    UINT08                              ucUseUlPathIdx;                         /* У׼ʹ�õ����е�pathIdx */
    UINT08                              bitCalMainAntValidFlg       :1;
    UINT08                              bitCalDivAntValidFlg        :1;
    UINT08                              bitCalAuxMainAntValidFlg    :1;
    UINT08                              bitCalAuxDivAntValidFlg     :1;
    UINT08                              bitRsv0                     :4;
    UINT08                              ucRsv;
    NV_LTE_IP2_USE_APC_CODE_STRU        astRxIp2Para;

}NV_LTE_IP2_CAl_PATH_PARA_STRU;
/*****************************************************************************
 �ṹ��    : NV_LTE_CAL_IP2_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    UINT08                              ucIp2CalDlPathNum;                      /* IP2У׼Path�� */
    UINT08                              ucRsv0;
    UINT08                              ucRsv1;
    UINT08                              ucRsv2;
    NV_LTE_IP2_CAl_PATH_PARA_STRU       astRxIp2PathPara[LPHY_DL_PATH_NUM];

}NV_LTE_CAL_IP2_PARA_STRU;                                                    /* ����NV��С�����鰴��BandԤ�� */

/*****************************************************************************
 �ṹ��    : NV_RX_IP2_IQREG_CODE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    INT16                               sIRegCode;                              /*��Ҫȷ����UMTS��INT16��ԭ��L��V7r5���õ���UINT16*/
    INT16                               sQRegCode;

}NV_RX_IP2_IQREG_CODE_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_IP2_CAL_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    NV_RX_IP2_IQREG_CODE_STRU           stMainAntDivOn;
    NV_RX_IP2_IQREG_CODE_STRU           stMainAntDivOff;                        /*RFIC ȷ�ϲ���Ҫ����У׼�ּ���Ip2,ɾ����ǰ�汾�й���У׼�ּ��Ĳ���*/

}NV_RX_IP2_CAL_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : NV_RX_PATH_IP2_CAL_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    NV_RX_IP2_CAL_RESULT_STRU           astRxIp2CalResultFreq[MAX_IP2_CAL_FREQ_NUM];
}NV_RX_PATH_IP2_CAL_RESULT_STRU;

typedef struct
{
    NV_RX_PATH_IP2_CAL_RESULT_STRU      astIp2CalResultPath[LPHY_DL_PATH_NUM];
}NV_LTE_RX_IP2_CAL_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_TXIQ_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    UINT16                              usTxDefaultPowHIdx;                     /*�ɲ�Ʒ����дУ׼Ĭ�Ϲ��ʵ�Index,����㵽Ĭ�ϵ�RFIC Table���в��Ӧʹ�õ�
                                                                                APC Code��default power��APC Codeһһ��Ӧ,��Ҫ����APC�����ʼ�����RFIC
                                                                                ��APC code index��*/
    UINT16                              usRficMrxGainIdx;                       /*��дMrxʵ�ʶ�Ӧ�����浵λ��Ĭ��ֵ��0~F*/

}NV_LTE_TXIQ_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_ID_LTE_TX_CAL_TXIQ_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    NV_LTE_TXIQ_PARA_STRU               astTxiqParaPath[LPHY_UL_PATH_NUM ];

}NV_ID_LTE_TX_CAL_TXIQ_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_TX_CAL_DEFAULT_POWER_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    INT32                               bitFreqComDefaultPowerHIdx      :6;     /* Ƶ����У׼Ŀ�깦��Ĭ�ϴӸ߹�����ѡ,0~40 */
    INT32                               bitPowerLowDiff                 :6;     /* ÿ��path�������׼Ŀ�깦�ʹ̶��-64~64��1/8 dB */
    INT32                               bitPowerMidDiff                 :6;
    INT32                               bitPowerHighDiff                :6;
    INT32                               bitRsv                          :8;

}NV_TX_CAL_DEFAULT_POWER_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_TX_CAL_DEFAULT_POWER_TABLE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{

    NV_TX_CAL_DEFAULT_POWER_STRU        astTxDefaultPowPath[LPHY_UL_PATH_NUM ];
    INT16                               asRfDefaultPowerLow[RF_TX_GAIN_6363_NUM][BBGAIN_NUM_PER_RFGAIN];/*����У׼���߿ڻ�׼Ŀ�깦�ʣ�RF_TX_GAIN_6363_NUM = 20,RF_BBGAIN_NUM_PER_RFGAIN = 2 */
    INT16                               asRfDefaultPowerMid[RF_TX_GAIN_6363_NUM][BBGAIN_NUM_PER_RFGAIN];
    INT16                               asRfDefaultPowerHigh[RF_TX_GAIN_6363_NUM][BBGAIN_NUM_PER_RFGAIN];

}NV_LTE_TX_CAL_DEFAULT_POWER_TABLE_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_APC_TABLE_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    UINT16                              ausApcTableStartPointEachPalevel[RF_PA_GAIN_NUM];
    UINT16                              ausGainNumsNeedCalEachPaLevel[RF_PA_GAIN_NUM];                  /* RF_PA_GAIN_NUM = 3 */
    INT16                               sDbbValue;                                              /* У׼ʱDBB ˥��ֵ����λ: 1/16 */
    INT16                               sRsv;
}NV_LTE_APC_TABLE_PARA_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_TX_CAL_APC_TABLE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{

    NV_LTE_APC_TABLE_PARA_STRU          astTxApcParaPath[LPHY_UL_PATH_NUM ];
    UINT32                              aulLteApcTable[RF_TX_GAIN_6363_NUM][BBGAIN_NUM_PER_RFGAIN]; /* RFIC У׼APC ��׼��ÿ��Bandһ����Path���� */
}NV_LTE_TX_CAL_APC_TABLE_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_TX_APC_GAIN_STATUS_POW_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
        INT16 sMaxPow;
        INT16 sMinPow;
}NV_LTE_TX_APC_GAIN_STATUS_POW_STRU;

/*****************************************************************************
 �ṹ��    : NV_LTE_TX_CAL_RESULT_TABLE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{

   NV_LTE_TX_APC_GAIN_STATUS_POW_STRU   astTxPaPower[RF_PA_GAIN_NUM][RF_TX_GAIN_6363_NUM];

}NV_LTE_TX_CAL_APC_RESULT_STRU;
/*****************************************************************************
 �ṹ��    : NV_LTE_TX_CAL_GAIN_COMP_RESULT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{

    NV_LTE_TX_CAL_APC_RESULT_STRU     astTxCalResultPath[LPHY_UL_PATH_NUM ];

}NV_LTE_TX_CAL_COMP_RESULT_STRU;

/*****************************************************************************
 �ṹ��    : NV_MODEM_TEMP_DEFINE_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  :
*****************************************************************************/
typedef struct
{
    UINT16                            usTempNum;
    UINT16                            usRsv;
    INT16                             asTempList[MAX_TEMP_DEFINE_NUM];
}NV_MODEM_TEMP_DEFINE_STRU;

/*****************************************************************************
  7 UNION����
*****************************************************************************/








#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of nv_common_interface */
