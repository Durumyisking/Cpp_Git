#include <iostream>


using namespace std;


int main()
{
	// ������ ����
	// 1. ����
	// 2. ������
	// 3. ��
	// 4. �ڵ� ���� (�б� ���� read only memory)


	// ����

	// char�� 1����Ʈ ���� 8bit�� ������ ���� ǥ�� �Ұ� (�ƽ�Ű�ڵ� ���)
	// �׷��� ���°� wchar ��� 2����Ʈ (�����ڵ���)

	char c = '1'; // �̷��� 1�ڸ� �̻��� ���ڸ� ������ �� ���� ���ڸ� ����
	// ���ڸ� ��� �дٰ� �������� �ƽ�Ű�ڵ�0(null)�� ������ ������ ������ �ν�

	
	wchar_t wc = L'91';		// 2����Ʈ ���� => �� �� ���� 9�� �ش��ϴ� �����ڵ�(57)�� ���
							// 2����Ʈ ���ڸ� �ۼ��Ҷ��� �տ� L�� �ٿ��� 2����Ʈ �������� ǥ�� (�ƽ�Ű�� �ƴ϶� �����ڵ�� �ν�)
	wchar_t wc2 = 'baa';	// �̷����ϸ� �� ���� 16bit�� �� aa�� ���� 97(0110 0001) 97(0110 0001)
	short s = 49;			// ������ �״�� ������

	c = 49;

	cout << c << endl << wc << endl;

	wc = 459; 
	//�̰Ŷ� "459" �̰Ŷ� �ٸ� => "459"�� �ȿ� ������ �� ����Ʈ���� 4�Ǿƽ�Ű(52) 5�Ǿƽ�Ű(53) 9�Ǿƽ�Ű(57) null�Ǿƽ�Ű(0) ����
	c = '459';

	cout << c;
	


	return 0;
}