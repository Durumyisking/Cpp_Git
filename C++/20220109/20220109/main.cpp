#include <iostream>


using namespace std;


int main()
{
	// ������ ����
	// �ּҸ� �����ϴ� ����
	int* pInt = nullptr; // �ƹ��͵� ����Ű�� ���� �ʴ�.
	

	int num = 100;
	int* pnum = &num;


	/*�ּҰ��� �����ϰڴ�*/ *pnum = 5;
	// �ּ��� �ּ� ������ ����Ʈ
	// in 32bit = 4byte (86x)
	// in 64bit = 8byte
	
	int i =  100;
	float f = 3.f;

	int* p_i = (int*)&f;
	// �̷��� �ϸ� �Ǽ� �ּ� ���� �ȿ� �ִ� ���� ���� ������� �ؼ���

	i = *pInt;


	// �����Ϳ� �迭
	// �迭�� Ư¡
	// 1. �޸𸮰� �������� ����
	// 2. �迭�� �̸��� �迭�� �����ּ�

	int iArr[10] = {};

	*(iArr + 4) = 123; // �̸��� �迭 �����ּҿ��� 16����Ʈ ���� �ε������� ����

	// 29��
	
	// 1������
	short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *pI = (int*)sArr;
	int iData = *((short*)(pI + 2));
	cout << "1�� ���� ���� : " << iData << endl;


	// 5

	// 2������
	char cArr[2] = { 1, 1 };
	short * pS = (short*)cArr;
	iData = *pS;
	cout << "1�� ���� ���� : " << iData << endl;

	// 257


	return 0;
}