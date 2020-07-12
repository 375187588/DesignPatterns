#pragma once
/*////////////////////////////////////////////////////
//˵�������ģʽ��ʵ��
//�ļ���Facade.h
//���ڣ�2020/6/29
//���ߣ�coder
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

class CMaleUnmarriedcert
{
public:
	CMaleUnmarriedcert(std::string* pStr):
		m_pStr(pStr)
	{
	}
	~CMaleUnmarriedcert() {};

	//�ύ�з�����
	void Give()
	{
		std::cout << "�з�δ��֤��,��ס���ڱ����������֤,����֤��" << m_pStr->c_str() << std::endl;
	}
	
private:
	std::string* m_pStr;
};

class CFemaleUnmarriedcert
{
public:
	CFemaleUnmarriedcert(std::string* pStr):
		m_pStr(pStr)
	{
		
	}
	~CFemaleUnmarriedcert() {};

	//�ύŮ������
	void Give()
	{
		std::cout << "Ů��δ��֤��,��ס���ڱ����������֤,����֤��" << m_pStr->c_str() << std::endl;
	}

private:
	std::string* m_pStr;
};
//3��2����ڰ�����ڲ�ɫ��Ӱ��
class CMBOCAffairs
{
public:
	CMBOCAffairs()
	{
		m_str = "3��2����ڰ�����ڲ�ɫ��Ӱ��";
		m_pMale = new CMaleUnmarriedcert(&m_str);
		m_pFemal = new CFemaleUnmarriedcert(&m_str);
	}
	~CMBOCAffairs()
	{
		delete m_pMale;
		delete m_pFemal;
	}
	
	void DoAFMCertificate()
	{
		//�ύ�з�����
		m_pMale->Give();
		//�ύŮ������
		m_pFemal->Give();
		std::cout << "�ɹ�������Ǽ��ˣ������Ž��֤�����װ��������మ����ͷ���ϰ�!" << std::endl;
	}

private:
	CMaleUnmarriedcert* m_pMale;
	CFemaleUnmarriedcert* m_pFemal;
	std::string m_str;
};

//////////////////////////////////////////////////////////
//��˰ϵͳ
class CPersonTaxSystem
{
public:
	CPersonTaxSystem()
	{
	}
	~CPersonTaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "��˰��ϵͳҵ��" << std::endl;
	}
};

//����˰ϵͳ
class CConsumptiontaxSystem
{
public:
	CConsumptiontaxSystem()
	{
	}
	~CConsumptiontaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "����˰��ϵͳҵ��" << std::endl;
	}
};

//��ҵ����˰ϵͳ
class CBusinessIncomeTaxSystem
{
public:
	CBusinessIncomeTaxSystem()
	{
	}
	~CBusinessIncomeTaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "��ҵ����˰��ϵͳҵ��" << std::endl;
	}
};

//����˰��ϵͳ
class CCustomsTaxSystem
{
public:
	CCustomsTaxSystem()
	{
	}
	~CCustomsTaxSystem()
	{
	}
	void DoTax()
	{
		std::cout << "����˰����ϵͳҵ��" << std::endl;
	}
};

class CTaxHall
{
public:
	CTaxHall()
	{
		m_pSys1 = new CPersonTaxSystem;
		m_pSys2 = new CConsumptiontaxSystem;
		m_pSys3 = new CBusinessIncomeTaxSystem;
		m_pSys4 = new CCustomsTaxSystem;
	}
	~CTaxHall()
	{
		delete m_pSys1;
		delete m_pSys2;
		delete m_pSys3;
		delete m_pSys4;
	}

	void DoTaxWindow()
	{
		m_pSys1->DoTax();
		m_pSys2->DoTax();
		m_pSys3->DoTax();
		m_pSys4->DoTax();
	}

private:
	CPersonTaxSystem* m_pSys1;
	CConsumptiontaxSystem* m_pSys2;
	CBusinessIncomeTaxSystem* m_pSys3;
	CCustomsTaxSystem* m_pSys4;
};