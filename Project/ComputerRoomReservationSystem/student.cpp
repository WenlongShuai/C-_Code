#include "student.h"

Student::Student()
{
	// this->index = 1;
}

Student::~Student()
{

}

void Student::setStudentNum(string num)
{
	this->studentNum = num;
}

void Student::setStudentName(string name)
{
	this->studentName = name;
}

void Student::setStudentPassword(string password)
{
	this->studentPassword = password;
}

string Student::getStudentNum()
{
	return this->studentNum;
}

string Student::getStudentName()
{
	return this->studentName;
}

string Student::getStudentPassword()
{
	return this->studentPassword;
}


void Student::showSubMenu()
{
	cout<<"----------------------------"<<endl;
	cout<<"------------学生界面---------"<<endl;
	cout<<"---------1、申请预约----------"<<endl;
	cout<<"---------2、查看预约----------"<<endl;
	cout<<"---------3、取消预约----------"<<endl;
	cout<<"---------4、查看所有预约-------"<<endl;
	cout<<"---------0、注销登录----------"<<endl;
	cout<<"-----------------------------"<<endl;
}


void Student::enterStudentScreen()
{
	int choice = 0;
	do
	{
		this->showSubMenu();
		cin>>choice;

		switch(choice)
		{
		case 1:
			this->requestAnAppointment();
			break;
		case 2:
			this->viewReservations();
			break;
		case 3:
			this->cancelTheReservation();
			break;
		case 4:
			this->viewAllReservations();
			break;
		case 0:
			cout<<"注销成功!"<<endl;
			break;
		default:
			cout<<"输入有误,请重新输入!"<<endl;
			break;
		}

	}while(choice);
}


void Student::requestAnAppointment()
{
	string openingHours[] = {"周一", "周二", "周三", "周四", "周五"};
	string time[] = {"8:00-9:00", "9:00-10:00", "10:00-11:00", "11:00-12:00" ,
					 "14:00-15:00", "15:00-16:00", "16:00-17:00", "17:00-18:00"};

	string computerRoom = "123";

	int choice = 0;
	string day = "";
	string hour = "";
	string room = "";

	ofstream ofs;

	cout<<"机房开放时间为周一到周五:"<<endl;
	cout<<"请输入预约的时间:"<<endl;
	cout<<"1、周一"<<endl;
	cout<<"2、周二"<<endl;
	cout<<"3、周三"<<endl;
	cout<<"4、周四"<<endl;
	cout<<"5、周五"<<endl;
	
	
	cin>>choice;

	day = openingHours[choice-1];

	cout<<"请输入预约的时间段:"<<endl;
	cout<<"------------上午-----------"<<endl;
	cout<<"-------1、8:00-9:00--------"<<endl;
	cout<<"-------2、9:00-10:00-------"<<endl;
	cout<<"-------3、10:00-11:00-------"<<endl;
	cout<<"-------4、11:00-12:00-------"<<endl;
	cout<<"------------下午------------"<<endl;
	cout<<"-------5、14:00-15:00-------"<<endl;
	cout<<"-------6、15:00-16:00-------"<<endl;
	cout<<"-------7、16:00-17:00-------"<<endl;
	cout<<"-------8、17:00-18:00-------"<<endl;

	cin>>choice;
	hour = time[choice-1];

	cout<<"请选择机房:"<<endl;
	cout<<"1、1号机房容量:20"<<endl;
	cout<<"2、2号机房容量:50"<<endl;
	cout<<"3、3号机房容量:100"<<endl;

	cin>>choice;
	room = computerRoom[choice-1];

	ofs.open("order.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"order.csv open fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<"预约日期:"<<day<<"\t时段:"<<hour<<"\t学号:"<<this->getStudentNum()<<"\t姓名:"<<this->getStudentName()<<"\t机房:"<<room<<"\t状态:"<<"审核中"<<endl;
	cout<<"预约成功!"<<endl;
	ofs.close();	
}

void Student::viewReservations()
{
	ifstream ifs;
	ifs.open("order.csv", ios::in);
	if(!ifs.is_open())
	{
		
		cout<<"open order.csv fail!"<<endl;
		ifs.close();
		return;
	}

	char ch = ifs.get();
	if(ch == EOF)
	{
		cout<<"预约为空,请先预约!"<<endl;
		ifs.close();
		return;
	}

	int flag = 0;
	int flag2 = 0;

	ifs.putback(ch);
	string buf = "";
	int index = 1;
	while(getline(ifs, buf))
	{
		flag2++;
		int pos = buf.find(this->getStudentNum(), 0);
		if(pos == -1)
		{
			flag++;
			continue;
		}
		cout<<index<<"、"<<buf<<endl;
		index++;
	}
	if(flag == flag2)
	{
		cout<<"预约为空,请先预约!"<<endl;
	}

	ifs.close();
}

void Student::cancelTheReservation()
{
	cout<<"审核中或预约成功的记录可以取消,请输入取消的记录:"<<endl;
	int pos = -1;
	int pos2 = -1;
	vector<string> v;
	vector<string> vAll;


	ifstream ifs;
	ifs.open("order.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"order.csv open fail"<<endl;
		ifs.close();
		return;
	}
	string buf = "";
	int index = 1;
	while(getline(ifs, buf))
	{
		vAll.push_back(buf);

		pos = buf.find(this->getStudentNum(), 0);
		if(pos == -1)
		{
			continue;
		}
		pos = buf.find("审核中", 0);
		pos2 = buf.find("预约成功", 0);
		if(pos == -1 && pos2 == -1)
		{
			continue;
		}
		v.push_back(buf);
		cout<<index<<"、"<<buf<<endl;
		index++;
	}
	ifs.close();

	cout<<"请输入取消的记录,0代表返回"<<endl;
	int input = 0;

	while(true)
	{
		cin>>input;
		if(input >= 0 && input <= v.size())
		{
			if(input == 0)
			{
				break;
			}
			else
			{

				for(vector<string>::iterator it = vAll.begin();it!=vAll.end();it++)
				{
					if(*it == v[input-1])
					{
						pos2 = (*it).find("状态:", 0);
						cout<<"pos2--->"<<pos2<<endl;
						pos2 = pos2+7;
						int endPos = (*it).size();
						(*it).erase(pos2, endPos-pos2);
						(*it).insert(pos2, "预约已取消");
					}
				}
				cout<<"成功取消预约"<<endl;
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

	ofs.close();
}

void Student::viewAllReservations()
{
	ifstream ifs;
	ifs.open("order.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"order.csv open fail"<<endl;
		ifs.close();
		return;
	}
	string buf = "";
	int index = 1;

	while(getline(ifs, buf))
	{
		cout<<index<<"、"<<buf<<endl;
		index++;
	}

	ifs.close();
}
