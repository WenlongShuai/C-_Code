#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "computerRoom.h"

using namespace std;

class Management
{
public:

	Management();

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

	void ComputerRoomState(int num);

	void logout(void (*fun)());


	multimap<string, map<string, string>> studentPW;
	multimap<string, map<string, string>> teacherPW;
	map<string, string> managementPW;

	ComputerRoom room;


private:
	string managementName;
	string managementPassword;
};


#endif