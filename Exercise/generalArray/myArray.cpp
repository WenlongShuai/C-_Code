#include "myArray.h"

template<class T>
MyArray<T>::MyArray(int arrayCount)
{
	// cout<<"构造函数"<<endl;
	this->arrayCapacitySize = arrayCount;
	this->arrayelementCount = 0;
	this->arrayAddress = new T[this->arrayCapacitySize];
}

template<class T>
MyArray<T>::~MyArray()
{
	if(this->arrayAddress != NULL)
	{
		// cout<<"析构函数"<<endl;
		delete [] this->arrayAddress;
		this->arrayAddress = NULL;
	}
}


template<class T>
MyArray<T>::MyArray(const MyArray &m)
{
	// cout<<"拷贝构造函数"<<endl;
	this->arrayCapacitySize = m.arrayCapacitySize;
	this->arrayelementCount = m.arrayelementCount;
	// this->arrayAddress = m.arrayAddress;  //浅拷贝。如果在堆区开辟空间了，这种写法会报错
	this->arrayAddress = new T[this->arrayCapacitySize];
	if(this->arrayAddress == NULL)
	{
		cout<<"MyArray(const MyArray &m) new fail"<<endl;
		return;
	}
	for(int i = 0;i < this->arrayelementCount;i++)
	{
		this->arrayAddress[i] = m.arrayAddress[i];
	}
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray &m)
{
	// cout<<"operator函数"<<endl;
	if(this->arrayAddress != NULL)
	{
		delete [] this->arrayAddress;
		this->arrayAddress = NULL;
	}

	this->arrayCapacitySize = m.arrayCapacitySize;
	this->arrayelementCount = m.arrayelementCount;
	this->arrayAddress = new T[this->arrayCapacitySize];
	if(this->arrayAddress == NULL)
	{
		cout<<"MyArray::operator=(const MyArray &m) new fail"<<endl;
		// return ;
	}
	for(int i = 0;i < this->arrayelementCount;i++)
	{
		this->arrayAddress[i] = m.arrayAddress[i];
	}
	return *this;
}

//为了让返回的值可以继续作为左值
template<class T>
T& MyArray<T>::operator[](int index)
{
	return this->arrayAddress[index];
}

template<class T>
void MyArray<T>::tailDelete()
{
	if(this->arrayelementCount == 0)
	{
		cout<<"array not element,delete fail"<<endl;
		return;
	}
	this->arrayelementCount--;
}


template<class T>
void MyArray<T>::tailInsert(T insertNum)
{
	if(this->arrayelementCount == this->arrayCapacitySize)
	{
		cout<<"array element full"<<endl;
		return;
	}
	this->arrayAddress[this->arrayelementCount] = insertNum;
	this->arrayelementCount++;
}

template<class T>
int MyArray<T>::getElementCount()
{
	return this->arrayelementCount;
}

template<class T>
int MyArray<T>::getArrayCapacitySize()
{
	return this->arrayCapacitySize;
}