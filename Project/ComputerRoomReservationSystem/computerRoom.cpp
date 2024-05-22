#include "computerRoom.h"

ComputerRoom::ComputerRoom()
{
	this->initRoom();
}

ComputerRoom::~ComputerRoom()
{

}

void ComputerRoom::initRoom()
{
	string time[] = {"8:00-9:00", "9:00-10:00", "10:00-11:00", "11:00-12:00" ,
					 "14:00-15:00", "15:00-16:00", "16:00-17:00", "17:00-18:00"};
	int size = sizeof(this->roomState) / sizeof(this->roomState[0]);
	int sizeTime = sizeof(time) / sizeof(time[0]);
	
	for(int i = 0;i < size;i++)
	{
		for(int j = 0;j < sizeTime;j++)
		{
			this->roomState[i].insert(pair<string, int>(time[j], 0));
		}
	}
}

void ComputerRoom::setRoomState(int num, string time, int state)
{
	this->roomState[num-1].insert(pair<string, int>(time, state));
}

int ComputerRoom::getRoomState(int num, string time)
{
	return this->roomState[num-1][time];
}

void ComputerRoom::computerRoom1()
{
	cout<<"1号机房"<<endl;
}

void ComputerRoom::computerRoom2()
{
	cout<<"2号机房"<<endl;
}

void ComputerRoom::computerRoom3()
{
	cout<<"3号机房"<<endl;
}