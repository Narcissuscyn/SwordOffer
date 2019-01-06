//二进制数中1的个数
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;
class Solution {
public:
	vector<int>a;
	int  NumberOf1(int n) {
		bool flag = true;
		if (n < 0)
		{
			flag = false;
		}
		n = abs(n);
		while (n!=0)
		{
			if (n % 2 == 1)
			{
				a.push_back(1);
			}
			else
			{
				a.push_back(0);
			}
			n = n / 2;

		}
		if (!flag)
		{
			while (a.size()<31)
			{
				a.push_back(0);
			}
			a.push_back(1);

			for (int i = 0; i < a.size()-1; i++)//reverse
			{
				if (a[i] == 1)
				{
					a[i] = 0;
				}
				else
				{
					a[i] = 1;

				}
			}
			for (int i = 0; i < a.size()-1; i++)//add 1
			{
				a[i] += 1;
				if (a[i] == 2)
				{
					a[i] = 0;
				}
				else
				{
					break;
				}
			}
			

		}
		
		int count = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 1)
			{
				count++;
			}
		}
		return count;
	}
};

int main()
{
	//-2147483648
	Solution solver;
	cout<<solver.NumberOf1(-1);
	return 0;
}