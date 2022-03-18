#pragma once
#include "Object.h"

class CMonster :
	public CObject
{

private:
	Vec2		m_vCenterPos;	// �͸����� ������
	float		m_fSpeed;
	float		m_fMaxDistance; // �ִ� �̵��Ÿ�
	int			m_iDir;			// �̵� ����


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
