#include <iostream>
#include "myArray.cpp"
#include <string>

using namespace std;

//案例描述：实现一个通用的数组类
// 要求：
// 1、可以对内置数据类型和自定义数据类型的数据进行存储。
// 2、将数组的数据存储在堆区
// 3、构造函数中可以传入数组的容量
// 4、提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// 5、提供尾删法和尾插法对数组进行删除和增加
// 6、可以通过下标的方式访问数组的元素
// 7、可以获取数组中当前元素个数和数组容量

class Person
{
public:

	//这里为什么要写无参和有参构造
	//因为写了有参构造之后,编译器就没有默认的无参构造,但是后面类模板传入模板参数列表时,需要用到无参构造函数.
	Person()
	{

	}
	Person(string name, int age)//:m_Name(name),m_Age(age)
	{
		m_Name = name;
		m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printInt(MyArray<int> &arr)
{
	for(int i = 0;i<arr.getElementCount();i++)
	{
		cout<<arr[i]<<endl;
	}
}

void printPerson(MyArray<Person> &arr)
{
	for(int i = 0;i<arr.getElementCount();i++)
	{
		cout<<"姓名:"<<arr[i].m_Name<<"年龄:"<<arr[i].m_Age<<endl;
	}
}

int main()
{
	cout<<"first:"<<endl;
	MyArray<int> arr(10);
	//尾插
	for(int i = 0;i<5;i++)
	{
		arr.tailInsert(i);
	}

	//打印数组元素
	printInt(arr);
	//元素个数
	cout<<arr.getElementCount()<<endl;

	//数组容量
	cout<<arr.getArrayCapacitySize()<<endl;

	cout<<"second:"<<endl;
	MyArray<Person> arr2(10);
	Person p1("zhangsan", 22);
	Person p2("lisi", 34);
	Person p3("wangwu", 28);
	Person p4("zhaoliu", 30);
	Person p5("qiqi", 19);

	//尾插
	arr2.tailInsert(p1);
	arr2.tailInsert(p2);
	arr2.tailInsert(p3);
	arr2.tailInsert(p4);
	arr2.tailInsert(p5);


	//打印数组元素
	printPerson(arr2);
	//元素个数
	cout<<arr2.getElementCount()<<endl;

	//数组容量
	cout<<arr2.getArrayCapacitySize()<<endl;


	return 0;
}