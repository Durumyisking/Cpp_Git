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
	
	// compatible�� ������ ģ������ delete�� �����ؾ���
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

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� ����
	m_hBit = CreateCompatibleBitmap(m_hDC, m_vResolution.x, m_vResolution.y);
	// �� ��¥ ��Ʈ�ʿ� ���� ������ �� �� �� ����� ��¥ ��Ʈ�ʿ� �ø�����
	// �׷��� ���� �ٸ� ������Ʈ���� ���� ���������� ����
	m_memDC = CreateCompatibleDC(m_hDC); // ȭ�鿡 ���� ��µ����ʴ� memory dc ����
	// DC�� ���۸� �뵵�� ��Ʈ���� ����ϰ���	
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);	// ������ ���� bitmap�� �ʿ���� ���ο� ��Ʈ������ ��ü�ع������
							// �������� �޸��� ���� ��Ʈ�� ����

			
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
	
	// ���� ���� ������ deltatime������ �Լ� ������ �����ϴ� ����
	// Ű�� ���� ���� ���� �������� ������ ���� ����
	// �츮�� ������ Ű�� ���� ������ ����� ������ �����
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
	// ȭ�� clear
	// ȭ�� ��ü�� �� �簢������ �ٽ� �׸�
	// �� �β��� ������ �ʰ� 1�ȼ��� ó�����ִ°�
	// �ƹ����� ȭ�� ��ü �ȼ��� #ffffff�� ĥ�ϴ°Ŵϱ� �������� Ȯ ������
	Rectangle(m_memDC, -1, -1, m_vResolution.x + 1, m_vResolution.y + 1);



	// �׸���
	Vec2 vPos = g_obj.GetPos();
	Vec2 vScale = g_obj.GetScale();

	Rectangle(m_memDC
		, (int)vPos.x - vScale.x / 2
		, (int)vPos.y - vScale.y / 2
		, (int)vPos.x + vScale.x / 2
		, (int)vPos.y + vScale.y / 2);

	BitBlt(m_hDC, 0, 0, m_vResolution.x, m_vResolution.y,
		m_memDC, 0, 0, SRCCOPY); // hdc���� ������ ũ�⸸ŭ ������ dc�� ������ ��ġ���� ���ȼ��� ����

}