
//(8,9)跳台阶（重要，有变种，比如每次跳2的整数次幂）
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;



class Solution {
public:
	int a[10000] = { 0 };
	//in the n-th floor
	int jumpFloor(int number) {
		if ((number == 1) || (number == 0)||(number==2))
		{
			return number;
		}
		if (a[number] == 0)
		{
			a[number] = jumpFloor(number - 1) + jumpFloor(number - 2);
			return a[number];
		}
		return a[number];
	}
};
//
//int main()
//{
//
//	return 0;
//}