#pragma once
/*////////////////////////////////////////////////////
//˵����װ����ģʽ��ʵ��
//�ļ���Decorator.h
//���ڣ�2020/6/28
//����: coder
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

//���ӱ�ǽ
class CTVBgWall
{
public:
	CTVBgWall() {}
	virtual ~CTVBgWall() 
	{ 
		std::cout << "~CTVBgWall()" << std::endl; 
	}

public:
	virtual void Decorate() { std::cout << "���ӱ���ǽ��Ҫװ��" << std::endl; }
};

//ֱ��װ��
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
		std::cout << "���ӱ���ǽ���ϸߵ�����ʯ��" << std::endl;
	}
};

//װ����
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

//����ߵ�װ����
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
		std::cout << "�����ۣ����ߴ��ϣ��ڰ��Ͻ��" << std::endl;
	}
};