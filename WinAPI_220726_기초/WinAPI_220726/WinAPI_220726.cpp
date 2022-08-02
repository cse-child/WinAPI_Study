// WinAPI_220726.cpp : 애플리케이션에 대한 진입점을 정의합니다.
/*
핵심 함수 !
- WinMain
  1. win 창 생성 (MyRegisterClass - 창 객체 등록, InitInstance - 창 초기화)
  2. 메시지 루프 (Queue 활용, 메시지를 돌리기만함)

- WndProc
  1. 메시지 처리


*/

#include "framework.h"
#include "WinAPI_220726.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINAPI220726, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI220726));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		// ★ TranslateAccelerator : win 창 메뉴바
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI220726));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPI220726);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
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

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		100, 100, // ★창 위치
		500, 500, // ★창 크기
		nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//★ HANDLE은 typedef void* HANDLE; 한 것과 같다.
//★ void* (void 포인터): 자료형이 특정되지 않은 경우 그 포인터를 받을 때 사용
//★ H->Handle : 특정 개체를 조정하는 역할, 포인터 변수이다.
//★ HWND(윈도우 핸들) : 윈도우 창과 관련된 기능을 수행할 때 사용
//★ HDC(Handle Device Context) : 출력에 관련된 모든 기능에 관여하는 객체
//★ DC(Device Context) : 출력 영역
//★ message : 윈도우 이벤트 메시지
//★ w : WORD(정수형 자료) -> 직접적인 데이터 포함.
//★ wParam : 키보드 및 마우스가 어떤 키가 들어왔는지에 대한 정보 등
//★ l -> long point : 보정이 필요한 데이터
//★ lParam : 마우스의 위치정보 등

POINT mousePos = {}; //★ 마우스 위치 저장변수
POINT startClickPos = {};

HPEN redPen;
HPEN greenPen;
HPEN selectPen;

HBRUSH yellowBrush;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//★ HWND : winAPI 에는 'H'가 붙은 객체가 많다. (H-> handle, WND -> window)
	//★ HWND는 일반 변수처럼 보이지만 항상 '포인터' 변수이다. 즉 함수에서도 call-by-reference임
	//★ message : 대략적인 어떤 메시지 객체
	//★ wParam, lParam : 메시지의 세부 정보
	switch (message)
	{
	case WM_CREATE: //★ 윈도우 창 생성될 때 호출되는 메시지
	{
		//★ HPEN도 포인터이고 동적할당을 받아서 사용하므로 해제해줘야함
		redPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		greenPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
		yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
	}
	break;
	case WM_COMMAND: //★ WM_COMMAND: 메뉴바를 클릭했을 때 메시지 
	{
		int wmId = LOWORD(wParam); //★ 메뉴바의 어떤 메뉴를 선택했는지 정보
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_ABOUT: //★ 도움말 메뉴
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		LPCWSTR w = L"HelloWorld"; //★ Long Pointer Const Wide STRing

		//★ hdc 이용하여 x,y=0,0 위치에 "HelloWorld"글인 10크기의 문자를 출력하겠다.
		TextOut(hdc, 250, 0, L"HelloWorld", 10);

		//★ 0~255
		COLORREF color = RGB(255, 128, 0);

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				SetPixel(hdc, i, j, color); //★ 1픽셀 찍기
			}
		}

		SelectObject(hdc, greenPen);

		MoveToEx(hdc, 100, 100, nullptr);
		LineTo(hdc, 200, 200);

		// SelectObject(hdc, yellowBrush); //★ 채우기 속성
		HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, yellowBrush);
		Rectangle(hdc, 200, 100, 300, 200); //★ 사각형 그리기

		SelectObject(hdc, redPen);
		SelectObject(hdc, defaultBrush);
		Ellipse(hdc, 200, 100, 300, 200); //★ 원형 그리기

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_MOUSEMOVE: //★ 마우스가 움직일 때 발생하는 메시지
		mousePos.x = LOWORD(lParam);
		mousePos.y = HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN: //★ 마우스 왼쪽 버튼 이벤트
	{ //★ hdc 선언할거면 중괄호 해야함
		HDC hdc = GetDC(hWnd);

		//SetPixel(hdc, mousePos.x, mousePos.y, RGB(255, 0, 255));

		//startClickPos.x = mousePos.x;
		//startClickPos.y = mousePos.y;
		startClickPos = mousePos;

		ReleaseDC(hWnd, hdc); //★ hdc를 해제해줘야함
	}
	break;
	case WM_LBUTTONUP:
	{
		HDC hdc = GetDC(hWnd);

		SelectObject(hdc, selectPen);

		MoveToEx(hdc, startClickPos.x, startClickPos.y, nullptr);
		LineTo(hdc, mousePos.x, mousePos.y);

		ReleaseDC(hWnd, hdc);
	}
	break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case 'Q':
			selectPen = redPen;
			break;
		case '1':
			selectPen = greenPen;
			break;
		default:
			break;
		}
	}
	break;
	case WM_DESTROY: //★ 윈도우 창이 꺼질 때 호출되는 메시지
		DeleteObject(redPen); //★ 동적할당 해제
		DeleteObject(greenPen); //★ 동적할당 해제
		DeleteObject(yellowBrush); //★ 동적할당 해제
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
