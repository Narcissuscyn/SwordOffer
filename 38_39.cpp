

#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
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
	void create_tree(TreeNode *&root)
	{
		
		char ch;
		if ((ch = getchar()) == '#')root = NULL;//
		else {
			root = new TreeNode(ch-'0');//
			create_tree(root->left);//
			create_tree(root->right);
		}
		return;
	}
	//38.二叉树的深度
	int TreeDepth(TreeNode* p)
	{
		if (p == NULL)
			return 0;
		int h1 = TreeDepth(p->left);
		if (h1 == -2)return -2;
		int h2 = TreeDepth(p->right);
		if (h2 == -2)return -2;
		if (abs(h1 - h2) > 1)return -2;
		if (h1>h2)return (h1 + 1);
		return h2 + 1;
	}


	//39.平衡二叉树
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;
		int h = TreeDepth(pRoot);
		if (h < 0)return false;
		return true;
	}

};
int main()
{
	Solution solver;
	TreeNode *root = NULL;
	solver.create_tree(root);
	bool result = solver.IsBalanced_Solution(root);
	return 0;
}