#pragma once
#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct _tagArr
{
	int*	pint;
	int		iCount;
	int		iMaxCount;
}Arr;


// �ʱ�ȭ
void InitArr(Arr* _pArr);

// ������ �߰�
void PushBack(Arr* _pArr, int _pData);

// �迭 ũ�� ����
void Reallocate(Arr* _pArr);

// �迭 ����
void Release(Arr* _pArr);

// ���� ����
void BubbleSort(Arr* _pArr);