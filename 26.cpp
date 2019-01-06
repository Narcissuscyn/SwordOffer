//26.二叉搜索树（BST）与双向链表
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
	TreeNode*head = NULL,*cur=NULL;
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)return NULL;
		if (pRootOfTree->left != NULL)Convert(pRootOfTree->left);
		if (head == NULL)
		{
			head = pRootOfTree;
			cur = head;
		}
		else
		{
			cur->right = pRootOfTree;
			cur->right->left = cur;
			cur = cur->right;
		}
		if (pRootOfTree->right != NULL)Convert(pRootOfTree->right);

		return head;
	}
};


int main()
{
	Solution solver;
	return 0;
}