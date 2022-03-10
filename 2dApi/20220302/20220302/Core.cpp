#include "pch.h"
#include "Core.h"

#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Object.h"

//// 동적할당 방식
// CCore* CCore::g_pInst = nullvr;




// 
CCore::CCore()
	: m_hWnd(0)
	, m_vResolution{}
	, m_hDC(0)
{

}

CCore::~CCore()
{
	// 얻어온 DC는 커널오브젝트라서 운영체제에게 해제해달라고 해야함
	ReleaseDC(m_hWnd, m_hDC);
}

CObject g_obj;

int CCore::init(HWND _hWnd, Vec2 _vResolution)
{
	m_hWnd = _hWnd;
	m_vResolution = _vResolution;


	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0, 0, m_vResolution.x, m_vResolution.y };
	// 우리는 메뉴바 밑을 바꾸고 싶은데 SetWindowPos는 윈도우 크기 전체를 설정함
	// 그래서 우리는 윈도우 크기를 우리가 지정한 해상도가 나오게 잡아주는 함수 AdjustWindowRect를 사용
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true); // 인자 RECT* , Windowstyle, 메뉴바 유무
	// 이렇게하면 rt에 메뉴바가 있는 WS_OVERLAPPEDWINDOW 스타일일때의 값이 채워짐
	// AdjustWindowRect를 보면 return값은 bool이고 실제로 돌려주고 싶은 값은 주소로 받아서 넘겨줌
	// return값이 register에 담겨서 돌아오는데 사이즈가 큰걸 반환할때는 성능이 저하됨
	// register에 담기에 너무 크면 임시메모리를 잡아서 레퍼런스를 해야함 ㅜ
	SetWindowPos(_hWnd, nullptr, 0, 0,
		rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd); // m_hWnd의 DC를 얻음

	// Manager 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();

	g_obj.SetPos(Vec2{ (float)m_vResolution.x / 2, (float)m_vResolution.y / 2 });
	g_obj.SetScale(Vec2{ 100, 100 });

	return S_OK;
}




void CCore::progress()
{
	// 윈도우의 paint는 화면을 한 번 싹 없애고 갱신해서 다시 그리는거면
	// 우리는 덧그리고 덧그려서 장면을 재구성할꺼

	// 의외로 변경점만 체크해서 그부분만 재구성하게 안함
	// 게임에서의 렌더링은 모든장면을 싹 다 지워서 다시 렌더링하는거

	static int callcount = 0;
	++callcount;

	static int iPrevCount = GetTickCount(); // static으로 선언하여 함수 재진입시 초기화가 다시 안되게 한다
	int iCurrentCount = GetTickCount();

	if (iCurrentCount - iPrevCount > 1000) // 초기 측정시간으로부터 1초가 지나면
	{
		iPrevCount = iCurrentCount; // 현재 시간을 초기 측정시간으로 변경
		callcount = 0;
		

	}
	CTimeMgr::GetInst()->update();




	update();

	render();



}
void CCore::update()
{
	// 변경점들을 체크

	Vec2 vPos = g_obj.GetPos();

	// 비동기 키 입출력 함수 ( 코드가 수행되는 지금 이 순간에 무슨 키가 눌렸는지 확인)

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)	// 인자에 적혀있는 키가 눌렸는지 확인
	{										// true or false가 아니라 여러 상태를 비트 조합으로 가짐
		// vPos.x -= 0.01;					// 당장 눌린걸 확인하려면 & 0x8000
		// 이렇게 하면 컴퓨터 성능에 따라 갱신 속도가 달라짐
		// 속도가 빨라서 업데이트가 빨리 될수록 빨라지니까

		// 빠른 컴퓨터는 움직임 단위가 작게
		// 느린 컴퓨터는 크게 해서 최종 결과를 같게 보장해야함
		//vPos.x -= 100.f * DeltaTime;

		vPos.x -= 200.f * CTimeMgr::GetInst()->GetDT();



	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 200.f * CTimeMgr::GetInst()->GetDT();

	}

	g_obj.SetPos(vPos);


	// InvalidateRect(m_hWnd, nullptr, true);
}
void CCore::render()
{
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_hDC
		, (int)vPos.x - vScale.x / 2
		, (int)vPos.y - vScale.y / 2
		, (int)vPos.x + vScale.x / 2
		, (int)vPos.y + vScale.y / 2);

}
/*
윈도우에 있는 대부분에 함수들은
HRESULT를 반환함 HRESULT는 그냥 long임
HRESULT hr = S_OK;

if (FAILED(S_OK)) // FAILED는 인자에 음수가 들어가면 true, E_FAIL = 음수, S_OK = 0, S_FALSE = 1
 따라서 S_OK면 함수가 성공했다는 것이고
 FAILED문에 걸리지 않음

*/