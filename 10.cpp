//矩形覆盖
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int a[100000] = { 0 };
	int rectCover(int number) {

		if (number == 0)
		{
			return 0;
		}
		if (number == 1 || number == 2)
		{
			return number;
		}
		if (a[number] == 0)
		{
			a[number] = rectCover(number - 2)+rectCover(number-1);
		}
		return a[number];
	}
};
int main()
{
	Solution solver;
	cout<<solver.rectCover(3);

	return 0;
}