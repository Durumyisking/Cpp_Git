#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <assert.h> // 경고발생하게하는 함수 있음

using namespace std;

// 우리 문자열 길이를 출력하는 wsclen을 만들어보아요

int c_wcslen(const wchar_t* _String)
{
	int iCount = 0;
	while (NULL != _String[iCount]) { ++iCount;}
	// 조건문 비교할때 상수를 왼쪽에 둬서 실수로 =만 적었을때
	// 오류뜨게 하는 습관을 기릅시다^^
	return iCount;
}

// 우리 문자열을 이어 붙이는 wcscat_s를 만들어보아요
void c_wcscat_s(wchar_t* _pDest, unsigned int _iBufSize, const wchar_t* _pSrc)
{
	// pdest + psrc보다 ibufsize가 작으면 버퍼 에러 assert호출
	// pdest랑 psrc 합쳐도 공간 남는거 확인 했으니까
	// pdest 끝에다가 psrc 붙이기
	

	int pDestlen = c_wcslen(_pDest);
	int pSrclen = c_wcslen(_pSrc);

	if (_iBufSize < pDestlen + pSrclen + 1)
		assert(nullptr); // 매크로함수 경고 호출
	
	
	for(int i=0; i<pSrclen; ++i)
		_pDest[pDestlen + i] = _pSrc[i];

}

int c_wcscmp(const wchar_t* _pStr1, const wchar_t* _pStr2)
{
	int minstr = min(c_wcslen(_pStr1), c_wcslen(_pStr2));

	for (int i = 0; i < minstr; ++i)
	{
		if (_pStr1[i] < _pStr2[i])
			return -1;
		else if (_pStr1[i] > _pStr2[i])
			return 1;
	}

	if (c_wcslen(_pStr1) < c_wcslen(_pStr2))
		return -1;
	else if
		(c_wcslen(_pStr1) > c_wcslen(_pStr2))
		return 1;
	
	return 0;
}


int main()
{
	// 문자열
	char c = 'a';
	wchar_t wc = L'a'; 

	cout << c << endl;
	cout << wc << endl;


	// 이런 배열 초기화는 문자 자료형만 가능
	char szChar[10] = "abcdef";

	wchar_t szWChar[10] = L"abcdef"; // == {97, 98, ... 102};
	// 이 친구는 스택에 szWChar의 메모리가 잡히고 여기에 abcdef가 채워지는것
	
	// 코드영역
	const wchar_t* pChar = L"abcdef"; // 문자열 시작주소 받아옴
	// 이 친구는 스택에 pChar라는 주소 변수가 생기고
	// 코드 영역에 있는 abcdef의 시작 주소를 준것
	// 여기있는 abcdef는 상수처럼 명령어 자체에 데이터가 들어가있는것
	// 여기있는 문자열을 수정한다는것은 상수를 수정한다는것
	// 즉 실시간으로 코드를 바꾼다는거임
	// 그렇기때문에 참조 대상을 바꿀 수 없는 const wchar_t* 로밖에 선언 못하는거
	// 따라서
	// pChar[1] = 'z'; 이 코드는 오류뜸
	szWChar[1] = 'z'; // 이거랑 다름 이건 코드영역에 있는 값을 스택에 복사해서 넣은거

	// 니가 굳이굳이 배열처럼 접근해서 쓰고싶으면
	// pChar = (wchar_t*) "abcdef";
	// 이렇게 하면 됨 그런데 이러면 당연히 오류뜸
	// ROM 영역 수정한다는 거잖아
	// 이건 컴파일 링크단계말고 런타임 단계에서 오류뜸


	// 멀티바이트 charset
	// 1바이트 문자는 1바이트로 표현하고 2바이트 문자는 2바이트로 표현
	char szTest[10] = "abc한글"; // 얘 안쓸거에요~
	// 이러면 abc는 1바이트로 저장되어있고 한글은 1바이트 1바이트 합쳐서 2바이트로 저장되어있음
	// 단점이 있는데
	// 예를들어 위에서 문자가 몇개인지 확인하고 싶은데 뭐는 1바이트 뭐는 2바이트 짜리면
	// 기준이 애매모호해짐

	wchar_t szTestW[10] = L"abc한글"; // Widebyte system(이게 유니코드래!)

	// 뒤에 _t 붙은 함수들은 프로젝트 속성에서 문자집합 설정에 따라
	// 멀티바이트로 해놨으면 함수들이 멀티바이트 함수로 바꿔주고
	// 유니코드집합으로 해놨으면 2바이트 기준 함수로 바꿔서 컴파일해줌
	// 우린 근데 유니코드로 쓸거라서 필요없음 ㅋ

	{
		wchar_t szName[10] = L"Raimond";
		// 여기서 L"Raimond"는 ROM에 있지만
		// 엄밀히 말하면 ROM의 코드영역이 아니라 초기화 영역에 있다
		// 특정 메모리를 초기화 시켜주는 애들은 따로 분류됨ㅇㅇ



		// wcslen(const wchar_t* _String) 
		// 이 함수는 문자열의 길이를 알려주는 놈이니까 길이만 알려줘야댐
		// 그러니까 나 원본 수정할생각 없으니까 const wchar_t* 로 받아감
		int iLen = wcslen(szName); 
		cout << "wcslen 사용한 szName길이 : " << iLen << endl;

		iLen = c_wcslen(szName);
		cout << "c_wcslen 사용한 szName길이 : " << iLen << endl;

		
	}

		
	{

		wchar_t szName1[20] = L"Raimond";
		wchar_t szName2[10] = L"Ds";

		wcscat_s(szName1, 14, szName2);
		c_wcscat_s(szName1, 14, szName2);

		cout << c_wcscmp(L"ABC", L"BBC") <<endl;
		cout << wcscmp(L"ABCD", L"BBC")<<endl;
	}


	return 0;
}