#pragma once

#include <iostream>
using namespace std;

class Player
{
public:
	//有参构造
	Player(int num, string name, float score);

	//获取选手编号
	int getNum();

	//获取选手姓名
	string getName();

	//获取选手成绩

	float getScore();


	//设置选手编号
	void setNum(int num);

	//设置选手姓名
	void setName(string num);

	//设置选手成绩
	void setScore(float score);

private:
	int playerNum;
	string playerName;
	float playerScore;
};

