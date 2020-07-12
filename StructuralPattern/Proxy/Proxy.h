#pragma once
/*////////////////////////////////////////////////////
//说明：装饰者模式类实例
//文件：Proxy.h
//日期：2020/6/29
//作者：coder
//修改：
//版本：
*//////////////////////////////////////////////////////

//个人身份
enum ePersonIdentity
{
	OneselfID,
	ProxyID,
	eMaxIdentity
};

//公积金提取业务
//Withdrawal of provident fund

//公积金个人提取提交资料
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

	ePersonIdentity eProxy;//是否是代理办理
	std::string strName;//姓名
	std::string strIDCard;//身份证
	std::string strTime;//时间
};

//代办代理人资料信息
struct stProxyWOPFundPersonInfo
{
	stProxyWOPFundPersonInfo& operator = (const stProxyWOPFundPersonInfo& r)
	{
		strProxyName = r.strProxyName;
		strProxyIDCard = r.strProxyIDCard;
		strRelation = r.strRelation;
		return *this;
	}

	std::string strProxyName;//代理人姓名
	std::string strProxyIDCard;//代理人身份证
	std::string strRelation;//关系
};

//个人提取公积金业务
class CPersonWOPFundBase
{
public:
	CPersonWOPFundBase()
	{
	}
	virtual ~CPersonWOPFundBase() {}

public:
	//提交资料
	virtual bool DoSubmission(const stWOPFundPersonInfo& info,
		const stProxyWOPFundPersonInfo& pInfo) = 0;
	//提取公积金
	virtual bool DoWOPFund() = 0;

protected:
	//本人信息
	stWOPFundPersonInfo m_info;
	//代理人信息
	stProxyWOPFundPersonInfo m_proxyInfo;
	//资料审核是否正确
	bool m_bPassed;
};

//个人办理公积金业务
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
		std::cout << "时间:" <<
			m_info.strTime << 
			" 不是本人：" <<
			" 由 " <<
			m_proxyInfo.strRelation <<
			" 关系的," <<
			m_proxyInfo.strProxyName <<
			" 身份证号：" <<
			m_proxyInfo.strProxyIDCard <<
			" 代为办理" << std::endl;
		std::cout << "提交的资料审核成功!" << std::endl;
		m_bPassed = true;
	}

	void DoOneselfEvent()
	{
		std::cout <<"时间:" <<
			m_info.strTime <<
			" 是本人：" <<
			" 由 " <<
			m_info.strName <<
			" 身份证号：" <<
			m_info.strIDCard <<
			" 亲自办理" << std::endl;
		std::cout << "提交的资料审核成功!" << std::endl;
		m_bPassed = true;
	}

	//提交资料
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
		std::cout << "提交的资料不正确！" << std::endl;
		return false;
	}

	//提取公积金
	bool DoWOPFund()
	{
		if (m_bPassed)
		{
			switch (m_info.eProxy)
			{
			case ProxyID:
				std::cout << "成功代办公积金提取业务，款项一个月后到帐！" << std::endl;
				return true;
			case OneselfID:
				std::cout << "成功办理公积金提取业务，款项一个月后到帐！" << std::endl;
				return true;
			default:
				break;
			}			
		}
		std::cout << "办理公积金提取业务失败!" << std::endl;
		return false;
	}
};

//代理人代办公积金业务
class CPersonWOPFundProxy
{
public:
	CPersonWOPFundProxy(CPersonWOPFundBase* pSub):
		m_pSub(pSub)
	{
	}
	~CPersonWOPFundProxy(){	}

	//代理提交资料
	bool DoSubmission(const stWOPFundPersonInfo& info,
		const stProxyWOPFundPersonInfo& pInfo)
	{
		return m_pSub->DoSubmission(info, pInfo);
	}

	//代理提取公积金
	bool DoWOPFund()
	{
		return m_pSub->DoWOPFund();
	}

protected:
	CPersonWOPFundBase* m_pSub;
};