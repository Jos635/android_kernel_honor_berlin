


/******************************************************************************
   1 ͷ�ļ�����
******************************************************************************/
#include "PsLogFilter.h"
#include "msp_diag_comm.h"
#include "PsLib.h"

#ifdef  __cplusplus
    #if  __cplusplus
        extern "C" {
    #endif
#endif

#define    THIS_FILE_ID        PS_FILE_ID_LOG_FILTER_C

/******************************************************************************
   2 �ⲿ������������
******************************************************************************/
extern VOS_UINT32 GUNAS_OM_LayerMsgFilter(
    const VOS_VOID                     *pstMsg
);

extern VOS_UINT32 PAM_OM_LayerMsgFilter(
    const VOS_VOID                      *pMsg
);

extern VOS_UINT32 TLPS_OM_LayerMsgFilter(
    const VOS_VOID                      *pMsg
);

/******************************************************************************
   3 ˽�ж���
******************************************************************************/


/******************************************************************************
   4 ȫ�ֱ�������
******************************************************************************/
#if (OSA_CPU_CCPU == VOS_OSA_CPU)

PS_OM_LAYER_MSG_MATCH_CTRL_STRU         g_stLayerMsgMatchCtrl =
    {0, {VOS_NULL_PTR, VOS_NULL_PTR, VOS_NULL_PTR, VOS_NULL_PTR}};

#endif
/******************************************************************************
   5 ����ʵ��
******************************************************************************/
/* C�˹��˺��� */
#if (OSA_CPU_CCPU == VOS_OSA_CPU)
/*****************************************************************************
 �� �� ��  : PS_OM_LayerMsgMatch_Ccpu
 ��������  : �����Ϣ�滻�ӿ�
 �������  : VOS_VOID                           *pstMsg
 �������  : ��
 �� �� ֵ  : VOS_VOID*
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2016��9��5��
    ��    ��   : z00311339
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID* PS_OM_LayerMsgMatch_Ccpu
(
    VOS_VOID                           *pMsg
)
{
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulEntryCnt;
    VOS_VOID                           *pResult = pMsg;
    PS_OM_LAYER_MSG_MATCH_CTRL_STRU    *pstMsgMatchCtrl;

    pstMsgMatchCtrl = &g_stLayerMsgMatchCtrl;
    ulEntryCnt      = PS_MIN((pstMsgMatchCtrl->ulRegCnt), PS_OM_LAYER_MSG_MATCH_ITEM_MAX_CNT);

    for (ulIndex = 0; ulIndex < ulEntryCnt; ulIndex++)
    {
        if (VOS_NULL != pstMsgMatchCtrl->apfuncMatchEntry[ulIndex])
        {
            pResult = pstMsgMatchCtrl->apfuncMatchEntry[ulIndex]((MsgBlock*)pMsg);
            if (pMsg != pResult)
            {
                break;
            }
        }
    }

    return pResult;
}

/*****************************************************************************
 �� �� ��  : PS_OM_LayerMsgMatchInit
 ��������  : ��ʼ��MsgMatch
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2016��9��3��
    ��    ��   : z00311339
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_VOID PS_OM_LayerMsgMatchInit(VOS_VOID)
{
    (VOS_VOID)DIAG_TraceMatchFuncReg(PS_OM_LayerMsgMatch_Ccpu);

    return;
}

/*****************************************************************************
 �� �� ��  : PS_OM_LayerMsgMatchFuncReg_Ccpu
 ��������  : ע��MsgMatch�ص��ӿ�
 �������  : PS_OM_LAYER_MSG_MATCH_PFUNC          pFunc
             ��������ص��ӿڹ���:
             1.���ע��ص��ڲ�û�ж���Ϣ���д�������Ҫ�����ָ�뷵�أ�����
               ��ģ�鲻֪���Ƿ���Ҫ������Ϣ���ݸ���һ��ע��ص����д���
             2.���ע��ص��ڲ�����Ϣ�����˴����򷵻�ֵ�ܹ�ʵ����������:
               �ٷ���VOS_NULL���򽫴���Ϣ������ȫ���ˣ������ٹ�ȡ����
               �ڷ��������ָ�벻ͬ����һ��ָ�룬��ȡ����Ϣ����ʹ�÷��ص�ָ
                 �������滻ԭ��Ϣ�����ݡ���ģ�鲻������滻���ڴ�����ͷţ�
                 �滻ԭ��Ϣʹ�õ��ڴ����ģ�����й���
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2016��9��5��
    ��    ��   : z00311339
    �޸�����   : �����ɺ���

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgMatchFuncReg
(
    PS_OM_LAYER_MSG_MATCH_PFUNC         pFunc
)
{
    PS_OM_LAYER_MSG_MATCH_CTRL_STRU    *pstMsgMatchCtrl;
    VOS_UINT32                          ulIndex     = 0;
    VOS_UINT32                          ulLoop      = 0;
    VOS_UINT32                          ulMaxLoop   = 0;

    pstMsgMatchCtrl = &g_stLayerMsgMatchCtrl;
    ulIndex = pstMsgMatchCtrl->ulRegCnt;

    ulMaxLoop   = PS_MIN(ulIndex, PS_OM_LAYER_MSG_MATCH_ITEM_MAX_CNT);

    for (ulLoop = 0; ulLoop < ulMaxLoop; ulLoop++)
    {
        if (pstMsgMatchCtrl->apfuncMatchEntry[ulLoop] == pFunc)
        {
            return VOS_OK;
        }
    }

    if ((VOS_NULL_PTR != pFunc) && (PS_OM_LAYER_MSG_MATCH_ITEM_MAX_CNT > ulIndex))
    {
        pstMsgMatchCtrl->ulRegCnt   += 1;
        pstMsgMatchCtrl->apfuncMatchEntry[ulIndex] = pFunc;

        return VOS_OK;
    }

    return VOS_ERR;
}

/*****************************************************************************
 �� �� ��  : PS_OM_LayerMsgFilter_Ccpu
 ��������  : ������DIAG�������ע��Ĺ�����LOG���˺���
             ��������ɽ��Լ��Ĺ��˺���������������ڣ�
             ͳһ��DIAG�������ע��
 �������  : const VOID *pMsg:��Ϣָ��
 �������  : ��
 �� �� ֵ  : VOS_UINT32:
                ����VOS_TRUE:  ��ʾ����Ϣ��Ҫ���й���
                ����VOS_FALSE: ��ʾ����Ϣ������й���
 ���ú���  :
 ��������  :
 �޸���ʷ      :
  1.��    ��   : 2015��09��28��
    ��    ��   : h00313353
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgFilter_Ccpu(
    const VOS_VOID                      *pMsg
)
{
    /* GUNAS */
    if (VOS_TRUE == GUNAS_OM_LayerMsgFilter(pMsg))
    {
        return VOS_TRUE;
    }

    /* LNAS */
    if (VOS_TRUE == TLPS_OM_LayerMsgFilter(pMsg))
    {
        return VOS_TRUE;
    }

    if (VOS_TRUE == PAM_OM_LayerMsgFilter(pMsg))
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;
}
#endif

/* A�˹��˺��� */
#if (OSA_CPU_ACPU == VOS_OSA_CPU)
/*****************************************************************************
 �� �� ��  : PS_OM_LayerMsgFilter_Acpu
 ��������  : ������DIAG�������ע��Ĺ�����LOG���˺���
             ��������ɽ��Լ��Ĺ��˺���������������ڣ�
             ͳһ��DIAG�������ע��
             (��������A��������ע�ᣬ���ڹ���A���ڲ������Ϣ)
 �������  : const VOID *pMsg:��Ϣָ��
 �������  : ��
 �� �� ֵ  : VOS_UINT32:
                ����VOS_TRUE:  ��ʾ����Ϣ��Ҫ���й���
                ����VOS_FALSE: ��ʾ����Ϣ������й���
 ���ú���  :
 ��������  :
 �޸���ʷ      :
  1.��    ��   : 2015��09��28��
    ��    ��   : h00313353
    �޸�����   : �����ɺ���
*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgFilter_Acpu(
    const VOS_VOID                      *pMsg
)
{
    /* GUNAS */
    if (VOS_TRUE == GUNAS_OM_LayerMsgFilter(pMsg))
    {
        return VOS_TRUE;
    }

    if (VOS_TRUE == PAM_OM_LayerMsgFilter(pMsg))
    {
        return VOS_TRUE;
    }

    return VOS_FALSE;
}
#endif

#ifdef  __cplusplus
    #if  __cplusplus
        }
    #endif
#endif
