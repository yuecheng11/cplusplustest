 ///
 /// @file    sort.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-09 11:06:26
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	int arr[10] = {9, 6, 3, 2, 1, 4, 7, 0, 5, 8};
	vector<int> vecInt(arr, arr + 10);
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;

	sort(vecInt.begin(), vecInt.end());
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;


}

