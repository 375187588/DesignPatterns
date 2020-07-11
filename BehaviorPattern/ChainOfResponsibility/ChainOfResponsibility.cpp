// 责任链模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ChainOfResponsibility.h"

/*
我将CConcreateHandler3处理权给后继节点.....
我将CConcreateHandler2处理权给后继节点.....
CConcreateHandler1 没有后继了，我必须自己处理
Hello World!
*/

int main()
{
	CHandler *pHandler1 = new CConcreateHandler1();
	CHandler *pHandler2 = new CConcreateHandler2(pHandler1);
	CHandler *pHandler3 = new CConcreateHandler3(pHandler2);
	pHandler3->Request();
	
	delete pHandler3;
	pHandler3 = nullptr;

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
