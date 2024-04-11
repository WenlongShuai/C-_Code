#include <iostream>

using namespace std;

//基类
class Animal
{
public:
	//晚绑定的方法,需要对晚绑定的函数前加一个virtual关键字.加了virtual之后,函数就是虚函数了.
	//相当于虚函数就是晚绑定的方法
	virtual void speak()
	{
		cout<<"animal speak"<<endl;
	}
};

//派生类1
class Dog:public Animal
{
public:

	//重写父类的虚函数
	//函数返回值 函数名 函数形参列表,三个必须完全一样.
	//子类的重写可以加virtual关键字也可以不加.
	void speak()
	{
		cout<<"dog speak"<<endl;
	}
};

//派生类2
class Cat:public Animal
{
public:
	//重写父类的虚函数
	void speak()
	{
		cout<<"cat speak"<<endl;
	}
};


void dowork(Animal &animal)  //Animal &animal = cat/dog.因为在父类和子类之间可以类型转换,不需要强制转换.可以让父类的指针或者引用直接指向子类对象.
{
	//为什么不管我们传入的对象是cat还是dog,都会去调用Animal类的speak函数.因为这里出现了早绑定的概念.
	//早绑定:地址早绑定,在编译器期间就确定了函数的地址.函数地址一旦确定,不管后面传入的对象是什么,他都会调用animal对象下的speak函数.
	//为了解决,传入什么样的对象,就去调用什么样对象的函数.这里就要引用动态多态,也就是晚绑定.
	//晚绑定:地址晚绑定,在运行期间再去确定函数的地址.在运行期间,传入什么对象那么就去绑定什么对象的函数地址.
	//动态多态满足条件
	//1 必须要有继承关系.
	//2 子类必须要重写父类的虚函数.重写与函数重载是不一样的.
	//动态多态的使用条件
	//父类的指针或者引用指向子类对象.
	animal.speak();
}

int main()
{
	//多态的基本概念
	Cat cat;
	Dog dog;
	//为什么传入的是cat和dog对象,却执行的Animal类中的speak函数,却不能执行我们传入对象的函数.
	// dowork(cat);//animal speak
	// dowork(dog);//animal speak

	//当把animal类的speak()函数设置为晚绑定之后,函数地址就会在运行期间才会确定,那么传入什么对象,就会去调用什么对象的speak函数.
	dowork(cat);//cat speak
	dowork(dog);//dog speak


	return  0;
}