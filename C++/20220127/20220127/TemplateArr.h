#pragma once

#include <iostream>
using namespace std;


// ���ø��� ��������� �����ؾ� �Ѵ�.
// ����� cpp�� ����� �����ϸ� �����Լ����� ���ø����� ���� �ص� �Լ��鿡 ���ø� �ڷ����� �־ ����Ҷ� ������ ������ ������
// cpp�� ������ �ɶ��� �ش� ���ø� �ڷ����� �� �Լ����� ��� �ȿ��� ����
// �� main���� T�� int�� ���Ÿ� cpp������ �� ���� ����

// ���� Ŭ������ �Լ����� cpp�� ������ ��� ���� �Լ��� �������� ���������
// ���ø��� �ٷ� ����� �ȵǰ� type�� ���������� ��������ϱ� ����� �ƴ� ��


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
CTemplateArr<T>::CTemplateArr() // type T�� ���� �����ڸ� ����ٴ� �� 
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

void CTemplateArr<T>::PushBack(const T& _Data) // T �ڷ����� ũ�Ⱑ ũ�� ���������� ����� �� ���������� �����ϴ°� ��ü�� ��ȿ�����̴ϱ� ������ �ּҸ� �ѱ��
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




