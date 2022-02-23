#include "Tree.h"

#include <map>
#include <set>
#include <string>

using std::wstring;

using std::wcout;
using std::cout;
using std::endl;
using std::set; // set은 잘 안씀
using std::map;
using std::make_pair;


enum class MY_TYPE
{
	TYPE_1,
	TYPE_2,
	TYPE_3,
	TYPE_4 = 100,
	TYPE_5 // 101
};

enum class sex
{
	DEFAULT,
	MAN,
	WOMAN
};


struct tStdInfo
{
	wchar_t			szName[20];
	unsigned char	age;
	sex		gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(sex::DEFAULT)
	{

	}

	tStdInfo(const wchar_t* _pName, unsigned char _age, sex _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);

	}

};


int main()
{
	_wsetlocale(LC_ALL, L"korean");

	set<int> setInt;

	setInt.insert(100);	// root
	setInt.insert(50);	// left
	setInt.insert(150);	// right

	//map<int, float> mapData;	// map<key값, datatype>
								// 정렬은 key 값을 기준으로 정렬됨
								// 예를들어 map<학생이름, 학생정보>
								// 학생이름을 기준으로 정렬 및 탐색
								// map이 더 여러 자료 저장하기 적합


	map<const wchar_t*, tStdInfo> mapData;
	


	tStdInfo info(L"홍길동", 20, sex::MAN);
	tStdInfo info2(L"이지혜", 20, sex::WOMAN);

	// make_pair : 인자 2개를 묶어서 map에 넣어줌
	// pair 라는 구조체로 return 해줌
	// struct pair { T first, T second } 라고 저장되어있음
	mapData.insert(make_pair(L"홍길동", info));
	mapData.insert(make_pair(L"이지혜", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"홍길동");
	// const wchar_t* 를 비교하는 것이기 때문에 주소값을 비교하는거지 문자열을 비교하는게 아니다
	// find로는 ROM의 홍길동이란 글자를 찾아가는 것 
	// 따라서 str = L"홍길동" 을 해서 str을 find하면 다른 주소기 때문에 오류가 나온다


	// mapiter = mapData.find(L"김상동"); 
	// 찾는 데이터가 없어도 치명적인 에러는 아님
	// 찾는 데이터가 없을때 end iterator를 반환함

	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 못찾겠어요" << endl;
	}
	else
	{
		wcout << L"이름 :" << mapiter->second.szName << endl;
		wcout << L"나이 :" << mapiter->second.age << endl;
		wcout << L"성별 :" ;
		if (sex::MAN == mapiter->second.gender)
			wcout << L"남자" << endl;
		else if (sex::WOMAN == mapiter->second.gender)
			wcout << L"여자" << endl;
		else
			wcout << L"알 수 없음" << endl;
	}
									
	// find는 이렇게 찾아서 mapData에 홍길동이 존재하면
	// pair(홍길동, info)를 iterator로 가져옴

	// (*mapiter).first;
	// (*mapiter).second;
	
	// mapiter->first;		// 포인터가 아니여도 연산자 오버로딩이 되어있어서 가능
	// mapiter->second;


	map<wstring, tStdInfo> mapStdInfo; // 이렇게 해야지 진짜 문자열 자체를 비교함
	wstring str; // 가변배열과 유사

	str = L"abcdef";
	str += L"hijk";  // 이렇게 이어 붙이기도 가능


	// 우리꺼

	CTree<int, int> bstint;

	bstint.insert(make_bstPair(100, 0));	//				100
	bstint.insert(make_bstPair(150, 0));	//		50				150
	bstint.insert(make_bstPair(50, 0));		//	25		75		125		175
	bstint.insert(make_bstPair(25, 0));
	bstint.insert(make_bstPair(75, 0));
	bstint.insert(make_bstPair(125, 0));
	bstint.insert(make_bstPair(175, 0));

	CTree<int, int>::iterator iter = bstint.begin();
	++iter;


	// iter = bstint.find(150);

	// (*iter).first == iter->first
	
	wcout << bstint.GetInOrderSuccessor(iter.m_pNode)->pair.first << endl;
	wcout << bstint.GetInOrderPreSuccessor(iter.m_pNode)->pair.first <<endl;


	for (iter = bstint.begin(); iter != bstint.end(); ++iter)
	{
		wcout << iter->first << endl;
	}
	


	return 0;
}