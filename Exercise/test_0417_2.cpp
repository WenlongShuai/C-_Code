#include <iostream>

using namespace std;

//声明Person类，并且是类模板
template<class T1,class T2>
class Person;

//全局函数类外实现，函数模板。必须要写在Person类之前，因为需要编译器提前知道全局函数的存在，如果写在Person类后面则会报错。
//在这之前要声明一下Person类是一个类模板
template<class T1,class T2>
void printPerson2(Person<T1,T2> p)
{
	cout<<"类外实现全局函数  "<<"姓名："<<p.m_Name<<"年龄："<<p.m_Age<<endl;
}

template<class T1, class T2>
class Person
{
	//全局函数类内实现并作为友元函数
	friend void printPerson(Person<T1,T2> p)
	{
		cout<<"姓名："<<p.m_Name<<"年龄："<<p.m_Age<<endl;
	}
	//全局函数类外实现，类内声明
	// friend void printPerson2(Person<T1,T2> p);//报错。因为这样写只是一个函数声明，而实现的时候是一个函数模板，所以声明和实现不一致。
	//为了解决声明和实现不一致的问题，就要把声明变成函数模板的声明形式。
	//在声明的时候加上空模板参数，让编译器知道这是一个函数模板。
	friend void printPerson2<>(Person<T1,T2> p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};



int main()
{
	//类模板与友元
	//1、类内实现全局函数作友元
	Person<string, int> p("zhangsan", 33);
	printPerson(p);

	//2、类外实现全局函数作友元
	Person<string, int> p2("wangwu", 12);
	printPerson2(p2);

	return 0;
}