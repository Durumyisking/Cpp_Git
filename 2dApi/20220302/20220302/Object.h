#pragma once
class CObject
{

private:
	Vec2	m_vPos;
	Vec2	m_vSclae;

public:
	CObject();
	~CObject();

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vSclae = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vSclae; }

};

