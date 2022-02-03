#pragma once

#include <iostream>
using namespace std;


// 템플릿은 헤더에서만 구현해야 한다.
// 헤더와 cpp로 나누어서 구현하면 메인함수에서 템플릿에서 선언만 해둔 함수들에 템플릿 자료형을 넣어서 사용할때 오류가 생기지 않지만
// cpp가 컴파일 될때는 해당 템플릿 자료형이 들어간 함수들은 헤더 안에는 없음
// 즉 main에서 T에 int가 들어간거를 cpp에서는 알 수가 없음

// 기존 클래스나 함수들은 cpp에 갔을때 즉시 사용될 함수라서 컴파일이 진행되지만
// 템플릿은 바로 사용이 안되고 type이 정해져야지 만들어지니까 헤더만 아는 것


template <typename T>
class CTemplateArr
{
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;
public:
	CTemplateArr();
	~CTemplateArr();

public:
	void PushBack(const T& _Data);
	void Reallocate(int _iNewCount);
	void BubbleSort();
	T& operator [] (int _iIndex);
};

template <typename T>
CTemplateArr<T>::CTemplateArr() // type T에 대한 생성자를 만든다는 뜻 
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}

template <typename T>
CTemplateArr<T>::~CTemplateArr()
{
	if (nullptr != m_pData)
		free(m_pData);
	m_iCount = 0;
	m_iMaxCount = 0;
}
template <typename T>

void CTemplateArr<T>::PushBack(const T& _Data) // T 자료형의 크기가 크면 지역변수로 사용할 때 지역변수를 복사하는것 자체가 비효율적이니까 참조나 주소를 넘긴다
{

	if (m_iCount >= m_iMaxCount)
		Reallocate(m_iMaxCount * 2);

	m_pData[m_iCount++] = _Data;

}

template <typename T>
void CTemplateArr<T>::Reallocate(int _iNewCount)
{
	T* pNewData = new T[_iNewCount];

	for (int i = 0; i < m_iCount; ++i)
		pNewData[i] = m_pData[i];

	delete[] m_pData;
	m_pData = pNewData;

	m_iMaxCount *= 2;
}

template <typename T>
void CTemplateArr<T>::BubbleSort()
{
	int temp;

	if (m_iCount <= 1)
		return;

	for (int i = 0; i < m_iCount - 1; ++i)
	{
		for (int j = i + 1; j < m_iCount; ++j)
		{
			if (m_pData[i] > m_pData[j])
			{
				temp = m_pData[i];
				m_pData[i] = m_pData[j];
				m_pData[j] = temp;
			}
		}
	}
}


template <typename T>
T& CTemplateArr<T>::operator [] (int _iIndex) 
{
	return m_pData[_iIndex];
}




