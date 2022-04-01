#pragma once



/*
��ũ���Լ��� �Լ�ó�� ���۸� �ϴ°��� ����� �ڵ尡 ġȯ�Ǵ°�

	#define ADD(a, b) a + b
	int i = ADD(10, 10) 
*/


// static���� �޾� �ʱ�ȭ�� �� ���� ����
// static���� �޾ұ� ������ mgr�� ������ ������ mgr�� return �׷��� ������ ��ݸ��� mgr return

#define SINGLE(type) public:\
						 static type* GetInst() \
						{\
							static type mgr;\
							return &mgr;\
						}\
					private:\
						type();\
						~type();


#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT CTimeMgr::GetInst()->GetDT()

#define KEY_CHECK(key, state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)


#define PI 3.14159265385

//#define OBJUPDATE() for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)\
//					{\
//						for (size_t j = 0; j < m_arrObj[i].size(); ++j)\
//						{\
//							m_arrObj[i][j]->update();\
//						}\
//					}\


// Scene�� ����ִ� Object���� �з��ϴ� �۾�
enum class GROUP_TYPE
{
	DEFAULT,

	PLAYER,

	MISSILE,

	MONSTER,



	END = 32,
};


enum class SCENE_TYPE
{
	TOOL, // ���� ����� ��
	START,
	STAGE_01,
	STAGE_02,



	END,
};

enum class MISSILE_TYPE
{
	DEFAULT, // ����
	ZIGJAG, // �������
	

	MONSTER_DEFAULT, // ���� ����
	END,
};


enum class BRUSH_TYPE
{
	HOLLOW,
	END,

};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,

	END,
};