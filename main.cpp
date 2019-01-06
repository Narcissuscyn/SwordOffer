#include<iostream>

#include<string>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		string a = "";
		int idx = 0;
		for (int i = 0; i < length; i++)
		{

			if (str[i] !=' ')
			{
			    a.append("a");
				//a[idx] = str[i];
				idx++;

			}
			else
			{
				idx += 3;
				a.append("%20");
			}
		}
		cout << a;
	}
};

int main()
{
	Solution solver;
	solver.replaceSpace("We Are Happy",12);

	return 0;
}
