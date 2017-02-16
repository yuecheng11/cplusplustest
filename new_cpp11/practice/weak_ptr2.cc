 ///
 /// @file    weak_ptr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-11 17:12:27
 ///
 
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class X
{
public:
	X(){	cout << "X()" << endl;	}
	~X(){	cout << "~X()" << endl;	}
	void func()
	{	cout << "X::func()" << endl;	}
};

int main(void)
{
	std::weak_ptr<X> p;
	{
		std::shared_ptr<X> p2(new X);
		cout << "p2.use_count() = " << p2.use_count() <<endl;

		p = p2;//把一个shared_ptr对象赋值给一个weak_ptr对象，引用计数不会加1
		cout << "after p = p2" << endl;
		cout << "p2.use_count() = " << p2.use_count() <<endl;

		std::shared_ptr<X> p3 = p.lock();//将p提升为shared_ptr
		if(!p3)
		{//提升失败
			cout << "object has been destroyed!" << endl;
		}
		else
		{
			p3->func();
			cout << p3.use_count() << endl;
		}
	}
	
	std::shared_ptr<X> p4 = p.lock();
	if(!p4)
	{
		cout << "object has been destroyed!" << endl;
	}
	else
	{
		p4->func();
		cout << p4.use_count() << endl;
	}

}
