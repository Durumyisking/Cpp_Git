#include <iostream>
#include "TemplateArr.h"



void MyEndL()
{
	wprintf(L"\n");
}


// 항상 std::cin 하기 귀찮으면 이렇게 하면된다.
// using namespace std;
// 그런데 이렇게 해주면 namespace를 만들어주는 이유가 없긴해
// MYSPACE랑 NEWSPACE 의 g_int가 모호해지잖아
// 그래서 자주 사용하는 기능들만 가져올수 있음

using std::cout;
using std::cin;
using std::endl;
// 요로코럼 하면 namespace의 일부 기능들만 빼서 사용가능

// 이렇게하면 우리가 std::cout 하듯
// MYSPACE::g_int 해줄수있음
namespace MYSPACE
{
	int g_int;
}

// 전역 변수명 중복 막고싶으면 
// 다른 namespace를 만들면 된다.
namespace NEWSPACE
{
	int g_int;
}

class CTest
{
private:
	int a;

public:
	CTest()
		:a(10)
	{

	}


};

class TestClass; // 클래스를 만들고 아무 멤버도 넣지 않으면 1byte 할당

class CMyOStream
{
public:
	CMyOStream& operator << (int _idata)
	{
		printf("%d", _idata);
		return *this;
	}

	// 함수 오버로드로 여러 방식으로 사용 가능
	CMyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}

	CMyOStream& operator << (void(*_pFunc)(void)) // 함수 포인터를 받아와서 MyEndL 호출
	{
		_pFunc();
		return *this;
	}

	CMyOStream& operator >> (int& _iData)
	{
		scanf("%d", &_iData);
		return *this;
	}


};


/*
int Add(int a, int b)
{
	return a + b;
}

float Add(float fa, float fb)
{
	return fa + fb;
}
*/
// 함수 템플릿
// 함수를 찍어내는 틀
// typename 자리에 어떤게 들어갈지 요청 했을때 함수가 생성됨
// 이렇게 선언해놓아도 함수는 메모리에 없는것

template <typename T> // 여기 T 자리에 원하는 자료형으로 정의해줄수 있음
T Add(T a, T b)
{
	return a + b;
}




int main()
{

	// 템플릿으로 선언된 함수 호출
	int i = Add<int>(10, 20);
	int f = Add<int>(10.0, 20.0);

	int i2 = Add(10, 20); // 이렇게 하면 입력으로 넣어주는 두 데이터가 int고 전달 받는애도 int니까 템플릿 함수에서 반환타입이 int로 알아서 매칭
	// 근데 이렇게 하면 일반함수를 쓴 것인지 함수 템플릿을 쓴 것인지 모름


	CTemplateArr<int> int_arr;
	CTemplateArr<float> float_arr;

	for (int i = 0; i < 10; ++i)
	{
		int_arr.PushBack(i);
		float_arr.PushBack(i);
	}

	MYSPACE::g_int = 0;

	CMyOStream mycout;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	mycout << 10 << 30 << 50 << MyEndL;
	mycout << L"한글" << MyEndL;
	// cout의 원리
	// cout 객체의 함수 <<, <<의 인자로 10을 받아서
	// << 함수를 처리한 뒤 자기 자신 포인터를 return
	// 다시 return한 자기 자신으로 cout << 30처리
	// 그 후 cout << 50처리

	int a = 0;
	mycout >> a;

	return 0;

}