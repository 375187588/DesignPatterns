#pragma once

//ͨ��ģ�巽��
class CFactor
{
public:
	template<class T>
	static T* Create()
	{
		return new T();
	}
};

//���ػ����ģ�巽��������̳�CBase
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