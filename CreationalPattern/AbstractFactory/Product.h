#pragma once
/*////////////////////////////////////////////////////
//˵���������Ʒ�;����Ʒ������
//�ļ���Product.h
//���ڣ�2020/6/23
//���ߣ�coder
//QQ��375187588
//�޸ģ�2020/6/30
//�汾��
*//////////////////////////////////////////////////////


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

class IEngine
{
public:
	virtual void Create() = 0;
	virtual ~IEngine() {};
};

class IChassis
{
public:
	IChassis() {}
	virtual void Create() = 0;	
	virtual ~IChassis() {};
};

class IWheel
{
public:
	virtual void Create() = 0;
	IWheel() {}
	virtual ~IWheel() {};
};


class CBMWEngine : public IEngine
{
public:
	CBMWEngine() {}
	~CBMWEngine() {}
	void Create()
	{
		std::cout << "CBMWEngine!" << std::endl;
	}
};

class CBMWChassis : public IChassis
{
public:
	CBMWChassis() {}
	~CBMWChassis() {}
	void Create()
	{
		std::cout << "CBMWChassis!" << std::endl;
	}
};

class CBMWWheel : public IWheel
{
public:
	CBMWWheel() {}
	~CBMWWheel() {}
	void Create()
	{
		std::cout << "CBMWWheel!" << std::endl;
	}
};

class CBenzEngine : public IEngine
{
public:
	CBenzEngine() {}
	~CBenzEngine() {}
	void Create()
	{
		std::cout << "CBenzEngine!" << std::endl;
	}
};

class CBenzChassis : public IChassis
{
public:
	CBenzChassis() {}
	~CBenzChassis() {}
	void Create()
	{
		std::cout << "CBenzChassis!" << std::endl;
	}
};

class CBenzWheel : public IWheel
{
public:
	CBenzWheel() {}
	~CBenzWheel() {}
	void Create()
	{
		std::cout << "CBenzWheel!" << std::endl;
	}
};

class CBMWBusinessCar : public IBusinessCarBase
{
public:
	CBMWBusinessCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBMWBusinessCar() { std::cout << "CBMWBusinessCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWBusinessCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBMWBusinessCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBMWCivilCar : public ICivilCarBase
{
public:
	CBMWCivilCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBMWCivilCar() { std::cout << "CBMWCivilCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWCivilCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBMWCivilCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBMWSportCar : public ISportCarBase
{
public:
	CBMWSportCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBMWSportCar() { std::cout << "CBMWSportCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBMWSportCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBMWSportCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBenzBusinessCar : public IBusinessCarBase
{
public:
	CBenzBusinessCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzBusinessCar() { std::cout << "CBenzBusinessCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzBusinessCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzBusinessCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBenzCivilCar : public ICivilCarBase
{
public:
	CBenzCivilCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzCivilCar() { std::cout << "CBenzCivilCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzCivilCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzCivilCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

class CBenzSportCar : public ISportCarBase
{
public:
	CBenzSportCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzSportCar() { std::cout << "CBenzSportCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzSportCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzSportCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};

///-------------------------------------------------------------------
//����һ���µĳ��� ���� //////////////////////////////////////////////
//�ܳ�
class IRoomCarBase
{
public:
	IRoomCarBase() {}
	virtual~IRoomCarBase() {}
	virtual void Create() = 0;
};

class CBenzRoomCar : public IRoomCarBase
{
public:
	CBenzRoomCar(IEngine* pEngine, IChassis* pChassis, IWheel* pWheel)
	{
		m_pEngine.reset(pEngine);
		m_pChassis.reset(pChassis);
		m_pWheel.reset(pWheel);
	}
	~CBenzRoomCar() { std::cout << "CBenzRoomCar ������!" << std::endl; }

	void Create()
	{
		std::cout << "CBenzRoomCar��ʼ������" << std::endl;
		m_pEngine.get()->Create();
		m_pChassis.get()->Create();
		m_pWheel.get()->Create();
		std::cout << "CBenzRoomCar�����ɹ���" << std::endl;
	}

private:
	std::shared_ptr<IEngine> m_pEngine;
	std::shared_ptr<IChassis> m_pChassis;
	std::shared_ptr<IWheel> m_pWheel;
};
