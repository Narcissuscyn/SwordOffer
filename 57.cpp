//57.二叉树的下一个结点
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)return NULL;
		TreeLinkNode*temp=NULL,*temp1=NULL;
		if (pNode->right != NULL)
		{
			temp = pNode->right;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			return temp;
		}
		else if(pNode->next!=NULL)
		{

			temp= pNode->next,temp1 = pNode;
			while (temp != NULL&&temp->left != temp1)
			{
				temp1 = temp;
				temp = temp->next;
			}

		}

		return temp;
	}
};