#pragma once
/*////////////////////////////////////////////////////
//˵��������ģʽ��ʵ��
//�ļ���Strategy.h
//���ڣ�2020/6/30
//���ߣ�coder
//QQ��375187588
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

//�������
class CStrategy
{
public:
	CStrategy() {}
	virtual ~CStrategy() {}

	virtual int DoOperator(int nNum1, int nNum2) = 0;
};

//�㷨��ʵ��
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

//�㷨��ʵ��
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

//�㷨��ʵ��
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

//�㷨��ʵ��
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