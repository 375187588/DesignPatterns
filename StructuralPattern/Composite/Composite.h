#pragma once
/*////////////////////////////////////////////////////
//说明：组合模式类实例
//文件：Composite.h
//日期：2020/6/30
//作者：coder
//修改：
//版本：
*//////////////////////////////////////////////////////

class CComponent
{
public:
	CComponent() {}
	virtual ~CComponent() {}

public:
	virtual void Operation() = 0;
	virtual void Add(const CComponent& com) {}
	virtual void Remove(const CComponent& com) {}
	virtual CComponent* GetChild(int nIndex) { return nullptr; };
};

class CComposite : public CComponent
{
public:
	CComposite() {}
	~CComposite() {}

public:
	void Operation()
	{
		for (auto it : m_coms)
		{
			it->Operation();
		}
	}
	void Add(CComponent* com)
	{
		m_coms.push_back(com);
	}
	void Remove(CComponent* com)
	{
		auto it = std::find(std::begin(m_coms),
			std::end(m_coms), com);

		if (it != m_coms.end())
		{
			m_coms.erase(it);
		}
	}
	CComponent* GetChild(int nIndex)
	{
		return m_coms[nIndex];
	}

private:
	std::vector<CComponent*> m_coms;
}; 

class CLeaf : public CComponent
{
public:
	CLeaf() {}
	~CLeaf() {}

public:
	void Operation()
	{
		std::cout << "CLeaf Operation" << std::endl;
	}
};

enum eOrderType
{
	DLR,//先序遍历
	LDR,//中序遍历
	LRD //后序遍历
};

class CAbstractTreeNode
{
public:
	CAbstractTreeNode() {}
	virtual ~CAbstractTreeNode() {}	
	
	CAbstractTreeNode(std::string strName) {
		this->m_strName = strName;
	}
	CAbstractTreeNode* GetLeft()
	{
		return m_Left;
	}
	void SetLeft(CAbstractTreeNode* left)
	{
		m_Left = left;
	}
	CAbstractTreeNode* GetRight()
	{
		return m_Right;
	}
	void SetRight(CAbstractTreeNode* right)
	{
		m_Right = right;
	}

	virtual void OutputDisplay(eOrderType etype) {}

protected:
	CAbstractTreeNode* m_Left;
	CAbstractTreeNode* m_Right;
	std::string m_strName;
};

class CTreeNode :public CAbstractTreeNode
{
public:
	CTreeNode(std::string strName) : 
		CAbstractTreeNode(strName) 
	{ 
	}

	void OutputDisplay(eOrderType etype)
	{
		switch (etype)
		{
		case DLR:
			DLROutputDisplay(etype);
			break;
		case LDR:
			LDROutputDisplay(etype);
			break;
		case LRD:
			LRDOutputDisplay(etype);
			break;
		}
	}

	void DLROutputDisplay(eOrderType etype)
	{
		std::cout << m_strName;
		if (m_Left!= nullptr)
		{
			m_Left->OutputDisplay(etype);
		}
		if (m_Right != nullptr)
		{
			m_Right->OutputDisplay(etype);
		}
	}
	void LDROutputDisplay(eOrderType etype)
	{
		if (m_Left != nullptr)
		{
			m_Left->OutputDisplay(etype);
		}
		std::cout << m_strName;
		if (m_Right != nullptr)
		{
			m_Right->OutputDisplay(etype);
		}
	}
	void LRDOutputDisplay(eOrderType etype)
	{
		if (m_Left != nullptr)
		{
			m_Left->OutputDisplay(etype);
		}
		if (m_Right != nullptr)
		{
			m_Right->OutputDisplay(etype);
		}
		std::cout << m_strName;
	}
};

class CLeafNode :public CAbstractTreeNode
{
public:
	CLeafNode(std::string strName)
		: CAbstractTreeNode(strName) { }

	void OutputDisplay(eOrderType etype)
	{
		std::cout << m_strName;
	}
};
