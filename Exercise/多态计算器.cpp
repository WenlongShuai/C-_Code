#include <iostream>
#include <string.h>

using namespace std;

//普通实现计算器类
class Calculator
{
public:

	//如果想要扩展新的功能,需要修改源码.
	//在实际开发中,提倡开闭原则
	//开闭原则:对扩展新功能进行开放,对修改进行关闭.
	int getResult(string oper)
	{
		if(oper == "+")
		{
			return num1+num2;
		}
		else if(oper == "-")
		{
			return num1-num2;
		}
		else if(oper == "*")
		{
			return num1*num2;
		}
		else
		{
			return num1/num2;
		}

	}

	int num1;
	int num2;
};


//多态实现计算器类
//首先实现一个抽象类,什么都不去实现,只写一个虚函数
class AbstractCalculator
{
public:
	//虚函数,什么都不去实现
	virtual int getResult()
	{
		return 0;
	}


	int num1;
	int num2;
};

//加法
class Add:public AbstractCalculator
{
public:

	//重写父类的虚函数
	int getResult()
	{
		return num1+num2;
	}
};

//减法
class Sub:public AbstractCalculator
{
public:
	//重写父类的虚函数
	int getResult()
	{
		return num1-num2;
	}
};

//乘法
class Mul:public AbstractCalculator
{
public:
	int getResult()
	{
		return num1*num2;
	}
};

//除法
class Div:public AbstractCalculator
{
public:
	int getResult()
	{
		return num1/num2;
	}

};

int main()
{
	//多态计算器类
	//1 普通实现计算器类
	Calculator c;
	c.num1 = 20;
	c.num2 = 30;
	cout<<c.num1<<"+"<<c.num2<<"="<<c.getResult("+")<<endl;
	cout<<c.num1<<"-"<<c.num2<<"="<<c.getResult("-")<<endl;
	cout<<c.num1<<"*"<<c.num2<<"="<<c.getResult("*")<<endl;
	cout<<c.num1<<"/"<<c.num2<<"="<<c.getResult("/")<<endl;

	//2 多态实现计算器类
	//使用多态的条件:父类的指针或者引用指向一个子类的对象
	//加法
	AbstractCalculator *abc = new Add;  //在堆区上创建一个对象
	abc->num1 = 20;
	abc->num2 = 50;
	cout<<abc->num1<<"+"<<abc->num2<<"="<<abc->getResult()<<endl;
	//new开辟的空间在使用完之后要释放
	delete abc;

	//减法
	abc = new Sub;
	abc->num1 = 20;
	abc->num2 = 50;
	cout<<abc->num1<<"-"<<abc->num2<<"="<<abc->getResult()<<endl;
	//new开辟的空间在使用完之后要释放
	delete abc;

	//乘法
	abc = new Mul;
	abc->num1 = 2;
	abc->num2 = 5;
	cout<<abc->num1<<"*"<<abc->num2<<"="<<abc->getResult()<<endl;
	//new开辟的空间在使用完之后要释放
	delete abc;

	//除法
	abc = new Div;
	abc->num1 = 100;
	abc->num2 = 50;
	cout<<abc->num1<<"/"<<abc->num2<<"="<<abc->getResult()<<endl;
	//new开辟的空间在使用完之后要释放
	delete abc;
	abc = NULL;



	return 0;
}