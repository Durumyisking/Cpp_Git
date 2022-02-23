#pragma once

#include <iostream>
#include <assert.h>

#include <map>
#include <set>
#include <string>

// 트리는 순회가 되지 않는 그래프이다
// 트리는 계층관계로 이루어져있다.

// 트리의 레벨(높이)
// 최상위 부모(루트)를 레벨0으로보고
// 가장 최하위의 자식의 레벨을 트리의 높이로 봄

// 최하위 레벨의 노드들을 (리프, 말단노드)라고 부름

// 이진트리
// 자식을 최대 두 개만 가질 수 있는 트리
// (힙 이라는 자료구조를 만들 때 사용됨)

// 완전 이진트리
// 항상 꽉꽉 채워가는 형태의 이진트리
// 항상 위쪽 레벨부터 왼쪽 자식부터 꽉꽉 채운다.
// 보통 배열로 구현한다

// 첫번째 자식의 idx = 2부모idx + 1
// 두번째 자식의 idx = 2부모idx + 2

// 특정 idx의 부모 = (idx - 1) / 2 의 몫

// 배열 형태
// ex)	루트노드 = idx 0
//		루트왼쪽 = idx 1
//		루트오른 = idx 2

// 탐색 이진트리 : 이진트리중 탐색을 할 수 있는 이진트리


// 이진탐색
// 이진탐색의 조건

// *******정렬된 데이터*******
// 데이터를 절반씩 나눠서 탐색
// 최악 = O(log2(N)) // 매번 문제를 2등분 하니까 log2야


// ex ) 오름차순을 정렬된 값들중 수를 찾는다고치자
// 1. 전체 idx중 중앙 idx에 접근
// 2. 찾으려는값이 중앙보다 작으면 오른쪽 idx 제외
// 1 2번 무한 반복


// 이진탐색은 겁나 효율적이지만 정렬이 필수적임
// 그래서 데이터를 넣을때
// 루트부터 시작해서 부모노드 기준으로
// 루트보다 작은 값은 왼쪽 큰 값은 오른쪽에 대입

// 데이터 입력할때 좀 손해를 봄
// 하지만 게임이라고 쳤을때 데이터를 입력하는 시간을 로딩시간
// 플레이 하는 시간을 탐색시간이라고 하면
// 로딩시간이 아무리 길어도 플레이 하는시간에서 문제가 안생기는게 나음


// 데이터 삽입도 탐색과 똑같음
// 절반씩 비교하면서 자리 찾아감
// 그러니까 log2(N)임
// 리스트나 벡터같이 삽입 시간이 O(1)인거에 비해 느리지만 그래도 빨라


// 전위순회 (pre order)
// 부모 - 왼쪽 - 오른쪽
// 1. 말단 노드를 만날 때 까지 쭈욱 왼쪽으로 노드들 방문하면서 내려김
// 2. 말단 노드를 만났으면 다시 올라가면서 부모들의 오른쪽도 확인


// 중위순회 (in order) : 중위순회로 조져야지 오름차순 나옴
// 왼쪽 - 부모 - 오른쪽 우선순위
// 1. 말단 노드를 만날 때 까지 왼쪽으로 노드들 방문하지 않으면서 내려감
// 2. 말단 노드를 만났으면 방문하면서 다시 올라가면서 부모들 오른쪽도 확인


// 후위순회 (post order)
// 왼쪽 - 오른쪽 - 부모


// 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 안나옴
// 실제 프로그래밍에서 이진탐색트리에서 탐색 알고리즘을 구현할 때
// self balanced
// 자가 균형 기능이 구현되어있는 트리
// AVL, Red Black tree (std::map, set에 구현)


enum class NODE_TYPE
{
	PARENT,
	LCHILD,
	RCHILD,
	END
};



template <typename T1, typename T2>  // <key type // 비교대상, data type>
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

	// 노드간의 관계 포인터
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
	tBSTNode<T1, T2>*	m_pRoot;	// 루트 노드 주소
	int					m_iCount;	// 데이터 개수

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
		tBSTNode<T1, T2>*	m_pNode; // null이면 end iterator

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
			// m_pNode nullptr 체크
			assert(m_pNode);

			return m_pNode->pair;	
		}
		
		const tPair<T1, T2>* operator -> ()
		{
			// m_pNode nullptr 체크
			assert(m_pNode);

			return &m_pNode->pair;
		}

		iterator& operator ++()
		{
			// 현재 트리의 중위 후속자(중위 순회에서의 다음 순서)를 얻으면 종료
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

	// 1. 오른쪽 자식이 있는 경우
	//		오른쪽 자식으로 가서 왼쪽 자식이 없을 때 까지 내려감
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];

		}
	}
	// 2. 부모로부터 자신이 왼쪽 자식일 때 까지 위로 올라감
	//		그때의 부모가 후속자
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

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD]) // 왼쪽자식이 존재하면
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
			// 찾으면 현재 노드 반환
			break;


		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// 못찾으면 node를 end iterator로 바꿈
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