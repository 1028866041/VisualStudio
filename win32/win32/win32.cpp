// win32.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "match.h"
#include "coor.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Coor coor(1,2);
	printXY(coor);

	Time t(1,2,3);
	Match m;
	m.printTime(t);
	
	cout<<__cplusplus<<endl;
	system("pause");
	return 0;
}