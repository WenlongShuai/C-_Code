#include "teacher.h"

Teacher::Teacher()
{

}
Teacher::~Teacher()
{

}

void Teacher::setEmployeeNum(string num)
{
	this->employeeNum = num;
}

void Teacher::setEmployeeName(string name)
{
	this->employeeName = name;
}

void Teacher::setEmployeePassword(string passwd)
{
	this->employeePassword = passwd;
}

string Teacher::getEmployeeNum()
{
	return this->employeeNum;
}

string Teacher::getEmployeeName()
{
	return this->employeeName;
}

string Teacher::getEmployeePassword()
{
	return this->employeePassword;
}

void Teacher::showSubMenu()
{
	cout<<"----------------------------"<<endl;
	cout<<"------------教师界面---------"<<endl;
	cout<<"---------1、查看所有预约-------"<<endl;
	cout<<"---------2、审核预约-----------"<<endl;
	cout<<"---------3、注销登录----------"<<endl;
	cout<<"-----------------------------"<<endl;
}