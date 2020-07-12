#pragma once
/*////////////////////////////////////////////////////
//˵����װ����ģʽ��ʵ��
//�ļ���Proxy.h
//���ڣ�2020/6/29
//���ߣ�coder
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

//�������
enum ePersonIdentity
{
	OneselfID,
	ProxyID,
	eMaxIdentity
};

//��������ȡҵ��
//Withdrawal of provident fund

//�����������ȡ�ύ����
struct stWOPFundPersonInfo
{
	stWOPFundPersonInfo& operator = (const stWOPFundPersonInfo& r)
	{
		eProxy = r.eProxy;
		strName = r.strName;
		strIDCard = r.strIDCard;
		strTime = r.strTime;

		return *this;
	}

	ePersonIdentity eProxy;//�Ƿ��Ǵ������
	std::string strName;//����
	std::string strIDCard;//���֤
	std::string strTime;//ʱ��
};

//���������������Ϣ
struct stProxyWOPFundPersonInfo
{
	stProxyWOPFundPersonInfo& operator = (const stProxyWOPFundPersonInfo& r)
	{
		strProxyName = r.strProxyName;
		strProxyIDCard = r.strProxyIDCard;
		strRelation = r.strRelation;
		return *this;
	}

	std::string strProxyName;//����������
	std::string strProxyIDCard;//���������֤
	std::string strRelation;//��ϵ
};

//������ȡ������ҵ��
class CPersonWOPFundBase
{
public:
	CPersonWOPFundBase()
	{
	}
	virtual ~CPersonWOPFundBase() {}

public:
	//�ύ����
	virtual bool DoSubmission(const stWOPFundPersonInfo& info,
		const stProxyWOPFundPersonInfo& pInfo) = 0;
	//��ȡ������
	virtual bool DoWOPFund() = 0;

protected:
	//������Ϣ
	stWOPFundPersonInfo m_info;
	//��������Ϣ
	stProxyWOPFundPersonInfo m_proxyInfo;
	//��������Ƿ���ȷ
	bool m_bPassed;
};

//���˰�������ҵ��
class CPersonWOPFund : public CPersonWOPFundBase
{
public:
	CPersonWOPFund()
	{
		m_bPassed = false;
	}
	~CPersonWOPFund()
	{
		m_bPassed = false;
	}

	void DoProxyEvent()
	{
		std::cout << "ʱ��:" <<
			m_info.strTime << 
			" ���Ǳ��ˣ�" <<
			" �� " <<
			m_proxyInfo.strRelation <<
			" ��ϵ��," <<
			m_proxyInfo.strProxyName <<
			" ���֤�ţ�" <<
			m_proxyInfo.strProxyIDCard <<
			" ��Ϊ����" << std::endl;
		std::cout << "�ύ��������˳ɹ�!" << std::endl;
		m_bPassed = true;
	}

	void DoOneselfEvent()
	{
		std::cout <<"ʱ��:" <<
			m_info.strTime <<
			" �Ǳ��ˣ�" <<
			" �� " <<
			m_info.strName <<
			" ���֤�ţ�" <<
			m_info.strIDCard <<
			" ���԰���" << std::endl;
		std::cout << "�ύ��������˳ɹ�!" << std::endl;
		m_bPassed = true;
	}

	//�ύ����
	bool DoSubmission(const stWOPFundPersonInfo& info,
		const stProxyWOPFundPersonInfo& pInfo)
	{
		ePersonIdentity eProxy = info.eProxy;
		switch (eProxy)
		{
		case OneselfID:
		{
			m_info = info;
		}
		break;
		case ProxyID:
		{
			m_info = info;
			m_proxyInfo = pInfo;
		}
		break;
		default:
			memset(&m_info, 0, sizeof(m_info));
			break;
		}

		switch (m_info.eProxy)
		{
		case ProxyID:
			DoProxyEvent();
			return true;
		case OneselfID:
			DoOneselfEvent();
			return true;
		default:
			break;
		}	
		std::cout << "�ύ�����ϲ���ȷ��" << std::endl;
		return false;
	}

	//��ȡ������
	bool DoWOPFund()
	{
		if (m_bPassed)
		{
			switch (m_info.eProxy)
			{
			case ProxyID:
				std::cout << "�ɹ����칫������ȡҵ�񣬿���һ���º��ʣ�" << std::endl;
				return true;
			case OneselfID:
				std::cout << "�ɹ�����������ȡҵ�񣬿���һ���º��ʣ�" << std::endl;
				return true;
			default:
				break;
			}			
		}
		std::cout << "����������ȡҵ��ʧ��!" << std::endl;
		return false;
	}
};

//�����˴��칫����ҵ��
class CPersonWOPFundProxy
{
public:
	CPersonWOPFundProxy(CPersonWOPFundBase* pSub):
		m_pSub(pSub)
	{
	}
	~CPersonWOPFundProxy(){	}

	//�����ύ����
	bool DoSubmission(const stWOPFundPersonInfo& info,
		const stProxyWOPFundPersonInfo& pInfo)
	{
		return m_pSub->DoSubmission(info, pInfo);
	}

	//������ȡ������
	bool DoWOPFund()
	{
		return m_pSub->DoWOPFund();
	}

protected:
	CPersonWOPFundBase* m_pSub;
};