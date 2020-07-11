#pragma once
/*////////////////////////////////////////////////////
//˵����������ģʽ�� ������Ͷ�������
//�ļ���Adapter.h
//���ڣ�2020/6/28
//����: coder
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

//����
class IPlug
{
public:
	IPlug() {}
	virtual ~IPlug() {}
	virtual void DoPlugIn() = 0;
};

//���ײ���
class CThreeHolePlug
{
public:
	CThreeHolePlug() {}
	~CThreeHolePlug()
	{
		std::cout << "~CThreeHolePlug()" << std::endl;
	}
	void DoSpecialPlugIn()
	{
		std::cout << "���ײ�ͷ��ͨ��Դ" << std::endl;
	}
};

//��Ҫ���ײ��� �̳�ʵ��
class CAdapterClass : public IPlug,private CThreeHolePlug
{
public:
	CAdapterClass()
	{
	}
	~CAdapterClass()
	{
		std::cout << "~CAdapterObject()" << std::endl;
	}
	void DoPlugIn()
	{
		this->DoSpecialPlugIn();
		std::cout << "�ɹ������ײ�ͷת�����ײ�ͷ��" << std::endl;
	}
};

//��Ҫ���ײ��� ���ʵ��
class CAdapterObject : public IPlug
{
public:
	CAdapterObject(CThreeHolePlug* pPlug):
		m_pThreeHolePlug(pPlug)
	{
	}
	~CAdapterObject()
	{
		std::cout << "~CAdapterObject()" << std::endl;
	}

	void DoPlugIn()
	{
		std::cout << "�ɹ������ײ�ͷת�����ײ�ͷ��" << std::endl;
		m_pThreeHolePlug->DoSpecialPlugIn();
	}

protected:
	CThreeHolePlug* m_pThreeHolePlug;
};