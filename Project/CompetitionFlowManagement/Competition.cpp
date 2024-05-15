#include "Competition.h"

Competition::Competition()
{
	this->initCompetition();
	this->createPlayer();
}

Competition::~Competition()
{

}

void Competition::initCompetition()
{
	this->index = 1;
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->player.clear();
}

void Competition::createPlayer()
{
	string nameFlag = "ABCDEFGHIJKL";
	for(int i = 0;i < 12;i++)
	{
		string name = "选手";
		name += nameFlag[i];
		v1.push_back(10002+i);
		Player p(this->index, name, 0);
		player.insert(pair<int, Player>(10002+i, p));
	}
}

void Competition::drawLots()
{
	cout<<"-----第"<<this->index<<"轮比赛选手正在抽签---"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"抽签后演讲顺序如下： "<<endl;

	if(this->index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for(vector<int>::const_iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for(vector<int>::const_iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	
	cout<<"-----------------"<<endl;
}

void Competition::kickOff()
{
	cout<<"-----第"<<this->index<<"轮演讲正式开始------"<<endl;
	vector<int> vTemp;
	multimap<float, int, greater<float>> mTemp;
	int num = 0;
	if(this->index == 1)
	{
		vTemp = v1;
		v1.clear();
	}
	else
	{
		vTemp = v2;
		v2.clear();
	}

	for(vector<int>::iterator it = vTemp.begin();it != vTemp.end();it++)
	{
		deque<int> d;
		for(int i = 0;i < 10;i++)
		{
			int score = (600+rand()%410) / 10.0f;
			d.push_back(score);
		}
		sort(d.begin(), d.end());

		d.pop_front();
		d.pop_back();

		float sum = accumulate(d.begin(), d.end(), 0);
		
		float avg = sum / d.size();

		map<int,Player>::iterator pos = player.find(*it);
		if(pos == player.end())
		{
			cout<<"kickOff 没有找到key为"<<*it<<"的值"<<endl;
		}
		else
		{
			pos->second.setScore(this->index-1, avg);
			mTemp.insert(pair<float, int>(avg, *it));
		}

		num++;

		if(num % 6 == 0)
		{
			int count = 0;
			cout<<"第"<<num / 6<<"组比赛名次"<<endl;
			for(multimap<float, int, greater<float>>::iterator it = mTemp.begin();it != mTemp.end();it++, count++)
			{
				cout<<"编号:"<<it->second<<"\t姓名:"<<player.find(it->second)->second.getName()<<"\t成绩:"<<player.find(it->second)->second.getScore(this->index-1)<<endl;
				if(count < 3)
				{
					v2.push_back(it->second);
				}	
			}
			mTemp.clear();
			cout<<endl;
		}
	}
	cout<<"-----第"<<this->index<<"轮演讲结束------"<<endl;
}

void Competition::listOfWinners()
{
	ofstream ofs;
	ofs.open("./victoryScore.csv", ios::out | ios::app);
	if(!ofs.is_open())
	{
		cout<<"listOfWinners 打开文件失败"<<endl;
		return;
	}
	cout<<"-----两轮演讲结束,获胜名单-----"<<endl;
	for(vector<int>::const_iterator it = v2.begin(); it != v2.end(); it++)
	{
		vVictory.push_back(*it);
		map<int, Player>::iterator pos = player.find(*it);
		if(pos == player.end())
		{
			cout<<"listOfWinners 没有找到key为"<<*it<<"的值"<<endl;
		}
		else
		{
			cout<<"编号:"<<pos->first<<"\t姓名:"<<pos->second.getName()<<"\t成绩:"<<pos->second.getScore(this->index-1)<<endl;	
			ofs<<pos->first<<","<<pos->second.getScore(this->index-1)<<",";
		}	
	}
	ofs<<endl;
	ofs.close();
}


void Competition::competitionSchedule()
{
	drawLots();
	kickOff();
	this->index++;
	drawLots();
	kickOff();
	listOfWinners();
	initCompetition();
	createPlayer();
}


void Competition::showMenu()
{
	cout<<"-----------------------------"<<endl;
	cout<<"------欢迎参加演讲比赛-------"<<endl;
	cout<<"------1、开始演讲比赛--------"<<endl;
	cout<<"------2、查看往届记录--------"<<endl;
	cout<<"------3、清空比赛记录--------"<<endl;
	cout<<"------0、退出比赛程序--------"<<endl;
	cout<<"-----------------------------"<<endl;
}



void Competition::lookAtPastRecords()
{
	ifstream ifs;

	ifs.open("./victoryScore.csv", ios::in);
	if(!ifs.is_open())
	{
		cout<<"lookAtPastRecords 打开文件失败"<<endl;
		return;
	}

	string buf = "";
	int count = 1;
	int startPos = 0;
	int endPos = 0;
	int count2 = 0;
	int flag2 = 0;
	string flag = ",";
	string str;
	char *arr[3] = {"冠军编号:","亚军编号:","季军编号:"};

	while(getline(ifs, buf))
	{
		cout<<"第"<<count<<"届: ";

		while(1)
		{
			endPos = buf.find(flag , startPos);
			if(endPos == -1)
			{
				break;
			}
			str = buf.substr(startPos, endPos-startPos);
			startPos = endPos + 1;
			if(count2 % 2 == 0)
			{
				cout<<arr[flag2]<<str<<"\t";
				flag2++;
			}
			else
			{
				cout<<"得分:"<<str<<"\t\t";
			}
			count2++;
		}

		startPos = 0;
		endPos = 0;
		flag2 = 0;
		count2 = 0;
		count++;
		cout<<endl;
	}
}	

void Competition::clearRecords()
{
	ofstream ofs;

	ofs.open("./victoryScore.csv", ios::trunc);
	if(!ofs.is_open())
	{
		cout<<"clearRecords 打开文件失败"<<endl;
		return;
	}
	cout<<"清除记录成功"<<endl;
	ofs.close();
}

void Competition::exit()
{
	cout<<"退出比赛,欢迎下次比赛"<<endl;
}

void Competition::inputError()
{
	cout<<"输入有误,请重新输入"<<endl;
}


