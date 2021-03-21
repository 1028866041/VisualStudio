#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

int app5(int argc, char* argv[])
{
	list<int> lst;
	int i = 0,c, n = 3;
	list<int>::iterator iter;

	for (i = 0; i < n; i++)
	{
		cin >> c;
		lst.push_back(c);
	}
	lst.reverse();

	for (iter = lst.begin(); iter != lst.end(); ++iter)
		cout << *iter << endl;

	return 0;
}