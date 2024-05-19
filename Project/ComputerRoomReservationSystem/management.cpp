#include "management.h"

// Management::Management()
// {
// 	this->studentPW.clear();
// 	this->teacherPW.clear();
// 	this->managementPW.clear();
// }

Management::~Management()
{

}

void Management::setManagementName(string name)
{
	this->managementName = name;
}

void Management::setManagementPassword(string passwd)
{
	this->managementPassword = passwd;
}

string Management::getManagementName()
{
	return this->managementName;
}

string Management::getManagementPassword()
{
	return this->managementPassword;
}

void Management::showSubMenu()
{
	cout<<"----------------------------"<<endl;
	cout<<"----------管理员界面---------"<<endl;
	cout<<"---------1、添加账号----------"<<endl;
	cout<<"---------2、查看账号----------"<<endl;
	cout<<"---------3、查看机房----------"<<endl;
	cout<<"---------0、注销登录----------"<<endl;
	cout<<"-----------------------------"<<endl;
}

void Management::enterManagementScreen()
{
	int choice = 0;
	do
	{
		showSubMenu();
		cin>>choice;

		switch(choice)
		{
		case 1:
			addingAnAccount();
			break;
		case 2:
			viewAccount();
			break;
		case 3:
			viewComputerRoom();
			break;
		case 0:
			cout<<"注销成功"<<endl;
			break;
		default:
			cout<<"输入有误,请重新输入!"<<endl;
			break;
		}
	}while(choice);
}

void Management::addStudentAccount()
{
	string name = "";
	string passwd = "";
	string num = "";

	cout<<"请输入添加学生的学号:";
	cin>>num;

	cout<<"请输入添加学生的姓名:";
	cin>>name;

	cout<<"请输入添加学生的密码:";
	cin>>passwd;

	ofstream ofs;
	ofs.open("studentPW.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"open studentPW.csv fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<num<<","<<name<<","<<passwd<<","<<endl;
	cout<<"添加成功"<<endl;

	ofs.close();
}

void Management::addTeacherAccount()
{
	string name = "";
	string passwd = "";
	string num = "";

	cout<<"请输入添加教师的职工号:";
	cin>>num;

	cout<<"请输入添加教师的姓名:";
	cin>>name;

	cout<<"请输入添加教师的密码:";
	cin>>passwd;

	ofstream ofs;
	ofs.open("teacherPW.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"open teacherPW.csv fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<num<<","<<name<<","<<passwd<<","<<endl;
	cout<<"添加成功"<<endl;

	ofs.close();
}

void Management::addManagementAccount()
{
	string name = "";
	string passwd = "";

	cout<<"请输入添加管理员的姓名:";
	cin>>name;

	cout<<"请输入添加管理员的密码:";
	cin>>passwd;

	ofstream ofs;
	ofs.open("managementPW.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"open managementPW.csv fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<name<<","<<passwd<<","<<endl;

	cout<<"添加成功"<<endl;


	ofs.close();
}

void Management::addingAnAccount()
{
	int choice = 0;

	cout<<"----------------------------"<<endl;
	cout<<"---------1、添加学生账号------"<<endl;
	cout<<"---------2、添加教师账号------"<<endl;
	cout<<"---------3、添加管理员账号----"<<endl;
	cout<<"----------------------------"<<endl;

	cin>>choice;
	
	switch(choice)
	{
	case 1:
		addStudentAccount();
		break;
	case 2:
		addTeacherAccount();
		break;
	case 3:
		addManagementAccount();
		break;
	default:
		cout<<"输入有误!"<<endl;
		break;
	}
}

void Management::viewStudentAccount()
{
	cout<<"学生:"<<endl;
	for(map<string, string>::const_iterator it = this->studentPW.begin();it != this->studentPW.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

void Management::viewTeacherAccount()
{
	cout<<"教师:"<<endl;
	for(map<string, string>::const_iterator it = this->studentPW.begin();it != this->studentPW.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

void Management::viewManagementAccount()
{
	cout<<"管理员:"<<endl;
	for(map<string, string>::const_iterator it = this->studentPW.begin();it != this->studentPW.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

void Management::viewAccount()
{
	int choice = 0;
	cout<<"----------------------------"<<endl;
	cout<<"---------1、查看学生账号------"<<endl;
	cout<<"---------2、查看教师账号------"<<endl;
	cout<<"---------3、查看管理员账号----"<<endl;
	cout<<"----------------------------"<<endl;

	cin>>choice;
	
	switch(choice)
	{
	case 1:
		viewStudentAccount();
		break;
	case 2:
		viewTeacherAccount();
		break;
	case 3:
		viewManagementAccount();
		break;
	default:
		cout<<"输入有误!"<<endl;
		break;
	}
}

void Management::viewComputerRoom()
{

}

void Management::logout(void (*fun)())
{
	cout<<"注销成功"<<endl;
	fun();
}