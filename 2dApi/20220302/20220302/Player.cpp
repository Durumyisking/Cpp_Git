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

	// 직선 미사일
	if (KEY_TAP(KEY::SPACE))
	{
//		if (0.f > 0.f - m_dPrevTime)
//		{
		CMissile* pMissile = new CMissile;
		pMissile->CreateMissile(MISSILE_TYPE::DEFAULT , GetPos(), GROUP_TYPE::PLAYER);
		//m_dPrevTime = 0.f;
//		}
	}

	// 지그재그 미사일
	// (꼬불꼬불 미사일은 cos함수로 구현하자)
	if (KEY_TAP(KEY::Z))
	{
		CMissile* pMissile = new CMissile;
		pMissile->CreateMissile(MISSILE_TYPE::ZIGJAG, GetPos(), GROUP_TYPE::PLAYER);
	}

	// 유도 미사일 (아직 미구현)
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
	int iHeight = (int)m_pTex->Height(); //Tex.Wid/height는 unsignedint지만 우리 maindc에서는 이 텍스처가 화면을 넘어갈 수도 있기 때문에 넘어가면 비트값에 문제가 생겨 int로 캐스팅


	Vec2 vPos = GetPos();

	// 계산하기전에 정확하게 하기위해 실수로 계산	
	//BitBlt(_dc
	//	, (int)(vPos.x - (float)(iWidth / 2))
	//	, (int)(vPos.y - (float)(iHeight / 2))
	//	, iWidth, iHeight
	//	, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);

	// 얘는 원본 src의 좌상단만 알려주는게 아니라
	// 원본 src의 좌상단으로부터 어디까지 지울거냐 하는 좌표도 받음

	// lnk 1120 뜬다는것은 우리가 헤더를 참조했기 때문에
	// 이 함수가 존재하는것은 알고있음 그래서 호출까지 가능함
	// 근데 실제 구현부는 몰라서 링크하는데 문제가생김
	// 그래서 구현파트도 참조해야함
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));

	// 컴포넌트 (충돌체, etc...)가 잉ㅆ는 경우 렌더
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

