#include "student.h"

Student::Student()
{

}

Student::~Student()
{

}

void Student::setStudentNum(string num)
{
	this->studentNum = num;
}

void Student::setStudentName(string name)
{
	this->studentName = name;
}

void Student::setStudentPassword(string password)
{
	this->studentPassword = password;
}

string Student::getStudentNum()
{
	return this->studentNum;
}

string Student::getStudentName()
{
	return this->studentName;
}

string Student::getStudentPassword()
{
	return this->studentPassword;
}


void Student::showSubMenu()
{
	cout<<"----------------------------"<<endl;
	cout<<"------------学生界面---------"<<endl;
	cout<<"---------1、申请预约----------"<<endl;
	cout<<"---------2、查看预约----------"<<endl;
	cout<<"---------3、取消预约----------"<<endl;
	cout<<"---------4、查看所有预约-------"<<endl;
	cout<<"---------5、注销登录----------"<<endl;
	cout<<"-----------------------------"<<endl;
}