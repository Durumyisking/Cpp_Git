#pragma once



/*
��ũ���Լ��� �Լ�ó�� ���۸� �ϴ°��� ����� �ڵ尡 ġȯ�Ǵ°�

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
