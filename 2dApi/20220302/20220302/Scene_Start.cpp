#include "pch.h"
#include "Scene_Start.h"

#include "Object.h"
#include "Player.h"
#include "Monster.h"

#include "Core.h"

#include"PathMgr.h"
#include"ResMgr.h"


CScene_Start::CScene_Start()
	:m_fWave(1)
{

	m_pTex = CResMgr::GetInst()->LoadTexture(L"StartSceneTex", L"texture\\BackGround\\BG.bmp");

}


CScene_Start::~CScene_Start()
{
}


void CScene_Start::Enter()
{
	//Texture 로딩하기


	// Object 추가
	CObject* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(640.f, 500.f));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayer, GROUP_TYPE::PLAYER);



	int iMonsterCount = m_fWave;
	float fMoveDist = 100.f;
	float fObjScale = 30.f;

	Vec2 vResolution = CCore::GetInst()->GetResolution();

	CMonster* pMonster = nullptr;

	// Monster Obj 추가
	pMonster = new CMonster;

	pMonster->SetPos(Vec2(vResolution.x / (iMonsterCount + 1) * (float)(0 + 1), 50.f * m_fWave));
	pMonster->SetCenterPos(pMonster->GetPos());
	pMonster->SetMoveDistance(fMoveDist);
	pMonster->SetScale(Vec2(fObjScale, fObjScale));
	AddObject(pMonster, GROUP_TYPE::MONSTER);


}

void CScene_Start::Exit()
{
}

void CScene_Start::StageEvent()
{

	
	
	/*
	if (m_fTimeCount > 1.f && m_fWave < 7)
	{
		int iMonsterCount = m_fWave;
		float fMoveDist = 100.f;
		float fObjScale = 30.f;

		Vec2 vResolution = CCore::GetInst()->GetResolution();
		//float fTerm = (vResolution.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonsterCount - 1);
		

		CMonster* pMonster = nullptr;


		for (int i = 0; i < iMonsterCount; ++i)
		{
			// Monster Obj 추가
			pMonster = new CMonster;

			pMonster->SetPos(Vec2(vResolution.x / (iMonsterCount + 1) * (float)(i+1), 50.f * m_fWave));
			pMonster->SetCenterPos(pMonster->GetPos());
			pMonster->SetMoveDistance(fMoveDist);
			pMonster->SetScale(Vec2(fObjScale, fObjScale));
			AddObject(pMonster, GROUP_TYPE::MONSTER);
		}

		
		++m_fWave;
		m_fTimeCount = 0.f;
	}

	*/
}
