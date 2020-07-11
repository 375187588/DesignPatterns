// 组合模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Mode.h"

CNode* Build(CNode* root, const std::string &val) 
{
	if (root == NULL) {
		root = new CNode();
		root->name = val;
		return root;
	}
	if (val < root->name)
		root->left = Build(root->left, val);
	else if (val > root->name)
		root->right = Build(root->right, val);

	return root;
}

template<typename TIter>
void DoLoop(TIter& iter)
{
	while (iter.MoveNext())
	{
		std::cout << "Current Node name:" << iter.GetCurrent().GetName() << std::endl;
	}
}

int main()
{
	std::cout << "Hello World!\n";
	CNode *root = NULL;
	const std::string t[] = { 
		"node1",
		"node2",
		"node3",
		"node4",
		"node5",
		"node6",
		"node7",
		"node8",
		"node9",
		"node10"
	};

	for (int i = 0; i < 10; i++)
	{
		root = Build(root, t[i]);
	}

	std::cout << "先根遍历器 深度优先 从上到下 从左到右遍历器" << std::endl;
	CNFDLRIter it(root);
	DoLoop<CNFDLRIter>(it);

    std::cout << "Bye Hello World!\n";
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
