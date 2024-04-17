#include "myArray.h"

MyArray::MyArray(int arrayCount)
{
	arraySize = arrayCount;
	if(arrayAddress != NULL)
	{
		arrayAddress = new int[this->arraySize];
	}
}

MyArray::MyArray(const MyArray &m)
{
	if(arrayAddress != NULL)
	{
		delete [] arrayAddress;
	}
	arrayAddress = new int[m.arraySize];
}

MyArray& MyArray::operator=(MyArray &m)
{
	this->arraySize = m.arraySize;
	return *this;
}

void MyArray::tailDelete()
{

}

void MyArray::tailInsert(int insertNum)
{

}

int MyArray::getElementCount()
{

}

int MyArray::getArraySize()
{

}