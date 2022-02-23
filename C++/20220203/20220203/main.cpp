#include <vector>
#include <list>

#include "Arr.h"


// vector, list �� �� std �ȿ� ����
using namespace std;


int main()
{
	vector<int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	vecInt[0] = 100;
	vecInt.at(1); // =vecInt[1];
	vecInt.data(); // �迭�� ���� �ּ�
	vecInt.size(); // ���� �迭�� � ����ִ���
	vecInt.capacity(); // �迭 ��ü ũ��

	for (size_t i = 0; i<vecInt.size(); ++i)
	{
		// ���ʹ� �̷��� ��ȸ�ϸ� ������
		// ����Ʈ�� �Ұ�����
		//cout << vecInt.at(i) << endl;
	}
	vector<int>::iterator veciter = vecInt.begin();
	*veciter = 100;
	++veciter;
	vecInt.erase(veciter); // �迭�� �߰��� �����ϰ� �迭 �� �κе��� ������ ��ܿ��� �۾� ����



	list<int> listInt;

	listInt.push_back(10);
	listInt.push_back(100);
	listInt.push_back(1000);
	 
	listInt.size();

	// iterator (inner class : ����/���� Ŭ����) list �ȿ� �����Ǿ��ִ� Ŭ����
	list<int>::iterator iter = listInt.begin(); // iter�� listInt�� ù��° ��带 ����Ŵ
	int iData = *iter; // operator *�� iterator�� ����Ű�� �ִ� ������� data�� �̾ư�
	++iter; // �̷��� iter�� index 0�� �ƴ϶� 1����Ŵ
	iData = *iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) // list.end()�� ������ �������� ���� �ε��� �׷��� for�� ��ȸ ����
	{
		//cout << *iter << endl;
	}


	CArr<int> myArr;

	myArr.Push_back(10);
	myArr.Push_back(20);
	myArr.Push_back(30);
	myArr.Push_back(40);
	myArr.Push_back(50);

	CArr<int>::iterator myiter = myArr.begin();

	// myArr.erase(myiter);	// iterator�� ����Ű�� �κ��� �����ϴ� ���̱� ������
							// cout<<myiter ���� �ٷ� ����� �� ����
							// �ֳ��ϸ� myArr������ 10�� ������� 20~ 50�� ��ܿ°� ������
							// myiter�� ����Ű�� �κ��� ������ ���̱� ���� ����
	myiter = myArr.erase(myiter);	// �̷��� �ٽ� iterator �־���ߴ� (erase �Լ��� �Ű������� iterator�� ����Ű�� idx�� ������ ��
									// ������ �κ��� �޺κ��� ��ܿ´��� ���� ����Ű�� �ִ� idx�� ����Ű�� iterator�� ��ȯ��


	


	/*
	for (; myiter != myArr.end(); ++myiter)
	{
		cout << *myiter << endl;
	}
	*/



	return 0;
}