#pragma once
/*////////////////////////////////////////////////////
//说明：访问者模式实例
//文件：Visitor.h
//日期：2020/6/30
//作者：coder
//QQ：375187588
//修改：
//版本：
*//////////////////////////////////////////////////////

class CElement1;
class CElement2;
class CElement;
class CVistor
{
public:
	CVistor() {}
	virtual ~CVistor() {}

	virtual void VistorElement1(CElement* pElement) = 0;
	virtual void VistorElement2(CElement* pElement) = 0;
};

class CVistor1 : public CVistor
{
public:
	void VistorElement1(CElement* pElement)
	{
		std::cout << "I will vistor CElement1" << std::endl;
	}
	void VistorElement2(CElement* pElement)
	{
		std::cout << "I will vistor CElement2" << std::endl;
	}
};

class CVistor2 : public CVistor
{
public:
	void VistorElement1(CElement* pElement)
	{
		std::cout << "I will vistor CElement1" << std::endl;
	}
	void VistorElement2(CElement* pElement)
	{
		std::cout << "I will vistor CElement2" << std::endl;
	}
};

class CVistor;
class CElement
{
public:
	CElement() {}
	virtual ~CElement() {}

public:
	virtual void Accept(CVistor* pVistor) = 0;
};

class CElement1 :public CElement
{
public:
	void Accept(CVistor* pVistor)
	{
		std::cout << "Visiting CElement1 ..." << std::endl;
		pVistor->VistorElement1(this);
	}
};

class CElement2 : public CElement
{
public:
	void Accept(CVistor* pVistor)
	{
		std::cout << "Visiting CElement2 ..." << std::endl;
		pVistor->VistorElement2(this);
	}
};