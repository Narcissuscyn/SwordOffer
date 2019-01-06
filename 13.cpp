//调整数组顺序使奇数位于偶数前面
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> old,even;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
			{
				even.push_back(array[i]);
			}
			else
			{
				old.push_back(array[i]);
			}
		}
		old.insert(old.end(), even.begin(), even.end());
		array = old;

	}
};

int main()
{
	Solution solver;
	return 0;
}