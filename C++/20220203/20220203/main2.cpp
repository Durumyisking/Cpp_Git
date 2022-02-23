#include <iostream>

class CTest
{

public:
	int m_i;

public:
	CTest()
		: m_i(0)
	{

	}
	/*
	복사생성자
	안만들어주면 컴파일러에서 자동 생성해줌
	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{

	}
	*/

};


int main()
{


	CTest t1;
	t1.m_i = 100;

	/*
	CTest t2;
	t2 = t1;
	이렇게 해도 되지만
	*/
	CTest t2(t1); // 이렇게  복사생성자를 사용하면 생성하는 동시에 t1을 가져옴

	CTest t3 = t1;	// 겉으로는 t3을 생성하면서 t1을 넣는 것 같지만
					// 생성 후 t1을 대입하는것
					// 그런데 컴파일러 자체에서 저렇게 코드를 작성했을때
					// 자동생성되는 복사 생성자를 호출해줌

	std::cout << t1.m_i << " " << t2.m_i << " " << t3.m_i << std::endl;


	


	return 0;
}