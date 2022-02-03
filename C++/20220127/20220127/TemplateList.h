#pragma once


// c++에서 구조체와 c++에서의 클래스는 서로 같음
// 구조체도 생성자 소멸자 다 가능
// 굳이 차이를 따지자면
// 구조체는 디폴트로 선언했을때 public이고 클래스는 private임

// 노드를 클래스로 선언해도 되지만
// 딱히 많은 기능을 지원하지 않고 데이터를 묶어둘때 정도는 구조체 사용이 편할 수 있음
template <typename T>
struct _tagNode
{
	T				Data;
	_tagNode<T>*	pPrevNode;
	_tagNode<T>*	pNextNode;

	// 구조체 생성자
	_tagNode()
		: data()
		, pPrevNode(nullptr)
		, pNextNode(nullptr)
	{
	}
	// 생성자 오버로딩
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
	// 노드구조체 초기화 함수를 사용해서 편하게 노드 생성
	_tagNode<T>* pNewNode = new _tagNode<T> (_Data, nullptr, nullptr);

	
	// 처음 입력된 데이터면
	if (0 = = m_iCount)
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


	// 처음 입력된 데이터면
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

	Release(_pNode->pNextNode);
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