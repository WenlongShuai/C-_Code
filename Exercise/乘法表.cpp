#include <iostream>

using namespace std;


//打印9*9乘法表
int main()
{
	int i = 1;
	int j = 1;

	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<j<<"*"<<i<<"="<<i*j<<'\t';
		}
		cout<<endl;
	}

	return 0;
}