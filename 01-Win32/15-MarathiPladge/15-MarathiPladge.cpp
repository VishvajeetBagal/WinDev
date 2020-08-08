#include<Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int iCmdShow)
{
	WNDCLASSEX wndclass;
	MSG iMsg;
	HWND hWnd;
	TCHAR szAppName[] = TEXT("Pladge");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);

	hWnd = CreateWindow(szAppName, TEXT("Pladge"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	UpdateWindow(hWnd);
	ShowWindow(hWnd, iCmdShow);

	while (GetMessage(&iMsg, NULL, 0, 0))
	{
		TranslateMessage(&iMsg);
		DispatchMessage(&iMsg);
	}

	return (int)(iMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rc;
	TCHAR str[255] = TEXT("\0");
	PAINTSTRUCT ps;

	switch (msg)
	{
	case WM_PAINT:
		GetClientRect(hWnd, &rc);
		hdc = BeginPaint(hWnd, &ps);
		SetTextColor(hdc, RGB(255, 128, 0));
		SetBkColor(hdc, RGB(0, 0, 0));
		wsprintf(str, TEXT(" भारत  माझा  देश  आहे."));
		//TextOut(hdc, MM_TEXT, MM_TEXT, str, strlen(str));
		TextOut(hdc, MM_TEXT, MM_TEXT, str, wcslen(str));
		wsprintf(str, TEXT(" सारे  भारतीय  माझे  बांधव  आहेत."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 20, str, wcslen(str));
		wsprintf(str, TEXT(" माझ्या  देशावर  माझे  प्रेम  आहे ."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 40, str, wcslen(str));
		wsprintf(str, TEXT(" माझ्या  देशातल्या  समृद्ध  आणि"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 60, str, wcslen(str));
		wsprintf(str, TEXT(" विविधतेने  नटलेल्या  परंपरांचा  मला  अभिमान  आहे."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 80, str, wcslen(str));

		SetTextColor(hdc, RGB(255, 255, 255));
		
		wsprintf(str, TEXT(" त्या  परंपरांचा  पाईक  होण्याची  पात्रता"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 110, str, wcslen(str));
		wsprintf(str, TEXT(" माझ्या  अंगी  यावी  म्हणून  मी  सदैव  प्रयत्न  करीन ."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 130, str, wcslen(str));
		wsprintf(str, TEXT(" मी  माझ्या  पालकांचा ,  गुरुजनांचा"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 150, str, wcslen(str));
		wsprintf(str, TEXT(" आणि  वडीलधार्‍या  माणसांचा  मान  ठेवीन"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 170, str, wcslen(str));
		wsprintf(str, TEXT(" आणि  प्रत्येकाशी  सौजन्याने  वागेन."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 190, str, wcslen(str));

		SetTextColor(hdc, RGB(0, 255, 0));
		wsprintf(str, TEXT(" माझा  देश  आणि  माझे  देशबांधव"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 220, str, wcslen(str));
		wsprintf(str, TEXT(" यांच्याशी  निष्ठा  राखण्याची  मी  प्रतिज्ञा  करीत  आहे ."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 240, str, wcslen(str));
		wsprintf(str, TEXT(" त्यांचे  कल्याण  आणि  त्यांची  समृद्धी  ह्यांतच  माझे "));
		TextOut(hdc, MM_TEXT, MM_TEXT + 260, str, wcslen(str));
		wsprintf(str, TEXT(" सौख्य  सामावले  आहे."));
		TextOut(hdc, MM_TEXT, MM_TEXT + 280, str, wcslen(str));
		wsprintf(str, TEXT(" जय  हिन्द  !"));
		TextOut(hdc, MM_TEXT, MM_TEXT + 300, str, wcslen(str));


		EndPaint(hWnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}