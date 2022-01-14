#include <iostream>


using namespace std;


int main()
{
	// 포인터 변수
	// 주소를 저장하는 변수
	int* pInt = nullptr; // 아무것도 가리키고 있지 않다.
	

	int num = 100;
	int* pnum = &num;


	/*주소값을 접근하겠다*/ *pnum = 5;
	// 주소의 최소 단위는 바이트
	// in 32bit = 4byte (86x)
	// in 64bit = 8byte
	
	int i =  100;
	float f = 3.f;

	int* p_i = (int*)&f;
	// 이렇게 하면 실수 주소 변수 안에 있는 값을 정수 방식으로 해석함

	i = *pInt;


	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조
	// 2. 배열의 이름은 배열의 시작주소

	int iArr[10] = {};

	*(iArr + 4) = 123; // 이르면 배열 시작주소에서 16바이트 다음 인덱스에서 시작

	// 29강
	
	// 1번문제
	short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *pI = (int*)sArr;
	int iData = *((short*)(pI + 2));
	cout << "1번 문제 정답 : " << iData << endl;


	// 5

	// 2번문제
	char cArr[2] = { 1, 1 };
	short * pS = (short*)cArr;
	iData = *pS;
	cout << "1번 문제 정답 : " << iData << endl;

	// 257


	return 0;
}