
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#include<map>



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
	//58.对称的二叉树
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)return true;
		return symmetrical(pRoot->left,pRoot->right);
	}
	bool symmetrical(TreeNode*left, TreeNode*right)
	{
		if ((!left) && (!right)) return true;
		if (!(left)||!(right))return false;
		return (left->val == right->val) && (symmetrical(left->left, right->right) && symmetrical(left->right, right->left));
	}

	//59.按Z字型顺序打印二叉树
	vector<vector<int> > Print(TreeNode* pRoot) {

		int depth = 0;

		vector<vector<int> > result;
		if (pRoot == NULL)return result;
		vector<TreeNode*>a;
		a.push_back(pRoot);
		print_level(a, depth, result);
		return result;
	}
	void print_level(vector<TreeNode*>a,int depth, vector<vector<int> >&result)
	{
		if (a.size() == 0)return;
		vector<int>level;
		vector<TreeNode*> temp;
		if (depth % 2 == 0)
		{
			for (int i = 0; i < a.size(); i++)
			{
				level.push_back(a[i]->val);
				if (a[i]->left != NULL)temp.push_back(a[i]->left);
				if (a[i]->right != NULL)temp.push_back(a[i]->right);
			}
		}
		else
		{
			for (int i = a.size()-1; i>=0; i--)
			{
				level.push_back(a[i]->val);
			}
			for (int i = 0; i < a.size(); i++)
			{

				if (a[i]->left != NULL)temp.push_back(a[i]->left);
				if (a[i]->right != NULL)temp.push_back(a[i]->right);
			}
		}
		depth++;
		result.push_back(level);
		print_level(temp,depth,result);
	}

	//60.把二叉树打印成多行
	vector<vector<int> > Print(TreeNode* pRoot) {
		int depth = 0;

		vector<vector<int> > result;
		if (pRoot == NULL)return result;
		vector<TreeNode*>a;
		a.push_back(pRoot);
		print_level1(a, depth, result);
		return result;
	}
	void print_level1(vector<TreeNode*>a, int depth, vector<vector<int> >&result)
	{
		if (a.size() == 0)return;
		vector<int>level;
		vector<TreeNode*> temp;
		for (int i = 0; i < a.size(); i++)
		{
			level.push_back(a[i]->val);
			if (a[i]->left != NULL)temp.push_back(a[i]->left);
			if (a[i]->right != NULL)temp.push_back(a[i]->right);
		}
		result.push_back(level);
		depth++;
		print_level1(temp, depth, result);
	}

	char* Serialize(TreeNode *root) {
		if (root == NULL)return NULL;
		string str;
		getSerialize(root, str);
		char *ret = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++) {
			ret[i] = str[i];
		}
		ret[i] = '\0';
		return ret;
		//char*a= (char*)str.c_str() ;
		//return a;
	}

	//61.序列化二叉树
	void  getSerialize(TreeNode*root, string& str)
	{
		if (root == NULL)
		{
			str += '#';
			return;
		}
		str += to_string(root->val);
		str += ',';
		getSerialize(root->left, str);
		getSerialize(root->right, str);

	}

		TreeNode* Deserialize(char *str) {
		if (str == NULL)
			return NULL;
		TreeNode *ret = Deserialize(&str);

		return ret;
	}
	TreeNode* Deserialize(char **str) {
		TreeNode*root;
		if (**str == '#') {
			++(*str);
			return NULL;
		}
		int num = 0;
		while ((**str)!='\0'&&(**str)!=',')
		{
			num = num * 10 + ((**str) - '0');
			++(*str);
		}
		root = new TreeNode(num);
		if (**str == '\0')return root;
		++(*str);
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}

	//62.二叉搜索树的第k个节点
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{

		if (pRoot == NULL || k<1)return NULL;
		vector<TreeNode*>a;
		midNode(pRoot, a);
		if (k >a.size())return NULL;
		return a[k - 1];
	}

	//63.数据流中的中位数
	void midNode(TreeNode*p, vector<TreeNode*>&a)
	{
		if (p == NULL)return;
		midNode(p->left, a);
		a.push_back(p);
		midNode(p->right, a);
	}
	priority_queue<int, vector<int>, less<int> > p;
	priority_queue<int, vector<int>, greater<int> > q;
	void Insert(int num) {
		if (p.empty() || num <= p.top()) p.push(num);
		else q.push(num);
		if (p.size() == q.size() + 2) q.push(p.top()), p.pop();
		if (p.size() + 1 == q.size()) p.push(q.top()), q.pop();
	}
	double GetMedian() {
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
	}

	//64.栈和队列 滑动窗口的最大值
	//滑动窗口的最大值

std::vector<int> maxWindows(const std::vector<int> &nums,unsigned int size)
{
	std::vector<int> res;

	std::deque<int> dq;//保存的是nums的索引
	if(nums.size()<=0||nums.size()<size||size<1)return res;

	for(unsigned int i=0;i<size;i++)
	{
		if(!dq.empty()&&nums[i]>nums[dq.back()])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(unsigned int i=size;i<nums.size();i++)
	{
		res.push_back(nums[dq.front()]);

		while(!dq.empty()&&nums[i]>nums[dq.back()])
		{
			dq.pop_back();
		}
		while(!dq.empty()&&dq.front()<=i-size)
		{
			dq.pop_front();
		}
		dq.push_back(i);
	}
	res.push_back(nums[dq.front()]);
	return res;
}

	//65.矩阵中的路径
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		bool* mat_flag = new bool[rows*cols]{false};
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i*cols+j] == str[0])
				{
					if (path(matrix, mat_flag, rows, cols, i, j, 0, str))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	bool path(char* matrix,bool*mat_flag, int rows, int cols, int i, int j, int char_pos, char*str)
	{
		if (str[char_pos] == '\0')return true;
		if ((!mat_flag[i*cols + j])&&(str[char_pos] == matrix[i*cols + j]))
		{
			if (str[char_pos+1] == '\0')return true;
			mat_flag[i*cols + j] = true;
			bool up=false, down=false, left=false, right=false;
			if (i - 1 >= 0)up = path(matrix, mat_flag, rows, cols, i - 1, j, char_pos + 1, str);
			if (i + 1 < rows)down = path(matrix, mat_flag, rows, cols, i + 1, j, char_pos + 1, str);
			if(j-1>=0)left= path(matrix, mat_flag, rows, cols, i, j-1, char_pos + 1, str);
			if(j+1<cols)right= path(matrix, mat_flag, rows, cols, i, j+1, char_pos + 1, str);
			if (up || down || right || left)return true;
			mat_flag[i*cols + j] = false;

		}
		return false;
	}
	//66.机器人的运动范围
	int movingCount(int threshold, int rows, int cols)
	{
		bool*mat_flag = new bool[rows*cols]{ false };
		move(mat_flag, threshold, rows, cols, 0, 0);
		int count = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				count += mat_flag[i*cols+j];
			}
		}

		return count;
	}

	void move(bool * mat_flag, int thresh, int rows, int cols, int i, int j)
	{
		if (i<rows&&j<cols&&mat_flag[i*cols + j]!=true&&isEnter(i, j, thresh))
		{
			mat_flag[i*cols + j] = true;
			if (i - 1 >= 0)move(mat_flag, thresh, rows, cols, i - 1, j);
			if (i + 1 < rows)move( mat_flag, thresh, rows, cols, i + 1, j);
			if (j - 1 >= 0)move(mat_flag, thresh, rows, cols, i, j - 1);
			if (j + 1 < cols)move( mat_flag, thresh, rows, cols, i, j + 1);
		}
	}

	bool isEnter(int i, int j,int thresh)
	{
		int sum = 0;
		while (i!=0)
		{
			sum += i % 10;
			i /= 10;
		}
		while (j!=0)
		{
			sum += j % 10;
			j /= 10;
		}
		return thresh>=sum;
	}
};

int main()
{
	Solution solver;
	////ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGSSGGFIECVAASABCEHJIGQEM
	//char* matrix = new char[41];
	//matrix[40] = '\0';
	//char*str=new char[23];
	//str[22] = '\0';
	//for (int i = 0; i < 40; i++)
	//{
	//	cin >> matrix[i];
	//}
	//for (int i = 0; i < 22; i++)
	//{
	//	cin >> str[i];
	//}

	//solver.hasPath(matrix, 5,8, str);
	solver.movingCount(5, 10, 10);
	return 0;
}
