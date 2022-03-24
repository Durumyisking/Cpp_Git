#include "pch.h"
#include "Missile.h"

#include "Player.h"
#include "Monster.h"

#include "TimeMgr.h"

#include "Core.h"


CMissile::CMissile()
	: m_fTheta(PI / 2.f)
	, m_vDir(Vec2(0.f, -1.f))
	, m_vStartvec()
	, m_fModifyXDir(0.1f)
	, m_fModifyYDir(0.f)
	, m_bCase(false)
{
	m_vDir.Nomalize();
}


CMissile::~CMissile()
{

}

void CMissile::update()
{

	MissileType();

	if (0 > GetPos().y)
	{
		// scene의 obj벡터의 여기 인덱스를 erase 해주는 함수

		// delete this;
	}

}

void CMissile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();


	Ellipse(_dc,
		(int)vPos.x - vScale.x / 2.f,
		(int)vPos.y - vScale.y / 2.f,
		(int)vPos.x + vScale.x / 2.f,
		(int)vPos.y + vScale.y / 2.f);
}

void CMissile::MissileType()
{
	Vec2 vPos = GetPos();

	switch (m_iType)


	{
	case 1:
	{
//		vPos.x += 400.f * cosf(m_fTheta) * fDT;
//		vPos.y -= 400.f * sinf(m_fTheta) * fDT;

		vPos.x += 400.f * m_vDir.x * fDT;
		vPos.y += 400.f * m_vDir.y * fDT;

		SetPos(vPos);
	}
		break;
	case 2:
	{	
		vPos.x += 500.f * m_vDir.x * fDT;
		vPos.y += 200.f * m_vDir.y * fDT;


		if (GetPos().x > m_vStartvec.x + 100.f)
		{
			SetPos(Vec2(m_vStartvec.x + 100, vPos.y));
			m_vDir.x *= -1;
		}
		else if (GetPos().x < m_vStartvec.x - 100.f)
		{
			SetPos(Vec2(m_vStartvec.x - 100.f, vPos.y));
			m_vDir.x *= -1;
		}
		
		else 
			SetPos(vPos);

		return;
	}
		break;

	case 3:
	{

	}

	default:
		break;
	}
}