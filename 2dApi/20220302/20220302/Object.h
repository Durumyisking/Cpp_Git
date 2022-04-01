#pragma once

class CCollider;

class CObject
{

private:
	wstring		m_strName;

	Vec2		m_vPos;
	Vec2		m_vScale;

	CCollider*	m_pCollider; // 충돌체 필요하면 얘 가지고 없으면 안가지면 되는 것

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

	// finalupdate는 오브젝트에서만 처리 할 것이기 때문에 오버라이딩 못하게 해야댐
	// scene에서 관리하는 object* 객체가 이 함수를 사용해서 어차피 자식 포인터가 아니라
	// 부모인 obj 포인터가 호출되는데 그래도 실수 막기위해
	virtual void finalupdate() final;	// 끝에 final 쓰면 오버라이딩 안댐
										// 모든 자식들은 이 finalupdate를 사용하게 되어있음
	virtual void render(HDC _dc);


	virtual void OnCollision(CCollider* _pOther) {};
	virtual void OnCollisionEnter(CCollider* _pOther) {};
	virtual void OnCollisionExit(CCollider* _pOther) {};

	void component_render(HDC _dc);
};

