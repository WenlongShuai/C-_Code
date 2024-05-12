// 比赛规则：
// 1、演讲比赛，一共12人参加，比赛两轮，第一轮为淘汰赛，第二轮为决赛。
// 2、每名选手都有对应的编号，比如10001～10012。
// 3、比赛方式，分组比赛，每组6人。
// 4、第一轮分为两组，整体按照选手编号进行抽签后顺序演讲。
// 5、十个评委打分，去掉最高分和最低分，最后求平均分为选手的成绩。
// 6、当小组演讲完后，淘汰小组内排名最后的三名选手，前三名晋级，进入下一轮比赛。
// 7、第二轮为决赛，前三名胜出。
// 8、每轮比赛后需要显示晋级选手的信息。


#include <iostream>

#include <ctime>
#include <cstdlib>
#include "Competition.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	vector<Player> player;
	multimap<int, Player> grouping;

	printMenu();

	cout<<"请输入您的选择："<<endl;
	int choice = 0;
	cin>>choice;

	kickOff();

	// do
	// {
	// 	switch(choice)
	// 	{
	// 	case 1:
	// 		kickOff();
	// 		break;
	// 	case 2:
	// 		lookAtPastRecords();
	// 		break;
	// 	case 3:
	// 		clearRecords();
	// 		break;
	// 	case 0:
	// 		cout<<"退出比赛"<<endl;
	// 		break;
	// 	}
	// }while(choice);

	return 0;
}