#include <iostream>
#include <stdio.h>
#include "main5.h"

// ����ü
// ����ü�� ����� ���� �ڷ���
typedef struct _tagMyST
// ���� c���� �տ� typedef �Ⱥ��̸� main���� �����Ҷ� intó�� struct ����ü�� ������ �̷��� �ؾߴ�
{
	int		inum;
	float	fnum;
}MYST; // ���� (�տ� typedef�� ����� ������ ���� ������ �� �ִ°�


typedef struct _tagBig
{
	MYST	myst; // ����ü �ӿ� ����ü �԰���
	int		i;
	char	c;

}BIG; // ����

typedef int INT; // �̷��� �ϸ� int�� ������ INT�� �����ذ�

using namespace std;

int main()
{

	// �迭

	// ����
	int arr[10] = {}; // �̷��� ���� 0���� �ʱ�ȭ
	
	// �迭 ���� �ε����� ���� ������ ����Ǿ��ִ� �ٸ� ������ ��� �� �� ����


	MYST t; // ����ü�� ���� ����
	BIG b = {100, 3.14}; // �ʱ�ȭ ����!

	
	// ��Ī�Ϸ��� .��
	t.inum = 15;
	t.fnum = 20.33;

	b.myst.inum = 123;

	Add(123, 456); // main5.cpp�� include ���� �ʾ����� �˾Ƽ� ��ũ�Ǿ� main5.cpp�� Add�� ����Ѵ�.


	return 0;
}