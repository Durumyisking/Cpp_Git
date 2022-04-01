#include "pch.h"
#include "Scene_Start.h"

#include "Object.h"
#include "Player.h"
#include "Monster.h"

#include "Core.h"

#include"TimeMgr.h"
#include"PathMgr.h"
#include"ResMgr.h"
#include"CollisionMgr.h"


CScene_Start::CScene_Start()
	:m_iWave(1)
	, vResolution(CCore::GetInst()->GetResolution())
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"StartSceneTex", L"texture\\BackGround\\BG.bmp");
	
}


CScene_Start::~CScene_Start()
{
}


void CScene_Start::Enter()
{
	// Player Object 추가
	CObject* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(vResolution.x/2, vResolution.y/2 + 300.f));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayer, GROUP_TYPE::PLAYER);




	// 충돌 지정

	// Player - Monster
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MISSILE);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::MISSILE);
	
}

void CScene_Start::Exit()
{
	// 다른 씬에서는 다른 충돌 그룹을 쓸 수 있기 때문에 해제시켜주어야함
	CCollisionMgr::GetInst()->Reset();

}

void CScene_Start::StageEvent()
{


	if (m_fTimeCount > 1.f && m_iWave < 4)
	{
		int iMonsterCount = 0;
		float fMoveDist = 0.f;
		float fSpeed = 0.f;
		float fAcc = 0.f;
		float fObjScale = 0.f;

		
		float fTerm = 40.f;

		CMonster* pMonster = nullptr;

		switch (m_iWave)
		{
		case 1:
			iMonsterCount = 3;
			fSpeed = 500.f;
			fAcc = -300.f;
			fMoveDist = fSpeed -fAcc * fDT;
			fObjScale = 30.f;
			

			for (int i = 0; i < iMonsterCount; ++i)
			{
				pMonster = new CMonster;

				pMonster->SetPos(Vec2(vResolution.x/2 + fTerm * (i-1), -(fObjScale / 2.f)));
				pMonster->SetCenterPos(pMonster->GetPos());
				pMonster->SetMoveDistance(fMoveDist);
				pMonster->SetSpeed(fSpeed);
				pMonster->SetAcc(fAcc);
				pMonster->SetScale(Vec2(fObjScale, fObjScale));
				AddObject(pMonster, GROUP_TYPE::MONSTER);
			}
			break;
		case 2:
			iMonsterCount = 3;
			fSpeed = 500.f;
			fAcc = -300.f;
			fMoveDist = fSpeed - fAcc * fDT;
			fObjScale = 30.f;


			for (int i = 0; i < iMonsterCount; ++i)
			{
				pMonster = new CMonster;

				pMonster->SetPos(Vec2(100.f + fTerm * i, -(fObjScale / 2.f)));
				pMonster->SetCenterPos(pMonster->GetPos());
				pMonster->SetMoveDistance(fMoveDist);
				pMonster->SetSpeed(fSpeed);
				pMonster->SetAcc(fAcc);
				pMonster->SetScale(Vec2(fObjScale, fObjScale));
				AddObject(pMonster, GROUP_TYPE::MONSTER);
			}
			break;
		case 3:
			iMonsterCount = 3;
			fSpeed = 500.f;
			fAcc = -300.f;
			fMoveDist = fSpeed - fAcc * fDT;
			fObjScale = 30.f;


			for (int i = 0; i < iMonsterCount; ++i)
			{
				pMonster = new CMonster;

				pMonster->SetPos(Vec2(vResolution.x - 100.f - fTerm * i, -(fObjScale / 2.f)));
				pMonster->SetCenterPos(pMonster->GetPos());
				pMonster->SetMoveDistance(fMoveDist);
				pMonster->SetSpeed(fSpeed);
				pMonster->SetAcc(fAcc);
				pMonster->SetScale(Vec2(fObjScale, fObjScale));
				AddObject(pMonster, GROUP_TYPE::MONSTER);
			}
			break;
		}
		

		
		++m_iWave;
		m_fTimeCount = 0.f;
	}
	
}

void CScene_Start::render(HDC _dc)
{

	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();


	TransparentBlt(_dc
		, (int)(0.f)
		, (int)(0.f)
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, iWidth, iHeight
		, RGB(255, 0, 255));

	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->render(_dc);
		}
	}
}
