#pragma once

#include <iostream>

using namespace std;

//类模板
template<class T>
class MyArray
{
public:

	//声明一个构造函数，可以传入数组的容量
	MyArray(int arrayCount);

	//拷贝构造函数，防止浅拷贝
	MyArray(const MyArray &m);

	//析构函数
	~MyArray();

	//成员函数重载运算符=
	MyArray& operator=(const MyArray &m);

	//尾删除
	void tailDelete();

	//尾插入
	void tailInsert(T insertNum);

	//成员函数重载运算符[]
	T& operator[](int index);

	//获取数组中当前元素个数
	int getElementCount();

	//获取数组的容量
	int getArrayCapacitySize();


private:
	int arrayCapacitySize;
	int arrayelementCount;
	T *arrayAddress;

};