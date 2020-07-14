#pragma once
/*////////////////////////////////////////////////////
//说明：策略模式类实例
//文件：Strategy.h
//日期：2020/6/30
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//定义策略
class CStrategy
{
public:
	CStrategy() {}
	virtual ~CStrategy() {}

	virtual int DoOperator(int nNum1, int nNum2) = 0;
};

//算法加实现
class CAdd : public CStrategy
{
public:
	CAdd() {}
	~CAdd() {}

public:
	int DoOperator(int nNum1, int nNum2)
	{
		return nNum1 + nNum2;
	}
};

//算法减实现
class CSub : public CStrategy
{
public:
	CSub() {}
	~CSub() {}

public:
	int DoOperator(int nNum1, int nNum2)
	{
		return nNum1 - nNum2;
	}
};

//算法乘实现
class CMul : public CStrategy
{
public:
	CMul() {}
	~CMul() {}

public:
	int DoOperator(int nNum1, int nNum2)
	{
		return nNum1 * nNum2;
	}
};

//算法除实现
class CDiv : public CStrategy
{
public:
	CDiv() {}
	~CDiv() {}

public:
	int DoOperator(int nNum1, int nNum2)
	{
		return nNum1 / nNum2;
	}
};

class CContext
{
public:
	CContext(CStrategy* p) :
		m_pStrategy(p)
	{

	}
	~CContext()
	{
		delete m_pStrategy;
		m_pStrategy = nullptr;
	}

	int DoOperator(int nNum1, int nNum2)
	{
		return m_pStrategy->DoOperator(nNum1, nNum2);
	}

private:
	CStrategy* m_pStrategy;
};