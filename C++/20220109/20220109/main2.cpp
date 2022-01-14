#include <iostream>


using namespace std;


void output(const int * pI) // 인자를 cosnt pointer로 받아서 원본 변경 불가
							// 매개인자로 값을 받을때 포인터 주소가 아니라 변수를 직접 받으면
							// 너무 큰 data를 받을때 호출할 때마다 큰 data를 임시로 만들고 함수 다 쓰면 사라지고
							// 매우 비효율적
{
	int i = *pI;
	// *pI = 100; 못바꿈
}

int main()
{
	// 상수화
	// lvalue : 변수
	// rvalue : 상수

	int i = 10; // 여기서 왼쪽 변수는 바뀔수 있고 오른쪽 10은 우리가 10의 값 자체를 바꿀수 없으니까 상수

	const int cint = 100; 
	// 여기서 cint는 상수지만 우리가 const를 사용해서 cint가 변할수 없게 만드는거지
	// 이 cint가 진짜 상수처럼 절때 못바꾸는건 아님
	
	//ex)
	int* pint = (int*)&cint;
	*pint = 123;

	cout << cint << endl; // 이러면 상수 cint의 메모리 값 100이 123으로 바뀐다
	// 하지만 내부적으로 cint를 상수라고 판단해서 레지스터에 임시로 저장해놓은 100을 출력 => 레지스터 최적화라고 부름
	// volatile const int cint = 100 처럼 선언해 레지스터 최적화를 사용 안하면 123을 출력


	// const와 포인터
	int a = 0;
	int* pa = &a;

	*pa = 1;		// 가리키는 대상 바꾸기
	pa = nullptr;	// 가리키는 곳 바꾸기

	// 포인터 변수에서의 상수화는 const가 붙는 위치에 따라
	// 가리키는 주소가 상수화 될 것인지 가리키는 주소의 내부값이 상수화 될 것인지 정해짐


	// const 포인터 // 주소 바꿀 수 있음 | 주소가 가지고 있는 값 변경 불가능
	const int* pConstint = &a;
	// *pConstint = 3; // 이러면 pConstint가 가리키는 쪽을 상수화 시킴 
	// int const* pointer와 동일
	

	// 포인터 const // 주소 못바꿈 | 주소가 가지고 있는 값 변경 가능
	int* const pIntconst = &a;
	// pIntconst = pConstint; // 이러면 pIntconst가 가지고 있는 주소값이 상수화 되어 다른 주소를 받을 수 없음
	

	// 다 상수화
	// 초기화시 가리킨 대상만 가리키고 원본 수정 불가
	const int* const pConstintconst = nullptr;


	// 사용 예시
	// 함수 등으로 변수에 접근할때 주소값을 참조하여 값 확인을 할 수 있지만 변경은 못하게 할 때
	// 전달해야할 data 타입이 너무 거대하거나 유일해야 하면 사용한다
	


	a = 100;
	output(&a);



	// void
	// void는 반환 타입이 없다
	// 원본 비트값의 형태를 어떻게 볼지 정하지 않은 자료형
	// 원본의 자료형을 정하지 않음
	

	void* pvoid = nullptr;
	float* pfloat = nullptr;


	// 원본의 자료형을 정하지 않아서 생기는 특징들

	// 어떤 주소의 변수든지 담을 수 있음
	{
		int a = 0;
		float f = 0.f;
		double d = 0;
		long long ll = 0;

		pvoid = &a;
		pvoid = &f;
		pvoid = &d;
		pvoid = &ll;

		// *pvoid = 123;	역참조 불가 => 정해진 자료형이 없기 때문
		// pvoid + 1		주소연산 불가 => 정해진 자료형이 없으니까 몇바이트를 증가시킬지 모름


	}




	return 0;
}