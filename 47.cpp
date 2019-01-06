
//47.求1+2+3+……+n（不能使用部分操作）
//递归方法
class Solution {
public:
	int Sum_Solution(int n) {
		if (n == 1)return 1;
		return n + Sum_Solution(n - 1);
	}
};

//
//
//构造函数法(循环角度)
class Temp
{
public:
	Temp() { ++N; Sum += N; }//在构造函数里面实现每次加运算
	~Temp();
	static void Reset() { N = 0, Sum = 0; }//注意函数和变量都设置成静态的，能通过类调用。
	static int GetSum() { return Sum; }
private:
	static int N;
	static int Sum;
};
int Temp::N = 0;
int Temp::Sum = 0;
Temp::~Temp()
{
}
class Solution {
public:
	int Sum_Solution(int n) {
		Temp::Reset();
		Temp*a = new Temp[n];//调用n次构造函数
		delete a;
		a = NULL;
		return Temp::GetSum();
	}
};

//虚函数方法(递归角度：c++)


class A;
A* Array[2];

class A
{
public:
	A();
	~A();
	virtual int sum(int n) { return 0; }
private:

};

A::A()
{
}

A::~A()
{
}


class B:public A
{
public:
	B();
	~B();
	virtual int sum(int n)
	{
		return Array[!!n]->sum(n - 1) + n;//ÕâÀïÓÐ¸ö¼¼ÇÉ:n>0,!!n=1,·ñÔòn==0,Ôò!!n=0;¸ù¾Ý0ºÍ1µÄ±êÊ¶À´ÅÐ¶Ïµ÷ÓÃAµÄº¯Êý»¹ÊÇBµÄº¯Êý
	}
private:

};

B::B()
{
}

B::~B()
{
}

class Solution {
public:
	int Sum_Solution(int n) {
		A a;
		B b;
		Array[0] = &a;
		Array[1] = &b;

		int value = Array[1]->sum(n);
		return value;
	}
};


//函数指针法
typedef int(*fun)(int);
int terminator(int n) { return 0; }
int sum(int n)
{
	static fun f[2] = { terminator,sum };
	return n + f[!!n](n - 1);
}
class Solution {
public:
	int Sum_Solution(int n) {

		return sum(n);
	}
};

//模板类型求解
template <int n>struct Sum
{
	enum Value{N=Sum<n-1>::N+n};
};
template<>struct Sum<1>
{
	enum Value { N = 1 };

};

//逻辑与的短路特性(牛客上还有很多新颖的思路)
// 链接：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1
// 来源：牛客网

// 解题思路：
// 1.需利用逻辑与的短路特性实现递归终止。 2.当n==0时，(n>0)&&((sum+=Sum_Solution(n-1))>0)只执行前面的判断，为false，然后直接返回0；
// 3.当n>0时，执行sum+=Sum_Solution(n-1)，实现递归计算Sum_Solution(n)。
    public int Sum_Solution(int n) {
        int sum = n;
        boolean ans = (n>0)&&((sum+=Sum_Solution(n-1))>0);
        return sum;
    }