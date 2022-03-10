#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"


CTimeMgr::CTimeMgr()
	: m_llCurCount{} // union�̶� {} �ʱ�ȭ
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDeltaTime(0.)
	, m_dAcc(0.)
	, m_iCallCount(0)
{

}


CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// ���� ī��Ʈ
	QueryPerformanceCounter(&m_llPrevCount);

	// 1�ʰ� ���������� count�� �󸶳� ���̳����� ���ؿ;���

	// �ʴ� ī��Ʈ�� �󸶳� �Ͼ���� Ƚ��
	QueryPerformanceFrequency(&m_llFrequency);



}

void CTimeMgr::update()
{
	// �� ������Ʈ���� �� �����Ӹ��� �ɸ� �ð��� �����ð�
	QueryPerformanceCounter(&m_llCurCount);


	// ������Ʈ�� �� �����Ӹ��� �ϴϱ� ���� ������Ʈ��
	// �̹� ������Ʈ�� ���� �ð��� ���� ����ϸ� 1�����Ӵ� �ɸ� �ð��� ����
	// 1������ �̵��� �ɸ��� ƽ = �� �����Ӵ� �ɸ��� ƽ / �ʴ� ƽ�� �󸶳� �����ϴ���
	m_dDeltaTime = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;
	// QuadPard = Large_Integer ���� LongLongŸ�� �ڷ���
	
	++m_iCallCount; // �Լ� ȣ�� Ƚ��

	m_dAcc += m_dDeltaTime;

	// �̷��� ���� deltatime �� �����ϸ� fps
	// �׷��� �̷��� ���� fps�� �Ҿ����� deltatime�� �ʹ� �̼��ؼ� �������� fps���� ���̰� �� ��
	// �׷��� 1�ʵ��� �� �����Ӹ��� ȣ��Ǵ� �� update�Լ��� ��� ȣ��Ǵ��� üũ�ϴ°� ����
	if (m_dAcc >= 1.) // 1�ʰ� �Ǹ� ����
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;
		m_dAcc = 0.;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %F", m_iFPS, m_dDeltaTime);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}



	m_llPrevCount = m_llCurCount; // ���̰� ��� �� �ٽ� ���� ī��Ʈ ����

}


// fps�� 100�̴� = �� ���ට 1�� ó���ϸ� 100�� ó�������� 1�̴�
// �� ���� ó���� = 1�ʴ� ó���ϰ���� ���෮ / �ʴ� ó����
// �� ���� ������ ���� �� = 1�ʵ��� �����ְ���� ��� * cpu���� 1�����Ӵ� �ɸ��� ���� �ð�
// �� �� �����ӿ� �ɸ��� �ð� ��ŭ�� ��ü �翡�� ó���ϰڴٴ� ��