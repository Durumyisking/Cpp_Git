#pragma once

#include "Object.h"
#include "Texture.h"

class CObject;	// ���漱���̶� ���� �̰� �츮�� CObject���� ��
				// ���� ����� �����ϸ� CObject���� �ڵ尡 ����Ǹ�
				// ���� Ŭ������ �ڵ嵵 �Ź� Ȯ��������ؼ� �������� �����ɸ�
				// �� Ŭ���������� Object�� �ִ°� �˱⸸ �ϸ� �����Ƽ�
				// �� Ÿ�Կ� ���� ������ �޾ƿ����� �����ͷθ� ����


			
class CScene
{


protected:
	// ��� OBject Ŭ������ �θ� Ŭ�����ν� ��� �ڽ� Ŭ������ �����͸� ���� �� ����
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END]; // Obj �׷��� ���� ���͸� �迭�� ����
	wstring				m_strName; // Scene�̸�

	float				m_fTimeCount;
	CTexture*			m_pTex;

public:
	CScene();
	virtual ~CScene();


public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	// ������ ������ ������ �ջ��� �Ȱ��� const ����
	const vector <CObject*>& GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }


	// ��� Scene�� ���� update�� render�� �����ϱ� ���� virtual �Ⱦ�
	void update();
	void finalupdate(); // update�Ȱ��� ������ �� Ȯ�������ִ� �Լ�

	virtual void render(HDC _dc);



public:
	virtual void Enter() = 0;	// �ش� Scene�� ���Խ� ȣ��

								// �츮�� Scene���� ����� ���� �� ���� ����
								// ���� start�� ���� ���� �Լ��� �����
								// �θ� �߻�ȭ���� ��ü ���� �Ұ����ϰ� ����
								// �� �ڽ� Ŭ�������� Start�� ���� ���س����� ��üȭ �� �� ����
						 		// ���� �����Լ��� ���� 2������

	virtual void Exit() = 0;	// �ش� Scene�� Ż��� ȣ��


	virtual void StageEvent() = 0;



public:
	void AddObject(CObject* _Obj, GROUP_TYPE _eType)
	{
		// ������ protected�ص� ������ �Ǽ��� �����ϱ�����
		// protected �Լ��� ���� ó�� ==> �ٽ� �÷��̾�� �̻����� ������� public���� �ٲ�
		// Ư�� ���ʿ��� �Լ��� ������̴� inline�Լ��� ���� ȣ���� ����
		m_arrObj[(UINT)_eType].push_back(_Obj);
	}

};
