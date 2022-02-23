#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
class CArr
{
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;

public:
	CArr();
	~CArr();

public:
	void Push_back(const T& _Data);
	void resize(int _iResizeCount);
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator [] (int _idx);
	void clear() { m_iCount = 0; }

	class iterator;
	iterator begin();
	iterator end(); 
	iterator erase(iterator& _iter);

public:
	// iterator은 inner class로 만든다.
	// 클래스가 안에 선언되어 있다고 CArr 객체의 할당 용량이 늘어나지 않음
	// inner class는 부모 클래스의 private 멤버에 접근이 가능하다
	class iterator
	{
	private:
		CArr*	m_pArr;	// iterator의 기존 배열이 reallocate되어서 위치가 바뀌어도
						// iterator가 가리키는 위치가 배열의 idx만을 중요시하면 m_pArr 변수가 없어도 되지만
						// reallocate되어서 위치가 바뀌였을때 배열의 시작 주소가 바뀐것을 확인하려면 필요함
		T*		m_pData;
		int		m_iIdx;
		bool	m_bValid; // 유효한 iterator인지 확인

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1) // 아무 데이터 없을때 end iterator라는 것
			, m_bValid(false)
		{
		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
		: m_pArr(_pArr)
		, m_pData(_pData)
		, m_iIdx(_iIdx)
		, m_bValid(false)
		{
			if (nullptr != _pArr && 0 <= _iIdx)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		// friend 선언
		friend class CVector;
		// 원래는 CVector 객체는 inner class인 iterator의 private멤버에 접근이 불가능하지만
		// 이렇게 friend 클래스로 선언하면 접근이 가능해진다
		// ********** CVector에서 iterator를 friend 선언하는게 아니라 iterator에서 CVector에 friend 해줘야함
		// 간단히 생각해서 CVector가 iterator한테 돈빌릴려면 iterator가 CVector를 친구라고 인정해줘야 되는거자나
		// 보통 안하는게 좋긴 한데
		// CVector이랑 iterator가 긴밀한 관계기도하고 심지어 inner클래스기도 하니까



	public:
		T& operator * ()
		{
			if (this->m_pData != m_pData || -1 == m_iIdx || !m_bValid) // 기존 배열의 첫 주소와 iterator가 가리키는 주소가 일치하는지 확인
															// -1은 end iterator(마지막 idx의 다음) 이면 비교할 수 없으니까
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// 전위
		iterator& operator ++ ()
		{
			if (-1 == m_iIdx || m_pArr->m_pData != m_pData)
				assert(nullptr);
			else if (m_pArr->size() - 1 == m_iIdx)
				m_iIdx = -1;
			else
				++m_iIdx;

			return *this;
		}

		// 후위
		// 반환타입이 전위연산지와 같으면 operator 처리했을때 그 줄에서 처리되기 때문에 후위가 안됨
		// 따라서 참조하지말고 복사본을 넘겨주어야함
		iterator operator ++ (int) // 인자에 자료형 하나를 넣어줌 main에서 ++을 후위에 붙였을때 이 함수로 들어옴
		{
			iterator copy_iter = *this; // 함수 호출한 iterator(아직 ++로 증가하지 않은객체)랑 똑같이 만들어줌

			++(*this); // this를 증가시킴 (실제 iterator은 증가가 되어있음)


			return copy_iter();	// 증가하지 않은 iterator 반환
								// 따라서 증가하기 전 상황의 복사본을 반환시킴
								// 그래서 사용한 함수 내에서는 증가를 안했지만
								// 다음에 this를 사용하면 증가되어있음
								// 이게 왠만해서는 전위연산자를 쓰라는 이유임
								// 일단 함수를 두 번타고 ref를 안하기 때문에 새로운 객체(copy_iter)를 만들어줘야함
		}

		iterator& operator -- ()
		{
			if (0 == m_iIdx || m_pArr->m_pData != m_pData)
				assert(nullptr);


			--m_iIdx;

			return *this;
		}

		iterator operator -- (int)
		{
			iterator copy_iter = *this;

			--(*this);	

			return copy_iter;
		}
		
		bool operator == (const iterator& _iter)
		{
			if ((m_pData == _iter.m_pData) && (m_iIdx == _iter.m_iIdx))
				return true;

			return false;
		}


		bool operator != (const iterator& _iter)
		{
			return !(*this == _iter); // 바로 위의 == operator을 활용
		}
		
	};
};

template<typename T>
 CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[m_iMaxCount];
}

template<typename T>
 CArr<T>::~CArr()
{
}

template<typename T>
 void CArr<T>::Push_back(const T & _Data)
{
	if (m_iCount >= m_iMaxCount)
		resize(m_iMaxCount * 2);

	m_pData[m_iCount] = _Data;
	++m_iCount;

}

template<typename T>
 void CArr<T>::resize(int _iResizeCount)
{
	T* newData = new T[_iResizeCount];

	for (int i = 0; i < m_iCount; ++i)
		newData[i] = m_pData[i];

	delete [] m_pData;
	m_pData = newData;

	m_iMaxCount *= 2;
	
}

template<typename T>
T& CArr<T>::operator[](int _idx)
{
	return m_pData[_idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin() // typename을 적는 이유는 CArr안의 iterator가 특정 type이라는 것을 알려줘야함
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);

	return iterator(this, m_pData, 0); // 임시객체 : 변수명을 지어주지 않고 바로 반환 가능 => 변수명이 없어서 만들어질때 빼고는 접근 불가능
}




// iterator의 end는 마지막 인덱스의 다음 인덱스를 가리킨다
// 따라서 vector에 데이터가 하나도 없을때는 begin이 존재하지 않을때
// end iterator밖에 존재하지 않음 따라서 비어있는 벡터의 begin은 end다
// 우리는 end idx를 -1로 하기로 한다.
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_pData, -1);
}


// iterator가 가리키는 부분을 삭제
// 메모리 자체를 삭제하는것
// 가변배열에서 erase는 비어있는 부분이 생기면 다시 당겨와야서 채워야댐
template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{

	// iterator가 가리키는 배열이랑 이 함수를 불러온 배열이랑 다르면 당연히 안되겠죠^^?
	// 당연히 end iterator은 배열의 마지막 idx의 다음 idx를 가리키는건데 삭제가 불가능하죠
	// idx가 배열 크기 넘어가면 안되겠쬬
	if (this != _iter.m_pArr || end()  == _iter || m_iMaxCount <= _iter.m_iIdx)	
		assert(nullptr);


	// iterator가 가리키는 데이터를 배열에서 제거
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}
	_iter.m_bValid = false;

	--m_iCount;


	return iterator(this, m_pData, _iter.m_iIdx);
}