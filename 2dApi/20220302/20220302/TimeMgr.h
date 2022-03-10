#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);


private:
	// �̵��ϰ������ X 1�����Ӵ� �ð�(��) = 1�����Ӵ� �̵��ϴ� ��
	
	// QueryPerformanceCounter() �� �������� ������ �鸸 ������
	// Count�� ������ ������ LARGE_INTEGER ���
	LARGE_INTEGER	m_llCurCount; // ���� �ķκ��� ���� cpu�� ƽ�� ��ȯ
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFrequency; // ���� ���� ī����, Ÿ�̸��� ���ļ�

	double			m_dDeltaTime; // ������ ���� �ð���
	double			m_dAcc;		  // ����
	UINT			m_iCallCount; // �ʴ� ȣ�� Ƚ��
	UINT			m_iFPS;


	// FPS
	// 1. �����Ӵ� �ð� (Delta Time)

public:
	void init();
	void update();

public:
	double GetDT() { return m_dDeltaTime; }
	float GetfDT() { return (float)m_dDeltaTime; }
	
};

