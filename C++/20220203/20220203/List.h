#pragma once
#include <iostream>
#include <assert.h>

using namespace std;


template <typename T>
struct _tagNode
{
	T			m_Data;
	_tagNode*	m_pNextNode;
	_tagNode*	m_pPrevNode;

	_tagNode()
		: m_Data()
		, m_pNextNode(nullptr)
		, m_pPrevNode(nullptr)
	{
	}

	_tagNode(T _Data, _tagNode* _pNext, _tagNode _pPrev)
		: m_Data(_Data)
		, m_pNextNode(_pNext)
		, m_pPrevNode(_pPrev)
	{
	}

};

template <typename T>
class CList	
{
private:
	_tagNode*	m_Head;
	_tagNode*	m_Tail;
	int			m_iCount;

public:
	CList();
	~CList();
	void Push_back(const T& _Data);
	void Push_front(const T& _Data);
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data); // 지정한 iterator 사이에 끼워 넣음

public:
	class iterator
	{
		friend class CList;
	private:
		CList<T>*		m_pList;
		_tagNode<T>*	m_pCurrentNode; // 이게 nullptr일때 end iterator
										// 생각해보면 당연함
										// end iterator은 마지막 다음node라 nullptr이고
										// node가 하나도 없을때
										// begin iterator(head)는 null이니까 end
										// 따라서 node가 null이면 end iterator
		bool			m_bvalid;

	public:
		iterator()
			: m_pList(nullptr)
			, m_pCurrentNode(nullptr)
			, m_bvalid(false)
		{

		}
		iterator(CList<T>* _pList, _tagNode<T>* _pNode)
			: m_pList(_pList)
			, m_pCurrentNode(_pNode)
			, m_bvalid(false)
		{
			if (nullptr != m_pList && nullptr != m_pCurrentNode)
				m_bvalid = true;
		}
		~iterator()
		{
		}

		T& operator * ()
		{
			return m_pCurrentNode->m_Data;
		}
		
		bool operator == (const iterator& _iter)
		{
			if (m_pList == _iter.m_pList && m_pCurrentNode == _iter.m_pCurrentNode)
				return true;

			return false;
			
		}

		bool operator != (const iterator& _iter)
		{
			return !(this == _iter);
		}

		iterator& operator ++ ()
		{
			if (nullptr == m_pCurrentNode || !m_bvalid)
				assert(nullptr);

			m_pCurrentNode = m_pCurrentNode->m_pNextNode;
		}

			iterator copy_iter
		iterator& operator ++ (int)
		{(*this);

			++(*this);

			return copy_iter;

		}

		iterator& operator -- ()
		{
			if (nullptr == m_pCurrentNode || !m_bvalid)
				assert(nullptr);

			m_pCurrentNode = m_pCurrentNode->m_pPrevNode;
		}

		iterator& operator -- (int)
		{
			iterator copy_iter(*this);

			--(*this);

			return copy_iter;
		}



	}

};

template <typename T>
CList<T>::CList()
	: m_Head(nullptr)
	, m_Tail(nullptr)
	, m_iCount(0)
{
}

template <typename T>
CList<T>::~CList()
{

}

template <typename T>
void CList<T>::Push_back(const T& _Data)
{
	_tagNode<T> NewNode = new _tagNode<T> (_Data, m_Tail, nullptr);


	m_Tail->m_pNextNode = NewNode;

	m_Tail = NewNode;

	++m_iCount;
}


template <typename T>
void CList<T>::Push_front(const T& _Data)
{
	_tagNode<T>* NewNode = new _tagNode<T>(_Data, nullptr, m_Head);


	m_Head->m_pPrevNode= NewNode;

	m_Head = NewNode;
	
	++m_iCount;
}


// inline 함수
// 클래스의 함수를 헤더에 구현하면 inline 처리하겠다고 받아들임
// 해당 함수를 호출하는 쪽에 코드를 그대로 붙여놓는것
// 호출 비용 생기지 않음
// inline 지웠어도 inline 되고 있음
// 근데 inline 처리 한다고 컴파일러가 전부 inline 처리하지 않음
// => 예를들어 코드가 엄청 긴데 여러군데 출몰하면 코드의 길이가 너무 길어짐

// inline 처리 하기 좋은 함수란
// => 매우 짧고 자주 호출하는 함수 (getter setter)


template <typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_Head);
}

template <typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator & _iter)
{
	if (end() == _iter)
		assert(nullptr);


	_tagNode<T>* pPrevNode = _iter.m_pCurrentNode->m_pPrevNode;
	_tagNode<T>* pNextNode = _iter.m_pCurrentNode->m_pPrevNode;

	pPrevNode->m_pNextNode = pNextNode;
	pNextNode->m_pPrevNode = pPrevNode;

	delete _iter.m_PCurrentNode;

	--m_iCount;

	return iterator();
}

template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator & _iter, const T & _data)
{
	if (end() == _iter)
		assert(nullptr);


	_tagNode<T>* pNode = new _tagNode<T>(_data, nullptr, nullptr);


	if (_iter.m_pCurrentNode == m_Head)
	{
		_iter.m_pCurrentNode->m_pPrevNode = pNode;
		pNode->m_pNextNode = _iter.m_pCurrentNode;
		m_Head = pNode;
	}


	_tagNode<T>* pPrevNode = _iter.m_pCurrentNode->m_pPrevNode;



	pPrevNode->m_pNextNode = pNode;
	pNode->m_pPrevNode = pPrevNode;

	_iter.m_pCurrentNode->m_pPrevNode = pNode;
	pNode->m_pNextNode = _iter.m_pCurrentNode;


	++m_iCount;


	return iterator(this, pNode);
}

