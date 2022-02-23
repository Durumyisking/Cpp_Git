#include <vector>
#include <list>

#include "Arr.h"


// vector, list 둘 다 std 안에 있음
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
	vecInt.data(); // 배열의 시작 주소
	vecInt.size(); // 현재 배열에 몇개 들어있는지
	vecInt.capacity(); // 배열 전체 크기

	for (size_t i = 0; i<vecInt.size(); ++i)
	{
		// 벡터는 이렇게 순회하면 되지면
		// 리스트는 불가능함
		//cout << vecInt.at(i) << endl;
	}
	vector<int>::iterator veciter = vecInt.begin();
	*veciter = 100;
	++veciter;
	vecInt.erase(veciter); // 배열의 중간을 삭제하고 배열 뒷 부분들을 앞으로 당겨오는 작업 해줌



	list<int> listInt;

	listInt.push_back(10);
	listInt.push_back(100);
	listInt.push_back(1000);
	 
	listInt.size();

	// iterator (inner class : 내부/포함 클래스) list 안에 구현되어있는 클래스
	list<int>::iterator iter = listInt.begin(); // iter은 listInt의 첫번째 노드를 가리킴
	int iData = *iter; // operator *은 iterator가 가리키고 있는 노드쪽의 data만 뽑아감
	++iter; // 이러면 iter이 index 0이 아니라 1가리킴
	iData = *iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) // list.end()는 마지막 데이터의 다음 인덱스 그래서 for문 순회 가능
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

	// myArr.erase(myiter);	// iterator가 가리키는 부분을 제거하는 것이기 때문에
							// cout<<myiter 같이 바로 사용할 수 없음
							// 왜냐하면 myArr에서는 10이 사라지고 20~ 50을 당겨온게 맞지만
							// myiter은 가리키는 부분이 없어진 것이기 때문 따라서
	myiter = myArr.erase(myiter);	// 이렇게 다시 iterator 넣어줘야댐 (erase 함수는 매개변수의 iterator가 가리키는 idx를 삭제한 후
									// 삭제한 부분의 뒷부분을 당겨온다음 전에 가리키고 있던 idx를 가리키는 iterator를 반환함


	


	/*
	for (; myiter != myArr.end(); ++myiter)
	{
		cout << *myiter << endl;
	}
	*/



	return 0;
}