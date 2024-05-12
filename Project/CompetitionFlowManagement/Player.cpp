#include "Player.h"

//有参构造
Player::Player(int num, string name, float score)
{
	this->playerNum = num;
	this->playerName = name;
	this->playerScore = score;
}

//获取选手编号
int Player::getNum()
{
	return this->playerNum;
}

//获取选手姓名
string Player::getName()
{
	return this->playerName;
}

//获取选手成绩
float Player::getScore()
{
	return this->playerScore;
}

//设置选手编号
void Player::setNum(int num)
{
	this->playerNum = num;
}

//设置选手名字
void Player::setName(string name)
{
	this->playerName = name;
}

//设置选手成绩
void Player::setScore(float score)
{
	this->playerScore = score;
}
