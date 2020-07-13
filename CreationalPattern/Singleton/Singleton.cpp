// 单例模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <iostream>
#include <condition_variable>
#include "Singleton.h"

class CFileSystem :public CTSSingletonPtr<CFileSystem>
{
public:
	CFileSystem() 
	{
		std::cout << "CFileSystem construct" << std::endl;
		m_nCount = 0;
	}
	~CFileSystem()
	{
		std::cout << "CFileSystem destruct" << std::endl;
	}

public:
	void Print()
	{
		std::cout << "CFileSystem Object! " << std::endl;
	}

private:
	int m_nCount;
};

class CFileChildSystem : public CSingletonPtr<CFileChildSystem>
{
	friend class CSingletonPtr<CFileChildSystem>;

protected:
	CFileChildSystem() 
	{ 
		std::cout << "CFileChildSystem construct" << std::endl; 
		m_nCount = 0;
	}
	~CFileChildSystem()
	{
		std::cout << "CFileChildSystem destruct" << std::endl;
	}

public:
	void Print()
	{
		std::cout << "CFileChildSystem Object! count:" << m_nCount++ << std::endl;
	}

private:
	int m_nCount;
};


void Thread()
{
	std::cout << "cur thread id:" << std::this_thread::get_id() << std::endl;
	//CFileSystem::GetInstance()->Print();
	//CFileChildSystem::GetFirstInstance().Print();
	CFileChildSystem::GetSecondInstance().Print();
}

int main()
{
    std::cout << "Hello World!\n";
	std::cout << "main thread id:" << std::this_thread::get_id() << std::endl;

	for (size_t i = 0; i < 3; i++)
	{
		std::thread t(Thread);
		t.join();
	}
	getchar();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
