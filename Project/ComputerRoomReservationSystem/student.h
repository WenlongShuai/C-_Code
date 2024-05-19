#pragma once

#include <iostream>

using namespace std;

class Student
{
public:
	Student();
	~Student();

	void setStudentNum(string num);

	void setStudentName(string name);

	void setStudentPassword(string password);

	string getStudentNum();

	string getStudentName();

	string getStudentPassword();

	void showSubMenu();

	void enterStudentScreen();

private:
	string studentNum;
	string studentName;
	string studentPassword;
};

