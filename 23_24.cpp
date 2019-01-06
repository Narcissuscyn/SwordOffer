
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
	//23.二叉树的后序遍历序列
	bool flag=false;
	// vector<int> PrintFromTopToBottom(TreeNode* root) {
	// 	vector<int> result;
	// 	if (root == NULL)return result;
	// 	if (!flag)
	// 	{
	// 		result.push_back(root->val);
	// 		flag = true;
	// 	}
	// 	if (root->left != NULL)result.push_back(root->left->val);
	// 	if (root->right != NULL)result.push_back(root->right->val);

	// 	vector<int> temp=PrintFromTopToBottom(root->left);
	// 	result.insert(result.end(), temp.begin(), temp.end());

	// 	temp=PrintFromTopToBottom(root->right);
	// 	result.insert(result.end(), temp.begin(), temp.end());
	// 	return result;
	// }

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

	bool VerifySquenceOfBST(vector<int> sequence) {

		int len = sequence.size();
		if (len == 0)return false;
		int root = sequence[len - 1];
		int root_idx = 0;
		vector<int> right, left;
		for(int i=len-2;i>=0;i--)
		{ 
			if (sequence[i] < root)
			{
				for (; i >= 0; i--)
				{
					if (sequence[i] > root)return false;
					left.push_back(sequence[i]);
				}
			}
			else
			{
				right.push_back(sequence[i]);
			}
		}
		reverse(left.begin(), left.end());
		reverse(right.begin(), right.end());

		if (left.size()!=0&&!VerifySquenceOfBST(left))return false;
		if (right.size() != 0 && !VerifySquenceOfBST(right))return false;

		return true;
	}
//24.二叉树中和为某一值的路径(！有问题)
	vector<vector<int>> path;
	bool comp(vector<int> a, vector<int>b) { return a.size() > b.size(); }
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)return path;

		vector<int>cur_pth;
		int cur_val = 0;
		find_cur_pth(root, expectNumber, cur_val, cur_pth);

		std::sort(path.begin(), path.end(),comp );
		return path;
	}

	void  find_cur_pth(TreeNode* root, int expectNumber,int cur_val,vector<int>cur_pth)
	{
		cur_val += root->val;
		cur_pth.push_back(root->val);
		if (cur_val == expectNumber&&root->left == NULL&& root->right==NULL)
		{
			path.push_back(cur_pth); 
		}
		else if(cur_val<expectNumber)
		{
			if(root->left!=NULL)find_cur_pth(root->left, expectNumber, cur_val, cur_pth);
			if (root->right != NULL)find_cur_pth(root->right, expectNumber, cur_val, cur_pth);
		}
		cur_val -= root->val;
		cur_pth.pop_back();
	}

};
int main()
{
	Solution solver;
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(7);
	vec.push_back(6);
	vec.push_back(9);
	vec.push_back(11);
	vec.push_back(10);
	vec.push_back(8);

	solver.VerifySquenceOfBST(vec);
	return 0;
}