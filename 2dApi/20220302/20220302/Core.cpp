#include "pch.h"
#include "Core.h"

#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Object.h"


CCore::CCore()
	: m_hWnd(0)
	, m_vResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_memDC(0)
{

}

CCore::~CCore()
{	
	ReleaseDC(m_hWnd, m_hDC);
	
	// compatible로 생성된 친구들은 delete로 삭제해야함
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

CObject g_obj;

int CCore::init(HWND _hWnd, Vec2 _vResolution)
{
	m_hWnd = _hWnd;
	m_vResolution = _vResolution;


	
	RECT rt = { 0, 0, m_vResolution.x, m_vResolution.y };
	
	
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true); 
	SetWindowPos(_hWnd, nullptr, 0, 0,
		rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd); 

	// 이중 버퍼링 용도의 비트맵과 DC를 생성
	m_hBit = CreateCompatibleBitmap(m_hDC, m_vResolution.x, m_vResolution.y);
	// 이 가짜 비트맵에 완전 렌더링 한 후 그 결과를 진짜 비트맵에 올릴거임
	// 그래야 서로 다른 오브젝트들이 따로 렌더링되지 않음
	m_memDC = CreateCompatibleDC(m_hDC); // 화면에 직접 출력되지않는 memory dc 생성
	// DC가 버퍼링 용도의 비트맵을 사용하게함	
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);	// 어차피 기존 bitmap은 필요없음 새로운 비트맵으로 교체해버리면됨
							// 쓸때없는 메모리인 기존 비트맵 삭제

			
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();

	g_obj.SetPos(Vec2{ (float)m_vResolution.x / 2, (float)m_vResolution.y / 2 });
	g_obj.SetScale(Vec2{ 100, 100 });

	return S_OK;
}


void CCore::progress()
{
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();


	update();
	
	render();
}
void CCore::update()
{
	Vec2 vPos = g_obj.GetPos();
	
	// 정말 운이 없을때 deltatime동안의 함수 로직이 동작하는 도중
	// 키를 떼면 동작 도중 나가지기 때문에 수정 요함
	// 우리는 동일한 키에 대해 동일한 결과가 나오게 만들것
	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)
	{
		vPos.x -= 200.f * CTimeMgr::GetInst()->GetDT();
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::TAP
		|| CKeyMgr::GetInst()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
	{
		vPos.x += 200.f * CTimeMgr::GetInst()->GetDT();

	}

	g_obj.SetPos(vPos);


	
}


void CCore::render()
{
	// 화면 clear
	// 화면 전체를 흰 사각형으로 다시 그림
	// 펜 두께가 보이지 않게 1픽셀씩 처리해주는것
	// 아무래도 화면 전체 픽셀을 #ffffff로 칠하는거니까 프레임이 확 떨어짐
	Rectangle(m_memDC, -1, -1, m_vResolution.x + 1, m_vResolution.y + 1);



	// 그리기
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_memDC
		, (int)vPos.x - vScale.x / 2
		, (int)vPos.y - vScale.y / 2
		, (int)vPos.x + vScale.x / 2
		, (int)vPos.y + vScale.y / 2);

	BitBlt(m_hDC, 0, 0, m_vResolution.x, m_vResolution.y,
		m_memDC, 0, 0, SRCCOPY); // hdc에서 지정한 크기만큼 복사할 dc의 지정한 위치에서 한픽셀씩 복사

}