#pragma once
/*////////////////////////////////////////////////////
//说明：外观模式类实例
//文件：Facade.h
//日期：2020/6/29
//作者：coder
//修改：
//版本：
*//////////////////////////////////////////////////////

class CMaleUnmarriedcert
{
public:
	CMaleUnmarriedcert(std::string* pStr):
		m_pStr(pStr)
	{
	}
	~CMaleUnmarriedcert() {};

	//提交男方资料
	void Give()
	{
		std::cout << "男方未婚证明,常住户口本，居民身份证,户籍证明" << m_pStr->c_str() << std::endl;
	}
	
private:
	std::string* m_pStr;
};

class CFemaleUnmarriedcert
{
public:
	CFemaleUnmarriedcert(std::string* pStr):
		m_pStr(pStr)
	{
		
	}
	~CFemaleUnmarriedcert() {};

	//提交女方资料
	void Give()
	{
		std::cout << "女方未婚证明,常住户口本，居民身份证,户籍证明" << m_pStr->c_str() << std::endl;
	}

private:
	std::string* m_pStr;
};
//3张2寸近期半身免冠彩色合影照
class CMBOCAffairs
{
public:
	CMBOCAffairs()
	{
		m_str = "3张2寸近期半身免冠彩色合影照";
		m_pMale = new CMaleUnmarriedcert(&m_str);
		m_pFemal = new CFemaleUnmarriedcert(&m_str);
	}
	~CMBOCAffairs()
	{
		delete m_pMale;
		delete m_pFemal;
	}
	
	void DoAFMCertificate()
	{
		//提交男方资料
		m_pMale->Give();
		//提交女方资料
		m_pFemal->Give();
		std::cout << "成功办理结婚登记了，快拿着结婚证和你亲爱的相亲相爱，白头到老吧!" << std::endl;
	}

private:
	CMaleUnmarriedcert* m_pMale;
	CFemaleUnmarriedcert* m_pFemal;
	std::string m_str;
};

//////////////////////////////////////////////////////////
//个税系统
class CPersonTaxSystem
{
public:
	CPersonTaxSystem()
	{
	}
	~CPersonTaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "个税子系统业务" << std::endl;
	}
};

//消费税系统
class CConsumptiontaxSystem
{
public:
	CConsumptiontaxSystem()
	{
	}
	~CConsumptiontaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "消费税子系统业务" << std::endl;
	}
};

//企业所得税系统
class CBusinessIncomeTaxSystem
{
public:
	CBusinessIncomeTaxSystem()
	{
	}
	~CBusinessIncomeTaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "企业所得税子系统业务" << std::endl;
	}
};

//海关税务系统
class CCustomsTaxSystem
{
public:
	CCustomsTaxSystem()
	{
	}
	~CCustomsTaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "海关税务子系统业务" << std::endl;
	}
};

class CTaxHall
{
public:
	CTaxHall()
	{
		m_pSys1 = new CPersonTaxSystem;
		m_pSys2 = new CConsumptiontaxSystem;
		m_pSys3 = new CBusinessIncomeTaxSystem;
		m_pSys4 = new CCustomsTaxSystem;
	}
	~CTaxHall()
	{
		delete m_pSys1;
		delete m_pSys2;
		delete m_pSys3;
		delete m_pSys4;
	}

	void DoTaxWindow()
	{
		m_pSys1->DoTax();
		m_pSys2->DoTax();
		m_pSys3->DoTax();
		m_pSys4->DoTax();
	}

private:
	CPersonTaxSystem* m_pSys1;
	CConsumptiontaxSystem* m_pSys2;
	CBusinessIncomeTaxSystem* m_pSys3;
	CCustomsTaxSystem* m_pSys4;
};