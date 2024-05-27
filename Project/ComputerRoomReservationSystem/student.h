#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
// #include <management.h>


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

	void requestAnAppointment();

	void viewReservations();

	void cancelTheReservation();

	void viewAllReservations();

private:
	string studentNum;
	string studentName;
	string studentPassword;

};

