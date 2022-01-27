#include "Arr.h"



void InitArr(Arr * _pArr)
{

	_pArr->pint = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;

}

void PushBack(Arr * _pArr, int _pData)
{
	if (_pArr->iMaxCount <= _pArr->iCount)
		Reallocate(_pArr);

	_pArr->pint[_pArr->iCount++] = _pData;
}

void Reallocate(Arr * _pArr)
{
	int* pNewint = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	for (int i = 0; i < _pArr->iCount; ++i)
		pNewint[i] = _pArr->pint[i];

	_pArr->iMaxCount *= 2;

	free(_pArr->pint);
	_pArr->pint = pNewint;
}

void Release(Arr * _pArr)
{
	if (_pArr != nullptr)
		free(_pArr->pint);

	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void BubbleSort(Arr* _pArr)
{
	int temp;

	if (_pArr->iCount <= 1)
		return;

	for (int i = 0; i < _pArr->iCount - 1; ++i)
	{
		for (int j = i + 1; j < _pArr->iCount; ++j)
		{

			if (_pArr->pint[i] > _pArr->pint[j])
			{
				temp = _pArr->pint[i];
				_pArr->pint[i] = _pArr->pint[j];
				_pArr->pint[j] = temp;
			}
		}
	}
}
