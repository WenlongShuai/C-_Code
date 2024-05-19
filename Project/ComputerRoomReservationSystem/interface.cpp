#include "interface.h"

Interface::Interface()
{
	this->loadAllCSV();
}

Interface::~Interface()
{

}

void Interface::showMainMenu()
{
	cout<<"----------------------------"<<endl;
	cout<<"---------机房预约系统---------"<<endl;
	cout<<"---------1、学生代表----------"<<endl;
	cout<<"---------2、教师-------------"<<endl;
	cout<<"---------3、管理员-----------"<<endl;
	cout<<"---------0、退出-------------"<<endl;
	cout<<"----------------------------"<<endl;
}

void Interface::studentLogin()
{
	cout<<"-------学生登录界面---------"<<endl;
	string num = "";
	string name = "";
	string passwd = "";
	cout<<"学号:";
	cin>>num;
	cout<<"姓名:";
	cin>>name;
	cout<<"密码:";
	cin>>passwd;

	map<string, string>::iterator pos = this->management.studentPW.find(num);
	if(pos == this->management.studentPW.end())
	{
		cout<<"学号错误,请重新输入!"<<endl;
	}
	else
	{
		if(passwd == pos->second)
		{
			cout<<"学号密码正确"<<endl;
			student.showSubMenu();
		}
		else
		{
			cout<<"密码错误,请重新输入!"<<endl;
		}
	}
}

void Interface::teacherLogin()
{
	cout<<"-------教师登录界面---------"<<endl;
	string num = "";
	string name = "";
	string passwd = "";
	cout<<"职工号:";
	cin>>num;
	cout<<"姓名:";
	cin>>name;
	cout<<"密码:";
	cin>>passwd;

	map<string, string>::iterator pos = this->management.teacherPW.find(num);
	if(pos == this->management.teacherPW.end())
	{
		cout<<"用户名错误,请重新输入!"<<endl;
	}
	else
	{
		if(passwd == pos->second)
		{
			cout<<"用户名密码正确"<<endl;
			teacher.showSubMenu();
		}
		else
		{
			cout<<"用户名密码错误,请重新输入!"<<endl;
		}
	}
}

void Interface::managementLogin()
{
	cout<<"-------管理员登录界面---------"<<endl;
	string name = "";
	string passwd = "";
	cout<<"姓名:";
	cin>>name;
	cout<<"密码:";
	cin>>passwd;

	map<string, string>::iterator pos = this->management.managementPW.find(name);
	if(pos == this->management.managementPW.end())
	{
		cout<<"用户名错误,请重新输入!"<<endl;
	}
	else
	{
		if(passwd == pos->second)
		{
			cout<<"用户名密码正确"<<endl;
			management.enterManagementScreen();
		}
		else
		{
			cout<<"用户名密码错误,请重新输入!"<<endl;
		}
	}
}

void Interface::loadAllCSV()
{
	vector<string> v;
	string fileName[3] = {"studentPW.csv", "teacherPW.csv", "managementPW.csv"};
	// map<string, string> (&managementMap)[3] = {this->management.studentPW, this->management.teacherPW, this->management.managementPW};

	int size = sizeof(fileName) / sizeof(fileName[0]);

	ifstream ifs;

	for(int i = 0;i < size;i++)
	{
		ifs.open(fileName[i], ios::in);
		if(!ifs.is_open())
		{
			cout<<fileName[i]<<" fail"<<endl;
			ifs.close();
			return;
		}
		string str = "";
		int startPos = 0;
		int endPos = 0;

		while(ifs>>str)
		{
			// cout<<str<<endl;
			while(1)
			{
				endPos = str.find(",", startPos);
				if(endPos == -1)
				{
					break;
				}
				string subStr = str.substr(startPos, endPos-startPos);
				startPos = endPos+1;

				v.push_back(subStr);
			}
			startPos = 0;
		}

		
		if(i == 2)
		{
			for(int j = 0;j < v.size()/2;j++)
			{
				this->management.managementPW.insert(make_pair(v[j*2], v[j*2+1]));
			}
		}
		else
		{
			if(i == 1)
			{
				for(int j = 0;j < v.size()/3;j++)
				{
					this->management.teacherPW.insert(make_pair(v[j*3+0], v[j*3+2]));
				}
			}
			else
			{
				for(int j = 0;j < v.size()/3;j++)
				{
					this->management.studentPW.insert(make_pair(v[j*3+0], v[j*3+2]));
				}
			}
		}
	
		v.clear();
		ifs.close();
	}
}

void Interface::exitMenu()
{
	cout<<"退出系统,欢迎下次使用"<<endl;
}

void Interface::inputError()
{
	cout<<"选项输入有误,请重新输入!"<<endl;
}