#pragma once
#include <chrono>
#include <thread>

/*////////////////////////////////////////////////////
//说明：单例模式 线程安全
//文件：Singleton.h
//日期：2020/6/23
//作者: coder
//QQ:375187588
//修改：
//版本：
*//////////////////////////////////////////////////////
#include <atomic>

enum State : unsigned
{
	sleeping = 0,	//默认状态
	running,		//开始状态
};

std::atomic<State> state{State::sleeping}; 

enum eLockState : unsigned
{
	eDefaultState = 0,	//默认状态
	eLockingState,		//开始锁定状态
	eLockedState		//已经锁定状态
};

//extern "C" long _cdecl _InterlockedCompareExchange(long volatile*, long, long);
//#pragma intrinsic(_InterlockedCompareExchange)

//懒汉单例模式 原子锁
template <class T>
class CTSSingletonPtr
{
private:
	CTSSingletonPtr(const CTSSingletonPtr&) = delete;
	CTSSingletonPtr& operator=(const CTSSingletonPtr&) = delete;

	//对象删除器
	class Deleter
	{
	public:
		void operator()(T* ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	};

public:
	virtual ~CTSSingletonPtr(){}
	static T* GetInstance()
	{
		static volatile unsigned lLock = eDefaultState;
		
		State expected{State::sleeping}; 
		//if (_InterlockedCompareExchange(&lLock, eLockingState, eDefaultState)
		//	!= eDefaultState)
		if (state.compare_exchange_strong(expected, State::running)) 
		{
			while (lLock != eLockedState)
			{
				std::this_thread::sleep_for(std::chrono::microseconds(0));
			}
			return m_pSingleton.get();
		}

		m_pSingleton = std::shared_ptr<T>(new T,T::Deleter());
		lLock = eLockedState;
		
		return m_pSingleton.get();
	}

protected:
	CTSSingletonPtr() {}
	
private:
	static std::shared_ptr<T> m_pSingleton;
};

template <class T>
std::shared_ptr<T> CTSSingletonPtr<T>::m_pSingleton;


//饿汉单例模式
template <class T>
class CSingletonPtr
{
private:
	CSingletonPtr(const CSingletonPtr&) = delete;
	CSingletonPtr& operator=(const CSingletonPtr&) = delete;

public:
	virtual ~CSingletonPtr() {}

	//Meyers Singleton
	static T& GetSecondInstance()
	{
		static T instance;
		return instance;
	}
	//Non-Local-Static
	static T& GetFirstInstance()
	{
		return m_Singleton;
	}

protected:
	CSingletonPtr() {}

private:
	static T m_Singleton;
};

template <class T>
T CSingletonPtr<T>::m_Singleton;