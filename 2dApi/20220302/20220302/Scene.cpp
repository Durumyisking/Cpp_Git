#include "pch.h"
#include "Scene.h"

#include "TimeMgr.h"


CScene::CScene()
	:m_fTimeCount(0)
{
}


CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		// m_arrObj[i]�� ���� �Ҹ��ڰ� ȣ�� �� �� �ڵ����� vector �Ҹ��ڸ� �θ���
		// ���Ͱ� CScene�� ����ϱ�!
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			delete m_arrObj[i][j];
		}
	}
}

void CScene::update()
{
	m_fTimeCount += fDT;

	
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->update(); 
		}
	}

}

void CScene::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->render(_dc);
		}
	}
}

