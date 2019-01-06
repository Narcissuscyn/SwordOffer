
#1.二维数组中的查找
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