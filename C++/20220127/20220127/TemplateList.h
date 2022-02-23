#pragma once


// c++���� ����ü�� c++������ Ŭ������ ���� ����
// ����ü�� ������ �Ҹ��� �� ����
// ���� ���̸� �����ڸ�
// ����ü�� ����Ʈ�� ���������� public�̰� Ŭ������ private��

// ��带 Ŭ������ �����ص� ������
// ���� ���� ����� �������� �ʰ� �����͸� ����Ѷ� ������ ����ü ����� ���� �� ����
template <typename T>
struct _tagNode
{
	T				Data;
	_tagNode<T>*	pPrevNode;
	_tagNode<T>*	pNextNode;

	// ����ü ������
	_tagNode()
		: data()
		, pPrevNode(nullptr)
		, pNextNode(nullptr)
	{
	}
	// ������ �����ε�
	_tagNode(const T& _data, _tagNode _pPrev, _tagNode<T>* _pNext)
		: data(_data)
		, pPrevNode(_pPrev)
		, pNextNode(_pNext)
	{

	}
};


template <typename T>
class CTemplateList
{
private:
	_tagNode<T>*	m_pHeadNode;
	_tagNode<T>*	m_pTailNode;
	int				m_iCount;

public:
	void PushBack(const T& _Data);
	void PushFront(const T& _Data);
	void ReleaseNode(_tagNode<T>* _pNode);
	void ReleaseList();

public:
	CTemplateList();
	~CTemplateList();
};

template <typename T>
CTemplateList<T>::CTemplateList()
	: m_pHeadNode(nullptr)
	, m_pTailNode(nullptr)
	, m_iCount(0)
{

}

template <typename T>
CTemplateList<T>::~CTemplateList()
{
	ReleaseList();
	m_iCount = 0;
}

template <typename T>
void CTemplateList<T>::PushBack(const T& _Data)
{
	// ��屸��ü �ʱ�ȭ �Լ��� ����ؼ� ���ϰ� ��� ����
	_tagNode<T>* pNewNode = new _tagNode<T> (_Data, nullptr, nullptr);

	
	// ó�� �Էµ� �����͸�
	if (0 == m_iCount)
	{
		m_pHeadNode = pNewNode;
		m_pTailNode = pNewNode;
	}
	else
	{
		m_pTailNode->pNextNode = pNewNode;
		pNewNode->pPrevNode = m_pTailNode;
		m_pTailNode = pNewNode;
	}


	++m_iCount;
}

template <typename T>
void CTemplateList<T>::PushFront(const T& _Data)
{
	_tagNode<T>* pNewNode = new _tagNode<T>(_Data, nullptr, nullptr);


	// ó�� �Էµ� �����͸�
	if (0 = = m_iCount)
	{
		m_pHeadNode = pNewNode;
		m_pTailNode = pNewNode;
	}
	else
	{
		m_pHeadNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = m_pHeadNode;
		m_pHeadNode = pNewNode;
	}


	++m_iCount;
}


template <typename T>
void CTemplateList<T>::ReleaseNode(_tagNode<T>* _pNode)
{
	if (nullptr == _pNode)
		return;

	
	delete _pNode;
}

template <typename T>
void CTemplateList<T>::ReleaseList()
{
	_tagNode<T>* pNode = m_pHeadNode;
	while (pNode)
	{
		_tagNode<T>* pNextNode = pNode->pNextNode;
		delete pNode;
		pNode = pNextNode;

	}
}