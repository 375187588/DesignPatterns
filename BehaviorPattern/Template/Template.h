#pragma once
/*////////////////////////////////////////////////////
//˵����ģ�巽��ģʽʵ��
//�ļ���Template.h
//���ڣ�2020/6/30
//���ߣ�coder
//QQ��375187588
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

//��һͷţ�ŵ���������Ҫ����
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
		std::cout << "�����������������!" << std::endl;
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
		std::cout << "��һ�����򿪱���!" << std::endl;
	}
	void Step2()
	{
		std::cout << "�ڶ�������ţ�Ž�ȥ!" << std::endl;
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
		std::cout << "��һ������ţɱ��!" << std::endl;
	}
	void Step2()
	{
		std::cout << "�ڶ������ֿ����!" << std::endl;
	}
};