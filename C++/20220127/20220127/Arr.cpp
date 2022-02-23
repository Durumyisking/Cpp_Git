#include "Arr.h"




CArr::CArr()		
{
	m_iCount = 0;
	m_iMaxCount = 2;
	m_pint = (int*)malloc(sizeof(int) * m_iMaxCount);
}


CArr::~CArr()
{
	if(nullptr !=m_pint)
		free(m_pint);
	m_iCount = 0;
	m_iMaxCount = 0;
}

void CArr::PushBack(int _iData)
{

	if (m_iCount >= m_iMaxCount)
		Reallocate(m_iMaxCount * 2);

	m_pint[m_iCount++] = _iData;

}

void CArr::Reallocate(int _iNewCount)
{
	int* pNewint = new int[_iNewCount];

	for (int i = 0; i < m_iCount; ++i)
		pNewint[i] = m_pint[i];

	delete[] m_pint;
	m_pint = pNewint;

	m_iMaxCount *= 2;
}

void CArr::BubbleSort()
{
	int temp;

	if (m_iCount <= 1)
		return;

	for (int i = 0; i < m_iCount - 1; ++i)
	{
		for (int j = i+1; j < m_iCount; ++j)
		{ 
			if (m_pint[i] > m_pint[j])
			{
				temp = m_pint[i];
				m_pint[i] = m_pint[j];
				m_pint[j] = temp;
			}
		}
	}
}

//int* CArr::operator [] (int _iIndex)  이렇게 하면 []를 사용할때 *arr[index] 이렇게 해야댐
//{
//	return 	(m_pint + _iIndex);
//}

int CArr::operator [] (int _iIndex)
{
	return m_pint[_iIndex];
}