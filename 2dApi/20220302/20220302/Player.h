#pragma once
#include "Object.h"
class CPlayer :
	public CObject
{
public:
	CPlayer();
	~CPlayer();

public:
	virtual void update();
	virtual void render(HDC _dc);

private:
	void CreateMissile();
};

