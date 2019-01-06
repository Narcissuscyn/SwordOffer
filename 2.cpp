//替换空格
	//2 c++
	void replaceSpace(char *str, int length) {
		string a = "";
		int idx = 0;
		for (int i = 0; i < length; i++)
		{

			if (str[i] != ' ')
			{
				//a.push_back(str[i]);
				a.append(sizeof(char), str[i]);
				//cout << (typeid(str[i])== typeid(char));
				idx++;

			}
			else
			{
				idx += 3;
				a.append("%20");
			}
		}
		//str=strcpy(str, a.c_str());

		//str = (char*)a.c_str();
		//cout << str;
	}

//python
'''
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
'''

# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target, array):
        # array=np.array(array)
        # write code here
        if array==[[]]:
            return False
        l = len(array[0])
        row=array.__len__()
        for i in range(row):
            min = 0
            max=l
            pre=-1
            idx=0
            while(pre!=idx):
                idx = int(((min + max)/2))
                pre=idx
                if target < array[i][idx]:
                    max=idx
                    idx =int(((idx+min) / 2))
                elif target > array[i][idx]:
                    min=idx
                    idx =int(( (idx + max) / 2))
                else:
                    return True

        return False

array=[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
solve=Solution()
if solve.Find(7,array):
    print("yes")
else:
    print("No")