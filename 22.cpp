//22.从上到下打印二叉树
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
	bool flag=false;
	//vector<int> PrintFromTopToBottom(TreeNode* root) {
	//	vector<int> result;
	//	if (root == NULL)return result;
	//	if (!flag)
	//	{
	//		result.push_back(root->val);
	//		flag = true;
	//	}
	//	if (root->left != NULL)result.push_back(root->left->val);
	//	if (root->right != NULL)result.push_back(root->right->val);

	//	vector<int> temp=PrintFromTopToBottom(root->left);
	//	result.insert(result.end(), temp.begin(), temp.end());

	//	temp=PrintFromTopToBottom(root->right);
	//	result.insert(result.end(), temp.begin(), temp.end());
	//	return result;
	//}

	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		if (root == NULL)return result;
		queue<TreeNode*>queue_tree;
		queue_tree.push(root);

		while (!queue_tree.empty())
		{
			TreeNode* pNode = queue_tree.front();
			queue_tree.pop();

			result.push_back(pNode->val);
			if (pNode->left != NULL)
			{
				queue_tree.push((pNode->left));
			}
			if (pNode->right != NULL)
			{
				queue_tree.push(pNode->right);
			}

		}
		return result;
	}
};
int main()
{
	Solution solver;
	return 0;
}