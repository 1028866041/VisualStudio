#include"stdAfx.h"
#include<windows.h>

//#pragma comment( linker, "/subsystem:\"console\" /entry:\"startup\"" )
int startup()
{
	int a= 10;
	HANDLE heap= HeapCreate(HEAP_NO_SERIALIZE,0x010,400*1024);
	int *p= (int*)HeapAlloc(heap, HEAP_ZERO_MEMORY,0x010);	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			*p= i*100+j+1;
		}
	}
	MessageBoxA(NULL, (char *)p, "startup", MB_OK);
	return 0;
}