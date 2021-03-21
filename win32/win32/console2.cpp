#include "stdafx.h"
#include <windows.h>
#include <iostream>

HANDLE hMutex = NULL;

DWORD WINAPI Func(LPVOID lpPara)
{
	for (int i = 0; i < 3; i++) 
	{
		WaitForSingleObject(hMutex, INFINITE);
		std::cout << "New thread" << std::endl;
		Sleep(1);
		ReleaseMutex(hMutex);
	}	
	return 0;
}

int app2(int argc, char* argv[])
{
	HANDLE hThread = CreateThread(NULL, 0, Func, NULL, 0, NULL);
	CloseHandle(hThread);

	hMutex = CreateMutex(NULL, FALSE, NULL);
	for (int i = 0; i < 5; i++)
	{
		WaitForSingleObject(hMutex, INFINITE);
		std::cout << "Main  Thread" << std::endl;
		Sleep(2);
		ReleaseMutex(hMutex);
	}
	return 0;
}