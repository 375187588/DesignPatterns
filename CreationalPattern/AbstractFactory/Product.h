#pragma once
/*////////////////////////////////////////////////////
//说明：抽象产品和具体产品对象类
//文件：Product.h
//日期：2020/6/23
//作者：coder
//QQ：375187588
//修改：2020/6/30
//版本：
*//////////////////////////////////////////////////////


//抽象工厂模式可以产生一系列产品
//商务车
class IBusinessCarBase
{
public:
	IBusinessCarBase() {}
	virtual~IBusinessCarBase() {}
	virtual void Create() = 0;
};

//民用车
class ICivilCarBase
{
public:
	ICivilCarBase() {}
	virtual~ICivilCarBase() {}
	virtual void Create() = 0;
};

//跑车
class ISportCarBase
{
public:
	ISportCarBase() {}
	virtual~ISportCarBase() {}
	virtual void Create() = 0;
};

class IEngine
{
public:
	virtual void Create() = 0;
	virtual ~IEngine() {};
};

class IChassis
{
public:
	IChassis() {}
	virtual void Create() = 0;	
	virtual ~IChassis() {};
};

class IWheel
{
public:
	virtual void Create() = 0;
	IWheel() {}
	virtual ~IWheel() {};
};


class CBMWEngine : public IEngine
{
public:
	CBMWEngine() {}
	~CBMWEngine() {}
	void Create()
	{
		std::cout << "CBMWEngine!" << std::endl;
	}
};

class CBMWChassis : public IChassis
{
public:
	CBMWChassis() {}
	~CBMWChassis() {}
	void Create()
	{
		std::cout << "CBMWChassis!" << std::endl;
	}
};

class CBMWWheel : public IWheel
{
public:
	CBMWWheel() {}
	~CBMWWheel() {}
	void Create()
	{
		std::cout << "CBMWWheel!" << std::endl;
	}
};

class CBenzEngine : public IEngine
{
public:
	CBenzEngine() {}
	~CBenzEngine() {}
	void Create()
	{
		std::cout << "CBenzEngine!" << std::endl;
	}
};

class CBenzChassis : public IChassis
{
public:
	CBenzChassis() {}
	~CBenzChassis() {}
	void Create()
	{
		std::cout << "CBenzChassis!" << std::endl;
	}
};

class CBenzWheel : public IWheel
{
public:
	CBenzWheel() {}
	~CBenzWheel() {}
	void Create()
	{
		std::cout << "CBenzWheel!" << std::endl;
	}
};

class CBMWBusinessCar : public IBusinessCarBase
{
public:
	CBMWBusinessCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBMWBusinessCar() { std::cout << "CBMWBusinessCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWBusinessCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBMWBusinessCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBMWCivilCar : public ICivilCarBase
{
public:
	CBMWCivilCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBMWCivilCar() { std::cout << "CBMWCivilCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWCivilCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBMWCivilCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBMWSportCar : public ISportCarBase
{
public:
	CBMWSportCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBMWSportCar() { std::cout << "CBMWSportCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWSportCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBMWSportCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBenzBusinessCar : public IBusinessCarBase
{
public:
	CBenzBusinessCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzBusinessCar() { std::cout << "CBenzBusinessCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzBusinessCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzBusinessCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBenzCivilCar : public ICivilCarBase
{
public:
	CBenzCivilCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzCivilCar() { std::cout << "CBenzCivilCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzCivilCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzCivilCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBenzSportCar : public ISportCarBase
{
public:
	CBenzSportCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzSportCar() { std::cout << "CBenzSportCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzSportCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzSportCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

///-------------------------------------------------------------------
//增加一种新的车型 房车 //////////////////////////////////////////////
//跑车
class IRoomCarBase
{
public:
	IRoomCarBase() {}
	virtual~IRoomCarBase() {}
	virtual void Create() = 0;
};

class CBenzRoomCar : public IRoomCarBase
{
public:
	CBenzRoomCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzRoomCar() { std::cout << "CBenzRoomCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzRoomCar开始生产！" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzRoomCar生产成功！" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};
