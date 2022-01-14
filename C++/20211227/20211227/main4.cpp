#include <iostream>
#include <stdio.h>
#include "main5.h"

// 구조체
// 구조체는 사용자 정의 자료형
typedef struct _tagMyST
// 원래 c에서 앞에 typedef 안붙이면 main에서 선언할때 int처럼 struct 구조체명 변수명 이렇게 해야댐
{
	int		inum;
	float	fnum;
}MYST; // 별명 (앞에 typedef를 해줬기 때문에 별명 지어줄 수 있는거


typedef struct _tagBig
{
	MYST	myst; // 구조체 속에 구조체 쌉가능
	int		i;
	char	c;

}BIG; // 별명

typedef int INT; // 이렇게 하면 int의 별명을 INT로 지어준것

using namespace std;

int main()
{

	// 배열

	// 선언
	int arr[10] = {}; // 이러면 전부 0으로 초기화
	
	// 배열 밖의 인덱스에 값을 넣으면 선언되어있는 다른 변수에 쏘옥 들어갈 수 있음


	MYST t; // 구조체로 선언 가능
	BIG b = {100, 3.14}; // 초기화 가능!

	
	// 지칭하려면 .찍어서
	t.inum = 15;
	t.fnum = 20.33;

	b.myst.inum = 123;

	Add(123, 456); // main5.cpp를 include 하지 않았지만 알아서 링크되어 main5.cpp의 Add를 사용한다.


	return 0;
}