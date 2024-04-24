#include <iostream>

using namespace std;

//基类
class Animal
{
public:
	Animal()
	{
		cout<<"Animal 的构造函数"<<endl;
	}

	//如果写成这种析构函数,那么子类的析构函数就不会去执行,子类在堆区开辟的空间也得不到释放,就会存在内存泄露.
	// ~Animal()
	// {
	// 	cout<<"Animal 的析构函数"<<endl;
	// }

	//虚析构,可以解决父类的指针释放子类对象时,子类的析构不能执行的问题.
	// virtual ~Animal()
	// {
	// 	cout<<"Animal 的析构函数"<<endl;
	// }

	//纯虚析构,虚析构和纯虚析构只能有一个
	//需要声明也要实现
	virtual ~Animal() = 0;  //这里只是声明,但是有时候父类也在堆区开辟空间,如果只声明析构函数,不去实现析构函数,那么也会存在内存泄露

	//虚函数,子类必须要重写
	// virtual void speak()
	// {
	// 	cout<<"动物在说话"<<endl;
	// }

	//纯虚函数
	virtual void speak() = 0;

};

//纯虚函数的实现
Animal::~Animal()
{
	cout<<"Animal 的析构函数"<<endl;
}

//派生类
class Cat:public Animal
{
public:
	Cat(string name)
	{
		m_Name = new string(name);
		cout<<"Son 的构造函数"<<endl;
	}

	~Cat()
	{
		if(m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
		cout<<"Son 的析构函数"<<endl;
	}

	void speak()
	{
		cout<<*m_Name<<" cat在说话"<<endl;
	}

	string *m_Name;

};


int main()
{
	//虚析构和纯虚析构
	//问题:父类指针释放子类对象,子类对象又在堆区申请了空间,那么子类的析构函数能不能调用呢.
	Animal *animal = new Cat("Tom");
	animal->speak();
	delete animal;
	
	return 0;
}