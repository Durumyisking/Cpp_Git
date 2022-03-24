#include "pch.h"
#include "Texture.h"

#include "Core.h"

CTexture::CTexture()
	: m_dc(0)
	, m_hBit(0)
	, m_bitInfo{}
{
}


CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}


void CTexture::Load(const wstring & _strFilePath) // 인자의 경로에는 최종적인 경로값이 들어감
{
	/*
		LoadImage(Hinstance, 이미지 경로, 이미지 타입
			, 가로길이, 세로길이, 이미지 로딩 옵션
	*/

	// 마지막 두 인자 에 이미지의 가로 세로를 넣어야 하는데 
	// 이미지는 이미지마다 다 다른 크기를 가지기 때문에 여기서 지정안함
	// 따라서 default인 0을 넣는다
	
	//wchar_t szBuffer[255] = {};
	//swprintf_s(szBuffer, L"FPS : %d, DT : %F", m_iFPS, m_dDeltaTime);
	//SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);

	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP ,0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit); // 이미지 로딩 실패시

	// 비트맵을 띄워줄 작은 DC 생성
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit); // 남아있던 이전의 bitmap 제거

	// 가로 세로 길이
	// BITMAP : 비트맵의 각종 정보드를 저장하는 구조체
	
	// GetObject() : 특정 OBJ들의 정보를 알려주는 함수, 이때 핸들로 넣어주는게 우리의 비트맵
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);



}
