#include <iostream>

using namespace std;

//抽象类
//制作饮品的各种流程
class AbstractDrinking
{
public:

	//煮水
	virtual void boil() = 0;

	//冲泡
	virtual void brew() = 0;

	//倒入杯中
	virtual void pourInto() = 0;

	//加入辅料
	virtual void putSomething() = 0;

	void makeDrink()
	{
		boil();
		brew();
		pourInto();
		putSomething();
	}

};

//制作咖啡
class Coffee:public AbstractDrinking
{
public:
	//重写父类中的纯虚函数
	void boil()
	{
		cout<<"煮农夫三泉"<<endl;
	}

	void brew()
	{
		cout<<"冲泡"<<endl;
	}

	void pourInto()
	{
		cout<<"倒入杯中"<<endl;
	}

	void putSomething()
	{
		cout<<"放入糖和牛奶"<<endl;
	}
};

//制作凉茶
class Tea:public AbstractDrinking
{
public:
	//重写父类中的纯虚函数
	void boil()
	{
		cout<<"煮娃哈哈"<<endl;
	}

	void brew()
	{
		cout<<"冲泡"<<endl;
	}

	void pourInto()
	{
		cout<<"倒入杯中"<<endl;
	}

	void putSomething()
	{
		cout<<"放入柠檬"<<endl;
	}
};

void doWork(AbstractDrinking *abd)
{
	abd->makeDrink();
	delete abd;
}

int main()
{
	//使用多态制作饮品
	//制作咖啡
	doWork(new Coffee);

	//制作凉茶
	doWork(new Tea);

	return 0;
}