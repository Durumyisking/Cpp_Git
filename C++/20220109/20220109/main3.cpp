#include <iostream>


using namespace std;


int main()
{
	// 데이터 영역
	// 1. 스택
	// 2. 데이터
	// 3. 힙
	// 4. 코드 영역 (읽기 전용 read only memory)


	// 문자

	// char은 1바이트 문자 8bit로 전세계 문자 표현 불가 (아스키코드 사용)
	// 그래서 나온게 wchar 얘는 2바이트 (유니코드사용)

	char c = '1'; // 이렇게 1자리 이상의 글자를 넣으면 맨 뒤의 글자를 저장
	// 문자를 계속 읽다가 마지막에 아스키코드0(null)을 만나면 문자의 끝임을 인식

	
	wchar_t wc = L'91';		// 2바이트 문자 => 맨 앞 글자 9에 해당하는 유니코드(57)가 출력
							// 2바이트 문자를 작성할때는 앞에 L을 붙여서 2바이트 문자임을 표시 (아스키가 아니라 유니코드로 인식)
	wchar_t wc2 = 'baa';	// 이렇게하면 맨 뒤의 16bit를 즉 aa를 읽음 97(0110 0001) 97(0110 0001)
	short s = 49;			// 정수가 그대로 보여짐

	c = 49;

	cout << c << endl << wc << endl;

	wc = 459; 
	//이거랑 "459" 이거랑 다름 => "459"는 안에 있으면 한 바이트마다 4의아스키(52) 5의아스키(53) 9의아스키(57) null의아스키(0) 들어간것
	c = '459';

	cout << c;
	


	return 0;
}