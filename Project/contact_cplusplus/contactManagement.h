// #pragma once
#ifndef __CONTACTMANAGEMENT_H__
#define __CONTACTMANAGEMENT_H__

#include <iostream>
#include <string>
using namespace std;

enum Sex
{
	male,
	female,
	secrecy
};

class ContactManagement
{
public:
	ContactManagement();
	~ContactManagement();
	void setName(string name);
	void setSex(enum Sex sex);
	void setAge(int age );
	void setPhoneNum(string phone);
	void setAddress(string address);

	string getName();
	int getSex();
	int getAge();
	string getPhoneNum();
	string getAddress();

	//操作相关的成员函数
	void printMenu();
	void addContact(string name, enum Sex sex, int age, string phoneNum, string address);
	void printContact();




private:
	string name;
	enum Sex sex;
	int age;
	string phoneNum;
	string address;
	ContactManagement *next;

};

#endif   //__CONTACTMANAGEMENT_H__
