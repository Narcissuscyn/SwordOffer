//5.用两个栈实现队列
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
	void push(int node) {
		if (stack1.empty())
		{
			stack1.push(node);
		}
		else
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.push(node);
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}

		}
	}

	int pop() {
		int a = stack1.top();
		stack1.pop();
		return a;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//int main()
//{
//	Solution solver;
//	solver.push(1);
//	solver.push(2);
//	solver.push(3);
//	solver.pop();
//	return 0;
//}