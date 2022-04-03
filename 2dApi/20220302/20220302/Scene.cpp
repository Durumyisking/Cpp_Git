#include "pch.h"
#include "Scene.h"

#include "TimeMgr.h"


CScene::CScene()
	:m_fTimeCount(0)
	,m_pTex(nullptr)
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

void CScene::DeleteGroup(GROUP_TYPE _eTarget)
{
	Safe_Delete_Vec<CObject*>(m_arrObj[(UINT)_eTarget]);
}

void CScene::DeleteAll()
{
	for (size_t i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{

		Safe_Delete_Vec<CObject*>(m_arrObj[i]);
	}
}

void CScene::update()
{
	m_fTimeCount += fDT;

	
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			if (!m_arrObj[i][j]->IsDead())
				m_arrObj[i][j]->update(); 
		}
	}

}

void CScene::finalupdate()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_arrObj[i].size(); ++j)
		{
			m_arrObj[i][j]->finalupdate();
		}
	}

}

void CScene::render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		// �츮�� Obj�� �����ϱ� ���ؼ���
		// delete obj �� ������ �ܰ��� (update - *render* - event(���⼭ delete))
		// render�ܰ迡�� �����Ͽ��� �Ѵ� (���� ���ϸ� ������ obj�� �����ַ��� �ϰڧc?
		// erase�Լ� �������� iterator�� ����
		vector<CObject*>::iterator iter = m_arrObj[i].begin();

		// erase�� �����ϸ� ���� iter�� ��ȯ�ϱ� ������ ++�� iter�� �� �� ����Ѵ�
		// ���� obj�� alive�����϶� ++���ְ� �ƴҶ� erase���༭ �ݺ��Ѵ�
		for (; iter != m_arrObj[i].end();)
		{
			if (!(*iter)->IsDead())
			{
				(*iter)->render(_dc);
				++iter;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}


void CScene::CreateMonster(CMonster * _pMonster, Vec2 _vPos, Vec2 _vScale, float _fMoveDist, float _fSpeed, float _fAcc)
{
	// ���� ������ �����Ѵ�.
}

