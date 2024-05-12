#include "Competition.h"

class MyCompare
{
public:
	bool operator()(Player &p1, Player &p2) const
	{
		return p1.getScore() > p2.getScore();
	}
};

void createPlayer(vector<Player> &player)
{
	string nameFlag = "ABCDEFGHIJKL";
	for(int i = 0;i < 12;i++)
	{
		string name = "选手";
		name += nameFlag[i];
		Player p(10002+i, name, 0);
		player.push_back(p);
	}
}

void setGrouping(vector<Player> &p, multimap<int, Player> mp)
{
	random_shuffle(p.begin(), p.end());
	int pSize = p.size();

	for(int i = 0;i < pSize/2;i++)
	{
		mp.insert(pair<int, Player>(1,p[i]));
	}

	for(int i = pSize/2;i < pSize;i++)
	{
		mp.insert(make_pair(2, p[i]));
	}
}

void markPlayer(multimap<int, Player> player)
{
	
	multimap<int, Player>::iterator pos = player.find(1);
	int count = player.count(1);
	int index = 0;

	for( ;pos != player.end() && index < count;pos++, index++ )
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

		pos->second.setScore(avg);
		
	}

	pos = player.find(2);
	count = player.count(2);
	index = 0;
	for( ;pos != player.end() && index < count;pos++, index++ )
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

		pos->second.setScore(avg);
	}
}

void printPlayer(vector<Player> &p)
{
	for(vector<Player>::iterator it = p.begin();it != p.end();it++)
	{
		cout<<"选手:"<<it->getNum()<<"成绩:"<<it->getScore()<<endl;
	}
}

void printGrouping(multimap<int, Player> g)
{
	multimap<int, Player>::iterator pos = g.find(1);
	int count = g.count(1);
	int index = 0;
	cout<<"第一组:"<<endl;
	for( ;pos != g.end() && index < count;pos++, index++ )
	{
		
		cout<<"编号："<<pos->second.getNum()<<" 姓名:"<<pos->second.getName()<<" 成绩:"<<pos->second.getScore()<<endl;
	}

	pos = g.find(2);
	count = g.count(2);
	index = 0;
	cout<<"第二组:"<<endl;
	for( ;pos != g.end() && index < count;pos++, index++ )
	{
		cout<<"编号："<<pos->second.getNum()<<" 姓名:"<<pos->second.getName()<<" 成绩:"<<pos->second.getScore()<<endl;
	}
}

void print(pair<int, Player> p)
{
	cout<<p.second.getNum()<<" ";
}



void printMenu()
{
	cout<<"-----------------------------"<<endl;
	cout<<"------欢迎参加演讲比赛-------"<<endl;
	cout<<"------1、开始演讲比赛--------"<<endl;
	cout<<"------2、查看往届记录--------"<<endl;
	cout<<"------3、清空比赛记录--------"<<endl;
	cout<<"------0、退出比赛程序--------"<<endl;
	cout<<"-----------------------------"<<endl;
}

void kickOff()
{
	vector<Player> player;
	multimap<int, Player, MyCompare> grouping;
	
	createPlayer(player);
	setGrouping(player, grouping);

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

void lookAtPastRecords()
{

}

void clearRecords()
{

}


