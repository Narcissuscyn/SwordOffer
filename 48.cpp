//48.不用加减乘除做加法（只剩下位运算，二进制模拟十进制加法运算）**
class Solution {
public:

	int Add(int num1, int num2)
	{
		int sum=0, carray=0;
		do
		{
			sum = num1^num2;
			carray= (num1&num2) << 1;//进位应该加到下一位上，所以要左移
			num1 = sum;
			num2 = carray;
		} while (num2!=0);//注意可能产生多次进位，所以要用循环
		return sum;
	}
};