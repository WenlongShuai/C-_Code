// 有三只小猪ABC，分别输入他们的体重，判断哪个小猪最重

#include <iostream>

using namespace std;


int main()
{
	float A = 0.0f;
	float B = 0.0f;
	float C = 0.0f;

	cout<<"请分别输入三只小猪的体重："<<endl;
	cout<<"A的体重：";
	cin>>A;
	cout<<"B的体重：";
	cin>>B;
	cout<<"C的体重：";
	cin>>C;


	if(A > B)
	{
		if(A > C)
		{
			cout<<"A的体重最重"<<endl;
		}
		else
		{
			cout<<"C的体重最重"<<endl;
		}
	}
	else
	{
		if(B > C)
		{
			cout<<"B的体重最重"<<endl;
		}
		else
		{
			cout<<"C的体重最重"<<endl;
		}
	}

	return 0;
}