#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	//40.数组中只出现一次的数字
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int and_result=data[0];
		for (int i = 1; i < data.size(); i++)
		{
			and_result ^= data[i];
		}
		*num1 = 0;
		*num2 = 0;
		int idx = findFstIdxOf1(and_result);
		for(int i=0;i<data.size();i++)
		{ 
			if (isIdx1(data[i],idx))
			{
				*num1 ^= data[i];
			}
			else
			{
				*num2 ^= data[i];

			}
		}

	}
	int findFstIdxOf1(int num)
	{
		int idx = 0;
		while (((num&1)==0)&&(idx<8*sizeof(int)))
		{
			num = num >> 1;
			idx++;
		}
		return idx;
	}

	bool isIdx1(int num,int idx)
	{
		num = num >> idx;
		if ((num & 1) == 0)return true;
		return false;
	}
//41.和为S的连续正数序列

	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> sequence;
		if (sum == 0) return sequence;
		int mid = sum / 2+1;
		for (int i =1; i < mid; i++)
		{
			int count = 2;
			int cur_sum = 0;
			while (cur_sum<sum)
			{
				cur_sum = (i + (i + count-1))*count/2;
				if (cur_sum == sum)
				{
					vector<int>cur_seq;
					for (int j = i; j < i + count; j++)
					{
						cur_seq.push_back(j);
					}
					sequence.push_back(cur_seq);
					i++;
					break;
				}
				count++;
			}
		}
		return sequence;
	}
//42.和为S的两个数

	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int>result;
		int beg = 0, end = array.size() - 1;
		while (beg<end)
		{
			int cur_sum = array[beg] + array[end];
			if (cur_sum==sum)
			{
				result.push_back(array[beg]);
				result.push_back(array[end]);
				break;
			}
			if (cur_sum > sum)
			{
				end--;
			}
			else
			{
				beg++;
			}
		}
		return result;
	}
////43.左旋转字符串
	string LeftRotateString(string str, int n) {
		int len = str.length();
		if (len == 0|| n>len)return str;
		return str.substr(n, len - n) + str.substr(0, n);
	}
//44.翻转单词顺序列
	string ReverseSentence(string str) {
		int len = str.length();
		string result;
		for (int i =  len- 1; i >= 0; i--)
		{
			result.push_back(str[i]);
		}
		int gap = 0;
		for (int i = 0; i < len; i++)
		{
			if (result[i] == ' ')
			{
				reverse(result, i -gap,i-1);
				gap = -1;
			}
			if (i == len - 1)
			{
				reverse(result, i - gap, i);
			}
			gap++;
		}
		return result;
	}
	void reverse(string&str,int begin,int end)
	{
		while (begin<end)
		{

			char temp = str[begin];
			str[begin] = str[end];
			str[end] = temp;
			begin++;
			end--;
		}
	}
};
int main()
{
	Solution solver;
	//vector<int>a;
	//a.push_back(2);
	//a.push_back(4);
	//a.push_back(3);
	//a.push_back(6);
	//a.push_back(3);
	//a.push_back(2);
	//a.push_back(5);
	//a.push_back(5);
	//int  b,c;
	//solver.FindNumsAppearOnce(a, &b, &c);
	//solver.FindContinuousSequence(10);
	solver.ReverseSentence("i am a student");
	return 0;
}
