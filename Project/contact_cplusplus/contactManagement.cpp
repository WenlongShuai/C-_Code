#include "contactManagement.h"

ContactManagement::ContactManagement()
{
		next = new ContactManagement[10];
}
ContactManagement::~ContactManagement()
{
	if(next != NULL)
	{
		delete [] next;
		next = NULL;
	}
}
void ContactManagement::setName(string name)
{
	this->name = name;
}
void ContactManagement::setSex(enum Sex sex)
{
	this->sex = sex;
}
void ContactManagement::setAge(int age )
{
	this->age = age;
}
void ContactManagement::setPhoneNum(string phoneNum)
{
	this->phoneNum = phoneNum;
}
void ContactManagement::setAddress(string address)
{
	this->address = address;
}

string ContactManagement::getName()
{
	return name;
}
int ContactManagement::getSex()
{
	return sex;
}
int ContactManagement::getAge()
{
	return age;
}
string ContactManagement::getPhoneNum()
{
	return phoneNum;
}
string ContactManagement::getAddress()
{
	return address;
}

void ContactManagement::printMenu()
{
	cout<<"--------------------------"<<endl;
	cout<<"------0、exit  1、add------"<<endl;
	cout<<"--------------------------"<<endl;
}

void ContactManagement::addContact(string name, enum Sex sex, int age, string phoneNum, string address)
{
	next->name = name;
	next->sex = sex;
	next->age = age;
	next->phoneNum = phoneNum;
	next->address = address;
}

void ContactManagement::printContact()
{
	cout<<"姓名:"<<name<<"\t"<<"性别:"<<sex<<"\t"<<"年龄:"<<age<<"\t"<<"电话:"<<phoneNum<<"\t"<<"地址:"<<address<<endl;
}