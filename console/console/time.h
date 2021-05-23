#include "match.h"
#pragma once

class Time
{
	friend void Match::printTime(Time &t);
public:
	Time(int hour,int min,int sec);
private:
	int hour;
	int min;
	int sec;
};