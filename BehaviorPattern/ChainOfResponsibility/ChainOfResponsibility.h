#pragma once
/*////////////////////////////////////////////////////
//说明：责任链模式实例
//文件：ChainOfResponsibility.h
//日期：2020/7/1
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

// 抽象基类,定义一个处理请求的接口
class CHandler
{
public:
	CHandler(CHandler *pHandler = nullptr) :
		m_pHandler(pHandler)
	{
	}
	virtual ~CHandler()
	{
		delete m_pHandler;
		m_pHandler = nullptr;
	}
	void SetHandler(CHandler* pHandler)
	{
		m_pHandler = pHandler;
	}
	CHandler* GetHandler() const
	{
		return m_pHandler;
	}
	// 纯虚函数,由派生类实现
	virtual void Request() = 0;

protected:
	CHandler* m_pHandler;
};

class CConcreateHandler1 : public CHandler
{
public:
	CConcreateHandler1(CHandler *pHandler = nullptr):
		CHandler(pHandler)
	{
	}
	virtual ~CConcreateHandler1()
	{
	}
	virtual void Request()
	{
		if (NULL != m_pHandler)
		{
			std::cout << "我将CConcreateHandler1处理权给后继节点....."<<std::endl;
			m_pHandler->Request();
		}
		else
		{
			std::cout << "CConcreateHandler1 没有后继了，我必须自己处理\n";
		}
	}
};

class CConcreateHandler2	: public CHandler
{
public:
	CConcreateHandler2(CHandler *pHandler = nullptr) :
		CHandler(pHandler)
	{
	}
	virtual ~CConcreateHandler2()
	{
	}
	virtual void Request()
	{
		if (NULL != m_pHandler)
		{
			std::cout << "我将CConcreateHandler2处理权给后继节点....." << std::endl;
			m_pHandler->Request();
		}
		else
		{
			std::cout << "CConcreateHandler2 没有后继了，我必须自己处理\n";
		}
	}
};


class CConcreateHandler3 : public CHandler
{
public:
	CConcreateHandler3(CHandler *pHandler = nullptr) :
		CHandler(pHandler)
	{
	}
	virtual ~CConcreateHandler3()
	{
	}
	virtual void Request()
	{
		if (NULL != m_pHandler)
		{
			std::cout << "我将CConcreateHandler3处理权给后继节点....." << std::endl;
			m_pHandler->Request();
		}
		else
		{
			std::cout << "CConcreateHandler3 没有后继了，我必须自己处理\n";
		}
	}
};
