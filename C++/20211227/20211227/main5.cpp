#include <iostream>
#include "main5.h" // include는 헤더파일 전체를 복붙한거랑 같은 의미

// 오류 발생시 LNK 붙어있으면 링크오류
// C붙어있으면 컴파일 오류


using namespace std;

void func(); // 함수 정의를 밑에서 해놓았을때 위에서 선언해주면 링크가 돼서 오류 안뜸

int Add(int a, int b)
{
	return a + b;
}

void func()
{
	cout << "asdf";
}