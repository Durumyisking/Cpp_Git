#pragma once
#include "Scene.h"
class CScene_Start :
	public CScene
{

private:
	int m_iWave;
	Vec2 vResolution;

public:
	CScene_Start();
	~CScene_Start();

public:
	virtual void Enter();	// virtual ����� �Ǵµ� �򰥸���� ������
	virtual void Exit();

public:
	virtual void StageEvent();
	virtual void render(HDC _dc);

};

	