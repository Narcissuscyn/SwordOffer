//数值的整数次方
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	double Power(double base, int exponent) {
		bool flag = true;
		double result = 1;
		if (exponent < 0)
		{
			flag = false;
			exponent = -exponent;
		}
		for (int i = 0; i < exponent; i++)
		{
			result *= base;
		}
		if (!flag)
		{
			result = 1 / result;
		}
		return result;
	}
};

int main()
{
	Solution solver;
	solver.Power(2, -3);
	return 0;
}