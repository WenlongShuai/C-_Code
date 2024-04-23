#include <iostream>

using namespace std;
#include <vector>
#include <deque>
#include <algorithm>

//描述
// 有5名选手,分别为ABCDE,10个评委分别对每一名选手打分,去掉最高分和去掉最低分,取平均分.

void printVector(const vector<char> &v)
{
	for(vector<char>::const_iterator it = v.begin();it != v.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	//创建一个vector容器,用于存放5位选手.
	vector<char> player;
	for(int i=0;i<5;i++)
	{
		player.push_back('A'+i);
	}
	printVector(player);

	//创建一个deque容器,用于存放10个评委的分数
	deque<int> playerScore;
	for(vector<char>::iterator it = player.begin();it != player.end();it++)
	{
		for(int j=0;j<10;j++)
		{
			playerScore.push_back(j);
		}

		sort(playerScore.begin(), playerScore.end());
		playerScore.pop_front();
		playerScore.pop_back();
		int sum = 0;
		int count = 0;
		float average = 0.0f;
		for(deque<int>::iterator it = playerScore.begin();it != playerScore.end();it++)
		{
			sum += *it;
			count++;
		}

		average = sum/count;
		cout<<*it<<" = "<<average<<endl;

	}


	



	return 0;
}