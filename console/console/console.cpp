// console.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	
	//delete
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(2);
	set<int> set;
    for(int i=0;i<nums.size();i++)
        set.insert(nums[i]);
    auto iter= set.begin();
    int j=0;
    if(set.size()>2){
        while(j<set.size()-3){
            j++;
            iter++;
        }
        cout<< *iter;
    }
    cout<< *set.begin();
   
}

