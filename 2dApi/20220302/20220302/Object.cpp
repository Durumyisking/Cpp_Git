#include "pch.h"
#include "Object.h"

#include "TimeMgr.h"
#include "KeyMgr.h"

CObject::CObject()
	: m_vPos{}
	, m_vSclae{}
{
}

CObject::~CObject()
{
}


void CObject::render(HDC _dc)
{
	Rectangle(_dc,
		(int)m_vPos.x - m_vSclae.x / 2.f,
		(int)m_vPos.y - m_vSclae.y / 2.f,
		(int)m_vPos.x + m_vSclae.x / 2.f,
		(int)m_vPos.y + m_vSclae.y / 2.f);

	
}
