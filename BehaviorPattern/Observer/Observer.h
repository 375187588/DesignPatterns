#pragma once
/*////////////////////////////////////////////////////
//说明：观察者模式类实例
//文件：Observer.h
//日期：2020/6/30
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//观察者
class CObserver;

using LLObservers = std::list<CObserver*>;

//主题对象
class CSubject
{
public:
	virtual ~CSubject()
	{
		delete m_pObserver;
		m_pObserver = nullptr;
	}
	CSubject()
	{
		m_pObserver = new LLObservers;
	}
	virtual void Attach(CObserver* obv)
	{
		m_pObserver->push_front(obv);
	}
	virtual void Detach(CObserver* obv)
	{
		if (m_pObserver != nullptr)
		{
			m_pObserver->remove(obv);
		}
	}
	virtual void Notify();
	virtual void SetMessage(char* pMsg) = 0;
	virtual char* GetMessage() const = 0;

private:
	LLObservers* m_pObserver;
};

class CSubject1 :public CSubject
{
public:
	CSubject1()
	{
		m_pMessage = nullptr;
	}
	~CSubject1() {}
	char* GetMessage() const
	{
		return m_pMessage;
	}
	void SetMessage(char* pMsg)
	{
		m_pMessage = pMsg;
	}

private:
	char* m_pMessage;
};

class CObserver
{
public:
	virtual ~CObserver() {}
	virtual void Update(CSubject* pSub) = 0;
	virtual void PrintInfo() = 0;

protected:
	CObserver() {}
	char* m_pMessage;
};

void CSubject::Notify()
{
	auto it = m_pObserver->begin();
	for (; it != m_pObserver->end(); it++)
	{
		(*it)->Update(this);
	}
}

class CObserver1 :public CObserver
{
public:
	virtual CSubject* GetSubject()
	{
		return m_pSubject;
	}
	CObserver1(CSubject* pSub)
	{
		m_pSubject = pSub;
		m_pSubject->Attach(this);
	}
	virtual ~CObserver1()
	{
		m_pSubject->Detach(this);
	}
	void Update(CSubject* pSub)
	{
		m_pMessage = pSub->GetMessage();
		PrintInfo();
	}
	void PrintInfo()
	{
		std::cout << "CObserver1 observer...." << m_pSubject->GetMessage() << std::endl;
	}
	void Release()
	{
		if (m_pSubject != nullptr)
		{
			delete m_pSubject;
		}
	}

private:
	CSubject* m_pSubject;
};

class CObserver2 :public CObserver
{
public:
	virtual CSubject* GetSubject()
	{
		return m_pSubject;
	}
	CObserver2(CSubject* pSub)
	{
		m_pSubject = pSub;
		m_pSubject->Attach(this);
	}
	virtual ~CObserver2()
	{
		m_pSubject->Detach(this);
	}
	void Update(CSubject* pSub)
	{
		m_pMessage = pSub->GetMessage();
		PrintInfo();
	}
	void PrintInfo()
	{
		std::cout << "CObserver2 observer....	" << m_pSubject->GetMessage() << std::endl;
	}
	void Release()
	{
		if (m_pSubject != nullptr)
		{
			delete m_pSubject;
		}
	}

private:
	CSubject* m_pSubject;
};

/////////////////////////////////////////////////////////////////
//实例2 C++用观察者模式实现MVC模式
struct IMessage
{
};
//检觉器
class IObservable;
//观察者
class IObserver
{
public:
	IObserver() {}
	virtual ~IObserver() {}
	virtual void Update(IObservable* pObservable, IMessage* pMessage) = 0;
};

//检觉器
class IObservable
{
public:
	IObservable() {}
	virtual ~IObservable() {}
	virtual void AddObserver(IObserver* pObserver) = 0;
	virtual void DeleteObserver(IObserver* pObserver) = 0;
	virtual void NotifyUpdate() = 0;
	virtual void NotifyUpdate(IMessage* pMessage) = 0;
};

class CBaseModels;
class IViewAction
{
public:
	IViewAction() {}
	virtual ~IViewAction() {}
	virtual void RefreshView(CBaseModels* pBaseModel, IMessage* pMessage) = 0;

};

//通知模型接口
class IModelAction
{
public:
	IModelAction() {}
	virtual ~IModelAction() {}
	virtual void RequestData() = 0;
};

using LObservers = std::list<IObserver*>;

//模型实现
class CBaseModels : public IObservable, IModelAction
{
public:
	CBaseModels()
	{
		m_pObserversList = new LObservers;
	}
	~CBaseModels()
	{
		delete m_pObserversList;
		m_pObserversList = nullptr;
	}
	//添加观察者
	void AddObserver(IObserver* pObserver)
	{
		if (m_pObserversList == nullptr)
		{
			return;
		}
		m_pObserversList->push_back(pObserver);
	}

	void DeleteObserver(IObserver* pObserver)
	{
		if (m_pObserversList == nullptr ||
			m_pObserversList->size() == 0)
		{
			return;
		}
		m_pObserversList->remove(pObserver);
	}

	void NotifyUpdate()
	{
		NotifyUpdate(nullptr);
	}

	void NotifyUpdate(IMessage* pMessage)
	{

		if (m_pObserversList == nullptr ||
			m_pObserversList->size() == 0)
		{
			return;
		}

		auto it = m_pObserversList->begin();
		for (; it != m_pObserversList->end(); it++)
		{
			(*it)->Update(this, pMessage);
		}
	}

	bool IsChanged()
	{
		return m_bChanged;
	}

	void SetChanged(bool bChanged)
	{
		this->m_bChanged = bChanged;
	}

private:
	LObservers* m_pObserversList;
	bool m_bChanged;
};


struct ModelMessage : public IMessage
{
	std::string strName;
	std::string strAddr;
};

//模型
class Model :public CBaseModels
{
public:
	std::string GetName()
	{
		return m_strName;
	}
	void SetName(std::string strName)
	{
		this->m_strName = strName;
	}	
	void SetAddr(std::string strAddr)
	{
		this->m_strAddr = strAddr;
	}
	std::string GetAddr()
	{
		return m_strAddr;
	}

	void RequestData()
	{
		// 模拟Model更新
		m_strName = "高宣帅";
		m_strAddr = "人民南路";

		m_message.strName = "白富美";
		m_message.strAddr = "富贵街";

		std::cout << "Model发生了改变，通知View更新" << std::endl;
		//设置改变
		SetChanged(true);
		NotifyUpdate((ModelMessage*)(&m_message));
	}

private:
	std::string m_strName;// 名字
	std::string m_strAddr;// 地址
	ModelMessage m_message;
};

class CBaseViews;
//控制器
class CController
{
public:
	CController(CBaseViews* pView)
	{
		this->m_pView = pView;
		m_pModel = new Model();
		// 将m_pView与m_pModel绑定
		m_pModel->AddObserver((IObserver*)pView);
	}
	~CController()
	{
		delete m_pModel;
		m_pModel = nullptr;
	}

	void DoNotifyMessage()
	{
		std::cout << "Controller响应View的界面操作事件，通知Model更新" << std::endl;
		((Model*)m_pModel)->RequestData();
	}

private:
	CBaseViews* m_pView;
	CBaseModels* m_pModel;
};

//视图
class CBaseViews : public IObserver, IViewAction
{
public:
	CBaseViews()
	{
		this->m_pController = new CController(this);
	}
	virtual ~CBaseViews()
	{
		delete m_pController;
		m_pController = nullptr;
	}
	void Update(IObservable* pObservable, IMessage* pMessage)
	{
		CBaseModels* pBaseModel = (CBaseModels*)pObservable;
		if (pBaseModel->IsChanged())
		{
			RefreshView(pBaseModel, pMessage);
		}
	}

protected:
	CController* m_pController;// 控制器
};

//视图
class CView :public CBaseViews
{
public:
	void DoTouchEvent()
	{
		std::cout << "模拟事件传给Controller处理" << std::endl;
		// 将事件传给Controller处理
		m_pController->DoNotifyMessage();
	}

	//刷新界面
	void RefreshView(CBaseModels* pBaseModel, IMessage* pMessage)
	{
		std::cout << std::endl << std::endl;
		std::cout << "收到Model发来的通知数据，更新界面" << std::endl;
		ModelMessage* p = (ModelMessage*)pMessage;
		Model* m_pModel = (Model*)pBaseModel;
		std::string strName = m_pModel->GetName();
		std::string  strAddr = m_pModel->GetAddr();
		std::cout << "住在:" <<
			p->strAddr <<
			"的:" <<
			p->strName <<
			" 约住在:" <<
			strAddr <<
			"的 名字：" <<
			strName <<
			"去看电影!" <<
			std::endl;
	}
};