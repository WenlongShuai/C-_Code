#include "management.h"

Management::Management()
{
	this->studentPW.clear();
	this->teacherPW.clear();
	this->managementPW.clear();
}

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
	cout<<"---------4、清空所有预约----------"<<endl;
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
		case 4:
			clearAllReservations();
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
	map<string, string> tmp;

	cout<<"请输入添加学生的学号:";
	cin>>num;

	cout<<"请输入添加学生的姓名:";
	cin>>name;

	cout<<"请输入添加学生的密码:";
	cin>>passwd;

	ifstream ifs;
	ifs.open("studentPW.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"open studentPW.csv fail"<<endl;
		ifs.close();
		return;
	}

	string buf = "";
	while(getline(ifs, buf))
	{
		if(buf.find(num) != -1)
		{
			cout<<"学号重复,请重新输入"<<endl;
			ifs.close();
			return;
		}
	}

	ofstream ofs;
	ofs.open("studentPW.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"open studentPW.csv fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<num<<","<<name<<","<<passwd<<","<<endl;

	tmp.insert(make_pair(num, passwd));

	this->studentPW.insert(make_pair(name, tmp));

	cout<<"添加成功"<<endl;

	ofs.close();
}

void Management::addTeacherAccount()
{
	string name = "";
	string passwd = "";
	string num = "";
	map<string, string> tmp;

	cout<<"请输入添加教师的职工号:";
	cin>>num;

	cout<<"请输入添加教师的姓名:";
	cin>>name;

	cout<<"请输入添加教师的密码:";
	cin>>passwd;


	ifstream ifs;
	ifs.open("teacherPW.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"open teacherPW.csv fail"<<endl;
		ifs.close();
		return;
	}

	string buf = "";
	while(getline(ifs, buf))
	{
		if(buf.find(num) != -1)
		{
			cout<<"职工号重复,请重新输入"<<endl;
			ifs.close();
			return;
		}
	}

	ofstream ofs;
	ofs.open("teacherPW.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"open teacherPW.csv fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<num<<","<<name<<","<<passwd<<","<<endl;
	tmp.insert(make_pair(num, passwd));
	this->teacherPW.insert(make_pair(name, tmp));
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

	ifstream ifs;
	ifs.open("managementPW.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"open managementPW.csv fail"<<endl;
		ifs.close();
		return;
	}

	string buf = "";
	while(getline(ifs, buf))
	{
		if(buf.find(name) != -1)
		{
			cout<<"管理员姓名重复,请重新输入"<<endl;
			ifs.close();
			return;
		}
	}

	ofstream ofs;
	ofs.open("managementPW.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"open managementPW.csv fail"<<endl;
		ofs.close();
		return;
	}

	ofs<<name<<","<<passwd<<","<<endl;

	this->managementPW.insert(make_pair(name, passwd));

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

	vector<string> v;

	ifstream ifs;
	ifs.open("studentPW.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"studentPW.csv"<<" fail"<<endl;
		ifs.close();
		return;
	}
	string str = "";
	int startPos = 0;
	int endPos = 0;

	while(ifs>>str)
	{
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

	for(int i = 0;i < v.size()/3;i++)
	{
		cout<<"学号:"<<v[i*3]<<"\t姓名:"<<v[i*3+1]<<"\t密码:"<<v[i*3+2]<<endl;
	}

	ifs.close();
}

void Management::viewTeacherAccount()
{
	cout<<"教师:"<<endl;
	vector<string> v;

	ifstream ifs;
	ifs.open("teacherPW.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"teacherPW.csv"<<" fail"<<endl;
		ifs.close();
		return;
	}
	string str = "";
	int startPos = 0;
	int endPos = 0;

	while(ifs>>str)
	{
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

	for(int i = 0;i < v.size()/3;i++)
	{
		cout<<"职工号:"<<v[i*3]<<"\t姓名:"<<v[i*3+1]<<"\t密码:"<<v[i*3+2]<<endl;
	}

	ifs.close();
}

void Management::viewManagementAccount()
{
	cout<<"管理员:"<<endl;
	vector<string> v;

	ifstream ifs;
	ifs.open("managementPW.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"managementPW.csv"<<" fail"<<endl;
		ifs.close();
		return;
	}
	string str = "";
	int startPos = 0;
	int endPos = 0;

	while(ifs>>str)
	{
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

	for(int i = 0;i < v.size()/2;i++)
	{
		cout<<"姓名:"<<v[i*2]<<"\t密码:"<<v[i*2+1]<<endl;
	}

	ifs.close();
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

void Management::ComputerRoomState(int num)
{
	string time[] = {"8:00-9:00", "9:00-10:00", "10:00-11:00", "11:00-12:00" ,
					 "14:00-15:00", "15:00-16:00", "16:00-17:00", "17:00-18:00"};
	int size = sizeof(time) / sizeof(time[0]);

	if(num == 4)
	{
		for(int i = 0;i < 3;i++)
		{
			cout<<"---------"<<i+1<<"号机房"<<"---------"<<endl;
			for(int j = 0;j < size;j++)
			{
				if(j == size / 2 )
				{
					cout<<"------------下午-----------"<<endl;
				}
				else if(j == 0)
				{
					cout<<"------------上午------------"<<endl;
				}
				cout<<time[j]<<"\t---->\t"<<this->room.getRoomState(num-1, time[j])<<endl;
			}
		}	
	}
	else
	{
		cout<<"---------"<<num<<"号机房"<<"---------"<<endl;
		for(int i = 0;i < size;i++)
		{

			if(i == size / 2)
			{
				cout<<"------------下午-----------"<<endl;
			}
			else if(i == 0)
			{
				cout<<"------------上午------------"<<endl;
			}
			cout<<time[i]<<"\t---->\t"<<this->room.getRoomState(num-1, time[i])<<endl;
		}
	}
}

void Management::viewComputerRoom()
{
	cout<<"-------查看机房状态-------"<<endl;
	cout<<"-------1、1号机房--------"<<endl;
	cout<<"-------2、2号机房-------"<<endl;
	cout<<"-------3、3号机房-------"<<endl;
	cout<<"-------4、全部机房-------"<<endl;

	int choice = 0;
	cin>>choice;

	switch(choice)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		this->ComputerRoomState(choice);
		break;
	default:
		cout<<"输入有误,请重新输入!"<<endl;
		break;
	}	
}

void Management::clearAllReservations()
{
	ifstream ifs;
	ifs.open("order.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"order.csv"<<" fail"<<endl;
		ifs.close();
		return;
	}
	
	char ch = 0;
	if((ch=ifs.get()) == EOF )
	{
		cout<<"预约为空"<<endl;
		ifs.close();
		return;
	}

	ifs.putback(ch);

	int choice = 0;
	cin>>choice;

	cout<<"1、确定"<<endl;
	cout<<"2、取消"<<endl;

	if(choice == 1)
	{
		ofstream ofs;
		ofs.open("order.csv", ios::out | ios::trunc);

		cout<<"清空成功"<<endl;
		ofs.close();
	}
	ifs.close();
}

void Management::logout(void (*fun)())
{
	cout<<"注销成功"<<endl;
	fun();
}