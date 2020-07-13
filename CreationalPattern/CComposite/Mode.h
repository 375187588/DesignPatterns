#pragma once
#include <array>
#include <queue>
#include <stack>
#include <assert.h>
/*////////////////////////////////////////////////////
//说明：组合模式类
//文件：Model.h
//日期：2020/6/23
//作者：coder
//QQ：375187588
//修改：2020/6/30
//版本：
*//////////////////////////////////////////////////////

template<typename T>
class IIterable
{
public:
	virtual void Reset() = 0;
	virtual T& GetCurrent() = 0;
	virtual bool MoveNext() = 0;
};

struct CGetIndexLR
{
	int operator()(int len, int idx)
	{
		return idx;
	}
};

struct CGetIndexRL
{
	int operator()(int len, int idx)
	{
		return (len - idx - 1);
	}
};

template<typename T>
class CArrayList
{
public:
	int GetSize()
	{
		return m_array.size();
	}

	T& GetAt(int nIndex)
	{
		return m_array.begin() + nIndex;
	}

private:
	std::array<T,1024> m_array;
};

template<typename T,typename Indexer = CGetIndexLR>
class CArrayIterator :public IIterable<T>
{
public:
	CArrayIterator() : m_pArrayList(NULL), m_nIdx(-1)
	{
	}
	CArrayIterator(CArrayList<T>* arrList)
	{
		assert(arrList);
		m_pArrayList = arrList;
		Reset();
	}
	bool MoveNext()
	{
		m_nIdx++;
		return m_nIdx < m_pArrayList->GetSize();
	}
	T& GetCurrent()
	{
		return m_pArrayList->GetAt(getIndex(m_pArrayList->GetSize(), m_nIdx));
	}
	void Reset()
	{
		m_nIdx = -1;
	}
	void SetContainer(CArrayList<T>* arrList)
	{
		assert(arrList);
		m_pArrayList = arrList;
		Reset();
	}
	CArrayList<T>* GetContainer()
	{
		return m_pArrayList;
	}

private:
	CArrayList<T>* m_pArrayList;
	int m_nIdx;
	Indexer getIndex;
};

//room  node1	     node2       node3
//	node4  node5  node6  node7   node8
//	node9		  node10

template<typename T>
class CAdapter
{
public:
	virtual void Add(T t) = 0;
	virtual T&	Remove() = 0;
	virtual size_t Size() const = 0;
	virtual bool IsEmpty() const = 0;
};

template<typename T>
class CQueueAdpter : public CAdapter<T>
{
public:
	void Add(T t)
	{
		m_queue.push(t);
	}
	T& Remove()
	{
		T& t = m_queue.front();
		m_queue.pop();
		return t;
	}
	size_t Size() const
	{
		return m_queue.size();
	}
	bool IsEmpty() const
	{
		return m_queue.empty();
	}

private:
	std::queue<T> m_queue;
};


template<typename T>
class CStackAdpter : public CAdapter<T>
{
public:
	void Add(T t)
	{
		m_stack.push(t);
	}
	T& Remove()
	{
		T& t = m_stack.top();
		m_stack.pop();
		return t;
	}
	size_t Size() const
	{
		return m_stack.size();
	}
	bool IsEmpty() const
	{
		return m_stack.empty();
	}

private:
	std::stack<T> m_stack;
};

template<typename TNode,
		typename Indexer = CGetIndexRL,
	typename Adpter = CStackAdpter<TNode*>>
class CNodeForwardIterator : public IIterable<TNode>
{
public:
	CNodeForwardIterator() :m_pNode(nullptr), m_pCurrent(nullptr) {}
	CNodeForwardIterator(TNode* pNode)
	{
		assert(pNode);
		m_pNode = pNode;
		Reset();
	}
	bool MoveNext()
	{
		if (m_apt.IsEmpty())
			return false;
		m_pCurrent = m_apt.Remove();
		int len = m_pCurrent->GetChildCount();
		for (int i = 0; i < len; i++)
		{
			m_apt.Add(m_pCurrent->GetChild(indexer(len, i)));
		}
		return true;
	}
	TNode& GetCurrent()
	{
		return (*m_pCurrent);
	}
	void Reset()
	{
		m_pCurrent = nullptr;
		m_apt.Add(m_pNode);
	}
	void SetContainer(TNode* pNode)
	{
		assert(pNode);
		m_pNode = pNode;
		Reset();
	}
	TNode* GetContainer()
	{
		return m_pNode;
	}
private:
	TNode* m_pNode;
	TNode* m_pCurrent;
	Adpter m_apt;
	Indexer indexer;
};

template<typename TNode,
	typename Indexer = CGetIndexLR,
	typename Adpter = CStackAdpter<TNode*> >
class CNodeBackwardIterator : public IIterable<TNode>
{
public:
	CNodeBackwardIterator(TNode* pNode)
	{
		assert(pNode);
		m_decorator.SetContainer(pNode);
		m_arrIter.SetContainer(&m_arrNodes);
		Reset();
	}
	bool MoveNext()
	{		
		return m_arrIter.MoveNext();
	}
	TNode& GetCurrent()
	{
		return (*m_arrIter.GetCurrent());
	}
	void Reset()
	{
		m_arrNodes.Clear();
		while (m_decorator.MoveNext())
		{
			m_arrNodes.Add(&m_decorator.GetCurrent());
		}
		m_arrIter.Reset();
	}
	
private:
	CNodeForwardIterator<TNode, Indexer, Adpter> m_decorator;
	CArrayIterator<TNode*> m_arrNodes;
	CArrayIterator<TNode*, CGetIndexRL> m_arrIter;
};


class CNode
{
public:
	std::string name;
	CNode* left, *right;
	CNode() { right = NULL; left = NULL; }

	std::string& GetName()
	{
		return name;
	}

	CNode* GetChild(int nIndex)
	{
		return nullptr;
	}
	int GetChildCount()
	{
		return 0;
	}
};

//先根遍历器
//1)深度优先 从上到下 从左到右遍历器
typedef CNodeForwardIterator<CNode> CNFDLRIter;
//2)深度优先，从上到下，从右到左遍历器
typedef CNodeForwardIterator<CNode,CGetIndexLR> CNFDRLIter;
//3)广度优先，从上到下，从左到右遍历器
typedef CNodeForwardIterator<CNode, CGetIndexLR,CQueueAdpter<CNode*>> CNFBLRIter;
//4)广度优先，从上到下，从右到左遍历器
typedef CNodeForwardIterator<CNode, CGetIndexRL, CQueueAdpter<CNode*>> CNFBRLIter;


//后根遍历器
//5)深度优先，从下到上，从左到右遍历器
typedef CNodeBackwardIterator<CNode> CNBDLRIter;
//6)深度优先，从下到上，从右到左遍历器
typedef CNodeBackwardIterator<CNode,CGetIndexRL> CNBDRLIter;
//7)广度优先，从下到上，从左到右遍历器
typedef CNodeBackwardIterator<CNode, CGetIndexRL, CQueueAdpter<CNode*>> CNBBLRIter;
//8)广度优先，从下到上，从右到左遍历器
typedef CNodeBackwardIterator<CNode, CGetIndexLR, CQueueAdpter<CNode*>> CNBBRLIter;