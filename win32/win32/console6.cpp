#include"stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

stack<int> stk1, stk2;

void push()
{
	stk1.push(stk2.top());
	stk2.pop();
}

void pop()
{
	cout << stk1.top();
	stk2.push(stk1.top());
	stk1.pop();
}

int app6(int argc, char* argv[])
{
	int n = 3, i, c;
		
	for (i = 0; i < n; i++)
	{
		cin >> c; 
		stk1.push(c);
	}

	for (i = 0; i < n; i++)
	{
		pop();
	}
	return 0;
}