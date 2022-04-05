#include "pch.h"
#include "Player.h"
#include"Missile.h"
#include "Scene.h"
#include "Collider.h"
#include "Animator.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"


CPlayer::CPlayer()
	: m_dPrevTime(fDT)
{
	// 콜라이더 생성
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, -10.f));
	GetCollider()->SetScale(Vec2(40.f, 40.f));

	// 애니메이션 생성
	CTexture* m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player\\Player.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Anim_Idle", m_pTex, Vec2(0.f, 0.f), Vec2(60.f, 65.f), Vec2(60.f, 0.f), 0.05f, 3);
	GetAnimator()->Play(L"Anim_Idle" , true);
	GetAnimator()->CreateAnimation(L"Anim_WalkDown", m_pTex, Vec2(0.f, 260.f), Vec2(60.f, 65.f), Vec2(60.f, 0.f), 0.05f, 10);

}


CPlayer::~CPlayer()
{
}


void CPlayer::update()
{
	m_dPrevTime += fDT;

	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();



/////////////////////////////////////////////////////////////
	//KEY//
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
		{
			GetAnimator()->Play(L"Anim_WalkDown", true);
			vPos.y = 768.f - vScale.y / 2;
		}
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

	// 직선 미사일
	if (KEY_TAP(KEY::SPACE))
	{
//		if (0.f > 0.f - m_dPrevTime)
//		{
		CMissile* pMissile = new CMissile;
		pMissile->CreateMissile(MISSILE_TYPE::DEFAULT , GetPos(), GROUP_TYPE::PROJ_PLAYER);
		//m_dPrevTime = 0.f;
//		}
	}

	// 지그재그 미사일
	// (꼬불꼬불 미사일은 cos함수로 구현하자)
	if (KEY_TAP(KEY::Z))
	{
		CMissile* pMissile = new CMissile;
		pMissile->CreateMissile(MISSILE_TYPE::ZIGJAG, GetPos(), GROUP_TYPE::PROJ_PLAYER);
	}

	// 유도 미사일 (아직 미구현)
	if (KEY_TAP(KEY::X))
	{
		//CMissile* pMissile = new CMissile;
		//pMissile->CreateMissile(3);
	}
///////////////////////////////////////////////////////

	SetPos(vPos);

	GetAnimator()->update();
}

void CPlayer::render(HDC _dc)
{
	component_render(_dc);
}

void CPlayer::OnCollision(CCollider * _pOther)
{
	
}

void CPlayer::OnCollisionEnter(CCollider * _pOther)
{
}

void CPlayer::OnCollisionExit(CCollider * _pOther)
{
}

