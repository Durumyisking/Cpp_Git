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


// 초기화
void InitArr(Arr* _pArr);

// 데이터 추가
void PushBack(Arr* _pArr, int _pData);

// 배열 크기 변경
void Reallocate(Arr* _pArr);

// 배열 해제
void Release(Arr* _pArr);

// 버블 정렬
void BubbleSort(Arr* _pArr);