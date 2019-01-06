#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
#include<map>
using namespace std;
class Solution {
public:
	//49.把字符串转换成整数
	int StrToInt(string str) {
		int flag = 1;
		int star_pos = 0;
		if (str[0] == '+') { star_pos = 1; }
		if (str[0] == '-') { flag = -1; star_pos = 1; }
		int base = 1;
		long long number = 0;
		for (int i = str.length() - 1; i >= star_pos; i--)
		{
			if (str[i] >= '0'&& str[i] <= '9')
			{
				number += (str[i] - '0')*base;
				base *= 10;
			}
			else
			{
				return 0;
			}
		}
		return number*flag;
	}
	//50	数组中重复的数字
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		map<int, int> m;

		for (int i = 0; i < length; i++)
		{
			if (m.find(numbers[i]) == m.end())
			{
				m[numbers[i]] = 1;
			}
			else
			{
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
	//51.构建乘积数组
	vector<int> multiply(const vector<int>& A) {
		vector<int>b,c,d;
		int len = A.size();
		if (len == 0)return b;
		c.push_back(A[0]);
		d.push_back(A[len-1]);
		for (int i = 1; i < len-1; i++)
		{
			c.push_back(c[i-1]*A[i]);
			d.push_back(A[len - i - 1] * d[i-1]);
		}
		c.push_back(c[len - 2] * A[len - 1]);
		d.push_back(d[len - 2] * A[0]);
		for (int i = 0; i < len; i++)
		{
			if (i == 0)b.push_back(d[len - 1]);
			else if (i == len - 1)b.push_back(c[len - 2]);
			else
			{
				b.push_back(c[i - 1] * d[len - i - 2]);
			}
		}

		return b;
	}
	//52.正则表达式匹配
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
			return false;

		return matchCore(str, pattern);
	}

	bool matchCore(char* str, char* pattern) {
		if (*str == '\0' && *pattern == '\0')
			return true;
		//str不为空，pattern为空时,返回false;反过来则不成立
		if (*str != '\0' && *pattern == '\0')
			return false;
		//当前字符的下一个字符为*时
		if (*(pattern + 1) == '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0')) {//当前字符匹配，则有3种情况：
				//1.aba和ab*a
				//2.abba和ab*a
				//3.aa和aa*a
				//三种情况，只要有一种为真即可
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			}
			else//当前字符不匹配aaa和aab*a
				return matchCore(str, pattern + 2);
		}
		//当前字符的下一个字符不为*时
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);

		return false;
	}

//53.表示数值的字符串
// 链接：https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2
// 来源：牛客网

    bool isNumeric(char* str)
    {
        if (str == NULL)
        return false;
    if (*str == '+' || *str == '-')
        ++str;
    if (*str == '\0')
        return false;
    int x = 0;    //标记整数部分
    int digit = 0; //标记小数点
    int e = 0;     //标记e的状态
    while (*str != '\0')
    {
        //标记整数部分的状态
        if (*str >= '0' && *str <= '9')
        {
            ++str;
            x = 1;
        }
        //小数点
        else if (*str == '.')
        {
            //前面已经出现过小数点或小数点之前存在e，则返回false
            if (digit > 0 || e > 0)
                return false;
            ++str;
            digit = 1;    //标记小数点已经出现过
        }
 
        //e
        else if (*str == 'e' || *str == 'E')
        {
            //e之前没有整数或e已经出现过，则返回false
            if (x == 0 || e > 0)
                return false;
            ++str;
            e = 1;     //标记e表示已经出现过
 
            //e之后可以出现+-号再加整数
            if (*str == '+' || *str == '-')
                ++str;
            //e之后没有数据也不行
            if (*str == '\0')
                return false;
        }
        else
            return false;
    }
    return true;
    }

    //54.字符流中第一个不重复的字符
    class Solution
{
public:
	string s;//用字符串s保存字符流中的字符
	map<int, int>m;//用一个map计数
	//Insert one char from stringstream
	void Insert(char ch)//计数及构造字符串
	{
		s += ch;
		m[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()//查找第一次出现一次的字符,O(n)的时间复杂度
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (m[s[i]] == 1)return s[i];
		}
		return '#';
	}


};
};

int main()
{
	Solution solver;
	solver.match("aaa", "a*");
	return 0;
}