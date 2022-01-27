
#include "Arr.h"



// 메모리 영역
// 힙 영역 (동적할당)
// 런타임중에 대응이 가능한 메모리 공간

int main()
{
	// 동적 할당
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 메모리 관리를 해주어야함 (메모리 해제)

	// malloc(100); // 힙 영역에 메모리 100바이트 할당
	// 포인터가 어떤 형태로 올지는 사용자가 판단
	// malloc은 순수하게 주소의 개념으로 괄호안의 바이트를 할당
	int* pInt = (int*)malloc(100);

	// malloc 은 void 타입이라서 캐스팅해서 사용하면
	// 해당 자료형으로 메모리를 할당한다.
	
	float* pF = (float*)malloc(4);
	int* pI = (int*)pF;

	*pF = 1.625f;

	// 원본은 float로 만들었지만 참조를 int로 하면
	// int로 읽어오는걸 확인 가능하다
	// cout << *pF << "\t" << *pI << endl;
	
	// 할당해준 메모리를 해제한다
	// 힙영역이 아닌 영역에서는 어셈블리어로 자동으로 해제되게 되어있다.

	if (nullptr != pF)
		free(pF);

	// 가변배열
	int a = 100;

	// 배열 개수를 선언할 때에는 변수 사용 불가능
	// 컴파일 했을때 메모리를 잡아주어야 하는데 그게 불가능하잖아
	// int arr[a] = {};


	// 객체(instance)
	// int라는 자료형이 있을때
	// int a 하면 a는 객체
	// int라는 자료형을 실제로 만들어낸것

	Arr pArr = {};
	InitArr(&pArr);
	
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&pArr, i);
	}
	Release(&pArr);
	
	return 0;
}