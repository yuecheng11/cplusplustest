 ///
 /// @file    repalce_if.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-09 10:08:38
 ///
 

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;



int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	std::vector<int> vecInt(arr, arr + 6);
	std::less<int> lt;//gt 
	replace_if(vecInt.begin(), vecInt.end(), 
				std::bind1st(lt, 3), 7);
	
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl << endl;
	sort(vecInt.begin(), vecInt.end());
	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl << endl;

	
}
