#pragma once



/*
매크로함수는 함수처럼 동작만 하는거지 사실은 코드가 치환되는것

	#define ADD(a, b) a + b
	int i = ADD(10, 10) 
*/



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
