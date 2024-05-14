#include "Player.h"

//有参构造
Player::Player(int index, string name, float score)
{
	this->playerName = name;
	this->playerScore[index] = score;
}


//获取选手姓名
string Player::getName()
{
	return this->playerName;
}

//获取选手成绩
float Player::getScore(int index)
{
	return this->playerScore[index];
}

//设置选手名字
void Player::setName(string name)
{
	this->playerName = name;
}

//设置选手成绩
void Player::setScore(int index, float score)
{
	this->playerScore[index] = score;
}
