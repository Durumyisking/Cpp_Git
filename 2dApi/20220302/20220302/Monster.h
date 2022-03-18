#pragma once
#include "Object.h"

class CMonster :
	public CObject
{

private:
	Vec2		m_vCenterPos;	// 와리가리 기준점
	float		m_fSpeed;
	float		m_fMaxDistance; // 최대 이동거리
	int			m_iDir;			// 이동 방향


public:
	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float _Speed) { m_fSpeed = _Speed; }
	void SetMoveDistance(float _f) { m_fMaxDistance = _f; }
	void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }

public:
	CMonster();
	~CMonster();
	
public:
	virtual void update();
	
};
