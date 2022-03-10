#pragma once


//// 프로그램 자체를 나타냄
//// 코어는 프로그램의 중추 => 객체가 하나만 존재해야함
//
//
//// singleton pattern
//// 객체의 생성을 1개로 제한
//
//// 언제 어디서든 쉽게 접근 가능 => 전역변수로 사용한다


//// 동적할당방식
//class CCore
//{
//	
//	static CCore* g_pinst;
//
//private: // 생성자를 숨겨두면 외부에 객체 생성이 불가능해짐
//		// 객체를 생성해주는 유일한 함수 1개를 제공 할 것
//		// 그런데 객체를 생성해주는 함수를 사용하려면 객체가 필요
//		// 우리는 객체가 없어도 멤버함수를 만들어 줄 것
//		// static 키워드의 멤버함수는 객체 없이 사용 가능
//	ccore();
//	~ccore();
//
//public:
//	// 정적 멤버함수, 객체없이 호출 가능 (객체 있이 호출 가능하지만 this가 없어서 의미가 없음)
//	// 따라서 this가 없으니 멤버 접근이 불가능, 정적 멤버는 접근 가능
//	
//	// 정적 (데이터 영역 : 영역을 실행할때 딱 하나 생성되고 종료될때 삭제)
//	// 1. 함수 안 (데이터 영역)
//	// 2. 파일 (데이터 영역) 다른 파일 정적 변수와 이름 중복 ok
//	// 3. 클래스 안 (데이터 영역)
//	static CCore* getinstance()
//	{
//		// this 키워드가 없음
//		// 누가 호출했는지 알 필요가 없기 때문
//		// 따라서 멤버접근도 불가능함 (단 static 멤버는 접근이 가능함)
//		
//
//		// static으로 해놔서 함수가 종료되도 사라지지 않음
//		// 정적 멤버의 초기화는 최초 한 번만 실행됨
//		// 따라서 두 번 호출된다고 pcore을 nullvr로 초기화 시키지 않음
//		
//		// 최초호출
//		if (nullvr == g_pinst)
//			g_pinst = new ccore;
//		
//		return g_pinst;
//	}
//
//
//	static void releaseinstance()
//	{
//
//		if (nullvr != g_pinst)
//			delete g_pinst;
//
//
//	}
//
//};
//


// singleton으로 만들 유일한 객체를 데이터 영역에 올리는 방식
// 동적할당 방식이 아니기 때문에 메모리 해제를 해주지 않아도 됨
// 그런데 그 이유 때문에 프로그램 종료 전까지 이 객체를 해제 해줄수 없음
class CCore
{

/*
	public:
		// 얘는 많이쓸꺼니까 매크로함수로 만들자
		static CCore* GetInst()
		{
			// core 객체를 데이터 영역에 만듬
			// 생성자가 private이지만 같은 멤버함수니까 접근 가능함
			static CCore core;	// 초기화는 한 번만 함
								// 따라서 호출할때마다 core의 주소만 반환
			return &core;
		}
*/
	SINGLE(CCore);

private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	Vec2	m_vResolution;	// 메인 윈도우 해상도
	HDC		m_hDC;			// 메인 윈도웨 Draw할 DC



public:
	int init(HWND _hWnd, Vec2 _vResolution);
	void progress();

private:
	void update();
	void render();

public:
	HWND GetMainHwnd() { return m_hWnd; }


};