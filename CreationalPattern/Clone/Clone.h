#pragma once
#include <string>
#include <iostream>
/*////////////////////////////////////////////////////
//说明：原型模式类
//文件：Clone.h
//日期：2020/6/23
//作者：coder
//QQ：375187588
//修改：2020/6/30
//版本：
*//////////////////////////////////////////////////////

template<class T>
class ICloneable
{
public:
	virtual T* Clone() = 0;
};

class CWorkExperience
{
public:
	CWorkExperience()
	{
	}
	CWorkExperience(const std::string& strCompany,
		int nTime)
	{
		m_strCompany = strCompany;
		m_nTime = nTime;
	}

	//拷贝构造函数
	CWorkExperience(const CWorkExperience& r)
	{
		m_strCompany = r.m_strCompany;
		m_nTime = r.m_nTime;
	}
	~CWorkExperience()
	{
		//Print();
	}
	void SetCompany(const std::string& strCompany)
	{
		m_strCompany = strCompany;
	}
	const std::string& GetCompany() const
	{
		return m_strCompany;
	}
	void SetWorkTime(int nWorkTime)
	{
		m_nTime = nWorkTime;
	}
	const unsigned char GetWorkTime() const
	{
		return m_nTime;
	}

	void Print()
	{
		std::cout << "工作公司:" << m_strCompany << std::endl;
		std::cout << "工作时间:" << (int)m_nTime << "年" << std::endl;
	}


private:
	std::string m_strCompany;
	int m_nTime;
};

class CResume : public ICloneable<CResume>
{
public:
	CResume()
	{
	}
	~CResume()
	{
		std::cout << "~CResume()" << std::endl;
	}
	CResume* Clone()
	{
		CResume* pResume = new CResume();
		pResume->SetPersonInfo(m_strName,m_btSex,m_btAge);
		pResume->SetWorkExperience(m_workExperience.GetCompany(), m_workExperience.GetWorkTime());
		return pResume;
	}

	void SetPersonInfo(const std::string& name, unsigned char sex, unsigned char age)
	{
		m_strName = name;
		m_btSex = sex;
		m_btAge = age;
	}
	void SetWorkExperience(const std::string& company, int workTime)
	{
		m_workExperience.SetCompany(company);
		m_workExperience.SetWorkTime(workTime);
	}

	void Print()
	{
		std::cout << "姓名:" << m_strName << std::endl;
		std::cout << "性别:" << ((m_btSex == 0)?"女":"男") << std::endl;
		std::cout << "年龄:" << (int)m_btAge << "岁" << std::endl;
		m_workExperience.Print();
	}

private:
	std::string m_strName;
	unsigned char m_btSex;
	unsigned char m_btAge;
	CWorkExperience m_workExperience;
};

//浅拷贝
class CResume2 : public ICloneable<CResume2>
{
public:
	CResume2()
	{
		m_pWorkExperience = nullptr;
	}
	CResume2(CWorkExperience* pWorkExperience)
	{
		m_pWorkExperience = pWorkExperience;
	}
	CResume2(const CResume2& r)
	{
		m_strName = r.m_strName;
		m_btSex = r.m_btSex;
		m_btAge = r.m_btAge;
		m_pWorkExperience = r.m_pWorkExperience;
	}
	~CResume2()
	{
		std::cout << "~CResume()" << std::endl;
	}
	CResume2* Clone()
	{
		CResume2* pResume = new CResume2(*this);
		return pResume;
	}

	void SetPersonInfo(const std::string& name, unsigned char sex, unsigned char age)
	{
		m_strName = name;
		m_btSex = sex;
		m_btAge = age;
	}
	void SetWorkExperience(const std::string& company, int workTime)
	{
		m_pWorkExperience->SetCompany(company);
		m_pWorkExperience->SetWorkTime(workTime);
	}

	void Print()
	{
		std::cout << "姓名:" << m_strName << std::endl;
		std::cout << "性别:" << ((m_btSex == 0) ? "女" : "男") << std::endl;
		std::cout << "年龄:" << (int)m_btAge << "岁" << std::endl;
		m_pWorkExperience->Print();
	}

protected:
	std::string m_strName;
	unsigned char m_btSex;
	unsigned char m_btAge;
	CWorkExperience *m_pWorkExperience;
};

//深拷贝
class CWorkExperience22
{
public:
	CWorkExperience22()
	{
	}
	CWorkExperience22(const std::string& strCompany,
		int nTime)
	{
		m_strCompany = strCompany;
		m_nTime = nTime;
	}
	//拷贝构造函数
	CWorkExperience22(const CWorkExperience22& r)
	{
		m_strCompany = r.m_strCompany;
		m_nTime = r.m_nTime;
	}
	~CWorkExperience22()
	{
		//Print();
	}
	void SetCompany(const std::string& strCompany)
	{
		m_strCompany = strCompany;
	}
	const std::string& GetCompany() const
	{
		return m_strCompany;
	}
	void SetWorkTime(int nWorkTime)
	{
		m_nTime = nWorkTime;
	}
	const unsigned char GetWorkTime() const
	{
		return m_nTime;
	}
	CWorkExperience22* Clone()
	{
		CWorkExperience22* p = new CWorkExperience22(*this);
		return p;
	}

	void Print()
	{
		std::cout << "工作公司:" << m_strCompany << std::endl;
		std::cout << "工作时间:" << (int)m_nTime << "年" << std::endl;
	}


private:
	std::string m_strCompany;
	int m_nTime;
};

class CResume22 : public ICloneable<CResume22>
{
public:
	CResume22()
	{
		m_pWorkExperience = nullptr;
	}
	CResume22(CWorkExperience22* pWorkExperience)
	{
		m_pWorkExperience = pWorkExperience;
	}
	CWorkExperience22* GetWorkExperience()
	{
		return m_pWorkExperience;
	}
	CResume22(const CResume22& r)
	{
		m_strName = r.m_strName;
		m_btSex = r.m_btSex;
		m_btAge = r.m_btAge;
		m_pWorkExperience = r.m_pWorkExperience->Clone();
	}
	~CResume22()
	{
		std::cout << "~CResume()" << std::endl;
	}
	CResume22* Clone()
	{
		CResume22* pResume = new CResume22(*this);
		return pResume;
	}

	void SetPersonInfo(const std::string& name, unsigned char sex, unsigned char age)
	{
		m_strName = name;
		m_btSex = sex;
		m_btAge = age;
	}
	void SetWorkExperience(const std::string& company, int workTime)
	{
		m_pWorkExperience->SetCompany(company);
		m_pWorkExperience->SetWorkTime(workTime);
	}

	void Print()
	{
		std::cout << "姓名:" << m_strName << std::endl;
		std::cout << "性别:" << ((m_btSex == 0) ? "女" : "男") << std::endl;
		std::cout << "年龄:" << (int)m_btAge << "岁" << std::endl;
		m_pWorkExperience->Print();
	}

protected:
	std::string m_strName;
	unsigned char m_btSex;
	unsigned char m_btAge;
	CWorkExperience22 *m_pWorkExperience;
};

/////////////////////////////////////////////////////////
//解决深拷贝内存释放问题
template<class T>
class ICloneable33
{
public:
	virtual T* Clone() = 0;
	bool IsDeepClone()
	{
		return m_bIsDeepClone;
	}
	virtual ~ICloneable33() {}

protected:
	ICloneable33()
	{
		m_bIsDeepClone = false;
	}
	//如果是深拷贝设置为true
	void SetDeepClone(bool b)
	{
		m_bIsDeepClone = b;
	}
	bool m_bIsDeepClone;
};

class CWorkExperience33 : public ICloneable33<CWorkExperience33>
{
public:
	CWorkExperience33()
	{
	}
	CWorkExperience33(const std::string& strCompany,
		int nTime)
	{
		m_strCompany = strCompany;
		m_nTime = nTime;
	}
	//拷贝构造函数
	CWorkExperience33(const CWorkExperience33& r)
	{
		m_strCompany = r.m_strCompany;
		m_nTime = r.m_nTime;
	}
	~CWorkExperience33()
	{
		//Print();
	}
	void SetCompany(const std::string& strCompany)
	{
		m_strCompany = strCompany;
	}
	const std::string& GetCompany() const
	{
		return m_strCompany;
	}
	void SetWorkTime(int nWorkTime)
	{
		m_nTime = nWorkTime;
	}
	const unsigned char GetWorkTime() const
	{
		return m_nTime;
	}
	CWorkExperience33* Clone()
	{
		CWorkExperience33* p = new CWorkExperience33(*this);
		p->SetDeepClone(true);
		return p;
	}

	void Print()
	{
		std::cout << "工作公司:" << m_strCompany << std::endl;
		std::cout << "工作时间:" << (int)m_nTime << "年" << std::endl;
	}


private:
	std::string m_strCompany;
	int m_nTime;
};

class CResume33 : public ICloneable33<CResume33>
{
public:
	CResume33()
	{
		m_pWorkExperience = nullptr;
	}
	CResume33(CWorkExperience33* pWorkExperience)
	{
		m_pWorkExperience = pWorkExperience;
	}
	CWorkExperience33* GetWorkExperience()
	{
		return m_pWorkExperience;
	}
	CResume33(const CResume33& r)
	{
		m_strName = r.m_strName;
		m_btSex = r.m_btSex;
		m_btAge = r.m_btAge;
		m_pWorkExperience = r.m_pWorkExperience->Clone();
	}
	~CResume33()
	{
		if (m_pWorkExperience != nullptr &&
			m_pWorkExperience->IsDeepClone())
		{
			delete m_pWorkExperience;
			m_pWorkExperience = nullptr;
		}
		std::cout << "~CResume()" << std::endl;
	}
	CResume33* Clone()
	{
		CResume33* pResume = new CResume33(*this);
		pResume->SetDeepClone(true);
		return pResume;
	}

	void SetPersonInfo(const std::string& name, unsigned char sex, unsigned char age)
	{
		m_strName = name;
		m_btSex = sex;
		m_btAge = age;
	}
	void SetWorkExperience(const std::string& company, int workTime)
	{
		m_pWorkExperience->SetCompany(company);
		m_pWorkExperience->SetWorkTime(workTime);
	}

	void Print()
	{
		std::cout << "姓名:" << m_strName << std::endl;
		std::cout << "性别:" << ((m_btSex == 0) ? "女" : "男") << std::endl;
		std::cout << "年龄:" << (int)m_btAge << "岁" << std::endl;
		m_pWorkExperience->Print();
	}

protected:
	std::string m_strName;
	unsigned char m_btSex;
	unsigned char m_btAge;
	CWorkExperience33 *m_pWorkExperience;
};

/////////////////////////////////////////////////////////////
/////////===================================================
////////////////////////////////////////////////////////////
//解决程序崩溃问题
//解决深拷贝内存释放问题
template<class T>
class ICloneable33Ptr
{
public:
	virtual T* Clone() = 0;
	virtual ~ICloneable33Ptr() {}

};

class CWorkExperience33Ptr : public ICloneable33Ptr<CWorkExperience33Ptr>
{
public:
	CWorkExperience33Ptr()
	{
	}
	CWorkExperience33Ptr(const std::string& strCompany,
		int nTime)
	{
		m_strCompany = strCompany;
		m_nTime = nTime;
	}
	//拷贝构造函数
	CWorkExperience33Ptr(const CWorkExperience33Ptr& r)
	{
		m_strCompany = r.m_strCompany;
		m_nTime = r.m_nTime;
	}
	~CWorkExperience33Ptr()
	{
	}
	void SetCompany(const std::string& strCompany)
	{
		m_strCompany = strCompany;
	}
	const std::string& GetCompany() const
	{
		return m_strCompany;
	}
	void SetWorkTime(int nWorkTime)
	{
		m_nTime = nWorkTime;
	}
	const unsigned char GetWorkTime() const
	{
		return m_nTime;
	}
	CWorkExperience33Ptr* Clone()
	{
		CWorkExperience33Ptr* p = new CWorkExperience33Ptr(*this);
		return p;
	}
	void Print()
	{
		std::cout << "工作公司:" << m_strCompany << std::endl;
		std::cout << "工作时间:" << (int)m_nTime << "年" << std::endl;
	}


private:
	std::string m_strCompany;
	int m_nTime;
};


class CResume33Ptr : public ICloneable33Ptr<CResume33Ptr>
{
public:
	CResume33Ptr()
	{
		m_pWorkExperience = nullptr;
	}
	CResume33Ptr(CWorkExperience33Ptr* pWorkExperience)
	{
		m_pWorkExperience.reset(pWorkExperience);
	}
	CResume33Ptr(const CResume33Ptr& r)
	{
		m_strName = r.m_strName;
		m_btSex = r.m_btSex;
		m_btAge = r.m_btAge;
		m_pWorkExperience.reset(r.m_pWorkExperience->Clone());
	}
	~CResume33Ptr()
	{
		std::cout << "~CResume()" << std::endl;
	}
	void SetPersonInfo(const std::string& name, unsigned char sex, unsigned char age)
	{
		m_strName = name;
		m_btSex = sex;
		m_btAge = age;
	}
	void SetWorkExperience(const std::string& company, int workTime)
	{
		m_pWorkExperience->SetCompany(company);
		m_pWorkExperience->SetWorkTime(workTime);
	}
	CResume33Ptr* Clone()
	{
		CResume33Ptr* pResume = new CResume33Ptr(*this);
		return pResume;
	}
	void Print()
	{
		std::cout << "姓名:" << m_strName << std::endl;
		std::cout << "性别:" << ((m_btSex == 0) ? "女" : "男") << std::endl;
		std::cout << "年龄:" << (int)m_btAge << "岁" << std::endl;
		m_pWorkExperience->Print();
	}

protected:
	std::string m_strName;
	unsigned char m_btSex;
	unsigned char m_btAge;
	std::shared_ptr<CWorkExperience33Ptr> m_pWorkExperience;
};