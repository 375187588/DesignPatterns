// 中介者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Mediator.h"

int main()
{
	CHouseMediator1* pMediator= new CHouseMediator1();
	CHouseOwner1* pHouseOwner1 = new CHouseOwner1(pMediator);
	CHouseOwner2* pHouseOwner2 = new CHouseOwner2(pMediator);
	pMediator->IntroHouseOwner(pHouseOwner1, pHouseOwner2);

	RequestMessage* pMessage1 = new RequestMessage();
	pMessage1->strName = "白富美1";
	pMessage1->strContext = "租700平，独门独栋小高层别墅一套 50000元/月";
	pHouseOwner1->SetMessage(pMessage1);

	RequestMessage* pMessage2 = new RequestMessage();
	pMessage2->strName = "高富帅";
	pMessage2->strContext = "租350平，独门独栋别墅一套 280000元/月";
	pHouseOwner2->SetMessage(pMessage2);

	pHouseOwner1->Action();
	pHouseOwner2->Action();

	delete pMessage1;
	delete pMessage2;

	std::cout << std::endl;

	pMessage1 = new RequestMessage();
	pMessage1->strName = "白富美1";
	pMessage1->strContext = "租700平，独门独栋小高层别墅一套 500000元/月";
	pHouseOwner1->SetMessage(pMessage1);

	pMessage2 = new RequestMessage();
	pMessage2->strName = "高富帅1";
	pMessage2->strContext = "租350平，独门独栋别墅一套 2800000元/月";
	pHouseOwner2->SetMessage(pMessage2);

	pHouseOwner1->Action();
	pHouseOwner2->Action();
	delete pMessage1;
	delete pMessage2;

	std::cout << std::endl;
	pMessage1 = new RequestMessage();
	pMessage1->strName = "白富美2";
	pMessage1->strContext = "租700平，独门独栋小高层别墅一套 11500000元/月";
	pHouseOwner1->SetMessage(pMessage1);

	pMessage2 = new RequestMessage();
	pMessage2->strName = "高富帅2";
	pMessage2->strContext = "租350平，独门独栋别墅一套 112800000元/月";
	pHouseOwner2->SetMessage(pMessage2);

	pHouseOwner2->Action();
	pHouseOwner1->Action();

	delete pMessage1;
	delete pMessage2;

	delete pHouseOwner1;
	delete pHouseOwner2;
	delete pMediator;

    std::cout << "Hello World!\n";
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
