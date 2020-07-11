#pragma once
/*////////////////////////////////////////////////////
//说明：命令模式实例
//文件：Command.h
//日期：2020/7/1
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

struct IControlLamp
{
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};

//客厅灯
class CParlourLamp : public IControlLamp
{
public:
	CParlourLamp() {}
	~CParlourLamp() {}

	void TurnOn()
	{
		std::cout << "客厅灯亮了!" << std::endl;
	}

	void TurnOff()
	{
		std::cout << "客厅灯关了!" << std::endl;
	}
};

//命令接口
class ICommand
{
public:
	ICommand() {}
	virtual ~ICommand() {}
	virtual void Do() {};
	virtual void UnDo() {};
};

//开灯命令
class CTrunOnCommand : public ICommand
{
public:
	CTrunOnCommand(IControlLamp* pLamp):
		m_pLamp(pLamp)
	{
	}
	~CTrunOnCommand() {}

	void Do()
	{
		m_pLamp->TurnOn();
	}

	void UnDo()
	{
		m_pLamp->TurnOff();
	}
	

private:
	IControlLamp* m_pLamp;
};

//关灯命令
class CTrunOffCommand : public ICommand
{
public:
	CTrunOffCommand(IControlLamp* pLamp) :
		m_pLamp(pLamp)
	{
	}
	~CTrunOffCommand() {}

	void Do()
	{
		m_pLamp->TurnOff();
	}

	void UnDo()
	{
		m_pLamp->TurnOn();
	}


private:
	IControlLamp* m_pLamp;
};

///调用器
class CInvoker
{
public:
	CInvoker(int nNumber)
	{
		m_nNumber = nNumber;
		m_pOnCommands = new ICommand*[nNumber];
		m_pOffCommands = new ICommand*[nNumber];
	}
	~CInvoker() 
	{
		delete[]m_pOnCommands;
		delete[]m_pOffCommands;
	}

	void SetCommand(int nSlot, ICommand* pOn, ICommand* pOff)
	{
		m_pOnCommands[nSlot] = pOn;
		m_pOffCommands[nSlot] = pOff;
	}

	void OnPressOn(int nSlot)
	{
		m_pOnCommands[nSlot]->Do();
		m_pUnDoCommand = m_pOnCommands[nSlot];
	}

	void OnPressOff(int nSlot)
	{
		m_pOffCommands[nSlot]->Do();
		m_pUnDoCommand = m_pOffCommands[nSlot];
	}

	void OnPressUnDo()
	{
		m_pUnDoCommand->UnDo();
	}

private:
	ICommand** m_pOnCommands;
	ICommand** m_pOffCommands;
	ICommand* m_pUnDoCommand;
	int m_nNumber;
};
