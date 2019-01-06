//旋转数组的最小值
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len == 0)
		{
			return 0;
		}
		else
		{
			int da = 1;
			for (int i = 1; i < len; i++)
			{
				da = rotateArray[i] - rotateArray[i - 1];
				if (da < 0)
				{
					return rotateArray[i];
				}
			}
		}
		return rotateArray[0];
	}
};

//int main()
//{
//	Solution solver;
//	//3.
//	//input:3 4 5 1 2 s
//	vector<int> a;
//	int val = 0;
//	while (cin >> val)
//	{
//		a.push_back(val);
//	}
//	cout << solver.minNumberInRotateArray(a) << endl;
//	getchar();
//	return 0;
//}