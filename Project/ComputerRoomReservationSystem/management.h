#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class Management
{
public:

	// Management();

	~Management();

	void setManagementName(string name);

	void setManagementPassword(string passwd);

	string getManagementName();

	string getManagementPassword();

	void showSubMenu();

	void enterManagementScreen();

	void addingAnAccount();

	void addStudentAccount();

	void addTeacherAccount();

	void addManagementAccount();

	void viewAccount();

	void viewStudentAccount();

	void viewTeacherAccount();

	void viewManagementAccount();

	void viewComputerRoom();

	void logout(void (*fun)());


	map<string, string> studentPW;
	map<string, string> teacherPW;
	map<string, string> managementPW;


private:
	string managementName;
	string managementPassword;
};


#endif