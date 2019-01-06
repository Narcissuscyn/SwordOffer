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
	//55.链表中环的入口节点
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		map<ListNode*, bool>m;
		m[pHead] = true;
		ListNode* temp=pHead->next;
		
		while (temp!=NULL)
		{
			if (m.find(temp) != m.end())return temp;
			m[temp] = true;
			temp = temp->next;
		}

		return NULL;
	}


//56.删除链表中重复的节点
ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)//空节点
			return NULL;
		if (pHead != NULL && pHead->next == NULL)//一个节点
			return pHead;

		ListNode* current;

		if (pHead->next->val == pHead->val) {//需要删除头结点
			current = pHead->next->next;
			while (current != NULL && current->val == pHead->val)//找到和头结点不重复的第一个节点
				current = current->next;
			return deleteDuplication(current);
		}

		else {
			current = pHead->next;
			pHead->next = deleteDuplication(current);
			return pHead;
		}
	}
};
int main()
{
	Solution solver;
	ListNode*pHead = new ListNode(1), *temp;;
	temp = pHead;
	temp->next = new ListNode(2);
	temp = temp->next;
	temp->next = new ListNode(3);
	temp = temp->next;	
	temp->next = new ListNode(3);
	temp = temp->next;
	temp->next = new ListNode(5);
	temp = temp->next;

	solver.deleteDuplication(pHead);
	return 0;
}