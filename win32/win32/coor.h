#include<iostream>
#pragma once
using namespace std;

class Coor
{
	friend void printXY(Coor &c);
public: 
	Coor(int i,int j)
	{
		x=i;
		y=j;
	}
private:
	int x;
	int y;
};

void printXY(Coor &c){
	cout<<c.x<<c.y<<endl;
}