 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-09 14:39:44
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

int func(int x, int y) // int(int,int)
{
	cout << "func(int,int)" << endl;
	return x + y;
}

class A
{
public:
	int funcA(int x, int y) // int(int,int)
	{
		cout << "A::funcA(int, int)" << endl;
		return x + y;
	}
};

int main(void)
{
	auto f1 = std::bind(func, 10, std::placeholders::_1);
	cout << f1(20) << endl;

	A a;
	auto f2 = std::bind(&A::funcA, a,
			std::placeholders::_1,
			std::placeholders::_2);
	cout << f2(1, 2) << endl;

	std::function<int(int)> f3 =
		std::bind(&A::funcA, a, std::placeholders::_1, 100);
	cout << f3(10) << endl;

	std::function<int()> f4 =
		std::bind(&A::funcA, a, 11, 22);
	cout << f4() << endl;

}
