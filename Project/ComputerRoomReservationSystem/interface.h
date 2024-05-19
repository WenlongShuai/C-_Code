#pragma once

#include <iostream>

using namespace std;

#include "student.h"
#include "teacher.h"
#include "management.h"
#include <fstream>
#include <algorithm>

class Interface
{
public:
	Interface();
	~Interface();


	void showMainMenu();

	void studentLogin();

	void teacherLogin();

	void managementLogin();

	void exitMenu();

	void inputError();

	void loadAllCSV();

	Student student;
	Teacher teacher;
	Management management;

};