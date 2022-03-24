#pragma once
#include "Res.h"
class CTexture :
	public CRes
{

private:
	// �� �� 4����Ʈ ����
	HDC			m_dc;
	HBITMAP		m_hBit;
	BITMAP		m_bitInfo;

private: // �츮�� ��ü������ �����Ҵ� �Ұ����ϰ� private���� ��
	CTexture();
	~CTexture();

	friend class CResMgr;

public:
	void Load(const wstring& _strFilePath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }

	HDC GetDC() { return m_dc; }

};

