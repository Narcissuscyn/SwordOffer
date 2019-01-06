	//4.根据先序和中序建立二叉树
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

		if (pre.size() == 1|| vin.size()==1)
		{
			return  new TreeNode(pre[0]);
		}

		int root_val = pre.front();
		TreeNode*root = new TreeNode(root_val);

		vector <int>::iterator it = find(vin.begin(),vin.end(), root_val);
		int nPosition = -1;
		if (it != vin.end())
		{
			nPosition = distance(vin.begin(), it);
		}

		vector<int> l_vin, r_vin;
		vector<int> l_pre,r_pre;
		if (nPosition == 0)
		{
			root->left = NULL;
		}
		else
		{
			l_pre=vector<int>(&pre[1], &pre[nPosition]);
			l_pre.push_back(pre[nPosition]);
			//l_vin=vector<int>(&vin[0], &vin[nPosition]);
			//l_pre.assign(pre.begin(), it);
			l_vin.assign(vin.begin(), it);
			root->left = reConstructBinaryTree(l_pre, l_vin);
			
		}
		if (nPosition == vin.size() - 1)
		{
			root->right = NULL;
		}
		else
		{
			r_pre=vector<int>(&pre[nPosition+1], &pre[pre.size()-1]);
			r_pre.push_back(pre[pre.size() - 1]);
			r_vin.assign(it+1,vin.end() );
			root->right = reConstructBinaryTree(r_pre, r_vin);
		}
		
		return root;
	}