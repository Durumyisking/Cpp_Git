#include "pch.h"
#include "Monster.h"

#include "TimeMgr.h"


CMonster::CMonster()
	: m_vCenterPos(Vec2 (640.f, 150.f))
	, m_fSpeed(200.f)
	, m_fMaxDistance(100.f)
	, m_iDir(1)

{
}


CMonster::~CMonster()
{
}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();
	vCurPos.x += m_fSpeed * m_iDir * fDT;

	// �������� �ִ� �̵��Ÿ��� �Ѿ �̵�������
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	if (0.f < fDist)
	{
		// ���� �̵����⿡�� ������ �ٲ� ��
		m_iDir *= -1;
		// �Ѿ ������ ���� �߽� ��ġ���� �ݴ�������� �ʰ��Ѹ�ŭ�� ���� ���Ѵ�
		vCurPos.x += fDist * m_iDir;
		// �׷� �츮�� ���ϴ� �ִ� �̵��Ÿ��� �����ϰ���?
	}
	


	SetPos(vCurPos);
}
