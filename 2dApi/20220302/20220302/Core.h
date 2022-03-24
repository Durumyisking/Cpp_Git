#pragma once

class CCore
{

	/*
		public:

			static CCore* GetInst()
			{


				static CCore core;

				return &core;
			}
	*/
	SINGLE(CCore);

private:
	HWND	m_hWnd;
	Vec2	m_vResolution;
	HDC		m_hDC;

	HBITMAP m_hBit; // 사본용 비트맵 (BITMAP : 화면을 구성하는 픽셀들을 전부 묶어서 비트맵이라 부름)
	HDC		m_memDC; // 사본용 DC


public:
	int init(HWND _hWnd, Vec2 _vResolution);
	void progress();


public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	Vec2 GetResolution() { return m_vResolution; }

};