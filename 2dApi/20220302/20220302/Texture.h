#pragma once
#include "Res.h"
class CTexture :
	public CRes
{

private:
	// 둘 다 4바이트 정수
	HDC			m_dc;
	HBITMAP		m_hBit;
	BITMAP		m_bitInfo;

private: // 우리가 자체적으로 동적할당 불가능하게 private으로 함
	CTexture();
	~CTexture();

	friend class CResMgr;

public:
	void Load(const wstring& _strFilePath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Height() { return m_bitInfo.bmHeight; }

	HDC GetDC() { return m_dc; }

};

