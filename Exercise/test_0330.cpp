#include <iostream>


using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int& func()
{
	int b = 10;
	return b;
}

int& func2()
{
	static int a = 20;
	return a;
}


int main()
{
	//使用引用
	// 数据类型 &别名 = 原名
	//注意事项
	//1、引用必须初始化
	//2、引用一旦初始化，后面就不能改变

	// int a = 10;
	
	// // int &b;//error
	// int &b = a;
	// int c = 20;
	// b = c;


	// // b = 30;

	// cout<<a<<endl;
	// cout<<b<<endl;


	// int a = 10;
	// int b = 20;

	// swap(a,b);
	// cout<<"a == "<<(int)a<<endl;
	// cout<<"b == "<<(int)b<<endl;

	//引用作函数的返回值
	//1、不能返回局部变量的引用

	//2、如果函数作为左值，那么必须返回引用

	// int &ref = func();
	// cout<<ref<<endl;

	int &ret = func2();
	cout<<ret<<endl;
	int c = 50;
	ret = c;
	cout<<ret<<endl;
	int &ret2 = func2();
	ret = 100;
	cout<<ret2<<endl;


	return 0;
}