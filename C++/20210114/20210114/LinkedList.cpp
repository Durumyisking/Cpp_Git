#include "LinkedList.h"

void InitList(List * _pList)
{
	_pList->pBegin = nullptr;
	_pList->iCount = 0;
}

void PushBack(List* _pList, int _Data)
{
	// 1. 새로운 노드를 만든다
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	// 2. 새 노드에 데이터를 넣는다.
	NewNode->iData = _Data;
	NewNode->pNextNode = nullptr;

	// 3. 리스트의 시작 노드의 다음노드로 새 노드를 설정한다
	if (0 == _pList->iCount)
		_pList->pBegin = NewNode;
	else
	{ 	
		Node* CurrentNode = _pList->pBegin;
		while (true)
		{
			if (nullptr == CurrentNode->pNextNode)
			{
				CurrentNode->pNextNode = NewNode;
				break;
			}
			else
				CurrentNode = CurrentNode->pNextNode;
		}
	}
	
	// 4. 리스트의 개수를 하나 늘린다.
	++_pList->iCount;
}

void PushFront(List * _pList, int _Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->iData = _Data;
	NewNode->pNextNode = _pList->pBegin;
	
	_pList->pBegin = NewNode;
	
	++_pList->iCount;
}

int PopBack(List * _pList)
{
	// 맨 끝의 인덱스를 추출 후 삭제
	Node* pNode = _pList->pBegin;
	Node* nextNode = pNode->pNextNode;
	int iData;
	while (true)
	{
		// 만약 현재 노드의 다음 노드가 nullptr이면 현재 노드의 데이터 리턴
		if (nullptr == nextNode)
		{
			iData = pNode->iData;

			pNode->iData = 0;
			pNode = nullptr;
			free(pNode);
			
			break;
		}
		// 아니면 다음 노드로 이동
		else
		{
			pNode = nextNode;
			nextNode = pNode->pNextNode;	
		}
	}

	return iData;
}

void Release(Node * _pNode)
{
	if (nullptr == _pNode)
		return;

	Release(_pNode->pNextNode);
	free(_pNode);
}

void ReleaseList(List * _pList)
{
	// Release(_pList->pBegin);

	Node* pNode = _pList->pBegin;

	// while 조건을 pNode로 넣어서 노드가 하나도 없을때 while문에 안들어가게함
	while (pNode)
	{
		Node* pNextNode = pNode->pNextNode;
		free(pNode);
		pNode = pNextNode;
	}
}
