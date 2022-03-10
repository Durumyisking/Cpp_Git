#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);


private:
	// 이동하고싶은양 X 1프레임당 시간(초) = 1프레임당 이동하는 양
	
	// QueryPerformanceCounter() 로 가져오는 단위가 백만 단위라서
	// Count를 저장할 값으로 LARGE_INTEGER 사용
	LARGE_INTEGER	m_llCurCount; // 부팅 후로부터 현재 cpu의 틱값 반환
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFrequency; // 현재 성능 카운터, 타이머의 주파수

	double			m_dDeltaTime; // 프레임 간의 시간값
	double			m_dAcc;		  // 누적
	UINT			m_iCallCount; // 초당 호출 횟수
	UINT			m_iFPS;


	// FPS
	// 1. 프레임당 시간 (Delta Time)

public:
	void init();
	void update();

public:
	double GetDT() { return m_dDeltaTime; }
	float GetfDT() { return (float)m_dDeltaTime; }
	
};

