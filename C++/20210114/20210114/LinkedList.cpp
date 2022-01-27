#include "LinkedList.h"

void InitList(List * _pList)
{
	_pList->pBegin = nullptr;
	_pList->iCount = 0;
}

void PushBack(List* _pList, int _Data)
{
	// 1. ���ο� ��带 �����
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	// 2. �� ��忡 �����͸� �ִ´�.
	NewNode->iData = _Data;
	NewNode->pNextNode = nullptr;

	// 3. ����Ʈ�� ���� ����� �������� �� ��带 �����Ѵ�
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
	
	// 4. ����Ʈ�� ������ �ϳ� �ø���.
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
	// �� ���� �ε����� ���� �� ����
	Node* pNode = _pList->pBegin;
	Node* nextNode = pNode->pNextNode;
	int iData;
	while (true)
	{
		// ���� ���� ����� ���� ��尡 nullptr�̸� ���� ����� ������ ����
		if (nullptr == nextNode)
		{
			iData = pNode->iData;

			pNode->iData = 0;
			pNode = nullptr;
			free(pNode);
			
			break;
		}
		// �ƴϸ� ���� ���� �̵�
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

	// while ������ pNode�� �־ ��尡 �ϳ��� ������ while���� �ȵ�����
	while (pNode)
	{
		Node* pNextNode = pNode->pNextNode;
		free(pNode);
		pNode = pNextNode;
	}
}
