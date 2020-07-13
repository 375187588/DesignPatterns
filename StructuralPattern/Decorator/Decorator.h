#pragma once
/*////////////////////////////////////////////////////
//说明：装饰者模式类实例
//文件：Decorator.h
//日期：2020/6/28
//作者: coder
//修改：
//版本：
*//////////////////////////////////////////////////////

//电视背墙
class CTVBgWall
{
public:
	CTVBgWall() {}
	virtual ~CTVBgWall() 
	{ 
		std::cout << "~CTVBgWall()" << std::endl; 
	}

public:
	virtual void Decorate() { std::cout << "电视背景墙想要装修" << std::endl; }
};

//直接装修
class CSchemeTVBgWall : public CTVBgWall
{
public:
	CSchemeTVBgWall() {}
	virtual ~CSchemeTVBgWall() 
	{ 
		std::cout << "~CSchemeTVBgWall()" << std::endl; 
	}

public:
	void Decorate()
	{
		this->DoScheme();
	}

	void DoScheme()
	{
		std::cout << "电视背景墙贴上高档大理石材" << std::endl;
	}
};

//装饰者
class CDecorator : public CTVBgWall
{
public:
	CDecorator(CTVBgWall* pWall)
	{
		m_pWall = pWall;
	}
	virtual ~CDecorator()
	{
		std::cout << "~CDecorator()" << std::endl;
	}
	void Decorate()
	{
		m_pWall->Decorate();
	}

protected:
	CTVBgWall* m_pWall;
};

//包金边的装饰者
class CTVBgWallDecorator : public CDecorator
{
public:
	CTVBgWallDecorator(CTVBgWall* pWall):
		CDecorator(pWall)
	{

	}
	~CTVBgWallDecorator()
	{
		std::cout << "~CTVBgWallDecorator()" << std::endl;
	}

	void Decorate()
	{
		m_pWall->Decorate();
		this->DoDecorate();
	}

	void DoDecorate()
	{
		std::cout << "不美观，不高大上，在包上金边" << std::endl;
	}
};