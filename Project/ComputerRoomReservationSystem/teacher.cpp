#include "teacher.h"

Teacher::Teacher()
{

}
Teacher::~Teacher()
{

}

void Teacher::setEmployeeNum(string num)
{
	this->employeeNum = num;
}

void Teacher::setEmployeeName(string name)
{
	this->employeeName = name;
}

void Teacher::setEmployeePassword(string passwd)
{
	this->employeePassword = passwd;
}

string Teacher::getEmployeeNum()
{
	return this->employeeNum;
}

string Teacher::getEmployeeName()
{
	return this->employeeName;
}

string Teacher::getEmployeePassword()
{
	return this->employeePassword;
}

void Teacher::showSubMenu()
{
	cout<<"----------------------------"<<endl;
	cout<<"------------教师界面---------"<<endl;
	cout<<"---------1、查看所有预约-------"<<endl;
	cout<<"---------2、审核预约-----------"<<endl;
	cout<<"---------0、注销登录----------"<<endl;
	cout<<"-----------------------------"<<endl;
}


void Teacher::enterTeacherScreen()
{
	int choice = 0;

	do
	{
		this->showSubMenu();

		cin>>choice;

		switch(choice)
		{
		case 0:
			cout<<"注销成功"<<endl;
			break;
		case 1:
			this->viewAllReservations();
			break;
		case 2:
			this->auditReservations();
			break;
		default:
			cout<<"输入有误,请重新输入!"<<endl;
			break;
		}

	}while(choice);
}


void Teacher::viewAllReservations()
{
	ifstream ifs;
	ifs.open("order.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"open order.csv fail"<<endl;
		ifs.close();
		return;
	}

	char ch;
	if((ch = ifs.get()) == EOF)
	{
		cout<<"预约为空"<<endl;
		ifs.close();
		return;
	}

	ifs.putback(ch);

	string buf = "";
	int index = 1;

	while(getline(ifs, buf))
	{
		cout<<index<<"、"<<buf<<endl;
		index++;
	}

	ifs.close();
}


void Teacher::auditReservations()
{
	vector<string> v;
	vector<string> vAll;
	ifstream ifs;
	ifs.open("order.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"open order.csv fail"<<endl;
		ifs.close();
		return;
	}

	char ch;
	if((ch = ifs.get()) == EOF)
	{
		cout<<"预约为空"<<endl;
		ifs.close();
		return;
	}

	ifs.putback(ch);

	string buf = "";
	int index = 1;
	int flag = 0;
	int flag2 = 0;
	cout<<"待审核的预约记录如下:"<<endl;

	while(getline(ifs, buf))
	{
		vAll.push_back(buf);
		flag2++;
		int pos = buf.find("审核中", 0);
		if(pos == -1)
		{
			flag++;
			continue;
		}
		v.push_back(buf);
		cout<<index<<"、"<<buf<<endl;
		index++;
	}
	if(flag == flag2)
	{
		cout<<"预约记录为空"<<endl;
		ifs.close();
		return;
	}

	cout<<"请重新输入审核预约的记录,0代表返回"<<endl;

	int choice = 0;

	while(true)
	{
		cin>>choice;
		if(choice >=0 && choice <= v.size())
		{
			if(choice == 0)
			{
				break;
			}
			else
			{
				for(vector<string>::iterator it = vAll.begin();it != vAll.end();it++)
				{
					if(*it == v[choice-1])
					{
						cout<<"1、通过"<<endl;
						cout<<"2、不通过"<<endl;
						int passChoice = 0;
						cin>>passChoice;

						int pos = (*it).find("状态:", 0);
						pos += 7;
						int endPos = (*it).length();
						(*it).erase(pos, endPos-pos);

						if(passChoice == 1)
						{
							(*it).insert(pos, "审核通过");
						}
						else if(passChoice == 2)
						{
							(*it).insert(pos, "审核不通过");
						}
						else
						{
							cout<<"输入有误,请重新输入:"<<endl;
						}
						break;
					}	
				}
				break;
			}
		}
		else
		{
			cout<<"输入有误,请重新输入:"<<endl;
		}
	}


	ofstream ofs;
	ofs.open("order.csv", ios::out | ios::trunc);
	if(!ofs.is_open())
	{
		cout<<"order.csv open fail"<<endl;
		ofs.close();
		return;
	}

	for(vector<string>::iterator it = vAll.begin();it!=vAll.end();it++)
	{
		ofs<<*it<<endl;
	}

	ifs.close();
	ofs.close();
}

