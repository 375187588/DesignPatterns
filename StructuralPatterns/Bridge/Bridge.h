#pragma once
/*////////////////////////////////////////////////////
//˵�����Ž�ģʽ��ʵ��
//�ļ���Bridge.h
//���ڣ�2020/6/29
//���ߣ�coder
//�޸ģ�
//�汾��
*//////////////////////////////////////////////////////

class CDataSafeBase
{
public:
	CDataSafeBase() {}
	virtual ~CDataSafeBase() {}

	void setData(const std::string& strData)
	{
		m_strData = strData;
	}

	std::string getData()
	{
		return m_strData;
	}
	//��������
	virtual bool Encryption() { return false; };
	//��������
	virtual bool Decrypt() { return false; }
	
protected:
	std::string m_strData;
};

class CCRC32Algorithm :public CDataSafeBase
{
public:
	CCRC32Algorithm() {}
	~CCRC32Algorithm() {}
	
	bool Encryption()
	{
		std::cout << "����\""<< m_strData.c_str() << "\" ������CRC����" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "����\"" << m_strData.c_str() << "\"������CRC����" << std::endl;
		return true;
	}	
};


class CORAlgorithm :public CDataSafeBase
{
public:
	CORAlgorithm() {}
	~CORAlgorithm() {}

	bool Encryption()
	{
		std::cout << "����\"" << m_strData.c_str() << "\"������OR����" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "����\"" << m_strData.c_str() << "\"������OR����" << std::endl;
		return true;
	}
};

class CDataBase
{
public:
	CDataBase(CDataSafeBase* p):
		m_if(p)
	{
	}
	virtual ~CDataBase() {}

public:
	//��������
	virtual bool Encryption() = 0;
	//��������
	virtual bool Decrypt() = 0;

protected:
	CDataSafeBase* m_if;
};

class CMemBuffer : public CDataBase
{
public:
	CMemBuffer(CDataSafeBase* p):
		CDataBase(p)
	{
	}
	virtual ~CMemBuffer() {}

public:
	//��������
	bool Encryption()
	{
		std::cout << "CMemBuffer �������ݿ�ʼ" << std::endl;
		return m_if->Encryption();
	}
	//��������
	bool Decrypt()
	{
		std::cout << "CMemBuffer �������ݿ�ʼ" << std::endl;
		return m_if->Decrypt();
	}
};


class CFileBuffer : public CDataBase
{
public:
	CFileBuffer(CDataSafeBase* p) :
		CDataBase(p)
	{
	}
	virtual ~CFileBuffer() {}

public:
	//��������
	bool Encryption()
	{
		std::cout << "CFileBuffer �������ݿ�ʼ" << std::endl;
		return m_if->Encryption();
	}
	//��������
	bool Decrypt()
	{
		std::cout << "CFileBuffer �������ݿ�ʼ" << std::endl;
		return m_if->Decrypt();
	}
};

//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
class CAlgorithmImp;
class CSafeDataImp
{
public:
	virtual ~CSafeDataImp() {};
	//��������
	virtual bool Encryption() = 0;
	//��������
	virtual bool Decrypt() = 0;

protected:
	CSafeDataImp() {}
};

class CAlgorithmImp
{
public:
	CAlgorithmImp() {}
	virtual ~CAlgorithmImp() {}

	void setData(const std::string& strData)
	{
		m_strData = strData;
	}

	std::string getData()
	{
		return m_strData;
	}
	//��������
	virtual bool Encryption() = 0;
	//��������
	virtual bool Decrypt() = 0;

protected:
	std::string m_strData;
};

class CAESAlgorithm : public CAlgorithmImp
{
public:
	CAESAlgorithm() {}
	~CAESAlgorithm() {}

	bool Encryption()
	{
		std::cout << "����\"" << m_strData.c_str() << "\" ������AES����" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "����\"" << m_strData.c_str() << "\"������AES����" << std::endl;
		return true;
	}
};

class CDESAlgorithm : public CAlgorithmImp
{
public:
	CDESAlgorithm() {}
	~CDESAlgorithm() {}

	bool Encryption()
	{
		std::cout << "����\"" << m_strData.c_str() << "\" ������DES����" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "����\"" << m_strData.c_str() << "\"������DES����" << std::endl;
		return true;
	}
};

class CTextFile : public CSafeDataImp
{
public:
	CTextFile(CAlgorithmImp* pImp) :
		m_pImp(pImp)
	{
	}
	~CTextFile()
	{
		if (m_pImp)
		{
			delete m_pImp;
		}
	}
	//��������
	bool Encryption()
	{
		return m_pImp->Encryption();
	}
	//��������
	bool Decrypt()
	{
		return m_pImp->Decrypt();
	}

private:
	CAlgorithmImp* m_pImp;
};

class CBinaryFile : public CSafeDataImp
{
public:
	CBinaryFile(CAlgorithmImp* pImp) :
		m_pImp(pImp)
	{
	}
	~CBinaryFile()
	{
		if (m_pImp)
		{
			delete m_pImp;
		}
	}

	//��������
	bool Encryption()
	{
		return m_pImp->Encryption();
	}
	//��������
	bool Decrypt()
	{
		return m_pImp->Decrypt();
	}

private:
	CAlgorithmImp* m_pImp;
};
//////////////////////////////////////////////////////////////////