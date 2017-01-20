/**
 * @file tee_client_id.h
 *
 * Copyright(C), 2008-2013, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * ��������ȫ�����ṩ�İ�ȫ�����������ͷ�ļ�\n
 */
#ifndef _TEE_CLIENT_ID_H_
#define _TEE_CLIENT_ID_H_

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ����Global��UUID����ȫ����Global������������ȫ����Ļ���
 */
#define TEE_SERVICE_GLOBAL \
{ \
	0x00000000, \
	0x0000, \
	0x0000, \
	{ \
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 \
	} \
}

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ����Echo��UUID
 */
#define TEE_SERVICE_ECHO \
{ \
	0x01010101, \
	0x0101, \
	0x0101, \
	{ \
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 \
	} \
}

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ�洢�����UUID
 */
#define TEE_SERVICE_STORAGE \
{ \
	0x02020202, \
	0x0202, \
	0x0202, \
	{ \
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 \
	} \
}

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ����UT���Ե�UUID
 */
#define TEE_SERVICE_UT \
{ \
	0x03030303, \
	0x0303, \
	0x0303, \
	{ \
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 \
	} \
}

/**
 * @ingroup  TEE_ID
 *
 * �ӽ��ܷ����UUID
 */
#define TEE_SERVICE_CRYPTO \
{ \
	0x04040404, \
	0x0404, \
	0x0404, \
	{ \
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 \
	} \
}

/**
 * @ingroup  TEE_ID
 *
 * efuse�����UUID
 */
#define TEE_SERVICE_EFUSE \
{ \
	0x05050505, \
	0x0505, \
	0x0505, \
	{ \
		0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05 \
	} \
}
/**
 * @ingroup  TEE_ID
 *
 * HDCP�����UUID
 */
#define TEE_SERVICE_HDCP \
{ \
	0x06060606, \
	0x0606, \
	0x0606, \
	{ \
		0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06 \
	} \
}
/**
 * @ingroup  TEE_ID
 *
 * KeyMaster�����UUID
 */
#define TEE_SERVICE_KEYMASTER \
{ \
	0x07070707, \
	0x0707, \
	0x0707, \
	{ \
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07 \
	} \
}

/**
 *  * @ingroup  TEE_ID
 *   *
 *    * secboot��
 *     */
#define TEE_SERVICE_SECBOOT \
{ \
	0x08080808, \
	0x0808, \
	0x0808, \
	{ \
		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08 \
	} \
}

/**
 * @ingroup  TEE_COMMON_DATA
 *
 * ��ȫ����secboot֧�ֵ�����ID
 */
enum SVC_SECBOOT_CMD_ID {
	SECBOOT_CMD_ID_INVALID = 0x0,	/**< Secboot Task ��ЧID*/
	SECBOOT_CMD_ID_COPY_VRL,	/**< Secboot Task ����VRL*/
	SECBOOT_CMD_ID_COPY_DATA,	/**< Secboot Task ��������*/
	SECBOOT_CMD_ID_VERIFY_DATA,	/**< Secboot Task ��֤*/
	SECBOOT_CMD_ID_RESET_IMAGE,	/**< Secboot Task ��λSoC����*/
	SECBOOT_CMD_ID_COPY_VRL_TYPE,  /**< Secboot Task ����VRL��������SoC Type*/
	SECBOOT_CMD_ID_COPY_DATA_TYPE,	/**< Secboot Task ��������,������SoC Type*/
	SECBOOT_CMD_ID_VERIFY_DATA_TYPE, /**< Secboot Task У�飬������SoC Type��У��ɹ��⸴λSoC*/
	 /**< Secboot Taskԭ��У�飬������SoC Type,У��ɹ��⸴λSoC*/
	SECBOOT_CMD_ID_VERIFY_DATA_TYPE_LOCAL,
	SECBOOT_CMD_ID_BSP_MODEM_CALL,           /**< Secboot Task ִ�ж�Ӧ����*/
	SECBOOT_CMD_ID_BSP_MODULE_VERIFY,        /**< Secboot Task modem moduleУ�麯��*/
};

/**
 * @ingroup TEE_COMMON_DATA
 *
 * ��ȫ����secboot֧�ֵľ�������
 */
enum SVC_SECBOOT_IMG_TYPE {
	MODEM,
	HIFI,
	DSP,
	XDSP,
	TAS,
	WAS,
	CAS,
	MODEM_DTB,
    ISP,
	SOC_MAX
};
/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ����Global֧�ֵ�����ID
 */
enum SVC_GLOBAL_CMD_ID {
	GLOBAL_CMD_ID_INVALID = 0x0,	/**< ��ȫ����Global����Ч������*/
	GLOBAL_CMD_ID_BOOT_ACK,	   /**< ��ȫ����Global������Ӧ��*/
	GLOBAL_CMD_ID_OPEN_SESSION,    /**< ��ȫ����Global����Session*/
	GLOBAL_CMD_ID_CLOSE_SESSION,	/**< ��ȫ����Global���ر�Session*/
	GLOBAL_CMD_ID_LOAD_SECURE_APP,
	/**< ��ȫ����Global����̬���ذ�ȫӦ��*/
	GLOBAL_CMD_ID_NEED_LOAD_APP,/**< ��ȫ����Global���ж��Ƿ�����Ҫ���ذ�ȫӦ��*/
	GLOBAL_CMD_ID_REGISTER_AGENT,
	/**< ��ȫ����Global��ע�����*/
	GLOBAL_CMD_ID_UNREGISTER_AGENT,
	/**< ��ȫ����Global��ע������*/
	GLOBAL_CMD_ID_REGISTER_NOTIFY_MEMORY,
	/**< ��ȫ����Global��ע���첽���û�����*/
	GLOBAL_CMD_ID_UNREGISTER_NOTIFY_MEMORY,
	 /**< ��ȫ����Global��ע���첽���û�����*/
	GLOBAL_CMD_ID_INIT_CONTENT_PATH,  /**< ��ȫ����Global����ʼ��content path*/
	GLOBAL_CMD_ID_TERMINATE_CONTENT_PATH,
	 /**< ��ȫ����Global���ͷ�content path*/
	GLOBAL_CMD_ID_ALLOC_EXCEPTION_MEM,
	/**< ��ȫ����Global�������쳣��Ϣ����ռ�*/
	GLOBAL_CMD_ID_TEE_TIME,	    /**< ��ȫ����Global����ȡ��ȫOS��ʱ�� */
	GLOBAL_CMD_ID_TEE_INFO,	   /** tlogcat ����OS  �� */
	GLOBAL_CMD_ID_KILL_TASK,   /** Global Task Kill session */
	GLOBAL_CMD_ID_SET_CA_HASH,   /*set ca hash info*/
	GLOBAL_CMD_ID_MAX,    /**< ��ȫ����Global��δ֧�ֵ�����*/
};

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ����echo֧�ֵ�����ID
 */
enum SVC_ECHO_CMD_ID {
	ECHO_CMD_ID_INVALID = 0x0,    /**< Echo Task��Ч������*/
	ECHO_CMD_ID_SEND_CMD,	 /**< Echo Task��������*/
	ECHO_CMD_ID_EFUSE_READ,
	ECHO_CMD_ID_EFUSE_WRITE,
	ECHO_CMD_ID_MAX,    /**< Echo Taskδ֧�ֵ�����*/
};

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ�洢����֧�ֵ�����ID
 */
enum SVC_STORAGE_CMD_ID {
	STORAGE_CMD_ID_INVALID = 0x10,	  /**< ��ȫ�洢������Ч������*/
	STORAGE_CMD_ID_OPEN,	/**< ��ȫ�洢���񣬴��ļ�����*/
	STORAGE_CMD_ID_CLOSE,	 /**< ��ȫ�洢���񣬹ر��ļ�����*/
	STORAGE_CMD_ID_CLOSEALL,    /**< ��ȫ�洢���񣬹ر������ļ�����*/
	STORAGE_CMD_ID_READ,	/**< ��ȫ�洢���񣬶�ȡ�ļ�����*/
	STORAGE_CMD_ID_WRITE,	 /**< ��ȫ�洢����д���ļ�����*/
	STORAGE_CMD_ID_SEEK,		    /**< ��ȫ�洢�����ȡ��ǰ�ļ�λ��*/
	STORAGE_CMD_ID_TELL,		    /**< ��ȫ�洢�����ض�λ�ļ�*/
	STORAGE_CMD_ID_TRUNCATE,	    /**< ��ȫ�洢����ı��ļ���С*/
	STORAGE_CMD_ID_REMOVE,		    /**< ��ȫ�洢����ɾ���ļ�*/
	STORAGE_CMD_ID_FINFO,		     /**< ��ȫ�洢���񷵻��ļ�״̬*/
	STORAGE_CMD_ID_UNKNOWN = 0x7FFFFFFE,/**< ��ȫ�洢���� δ֪ID*/
	STORAGE_CMD_ID_MAX = 0x7FFFFFFF,    /**< ��ȫ�洢����δ֧�ֵ�����*/
};

/**
 * @ingroup  TEEC_COMMON_DATA
 *
 * ��ȫ����CRYPTO֧�ֵ�����ID, �����ԳƼӽ��ܡ��ǶԳƼӽ��ܡ�ժҪHMAC��\n
 * ע��:�Գ��㷨�е�nopadģʽ��ҪTA(Trusted Application������Ӧ��)�������
 */
enum SVC_CRYPT_CMD_ID {
	CRYPT_CMD_ID_INVALID = 0x10,	    /**< ��ЧID */
	CRYPT_CMD_ID_ENCRYPT,		    /**< ���� */
	CRYPT_CMD_ID_DECRYPT,		    /**< ���� */
	CRYPT_CMD_ID_MD5,		    /**< ժҪ�㷨MD5 */
	CRYPT_CMD_ID_SHA1,		    /**< ժҪ�㷨SHA1 */
	CRYPT_CMD_ID_SHA224,		    /**< ժҪ�㷨SHA224 */
	CRYPT_CMD_ID_SHA256,		    /**< ժҪ�㷨SHA256 */
	CRYPT_CMD_ID_SHA384,		    /**< ժҪ�㷨SHA384 */
	CRYPT_CMD_ID_SHA512,		    /**< ժҪ�㷨SHA512 */
	CRYPT_CMD_ID_HMAC_MD5,		    /**< HMAC MD5 */
	CRYPT_CMD_ID_HMAC_SHA1,		    /**< HMAC SHA1 */
	CRYPT_CMD_ID_HMAC_SHA224,	    /**< HMAC SHA224 */
	CRYPT_CMD_ID_HMAC_SHA256,	    /**< HMAC SHA256 */
	CRYPT_CMD_ID_HMAC_SHA384,	    /**< HMAC SHA384 */
	CRYPT_CMD_ID_HMAC_SHA512,	    /**< HMAC SHA512 */
	CRYPT_CMD_ID_CIPHER_AES_CBC,	/**< �ԳƼӽ���AES 128bits��Կ CBCģʽ */
	CRYPT_CMD_ID_CIPHER_AES_CBC_CTS,/**< �ԳƼӽ���AES 128bits��Կ CBC_CTSģʽ */
	CRYPT_CMD_ID_CIPHER_AES_ECB,	/**< �ԳƼӽ���AES 128bits��Կ ECBģʽ */
	CRYPT_CMD_ID_CIPHER_AES_CTR,	/**< �ԳƼӽ���AES 128bits��Կ CTRģʽ */
	CRYPT_CMD_ID_CIPHER_AES_CBC_MAC,/**< �ԳƼӽ���AES 128bits��Կ CBC_MACģʽ */
	CRYPT_CMD_ID_CIPHER_AES_XCBC_MAC,
	/**< �ԳƼӽ���AES 128bits��Կ XCBC_MACģʽ */
	CRYPT_CMD_ID_CIPHER_AES_CMAC,	/**< �ԳƼӽ���AES 128bits��Կ CMACģʽ */
	CRYPT_CMD_ID_CIPHER_AES_CCM,	/**< �ԳƼӽ���AES 128bits��Կ CCMģʽ */
	CRYPT_CMD_ID_CIPHER_AES_XTS,	/**< �ԳƼӽ���AES 128bits��Կ XTSģʽ */
	CRYPT_CMD_ID_CIPHER_DES_ECB,	    /**< �ԳƼӽ���DES ECBģʽ */
	CRYPT_CMD_ID_CIPHER_DES_CBC,	    /**< �ԳƼӽ���DES CBCģʽ */
	CRYPT_CMD_ID_CIPHER_DES3_ECB,	    /**< �ԳƼӽ���DES3 ECBģʽ */
	CRYPT_CMD_ID_CIPHER_DES3_CBC,	    /**< �ԳƼӽ���DES3 CBCģʽ */
	CRYPT_CMD_ID_CIPHER_RND,	    /**< �����ģʽ */
	CRYPT_CMD_ID_CIPHER_DK,		    /**< ��Կ����ģʽ */
	CRYPT_CMD_ID_RSAES_PKCS1_V1_5,	    /**< �ǶԳƼӽ���PKCS1_V1_5ģʽ */
	CRYPT_CMD_ID_RSAES_PKCS1_OAEP_MGF1_SHA1,
					    /**< �ǶԳƼӽ���OAEP_SHA1ģʽ */
	CRYPT_CMD_ID_RSAES_PKCS1_OAEP_MGF1_SHA224,
	/**< �ǶԳƼӽ���OAEP_SHA224ģʽ */
	CRYPT_CMD_ID_RSAES_PKCS1_OAEP_MGF1_SHA256,
	/**< �ǶԳƼӽ���OAEP_SHA256ģʽ */
	CRYPT_CMD_ID_RSAES_PKCS1_OAEP_MGF1_SHA384,
	/**< �ǶԳƼӽ���OAEP_SHA384ģʽ */
	CRYPT_CMD_ID_RSAES_PKCS1_OAEP_MGF1_SHA512,
	/**< �ǶԳƼӽ���OAEP_SHA512ģʽ */
	CRYPT_CMD_ID_RSA_NOPAD,		    /**< �ǶԳƼӽ��������ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_V1_5_MD5, /**< �ǶԳ�ǩ����֤PKCS1_V1_5_MD5ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_V1_5_SHA1,/**< �ǶԳ�ǩ����֤PKCS1_V1_5_SHA1ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_V1_5_SHA224,
	/**< �ǶԳ�ǩ����֤PKCS1_V1_5_SHA224ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_V1_5_SHA256,
	/**< �ǶԳ�ǩ����֤PKCS1_V1_5_SHA256ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_V1_5_SHA384,
	/**< �ǶԳ�ǩ����֤PKCS1_V1_5_SHA384ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_V1_5_SHA512,
	/**< �ǶԳ�ǩ����֤PKCS1_V1_5_SHA512ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_PSS_MGF1_SHA1,
	/**< �ǶԳ�ǩ����֤PSS_MGF1_SHA1ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_PSS_MGF1_SHA224,
	/**< �ǶԳ�ǩ����֤PSS_MGF1_SHA224ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_PSS_MGF1_SHA256,
	/**< �ǶԳ�ǩ����֤PSS_MGF1_SHA256ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_PSS_MGF1_SHA384,
	/**< �ǶԳ�ǩ����֤PSS_MGF1_SHA384ģʽ */
	CRYPT_CMD_ID_RSASSA_PKCS1_PSS_MGF1_SHA512,
	/**< �ǶԳ�ǩ����֤PSS_MGF1_SHA512ģʽ */
	CRYPT_CMD_ID_DSA_SHA1,		    /**< �ǶԳ�ǩ����֤DSAģʽ */
	CRYPT_CMD_ID_UNKNOWN = 0x7FFFFFFE,  /**< δ֪ģʽ */
	CRYPT_CMD_ID_MAX = 0x7FFFFFFF	    /**< ���CMD ID */
};

enum SVC_KEYMASTER_CMD_ID {
	KM_CMD_ID_INVALID = 0x0,
	KM_CMD_ID_GENERATE_KEYPAIR,
	KM_CMD_ID_GET_PUBLIC_KEY,
	KM_CMD_ID_IMPORT_KEYPAIR,
	KM_CMD_ID_SIGN_DATA,
	KM_CMD_ID_VERIFY_DATA,
};
#endif
