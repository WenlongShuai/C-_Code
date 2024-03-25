#include <iostream>

using namespace std;

int main()
{

	//定义5只小猪体重的数组
	int arr[5] = {600,90,150,300,400};
	int max = arr[0];
	int j = 0;

	for(int i = 0;i < 5;i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
			j = i;
		}
	}
	cout<<"第"<<j+1<<"只小猪最重，体重为："<<max<<endl;

	return 0;
}