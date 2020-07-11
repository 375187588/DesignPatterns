#pragma once
/*////////////////////////////////////////////////////
//说明：中介者模式实例
//文件：Mediator.h
//日期：2020/7/1
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////


struct Message
{
};

class CHouseMediator;
//房东抽象
class CHouseOwner
{
public:
	CHouseOwner() {}
	virtual ~CHouseOwner() {}
	virtual void Action() = 0;
	virtual void SetMessage(Message* pMessage) = 0;
	virtual Message* GetMessage() const = 0;

protected:
	CHouseOwner(CHouseMediator* pMediator)
	{
		m_pMediator = pMediator;
	}

protected:
	CHouseMediator* m_pMediator;
};

//房屋中介抽象
class CHouseMediator
{
public:
	virtual ~CHouseMediator(){}
	CHouseMediator() {}
	virtual void DoActionFrom1to2() = 0;
	virtual void DoActionFrom2to1() = 0;
};

//提交房源消息
struct RequestMessage : public Message
{
	std::string strName;
	std::string strContext;
};

//房东高富帅
class CHouseOwner1 : public CHouseOwner
{
public:
	CHouseOwner1() {};
	CHouseOwner1(CHouseMediator* pMediator):
		CHouseOwner(pMediator)
	{		
	}
	~CHouseOwner1()
	{
	}
	void Action()
	{
		//m_pMediator->DoActionFrom1to2();
		RequestMessage* pMessage = (RequestMessage*)m_pMessage;
		std::cout << "CHouseOwner1's state:" << pMessage->strName.c_str() << ":" << pMessage->strContext.c_str() << std::endl;
	}
	void SetMessage(Message* pMessage)
	{
		m_pMessage = pMessage;
	}
	Message* GetMessage() const
	{
		return m_pMessage;
	}

private:
	Message* m_pMessage;
};

//房东白富美
class CHouseOwner2 : public CHouseOwner
{
public:
	CHouseOwner2() {};
	CHouseOwner2(CHouseMediator* pMediator) :
		CHouseOwner(pMediator)
	{
	}
	~CHouseOwner2()
	{
	}
	void Action()
	{
		//m_pMediator->DoActionFrom2to1();
		RequestMessage* pMessage = (RequestMessage*)GetMessage();
		std::cout << "CHouseOwner2's state:" << pMessage->strName.c_str() << ":" << pMessage->strContext.c_str() << std::endl;
	}
	void SetMessage(Message* pMessage)
	{
		m_pMessage = pMessage;
	}
	Message* GetMessage() const
	{
		return m_pMessage;
	}

private:
	Message* m_pMessage;
};

//房屋中介者
class CHouseMediator1 :public CHouseMediator
{
public:
	CHouseMediator1(){}
	CHouseMediator1(CHouseOwner* pHouseOwner1, CHouseOwner* pHouseOwner2)
	{
		m_pHouseOwner1 = pHouseOwner1;
		m_pHouseOwner2 = pHouseOwner2;
	}
	void SetHouseOwner1(CHouseOwner* pHouseOwner1)
	{
		m_pHouseOwner1 = m_pHouseOwner1;
	}
	void SetHouseOwner2(CHouseOwner* pHouseOwner2)
	{
		m_pHouseOwner2 = pHouseOwner2;
	}
	CHouseOwner* GetHouseOwner1()
	{
		return m_pHouseOwner1;
	}
	CHouseOwner* GetHouseOwner2()
	{
		return m_pHouseOwner2;
	}
	void IntroHouseOwner(CHouseOwner* pHouseOwner1, CHouseOwner* pHouseOwner2)
	{
		m_pHouseOwner1 = pHouseOwner1;
		m_pHouseOwner2 = pHouseOwner2;
	}
	void DoActionFrom1to2()
	{
		RequestMessage* pMessage = new RequestMessage();
		pMessage->strName = "高富帅";
		pMessage->strContext = "租350平，独门独栋别墅一套";
		m_pHouseOwner2->SetMessage(pMessage);
	}
	void DoActionFrom2to1()
	{
		RequestMessage* pMessage = new RequestMessage();
		pMessage->strName = "白富美";
		pMessage->strContext = "租700平，独门独栋小高层别墅一套";
		m_pHouseOwner1->SetMessage(pMessage);
	}
private:
	CHouseOwner* m_pHouseOwner1;
	CHouseOwner* m_pHouseOwner2;
};