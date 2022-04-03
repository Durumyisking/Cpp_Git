#include "pch.h"
#include "Scene_Tool.h"

#include "ResMgr.h"
#include "KeyMgr.h"


CScene_Tool::CScene_Tool()
{
	m_pTex = CResMgr::GetInst()->LoadTexture(L"ToolSceneText", L"texture\\BackGround\\BG_Tool.bmp");

}


CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}


void CScene_Tool::render(HDC _dc)
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

void CScene_Tool::Enter()
{
}

void CScene_Tool::Exit()
{
}