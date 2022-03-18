#include "pch.h"
#include "Player.h"

#include"Missile.h"

#include "Scene.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}


void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));


	HBRUSH hDefaultBrush = (HBRUSH)SelectObject(_dc, hBlueBrush);

	Ellipse(_dc,
		(int)vPos.x - vScale.x / 2.f,
		(int)vPos.y - vScale.y / 2.f,
		(int)vPos.x + vScale.x / 2.f,
		(int)vPos.y + vScale.y / 2.f);


	SelectObject(_dc, hDefaultBrush);

	DeleteObject(hBlueBrush);
}

void CPlayer::CreateMissile()
{
	CMissile* pMissile = new CMissile;

	Vec2 vMissilePos = GetPos(); // 현재 플레이어의 위치 가져옴
	vMissilePos.y -= GetScale().y / 2.f;

	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(10.f, 10.f));
	pMissile->SetDir(true);

	
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::MISSILE);
}



