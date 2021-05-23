#include "stdafx.h"
#include <iostream>
using namespace std;

int app10(int argc, char *argv[])
{
	printf("let's go!");
	throw("IllegalArgumentException error");

	return 0;
}