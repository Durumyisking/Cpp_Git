#pragma once
#include "Scene.h"
class CScene_Start :
	public CScene
{

private:
	float m_fWave;
public:
	CScene_Start();
	~CScene_Start();

public:
	virtual void Enter();	// virtual ����� �Ǵµ� �򰥸���� ������
	virtual void Exit();

public:
	virtual void StageEvent();


};

	