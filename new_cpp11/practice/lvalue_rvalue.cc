 ///
 /// @file    lvalue_rvalue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-11 10:10:28
 ///
 
#include <iostream>
#include <vector>
#include <string>

using std::vector;


int test0(void)
{
	int a = 10;
	int b = 120;
	int *pflag = &a;
	vector<int> vctTmp;
	vctTmp.push_back(1);
	std::string str1 = "hello";
	std::string str2 = "world";
	const int & m = 1;

	&a;
	&b;
	//&(a + b);//右值
	//&(a++);//右值
	&(++a);//左值
	&pflag;
	&(*pflag);
	&vctTmp[0];
	//&100;//右值
	//&std::string("hello");//右值
	&str1;
	//&(str1 + str2);//右值
	&m;
}

int main(void)
{
	int ia = 10;
	int &refa = ia;
	const int ib = 3;
	const int &refb = ib;
	const int &refc = ia;
	const int &refd = 100;//const左值引用可以绑定到所有的数据上，
		//不管是左值还是右值
	//我们现在的需求是在语法层面能区分出右值来
	int && refe = 100;//右值引用就是为了区分出右值	
	//int && reff = ia;//右值引用不能绑定到左值
}
