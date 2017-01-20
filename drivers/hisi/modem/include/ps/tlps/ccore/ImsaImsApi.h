/******************************************************************************


        @(#)Copyright(C)2013,Hisilicon Co. LTD.

 ******************************************************************************
    File name   : ImsaImsApi.h
    Description : IMSA��IMSЭ��ջ�����ӿ�ͷ�ļ�
    History     :
      1.sunbing 00049683    2013-07-15  Draft Enact
      2.sunbing 00049683    2013-10-10  ��������API����

******************************************************************************/

#ifndef __IMSAIMSAPI_H__
#define __IMSAIMSAPI_H__

/*****************************************************************************
  1 Include Headfile
*****************************************************************************/


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


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/
    /* "a1.a2.a3.a4 " */
#define IMSA_IMS_IPV4_ADDR_LEN              (4)

    /* "a1...a16" */
#define IMSA_IMS_IPV6_ADDR_LEN              (16)



/*****************************************************************************
  4 Enum
*****************************************************************************/
enum IMSA_VOICE_CODEC_ENUM
{
    IMSA_VOICE_CODEC_AMR_NB = 0,
    IMSA_VOICE_CODEC_EFR,
    IMSA_VOICE_CODEC_FR,
    IMSA_VOICE_CODEC_HR,
    IMSA_VOICE_CODEC_AMR_NB2,
    IMSA_VOICE_CODEC_AMR_WB,
    IMSA_VOICE_CODEC_G711,
    IMSA_VOICE_CODEC_BUTT
};
typedef unsigned short IMSA_VOICE_CODEC_ENUM_UINT16;

enum IMSA_CODEC_AMR_TYPE_TX_ENUM
{
    IMSA_CODEC_AMR_TYPE_TX_SPEECH_GOOD   = 0,
    IMSA_CODEC_AMR_TYPE_TX_SID_FIRST,
    IMSA_CODEC_AMR_TYPE_TX_SID_UPDATE,
    IMSA_CODEC_AMR_TYPE_TX_NO_DATA,
    IMSA_CODEC_AMR_TYPE_TX_SPEECH_DEGRADED,
    IMSA_CODEC_AMR_TYPE_TX_SPEECH_BAD,
    IMSA_CODEC_AMR_TYPE_TX_SID_BAD,
    IMSA_CODEC_AMR_TYPE_TX_ONSET,
    IMSA_CODEC_AMR_TYPE_TX_BUTT
};
typedef unsigned short IMSA_CODEC_AMR_TYPE_TX_ENUM_UINT16;

/* TIMER */
enum IMSA_TIMER_PRECISION_ENUM
{
    IMSA_TIMER_PRECISION_0   = 0,
    IMSA_TIMER_PRECISION_5   = 5,
    IMSA_TIMER_PRECISION_10   = 10,
    IMSA_TIMER_PRECISION_20   = 20,
    IMSA_TIMER_PRECISION_30   = 30,
    IMSA_TIMER_PRECISION_40   = 40,
    IMSA_TIMER_PRECISION_50   = 50,
    IMSA_TIMER_PRECISION_60   = 60,
    IMSA_TIMER_PRECISION_70   = 70,
    IMSA_TIMER_PRECISION_80   = 80,
    IMSA_TIMER_PRECISION_90   = 90,
    IMSA_TIMER_PRECISION_100   = 100,
    IMSA_TIMER_NO_PRECISION,
    IMSA_TIMER_PRECISION_BUTT
};
typedef unsigned int IMSA_TIMER_PRECISION_ENUM_UINT32;


typedef enum
{
    IMSA_IMS_TIMER_NAME_XXX = 500,
    IMSA_IMS_TIMER_NAME_BUTT
}IMSA_IMS_TIMER_NAME_ENUM;


typedef enum
{
    IMSA_DTMF_TYPE_0 = 0,               /**< @brief Event of "0" */
    IMSA_DTMF_TYPE_1 = 1,               /**< @brief Event of "1" */
    IMSA_DTMF_TYPE_2 = 2,               /**< @brief Event of "2" */
    IMSA_DTMF_TYPE_3 = 3,               /**< @brief Event of "3" */
    IMSA_DTMF_TYPE_4 = 4,               /**< @brief Event of "4" */
    IMSA_DTMF_TYPE_5 = 5,               /**< @brief Event of "5" */
    IMSA_DTMF_TYPE_6 = 6,               /**< @brief Event of "6" */
    IMSA_DTMF_TYPE_7 = 7,               /**< @brief Event of "7" */
    IMSA_DTMF_TYPE_8 = 8,               /**< @brief Event of "8" */
    IMSA_DTMF_TYPE_9 = 9,               /**< @brief Event of "9" */
    IMSA_DTMF_TYPE_STAR  = 10,          /**< @brief Event of "10" */
    IMSA_DTMF_TYPE_POUND = 11,          /**< @brief Event of "11" */
    IMSA_DTMF_TYPE_A     = 12,          /**< @brief Event of "12" */
    IMSA_DTMF_TYPE_B     = 13,          /**< @brief Event of "13" */
    IMSA_DTMF_TYPE_C     = 14,          /**< @brief Event of "14" */
    IMSA_DTMF_TYPE_D     = 15,          /**< @brief Event of "15" */
    IMSA_DTMF_TYPE_BUTT  = 16           /**< @brief Event of "16" */
} IMSA_DTMF_TYPE_ENUM;

typedef unsigned short IMSA_DTMF_TYPE_ENUM_UINT16;

typedef enum
{
    IMSA_CONTROL_MSG_PARAM_TYPE_DISABLE     = 0,
    IMSA_CONTROL_MSG_PARAM_TYPE_ENABLE      = 1,
    IMSA_CONTROL_MSG_PARAM_TYPE_BUTT
} IMSA_CONTROL_MSG_PARAM_TYPE_ENUM;

typedef unsigned short IMSA_CTRL_TYPE_PARAM_ENUM_UINT16;
 #if 0
typedef enum
{
    IMS_IMSA_CONTROL_MSG_TYPE_SETSEND   = 0,
    IMS_IMSA_CONTROL_MSG_TYPE_SETRECV   = 1,
    IMS_IMSA_CONTROL_MSG_TYPE_SETPLAY   = 2,
    IMS_IMSA_CONTROL_MSG_TYPE_SETRTCP   = 3,
    IMS_IMSA_CONTROL_MSG_TYPE_BUTT
} IMSA_CONTROL_MSG_TYPE_ENUM;

typedef unsigned short IMSA_CTRL_TYPE_ENUM_UINT16;
#endif
typedef enum
{
    IMSA_IMS_NTF_MSG_PARAM_TYPE_OK  = 0,
    IMSA_IMS_NTF_MSG_PARAM_TYPE_ERR = 1,
    IMSA_IMS_NTF_MSG_PARAM_TYPE_BUTT
} IMSA_NTF_MSG_PARAM_TYPE_ENUM;

typedef unsigned short IMSA_NTY_TYPE_PARAM_ENUM_UINT16;

typedef enum
{
    IMSA_NTY_MSG_TYPE_RTP_STATES = 0,
    IMSA_NTY_MSG_TYPE_BUTT
} IMSA_NTY_MSG_TYPE_ENUM;

typedef unsigned short IMSA_NTY_TYPE_ENUM_UINT16;




typedef void (*TIMER_FUNC)(unsigned int ulParam, unsigned int ulTimerName);

typedef struct
{
    unsigned int                     ulLen;          /*��ʱ��ʱ������λmillisecond*/
    unsigned int                     ulTimerName;    /*��ʱ��������ʶ��ʱ��������IMSA_IMS_TIMER_NAME_ENUMö��ֵ*/
    unsigned int                     ulParam;        /*��ʱ�����Ӳ���*/
    unsigned char                    ucMode;         /*��ʱ������ģʽ��0���ζ�ʱ��,1ѭ����ʱ������ʱ�Զ�����*/
    unsigned char                    ucRever[3];
    IMSA_TIMER_PRECISION_ENUM_UINT32 enPrecision;    /*��ʱ�����ȣ���ʾ�����̵Ķ�ʱ���ٷֱ�*/
    TIMER_FUNC                       TimeOutRoutine; /*�ص���������ʱ����ʱ����ã��ص������Ĳ���ΪulTimerName��ulTimerName*/
}IMSA_TIMER_PARA_STRU;


typedef struct
{
    IMSA_VOICE_CODEC_ENUM_UINT16  enCodecType;   /*��ǰ����֡��codec����,0��ʾAMR,5��ʾWB AMR,6��ʾG711*/
    unsigned short                usDtxEnable;   /*��֡�ı���DTX�Ƿ����ã�0��ʾ��������1��ʾ����*/
    unsigned short                usRateMode;    /*��֡�ı���������ʣ�ֵΪ0��8��AMR��AMR_WBʱ��Ч*/
    unsigned short                usErrorFlag;   /*��֡�Ƿ���lost packet,0��ʾ��1��ʾ��*/
    unsigned short                usFrameType;   /* ���б�֡��FrameType */
    unsigned short                usQualityIdx;  /* Quality indification */
    unsigned short                usSN;          /* �����к� */
    unsigned short                usReserve;
    unsigned long                 ulTS;          /* ��ʱ��� */
    unsigned long                 ulSsrc;        /* synchronization source */
}IMSA_RX_VOICE_PARA_STRU;


typedef struct
{
    IMSA_CODEC_AMR_TYPE_TX_ENUM_UINT16  usStatus;
    unsigned short                      usFrameType;  /* ���б�֡��FrameType */
}IMSA_TX_VOICE_PARA_STRU;


typedef struct
{
   unsigned long                         ulChannelId;
   unsigned short                        usPortType; /* Port type: 0 RTP; 1 RTCP */
   unsigned short                        usLength;    /* ָ�����ݳ��ȣ���λ��16Bit */
 } IMSA_IMS_RTP_PARA_STRU;

typedef struct
{
    IMSA_VOICE_CODEC_ENUM_UINT16 ulCodecType;
    unsigned long ulRecivePayload;          /**< @brief codec recive payload type */
    unsigned long ulSendPayload;            /**< @brief codec send payload type */
    unsigned long ulOctetAlign;             /**< @brief Octet Align */
    unsigned long ulBitrate;                /**< @brief bitrate */
    unsigned long ulSplRate;                /**< @brief sample rate (Hz) */
    unsigned long ulTsIncrease;             /**< @brief Ts increase value ������ */
}IMSA_ENGINE_PAYLOAD_PARA_STRU;

typedef struct
{
    unsigned long ulDTMFRecivePayload;      /**< @brief dtmf recive payload type */
    unsigned long ulDTMFSendPayload;        /**< @brief dtmf send payload type */
}IMSA_ENGINE_DTMF_PAYLOAD_PARA_STRU;

typedef struct
{
    unsigned short  usLocalRtpPort;        /* RTP Port��û�з�����0 */
    unsigned short  usLocalRtcpPort;       /* RTCP Port��û�з�����0 */
    unsigned short  usRemoteRtpPort;       /* RTP Port��û�з�����0 */
    unsigned short  usRemoteRtcpPort;      /* RTCP Port��û�з�����0 */
    unsigned char   ucIpType;              /* IPV4: 0x01; IPV6: 0x02 */
    unsigned char   aucReserved[3];
    unsigned char   aucIpV4Addr[IMSA_IMS_IPV4_ADDR_LEN];
    unsigned char   aucIpV6Addr[IMSA_IMS_IPV6_ADDR_LEN];
}IMSA_ENGINE_PORT_INFO_PARA_STRU;



/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/
/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��绰����HIFI�������������ʽ�ı�ʱ���ã�
 *        �ڸ�API�У�IMSA��֪ͨHIFI��������룬��������codec����
 * @param[in]   enCodeType     ��������codec����
 * @retval 0�ɹ���1ʧ��
 * 2015-09-11 z00353461 for VoWIFI add ChannelID
 */
extern unsigned int IMSA_StartVoiceDsp
(
    IMSA_VOICE_CODEC_ENUM_UINT16    enCodecType,
    unsigned long                   ulPacketTime,
    unsigned long                   ulBitrateSet,
    unsigned long                   ulVoiceEncrypt,
    unsigned char                   ucModeChangeNeigh
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ�ڹҶ����е绰�����
 *        �ڸ�API�У�IMSA��֪ͨHIFI,ֹͣ���������
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_StopVoiceDsp(void);


/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ�յ�����RTP���ݺ���ã�
 *        ���������ݷ��͸�HIFI��HIFI�յ����RTP���ݽ��н��봦��
 * @param[in]   pstRtpPara    ������Ϣ��ŵ�ַ
 * @param[in]   pusRevRtpData    RTP���ݴ�ŵ�ַ���ռ��СΪ160byte
 * @retval 0�ɹ���1ʧ��
 */

extern unsigned int IMSA_Send2HifiRxRtpData
(
   const IMSA_IMS_RTP_PARA_STRU *pstRtpPara,
   const unsigned char         *pucRevRtpData
);

/**
 * \brief IMSЭ��ջ�ṩ����˼��API��
 *        HIFI�������RTP����󣬷���������IMSA��IMSA�յ�����ø�API�������ݷ���IMSЭ��ջ
 * @param[in]   pstRtpPara       ������Ϣ��ŵ�ַ
 * @param[in]   pusRevRtpData    RTP���ݴ�ŵ�ַ���ռ��СΪ160byte
 * @retval 0�ɹ���1ʧ��
 * @retval ��
 */

extern unsigned int IMSA_Send2ImsTxRtpData
(
   const IMSA_IMS_RTP_PARA_STRU *pstRtpPara,
   const unsigned char         *pucRevRtpData
);

/* ��Media Controlģ����Ƶĺ��� */


/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��Ҫ��Media control Engineʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]    ulType          ָ��IP���� 0: IPV4, 1: IPV6
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_ImsEngineOpen
(
  unsigned long ulChannelId,
  unsigned long ulType
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��Ҫ�ر�Media control Engineʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineClose
(
  unsigned long ulChannelId
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��Ҫ����Media control Engine����ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   pstEngineParam     ���в���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSetPayload
(
    unsigned long                  ulChannelId,
    IMSA_ENGINE_PAYLOAD_PARA_STRU *pstEngineParam
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��Ҫ����Media control Engine DTMF����ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   pstEngineParam     ���в���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSetDtmfPayload
(
    unsigned long                       ulChannelId,
    IMSA_ENGINE_DTMF_PAYLOAD_PARA_STRU *pstEngineParam
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��Ҫ����WIFIģ��˿���Ϣʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   pstEngineParam     ���в���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSetPortInfo
(
    unsigned long                    ulChannelId,
    IMSA_ENGINE_PORT_INFO_PARA_STRU *pstEngineParam
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ����Media control Engine���Ϳ���ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam ���Ʋ���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSendCtrlRecv
(
   unsigned long                    ulChannelId,
   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ����Media control Engine���Ϳ���ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam ���Ʋ���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSendCtrlSend
(
   unsigned long                    ulChannelId,
   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ����Media control Engine���Ϳ���ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam ���Ʋ���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSendCtrlPlay
(
   unsigned long                    ulChannelId,
   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam
);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ����Media control Engine���Ϳ���ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam ���Ʋ���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineSendCtrlRtcp
(
   unsigned long                    ulChannelId,
   IMSA_CTRL_TYPE_PARAM_ENUM_UINT16 enCtrlParam
);


/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ֪ͨMedia control Engine����״̬ʱ���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   iSend     0: stop to send data, 1: start to send data
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int  IMSA_ImsEngineRecvStateMsg
(
   unsigned long                    ulChannelId,
   IMSA_NTY_TYPE_ENUM_UINT16        enCtrlType,
   IMSA_NTY_TYPE_PARAM_ENUM_UINT16  enCtrlParam
);



/**
 * \brief ��˼�ṩ��API������IMSЭ��ջͨ��Media control Engine����DTMF���е���
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   enDtmfType      ��ʶDTMF����
 * @param[in]   dwLen           ����
 * @retval 0�ɹ���1ʧ��
 */

extern unsigned int IMSA_ImsEngineSendDtmf
(
    unsigned long              ulChannelId,
    IMSA_DTMF_TYPE_ENUM_UINT16 enDtmfType,
    unsigned long              dwLen
);


/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ�յ��������ݺ���ã�
 *        ���������ݷ��͸�HIFI��HIFI�յ����������
 * @param[in]   pstVoicePara   ������Ϣ��ŵ�ַ�������ݿռ��ɵ������ͷ�
 * @param[in]   pusData        �������ݴ�ŵ�ַ���ռ��СΪ160byte�������ݿռ��ɵ������ͷ�
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_Send2HifiRxVoiceData(const IMSA_RX_VOICE_PARA_STRU *pstVoicePara,
                                                        const unsigned short *pusData);
#if 0
/**
 * \brief IMSЭ��ջ�ṩ����˼��API��
 *        HIFI���������������󣬷���������IMSA��IMSA�յ�����ø�API�������ݷ���IMSЭ��ջ
 * @param[in]   pstVoicePara   ������Ϣ��ŵ�ַ�������ݿռ��ɵ�����(��˼)�ͷ�
 * @param[in]   pusData        �������ݴ�ŵ�ַ���ռ��СΪ160byte�������ݿռ��ɵ�����(��˼)�ͷ�
 * @retval ��
 */
extern void IMSA_Send2ImsTxVoiceData(const IMSA_TX_VOICE_PARA_STRU *pstVoicePara,
                                              const unsigned short *pusData);

#endif
/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��IMSA������Ϣʱ����
 *
 * @param[in]   pstOutputEvent    �¼���ŵ�ַ�������ݿռ��ɵ������ͷţ�����ΪIMSA_IMS_OUTPUT_EVENT_STRU
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_Send2ImsaMsg(void *pstOutputEvent);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��HIFI��������/ֹͣRTP���ָʾ��Ϣʱ����
 *
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   enChrlParam     1 ����/0 ֹͣ RTP���
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_ImsEngineSendRTPChkEnable
(
    unsigned long                       ulChannelId,
    unsigned int                        enChrlParam
);

/**
 * \brief ��˼�ṩ����API������IMSЭ��ջ������ʱ��
 *
 * @param[in]    pstTimerPara�� ��ʱ��������ŵ�ַ�������ݿռ��ɵ������ͷ�
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_ImsStartTimer(const IMSA_TIMER_PARA_STRU  *pstTimerPara);


/**
 * \brief ��˼�ṩ��API������IMSЭ��ջֹͣ��ʱ��
 *
 * @param[in]    ulTimerName�� ��ʱ������
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_ImsStopTimer(unsigned int  ulTimerName);

/**
 * \brief IMSЭ��ջ�ṩ����˼��API������IMSЭ��ջ�ĳ�ʼ��
 * @retval 0ʧ�ܣ�1�ɹ�
 */
extern unsigned int IMSA_ImsInit(void);


/**
 * \brief IMSЭ��ջ�ṩ����˼��API�����ڸ�IMSЭ��ջ�����¼�
 *
 * @param[in]    pstInputEvent�� INPUT�¼�ָ�� ����ΪIMSA_IMS_INPUT_EVENT_STRU
 * @retval 0ʧ�ܣ�1�ɹ�
 */
extern unsigned int IMSA_WriteImsEvent(void *pstInputEvent);

/**
 * \brief IMSЭ��ջ�ṩ����˼��API������IMSЭ��ջ�ṩSrvcc������ת��CS��ĺ����б�
 *
 * @param[in]    pstSrvccCallList�� ����ΪIMSA_IMS_SRVCC_CALL_LIST_STRU���ڴ��ɺ�˼����
 * @retval 0ʧ�ܣ�1�ɹ�
 */
extern unsigned int IMSA_ImsWriteSrvccCallList(void *pstSrvccCallList);

/**
 * \brief ��˼�ṩ��API������IMSЭ��ջ��HIFI����SDP����ָʾ��Ϣʱ����
 *
 * @param[in]   ulChannelId     ����ͨ����ʶ
 * @param[in]   ucSdpDirect
 * @retval 0�ɹ���1ʧ��
 */
extern unsigned int IMSA_ImsEngineSendSdpDirect
(
    unsigned long                       ulChannelId,
    unsigned char                       ucSdpDirect
);

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

#endif /* end of ImsaImsApi.h */




