#include "stdafx.h"
#include <iostream>
using namespace std;

long func8(int n)
{
	if (n > 2)
		return (func8(n - 1) + func8(n - 2));
	else if (n <= 0)
		return 0;
	else
		return 1;
}

int app8(int argc, char *argv[])
{	
	cout << func8(39) << endl;
	return 0;
}