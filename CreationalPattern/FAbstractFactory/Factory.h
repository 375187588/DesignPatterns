#pragma once

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