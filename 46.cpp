//46.圆圈中最后剩下的数（模拟循环链表或寻求简易思路）

	//int LastRemaining_Solution(int n, int m)
	//{
	//	if (n < 1 || m < 1)return -1;
	//	int last = 0;
	//	for (int i = 2; i < n; i++)
	//	{
	//		last = (last + m) % i;
	//	}
	//	return last;
	//}

	//
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)return -1;

		vector<int>l;
		for (int i = 0; i < n; i++)l.push_back(i);
		int pos = 0;

		while (l.size()!=1)
		{
			int r_pos = pos + m-1 ;
			if (r_pos >=l.size())
			{
				r_pos %= l.size();
			}
			l.erase(l.begin()+r_pos);
			pos =r_pos;
		}
		return l.front();
	}