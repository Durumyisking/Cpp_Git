#include <iostream>


using namespace std;


typedef struct _tagMYST
{
	int		i; // ��׵��� ������ �ƴ϶� ������ �θ�
	float	f; // ������ �ؼ� ��ü�� �������� ������ ��
}MYST;


int main()

{

	// ����ü�� ������
	MYST s = {};
	MYST* ps = &s; // 8����Ʈ¥��

	(*ps).i = 100; // ����ü s�� i����� 100 �����ž�
	(*ps).f = 3.14;
	ps->f = 6.28; // �������� �Ȱ���


	return 0;
}