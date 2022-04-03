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
#include"EventMgr.h"
#include"SceneMgr.h"
#include "KeyMgr.h"


CScene_Start::CScene_Start()
	:m_iWave(1)
	, vResolution(CCore::GetInst()->GetResolution())
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"StartSceneTex", L"texture\\BackGround\\BG_Start.bmp");
	
}


CScene_Start::~CScene_Start()
{
	DeleteAll();

	CCollisionMgr::GetInst()->Reset();
}


void CScene_Start::Enter()
{
	// Player Object 추가
	CObject* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(vResolution.x/2, vResolution.y/2 + 300.f));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	pPlayer->SetName(L"Player");
	CreateObject(pPlayer, GROUP_TYPE::PLAYER);

	CObject* pPlayer2 = pPlayer->Clone();
	pPlayer->SetPos(Vec2(vResolution.x / 2 + 100, vResolution.y / 2 + 300.f));
	CreateObject(pPlayer2, GROUP_TYPE::PLAYER);



	// 충돌 지정

	// Player - Monster
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	//CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::PROJ_MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PROJ_PLAYER);
	
}

void CScene_Start::Exit()
{
	DeleteAll();

	// 다른 씬에서는 다른 충돌 그룹을 쓸 수 있기 때문에 해제시켜주어야함
	CCollisionMgr::GetInst()->Reset();

}

void CScene_Start::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::STAGE_01);
	}

	if (m_fTimeCount > 1.f && m_iWave < 4)
	{
		int			iMonsterCount = 3;
		Vec2		vObjPos = {};
		Vec2		vObjScale = { 30.f, 30.f };
		float		fSpeed = 500.f;
		float		fAcc = -300.f;
		float		fMoveDist = fSpeed - fAcc * fDT;


		float fTerm = 40.f;

		CMonster* pMonster = nullptr;

		switch (m_iWave)
		{
		case 1:


			for (int i = 0; i < iMonsterCount; ++i)
			{
				pMonster = new CMonster;
				pMonster->SetName(L"Monster");

				vObjPos = { vResolution.x / 2 + fTerm * (i - 1), -(vObjScale.x / 2.f) };

				CreateMonster(pMonster, vObjPos, vObjScale, fMoveDist, fSpeed, fAcc);
			}
			break;
		case 2:
			iMonsterCount = 3;
			fSpeed = 500.f;
			fAcc = -300.f;
			fMoveDist = fSpeed - fAcc * fDT;
			vObjScale = { 30.f, 30.f };


			for (int i = 0; i < iMonsterCount; ++i)
			{
				pMonster = new CMonster;
				pMonster->SetName(L"Monster");
				vObjPos = { 100.f + fTerm * i, -(vObjScale.x / 2.f) };

				CreateMonster(pMonster, vObjPos, vObjScale, fMoveDist, fSpeed, fAcc);

			}
			break;
		case 3:
			iMonsterCount = 3;
			fSpeed = 500.f;
			fAcc = -300.f;
			fMoveDist = fSpeed - fAcc * fDT;
			vObjScale = { 30.f, 30.f };


			for (int i = 0; i < iMonsterCount; ++i)
			{
				pMonster = new CMonster;
				pMonster->SetName(L"Monster");
				vObjPos = { vResolution.x - 100.f - fTerm * i, -(vObjScale.x / 2.f) };

				CreateMonster(pMonster, vObjPos, vObjScale, fMoveDist, fSpeed, fAcc);

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

	CScene::render(_dc);
	
}

void CScene_Start::CreateMonster(CMonster* _pMonster, Vec2 _vPos, Vec2 _vScale, float _fMoveDist, float _fSpeed, float _fAcc)
{
	_pMonster->SetPos(_vPos);
	_pMonster->SetScale(_vScale);
	_pMonster->SetCenterPos(_pMonster->GetPos());
	_pMonster->SetMoveDistance(_fMoveDist);
	_pMonster->SetSpeed(_fSpeed);
	_pMonster->SetAcc(_fAcc);
	CreateObject(_pMonster, GROUP_TYPE::MONSTER);
}
