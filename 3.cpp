	//3.从尾到头打印链表
//C++
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> a,b;
		if (head == NULL)
		{
			return a;
		}
		ListNode* temp = head;
		while (temp!=NULL)
		{
			cout << temp->val;
			a.push_back(temp->val);
			temp = temp->next;
		}
		for (int i = a.size()-1; i >=0 ; i--)
		{
			b.push_back(a[i]);
		}
		return b;
	}

//python
# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s=s.split(' ')
        s = '%20'.join(s)
        return s

a=Solution()
print(a.replaceSpace("We Are Happ"))