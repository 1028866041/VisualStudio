#include "StdAfx.h"
#include "match.h"
#include "time.h"
#include <iostream>
using namespace std;

void Match::printTime(Time &t)
{
	cout<<t.hour<<":"<<t.min<<":"<<t.sec<<endl;
}