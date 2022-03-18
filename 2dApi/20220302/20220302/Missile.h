#pragma once

#include "Object.h"

class CMissile :
	public CObject
{
private:
	float		m_fDir; // 위 아래 방향


public:
	CMissile();
	~CMissile();

public:
	void SetDir(bool _bUp)
	{
		if (_bUp)
			m_fDir = -1.f;
		else
			m_fDir = 1.f;
	}

public:
	virtual void update();
	virtual void render(HDC _dc);
};

