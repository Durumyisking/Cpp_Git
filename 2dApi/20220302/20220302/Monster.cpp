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

	// 설정해준 최대 이동거리를 넘어서 이동했을때
	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;

	if (0.f < fDist)
	{
		// 기존 이동방향에서 방향을 바꾼 후
		m_iDir *= -1;
		// 넘어간 상태의 현재 중심 위치에서 반대방향으로 초과한만큼의 양을 더한다
		vCurPos.x += fDist * m_iDir;
		// 그럼 우리가 원하는 최대 이동거리에 도달하겠죠?
	}
	


	SetPos(vCurPos);
}
