#include <iostream>

using namespace std;

// 案例分析
// 1、提示用户输入一个成绩，根据成绩作如下判断
// 2、分数如果大于600视为考上一本大学，
// 大于500视为考上二本大学，
// 大于400视为考上三本大学,
// 其余视为未考上本科
// 3、在一本的分数中，如果大于700，考入北大，大于650，考入清华，大于600考入人大

int main()
{
	int score = 0;
    cout<<"输入一个分数："<<endl;
	cin>>score;

	if(score >= 600)
	{
        cout<<"考上一本大学"<<endl;
        if(score >= 700)
        {
            cout<<"考上北大"<<endl;
        }
        else if(score >= 650)
        {
            cout<<"考上清华"<<endl;
        }
        else
        {
            cout<<"考上人大"<<endl;
        }
	}
	else if(score >= 500)
	{
        cout<<"考上二本大学"<<endl;
	}
	else if(score >= 400)
    {
        cout<<"考上三本大学"<<endl;
    }
    else
    {
        cout<<"未考上本科"<<endl;
    }


	return 0;
}