#pragma once
#include <string>
/*////////////////////////////////////////////////////
//说明：创建者模式类
//文件：Produce.h
//日期：2020/6/23
//作者：coder
//QQ：375187588
//修改：2020/6/30
//版本：
*//////////////////////////////////////////////////////

class CCar
{
public:
	void SetManufacturer(const std::string& strManufacturer)
	{
		m_strManufacturer = strManufacturer;
	}
	const std::string& GetManufacturer() const
	{
		return m_strManufacturer;
	}
	void SetChassis(const std::string& strChassis)
	{
		m_strChassis = strChassis;
	}
	const std::string& GetChassis() const
	{
		return m_strChassis;
	}
	void SetWheel(const std::string& strWheel)
	{
		m_strWheel = strWheel;
	}
	const std::string& GetWheel() const
	{
		return m_strWheel;
	}
	void SetEngine(const std::string& strEngine)
	{
		m_strEngine = strEngine;
	}
	const std::string& GetEngine() const
	{
		return m_strEngine;
	}
	void Print()
	{
		std::cout << "生产厂商:" << m_strManufacturer << std::endl;
		std::cout << "底盘:" << m_strChassis << std::endl;
		std::cout << "轮子:" << m_strWheel << std::endl;
		std::cout << "发动机:" << m_strEngine << std::endl;		
	}

private:
	std::string m_strManufacturer;//生产厂商
	std::string m_strEngine;//发动机
	std::string m_strChassis;//底盘
	std::string m_strWheel;//轮子
};

class CCarBuilderBase
{
public:
	CCar* Build()
	{
		BuildManufacturer();
		BuildChassis();
		BuildWheel();
		BuildEngine();
		return &m_car;
	}

protected:
	virtual void BuildManufacturer() = 0;
	virtual void BuildChassis() = 0;
	virtual void BuildWheel() = 0;
	virtual void BuildEngine() = 0;		
	CCar m_car;
};

class CBenzCar : public CCarBuilderBase
{
protected:
	void BuildManufacturer()
	{
		m_car.SetManufacturer("北京奔驰公司\n");
	}
	void BuildChassis()
	{
		m_car.SetChassis("进口德国奔驰底盘\n");
	}
	void BuildWheel()
	{
		m_car.SetWheel("进口德国奔驰轮胎\n");
	}
	void BuildEngine()
	{
		m_car.SetEngine("进口德国奔驰引擎\n");
	}
};

class CBMWCar : public CCarBuilderBase
{
protected:
	void BuildManufacturer()
	{
		m_car.SetManufacturer("德国宝马公司\n");
	}
	void BuildChassis()
	{
		m_car.SetChassis("进口德国宝马底盘\n");
	}
	void BuildWheel()
	{
		m_car.SetWheel("进口德国宝马轮胎\n");
	}
	void BuildEngine()
	{
		m_car.SetEngine("进口德国宝马引擎\n");
	}
};

//工厂模式不考虑组装的过程，而是直接生成一个我想要的对象 解决的是：工厂生产新产品
//创建者模式先创建每个部件，在统一组装成一个对象 工厂控制产品生成器组装各个部件的过程，然后从新产品生成器中得到产品