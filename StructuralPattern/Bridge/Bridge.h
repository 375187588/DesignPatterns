#pragma once
/*////////////////////////////////////////////////////
//说明：桥接模式类实例
//文件：Bridge.h
//日期：2020/6/29
//作者：coder
//修改：
//版本：
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
	//加密数据
	virtual bool Encryption() { return false; };
	//解密数据
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
		std::cout << "将：\""<< m_strData.c_str() << "\" 进行了CRC加密" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "将：\"" << m_strData.c_str() << "\"进行了CRC解密" << std::endl;
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
		std::cout << "将：\"" << m_strData.c_str() << "\"进行了OR加密" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "将：\"" << m_strData.c_str() << "\"进行了OR解密" << std::endl;
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
	//加密数据
	virtual bool Encryption() = 0;
	//解密数据
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
	//加密数据
	bool Encryption()
	{
		std::cout << "CMemBuffer 加密数据开始" << std::endl;
		return m_if->Encryption();
	}
	//解密数据
	bool Decrypt()
	{
		std::cout << "CMemBuffer 解密数据开始" << std::endl;
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
	//加密数据
	bool Encryption()
	{
		std::cout << "CFileBuffer 加密数据开始" << std::endl;
		return m_if->Encryption();
	}
	//解密数据
	bool Decrypt()
	{
		std::cout << "CFileBuffer 解密数据开始" << std::endl;
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
	//加密数据
	virtual bool Encryption() = 0;
	//解密数据
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
	//加密数据
	virtual bool Encryption() = 0;
	//解密数据
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
		std::cout << "将：\"" << m_strData.c_str() << "\" 进行了AES加密" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "将：\"" << m_strData.c_str() << "\"进行了AES解密" << std::endl;
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
		std::cout << "将：\"" << m_strData.c_str() << "\" 进行了DES加密" << std::endl;
		return true;
	}
	bool Decrypt()
	{
		std::cout << "将：\"" << m_strData.c_str() << "\"进行了DES解密" << std::endl;
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
	//加密数据
	bool Encryption()
	{
		return m_pImp->Encryption();
	}
	//解密数据
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

	//加密数据
	bool Encryption()
	{
		return m_pImp->Encryption();
	}
	//解密数据
	bool Decrypt()
	{
		return m_pImp->Decrypt();
	}

private:
	CAlgorithmImp* m_pImp;
};
//////////////////////////////////////////////////////////////////