#include "pch.h"
#include "Missile.h"

#include "Player.h"
#include "Monster.h"

#include "TimeMgr.h"


CMissile::CMissile()
	: m_fDir(1.f)
{
}


CMissile::~CMissile()
{
}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.y += 200.f * (float)m_fDir * fDT; // 여기서 200.f는 미사일의 속도

	SetPos(vPos);

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
