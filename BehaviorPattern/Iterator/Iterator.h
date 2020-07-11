#pragma once
/*////////////////////////////////////////////////////
//说明：迭代器模式类实例
//文件：Iterator.h
//日期：2020/7/1
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//数据抽象
struct DATA
{
	DATA() {}
	virtual ~DATA() {}
};

class CIterator;

// 容器聚集的抽象基类
class CAggregate
{
public:
	virtual ~CAggregate() {}

	virtual CIterator* CreateIterator(CAggregate *pAggregate) = 0;
	virtual int GetSize() = 0;
	virtual DATA* GetItem(int nIndex) = 0;
	virtual void Add(DATA* pData,int nIndex) = 0;
};

// 迭代器的抽象基类
class CIterator
{
public:
	virtual ~CIterator() {}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual DATA* CurrentItem() = 0;
};

// 访问CConcreateAggregate容器类的迭代器类
class CConcreateIterater	: public CIterator
{
public:
	CConcreateIterater(CAggregate* pAggregate) :
		m_pAggregate(pAggregate),
		m_nIndex(0)
	{

	}
	virtual ~CConcreateIterater()
	{
	}
	virtual void First()
	{
		m_nIndex = 0;
	}
	virtual void Next()
	{
		if (m_nIndex < m_pAggregate->GetSize())
		{
			++m_nIndex;
		}
	}
	virtual bool IsDone()
	{
		return m_nIndex == m_pAggregate->GetSize();
	}
	virtual DATA* CurrentItem()
	{
		return m_pAggregate->GetItem(m_nIndex);
	}

private:
	CAggregate* m_pAggregate;
	int m_nIndex;
};

// 具体的容器类,用数组实现
// 可以用链表，Hash表来实现
class CConcreateAggregate : public CAggregate
{
public:
	CConcreateAggregate(int nSize):
		m_nSize(nSize),
		m_pData(NULL)
	{
		m_pData = new DATA*[m_nSize];
		int i = 0;
		while(i < m_nSize)
		{
			m_pData[i] = nullptr;
			++i;
		}
	}
	virtual ~CConcreateAggregate()
	{
		int i = 0;
		while(i < m_nSize)
		{
			delete m_pData[i];
			m_pData[i] = nullptr;
			++i;
		}
		delete[] m_pData;
		m_pData = nullptr;
	}

	virtual CIterator* CreateIterator(CAggregate *pAggregate)
	{
		return new CConcreateIterater(this);
	}
	virtual int GetSize()
	{
		return m_nSize;
	}
	virtual DATA* GetItem(int nIndex)
	{
		if (nIndex < m_nSize)
		{
			return m_pData[nIndex];
		}
		return nullptr;
	}
	virtual void Add(DATA* pData, int nIndex)
	{
		assert(nIndex >= 0);
		assert(nIndex < m_nSize);
		m_pData[nIndex] = pData;
	}

private:
	int m_nSize;
	DATA* *m_pData;
};

