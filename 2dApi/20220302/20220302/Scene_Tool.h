#pragma once
#include "Scene.h"



class CScene_Tool :
	public CScene
{
public:
	CScene_Tool();
	~CScene_Tool();

public:
	virtual void update();
	virtual void render(HDC _dc);


public:
	virtual void Enter();
	virtual void Exit();

};


