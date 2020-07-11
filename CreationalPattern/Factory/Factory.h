#pragma once

/*////////////////////////////////////////////////////
//说明：简单工厂模式
//文件：Factory.h
//日期：2020/6/23
//作者: coder
//QQ: 375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//通用模板方法
class CFactor
{
public:
	template<class T>
	static T* Create()
	{
		return new T();
	}
};

//返回基类的模板方法，必须继承CBase
class CBase;
class CBaseFactor
{
public:
	template<class T>
	static CBase* Create()
	{
		return new T();
	}
};
