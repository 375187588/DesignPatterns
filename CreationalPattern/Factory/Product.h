#pragma once

#include "Factory.h"

/*////////////////////////////////////////////////////
//说明：简单工厂要生产的产品
//文件：Product.h
//日期：2020/6/23
//作者: coder
//QQ: 375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//符合开放-封闭原则
//工厂方法模式只能创建一种产品
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
