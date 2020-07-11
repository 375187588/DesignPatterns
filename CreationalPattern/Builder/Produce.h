#pragma once
#include <string>
/*////////////////////////////////////////////////////
//˵����������ģʽ��
//�ļ���Produce.h
//���ڣ�2020/6/23
//���ߣ�coder
//QQ��375187588
//�޸ģ�2020/6/30
//�汾��
*//////////////////////////////////////////////////////

class CCar
{
public:
	void SetManufacturer(const std::string& strManufacturer)
	{
		m_strManufacturer = strManufacturer;
	}
	const std::string& GetManufacturer() const
	{
		return m_strManufacturer;
	}
	void SetChassis(const std::string& strChassis)
	{
		m_strChassis = strChassis;
	}
	const std::string& GetChassis() const
	{
		return m_strChassis;
	}
	void SetWheel(const std::string& strWheel)
	{
		m_strWheel = strWheel;
	}
	const std::string& GetWheel() const
	{
		return m_strWheel;
	}
	void SetEngine(const std::string& strEngine)
	{
		m_strEngine = strEngine;
	}
	const std::string& GetEngine() const
	{
		return m_strEngine;
	}
	void Print()
	{
		std::cout << "��������:" << m_strManufacturer << std::endl;
		std::cout << "����:" << m_strChassis << std::endl;
		std::cout << "����:" << m_strWheel << std::endl;
		std::cout << "������:" << m_strEngine << std::endl;		
	}

private:
	std::string m_strManufacturer;//��������
	std::string m_strEngine;//������
	std::string m_strChassis;//����
	std::string m_strWheel;//����
};

class CCarBuilderBase
{
public:
	CCar* Build()
	{
		BuildManufacturer();
		BuildChassis();
		BuildWheel();
		BuildEngine();
		return &m_car;
	}

protected:
	virtual void BuildManufacturer() = 0;
	virtual void BuildChassis() = 0;
	virtual void BuildWheel() = 0;
	virtual void BuildEngine() = 0;		
	CCar m_car;
};

class CBenzCar : public CCarBuilderBase
{
protected:
	void BuildManufacturer()
	{
		m_car.SetManufacturer("�������۹�˾\n");
	}
	void BuildChassis()
	{
		m_car.SetChassis("���ڵ¹����۵���\n");
	}
	void BuildWheel()
	{
		m_car.SetWheel("���ڵ¹�������̥\n");
	}
	void BuildEngine()
	{
		m_car.SetEngine("���ڵ¹���������\n");
	}
};

class CBMWCar : public CCarBuilderBase
{
protected:
	void BuildManufacturer()
	{
		m_car.SetManufacturer("�¹�����˾\n");
	}
	void BuildChassis()
	{
		m_car.SetChassis("���ڵ¹��������\n");
	}
	void BuildWheel()
	{
		m_car.SetWheel("���ڵ¹�������̥\n");
	}
	void BuildEngine()
	{
		m_car.SetEngine("���ڵ¹���������\n");
	}
};

//����ģʽ��������װ�Ĺ��̣�����ֱ������һ������Ҫ�Ķ��� ������ǣ����������²�Ʒ
//������ģʽ�ȴ���ÿ����������ͳһ��װ��һ������ �������Ʋ�Ʒ��������װ���������Ĺ��̣�Ȼ����²�Ʒ�������еõ���Ʒ