//14.链表中倒数第k个节点
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL||pListHead->next==NULL)
		{
			return NULL;
		}
		ListNode* node_k= pListHead->next, *nex= pListHead->next;

		int interval = 0;

		while (nex->next!=NULL)
		{
			nex = nex->next;
			interval ++;
		}
		if (interval < k-1)
		{
			return NULL;
		}
		else
		{
			while (interval>k-1)
			{
				node_k = node_k->next;
				interval--;
			}
		}		
		return node_k;
	}
	//15.反转链表
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
			return pHead;
		ListNode*temp, *tail=pHead->next,*pre=pHead;
		while (tail->next != NULL)
		{
			temp = tail->next;
			tail->next = pre;
			pre = tail;
			tail = temp;
		}
		tail->next = pre;
		pHead->next = NULL;
		return tail;
	}
	//16.合并两个排序链表

	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL &&pHead2 == NULL)
			return NULL;

		if (pHead1 == NULL)return pHead2;
		if (pHead2 == NULL) return pHead1;
		ListNode*temp_big, *temp_small,*final, *temp=NULL;

		if (pHead1->val < pHead2->val)
		{
			temp_big = pHead2;
			temp_small = pHead1;
		}
		else
		{
			temp_big = pHead1;
			temp_small = pHead2;
		}
		final = temp_small;
		
		while (temp_small!=NULL)
		{

			while (temp_small!=NULL &&temp_small->val<=temp_big->val)
			{
				temp = temp_small;
				temp_small = temp_small->next;
			}
			if (temp_small != NULL)
			{
				temp->next = temp_big;
				temp=temp_small;
				temp_small = temp_big;
				temp_big = temp;
			}
		}
		if (temp_big != NULL)
		{
			temp->next = temp_big;
		}
		return final;
	}
};

int main()
{
	Solution solver;
	ListNode*head= new ListNode(0), *tail = NULL;
	//head->next = new ListNode(1);
	tail = head;
	for (int i = 1; i <= 6; i++)
	{
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	ListNode*head1 = new ListNode(3);
	//head->next = new ListNode(1);
	tail = head1;
	for (int i = 4; i <= 5; i++)
	{
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	//solver.FindKthToTail(head, 5);
	ListNode* result=solver.Merge(head, head1);
	return 0;
}