#pragma once
#include "Factory.h"
//符合开放-封闭原则

//组成车的引擎
class CEngine
{
public:
	CEngine()
	{
		std::cout << "组装引擎 !" << std::endl;
	}
	~CEngine()
	{
		std::cout << "析构引擎 !" << std::endl;
	}
};

//组成车的底盘
class CChassis
{
public:
	CChassis()
	{
		std::cout << "组装底盘 !" << std::endl;
	}
	~CChassis()
	{
		std::cout << "析构底盘 !" << std::endl;
	}
};

//组成车的轮子
class CWheel
{
public:
	CWheel()
	{
		std::cout << "组装轮子 !" << std::endl;
	}
	~CWheel()
	{
		std::cout << "析构轮子 !" << std::endl;
	}
};

class IBaseCar
{
public:
	virtual void Create() = 0;
	virtual ~IBaseCar() {};
};	

//组装车
class CCar : public IBaseCar
{
public:
	CCar(CEngine* pEngine, CChassis* pChassis, CWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	virtual ~CCar()
	{
		std::cout << "CCar 析构了!" << std::endl;
	}
	void Create()
	{
		std::cout << "CCar由引擎，底盘，轮子组合而成!" << std::endl;
	}

private:
	std::shared_ptr<CEngine> m_pEngine;
	std::shared_ptr<CChassis> m_pChassis;
	std::shared_ptr<CWheel> m_pWheel;
};

class IFactor
{
public:
	virtual IBaseCar* Create() = 0;
};

class CCarFactor : public IFactor
{
public:
	IBaseCar* Create()
	{
		return new CCar(new CEngine, new CChassis, new CWheel);
	}
};

//工厂方法模式只能创建一种产品


//抽象工厂模式可以产生一系列产品
//产务车
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

class CBMWBusinessCar : public IBusinessCarBase
{
public:
	CBMWBusinessCar(){}
	~CBMWBusinessCar() { std::cout << "CBMWBusinessCar 析构了!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWBusinessCar创建！" << std::endl;
	}
};

class CBMWCivilCar : public ICivilCarBase

{
public:
	CBMWCivilCar() {}
	~CBMWCivilCar() {}

	void Create()
	{
		std::cout << "CBMWCivilCar创建！" << std::endl;
	}
};

class CBMWSportCar : public ISportCarBase
{
public:
	CBMWSportCar() {}
	~CBMWSportCar() {}

	void Create()
	{
		std::cout << "CBMWSportCar创建！" << std::endl;
	}
};

class CBenzBusinessCar : public IBusinessCarBase
{
public:
	CBenzBusinessCar() {}
	void Create()
	{
		std::cout << "CBenzBusinessCar创建！" << std::endl;
	}
	~CBenzBusinessCar() {}
};

class CBenzCivilCar : public ICivilCarBase

{
public:
	CBenzCivilCar() {}
	~CBenzCivilCar() {}

	void Create()
	{
		std::cout << "CBenzCivilCar创建！" << std::endl;
	}
};

class CBenzSportCar : public ISportCarBase
{
public:
	CBenzSportCar() {}
	~CBenzSportCar() {}

	void Create()
	{
		std::cout << "CBenzSportCar创建！" << std::endl;
	}
};

class IAbstractFactor
{
public:
	virtual IBusinessCarBase* CreateBusinessCar() = 0;
	virtual ICivilCarBase* CreateCivilCar() = 0;
	virtual ISportCarBase* CreateSportCar() = 0;
};

class CBMWFactor : public IAbstractFactor
{
public:
	IBusinessCarBase* CreateBusinessCar()
	{
		return new CBMWBusinessCar();
	}
	ICivilCarBase* CreateCivilCar()
	{
		return new CBMWCivilCar();
	}
	ISportCarBase* CreateSportCar()
	{
		return new CBMWSportCar();
	}
	~CBMWFactor()
	{
		std::cout << "CBMWFactor 析构!" << std::endl;
	}
};

class CBenzFactor : public IAbstractFactor
{
public:
	~CBenzFactor()
	{
		std::cout << "CBenzFactor 析构!" << std::endl;
	}
	IBusinessCarBase* CreateBusinessCar()
	{
		return new CBenzBusinessCar();
	}
	ICivilCarBase* CreateCivilCar()
	{
		return new CBenzCivilCar();
	}
	ISportCarBase* CreateSportCar()
	{
		return new CBenzSportCar();
	}
};
/*---------------------------------------
IAbstractFactor						-	返回 依赖		IBusinessCarBase
-+CreateBusinessCar():IBusinessCarBase	- - - - - ->	+Create():void
-										-
-+CreateCivilCar():ICivilCarBasei		-返回 依赖		ICivilCarBase
-										- - - - - ->	+Create():void
--										-
-										-返回 依赖		ISportCarBase
-+CreateSportCar():ISportCarBase		-- - - - - ->	+Create():void
----------------------------------------

*/