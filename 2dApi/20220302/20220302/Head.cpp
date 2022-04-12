#include "pch.h"
#include "Head.h"

#include "Collider.h"
#include "Animation.h"
#include "Animator.h"

#include "Missile.h"

#include "ResMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"


CHead::CHead()
	: m_pAnim(nullptr)
	, m_strAnimName(L"HEAD_DOWN")
{
	

	// �ݶ��̴� ����
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(28.f, 25.f));

	// �ִϸ��̼� ����

	// isaac head
	CTexture* m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player\\isaac.bmp");

	CreateAnimator();

	GetAnimator()->CreateAnimation(L"HEAD_UP", m_pTex, Vec2(170.f, 25.f), Vec2(28.f, 25.f), Vec2(40.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"HEAD_DOWN", m_pTex, Vec2(10.f, 25.f), Vec2(28.f, 25.f), Vec2(40.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"HEAD_LEFT", m_pTex, Vec2(250.f, 25.f), Vec2(28.f, 25.f), Vec2(40.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"HEAD_RIGHT", m_pTex, Vec2(90.f, 25.f), Vec2(28.f, 25.f), Vec2(40.f, 0.f), 0.5f, 2);


	PlayAnim(m_pAnim, m_strAnimName, Vec2(0.f, 0.f));


}


CHead::~CHead()
{
}


void CHead::update()
{

	CPlayer::update();
	if (KEY_HOLD(KEY::UP))
	{
		GetAnimator()->Play(m_strAnimName, false); 
		m_strAnimName = L"HEAD_UP";
		PlayAnim(m_pAnim, m_strAnimName, Vec2(0.f, 0.f));

		CreateMissile(Vec2(0.f, -1.f));
	}

	if (KEY_HOLD(KEY::DOWN))
	{
		GetAnimator()->Play(m_strAnimName, false);
		m_strAnimName = L"HEAD_DOWN";
		PlayAnim(m_pAnim, m_strAnimName, Vec2(0.f, 0.f));

		CreateMissile(Vec2(0.f, 1.f));
	}

	if (KEY_HOLD(KEY::LEFT))
	{
		GetAnimator()->Play(m_strAnimName, false);
		m_strAnimName = L"HEAD_LEFT";
		PlayAnim(m_pAnim, m_strAnimName, Vec2(0.f, 0.f));

		CreateMissile(Vec2(-1.f, 0.f));
	}

	if (KEY_HOLD(KEY::RIGHT))
	{
		GetAnimator()->Play(m_strAnimName, false);
		m_strAnimName = L"HEAD_RIGHT";
		PlayAnim(m_pAnim, m_strAnimName, Vec2(0.f, 0.f));

		CreateMissile(Vec2(1.f, 0.f));
	}

	if (KEY_AWAY(KEY::UP) || KEY_AWAY(KEY::DOWN) ||
		KEY_AWAY(KEY::LEFT) || KEY_AWAY(KEY::RIGHT))
	{
		GetAnimator()->Play(m_strAnimName, false);
		m_strAnimName = L"HEAD_DOWN";
		PlayAnim(m_pAnim, m_strAnimName, Vec2(0.f, 0.f));
	}
}

void CHead::CreateMissile(Vec2 _vDir)
{
	if (m_dPrevTime > m_fAttackDelay)
	{
		CMissile* pMissile = new CMissile;
		pMissile->SetDir(_vDir);
		pMissile->CreateMissile(MISSILE_TYPE::DEFAULT, GetPos() + Vec2(0.f, 0.f), GROUP_TYPE::PROJ_PLAYER);

		m_dPrevTime = 0.f;
	}

}
