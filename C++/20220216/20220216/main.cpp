#include "Tree.h"

#include <map>
#include <set>
#include <string>

using std::wstring;

using std::wcout;
using std::cout;
using std::endl;
using std::set; // set�� �� �Ⱦ�
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

	//map<int, float> mapData;	// map<key��, datatype>
								// ������ key ���� �������� ���ĵ�
								// ������� map<�л��̸�, �л�����>
								// �л��̸��� �������� ���� �� Ž��
								// map�� �� ���� �ڷ� �����ϱ� ����


	map<const wchar_t*, tStdInfo> mapData;
	


	tStdInfo info(L"ȫ�浿", 20, sex::MAN);
	tStdInfo info2(L"������", 20, sex::WOMAN);

	// make_pair : ���� 2���� ��� map�� �־���
	// pair ��� ����ü�� return ����
	// struct pair { T first, T second } ��� ����Ǿ�����
	mapData.insert(make_pair(L"ȫ�浿", info));
	mapData.insert(make_pair(L"������", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"ȫ�浿");
	// const wchar_t* �� ���ϴ� ���̱� ������ �ּҰ��� ���ϴ°��� ���ڿ��� ���ϴ°� �ƴϴ�
	// find�δ� ROM�� ȫ�浿�̶� ���ڸ� ã�ư��� �� 
	// ���� str = L"ȫ�浿" �� �ؼ� str�� find�ϸ� �ٸ� �ּұ� ������ ������ ���´�


	// mapiter = mapData.find(L"���"); 
	// ã�� �����Ͱ� ��� ġ������ ������ �ƴ�
	// ã�� �����Ͱ� ������ end iterator�� ��ȯ��

	if (mapiter == mapData.end())
	{
		wcout << L"�����͸� ��ã�ھ��" << endl;
	}
	else
	{
		wcout << L"�̸� :" << mapiter->second.szName << endl;
		wcout << L"���� :" << mapiter->second.age << endl;
		wcout << L"���� :" ;
		if (sex::MAN == mapiter->second.gender)
			wcout << L"����" << endl;
		else if (sex::WOMAN == mapiter->second.gender)
			wcout << L"����" << endl;
		else
			wcout << L"�� �� ����" << endl;
	}
									
	// find�� �̷��� ã�Ƽ� mapData�� ȫ�浿�� �����ϸ�
	// pair(ȫ�浿, info)�� iterator�� ������

	// (*mapiter).first;
	// (*mapiter).second;
	
	// mapiter->first;		// �����Ͱ� �ƴϿ��� ������ �����ε��� �Ǿ��־ ����
	// mapiter->second;


	map<wstring, tStdInfo> mapStdInfo; // �̷��� �ؾ��� ��¥ ���ڿ� ��ü�� ����
	wstring str; // �����迭�� ����

	str = L"abcdef";
	str += L"hijk";  // �̷��� �̾� ���̱⵵ ����


	// �츮��

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