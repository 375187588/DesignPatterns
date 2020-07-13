// 工厂模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include "Product.h"

class ICar
{
public:
	virtual void Create() = 0;
};

class CBMWCar : public ICar
{
public:
	CBMWCar() {}
	~CBMWCar() {}

	void Create()
	{
		std::cout << "CBMWCard!" << std::endl;
	}
};

class CBenzCar : public ICar
{
public:
	CBenzCar() {}
	~CBenzCar() {}

	void Create()
	{
		std::cout << "CBenzCar!" << std::endl;
	}
};

class CPorsche : public ICar
{
public:
	CPorsche() {}
	~CPorsche() {}

	void Create()
	{
		std::cout << "CPorsche!" << std::endl;
	}
};

class CBase
{
public:
	virtual void Create() = 0;
};

class CToyotaCar :public CBase
{
public:
	CToyotaCar() {}
	~CToyotaCar() {}

	void Create()
	{
		std::cout << "CToyotaCar!" << std::endl;
	}
};

void TestCar()
{
	ICar* pCar = nullptr;
	pCar = CFactor::Create<CBMWCar>();
	pCar->Create();
	delete pCar;

	pCar = CFactor::Create<CBenzCar>();
	pCar->Create();
	delete pCar;

	pCar = CFactor::Create<CPorsche>();
	pCar->Create();
	delete pCar;
}

void TestBaseCar()
{
	CBase* pCar = nullptr;
	pCar = CBaseFactor::Create<CToyotaCar>();
	pCar->Create();
	delete pCar;
}

void TestCarFactor()
{
	CCarFactor factor;
	IBaseCar* pCar = factor.Create();
	pCar->Create();
	delete pCar;
	pCar = nullptr;
}

int main()
{
    std::cout << "Hello World!\n";
	TestCar();
	TestBaseCar();
	TestCarFactor();

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
