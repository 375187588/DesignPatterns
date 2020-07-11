#pragma once
/*////////////////////////////////////////////////////
//说明：状态模式实例
//文件：State.h
//日期：2020/7/1
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//上下文 前置申明
class CContext;
class CState
{
public:
	CState() {}
	virtual ~CState(){}

	virtual void OpInterface(CContext* pContext) = 0;
	virtual void OpChangeState(CContext* pContext) = 0;
	bool ChangeState(CContext* pContext, CState* pState);
};

class CState2;
//状态1
class CState1 :public CState
{
public:
	void OpInterface(CContext* pContext)
	{
		std::cout << "CState1 OpInterface!" << std::endl;
	}
	void OpChangeState(CContext* pContext);
};

//状态3
class CState3 :public CState
{
public:
	void OpInterface(CContext* pContext)
	{
		std::cout << "CState3 OpInterface!" << std::endl;
	}
	void OpChangeState(CContext* pContext)
	{
		OpInterface(pContext);
		this->ChangeState(pContext, new CState1);
	}
};

//状态2
class CState2 :public CState
{
public:
	void OpInterface(CContext* pContext)
	{
		std::cout << "CState2 OpInterface!" << std::endl;
	}
	void OpChangeState(CContext* pContext)
	{
		OpInterface(pContext);
		this->ChangeState(pContext, new CState3);
	}
};

void CState1::OpChangeState(CContext* pContext)
{
	OpInterface(pContext);
	this->ChangeState(pContext, new CState2);
}

//上下文
class CContext
{
public:
	CContext() {}
	virtual ~CContext() 
	{
		delete m_pState;
		m_pState = nullptr;
	}

	CContext(CState* pState):
		m_pState(pState)
	{
	}
	void OpInterface()
	{
		m_pState->OpInterface(this);
	}
	void OpChangeState()
	{
		m_pState->OpChangeState(this);
	}

private:
	//CState类可以访问CContext的成员
	friend class CState;
	bool ChangeState(CState* pState)
	{
		if (m_pState)
		{
			delete m_pState;
			m_pState = nullptr;
		}
		m_pState = pState;
		return true;
	}
	CState* m_pState;
};

bool CState::ChangeState(CContext* pContext, CState* pState)
{
	//可以访问CContext类中的私有方法ChangeState
	return pContext->ChangeState(pState);
}