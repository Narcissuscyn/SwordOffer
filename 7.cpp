//斐波那契数列
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

//F0 = 0     (n = 0)
//F1 = 1    (n = 1)
//Fn = F[n - 1] + F[n - 2](n = >2)
int a[10000] = { 0 };
class Solution {
public:
	
	int Fibonacci(int n) {
		if (n == 0)
		{
			a[0] = 0;
			return 0;
		}
		else if(n==1)
		{
			a[1] = 1;
			return 1;
		}
		if (a[n] == 0)
		{
			a[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
			return a[n];
		}
		else
		{
			return a[n];
		}

	}
};

//int main()
//{
//	Solution solver;
//	cout<<solver.Fibonacci(4);
//	getchar();
//	return 0;
//}