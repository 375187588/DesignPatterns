// 5_原型模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Clone.h"

void TestResume()
{
	CResume r;
	r.SetPersonInfo("tom", 1, 28);
	r.SetWorkExperience("四川大学教师", 2);
	r.Print();

	CResume* pClone = r.Clone();
	pClone->SetPersonInfo("lili", 0, 21);
	pClone->SetWorkExperience("四川音乐大学", 1);
	pClone->Print();

	delete pClone;
}

//浅拷贝
void TestResume2()
{
	CWorkExperience* p = new CWorkExperience("中国人民广播大学",5);
	CResume2 r(p);
	r.SetPersonInfo("李阳", 1, 30);
	r.Print();

	CResume2* pClone = r.Clone();
	pClone->SetPersonInfo("美丽", 0, 20);
	pClone->SetWorkExperience("北京大学教师", 2);
	pClone->Print();

	r.Print();
	delete pClone;
	delete p;
}

//深拷贝
void TestResume22()
{
	CWorkExperience22* p = new CWorkExperience22("清华大学教授", 15);
	CResume22 r(p);
	r.SetPersonInfo("成吉思", 1, 38);
	r.Print();

	CResume22* pClone = r.Clone();
	pClone->SetPersonInfo("王洪", 0, 25);
	pClone->SetWorkExperience("四川大学教师", 2);
	pClone->Print();

	r.Print();
	CWorkExperience22* p22 = pClone->GetWorkExperience();
	if (p22)
	{
		delete p22;
		p22 = nullptr;
	}
	delete pClone;
	pClone = nullptr;
	delete p;
	p = nullptr;
}


//深拷贝 防止深度拷贝的内存泄漏
void TestResume33()
{
	CWorkExperience33* p = new CWorkExperience33("清华大学博士", 24);
	CResume33 r(p);
	std::cout << "是否是深度拷贝：" << r.IsDeepClone() << std::endl;
	r.SetPersonInfo("在天天", 1, 50);
	r.Print();

	CResume33* pClone = r.Clone();
	pClone->SetPersonInfo("王洪", 0, 25);
	pClone->SetWorkExperience("四川大学教师", 2);
	pClone->Print();

	r.Print();
	delete pClone;
	pClone = nullptr;
	delete p;
	p = nullptr;
}

//解决深度拷贝崩溃问题
void TestResume33Ptr()
{
	CResume33Ptr r(new CWorkExperience33Ptr("牛津大学博士", 5));
	r.SetPersonInfo("牛牛乐", 1, 50);
	r.Print();

	std::shared_ptr<CResume33Ptr> pClone1(r.Clone());
	pClone1->SetPersonInfo("犀角1", 0, 25);
	pClone1->SetWorkExperience("中国科技大学1", 2);
	pClone1->Print();

	std::shared_ptr<CResume33Ptr> pClone2(r.Clone());
	pClone2->SetPersonInfo("犀角2", 0, 25);
	pClone2->SetWorkExperience("中国科技大学2", 2);
	pClone2->Print();

	pClone1->Print();
	r.Print();
}

int main()
{
    std::cout << "Hello World!\n";
	//TestResume();
	//std::cout << "==========浅拷贝 开始==========" << std::endl;
	//TestResume2();

	//std::cout << "==========深拷贝 开始==========" << std::endl;
	//std::cout << std::endl;
	//TestResume22();

	//std::cout << "==========深拷贝 开始==========" << std::endl;
	//TestResume33();

	std::cout << "==========深拷贝 解决内存泄漏问题开始==========" << std::endl;
	TestResume33Ptr();
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
