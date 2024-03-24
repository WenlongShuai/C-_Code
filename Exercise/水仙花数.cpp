#include <iostream>

using namespace std;

// 水仙花数是指一个3位数，他的每位数字的3次幂之和等于他本身。
// 153 ====> 1^3+5^3+3^3
//利用do...while循环实现所有3位数中的水仙花数

int main()
{
	int num = 100;

	do
	{
		int a = num % 10;
		int b = num / 10 % 10;
		int c = num / 100;
		if(a*a*a + b*b*b + c*c*c == num)
		{
			cout<<num<<endl;
		}
		num++;
	}while(num < 1000);

	return 0;
}