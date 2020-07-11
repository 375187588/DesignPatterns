#pragma once
#include "Product.h"
/*////////////////////////////////////////////////////
//说明：抽象工厂模式类
//文件：Factory.h
//日期：2020/6/23
//作者：coder
//QQ：375187588
//修改：2020/6/30
//版本：
*//////////////////////////////////////////////////////

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
		return new CBMWBusinessCar(new CBMWEngine, new CBMWChassis, new CBMWWheel);
	}
	ICivilCarBase* CreateCivilCar()
	{
		return new CBMWCivilCar(new CBMWEngine, new CBMWChassis, new CBMWWheel);
	}
	ISportCarBase* CreateSportCar()
	{
		return new CBMWSportCar(new CBMWEngine, new CBMWChassis, new CBMWWheel);
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
		return new CBenzBusinessCar(new CBenzEngine, new CBenzChassis, new CBenzWheel);
	}
	ICivilCarBase* CreateCivilCar()
	{
		return new CBenzCivilCar(new CBenzEngine, new CBenzChassis, new CBenzWheel);
	}
	ISportCarBase* CreateSportCar()
	{
		return new CBenzSportCar(new CBenzEngine, new CBenzChassis, new CBenzWheel);
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


///////////////////////////////////////////////////////////////////
//增加一种房车生产车间
class IAbstractFactorEx : public IAbstractFactor
{
public:
	virtual IRoomCarBase* CreateRoomCar() = 0;
};

//增加一种大奔房车
class CBenzFactorEx : public IAbstractFactorEx
{
public:
	IBusinessCarBase* CreateBusinessCar()
	{
		return m_factor.CreateBusinessCar();
	}
	ICivilCarBase* CreateCivilCar()
	{
		return m_factor.CreateCivilCar();
	}
	ISportCarBase* CreateSportCar()
	{
		return m_factor.CreateSportCar();
	}
	IRoomCarBase* CreateRoomCar()
	{
		return new CBenzRoomCar(new CBenzEngine, new CBenzChassis, new CBenzWheel);
	}

private:
	//组合进行扩展 优先使用组合，而不是继承
	CBenzFactor m_factor;
};

//组合负责它的所有局部类的生命周期
//聚合它不负责局部类的生命周期

//最终目的：
//高内聚：责任要单一
//低耦合：类与类之间的变化要尽量少 能单向依赖千万不要去双向依赖