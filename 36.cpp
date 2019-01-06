
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
#include<map>
using namespace std;



struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	//36.两个链表的第一个公共节点
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		map<ListNode*, int>m;

		ListNode*a=pHead1, *b=pHead2;

		while (a!=NULL)
		{
			m[a] = 1;
			a = a->next;
		}
		map<ListNode*, int>::iterator it;
		while (b!=NULL)
		{
			it=m.find(b);
			if (it != m.end())
			{
				return b;
			}
			b = b->next;
		}
		return NULL;
	}
	//37.数字在排序数组中出现的次数
	int GetNumberOfK(vector<int> data, int k) {

		int count = 0;
		if (data.size() != 0)
		{
			int min = getMinIdx(data, k, 0, data.size() - 1);
			int max = getMaxIdx(data, k, 0, data.size() - 1);
			if (min != -1 && max != -1)
			{
				count = max - min + 1;
			}
		}
		return count;
	}

	int getMinIdx(vector<int> data, int k, int l,int r)
	{
		if (l > r)return -1;
		int mid = (l + r) / 2;
		if (data[mid] < k) {
			l = mid + 1;
		}
		else if(data[mid]>k)
		{
			r = mid - 1;
		}
		else
		{
			if (mid>0&&data[mid - 1] == k)
			{
				r = mid - 1;
			}
			else
			{
				return mid;
			}
		}
		return getMinIdx(data, k, l, r);
	}
	int getMaxIdx(vector<int> data, int k, int l,int r)
	{
		if (l > r)return -1;
		int mid = (l + r) / 2;
		if (data[mid] < k) {
			l = mid + 1;
		}
		else if (data[mid]>k)
		{
			r = mid - 1;
		}
		else
		{
			if (mid<data.size()-1&&data[mid +1] == k)
			{
				l= mid +1;
			}
			else
			{
				return mid;
			}
		}
		return getMaxIdx(data, k, l, r);

	}

};

int main()
{
	Solution solver;
	vector<int>a;
	//a.push_back(1);
	//a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	solver.GetNumberOfK(a, 3);
	return 0;
}