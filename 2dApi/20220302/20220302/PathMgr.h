#pragma once


class CPathMgr
{
	SINGLE(CPathMgr);

private:
	wchar_t		m_szContentPath[255]; // ���� ��δ� 255���� ������

public:
	void init();
	void update();

	const wchar_t* GetContentPath() { return m_szContentPath; }

};

