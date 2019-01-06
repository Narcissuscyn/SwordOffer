//包含min函数的栈
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	vector<int>sta;
	int min_val;
	void push(int value) {
		if (sta.empty())min_val = value;
		else
		{
			if (value < min_val)min_val = value;
		}
		sta.push_back(value);
	}
	void pop() {
		vector<int>::iterator it = sta.end() - 1;
		
		sta.erase(it);
		if (*it == min_val)
		{
			min_val = sta[0];
			for (int i = 0; i < sta.size(); i++)
			{
				if (min_val > sta[i])min_val = sta[i];
			}
		}
	}
	int top() {
		return *(sta.end()-1);
	}
	int min() {
		return min_val;
	}
};

int main()
{
	Solution solver;
	for (int i = 1; i < 5; i++)
	{
		solver.push(i);
	}
	solver.pop();
	cout<<" "<<solver.top()<<" "<<solver.min();
	return 0;
}