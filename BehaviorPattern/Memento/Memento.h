#pragma once
/*/////////////////////////////////////////////////
//˵��������¼ģʽʵ��
//�ļ���Memento.h
//���ڣ�2020/7/1
//���ߣ�coder
//QQ:375187588
//�޸�:
//�汾:
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

// ��CMemento�Ľӿں���������Ϊ˽�е�,��COriginator��������Ԫ,
// ������֤��ֻ��COriginator���Զ������
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