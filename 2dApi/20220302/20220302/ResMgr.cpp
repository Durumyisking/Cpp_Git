#include "pch.h"
#include "ResMgr.h"

#include"PathMgr.h"
#include"Texture.h"

CResMgr::CResMgr()
{
}


CResMgr::~CResMgr()
{
	map <wstring, CTexture*>::iterator iter = m_mapTex.begin();

	for (; iter != m_mapTex.end(); ++iter)
		delete iter->second;
}

// _strkey : �ؽ�ó�� ResMgr���� ã�ƿ��� ���� key��, _strRelativePath : ����� ��� (���� ��θ� pathmgr���� �ذ�)
CTexture * CResMgr::LoadTexture(const wstring & _strKey, const wstring & _strRelativePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (nullptr != pTex)	// _strKey�� ���� �ؽ�ó�� �����ϸ�
		return pTex;		// ���� �ؽ�ó ��ȯ


	wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new CTexture; // �ؽ�ó�� ������ ��ü �����Ҵ�
	pTex->Load(strFilePath); // �ؽ�ó ��ü�� Bitmap�� ���� ��� �޾Ƽ� ����
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture * CResMgr::FindTexture(const wstring & _strKey)
{
	map<wstring, CTexture*>::iterator iter = m_mapTex.find(_strKey);

	if (m_mapTex.end() == iter)
	{
		return nullptr;
	}

	return iter->second;
}
