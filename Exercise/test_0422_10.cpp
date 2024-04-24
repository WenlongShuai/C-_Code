#include <iostream>

using namespace std;

#include <vector>
void printVector(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{	
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	// 容量和大小的函数原型：
	// empty();  //判断容器是否为空
	// capacity(); //返回容器的容量
	// size();   //返回容器中元素的个数
	// resize(int num);  //重新指定容器的长度为num，若容器的长度变长，则以默认值填充新位置。如果容器的长度变短，则末尾超出容器长度的部分元素被删除。
	// resize(int num, elem); //重新指定容器的长度为num，若容器的长度变长，则以elem值填充新位置。如果容器的长度变短，则末尾超出容器长度的部分元素被删除。

	vector<int> v;
	for(int i=1;i<11;i++)
	{
		v.push_back(i);
	}
	printVector(v);

	//empty();
	if(v.empty())
	{
		cout<<"为空"<<endl;
	}
	else
	{
		cout<<"不为空"<<endl;
		cout<<"容量:"<<v.capacity()<<endl;
		cout<<"大小:"<<v.size()<<endl;
	}

	//resize(int num);
	//长度变长
	v.resize(20);
	cout<<"容量:"<<v.capacity()<<endl;
	cout<<"大小:"<<v.size()<<endl;
	printVector(v);

	//长度变短
	v.resize(5);
	cout<<"容量:"<<v.capacity()<<endl;
	cout<<"大小:"<<v.size()<<endl;
	printVector(v);

	//resize(int num, elem);
	v.resize(20, 100);
	cout<<"容量:"<<v.capacity()<<endl;
	cout<<"大小:"<<v.size()<<endl;
	printVector(v);




	return 0;
}