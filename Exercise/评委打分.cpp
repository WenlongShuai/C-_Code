#include <iostream>

using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>

//描述
// 有5名选手,分别为ABCDE,10个评委分别对每一名选手打分,去掉最高分和去掉最低分,取平均分.

/*
//方式一
void createPlayer(vector<char> &v)
{
	for(int i=0;i<5;i++)
	{
		v.push_back('A'+i);
	}
}

void setScore(vector<char> &p, vector<int> &s)
{
	for(vector<char>::iterator it = p.begin();it != p.end();it++)
	{
		deque<int> playerScore;
		for(int j=0;j<10;j++)
		{
			int score = 60 + rand()%(100 - 60 + 1); //(60-100)
			playerScore.push_back(score);
		}

		sort(playerScore.begin(), playerScore.end());
		playerScore.pop_front();
		playerScore.pop_back();
		int sum = 0;
		for(deque<int>::iterator it = playerScore.begin();it != playerScore.end();it++)
		{
			sum += *it;
		}
		int average = sum / playerScore.size();
		s.push_back(average);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//创建一个vector容器,用于存放5位选手.
	vector<char> player;
	createPlayer(player);

	//创建一个deque容器,用于存放10个评委的分数
	vector<int> playerScore;
	setScore(player, playerScore);
	int i = 0;
	for(vector<char>::iterator it = player.begin();it!=player.end();it++,i++)
	{
		cout<<"选手"<<*it<<" = "<<playerScore[i]<<endl;
	}

	return 0;
}
*/


//方式二
//创建一个选手类,里面包含姓名和成绩
class Player
{
public:
	Player(string name, int score)
	{
		m_Name = name;
		m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void createPlayer(vector<Player> &v)
{
	string nameSeed = "ABCDE";

	for(int i = 0;i<5;i++)
	{
		string name = "选手";
		int score = 0;
		name += nameSeed[i];
		Player p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Player> &v)
{
	for(vector<Player>::iterator it = v.begin();it != v.end();it++)
	{
		deque<int> playerScore;
		for(int i = 0;i < 10;i++)
		{
			int score = 60+rand()%41;
			playerScore.push_back(score);
		}

		sort(playerScore.begin(), playerScore.end());
		playerScore.pop_back();
		playerScore.pop_front();

		int sum = 0;
		for(deque<int>::iterator sit = playerScore.begin();sit!=playerScore.end();sit++)
		{
			sum += *sit;
		}

		int average = sum / playerScore.size();

		it->m_Score = average;
	}
}


void showScore(vector<Player> &v)
{
	for(vector<Player>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<it->m_Name<<" = "<<it->m_Score<<endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//1 创建5名选手,放入vector中
	vector<Player> player;
	createPlayer(player);

	//2 10个评委打分,计算平均分
	setScore(player);

	//3 显示选手分数
	showScore(player);


	return 0;
}
