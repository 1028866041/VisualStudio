#include<windows.h>
#include<cstdio>
#include<locale.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"" )
/* #pragma comment(lib,"winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )*/

LRESULT WINAPI MyWindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE  hPrevInstance, LPSTR lpCmdline, int nShowCmd)
{
	WNDCLASS wnd;
	wnd.cbClsExtra=0;
	wnd.cbWndExtra=0;
	wnd.lpfnWndProc= MyWindProc;
	wnd.hInstance= hInstance;
	wnd.style= CS_HREDRAW|CS_VREDRAW;
	wnd.hIcon= LoadIcon(NULL,IDI_APPLICATION);
	wnd.hCursor= LoadCursor(NULL,IDC_ARROW);
	wnd.hbrBackground= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName= NULL;
	wnd.lpszClassName= L"main";
	RegisterClass(&wnd);	
	HWND hWnd= CreateWindow(L"main",L"windows", WS_OVERLAPPED,100,100,300,300,NULL,NULL,hInstance,NULL);
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	printf("%d %d %\n", hInstance, hPrevInstance, GetModuleHandle(NULL));
	printf("%s\t %d %d\n",GetCommandLineA(), nShowCmd, SW_SHOWDEFAULT);
	char *str= "A";
	wchar_t *str2= L"AÖÐ";
	_wsetlocale(LC_ALL, L"chs");
	printf("%s %d\n", str, strlen(str));
	wprintf(L"%s %d\n" ,str2, wcslen(str2));

 	//MessageBox(NULL, L"message box", L"main", MB_OK);
	MSG msg;
	while(GetMessage(&msg, NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT WINAPI MyWindProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		return 0;
	}
}
