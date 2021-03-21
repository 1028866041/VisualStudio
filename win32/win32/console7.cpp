#include "stdafx.h"
#include <iostream>
using namespace std;

int app7(int argc, char *argv[])
{
	int n = 5, arry[5], i = 0, m, k = 0, a[1024] = {0};

	for (i = 0; i < n; i ++)
		cin >> arry[i];
	
	m = arry[0];
	for (i = 0; i < n; i++)
	{
		if (m > arry[i]){
			m = arry[i];
			k = i;
		}
	}

	for (i = k; i < n; i++)
	{
		a[i-k] = arry[i];
	}
	for (i = 0; i < k; i++)
	{
		a[i + n - k] = arry[i];
	}

	for (i = 0; i < n; i++)
		cout << a[i] << ' ';

	return 0;
}