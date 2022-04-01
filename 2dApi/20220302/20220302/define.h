#pragma once



/*
매크로함수는 함수처럼 동작만 하는거지 사실은 코드가 치환되는것

	#define ADD(a, b) a + b
	int i = ADD(10, 10) 
*/


// static으로 받아 초기화를 한 번만 진행
// static으로 받았기 때문에 mgr이 있으면 기존의 mgr을 return 그렇지 않으면 방금만든 mgr return

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


// Scene에 들어있는 Object들을 분류하는 작업
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
	TOOL, // 게임 만드는 씬
	START,
	STAGE_01,
	STAGE_02,



	END,
};

enum class MISSILE_TYPE
{
	DEFAULT, // 직선
	ZIGJAG, // 지그재그
	

	MONSTER_DEFAULT, // 몬스터 직선
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