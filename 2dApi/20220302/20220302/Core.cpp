#include "pch.h"
#include "Core.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

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

// CObject g_obj;

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

	// 매니저 초기화
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();

	return S_OK;
}


void CCore::progress()
{
	// Mgr update
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();
	
	// =========
	// Rendering
	// =========

	// 화면 클리어
	Rectangle(m_memDC, -1, -1, m_vResolution.x + 1, m_vResolution.y + 1);


	CSceneMgr::GetInst()->render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_vResolution.x, m_vResolution.y,
		m_memDC, 0, 0, SRCCOPY); // hdc에서 지정한 크기만큼 복사할 dc의 지정한 위치에서 한픽셀씩 복사

	
}