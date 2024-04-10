#include <iostream>

using namespace std;

//父类
class Base1
{
public:
	int m_A;
private:
	int m_B;
protected:
	int m_C;
};

//1 子类以public的方式继承父类
class Son1:public Base1
{
public:
	void func()
	{
		m_A = 10;//父类的public权限的成员 到子类中依然是public权限
		// m_B = 10;//父类的private权限的成员 到子类中依然是private权限.这里会报错,因为不管是什么继承方式,父类的private权限的成员,子类访问不到.但是继承过来了,只是被编译器隐藏了.
		m_C = 10;//父类的protected权限的成员 到子类依然是protected权限
	}
};

void test01()
{
	Son1 son1;
	son1.m_A = 100;//访问子类中public权限的成员
	// son1.m_B = 100;//报错.因为子类访问不到父类的private权限的成员,所以类外也访问不到.
	// son1.m_C = 100;//访问子类中protected权限的成员.报错.因为子类的protected权限的成员类外不能访问,只能类内访问.
}

//2 子类以provate的方式继承父类
class Son2:private Base1
{
public:
	void func()
	{
		m_A = 200;//父类的public权限的成员,到子类就成了private权限的成员.
		// m_B = 200;//父类的private成员,子类访问不到.报错.因为子类不能访问父类的private权限的成员.但是继承过来了,只是被编译器隐藏了.
		m_C = 200;//父类的protected的成员,到子类就成了private权限的成员.
	}
};

void test02()
{
	Son2 son2;
	// son2.m_A = 300;//报错,因为子类的private权限的成员,类外不能访问
	// son2.m_B = 300;//报错,因为子类不能访问父类的private权限的成员,所以类外更不能访问了.
	// son2.m_C = 300;//报错,因为子类的private权限的成员,类外不能访问
}

//3 子类以protected权限继承父类
class Son3:protected Base1
{
public:
	void func()
	{
		m_A = 400;//父类中的public权限的成员,到子类就成了protected权限的成员.
		// m_B = 400;//父类中的private权限的成员,子类访问不到.报错.因为子类不能访问父类private权限的成员.但是继承过来了,只是被编译器隐藏了.
		m_C = 400;//父类中的protected权限的成员,到子类就成了protected权限的成员.
	}
};

void test03()
{
	Son3 son3;
	// son3.m_A = 500;//访问父类protected权限的成员.报错。因为子类中的protected权限的成员在类外不能访问。
	// son3.m_B = 500;//报错,因为子类不能访问父类的private权限的成员,所以类外更不能访问了.
	// son3.m_C = 500;//访问父类protected权限的成员.报错。因为子类中的protected权限的成员在类外不能访问。
}


int main()
{
	//继承的方式
	//1 子类以public的方式继承
	test01();

	//2 子类以private权限方式访问
	test02();

	//3 子类以protected权限方式访问
	test03();


	return 0;
}