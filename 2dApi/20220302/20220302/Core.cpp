#include "pch.h"
#include "Core.h"

#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Object.h"

//// �����Ҵ� ���
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
	// ���� DC�� Ŀ�ο�����Ʈ�� �ü������ �����ش޶�� �ؾ���
	ReleaseDC(m_hWnd, m_hDC);
}

CObject g_obj;

int CCore::init(HWND _hWnd, Vec2 _vResolution)
{
	m_hWnd = _hWnd;
	m_vResolution = _vResolution;


	// �ػ󵵿� �°� ������ ũ�� ����
	RECT rt = { 0, 0, m_vResolution.x, m_vResolution.y };
	// �츮�� �޴��� ���� �ٲٰ� ������ SetWindowPos�� ������ ũ�� ��ü�� ������
	// �׷��� �츮�� ������ ũ�⸦ �츮�� ������ �ػ󵵰� ������ ����ִ� �Լ� AdjustWindowRect�� ���
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true); // ���� RECT* , Windowstyle, �޴��� ����
	// �̷����ϸ� rt�� �޴��ٰ� �ִ� WS_OVERLAPPEDWINDOW ��Ÿ���϶��� ���� ä����
	// AdjustWindowRect�� ���� return���� bool�̰� ������ �����ְ� ���� ���� �ּҷ� �޾Ƽ� �Ѱ���
	// return���� register�� ��ܼ� ���ƿ��µ� ����� ū�� ��ȯ�Ҷ��� ������ ���ϵ�
	// register�� ��⿡ �ʹ� ũ�� �ӽø޸𸮸� ��Ƽ� ���۷����� �ؾ��� ��
	SetWindowPos(_hWnd, nullptr, 0, 0,
		rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd); // m_hWnd�� DC�� ����

	// Manager �ʱ�ȭ
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();

	g_obj.SetPos(Vec2{ (float)m_vResolution.x / 2, (float)m_vResolution.y / 2 });
	g_obj.SetScale(Vec2{ 100, 100 });

	return S_OK;
}




void CCore::progress()
{
	// �������� paint�� ȭ���� �� �� �� ���ְ� �����ؼ� �ٽ� �׸��°Ÿ�
	// �츮�� ���׸��� ���׷��� ����� �籸���Ҳ�

	// �ǿܷ� �������� üũ�ؼ� �׺κи� �籸���ϰ� ����
	// ���ӿ����� �������� �������� �� �� ������ �ٽ� �������ϴ°�

	static int callcount = 0;
	++callcount;

	static int iPrevCount = GetTickCount(); // static���� �����Ͽ� �Լ� �����Խ� �ʱ�ȭ�� �ٽ� �ȵǰ� �Ѵ�
	int iCurrentCount = GetTickCount();

	if (iCurrentCount - iPrevCount > 1000) // �ʱ� �����ð����κ��� 1�ʰ� ������
	{
		iPrevCount = iCurrentCount; // ���� �ð��� �ʱ� �����ð����� ����
		callcount = 0;
		

	}
	CTimeMgr::GetInst()->update();




	update();

	render();



}
void CCore::update()
{
	// ���������� üũ

	Vec2 vPos = g_obj.GetPos();

	// �񵿱� Ű ����� �Լ� ( �ڵ尡 ����Ǵ� ���� �� ������ ���� Ű�� ���ȴ��� Ȯ��)

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)	// ���ڿ� �����ִ� Ű�� ���ȴ��� Ȯ��
	{										// true or false�� �ƴ϶� ���� ���¸� ��Ʈ �������� ����
		// vPos.x -= 0.01;					// ���� ������ Ȯ���Ϸ��� & 0x8000
		// �̷��� �ϸ� ��ǻ�� ���ɿ� ���� ���� �ӵ��� �޶���
		// �ӵ��� ���� ������Ʈ�� ���� �ɼ��� �������ϱ�

		// ���� ��ǻ�ʹ� ������ ������ �۰�
		// ���� ��ǻ�ʹ� ũ�� �ؼ� ���� ����� ���� �����ؾ���
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
�����쿡 �ִ� ��κп� �Լ�����
HRESULT�� ��ȯ�� HRESULT�� �׳� long��
HRESULT hr = S_OK;

if (FAILED(S_OK)) // FAILED�� ���ڿ� ������ ���� true, E_FAIL = ����, S_OK = 0, S_FALSE = 1
 ���� S_OK�� �Լ��� �����ߴٴ� ���̰�
 FAILED���� �ɸ��� ����

*/