#include "LinkedList.h"


int main()
{
	// 연결형 리스트
	// 시작 데이터저장소(노드) 하나를 만듬
	// 각 데이터들은 다음 노드의 주소를 알고있음
	// 한 노드는 즉 데이터, 다음 노드의 주소를 가짐

	List list = {};

	InitList(&list);

	for (int i = 0; i < 10; ++i)
		PushBack(&list, i);


	for (int i = 0; i < 10; ++i)
		cout<<PopBack(&list)<<endl;

	ReleaseList(&list);


	return 0;
}