#pragma once

#include <iostream>

using namespace std;

class Teacher
{
public:
	Teacher();
	~Teacher();

	void setEmployeeNum(string num);

	void setEmployeeName(string name);

	void setEmployeePassword(string passwd);

	string getEmployeeNum();

	string getEmployeeName();

	string getEmployeePassword();

	void showSubMenu();

	void enterTeacherScreen();
private:
	string employeeNum;
	string employeeName;
	string employeePassword;

};