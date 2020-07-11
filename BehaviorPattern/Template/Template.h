#pragma once
/*////////////////////////////////////////////////////
//说明：模板方法模式实例
//文件：Template.h
//日期：2020/6/30
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

//把一头牛放到冰箱里需要三步
class CCattleInIceBox
{
public:
	CCattleInIceBox() {}
	virtual ~CCattleInIceBox() {}

public:
	void Step()
	{
		this->Step1();
		this->Step2();
		this->Step3();
	}
	virtual void Step1() = 0;
	virtual void Step2() = 0;

private:
	void Step3()
	{
		std::cout << "第三步：将冰箱关上!" << std::endl;
	}
};

class CThinkPerson :public CCattleInIceBox
{
public:
	CThinkPerson() {}
	~CThinkPerson() {}

public:
	void Step1()
	{
		std::cout << "第一步：打开冰箱!" << std::endl;
	}
	void Step2()
	{
		std::cout << "第二步：把牛放进去!" << std::endl;
	}
};

class CWorryPerson :public CCattleInIceBox
{
public:
	CWorryPerson() {}
	~CWorryPerson() {}

public:
	void Step1()
	{
		std::cout << "第一步：将牛杀死!" << std::endl;
	}
	void Step2()
	{
		std::cout << "第二步：分块放入!" << std::endl;
	}
};