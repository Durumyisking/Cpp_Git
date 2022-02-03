#include <iostream>
#include "TemplateArr.h"



void MyEndL()
{
	wprintf(L"\n");
}


// �׻� std::cin �ϱ� �������� �̷��� �ϸ�ȴ�.
// using namespace std;
// �׷��� �̷��� ���ָ� namespace�� ������ִ� ������ ������
// MYSPACE�� NEWSPACE �� g_int�� ��ȣ�����ݾ�
// �׷��� ���� ����ϴ� ��ɵ鸸 �����ü� ����

using std::cout;
using std::cin;
using std::endl;
// ����ڷ� �ϸ� namespace�� �Ϻ� ��ɵ鸸 ���� ��밡��

// �̷����ϸ� �츮�� std::cout �ϵ�
// MYSPACE::g_int ���ټ�����
namespace MYSPACE
{
	int g_int;
}

// ���� ������ �ߺ� ��������� 
// �ٸ� namespace�� ����� �ȴ�.
namespace NEWSPACE
{
	int g_int;
}

class CTest
{
private:
	int a;

public:
	CTest()
		:a(10)
	{

	}


};

class TestClass; // Ŭ������ ����� �ƹ� ����� ���� ������ 1byte �Ҵ�

class CMyOStream
{
public:
	CMyOStream& operator << (int _idata)
	{
		printf("%d", _idata);
		return *this;
	}

	// �Լ� �����ε�� ���� ������� ��� ����
	CMyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}

	CMyOStream& operator << (void(*_pFunc)(void)) // �Լ� �����͸� �޾ƿͼ� MyEndL ȣ��
	{
		_pFunc();
		return *this;
	}

	CMyOStream& operator >> (int& _iData)
	{
		scanf("%d", &_iData);
		return *this;
	}


};


/*
int Add(int a, int b)
{
	return a + b;
}

float Add(float fa, float fb)
{
	return fa + fb;
}
*/
// �Լ� ���ø�
// �Լ��� ���� Ʋ
// typename �ڸ��� ��� ���� ��û ������ �Լ��� ������
// �̷��� �����س��Ƶ� �Լ��� �޸𸮿� ���°�

template <typename T> // ���� T �ڸ��� ���ϴ� �ڷ������� �������ټ� ����
T Add(T a, T b)
{
	return a + b;
}




int main()
{

	// ���ø����� ����� �Լ� ȣ��
	int i = Add<int>(10, 20);
	int f = Add<int>(10.0, 20.0);

	int i2 = Add(10, 20); // �̷��� �ϸ� �Է����� �־��ִ� �� �����Ͱ� int�� ���� �޴¾ֵ� int�ϱ� ���ø� �Լ����� ��ȯŸ���� int�� �˾Ƽ� ��Ī
	// �ٵ� �̷��� �ϸ� �Ϲ��Լ��� �� ������ �Լ� ���ø��� �� ������ ��


	CTemplateArr<int> int_arr;
	CTemplateArr<float> float_arr;

	for (int i = 0; i < 10; ++i)
	{
		int_arr.PushBack(i);
		float_arr.PushBack(i);
	}

	MYSPACE::g_int = 0;

	CMyOStream mycout;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	mycout << 10 << 30 << 50 << MyEndL;
	mycout << L"�ѱ�" << MyEndL;
	// cout�� ����
	// cout ��ü�� �Լ� <<, <<�� ���ڷ� 10�� �޾Ƽ�
	// << �Լ��� ó���� �� �ڱ� �ڽ� �����͸� return
	// �ٽ� return�� �ڱ� �ڽ����� cout << 30ó��
	// �� �� cout << 50ó��

	int a = 0;
	mycout >> a;

	return 0;

}