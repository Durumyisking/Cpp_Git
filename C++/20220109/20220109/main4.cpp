#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <assert.h> // ���߻��ϰ��ϴ� �Լ� ����

using namespace std;

// �츮 ���ڿ� ���̸� ����ϴ� wsclen�� �����ƿ�

int c_wcslen(const wchar_t* _String)
{
	int iCount = 0;
	while (NULL != _String[iCount]) { ++iCount;}
	// ���ǹ� ���Ҷ� ����� ���ʿ� �ּ� �Ǽ��� =�� ��������
	// �����߰� �ϴ� ������ �⸨�ô�^^
	return iCount;
}

// �츮 ���ڿ��� �̾� ���̴� wcscat_s�� �����ƿ�
void c_wcscat_s(wchar_t* _pDest, unsigned int _iBufSize, const wchar_t* _pSrc)
{
	// pdest + psrc���� ibufsize�� ������ ���� ���� assertȣ��
	// pdest�� psrc ���ĵ� ���� ���°� Ȯ�� �����ϱ�
	// pdest �����ٰ� psrc ���̱�
	

	int pDestlen = c_wcslen(_pDest);
	int pSrclen = c_wcslen(_pSrc);

	if (_iBufSize < pDestlen + pSrclen + 1)
		assert(nullptr); // ��ũ���Լ� ��� ȣ��
	
	
	for(int i=0; i<pSrclen; ++i)
		_pDest[pDestlen + i] = _pSrc[i];

}

int c_wcscmp(const wchar_t* _pStr1, const wchar_t* _pStr2)
{
	int minstr = min(c_wcslen(_pStr1), c_wcslen(_pStr2));

	for (int i = 0; i < minstr; ++i)
	{
		if (_pStr1[i] < _pStr2[i])
			return -1;
		else if (_pStr1[i] > _pStr2[i])
			return 1;
	}

	if (c_wcslen(_pStr1) < c_wcslen(_pStr2))
		return -1;
	else if
		(c_wcslen(_pStr1) > c_wcslen(_pStr2))
		return 1;
	
	return 0;
}


int main()
{
	// ���ڿ�
	char c = 'a';
	wchar_t wc = L'a'; 

	cout << c << endl;
	cout << wc << endl;


	// �̷� �迭 �ʱ�ȭ�� ���� �ڷ����� ����
	char szChar[10] = "abcdef";

	wchar_t szWChar[10] = L"abcdef"; // == {97, 98, ... 102};
	// �� ģ���� ���ÿ� szWChar�� �޸𸮰� ������ ���⿡ abcdef�� ä�����°�
	
	// �ڵ念��
	const wchar_t* pChar = L"abcdef"; // ���ڿ� �����ּ� �޾ƿ�
	// �� ģ���� ���ÿ� pChar��� �ּ� ������ �����
	// �ڵ� ������ �ִ� abcdef�� ���� �ּҸ� �ذ�
	// �����ִ� abcdef�� ���ó�� ��ɾ� ��ü�� �����Ͱ� ���ִ°�
	// �����ִ� ���ڿ��� �����Ѵٴ°��� ����� �����Ѵٴ°�
	// �� �ǽð����� �ڵ带 �ٲ۴ٴ°���
	// �׷��⶧���� ���� ����� �ٲ� �� ���� const wchar_t* �ιۿ� ���� ���ϴ°�
	// ����
	// pChar[1] = 'z'; �� �ڵ�� ������
	szWChar[1] = 'z'; // �̰Ŷ� �ٸ� �̰� �ڵ念���� �ִ� ���� ���ÿ� �����ؼ� ������

	// �ϰ� ���̱��� �迭ó�� �����ؼ� ���������
	// pChar = (wchar_t*) "abcdef";
	// �̷��� �ϸ� �� �׷��� �̷��� �翬�� ������
	// ROM ���� �����Ѵٴ� ���ݾ�
	// �̰� ������ ��ũ�ܰ踻�� ��Ÿ�� �ܰ迡�� ������


	// ��Ƽ����Ʈ charset
	// 1����Ʈ ���ڴ� 1����Ʈ�� ǥ���ϰ� 2����Ʈ ���ڴ� 2����Ʈ�� ǥ��
	char szTest[10] = "abc�ѱ�"; // �� �Ⱦ��ſ���~
	// �̷��� abc�� 1����Ʈ�� ����Ǿ��ְ� �ѱ��� 1����Ʈ 1����Ʈ ���ļ� 2����Ʈ�� ����Ǿ�����
	// ������ �ִµ�
	// ������� ������ ���ڰ� ����� Ȯ���ϰ� ������ ���� 1����Ʈ ���� 2����Ʈ ¥����
	// ������ �ָŸ�ȣ����

	wchar_t szTestW[10] = L"abc�ѱ�"; // Widebyte system(�̰� �����ڵ巡!)

	// �ڿ� _t ���� �Լ����� ������Ʈ �Ӽ����� �������� ������ ����
	// ��Ƽ����Ʈ�� �س����� �Լ����� ��Ƽ����Ʈ �Լ��� �ٲ��ְ�
	// �����ڵ��������� �س����� 2����Ʈ ���� �Լ��� �ٲ㼭 ����������
	// �츰 �ٵ� �����ڵ�� ���Ŷ� �ʿ���� ��

	{
		wchar_t szName[10] = L"Raimond";
		// ���⼭ L"Raimond"�� ROM�� ������
		// ������ ���ϸ� ROM�� �ڵ念���� �ƴ϶� �ʱ�ȭ ������ �ִ�
		// Ư�� �޸𸮸� �ʱ�ȭ �����ִ� �ֵ��� ���� �з��ʤ���



		// wcslen(const wchar_t* _String) 
		// �� �Լ��� ���ڿ��� ���̸� �˷��ִ� ���̴ϱ� ���̸� �˷���ߴ�
		// �׷��ϱ� �� ���� �����һ��� �����ϱ� const wchar_t* �� �޾ư�
		int iLen = wcslen(szName); 
		cout << "wcslen ����� szName���� : " << iLen << endl;

		iLen = c_wcslen(szName);
		cout << "c_wcslen ����� szName���� : " << iLen << endl;

		
	}

		
	{

		wchar_t szName1[20] = L"Raimond";
		wchar_t szName2[10] = L"Ds";

		wcscat_s(szName1, 14, szName2);
		c_wcscat_s(szName1, 14, szName2);

		cout << c_wcscmp(L"ABC", L"BBC") <<endl;
		cout << wcscmp(L"ABCD", L"BBC")<<endl;
	}


	return 0;
}