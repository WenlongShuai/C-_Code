#include <iostream>

using namespace std;

#include <vector>
#include <iterator>
#include <algorithm>

class Person
{
public:
	Person(string name, int age):m_Name(name), m_Age(age)
	{

	}

	string m_Name;
	int m_Age;

};


void myPrintClass(Person p)
{
	cout<<"姓名:"<<p.m_Name<<" 年龄:"<<p.m_Age<<endl;
}

int main()
{
	//vector存放自定义数据类型
	//创建一个vector容器对象

	vector<Person> v;

	//创建Person类的对象
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);


	//使用尾插法向容器插入数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//第一种遍历方式
	vector<Person>::iterator itBegin = v.begin();  //起始迭代器,返回指向容器第一个元素的指针
	vector<Person>::iterator itEnd = v.end(); //结束迭代器,返回指向容器最后一个元素下一个位置的指针
	while(itBegin != itEnd)
	{
		// cout<<"姓名:"<<itBegin->m_Name<<" 年龄:"<<itBegin->m_Age<<endl; //使用指针的方式访问类成员属性
		cout<<"姓名:"<<(*itBegin).m_Name<<" 年龄:"<<(*itBegin).m_Age<<endl; //使用指针指向的内容方式访问类成员属性
		itBegin++;
	}


	//第二种遍历方式
	for(vector<Person>::iterator it = v.begin();it < v.end();it++)
	{
		cout<<"姓名:"<<(*it).m_Name<<" 年龄:"<<(*it).m_Age<<endl;
	}

	//第三种遍历方式,利用STL提供的遍历算法
	for_each(v.begin(), v.end(), myPrintClass);


	//vector存放自定义数据类型指针
	vector< Person* > v2;

	//创建Person类的对象
	Person p6("aaa", 10);
	Person p7("bbb", 20);
	Person p8("ccc", 30);
	Person p9("ddd", 40);
	Person p10("eee", 50);

	//使用尾插法向容器插入数据
	v2.push_back(&p6);
	v2.push_back(&p7);
	v2.push_back(&p8);
	v2.push_back(&p9);
	v2.push_back(&p10);

	//迭代器遍历容器
	for(vector<Person*>::iterator it = v2.begin();it<v2.end();it++)
	{
		// cout<<"-->姓名:"<<(*it)->m_Name<<" 年龄:"<<(*it)->m_Age<<endl;
		cout<<"-->姓名:"<<(**it).m_Name<<" 年龄:"<<(**it).m_Age<<endl;
	}


	return 0;
}