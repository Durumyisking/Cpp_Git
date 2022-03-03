// 20220225.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "20220225.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND		g_hwnd; //메인 윈도우 핸들
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 앞에 적혀있는 _In_, _In_opt_ 적어둔것은
// 그 변수의 의미/용도를 적어둔것 SAL이라고 부름
// 난 딱히 알 필요 없음


// 주석과 같은 역할임
// _in_		= 이 함수에 이 데이터가 입력된다
// _in_opt_	= 부가적인 데이터 (잉여인자)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance , /* 프로세스가 시작되는 메모리 주소 */
                     _In_opt_ HINSTANCE hPrevInstance, /* 먼저 실행된 이전 프로세스 메모리 주소 (이전 위도우 버전들의 잔재)*/ 
					// 현재는 프로세스 몇개를 띄워도 같은 메모리 주소를 가리킨다
					// 실제 물리적으로는 완전히 다른 공간이지만
					// 사용자들에게는 메모리가 하나인것처럼 가상 메모리를 잡아줌
					// 즉 각 프로세스별로 0번지 라고 하는곳은 실상은 다 다름
					// 그러니까 다 0번지라고 부르는데 사실은
					// 12345678 0번지 12345944 0번지 이런느낌

					// 위에서 이렇게 말 했다고 프로세스와 윈도우가 같은게 아님
					// 윈도우는 인터페이스 역할을 하고
					// 프로세스는 윈도우를 가질수도 아닐수도 있음
					// 작업관리자 키면 프로세스는 개많은데 윈도우 아닌게 많잖음

					// 가상 메모리가 생기기 전에는 프로세스의 실제 위치를 넣어줬었음
                     _In_ LPWSTR    lpCmdLine,
					// cmd로 ipconfig -e 이런식으로 명령어 내려줄때 -e 부분에 커맨드 넣을때 씀
                     _In_ int       nCmdShow)
{

    UNREFERENCED_PARAMETER(hPrevInstance);	// == hPrevInstance 신경쓸필요 없음
    UNREFERENCED_PARAMETER(lpCmdLine);		// 신경쓸필요 없음
	// 둘 다 매크로인데 매크로 안에 인자를 넣어주면 그냥
	// 인자 안에 있는 변수를 (hPrevInstance) 결과로 나타냄
	// 그냥 변수명 띡 하나 적어둔거


    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	// 우리 프로젝트에서 사용할 자원들을 볼 수 있는 리소스 뷰의
	// string table의 IDS_APP_TITLE 찾아서 가져옴
	// 가져온 문자열을 szTitle에 저장
	// 내가 따로 이름을 지어주지 않으면 내 프로젝트 이름을 string 테이블에 넣은 후
	// 그걸 읽어와서 InitInstance에 넣어줌
    LoadStringW(hInstance, IDC_MY20220225, szWindowClass, MAX_LOADSTRING);

	// 윈도우 정보 등록
    MyRegisterClass(hInstance);

    // 위에서 입력한 정보에 따라 윈도우 생성
	/*
		윈도우란
		유저와 프로그램간의 인터페이스
		입력에 대한 출력을 주고 사용자와 프로그램간에 일어나는 상호작용을 보여줌
	*/
	// 초기 기본 베이스 윈도우가 안만들어지면 종료
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

	// 단축키 테이블 정보들임 딱히 안중요
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY20220225));


    MSG msg;
	// 메시지 구조체 안에는 msg.hwnd 메시지 핸들이있음
	// 메시지 핸들 : 메시지가 발생한 윈도우

    // 기본 메시지 루프입니다: 

	// 발생한 메시지가 어떤 것인지 메시지 구조체의 정보를 채움
	// GetMessage 주요 특징
	// 메시지큐에서 메시지 확인할때까지 대기
	// 메시지 큐에 메시지가 없으면 함수가 종료

	// 받아온 메시지가 어떤 메시지냐에 따라 true or false
	// msg.message == WM_QUIT 이면 false -> 프로그램 종료
	
	// SetTimer(g_hwnd, 10, 0, nullptr);
	// 타이머 발생되는 윈도우, 타이머ID, 타이머 발생되는 시간, 타이머가 발생할때마다 호출해줄 함수 주소
	// 설정한 윈도우에 내가 설정한 시간마다 타이머 메시지가 들어옴
	// 우리는 개빨리 들어오게 하려고 0으로 해놓은거
	// 근데 이 방법은 굉장히 느림
	// 우리는 윈도우 메시지를 최대한 사용 안하는 방식으로 갈꺼임

	// 우리가 만들 게임은 어쩔수 없는 상황이 아니면 메시지 처리기는 일체 사용하지 않을 것

	// GetMessage
	// 메시지큐에서 메세지 확인 될 때까지 대기
	// msg.message == WM_QUIT 인 경우에 false를 반환(프로그램 종료)

	// PeekMessage
	// 메시지 유무와 관계없이 반환
	// 우리는 확인한 메시지가 있으면 그 메시지를 메시지 큐에서 제거하는 방식으로 할거

	// 윈도우가 메시지를 처리하는 시간은 너무 짧다
	// 따라서 메시지가 없을때는 계속 놀고있는것이다.
	// 그래서 메시지가 들어오지 않았을때도 처리할 일을 만든다

	// 비동기함수
	// 우리 프로그램이 포커싱(창이 눌려있음)이 되어있지 않아도
	// 메시지를 발생시키게 함

 //   while (GetMessage(&msg, nullptr, 0, 0)) // 여기의 getMessage때문에 우리 프로그램이 메시지 기반 방식으로 동작
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
				break;

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
				// 들어온 메시지가 단축키 테이블에 있는 정보인지 먼저 체크

			{
				// getmessage로 얻어온 메시지를 처리
				TranslateMessage(&msg); // 메시지 분석
				DispatchMessage(&msg); // 관련 처리기로 전송
			}
		}
		else
		{
			// 메시지가 없는동안 호출
			// game 코드 수행
			// 디자인 패턴


		}
    }

	// 타이머도 커널오브젝트라 프로그램 종료될때 꺼줘야댐
	// KillTimer(g_hwnd, 10);

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc; // 윈도우에 발생하는 메시지를 처리해줄 함수의 주소값
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY20220225));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY20220225); // 메뉴바
    wcex.lpszClassName  = szWindowClass;
	// 위의 LoadingStrW에서 받아온 것을 key값 파트에 넣음
	// 다른 함수에서 이렇게 저장한 정보를 사용할때 key값을 대입해서 사용
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
	// window쪽에서 제공해주는 함수
	// os차원에서 실행해주는 기능임
	// 왠만해서는 os자체에서 만들어져있는거 쓰는거 좋음
	
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   g_hwnd = CreateWindowW(szWindowClass, L"MyGame", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   // createwindow로 만들어진 객체는 OS에서 관리하기 때문에 내가 접근 할 수 없음

   if (!g_hwnd)
   {
      return FALSE;
   }

   ShowWindow(g_hwnd, nCmdShow);
   UpdateWindow(g_hwnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

#include <vector>

using std::vector;

struct tObjInfo
{
	POINT g_ptObjPos; // int 2개로 구성된 구조체
	POINT g_ptObjScale;
};

vector <tObjInfo> g_vecInfo;

// 좌 상단
POINT g_ptLT;
POINT g_ptRB;

bool bLbtnDown = false;

// 현재 PAINT 기능은 완전하지 않음
// 렌더링 되는 과정이 보여져 계속 깜빡이게 보임

// 이를 해결하기위한 2가지 방법이 있음

// 1. 일정시간마다 강제로 메시지를 실행시키게 함

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// 어떤 윈도우 메시지가 들어왔는지 확인
	// 모든 윈도우 메시지가 있는건 아니다
	// 원하는 윈도우 메시지의 case를 잡아서 처리하면댐

	// lParam에 마우스 좌표
	// wParam에 무슨 키가 눌렸는지 정보

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
				// default 프로시저에서는 아무것도 하면 안됨
            }
        }
        break;
    case WM_PAINT:	// 무효화 영역이 발생한 경우 WM_PAINT 발생
					// 창이 줄였다가 켜졌을때 발생한다.
	{
		PAINTSTRUCT ps;

		// Device Context(그리기 관련) 객체를 만들어주어 ID 반환
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...


		// 윈도우 핸들
		/*
			CreateWindowW로 윈도우가 생성되면
			OS는 우리에게 윈도우의 ID값을 줌
			그 ID값을 윈도우 핸들이라고 부름
			그 핸들로 Window의 다양한 함수를 사용 가능함
			우리가 코딩할때 대부분 window에서 다양한 ID를 얻어서
			그 ID에 해당하는 기능들을 사용해 코딩할꺼임

			이런 ID들은 모두 int를 하나 가지고 있는 4바이트 구조체인데
			이렇게 만들어져있는 이유는
			예를들어 함수를 사용할때 함수의 인자를 ID구조체가 아니라 int로 받으면
			다른 핸들러ID를 집어넣을수 있는 실수를 범할수도 있고 직관성도 떨어짐
			그래서 이렇게 구조체로 이름들이 따로 만들어져 있는거
		*/
		// 윈도우 좌표
		/*
			작업 영역 ( 타이틀바와 메뉴바 아래서부터 )
			단위 픽셀
		*/


		// HDC ? 
		/*
			HDC : 그리기 작업 수행에 필요한 Data들의 집합
			우리가 윈도우에 무언가를 그리려면 DC가 필요함
			HDC(device context)는 자신의 부모 윈도우를 알고 있어야 함

			DC가 목적지로 하고 있는 window에 DC안에 들어있는 pen, brush 등등 정보로
			목적지에 그림을 그린다

			DC의		목적지는 hWnd
					기본 펜은 black
					기본 brush(pen으로 그린 도형의 내부를 칠함)는 white

					픽셀 한 칸은 RGB값 각 1바이트씩 총 3바이트를 가지고 있다.

		*/

		// 직접 펜을 만들어서 DC에 지급해보자
		HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
		//GetStockObject(); // 우리가 직접 오브젝트를 만들거나 삭제할 필용 없는 자주 쓰이는 오브젝트를 가져온다


		// 기본 펜 ID 값을 받아둠
		HPEN hDefaultPen = (HPEN)SelectObject(hdc, hRedPen);
		// 반환타입이 void 포인터로 되어있어서 캐스팅 가능
		// SelectObject는 기존 DC의 HGDIOBJ에 저장된 값을 두번째 인자로 변경한 후, 기존 저장되어있는 핸들 값을 반환한다.
		HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);


		// 변경된 펜으러 사각형 그리기
		if (bLbtnDown)
		{
				
			Rectangle(hdc
				, g_ptLT.x, g_ptLT.y
				, g_ptRB.x, g_ptRB.y);
		}

		for (int i = 0; i < g_vecInfo.size(); ++i)
		{
			Rectangle(hdc
				, g_vecInfo[i].g_ptObjPos.x - g_vecInfo[i].g_ptObjScale.x / 2
				, g_vecInfo[i].g_ptObjPos.y - g_vecInfo[i].g_ptObjScale.y / 2
				, g_vecInfo[i].g_ptObjPos.x + g_vecInfo[i].g_ptObjScale.x / 2
				, g_vecInfo[i].g_ptObjPos.y + g_vecInfo[i].g_ptObjScale.y / 2);
		}
		

			// DC 의 펜을 원래 펜으로 되돌림
			SelectObject(hdc, hDefaultPen);
			SelectObject(hdc, hDefaultBrush);


			DeleteObject(hRedPen); // 커널 object를 삭제 요청
			DeleteObject(hBlueBrush);

            EndPaint(hWnd, &ps);
        }
        break;

		// 키가 눌렸을때 여기로 들어옴
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			
			InvalidateRect(hWnd, nullptr, true); 
			// WM_PAINT가 다시 발생하게 무효화 영역을 함수로 직접 설정
			// nullptr을 넣으면 전체 영역으로 된다
			// 마지막 인자 bErase를 false로 하면 픽셀들이 정리되지 않는다

			// 근데 이렇게 메시지 기반으로 하면 키를 꾹 누르고 있을때
			// 메시지큐에 눌렀다는 정보를 한 번 확인한 뒤
			// 계쏙 누르고 있네? 하면서 그 다음부터야 쭉 눌림


			break;

		case VK_DOWN:
			InvalidateRect(hWnd, nullptr, true);
			break;

		case VK_LEFT:
			InvalidateRect(hWnd, nullptr, true);
			break;

		case VK_RIGHT:
			InvalidateRect(hWnd, nullptr, true);
			break;


		case 'W':
		{
			int a = 0;
		}
		break;

		default:
			break;
		}
		break;

	case WM_LBUTTONDOWN:
	{
		g_ptLT.x = LOWORD(lParam);	// 마우스 x좌표
		g_ptLT.y = HIWORD(lParam);
		bLbtnDown = true;
	}
	break;

	case WM_MOUSEMOVE:	
		g_ptRB.x = LOWORD(lParam);
		g_ptRB.y = HIWORD(lParam);
		InvalidateRect(hWnd, nullptr, true);
		break;

	case WM_LBUTTONUP:
	{
		g_ptRB.x = LOWORD(lParam);
		g_ptRB.y = HIWORD(lParam);

		tObjInfo info = {};
		info.g_ptObjPos.x = (g_ptLT.x + g_ptRB.x) / 2;
		info.g_ptObjPos.y = (g_ptLT.y + g_ptRB.y) / 2;

		info.g_ptObjScale.x = abs(g_ptRB.x - g_ptLT.x);
		info.g_ptObjScale.y = abs(g_ptRB.y - g_ptLT.y);

		g_vecInfo.push_back(info);

		bLbtnDown = false;

	}
	InvalidateRect(hWnd, nullptr, true);
	break;

	case WM_TIMER:
		// 타이머가 발생할때 기능 구현
		// 타이머 속도를 빠르게 할수록 타이머 메시지가 자주 발생하지만
		// 여기 타이머 case내의 기능을 수행하는건 컴퓨터 성능에 따라 닫ㄹ림

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
