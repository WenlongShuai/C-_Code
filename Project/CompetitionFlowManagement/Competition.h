#ifndef __COMPETITION_H__
#define __COMPETITION_H__

#include <iostream>

#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Player.h"

using namespace std;

class Competition
{
public:
	Competition();
	~Competition();

	//初始化各种容器以及初始化index轮数
	void initCompetition();

	//创建12名选手
	void createPlayer();

	//抽签
	void drawLots();

	//开始比赛
	void kickOff();

	//比赛结束,将前三名保存到文件中
	void saveListOfWinners();

	//每比赛完一轮,就显示一轮成绩
	void showScore();

	//整个游戏流程
	void competitionSchedule();

	//显示菜单界面
	void showMenu();

	//查看往届记录
	void lookAtPastRecords();

	//清空往届记录
	void clearRecords();

	//退出游戏
	void exit();

	//选项错误
	void inputError();

	//记录比赛轮数
	int index;

	//存放12名比赛选手的编号 
	vector<int> v1;

	//存放每轮比赛胜利的选手
	vector<int> v2;

	//存放12名选手的编号,姓名以及分数
	map<int, Player> player;
};






#endif