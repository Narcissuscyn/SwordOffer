//25.复杂链表的复制(未通过)
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;


struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
label(x), next(NULL), random(NULL) {
}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL) return NULL;
		RandomListNode* head =NULL,*cur_p=pHead,*temp=NULL,*temp1;
		while (cur_p!=NULL)
		{
			temp = cur_p->next;
			cur_p->next = new RandomListNode(cur_p->label);
			cur_p->next->next = temp;
			cur_p = temp;
		}
		cur_p = pHead;
		while (cur_p != NULL)
		{
			temp = cur_p->next;
			if (cur_p->random != NULL)temp->random = cur_p->random->next;
			cur_p = temp->next;

		}
		cur_p = pHead;
		head = pHead->next;
		temp = head;
		while (temp->next !=NULL)
		{
			cur_p->next = temp->next;
			cur_p = cur_p->next;
			temp->next = temp->next->next;
			temp = temp->next;
		}
		return head;
	}
};

int main()
{
	Solution solver;
	RandomListNode* pHead=new RandomListNode(0),*cur=pHead,*temp;
	for (int i = 1; i < 5; i++)
	{
		temp = new RandomListNode(i);
		cur->next = temp;
		cur = temp;

	}
	pHead->random = pHead->next->next;
	solver.Clone(pHead);
	return 0;
}