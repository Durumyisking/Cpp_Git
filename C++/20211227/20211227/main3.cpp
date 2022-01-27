#include <iostream>
#include "main5.h"

using namespace std;

int a = 0;

void ppp()
{
	cout << a << endl;
}


int factorial(int num)
{
	int result = 1;


	for (int i = 0; i < num - 1; ++i)
		result *= i + 2;
	
	return result;

}


// 재귀함수
// 계층 구조를 표현 할 때 유리
// 함수 안에서 함수가 호출되면 스택 메모리 안에 새로운 스택이 추가됨

int recur_factorial(int num)
{
	if (num <= 1)
		return 1;
	else
	{
		return num * recur_factorial(num - 1);
	}

	
}

// 1 1 2 3 5 8 13 21 ....
int fibonacci(int num)
{
	int result = 1;
	int prev = 1;
	int prev2 = 1;
	
	if (num == 1 || num == 2)
		return 1;
	

	for (int i = 0; i < num - 2; ++i)
	{
		result = prev + prev2;

		prev2 = prev;
		prev = result;
	}

	return result;

}

int recur_fibonacci(int num)
{

	if (num == 1 || num == 2)
		return 1;
	else
	{
		return recur_fibonacci(num - 1) + recur_fibonacci(num - 2);

	}
}

// 전역변수
// 다른 클래스에 같은 이름의 전역 변수를 넣었을 때 오류가 생김
// 각 클래스를 따로 보는 컴파일 단계에서는 오류가 생기지 않으나
// 각 클래스를 합쳐서 보는 링크 단계에서 같은 이름으로 두 번 선언되었다고 오류가 생김
int g_inum = 0;


// 정적변수
// 얘는 전역변수와 다르게 다른 클래스에 같은 이름으로 선언해도 오류 안생김
// 컴파일러가 선언된 파일에서만 static 변수를 사용한다는 것을 인지하기 때문
// 선언되는 위치에 따라서 다른 동작 방식
// 선언된 함수 or 클래스에서만 사용 가능	
// 지역변수로 선언해도 스택이 아니라 데이터 영역에서 선언이 됨
// 쉽게 말하면 생성된 위치에서 움직이지 않음 => 다른 클래스에서 찾을 수 없음
// 헤더에 선언한 전역 static 변수를 다른 두 클래스에서 include 해서 써도 결국 다른 클래스의 static 변수가 됨으로 다른 변수로 취급된다.
static int g_istatic = 0;


// 외부변수
// 외부변수를 헤더파일에서 선언할 때 초기화를 하면 안됨 (두 개 이상의 클래스에서 사용시 같은 변수가 여러개 있는걸로 취급)
// extern int g_iextern; 요런 느낌으로 외부변수가 있을거야~ 라고만 선언
// 실제로 사용하려면 어딘가에 반드시 초기화를 해줘야지 컴파일 했을 때 링크가 됨



int static_test()
{
	static int icount = 0; // 이렇게 해도 처음 호출했을때만 초기화 한다.

	++icount;
	return icount;
}




int main()
{

	// 변수의 종류

	// 1. 지역변수				함수 내에 선언한 변수
	// 2. 전역변수				함수 밖에 선언한 변수
	// 3. 정적변수				선언한 부분에서만 사용할 수 있는 변수
	// 4. 외부변수				완전 모든 파일들이 사용 가능한 변수

	// 메모리 영역
	// 1. 스택 영역				지역변수가 사용
	// 2. 데이터 영역			전역, 정적, 외부변수가 사용, 프로그램이 실행되어 main함수가 호출될 때 데이터 영역이 만들어짐
	//							프로그램이 종료되면 메모리 해제됨
	// 2.1 BSS 영역				초기화되지 않은 전역 데이터들을 저장한다 ( 
	// 3. 읽기 전용(코드, ROM (Read Only Memory)	
	// 4. 힙 영역				
	// 함수 : 프로그램의 기능 하나하나를 함수라고 부름
	// 프로그램의 부품이라고 보자

	int a = 123; // 전역에 같은 이름으로 선언시켜놔도 이렇게 사용 가능

	cout << a << endl; // 지역 출력
	ppp(); //전역 출력


	// 반복문
	for (/*1. 반복자 초기화*/ int i =0; /*2. 반복자 조건 체크*/ i<5; /*4. 반복자 변경*/++i)
	{
		/*3. 구문 실행*/
		cout << i <<"번째 : 구문 실행" << endl;
	}


	int count = 0;
	while (/* 조건 체크 0이면 탈출*/count != 5)
	{
		cout << "while문 실행" << endl;
		++count;
	}

	// 함수 실행 방식
	/*
		프로그램을 실행하면 제일 먼저 main 코드블럭 내의 필드들만큼의 메모리가
		스택 메모리 영역에 올라감

		필드들의 메모리 할당은 지역에 들어가야 할당

		코드를 실행하다 함수를 만나면 
		스택 메모리 영역에 그 함수의 메모리만큼 메모리 할당

	*/

	cout << factorial(4) << endl;
	cout << recur_factorial(4) << endl;


	cout << fibonacci(8) << endl;
	cout << recur_fibonacci(8) << endl;


	/*
		return 이라 함은
		함수를 나가서 이전 실행 영역으로 간다

		쉽게말해 이전 디렉토리로 이동하는거

		함수의 리턴값은 레지스터에 임시로 들어간다
	*/

	return 0;

	g_staticint = 123;
	cout << g_staticint;

/*
	
	단축키

	지정 구문 주석			ctrl + k + c
	지정 구문 주석 해제		ctrl + k + u
	원하는 영역 드래그		alt drag
*/


/*
	호출 스택



*/
}



