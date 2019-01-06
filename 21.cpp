//21.栈的压入、弹出序列
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<int> st;
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int j = 0;
		int k = -1;
		for (int i = popV.size()-1; i>=0 ; i--)
		{
			
			if(j>=pushV.size())
			{
				if (st[k] != popV[i])return false;
				k--;
			}
			else
			{
				while (j<pushV.size()&&pushV[j]!=popV[i])
				{
					st.push_back(pushV[j]);
					k++;
					j++;
				}
				if (j >= pushV.size())
				{
					i++;
				}
				j++;

			}
		}
		return true;
	}
};

int main()
{
	vector<int> popV, pushV;
	/*for (int i = 1; i < 6; i++)
	{
		pushV.push_back(i);
		popV.push_back(i);
	}
	popV[4] = 4; popV[3] = 5; */
	popV.push_back(2);
	pushV.push_back(1);

	Solution solver;
	solver.IsPopOrder(pushV, popV);
	return 0;
}