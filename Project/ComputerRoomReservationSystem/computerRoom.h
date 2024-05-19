#pragma once

class ComputerRoom
{
public:
	ComputerRoom();
	~ComputerRoom();

	void setRoomState(int num, int state);

	int getRoomState(int num);

	void computerRoom1();
	void computerRoom2();
	void computerRoom3();

private:
	int room1state;
	int room2state;
	int room3state;

};