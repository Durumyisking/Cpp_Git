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


void CTexture::Load(const wstring & _strFilePath) // ������ ��ο��� �������� ��ΰ��� ��
{
	/*
		LoadImage(Hinstance, �̹��� ���, �̹��� Ÿ��
			, ���α���, ���α���, �̹��� �ε� �ɼ�
	*/

	// ������ �� ���� �� �̹����� ���� ���θ� �־�� �ϴµ� 
	// �̹����� �̹������� �� �ٸ� ũ�⸦ ������ ������ ���⼭ ��������
	// ���� default�� 0�� �ִ´�
	
	//wchar_t szBuffer[255] = {};
	//swprintf_s(szBuffer, L"FPS : %d, DT : %F", m_iFPS, m_dDeltaTime);
	//SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);

	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP ,0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit); // �̹��� �ε� ���н�

	// ��Ʈ���� ����� ���� DC ����
	m_dc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit); // �����ִ� ������ bitmap ����

	// ���� ���� ����
	// BITMAP : ��Ʈ���� ���� �����带 �����ϴ� ����ü
	
	// GetObject() : Ư�� OBJ���� ������ �˷��ִ� �Լ�, �̶� �ڵ�� �־��ִ°� �츮�� ��Ʈ��
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);



}
