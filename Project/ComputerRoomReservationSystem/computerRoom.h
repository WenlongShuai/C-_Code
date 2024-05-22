#pragma once

#include <iostream>
#include <map>

using namespace std;

class ComputerRoom
{
public:
	ComputerRoom();
	~ComputerRoom();

	void initRoom();

	void setRoomState(int num, string time, int state);

	int getRoomState(int num, string time);

	void computerRoom1();
	void computerRoom2();
	void computerRoom3();

private:

	map<string, int>roomState[3];

};