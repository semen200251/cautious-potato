#include "Draw.h"


char szClassName[] = "Window1";
HWND hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, UINT, LONG);

ATOM registerMyClass(HINSTANCE hInstance);
UINT uResult;
int createMyWindow(HINSTANCE hInstance, int nCmdShow);

int count_click = 0;
int count_iteration = 0;
int present_n = 0;

mypoint A, B;



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpszCmdParam, _In_ int nCmdShow)
{
	createMyWindow(hInstance, nCmdShow);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}




ATOM registerMyClass(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.cbClsExtra = wc.cbWndExtra = 0;
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCWSTR)szClassName;

	return RegisterClass(&wc);
}

int createMyWindow(HINSTANCE hInstance, int nCmdShow)
{
	registerMyClass(hInstance);
        HWND hWnd = CreateWindowW((LPCWSTR)szClassName, (LPCWSTR)L"Task2", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	if (!hWnd) { return 0; }
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);

		break;
	}
	case WM_LBUTTONDOWN:
	{
		if (count_click == 0)
		{
			A.x = LOWORD(lParam); 
			A.y = HIWORD(lParam);
			count_click++;
		}
		else if (count_click == 1)
		{
			B.x = LOWORD(lParam); 
			B.y = HIWORD(lParam);
			count_click++;
			InvalidateRect(hWnd, NULL, 1);
		}

		break;
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_RIGHT:
			count_iteration++;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_LEFT:
			count_iteration--;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		if (count_click == 2)
			DrawIteration(hdc, A, B, present_n, count_iteration);
		EndPaint(hWnd, &ps);
	}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
