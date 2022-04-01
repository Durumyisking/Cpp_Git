#pragma once

class CCollider;

class CObject
{

private:
	wstring		m_strName;

	Vec2		m_vPos;
	Vec2		m_vScale;

	CCollider*	m_pCollider; // �浹ü �ʿ��ϸ� �� ������ ������ �Ȱ����� �Ǵ� ��

public:
	CObject();
	virtual ~CObject();

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	CCollider* GetCollider() { return m_pCollider; }
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }
	wstring GetName() { return m_strName; }

	void CreateCollider();

public:
	virtual void update() = 0;

	// finalupdate�� ������Ʈ������ ó�� �� ���̱� ������ �������̵� ���ϰ� �ؾߴ�
	// scene���� �����ϴ� object* ��ü�� �� �Լ��� ����ؼ� ������ �ڽ� �����Ͱ� �ƴ϶�
	// �θ��� obj �����Ͱ� ȣ��Ǵµ� �׷��� �Ǽ� ��������
	virtual void finalupdate() final;	// ���� final ���� �������̵� �ȴ�
										// ��� �ڽĵ��� �� finalupdate�� ����ϰ� �Ǿ�����
	virtual void render(HDC _dc);


	virtual void OnCollision(CCollider* _pOther) {};
	virtual void OnCollisionEnter(CCollider* _pOther) {};
	virtual void OnCollisionExit(CCollider* _pOther) {};

	void component_render(HDC _dc);
};

