#pragma once

#include <iostream>
#include <assert.h>

#include <map>
#include <set>
#include <string>

// Ʈ���� ��ȸ�� ���� �ʴ� �׷����̴�
// Ʈ���� ��������� �̷�����ִ�.

// Ʈ���� ����(����)
// �ֻ��� �θ�(��Ʈ)�� ����0���κ���
// ���� �������� �ڽ��� ������ Ʈ���� ���̷� ��

// ������ ������ ������ (����, ���ܳ��)��� �θ�

// ����Ʈ��
// �ڽ��� �ִ� �� ���� ���� �� �ִ� Ʈ��
// (�� �̶�� �ڷᱸ���� ���� �� ����)

// ���� ����Ʈ��
// �׻� �˲� ä������ ������ ����Ʈ��
// �׻� ���� �������� ���� �ڽĺ��� �˲� ä���.
// ���� �迭�� �����Ѵ�

// ù��° �ڽ��� idx = 2�θ�idx + 1
// �ι�° �ڽ��� idx = 2�θ�idx + 2

// Ư�� idx�� �θ� = (idx - 1) / 2 �� ��

// �迭 ����
// ex)	��Ʈ��� = idx 0
//		��Ʈ���� = idx 1
//		��Ʈ���� = idx 2

// Ž�� ����Ʈ�� : ����Ʈ���� Ž���� �� �� �ִ� ����Ʈ��


// ����Ž��
// ����Ž���� ����

// *******���ĵ� ������*******
// �����͸� ���ݾ� ������ Ž��
// �־� = O(log2(N)) // �Ź� ������ 2��� �ϴϱ� log2��


// ex ) ���������� ���ĵ� ������ ���� ã�´ٰ�ġ��
// 1. ��ü idx�� �߾� idx�� ����
// 2. ã�����°��� �߾Ӻ��� ������ ������ idx ����
// 1 2�� ���� �ݺ�


// ����Ž���� �̳� ȿ���������� ������ �ʼ�����
// �׷��� �����͸� ������
// ��Ʈ���� �����ؼ� �θ��� ��������
// ��Ʈ���� ���� ���� ���� ū ���� �����ʿ� ����

// ������ �Է��Ҷ� �� ���ظ� ��
// ������ �����̶�� ������ �����͸� �Է��ϴ� �ð��� �ε��ð�
// �÷��� �ϴ� �ð��� Ž���ð��̶�� �ϸ�
// �ε��ð��� �ƹ��� �� �÷��� �ϴ½ð����� ������ �Ȼ���°� ����


// ������ ���Ե� Ž���� �Ȱ���
// ���ݾ� ���ϸ鼭 �ڸ� ã�ư�
// �׷��ϱ� log2(N)��
// ����Ʈ�� ���Ͱ��� ���� �ð��� O(1)�ΰſ� ���� �������� �׷��� ����


// ������ȸ (pre order)
// �θ� - ���� - ������
// 1. ���� ��带 ���� �� ���� �޿� �������� ���� �湮�ϸ鼭 ������
// 2. ���� ��带 �������� �ٽ� �ö󰡸鼭 �θ���� �����ʵ� Ȯ��


// ������ȸ (in order) : ������ȸ�� �������� �������� ����
// ���� - �θ� - ������ �켱����
// 1. ���� ��带 ���� �� ���� �������� ���� �湮���� �����鼭 ������
// 2. ���� ��带 �������� �湮�ϸ鼭 �ٽ� �ö󰡸鼭 �θ�� �����ʵ� Ȯ��


// ������ȸ (post order)
// ���� - ������ - �θ�


// Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� �ȳ���
// ���� ���α׷��ֿ��� ����Ž��Ʈ������ Ž�� �˰����� ������ ��
// self balanced
// �ڰ� ���� ����� �����Ǿ��ִ� Ʈ��
// AVL, Red Black tree (std::map, set�� ����)


enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	END
};



template <typename T1, typename T2>  // <key type // �񱳴��, data type>
struct tPair
{
	T1 first;
	T2 second;
};

template <typename T1, typename T2>
tPair<T1, T2> make_bstPair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{_first, _second};
}

template <typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2>	pair;

	// ��尣�� ���� ������
	tBSTNode*		arrNode[(int)NODE_TYPE::END];

	bool IsRoot()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}

	bool IsLeaf()
	{
		if ((nullptr == arrNode[(int)NODE_TYPE::LCHILD]) && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

	bool IsFull()
	{
		if ((nullptr != arrNode[(int)NODE_TYPE::LCHILD]) && nullptr != arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;

	}


	bool IsLeftChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}

	bool IsRightChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}



	tBSTNode()
		: pair()
		, arrNode()
	{}
	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: pair(_pair)
		, arrNode{ _pParent, _pLChild, _pRChild }
	{}
};


	template <typename T1, typename T2>
class CTree
{

private:
	tBSTNode<T1, T2>*	m_pRoot;	// ��Ʈ ��� �ּ�
	int					m_iCount;	// ������ ����

public:
	bool insert(const tPair<T1, T2>& _pair); 
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
	tBSTNode<T1, T2>* GetInOrderPreSuccessor(tBSTNode<T1, T2>* _pNode);

	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _Data);
	iterator erase(const iterator& _iter);

private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode <T1, T2>* _pNode);



public:
	CTree()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}
	~CTree()
	{}

	// iterator
	class iterator
	{
	friend class CTree<T1, T2>;

	public:
		CTree<T1, T2>*		m_pTree;
		tBSTNode<T1, T2>*	m_pNode; // null�̸� end iterator

	public:
		bool operator == (const iterator& _other)
		{
			if (m_pTree == _other.m_pTree && m_pNode == _other.m_pNode)
				return true;
			else 
				false;
		}

		bool operator != (const iterator& _other)
		{
			return (*this == _other);
		}

		
		const tPair<T1, T2>& operator * ()
		{
			// m_pNode nullptr üũ
			assert(m_pNode);

			return m_pNode->pair;	
		}
		
		const tPair<T1, T2>* operator -> ()
		{
			// m_pNode nullptr üũ
			assert(m_pNode);

			return &m_pNode->pair;
		}

		iterator& operator ++()
		{
			// ���� Ʈ���� ���� �ļ���(���� ��ȸ������ ���� ����)�� ������ ����
			m_pNode = m_pTree->GetInOrderSuccessor(m_pNode);
			return *this;
		}

		iterator& operator ++(int)
		{
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		iterator& operator --()
		{
			m_pNode = m_pTree->GetInOrderPreSuccessor(m_pNode);
			return *this;
		}

		iterator& operator --(int)
		{
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;
		}


	public:
		iterator()
			: m_pTree(nullptr)
			, m_pNode(nullptr)
		{}

		iterator(CTree<T1, T2>* _pTree, tBSTNode<T1, T2>* _pNode)
			: m_pTree(_pTree)
			, m_pNode(_pNode)
		{}

	};
};

template<typename T1, typename T2>
bool CTree<T1, T2>::insert(const tPair<T1, T2> & _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);
	pNewNode->pair = _pair;


	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{

			if (pNode->pair.first < pNewNode->pair.first)			
				node_type = NODE_TYPE::RCHILD;
			
			else if (pNode->pair.first > pNewNode->pair.first)			
				node_type = NODE_TYPE::LCHILD;			
			else			
				return false;
		

			if (nullptr == pNode->arrNode[(int)node_type])
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
				pNode = pNode->arrNode[(int)node_type];
			
		}
	}

	++m_iCount;

}

template<typename T1, typename T2>
tBSTNode<T1, T2>* CTree<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	// 1. ������ �ڽ��� �ִ� ���
	//		������ �ڽ����� ���� ���� �ڽ��� ���� �� ���� ������
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];

		}
	}
	// 2. �θ�κ��� �ڽ��� ���� �ڽ��� �� ���� ���� �ö�
	//		�׶��� �θ� �ļ���
	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			if (pSuccessor->IsRoot())
				return nullptr;

			if (pSuccessor->IsLeftChild())
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];


		}
	}


	return pSuccessor;
}

template<typename T1, typename T2>
tBSTNode<T1, T2>* CTree<T1, T2>::GetInOrderPreSuccessor(tBSTNode<T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{

		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD];
		while (pSuccessor->arrNode[(int)NODE_TYPE::RCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::RCHILD];
		}

	}

	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			if (pSuccessor->arrNode[0])
				return nullptr;

			if (pSuccessor->IsRightChild())
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];


		}
	}


	return pSuccessor;
}

template<typename T1, typename T2>
typename CTree<T1, T2>::iterator CTree<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD]) // �����ڽ��� �����ϸ�
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	} 

	return iterator(this, pNode);
}

template<typename T1, typename T2>
typename CTree<T1, T2>::iterator CTree<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
typename CTree<T1, T2>::iterator CTree<T1, T2>::find(const T1& _Data)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->pair.first < _Data)
			node_type = NODE_TYPE::RCHILD;

		else if (pNode->pair.first > _Data)
			node_type = NODE_TYPE::LCHILD;
		else
			// ã���� ���� ��� ��ȯ
			break;


		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// ��ã���� node�� end iterator�� �ٲ�
			pNode = nullptr;
			break;
		}
		else
			pNode = pNode->arrNode[(int)node_type];	
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
typename CTree<T1, T2>::iterator CTree<T1, T2>::erase(const iterator & _iter)
{
	assert(this == _iter.m_pTree);

		
	return iterator(this, DeleteNode(_iter.m_pNode);

}


template<typename T1, typename T2>
typename tBSTNode<T1, T2>* CTree<T1, T2>::DeleteNode(tBSTNode <T1, T2>* _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	if (_pNode->IsLeaf())
	{
		pSuccessor = GetInOrderSuccessor(_pNode);

		if (_pNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			if (_pNode->IsLeftChild)
				_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] nullptr;
		}
		delete _pNode;
	}
	else if (_iter.m_pNode->IsFull())
	{
		_pNode->pair = pSuccessor->pair;

		DeleteNode(pSuccessor);

		pSuccessor = _pNode;
	}
	else
	{
		pSuccessor = GetInOrderSuccessor(_pNode);
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		if (_pNode == m_pRoot)
		{
			m_pRoot = _pNode->arrNode[(int)eChildType];
			_pNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] == nullptr;

		}


		if (_pNode->IsLeftChild())
		{
			_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD]
				= _pNode->arrNode[(int)eChildType];		}
		else
		{	
			_pNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD]
				= _pNode->arrNode[(int)NODE_TYPE::eChildType];
		}
		_pNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT]
			= _pNode->arrNode[(int)NODE_TYPE::PARENT];

		delete _pNode;
	}
	--m_iCount;

	return pSuccessor;
}