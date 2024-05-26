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

	multimap<string, map<string, string>>::iterator pos = this->management.studentPW.find(name);
	if(pos == this->management.studentPW.end())
	{
		cout<<"姓名错误,请重新输入!"<<endl;
	}
	else
	{
		map<string, string>::iterator subPos = pos->second.find(num);
		if(subPos == pos->second.end())
		{
			cout<<"学号错误,请重新输入!"<<endl;
		}
		else
		{
			if(passwd == subPos->second)
			{
				cout<<"密码正确"<<endl;
				this->student.setStudentNum(num);
				this->student.setStudentName(name);
				student.enterStudentScreen();
			}
			else
			{
				cout<<"密码错误,请重新输入!"<<endl;
			}
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


	multimap<string, map<string, string>>::iterator pos = this->management.teacherPW.find(name);
	if(pos == this->management.teacherPW.end())
	{
		cout<<"姓名错误,请重新输入!"<<endl;
	}
	else
	{
		map<string, string>::iterator subPos = pos->second.find(num);
		if(subPos == pos->second.end())
		{
			cout<<"职工号错误,请重新输入!"<<endl;
		}
		else
		{
			if(passwd == subPos->second)
			{
				cout<<"密码正确"<<endl;
				teacher.showSubMenu();
			}
			else
			{
				cout<<"密码错误,请重新输入!"<<endl;
			}
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
	map<string, string> tmp;

	string fileName[] = {"studentPW.csv", "teacherPW.csv", "managementPW.csv", "order.csv"};
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

		// if(i == 3)
		// {
		// 	while(getline(ifs, str))
		// 	{
		// 		this->student.index++;
		// 	}
		// }
		// else
		// {
			while(getline(ifs, str))
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
		// }
		

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
					tmp.insert(make_pair(v[j*3+0], v[j*3+2]));
					this->management.teacherPW.insert(make_pair(v[j*3+1], tmp));
				}
			}
			else if(i == 0)
			{
				for(int j = 0;j < v.size()/3;j++)
				{
					tmp.insert(make_pair(v[j*3+0], v[j*3+2]));
					this->management.studentPW.insert(make_pair(v[j*3+1], tmp));
				}
			}
		}
	
		v.clear();
		tmp.clear();
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