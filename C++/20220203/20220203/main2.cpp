#include <iostream>

class CTest
{

public:
	int m_i;

public:
	CTest()
		: m_i(0)
	{

	}
	/*
	���������
	�ȸ�����ָ� �����Ϸ����� �ڵ� ��������
	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{

	}
	*/

};


int main()
{


	CTest t1;
	t1.m_i = 100;

	/*
	CTest t2;
	t2 = t1;
	�̷��� �ص� ������
	*/
	CTest t2(t1); // �̷���  ��������ڸ� ����ϸ� �����ϴ� ���ÿ� t1�� ������

	CTest t3 = t1;	// �����δ� t3�� �����ϸ鼭 t1�� �ִ� �� ������
					// ���� �� t1�� �����ϴ°�
					// �׷��� �����Ϸ� ��ü���� ������ �ڵ带 �ۼ�������
					// �ڵ������Ǵ� ���� �����ڸ� ȣ������

	std::cout << t1.m_i << " " << t2.m_i << " " << t3.m_i << std::endl;


	


	return 0;
}