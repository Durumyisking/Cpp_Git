#include "pch.h"
#include "Player.h"

#include"Missile.h"


#include "Scene.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"


CPlayer::CPlayer()
	: m_dPrevTime(fDT)
	, m_pTex(nullptr)
{

	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player\\Player_1.bmp");
}


CPlayer::~CPlayer()
{
}


void CPlayer::update()
{
	m_dPrevTime += fDT;

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	if (KEY_HOLD(KEY::W))
	{
		if (vPos.y - (vScale.y / 2.f) < 0.f)
			vPos.y = 0.f + vScale.y/2;
		else
			vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		if (vPos.y + (vScale.y / 2.f) > 768.f)
			vPos.y = 768.f - vScale.y / 2;
		else
			vPos.y += 200.f * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		if (vPos.x - (vScale.x / 2.f) < 0.f)
			vPos.x = 0.f + vScale.x / 2;
		else
			vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		if (vPos.x + (vScale.x / 2.f) > 1280.f)
			vPos.x = 1280.f - vScale.x / 2;
		else
			vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
//		if (0.f > 0.f - m_dPrevTime)
//		{
		CreateMissile(1);
		//m_dPrevTime = 0.f;
//		}
	}

	if (KEY_TAP(KEY::Z))
	{
		CreateMissile(2);
	}

	if (KEY_TAP(KEY::X))
	{
		CreateMissile(3);
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

void CPlayer::CreateMissile(int _iType)
{
	CMissile* pMissile = new CMissile;

	Vec2 vMissilePos = GetPos(); // 현재 플레이어의 위치 가져옴
	vMissilePos.y -= GetScale().y / 2.f;

	pMissile->SetPos(vMissilePos);
	pMissile->SetStartVec(Vec2(vMissilePos));
	pMissile->SetScale(Vec2(10.f, 10.f));

	switch (_iType)
	{
	case 1:
		pMissile->SetType(1);
		pMissile->SetDir(Vec2(0.f, -1.f));
		break;

	case 2:
		pMissile->SetType(2);
		pMissile->SetDir(Vec2(1.f, -1.f));
		break;

	case 3:
		pMissile->SetType(3);
		pMissile->SetDir(Vec2(0.f, -1.f));
		break;


	default:
		break;
	}

	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::MISSILE);
}

