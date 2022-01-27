#include <iostream>


using namespace std;


typedef struct _tagMYST
{
	int		i; // 얘네들은 변수가 아니라 멤버라고 부름
	float	f; // 선언을 해서 실체를 만들어야지 변수가 됨
}MYST;


int main()

{

	// 구조체와 포인터
	MYST s = {};
	MYST* ps = &s; // 8바이트짜리

	(*ps).i = 100; // 구조체 s의 i멤버에 100 넣을거야
	(*ps).f = 3.14;
	ps->f = 6.28; // 위에꺼랑 똑같음


	return 0;
}