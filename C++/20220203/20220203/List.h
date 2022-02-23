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
	iterator insert(const iterator& _iter, const T& _data); // ������ iterator ���̿� ���� ����

public:
	class iterator
	{
		friend class CList;
	private:
		CList<T>*		m_pList;
		_tagNode<T>*	m_pCurrentNode; // �̰� nullptr�϶� end iterator
										// �����غ��� �翬��
										// end iterator�� ������ ����node�� nullptr�̰�
										// node�� �ϳ��� ������
										// begin iterator(head)�� null�̴ϱ� end
										// ���� node�� null�̸� end iterator
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


// inline �Լ�
// Ŭ������ �Լ��� ����� �����ϸ� inline ó���ϰڴٰ� �޾Ƶ���
// �ش� �Լ��� ȣ���ϴ� �ʿ� �ڵ带 �״�� �ٿ����°�
// ȣ�� ��� ������ ����
// inline ����� inline �ǰ� ����
// �ٵ� inline ó�� �Ѵٰ� �����Ϸ��� ���� inline ó������ ����
// => ������� �ڵ尡 ��û �䵥 �������� ����ϸ� �ڵ��� ���̰� �ʹ� �����

// inline ó�� �ϱ� ���� �Լ���
// => �ſ� ª�� ���� ȣ���ϴ� �Լ� (getter setter)


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

