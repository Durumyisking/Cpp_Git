#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"


CTimeMgr::CTimeMgr()
	: m_llCurCount{} // union이라서 {} 초기화
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDeltaTime(0.)
	, m_dAcc(0.)
	, m_iCallCount(0)
{

}


CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);

	// 1초가 벌어졌을때 count가 얼마나 차이나는지 구해와야함

	// 초당 카운트가 얼마나 일어나는지 횟수
	QueryPerformanceFrequency(&m_llFrequency);



}

void CTimeMgr::update()
{
	// 매 업데이트마다 한 프레임마다 걸린 시간을 가져올것
	QueryPerformanceCounter(&m_llCurCount);


	// 업데이트는 매 프레임마다 하니까 저번 업데이트와
	// 이번 업데이트때 나온 시간을 차를 계산하면 1프레임당 걸린 시간이 나옴
	// 1프레임 이동시 걸리는 틱 = 한 프레임당 걸리는 틱 / 초당 틱이 얼마나 증가하는지
	m_dDeltaTime = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;
	// QuadPard = Large_Integer 내의 LongLong타입 자료형
	
	++m_iCallCount; // 함수 호출 횟수

	m_dAcc += m_dDeltaTime;

	// 이렇게 나온 deltatime 을 역수하면 fps
	// 그런데 이렇게 구한 fps는 불안정함 deltatime은 너무 미세해서 측정마다 fps에서 차이가 날 것
	// 그래서 1초동안 매 프레임마다 호출되는 이 update함수가 몇번 호출되는지 체크하는게 좋음
	if (m_dAcc >= 1.) // 1초가 되면 진입
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;
		m_dAcc = 0.;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %F", m_iFPS, m_dDeltaTime);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}



	m_llPrevCount = m_llCurCount; // 차이값 계산 후 다시 이전 카운트 갱신

}


// fps가 100이다 = 매 수행때 1씩 처리하면 100을 처리했을때 1이다
// 매 순간 처리량 = 1초당 처리하고싶은 수행량 / 초당 처리량
// 매 순간 보여줄 종이 수 = 1초동안 보여주고싶은 장면 * cpu에서 1프레임당 걸리는 실제 시간
// 즉 한 프레임에 걸리는 시간 만큼만 전체 양에서 처리하겠다는 것