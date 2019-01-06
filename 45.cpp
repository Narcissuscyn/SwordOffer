//扑克牌顺子
	bool IsContinuous(vector<int> numbers) {
		int len = numbers.size();
		if (len == 0)return false;
		sort(numbers.begin(), numbers.end(), cmp);
		int interval = 0;
		int count_0 = 0;
		for (int i = 0; i < len - 1; i++)
		{

			if (numbers[i] != 0)
			{
				if (numbers[i + 1] == numbers[i])return false;
				interval += numbers[i + 1] - numbers[i] - 1;
			}
			else
			{
				count_0++;
			}
		}
		if (count_0 >=interval)return true;
		else
		{
			return false;
		}
	}