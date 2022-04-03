#include "pch.h"
#include "Player.h"
#include"Missile.h"
#include "Scene.h"
#include "Collider.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "ResMgr.h"


CPlayer::CPlayer()
	: m_dPrevTime(fDT)
	, m_pTex(nullptr)
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player\\Player_1.bmp");
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(0.f, -10.f));
	GetCollider()->SetScale(Vec2(40.f, 40.f));
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

	// ���� �̻���
	if (KEY_TAP(KEY::SPACE))
	{
//		if (0.f > 0.f - m_dPrevTime)
//		{
		CMissile* pMissile = new CMissile;
		pMissile->CreateMissile(MISSILE_TYPE::DEFAULT , GetPos(), GROUP_TYPE::PROJ_PLAYER);
		//m_dPrevTime = 0.f;
//		}
	}

	// ������� �̻���
	// (���Ҳ��� �̻����� cos�Լ��� ��������)
	if (KEY_TAP(KEY::Z))
	{
		CMissile* pMissile = new CMissile;
		pMissile->CreateMissile(MISSILE_TYPE::ZIGJAG, GetPos(), GROUP_TYPE::PROJ_PLAYER);
	}

	// ���� �̻��� (���� �̱���)
	if (KEY_TAP(KEY::X))
	{
		//CMissile* pMissile = new CMissile;
		//pMissile->CreateMissile(3);
	}


	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height(); //Tex.Wid/height�� unsignedint���� �츮 main_dc������ �� �ؽ�ó�� ȭ���� �Ѿ ���� �ֱ� ������ �Ѿ�� ��Ʈ���� ������ ���� int�� ĳ����


	Vec2 vPos = GetPos();

	// ����ϱ����� ��Ȯ�ϰ� �ϱ����� �Ǽ��� ���	
	//BitBlt(_dc
	//	, (int)(vPos.x - (float)(iWidth / 2))
	//	, (int)(vPos.y - (float)(iHeight / 2))
	//	, iWidth, iHeight
	//	, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);

	// ��� ���� src�� �»�ܸ� �˷��ִ°� �ƴ϶�
	// ���� src�� �»�����κ��� ������ ����ų� �ϴ� ��ǥ�� ����

	// lnk 1120 ��ٴ°��� �츮�� ����� �����߱� ������
	// �� �Լ��� �����ϴ°��� �˰����� �׷��� ȣ����� ������
	// �ٵ� ���� �����δ� ���� ��ũ�ϴµ� ����������
	// �׷��� ������Ʈ�� �����ؾ���
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));

	// ������Ʈ (�浹ü, etc...)�� �פ��� ��� ����
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

