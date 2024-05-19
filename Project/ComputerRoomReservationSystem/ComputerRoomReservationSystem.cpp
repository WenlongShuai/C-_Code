#include <iostream>

using namespace std;

#include "interface.h"

int main()
{
	Interface interface;
	int choice = 0;

	do
	{
		interface.showMainMenu();
		cin>>choice;
		switch(choice)
		{
		case 1:
			interface.studentLogin();
			break;
		case 2:
			interface.teacherLogin();
			break;
		case 3:
			interface.managementLogin();
			break;
		case 0:
			interface.exitMenu();
			break;
		default:
			interface.inputError();
			break;
		}

	}while(choice);
	return 0;
}