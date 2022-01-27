#pragma once
#include <iostream>
using namespace std;

typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode; // 아직 별명을 모르니까 별명으로 쓰면 안댐

}Node;


typedef struct _tagLinkedList
{
	Node*	pBegin;
	// Node*	pEnd;
	int		iCount;

}List;


// function
void InitList(List* _pList);
void PushBack(List* _pList, int _Data);
void PushFront(List* _pList, int _Data);
int PopBack(List* _pList);
void Release(Node* _pNode);
void ReleaseList(List* _pList);