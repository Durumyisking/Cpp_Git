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
	// iterator�� inner class�� �����.
	// Ŭ������ �ȿ� ����Ǿ� �ִٰ� CArr ��ü�� �Ҵ� �뷮�� �þ�� ����
	// inner class�� �θ� Ŭ������ private ����� ������ �����ϴ�
	class iterator
	{
	private:
		CArr*	m_pArr;	// iterator�� ���� �迭�� reallocate�Ǿ ��ġ�� �ٲ�
						// iterator�� ����Ű�� ��ġ�� �迭�� idx���� �߿���ϸ� m_pArr ������ ��� ������
						// reallocate�Ǿ ��ġ�� �ٲ���� �迭�� ���� �ּҰ� �ٲ���� Ȯ���Ϸ��� �ʿ���
		T*		m_pData;
		int		m_iIdx;
		bool	m_bValid; // ��ȿ�� iterator���� Ȯ��

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1) // �ƹ� ������ ������ end iterator��� ��
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

		// friend ����
		friend class CVector;
		// ������ CVector ��ü�� inner class�� iterator�� private����� ������ �Ұ���������
		// �̷��� friend Ŭ������ �����ϸ� ������ ����������
		// ********** CVector���� iterator�� friend �����ϴ°� �ƴ϶� iterator���� CVector�� friend �������
		// ������ �����ؼ� CVector�� iterator���� ���������� iterator�� CVector�� ģ����� ��������� �Ǵ°��ڳ�
		// ���� ���ϴ°� ���� �ѵ�
		// CVector�̶� iterator�� ����� ����⵵�ϰ� ������ innerŬ�����⵵ �ϴϱ�



	public:
		T& operator * ()
		{
			if (this->m_pData != m_pData || -1 == m_iIdx || !m_bValid) // ���� �迭�� ù �ּҿ� iterator�� ����Ű�� �ּҰ� ��ġ�ϴ��� Ȯ��
															// -1�� end iterator(������ idx�� ����) �̸� ���� �� �����ϱ�
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// ����
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

		// ����
		// ��ȯŸ���� ������������ ������ operator ó�������� �� �ٿ��� ó���Ǳ� ������ ������ �ȵ�
		// ���� ������������ ���纻�� �Ѱ��־����
		iterator operator ++ (int) // ���ڿ� �ڷ��� �ϳ��� �־��� main���� ++�� ������ �ٿ����� �� �Լ��� ����
		{
			iterator copy_iter = *this; // �Լ� ȣ���� iterator(���� ++�� �������� ������ü)�� �Ȱ��� �������

			++(*this); // this�� ������Ŵ (���� iterator�� ������ �Ǿ�����)


			return copy_iter();	// �������� ���� iterator ��ȯ
								// ���� �����ϱ� �� ��Ȳ�� ���纻�� ��ȯ��Ŵ
								// �׷��� ����� �Լ� �������� ������ ��������
								// ������ this�� ����ϸ� �����Ǿ�����
								// �̰� �ظ��ؼ��� ���������ڸ� ����� ������
								// �ϴ� �Լ��� �� ��Ÿ�� ref�� ���ϱ� ������ ���ο� ��ü(copy_iter)�� ����������
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
			return !(*this == _iter); // �ٷ� ���� == operator�� Ȱ��
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
typename CArr<T>::iterator CArr<T>::begin() // typename�� ���� ������ CArr���� iterator�� Ư�� type�̶�� ���� �˷������
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);

	return iterator(this, m_pData, 0); // �ӽð�ü : �������� �������� �ʰ� �ٷ� ��ȯ ���� => �������� ��� ��������� ����� ���� �Ұ���
}




// iterator�� end�� ������ �ε����� ���� �ε����� ����Ų��
// ���� vector�� �����Ͱ� �ϳ��� �������� begin�� �������� ������
// end iterator�ۿ� �������� ���� ���� ����ִ� ������ begin�� end��
// �츮�� end idx�� -1�� �ϱ�� �Ѵ�.
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_pData, -1);
}


// iterator�� ����Ű�� �κ��� ����
// �޸� ��ü�� �����ϴ°�
// �����迭���� erase�� ����ִ� �κ��� ����� �ٽ� ��ܿ;߼� ä���ߴ�
template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{

	// iterator�� ����Ű�� �迭�̶� �� �Լ��� �ҷ��� �迭�̶� �ٸ��� �翬�� �ȵǰ���^^?
	// �翬�� end iterator�� �迭�� ������ idx�� ���� idx�� ����Ű�°ǵ� ������ �Ұ�������
	// idx�� �迭 ũ�� �Ѿ�� �ȵǰڧc
	if (this != _iter.m_pArr || end()  == _iter || m_iMaxCount <= _iter.m_iIdx)	
		assert(nullptr);


	// iterator�� ����Ű�� �����͸� �迭���� ����
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}
	_iter.m_bValid = false;

	--m_iCount;


	return iterator(this, m_pData, _iter.m_iIdx);
}