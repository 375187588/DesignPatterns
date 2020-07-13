#pragma once
/*////////////////////////////////////////////////////
//说明：适配器模式类 类适配和对象适配
//文件：Adapter.h
//日期：2020/6/28
//作者: coder
//修改：
//版本：
*//////////////////////////////////////////////////////

//插座
class IPlug
{
public:
	IPlug() {}
	virtual ~IPlug() {}
	virtual void DoPlugIn() = 0;
};

//三孔插座
class CThreeHolePlug
{
public:
	CThreeHolePlug() {}
	~CThreeHolePlug()
	{
		std::cout << "~CThreeHolePlug()" << std::endl;
	}
	void DoSpecialPlugIn()
	{
		std::cout << "三孔插头接通电源" << std::endl;
	}
};

//需要两孔插座 继承实现
class CAdapterClass : public IPlug,private CThreeHolePlug
{
public:
	CAdapterClass()
	{
	}
	~CAdapterClass()
	{
		std::cout << "~CAdapterObject()" << std::endl;
	}
	void DoPlugIn()
	{
		this->DoSpecialPlugIn();
		std::cout << "成功将三孔插头转成两孔插头！" << std::endl;
	}
};

//需要两孔插座 组合实现
class CAdapterObject : public IPlug
{
public:
	CAdapterObject(CThreeHolePlug* pPlug):
		m_pThreeHolePlug(pPlug)
	{
	}
	~CAdapterObject()
	{
		std::cout << "~CAdapterObject()" << std::endl;
	}

	void DoPlugIn()
	{
		std::cout << "成功将三孔插头转成两孔插头！" << std::endl;
		m_pThreeHolePlug->DoSpecialPlugIn();
	}

protected:
	CThreeHolePlug* m_pThreeHolePlug;
};