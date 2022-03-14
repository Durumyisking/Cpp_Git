#pragma once
#include "Scene.h"
class CScene_Start :
	public CScene
{
public:
	CScene_Start();
	~CScene_Start();

public:
	virtual void Enter();	// virtual 안적어도 되는데 헷갈릴까봐 적어줌
	virtual void Exit();
};

