#pragma once
/*////////////////////////////////////////////////////
//˵������Ԫģʽ��ʵ��
//�ļ���Flyweight.h
//���ڣ�2020/6/30
//���ߣ�coder
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

class CFlyweight
{
public:
	CFlyweight(const std::string& strKey):
		m_strKey(strKey)
	{
	}
	virtual ~CFlyweight(){}
	virtual void Operation(const std::string& strKey) = 0;
	std::string GetKey() const { return m_strKey; }

private:
	std::string m_strKey;
};

class CConcreateFlyweight : public CFlyweight
{
public:
	CConcreateFlyweight(const std::string &strKey):
		CFlyweight(strKey)
	{
	}
	~CConcreateFlyweight() {}

	void Operation(const std::string& strKey)
	{
		std::cout << "CConcreateFlyweight " << strKey << std::endl;
	}
};

using MFlyweight = std::map<std::string, CFlyweight*>;

class CFlyweightFactory
{
public:
	CFlyweightFactory() {}
	~CFlyweightFactory() 
	{
		Release();
	}

	CFlyweight* GetFlyweight(const std::string& strKey)
	{
		auto it = m_weights.find(strKey);
		if (it != m_weights.end())
		{
			return it->second;
		}

		CFlyweight* pFlyweight = new CConcreateFlyweight(strKey);
		if (pFlyweight == nullptr)
		{
			return nullptr;
		}

		m_weights.insert(std::make_pair(strKey, pFlyweight));
		return pFlyweight;
	}

private:
	void Release()
	{
		for (auto it : m_weights)
		{
			delete it.second;
			it.second = nullptr;
		}
		m_weights.clear();
	}
	
private:
	MFlyweight m_weights;
};