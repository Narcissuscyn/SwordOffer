
	#include<iostream>
	#include <algorithm>
	#include<string>
	#include<vector>
	#include<stack>
	#include<map>
	using namespace std;
	struct Info
	{
		int count;
		int pos;
	};
	bool cmp(const  vector<int>&a, const  vector<int>&b)
	{
		/*return a.size() < b.size();*/
		vector<int>ab, ba;

		ab.insert(ab.end(), a.begin(), a.end());
		ab.insert(ab.end(), b.begin(), b.end());

		ba.insert(ba.end(), b.begin(), b.end());
		ba.insert(ba.end(), a.begin(), a.end());
		bool flag = true;
		for (int i = 0; i < ab.size(); i++)
		{
			if (ab[i] != ba[i])
			{
				if (ab[i] > ba[i])
				{
					flag = false;
				}
					break;
			}
			
		}
		return flag;
	}
	class Solution {
	public:
		//28.数组中出现次数超过一半的数
		int a[10000] = {0};
		int MoreThanHalfNum_Solution(vector<int> numbers) {
			for (int i = 0; i < numbers.size(); i++)
			{
				a[numbers.at(i)]++;
				if (a[numbers.at(i)] > (numbers.size() / 2))return numbers.at(i);
			}
			return 0;
		}
		//29.最小的k个数
		vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
			vector<int> result;
			if (k > input.size())return result;
			for (int i = 0; i < input.size(); i++)
			{
				a[input.at(i)]++;
			}
			int i = 0, count = 0;

			while (count<k)
			{
				if (a[i] != 0)
				{
					count += a[i];
					result.push_back(i);
				}

				i++;
			}
			return result;
		}
		//30.连续子数组的最大和
		int max_val=0;
		int FindGreatestSumOfSubArray(vector<int> array) {
			if (array.size() == 0)return 0;
			max_val = array[0];
			int cur_sum = 0;

			for (int i = 0; i< array.size(); i++)
			{
				cur_sum += array[i];
				if (cur_sum < array[i])cur_sum = array[i];
				if (cur_sum > max_val)max_val = cur_sum;
			}
			return max_val;
		}

		//31.整数中1出现的次数（重要，特别是代码风格，用了很多较好的内建函数）
		int NumberOf1Between1AndN_Solution(int n)
		{
			if (n < 0)return 0;
			char strN[50];
			sprintf(strN, "%d",n);
			return NumberOf1(strN);
		}
		int NumberOf1(const char*strN)
		{
			if (!strN || *strN<'0' || *strN>'9' || *strN == '\0')return 0;
			int first = *strN - '0';
			unsigned int length = static_cast<unsigned int>(strlen(strN));
			//Ò»Î»ÊýµÄÇé¿ö
			if (length == 1 && first == 0)return 0;
			if (length == 1 && first > 0)return 1;


			int numFirstDigit = 0;
			//µÚÒ»Î»ÊýÎª1µÄÇé¿ö
			if (first > 1)numFirstDigit = PowerBase10(length - 1);
			else if(first==1)//Ê£ÏÂÎ»ÊýµÄÇé¿ö
			{ 
				numFirstDigit = atoi(strN + 1) + 1;
			}
			int numOfOtherDigits = first*(length - 1)*PowerBase10(length - 2);
			int numRecursive = NumberOf1(strN + 1);

			return numFirstDigit + numOfOtherDigits + numRecursive;
		}
		int PowerBase10(unsigned int n)
		{
			int result = 1;
			for (unsigned int i = 0; i < n; i++)
			{
				result *= 10;
			}
			return result;
		}
		//32.把数组排成最小的数(自定义sort函数的使用)

		string PrintMinNumber(vector<int> numbers) {
			if (numbers.size() == 0)return "";
			if(numbers.size() == 1)return to_string(numbers[0]);

			vector<vector<int>> my_number;
			my_number.resize(numbers.size());

			int max_len = 0;
			for (int i = 0; i < numbers.size(); i++)
			{
				char strN[50];
				sprintf(strN, "%d", numbers[i]);
				for (int j=0;strN[j]!='\0';j++)
				{
					my_number[i].push_back(strN[j]-'0');
				}
				if (my_number[i].size() > max_len)max_len = my_number[i].size();
			}

			sort(my_number.begin(), my_number.end(), cmp);
			string result;
			for (int i = 0; i < my_number.size(); i++)
			{
				for (int j = 0; j < my_number[i].size(); j++)
				{
					result += to_string(my_number[i][j]);
				}
			}
			return result;
		}

		//33.第n个丑数
		int GetUglyNumber_Solution(int index) {
			if (index <= 0)return 0;

			int* pUglyNumbers = new int[index];
			pUglyNumbers[0] = 1;
			int nextIdx = 1;
			int *pUgly2 = pUglyNumbers;//Ö¸Ïòµ±Ç°Î»ÖÃ
			int *pUgly3 = pUglyNumbers;
			int *pUgly5 = pUglyNumbers;
			while (nextIdx<index)
			{

				pUglyNumbers[nextIdx] = Min(*pUgly2*2,*pUgly3*3,*pUgly5*5);
				//找到小于pUglyNumbers[nextIdx]分别乘2,3,5的丑数，也就是乘2,3,5离pUglyNumbers[nextIdx]最近的丑数
				while (*pUgly2*2<=pUglyNumbers[nextIdx])
				{
					++pUgly2;
				}
				while (*pUgly3 * 3 <= pUglyNumbers[nextIdx])
				{
					++pUgly3;
				}
				while (*pUgly5 * 5 <= pUglyNumbers[nextIdx])
				{
					++pUgly5;
				}
				nextIdx++;
			}
			int ug_num = pUglyNumbers[nextIdx - 1];
			delete[]pUglyNumbers;
			return ug_num;
		}


		int Min(int a, int b, int c)
		{
			int min = (a < b) ? a : b;
			min = (min < c) ? min : c;
			return min;
		}
		//34.第一个只出现一次的字符（时空平衡）

		map<char, Info> m;
		int FirstNotRepeatingChar(string str) {
			if (str.size() == 0)return -1;
			std::map<char, Info>::iterator it;
			for (int i = 0; i < str.size(); i++)
			{
				it = m.find(str.at(i));
				if (it != m.end())
					m[str.at(i)].count++;
				else
				{
					m[str.at(i)].count = 1;
					m[str.at(i)].pos = i;
				}
			}
			int pos= 10000;
			for (it = m.begin(); it != m.end(); it++)
			{
				if (it->second.count == 1)
				{
					if (it->second.pos < pos)pos = it->second.pos;
				}
			}
			return pos;
		}

		//35.数组中的逆序对（归并排序）
		int InversePairs(vector<int> data) {
			if (data.size() == 0)return 0;
			vector<int>copy;
			copy.insert(copy.end(), data.begin(), data.end());
			long long result= getInverseCount(data, copy, 0, data.size() - 1) % 1000000007;
			return result;

		}
		long long getInverseCount(vector<int>&data , vector<int>&copy, int start, int end)
		{
	
			if (start == end) {
				copy[start]=data[start];
				return 0;
			}
			int len = (end - start) / 2;
			long long left = getInverseCount(copy, data, start, start + len);
			long long right = getInverseCount(copy, data, start + len + 1, end);

			//¹é²¢ÅÅÐò
			int i = start + len;
			int j = end;
			int idx_sorted = end;
			long long count = 0;
			while (i >= start&&j >= start + len + 1)
			{
				if (data[i] > data[j])
				{
					copy[idx_sorted] = data[i];
					i--;
					idx_sorted--;
					count += j - start - len;
				}
				else
				{
					copy[idx_sorted]= data[j];
					j--;
					idx_sorted--;
				}
			}

			for (; i >= start; i--)
			{
				copy[idx_sorted] = data[i];
				idx_sorted--;
			}
			for (; j >= start + len + 1; j--)
			{
				copy[idx_sorted] = data[j];
				idx_sorted--;
			}

			return left + right + count;
		}
	};
	
	int main()
	{
		Solution solver;

		vector<int>a;
		a.push_back(7);
		a.push_back(5);
		a.push_back(6);
		a.push_back(4);
		//a.push_back(0);
		//a.push_back(5);
		//a.push_back(6);
		//a.push_back(7);
		//solver.PrintMinNumber(a);
		//int result = solver.FirstNotRepeatingChar("AAaBBbAsca");
		int result=solver.InversePairs(a);
		return 0;
	}