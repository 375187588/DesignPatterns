// 代理模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <sys/timeb.h>
#include <string.h>
#include "Proxy.h"

//返回当前系统时间 格式为：年/月/日 时:分:秒
std::string CurTimeToString(std::string& strTime)
{
	time_t curTime = time(nullptr);
	struct tm t;
	localtime_s(&t, &curTime);
	char szTime[32];
	sprintf_s(szTime, 32, "%4.4d/%2.2d/%2.2d %2.2d:%2.2d:%2.2d:%4.4d",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec,t.tm_isdst);
	strTime = szTime;
	return strTime;
}

//返回当前系统时间 格式为：年/月/日 时:分:秒:毫秒
std::string GetCurTimeToString(std::string& strTime)
{
	timeb tb; ftime(&tb);
	struct tm t;
	localtime_s(&t, &tb.time);
	char szTime[32];
	sprintf_s(szTime, 32, "%4.4d/%2.2d/%2.2d %2.2d:%2.2d:%2.2d:%4.4d",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);
	strTime = szTime;

	return strTime;
}

int main()
{
	CPersonWOPFundBase *pPerson = new CPersonWOPFund();
	CPersonWOPFundProxy* pProxy = new CPersonWOPFundProxy(pPerson);
	std::string strTime;
	stWOPFundPersonInfo info = { OneselfID ,"高富帅","123456789x" ,GetCurTimeToString(strTime) };
	stProxyWOPFundPersonInfo pInfo{ "白富美","987654321x","夫妻" };

	if (pProxy->DoSubmission(info, pInfo))
	{
		pProxy->DoWOPFund();
	}
	std::cout << std::endl;
	info.eProxy = ProxyID;
	GetCurTimeToString(info.strTime);
	if (pProxy->DoSubmission(info, pInfo))
	{
		pProxy->DoWOPFund();
	}

	delete pProxy;
	delete pPerson;

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
