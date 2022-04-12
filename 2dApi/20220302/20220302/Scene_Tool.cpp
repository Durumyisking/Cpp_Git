#include "pch.h"
#include "Scene_Tool.h"

#include "Tile.h"

#include "ResMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

#include "resource.h"


CScene_Tool::CScene_Tool()
	: m_pTileTex(nullptr)
{

}


CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::update()
{
	CScene::update();


	SetTileIdx();



}



void CScene_Tool::Enter()
{


	// Ÿ�� ����
	CreateTile(4, 8);

	CCamera::GetInst()->SetLookAt(m_vResolution / 2.f);
}

void CScene_Tool::Exit()
{
}

void CScene_Tool::SetTileIdx()
{
	Vec2 vMousePos = MOUSE_POS;

	if (KEY_TAP(KEY::LBTN))
	{
		Vec2 vMousePos = CCamera::GetInst()->GetRealPos(MOUSE_POS);

		UINT iTileX = GetTileX();
		UINT iTileY = GetTileY();

		UINT iCol = (UINT)vMousePos.x / ROCK_SIZE;
		UINT iRow = (UINT)vMousePos.y / ROCK_SIZE;

		UINT iIdx = iRow * iTileX + iCol;

		const vector <CObject*>& vecTile = GetGroupObject(GROUP_TYPE::TILE);
		((CTile*)vecTile[iIdx])->AddImgIdx();
				

	}
}









// �����Լ� �Դϴ�
// Tile Count Window Proc
INT_PTR CALLBACK TileCountProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{

			UINT iXCount = GetDlgItemInt(hDlg, IDC_EDIT1, nullptr, false);
			UINT iYCount = GetDlgItemInt(hDlg, IDC_EDIT2, nullptr, false);

			CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();

			// tool scene������ �����ϴ� �Լ��ϱ� ó�� ������
			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			pToolScene->DeleteGroup(GROUP_TYPE::TILE);
			pToolScene->CreateTile(iXCount, iYCount);
			


			// EndDialog�� �ι�° ���ڴ� dialogbox �Լ� ��������� �����
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}