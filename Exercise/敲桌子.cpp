#include <iostream>

using namespace std;

// 敲桌子
// 从1-100，只要数字的个位含有7,或者十位含有7,或者是7的倍数，这些情况都打印“敲桌子”

int main()
{
    for(int i = 1;i < 101;i++)
    {
        if((i%10==7) || (i/10%10==7) || (i%7 == 0))
        {
            cout<<"敲桌子"<<endl;
        }
        else
        {
            cout<<i<<endl;
        }
    }

	return 0;
}