#include "pch.h"
#include "TimeMgr.h"
#include "Core.h"


CTimeMgr::CTimeMgr()
	: m_llCurCount{} 
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
	
	QueryPerformanceCounter(&m_llPrevCount);

	

	
	QueryPerformanceFrequency(&m_llFrequency);



}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);


	m_dDeltaTime = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;
	
	++m_iCallCount; 

	m_dAcc += m_dDeltaTime;

	
	
	
	if (m_dAcc >= 1.) 
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;
		m_dAcc = 0.;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %F", m_iFPS, m_dDeltaTime);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);
	}



	m_llPrevCount = m_llCurCount; 

}






