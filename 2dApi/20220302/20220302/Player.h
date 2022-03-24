#pragma once
#include "Object.h"
#include"Texture.h"

class CPlayer :
	public CObject
{
private:
	double		m_dPrevTime; // ��Ÿ ��Ÿ��
	CTexture*	m_pTex;


public:
	CPlayer();
	~CPlayer();

public:
	virtual void update();
	virtual void render(HDC _dc);

private:
	void CreateMissile(int _iType);

};

