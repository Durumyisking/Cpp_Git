#include "LinkedList.h"


int main()
{
	// ������ ����Ʈ
	// ���� �����������(���) �ϳ��� ����
	// �� �����͵��� ���� ����� �ּҸ� �˰�����
	// �� ���� �� ������, ���� ����� �ּҸ� ����

	List list = {};

	InitList(&list);

	for (int i = 0; i < 10; ++i)
		PushBack(&list, i);


	for (int i = 0; i < 10; ++i)
		cout<<PopBack(&list)<<endl;

	ReleaseList(&list);


	return 0;
}