#pragma once

#include <iostream>
using namespace std;

class CArr
{
private:
	int*		m_pint;
	int		m_iCount;
	int		m_iMaxCount;
public:
	CArr();
	~CArr();

public:
	void PushBack(int _iData);
	void Reallocate(int _iNewCount);
	void BubbleSort();
	int operator [](int _iIndex);

};


