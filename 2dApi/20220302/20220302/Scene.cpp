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
		// m_arrObj[i]는 여기 소멸자가 호출 될 때 자동으로 vector 소멸자를 부른다
		// 벡터가 CScene의 멤버니까!
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
		// 우리가 Obj를 삭제하기 위해서는
		// delete obj 전 마지막 단계인 (update - *render* - event(여기서 delete))
		// render단계에서 삭제하여야 한다 (삭제 안하면 삭제한 obj를 보여주려고 하겠쬬?
		// erase함수 쓰기위해 iterator로 선언
		vector<CObject*>::iterator iter = m_arrObj[i].begin();

		// erase로 삭제하면 다음 iter을 반환하기 때문에 ++시 iter가 두 번 상승한다
		// 따라서 obj가 alive상태일때 ++해주고 아닐땐 erase해줘서 반복한다
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




