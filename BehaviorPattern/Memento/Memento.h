#pragma once
/*/////////////////////////////////////////////////
//说明：备忘录模式实例
//文件：Memento.h
//日期：2020/7/1
//作者：coder
//QQ:375187588
//修改:
//版本:
*//////////////////////////////////////////////////

typedef std::string State;

class CMemento;

class COriginator
{
public:
	COriginator(const State& rState) :
		m_State(rState)
	{
	}
	COriginator()
	{
	}
	~COriginator()
	{
	}

	State GetState()
	{
		return m_State;
	}
	void SetState(const State& rState)
	{
		m_State = rState;
	}
	CMemento* CreateMemento();
	void SetMemento(CMemento* pMemento)
	{

	}
	void RestoreState(CMemento* pMemento);
	void PrintState()
	{
		std::cout << "State = " << m_State << std::endl;
	}

private:
	State m_State;
};

// 把CMemento的接口函数都设置为私有的,而COriginator是它的友元,
// 这样保证了只有COriginator可以对其访问
class CMemento
{
private:
	friend class COriginator;
	CMemento(const State& rState) :
		m_State(rState)
	{

	}
	void SetState(const State& rState)
	{
		m_State = rState;
	}
	State GetState()
	{
		return m_State;
	}

	State m_State;
};

CMemento* COriginator::CreateMemento()
{
	return new CMemento(m_State);
}

void COriginator::RestoreState(CMemento* pMemento)
{
	if (NULL != pMemento)
	{
		m_State = pMemento->GetState();
	}
}