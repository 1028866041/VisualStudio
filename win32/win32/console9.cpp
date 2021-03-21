#include "stdafx.h"
#include <iostream>
using namespace std;

long func9(int n)
{
	if (n > 2)
		return (func9(n - 1) + func9(n - 2));
	else if (n == 2)
		return 2;
	else if (n == 1)
		return 1;
	else
		return 0;
}

long func9s(int n)
{
	if (n > 2)
		return 2*func9s(n - 1);
	else if (n == 2)
		return 2;
	else if (n == 1)
		return 1;
	else
		return 0;
}

int app9(int argc, char *argv[])
{
	cout << func9(39) << endl;
	cout << func9s(29) << endl;
	return 0;	
}