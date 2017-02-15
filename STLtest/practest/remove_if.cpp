 ///
 /// @file    remove_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-09 10:20:43
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vecInt;
	vecInt.reserve(10);
	cout << vecInt.size() << endl;
	cout << vecInt.capacity() << endl;

	for(int idx = 1; idx <= 10; ++idx)
	{
		vecInt.push_back(idx);
	}

	vecInt[3] = vecInt[5] = vecInt[9] = 99;
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << "vecInt'size = " << vecInt.size() << endl << endl;

	cout << "执行remove操作之后" << endl;
	//erase-remove 惯用法 --> 防止出现迭代器失效的问题
	vecInt.erase(remove(vecInt.begin(), vecInt.end(), 99),
			vecInt.end());
	cout << "vecInt'size = " << vecInt.size() << endl << endl;

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}


}
