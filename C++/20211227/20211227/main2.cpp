#include <iostream>


// 전처리기 (define)
	// 치환 매크로

#define HUNGRY	0x1 // 이러면 HUNGRY는 1 c++에서는 숫자앞에 0x붙이면 16진수
#define THIRSTY 0x2
#define HOT		0x4
#define COLD	0x8

#define DEAD	0x10
#define DEAD	0x20
#define DEAD	0x40
#define DEAD	0x80

#define DEAD	0x100
#define DEAD	0x200




// 전처리기의 장점
// 유지보수 측면에서 용이, 알아보기 쉬움


// 비트로 특정 상태를 나타낼 수 있음
// ex) 0000 0000 0000 0000 0000 0000 0000 0111
// 이러면 HUNGRY THIRSTY HOT 다 활성화



using namespace std;

int main()
{

	// 산술 연산자
	int data = 10 + 10;


	// 실수 나머지 연산
	//data = 10.1 % 3.3;   -  불가능

	// 나머지 연산은 피연산자가 모두 정수
	data = (10. / 3.); // 이렇게 형변환 하면 가능 이렇게 하면 double로 봄
	data = (10.f / 3.f); // 이렇게 해야 float으로 봄
	data = (int)(10.f / 3.f); // 이렇게 해야 float으로 보면서 경고 안뜸


	// 증감 연산자
	// ++ 증가 -- 감소
	// 1증가 1감소라고 볼 수도 있지만 1단계라는 개념이라고 생각하는게 좋음
	// 예를들어 int 포인터에서 ++하면 4바이트 다음 포인터 참조하는거니까
	// 변수 안에있는 값이 ㄹㅇ루 증가하는거기 때문에
	// 값을 증가시키고 그걸 다시 대입받고 그럴 필요 없음
	// 미세하지만 a++이랑 a+=1는 차이가 분명히 존재함

	// 전위연산 후위연산
	// 전위연산으로 썼을때는 연산자 우선순위가 가장 앞으로
	// 후위연산일때는 우선순위가 가장 나중으로 밀린다.


	// 논리 연산자
	// 역 : !	and : &&	or : ||
	// 0이아니면 참 (주로 1) 0은 거짓

	// bool : 1byte 
	// 1이 넘는 숫자를 넣어도 1이라고 받음 (결국 true로 받음)
	
	// 3항 연산자
	// b ? x : y // b가 참이면 x 거짓이면 y

	// 비트 연산자
	// 쉬프트 <<, >>
	// <<는 비트를 한칸 왼쪽으로 이동 >>는 오른쪽으로 이동
	// <<는 곱하기2 >>는 나누기 2

	// 비트 곱 : &		비트 합 : |		xor : ^		비트 반전 : ~
	// 두 비트를 비교
	// &은 둘 다 1이면 1 나머지 0
	// |은 둘 다 0이면 0 나머지 1
	// ^은 두 비트가 다르면 1 같으면 0
	// ~은 0이면1 1이면 0



	unsigned int iStatus = 0;

	iStatus |= HUNGRY;
	iStatus |= THIRSTY;



	if (iStatus & THIRSTY) // 지정한 비트에 1이 있는지
	{
		cout << 123;
	}

	if (iStatus &= ~THIRSTY) // 특정 자리 비트 제거 연산
	{
		cout << 56;
	}


	return 0;
}