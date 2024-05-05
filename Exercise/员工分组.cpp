#include <iostream>

using namespace std;

// 案例描述:
// 公司招聘10名员工(ABCDEFGHIJ),10名员工进入公司之后,需要指派员工在哪个部门工作.
// 员工信息有:姓名,工资组成;部门分为:策划,美术,研发.
// 随机给10名员工分配部门和工资.
// 通过multimap进行信息的插入,key表示部门,value表示员工.
// 分部门进行显示.

#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

#define CEHUA 	1
#define MEISHU 	2
#define YANFA 	3

class Employee
{
public:
	Employee(string name, int salary):m_Name(name),m_Salary(salary)
	{
	}
	string m_Name;
	int m_Salary;
};

void createEmployee(vector<Employee> &v)
{
	string nameFlag = "ABCDEFGHIJ";
	for(int i = 0;i<10;i++)
	{
		string name = "员工";
		name = nameFlag[i] + name;
		Employee e(name, 0);
		v.push_back(e);
	}

}

void setDepartmentAndSalary(vector<Employee> &v, multimap<int, Employee> &m)
{
	// for(int i = 0;i<10;i++)
	// {
	// 	int department = 1+rand()%3;   //a+rand()%(b+1-a)
	// 	int salary = 1000 + rand()%1000;
	// 	v[i].m_Salary = salary;
	// 	m.insert(make_pair(department, v[i]));
	// }

	for(vector<Employee>::iterator it = v.begin();it != v.end();it++)
	{
		int department = 1+rand()%3;
		int salary = 1000 + rand()%1000;
		(*it).m_Salary = salary;
		m.insert(make_pair(department, *it));
	}
}

void printEmployee(multimap<int, Employee> &m)
{
	// for(multimap<int, Employee>::iterator it = m.begin();it != m.end();it++)
	// {
	// 	if(it->first == 1)
	// 	{
	// 		cout<<"部门:策划"<<" 姓名:"<<it->second.m_Name<<" 工资:"<<it->second.m_Salary<<endl;
	// 	}
	// 	else if(it->first == 2)
	// 	{
	// 		cout<<"部门:美术"<<" 姓名:"<<it->second.m_Name<<" 工资:"<<it->second.m_Salary<<endl;
	// 	}
	// 	else
	// 	{
	// 		cout<<"部门:研发"<<" 姓名:"<<it->second.m_Name<<" 工资:"<<it->second.m_Salary<<endl;
	// 	}
	// }	

	cout<<"策划部门:"<<endl;
	multimap<int, Employee>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for( ;pos != m.end() && index < count; index++, pos++)
	{
		cout<<"姓名:"<<pos->second.m_Name<<"工资:"<<pos->second.m_Salary<<endl;
	}

	cout<<"美术部门:"<<endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for( ;pos != m.end() && index < count; index++, pos++)
	{
		cout<<"姓名:"<<pos->second.m_Name<<"工资:"<<pos->second.m_Salary<<endl;
	}

	cout<<"研发部门:"<<endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for( ;pos != m.end() && index < count; index++, pos++)
	{
		cout<<"姓名:"<<pos->second.m_Name<<"工资:"<<pos->second.m_Salary<<endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建10名员工
	vector<Employee> v;
	createEmployee(v);

	//为10名员工分配部门和工资
	multimap<int, Employee> m;
	setDepartmentAndSalary(v,m);

	//分部门显示
	printEmployee(m);

	return 0;
}