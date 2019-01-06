//树的子结构
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL&&pRoot2 != NULL)
		{
			if (pRoot1->val == pRoot2->val)
			{
				result = isEqueal(pRoot1, pRoot2);
				if (!result)result = HasSubtree(pRoot1->left, pRoot2);
				if (!result)result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;

	}

	bool isEqueal(TreeNode*pRoot1, TreeNode*pRoot2)//HasSubtree call isEqual(p1,p2),p1->val=p2->val;
	{
		if (pRoot2==NULL)
		{
			return true;
		}
		if (pRoot1==NULL)
		{
			return false;
		}
		if (pRoot1->val != pRoot2->val)
			return false;
		return isEqueal(pRoot1->left, pRoot2->left) && isEqueal(pRoot1->right, pRoot2->right);
	}
};

int main()
{
	Solution solver;
	return 0;
}