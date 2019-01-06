//27.字符串的排列(重要，有变种)
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:

	vector<string> s;
	int cur_pos = -1;
	bool isEqual = true;
	vector<string> Permutation(string str) {
		if (str.size() == 0)return s;
		cur_pos++;
		if (cur_pos == str.size() - 1)
		{
			s.push_back(str);
		}
		else
		{
			for (int i = cur_pos; i < str.size(); i++)
			{
				bool isSwap = true;
				for (int j = cur_pos; j < i; j++)
				{
					if (str.at(j) == str.at(i))isSwap = false;
				}
				if (isSwap)
				{
					char temp = str.at(i);
					//swap
					str.at(i) = str.at(cur_pos);
					str.at(cur_pos) = temp;

					Permutation(str);
					//swap back
					temp = str.at(i);
					str.at(i) = str.at(cur_pos);
					str.at(cur_pos) = temp;
				}
			}

		}
		cur_pos--;

		sort(s.begin(), s.end());
		return s;
	}
};

int main()
{
	Solution solver;
	solver.Permutation("abc");
	return 0;
}