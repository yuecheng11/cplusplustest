 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-11 16:15:53
 ///
 
#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

std::unique_ptr<int> getValue()
{
	std::unique_ptr<int> up(new int(88));
	return up;
}


int main(void)
{
	std::unique_ptr<int> ap(new int(88));
	//std::unique_ptr<int> one(ap);//error无法复制或赋值
	//std::unique_ptr<int> two = ap;//error,调用复制构造函数
	
	//getValue() 返回的是一个匿名对象，即右值,此时，就会调用
	//移动构造函数-->unique_ptr具有移动语义
	std::unique_ptr<int> uptr = getValue();

	std::unique_ptr<int> up(new int(99));
	//使用move函数,显式的告诉我们要发生所有权的转移
	std::unique_ptr<int> up2 = std::move(up);

	cout << "*up2 = " << *up2 << endl;
	cout << endl;

	vector<std::unique_ptr<int> > vec;
	vec.push_back(std::move(up2));//可以作为容器的元素
}


