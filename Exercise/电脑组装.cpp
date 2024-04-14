#include <iostream>

using namespace std;

//需求
// 电脑主要组成部件:CPU(用于计算) 显卡(用于显示) 内存条(用于存储).
// 将每个部件封装成抽象类,并且提供不同的厂商生产不同的部件,例如:Intel厂商 Lenovo厂商
// 创建电脑类,让电脑工作的函数,并且调用不同厂商的部件.
// 测试时组装成3台不同的电脑.

//使用的方法是将厂商生产的部件分别定义为厂商CPU类,厂商VideoCard类,厂商Memory类.

//电脑部件抽象类
//CPU
class CPU
{
public:
	//纯虚函数
	//用于计算
	virtual void calculate() = 0;
};

//显卡抽象类
class VideoCard
{
public:
	//用于显示
	virtual void display() = 0;
};

//内存抽象类
class Memory
{
public:
	//用于存储
	virtual void storage() = 0;
};

//电脑类,根据不用厂商的部件进行组装
class Computer
{
public:
	Computer(CPU *cpu, VideoCard *vc, Memory *mem):m_cpu(cpu),m_vc(vc),m_mem(mem)
	{

	}
	~Computer()
	{
		if(m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if(m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if(m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

	void doWork()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

private:
	CPU *m_cpu;
	VideoCard *m_vc;
	Memory *m_mem;

};

//厂商类,用于生产不同部件
//Intel
class IntelCPU:public CPU
{
public:
	//子类重写父类的纯虚函数
	//CPU类的纯虚函数
	virtual void calculate()
	{
		cout<<"Intel CPU 开始计算"<<endl;
	}
};

class IntelVideoCard:public VideoCard
{
public:
	//子类重写父类的纯虚函数
	//VideoCard类的纯虚函数
	virtual void display()
	{
		cout<<"Intel videoCard 开始显示"<<endl;
	}
};


class IntelMemory:public Memory
{
public:
	//子类重写父类的纯虚函数
	//Memory类的纯虚函数
	virtual void storage()
	{
		cout<<"Intel storage 开始存储"<<endl;
	}
};


//Lenovo
class LenovoCPU:public CPU
{
public:
	//子类重写父类的纯虚函数
	//CPU类的纯虚函数
	virtual void calculate()
	{
		cout<<"Lenovo CPU 开始计算"<<endl;
	}
};

class LenovoVideoCard:public VideoCard
{
public:
	//子类重写父类的纯虚函数
	//VideoCard类的纯虚函数
	virtual void display()
	{
		cout<<"Lenovo videoCard 开始显示"<<endl;
	}
};


class LenovoMemory:public Memory
{
public:
	//子类重写父类的纯虚函数
	//Memory类的纯虚函数
	virtual void storage()
	{
		cout<<"Lenovo storage 开始存储"<<endl;
	}
};


int main()
{
	
	//选取不同厂商的部件
	CPU *cpu = new IntelCPU;
	VideoCard *vc = new IntelVideoCard;
	Memory *mem = new IntelMemory;
	
	//开始组装电脑
	cout<<"第一台电脑"<<endl;
	Computer *c = new Computer(cpu, vc, mem);
	c->doWork();
	delete c;

	cout<<"第二台电脑"<<endl;
	Computer *c2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	c2->doWork();
	delete c2;

	cout<<"第三台电脑"<<endl;
	Computer *c3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	c3->doWork();
	delete c3;

	return 0;
}