#include <iostream>


using namespace std;
#include <list>
#include <algorithm>

// 描述：将Person自定义数据类型进行排序，Person中的属性有姓名、年龄、身高。
// 排序规则：按照年龄进行升序，如果年龄相同就按照身高进行排序。

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
	string m_Name;
	int m_Age;
	int m_Height;
};

void printList(const list<Person> &L)
{
	for(list<Person>::const_iterator it = L.begin();it != L.end();it++)
	{
		cout<<"姓名："<<it->m_Name<<"\t年龄："<<it->m_Age<<"\t身高："<<it->m_Height<<endl;
	}
}

bool myCompare(const Person &p1, const Person &p2)
{
	// if(p1.m_Age > p2.m_Age)
	// {
	// 	return false;
	// }
	// else if(p1.m_Age == p2.m_Age)
	// {
	// 	if(p1.m_Height > p2.m_Height)
	// 	{
	// 		return true;
	// 	}
	// 	else
	// 	{
	// 		return false;
	// 	}
	// }
	// else
	// {
	// 	return true;
	// }

	if(p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}


int main()
{
	//创建5个Person对象
	Person p1("zhangsan", 20, 180);
	Person p2("lisi", 18, 175);
	Person p3("wangwu", 18, 182);
	Person p4("zhaoliu", 25, 178);
	Person p5("xiaoqi", 18, 185);

	list<Person> L;

	//使用尾插法将5个对象插入到list容器中
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);

	cout<<"排序前："<<endl;
	printList(L);

	//对list进行排序
	cout<<"排序后："<<endl;
	L.sort(myCompare);
	printList(L);


	return 0;
}