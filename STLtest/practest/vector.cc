 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-09 10:55:54
 ///
 
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vecInt;
	vecInt.push_back(1);

	int idx = 2;
	
	vector<int>::iterator it = vecInt.begin();
	for(; it != vecInt.end(); ++it)
	{
		cout << *it << " ";
		vecInt.push_back(idx);//迭代器失效
		++idx;
	}

	
}
