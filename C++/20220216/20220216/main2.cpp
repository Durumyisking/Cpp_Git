#include <iostream>

using namespace std;


class CParent
{
protected:
	int		m_i;


public:
	CParent()
		: m_i(0)
	{
		cout << "C Parent" << endl;
	}
	CParent(int _a)
		: m_i(_a)
	{
		cout << "C Parent" << endl;
	}

	~CParent()
	{
		cout << "C Parent 소멸자" << endl;
	}
public:

	void SetInt(int _a)
	{
		m_i = _a;
	}

	virtual void Output()	// 함수 앞에 virtual을 붙이면 각 클래스 정보에 
							// 가상함수들을 담고있는 가상함수 테이블이 등록이 됨
							// 가상함수를 사용했을때 *내가 접근한 객체*의 테이블로가서
							// 그 쪽에 있는 함수를 호출
							
	{
		cout << "Parent output function" << endl;
	}


};

// 상속 받았을때의 메모리 구조
// parent가 4바이트일때 child가 4바이트일때
// child 객체안에는 child 객체의 메모리 용량 + parent의 메모리 용령
// 총 8바이트

class CChild : public CParent // 상속을 받는다 => 부모 클래스의 기능을 가져옴
{
private:
	float m_f;

public:
	CChild()
		// : CParent()
		: CParent(1000) // 오버로딩된 부모 생성자를 부르려면 명시를 해줘야함
		, m_f(0.f)
		// , m_i(0) parent의 변수이기 때문에 초기화를 parent의 생성자에 맡겨야됨
		// child객체의 메모리 구조가 [parent][child] 이렇게 생겼는데 
		// 더 일찍 호출되는 child가 parent로 접근할 수 가 없음

		// 생성자 초기화순서는 child -> parent다
		// parent의 생성자는 child 초기화 부분 맨위에 존재한다
		// 따라서 child 생성자 코드블럭 내부는 parent 생성자 다음에 실행된다
	{
		m_i = 0;
		cout << "C Child" << endl;
	}

	~CChild()
	{
		cout << "C Child 소멸자" << endl;

		// ~Parent();
	}
	// 소멸자는
	// 자식이 자신의 소멸자 호출해서 할 일을 하고
	// 부모쪽 소멸자를 호출
	// 생성자와 대칭적이라고 보면 될 듯?

public:
	void SetInt(int _a)
	{
		m_i = _a;	// m_i는 부모에서 protected로 선언되어 있기 때문에 접근 가능
					// private으로 선언되어 있으면 접근이 불가능하고
					// public으로 선언하면 캡슐화에 문제가 생긴다
	}

	virtual void Output()	// 인자랑 이름이 완전히 같은 함수는 원래 선언 불가
							// parent와 완전히 같은 함수이지만
							// parent의 output이 여기 구현되어있는게 아니니까 이렇게 호출가능
							// 이것을 오버라이딩이라고 부름
							// child.Output()을 했을때 무조건 child의 Output이 호출됨
	{
		cout << "Child Output function" << endl;
	}

	void child_only_func()
	{
		cout << "차일드 온니" << endl;
	}
};

// 메모리구조 : parent + child + childchild 모양으로 순차적으로 메모리가 잡힘 (매우 중요)


class CChildChild : public CChild
{
private:
	long long m_ll;

	CChildChild()
	{
		cout << "C ChildChild" << endl;
	}

	~CChildChild()
	{
		cout << "C childchild 소멸자" << endl;
	}
};

int main()
{
	// 객체지향 언어 특징
	/*
		1. 캡슐화 (은닉성) : private public..
		2. 상속 : 부모 클래스의 기능 가져옴
		3. 다형성
		4. 추상화

		


	*/

	CParent parent;
	parent.Output();	// 이건 당연히 할 수 있쥐

	CChild child;
	child.Output();		// child 구현부에 오버라이딩을 안했으면
						// parent output function이 출력된다
	// 나는 오버라이딩 함수 안쓰고 부모꺼를 호출할거야!
	child.CParent::Output(); // 근데 보통 이렇게 안함 ㅋ 이럴려면 오버라이딩 안하지



	parent.SetInt(10);
	child.SetInt(10);


	CParent* pParent = &child;
	// &child 메모리 구조를 생각해보면 이다
	// child : [parent] [child]
	// pParent의 시작주소에 child의 시작주소를 넣는다고 생각하면
	// 어차피 pParent는 CParent* 만큼만 읽을 것이기 때문에 노상관


	// CChild* pChild = &parent;
	// 반대로 pChild에 parent의 시작주소를 넣으면
	// Child* 만큼의 메모리를 읽어야 되는데
	// &parent의 뒷부분이 null이라서 읽을 수 없음

	// 정리하면 부모 클래스는 자식의 주소 받아올 수 있고
	// 자식은 부모 주소 못받아옴

	// 부모는 주소만 바꿔주면 어떤 자식이라도 될 수 있음
	// 근데 	CParent* pParent = &child; 이면 parent의 뒷부분은? 뭔데?

	((CChild*)pParent)->child_only_func();	
	// 이 방법은 위험함
	// 지금 가능한 이유는 우리가 위에서 pParent에 자식 객체를 가리켰기때문
	// pParent = &parent를 하면 문제 발생


	CChild* pChild = dynamic_cast<CChild*>(pParent);
	// 캐스팅에 실패하면 nullptr을 가져오기 때문에
	// 오류 방지
	if (nullptr != pChild)
	{
		pChild->child_only_func();
	}


	return 0;
}

// 정리

/*
	1. 상속
		자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버 초기화 불가능
		생성자 호출 순서 : 자식 -> 부모
		생성자 실행 순서, 초기화 순서 : 부모 -> 자식
		소멸자 호출 순서 : 자식 -> 부모
		소멸자 실행 순서 : 자식 -> 부모
		
	2. 오버 라이딩 ( 나도아는데 오버로딩이랑 다른거임 진짜로 알고있음;;;; )
		상속 관계에서만 발생
		부모클래스에 구현되어있는 함수와 똑같은 함수를
		자식클래스에 구현했을때
		자식객체에서 함수 호출시 자식클래스에 구현된 함수로 선택되서 호출된다.
		
		보통 사용하는 경우는
		부모의 기능의 대부분은 그대로 받아서 사용하는데
		특정 기능만 부모에 있는 기능이 아니라 내쪽에서 재정의 하고싶을때 씀
		
	3. 다형성
		// 부모는 참조하는 주소만 바꿔주면 어떤 자식이라도 될 수 있음
	
	3-1. 가상함수
		// 부모 포인터 타입으로, 부모 클래스로부터 파생되는 자식 클래스 객체들의 주소를 가리킬 수 있다.
		// 모든 객체를 부모 클래스 타입으로 인식하기 때문에, 가리킨 자식 클래스 객체가 무엇인지 알 수 없음
		// virual 키워드를 사용해 각 클래스는 자신만의 고유한 가상함수 테이블을 갖는다
		// 각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞는 테이블을 가리킨다.
		// 그 테이블에는 해당 클래스의 가상 함수들이 등록된다.

	4. 다운캐스팅
		// 부모 클래스에서 선언되지 않은, 오직 자식쪽에만 추가된 함수를 호출 하고 싶을 때 사용
		// 자식 포인터타입으로 일시적으로 캐스팅해서 호출한다.
		// 문제가 발생 할 수 있기 때문에 c++에서 dynamic_cast를 지원해서 안전하게 사용가능함
		// RTTI(Run Time Type Identification)
		// 런타임중에 테이블 정보를 확인해 실제 정채를 확인 가능

	5. 추상화
		// 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
		// virtual, = 0 (1 개 이상의 순수가상함수를 포함하면 추상 클래스가 된다.)

*/