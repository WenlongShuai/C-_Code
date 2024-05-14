#ifndef __COMPETITION_H__
#define __COMPETITION_H__

#include <iostream>

#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <ctime>
#include <cstdlib>
#include "Player.h"

using namespace std;

class Competition
{
public:
	Competition();
	~Competition();

	void initCompetition();
	void createPlayer();
	void drawLots();
	void kickOff();
	void competitionSchedule();

	void showMenu();
	void lookAtPastRecords();
	void clearRecords();
	void exit();
	void inputError();

	int index;
	vector<int> v1;
	vector<int> v2;
	vector<int> vVictory;
	map<int, Player> player;
};






#endif