#include "Competition.h"

Competition::Competition()
{
	this->initCompetition(this->playerNum, this->grouping);
}

Competition::~Competition()
{

}

void Competition::createPlayer(vector<int> &pN, map<int, Player> &mp)
{
	for(int i = 0;i < 12;i++)
	{
		pN.push_back(10002+i);
	}

	random_shuffle(pN.begin(), pN.end());

	string nameFlag = "ABCDEFGHIJKL";
	for(int i = 0;i < 12;i++)
	{
		string name = "选手";
		name += nameFlag[i];
		Player p(name, 0);
		mp.insert(pair<int, Player>(pN[i], p));
	}
}


void Competition::markPlayer(map<int, Player> &player)
{
	for(map<int, Player>::iterator it = player.begin(); it != player.end(); it++)
	{
		deque<int> d;
		for(int i = 0;i < 10;i++)
		{
			int score = 60+rand()%41;
			d.push_back(score);
		}
		sort(d.begin(), d.end());

		d.pop_front();
		d.pop_back();
		int sum = 0;
		for(deque<int>::iterator it = d.begin();it != d.end();it++)
		{
			sum += *it;
		}
		float avg = sum * 1.0 / d.size();

		it->second.setScore(avg);
	}
}

void Competition::printPlayer(vector<Player> &p)
{
	for(vector<Player>::iterator it = p.begin();it != p.end();it++)
	{
		cout<<"选手:"<<it->getName()<<"成绩:"<<it->getScore()<<endl;
	}
}

void Competition::printGrouping(map<int, Player> &grouping)
{
	
	int size = grouping.size();
	int index = 0;
	map<int, Player>::iterator it = grouping.begin();
	cout<<"第一组:"<<endl;
	sort(grouping.begin(), grouping.end(), MyCompare());
	for( ; it != grouping.end() && index < size / 2; it++, index++)
	{
		cout<<"编号："<<it->first<<" 姓名:"<<it->second.getName()<<" 成绩:"<<it->second.getScore()<<endl;
	}

	index = size / 2;
	cout<<"第二组:"<<endl;
	for( ; it != grouping.end() && index < size; it++, index++)
	{
		
		cout<<"编号："<<it->first<<" 姓名:"<<it->second.getName()<<" 成绩:"<<it->second.getScore()<<endl;
	}
}

void print(pair<int, Player> p)
{
	cout<<p.first<<" ";
}

void Competition::initCompetition(vector<int> &playerNum, map<int, Player> &grouping)
{
	playerNum.clear();
	grouping.clear();
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

void Competition::kickOff(vector<int> &playerNum, map<int, Player> &grouping)
{
	createPlayer(playerNum, grouping);

	cout<<"第一轮比赛选手正在抽签"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"抽签后演讲顺序如下： "<<endl;
	for_each(grouping.begin(), grouping.end(), print);
	cout<<endl;
	cout<<"-----------------"<<endl;

	cout<<"-----第一轮比赛正式开始-----"<<endl;
	markPlayer(grouping);
	printGrouping(grouping);

}

void Competition::lookAtPastRecords()
{

}

void Competition::clearRecords()
{

}

void Competition::exit()
{
	cout<<"退出比赛,欢迎下次比赛"<<endl;
}

void Competition::inputError()
{
	cout<<"输入有误,请重新输入"<<endl;
}


