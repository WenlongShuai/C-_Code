#include <iostream>


using namespace std;

//交换两个数位置的函数模板
//声明创建一个函数模板
template <class T>
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


//声明创建一个函数模板
template <typename T>
void mySelectionSort(T *Arr, int len)
{
	int max = 0;
	for(int i = 0;i < len;i++)
	{
		max = i;
		for(int j = i+1;j<len;j++)
		{
			if(Arr[max] < Arr[j])
			{
				max = j;
			}
		}
		if(max != i)
		{
			mySwap(Arr[max], Arr[i]);
		}
	}
}

//声明创建一个函数模板
template<class T>
void printArr(T *Arr, int len)
{
	for(int i = 0;i<len;i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	//利用函数模板实现选择排序,对不同的数据类型排序
	//int数组
	int intArr[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(intArr) / sizeof(intArr[0]);
	mySelectionSort(intArr, len);
	printArr(intArr, len);

	//char数组
	// char charArr[] = "abcdef";
	// int len = sizeof(charArr)/sizeof(charArr[0]);
	// mySelectionSort(charArr, len);
	// printArr(charArr, len);



	return 0;
}