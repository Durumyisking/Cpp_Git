#pragma once

// 프로그램 자체를 나타냄
// 코어는 프로그램의 중추 => 객체가 하나만 존재해야함


// singleton pattern
// 개체의 생성을 1개로 제한

// 언제 어디서든 쉽게 접근 가능 => 전역변수로 사용한다
// 그런데 extern으로 선언해서 만들어 놓으면 누구
class CCore
{
	static CCore* g_pInst;

private: // 생성자를 숨겨두면 외부에 객체 생성이 불가능해짐
		// 객체를 생성해주는 유일한 함수 1개를 제공 할 것
		// 그런데 객체를 생성해주는 함수를 사용하려면 객체가 필요
		// 우리는 객체가 없어도 멤버함수를 만들어 줄 것
		// static 키워드의 멤버함수는 객체 없이 사용 가능
	CCore();
	~CCore();

public:
	// 정적 멤버함수, 객체없이 호출 가능 (객체 있이 호출 가능하지만 this가 없어서 의미가 없음)
	// 따라서 this가 없으니 멤버 접근이 불가능, 정적 멤버는 접근 가능
	
	// 정적 (데이터 영역 : 영역을 실행할때 딱 하나 생성되고 종료될때 삭제)
	// 1. 함수 안 (데이터 영역)
	// 2. 파일 (데이터 영역) 다른 파일 정적 변수와 이름 중복 OK
	// 3. 클래스 안 (데이터 영역)
	static CCore* GetInstance()
	{
		// this 키워드가 없음
		// 누가 호출했는지 알 필요가 없기 때문
		// 따라서 멤버접근도 불가능함 (단 static 멤버는 접근이 가능함)
		

		// static으로 해놔서 함수가 종료되도 사라지지 않음
		// 정적 멤버의 초기화는 최초 한 번만 실행됨
		// 따라서 두 번 호출된다고 pCore을 nullptr로 초기화 시키지 않음
		
		// 최초호출
		if (nullptr == g_pInst)
			g_pInst = new CCore;
		
		return g_pInst;
	}


	static void ReleaseInstance()
	{

		if (nullptr != g_pInst)
			delete g_pInst;


	}

};

