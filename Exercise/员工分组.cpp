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
	for(int i = 0;i<10;i++)
	{
		int department = 1+rand()%3;   //a+rand()%(b+1-a)
		int salary = 1000 + rand()%1000;
		v[i].m_Salary = salary;
		m.insert(make_pair(department, v[i]));
	}
}

void printEmployee(const multimap<int, Employee> &m)
{
	for(multimap<int, Employee>::const_iterator it = m.begin();it != m.end();it++)
	{
		if(it->first == 1)
		{
			cout<<"部门:策划"<<" 姓名:"<<it->second.m_Name<<" 工资:"<<it->second.m_Salary<<endl;
		}
		else if(it->first == 2)
		{
			cout<<"部门:美术"<<" 姓名:"<<it->second.m_Name<<" 工资:"<<it->second.m_Salary<<endl;
		}
		else
		{
			cout<<"部门:研发"<<" 姓名:"<<it->second.m_Name<<" 工资:"<<it->second.m_Salary<<endl;
		}
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