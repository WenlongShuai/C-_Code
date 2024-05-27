#pragma once

#include <iostream>
#include <fstream>
#include <vector>

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

	void viewAllReservations();

	void auditReservations();


private:
	string employeeNum;
	string employeeName;
	string employeePassword;

};