 ///
 /// @file    function.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 09:57:23
 ///
 
#include <iostream>
#include <functional>

using std::cout;
using std::endl;

struct Foo
{
public:
	Foo(int num): _num(num){}
	void print_add(int i) const
	{
		cout << _num + i << endl;
	}
private:
	int _num;
};


void print_num(int i)
{
	cout << "print_num(int) " << i << endl;
}


struct PrintNum
{
	void operator()(int i) const
	{
		cout << "PrintNum() " << i << endl;
	}
};


int main(void)
{
	std::function<void(int)> f1 = print_num;
	f1(-9);

	f1 = PrintNum();
	f1(100);

	std::function<void(const Foo &, int)> f2 = &Foo::print_add;
	const Foo foo(314159);
	f2(foo, 1);
	cout << endl;

	std::function<void()> f3 = std::bind(print_num, 111);
	f3();


	f3 = std::bind(&Foo::print_add, &foo, 110);
	f3();
}
