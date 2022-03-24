#pragma once

#include "Object.h"

class CMissile :
	public CObject
{
private:
	float		m_fTheta;	// 각도

	Vec2		m_vDir;
	Vec2		m_vStartvec;

	int			m_iType;	// 미사일 타입

	float		m_fModifyXDir;
	float		m_fModifyYDir;
	
	bool		m_bCase;

public:
	CMissile();
	~CMissile();

public:
	void SetDir(float _fTheta) { m_fTheta = _fTheta; }
	void SetDir(Vec2 _vDir)
	{
		m_vDir = _vDir;
		m_vDir.Nomalize();
	}
	
	void SetType(int _iType) { m_iType = _iType; }

	void SetStartVec(Vec2 _vec) { m_vStartvec = _vec; }



public:
	virtual void update();
	virtual void render(HDC _dc);

public:
	void MissileType();


};

