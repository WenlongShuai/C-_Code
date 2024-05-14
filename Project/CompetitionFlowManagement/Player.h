#pragma once

#include <iostream>
using namespace std;

class Player
{
public:
	//有参构造
	Player(int index, string name, float score);

	//获取选手姓名
	string getName();

	//获取选手成绩

	float getScore(int index);

	//设置选手姓名
	void setName(string num);

	//设置选手成绩
	void setScore(int index, float score);

private:
	
	string playerName;
	float playerScore[2];
};

