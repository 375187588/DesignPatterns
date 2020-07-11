#pragma once
#include "Factory.h"
//���Ͽ���-���ԭ��

//��ɳ�������
class CEngine
{
public:
	CEngine()
	{
		std::cout << "��װ���� !" << std::endl;
	}
	~CEngine()
	{
		std::cout << "�������� !" << std::endl;
	}
};

//��ɳ��ĵ���
class CChassis
{
public:
	CChassis()
	{
		std::cout << "��װ���� !" << std::endl;
	}
	~CChassis()
	{
		std::cout << "�������� !" << std::endl;
	}
};

//��ɳ�������
class CWheel
{
public:
	CWheel()
	{
		std::cout << "��װ���� !" << std::endl;
	}
	~CWheel()
	{
		std::cout << "�������� !" << std::endl;
	}
};

class IBaseCar
{
public:
	virtual void Create() = 0;
	virtual ~IBaseCar() {};
};	

//��װ��
class CCar : public IBaseCar
{
public:
	CCar(CEngine* pEngine, CChassis* pChassis, CWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	virtual ~CCar()
	{
		std::cout << "CCar ������!" << std::endl;
	}
	void Create()
	{
		std::cout << "CCar�����棬���̣�������϶���!" << std::endl;
	}

private:
	std::shared_ptr<CEngine> m_pEngine;
	std::shared_ptr<CChassis> m_pChassis;
	std::shared_ptr<CWheel> m_pWheel;
};

class IFactor
{
public:
	virtual IBaseCar* Create() = 0;
};

class CCarFactor : public IFactor
{
public:
	IBaseCar* Create()
	{
		return new CCar(new CEngine, new CChassis, new CWheel);
	}
};

//��������ģʽֻ�ܴ���һ�ֲ�Ʒ


//���󹤳�ģʽ���Բ���һϵ�в�Ʒ
//����
class IBusinessCarBase
{
public:
	IBusinessCarBase() {}
	virtual~IBusinessCarBase() {}
	virtual void Create() = 0;
};

//���ó�
class ICivilCarBase
{
public:
	ICivilCarBase() {}
	virtual~ICivilCarBase() {}
	virtual void Create() = 0;
};

//�ܳ�
class ISportCarBase
{
public:
	ISportCarBase() {}
	virtual~ISportCarBase() {}
	virtual void Create() = 0;
};

class CBMWBusinessCar : public IBusinessCarBase
{
public:
	CBMWBusinessCar(){}
	~CBMWBusinessCar() { std::cout << "CBMWBusinessCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWBusinessCar������" << std::endl;
	}
};

class CBMWCivilCar : public ICivilCarBase

{
public:
	CBMWCivilCar() {}
	~CBMWCivilCar() {}

	void Create()
	{
		std::cout << "CBMWCivilCar������" << std::endl;
	}
};

class CBMWSportCar : public ISportCarBase
{
public:
	CBMWSportCar() {}
	~CBMWSportCar() {}

	void Create()
	{
		std::cout << "CBMWSportCar������" << std::endl;
	}
};

class CBenzBusinessCar : public IBusinessCarBase
{
public:
	CBenzBusinessCar() {}
	void Create()
	{
		std::cout << "CBenzBusinessCar������" << std::endl;
	}
	~CBenzBusinessCar() {}
};

class CBenzCivilCar : public ICivilCarBase

{
public:
	CBenzCivilCar() {}
	~CBenzCivilCar() {}

	void Create()
	{
		std::cout << "CBenzCivilCar������" << std::endl;
	}
};

class CBenzSportCar : public ISportCarBase
{
public:
	CBenzSportCar() {}
	~CBenzSportCar() {}

	void Create()
	{
		std::cout << "CBenzSportCar������" << std::endl;
	}
};

class IAbstractFactor
{
public:
	virtual IBusinessCarBase* CreateBusinessCar() = 0;
	virtual ICivilCarBase* CreateCivilCar() = 0;
	virtual ISportCarBase* CreateSportCar() = 0;
};

class CBMWFactor : public IAbstractFactor
{
public:
	IBusinessCarBase* CreateBusinessCar()
	{
		return new CBMWBusinessCar();
	}
	ICivilCarBase* CreateCivilCar()
	{
		return new CBMWCivilCar();
	}
	ISportCarBase* CreateSportCar()
	{
		return new CBMWSportCar();
	}
	~CBMWFactor()
	{
		std::cout << "CBMWFactor ����!" << std::endl;
	}
};

class CBenzFactor : public IAbstractFactor
{
public:
	~CBenzFactor()
	{
		std::cout << "CBenzFactor ����!" << std::endl;
	}
	IBusinessCarBase* CreateBusinessCar()
	{
		return new CBenzBusinessCar();
	}
	ICivilCarBase* CreateCivilCar()
	{
		return new CBenzCivilCar();
	}
	ISportCarBase* CreateSportCar()
	{
		return new CBenzSportCar();
	}
};
/*---------------------------------------
IAbstractFactor						-	���� ����		IBusinessCarBase
-+CreateBusinessCar():IBusinessCarBase	- - - - - ->	+Create():void
-										-
-+CreateCivilCar():ICivilCarBasei		-���� ����		ICivilCarBase
-										- - - - - ->	+Create():void
--										-
-										-���� ����		ISportCarBase
-+CreateSportCar():ISportCarBase		-- - - - - ->	+Create():void
----------------------------------------

*/