 ///
 /// @file    priority_queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-09 11:26:34
 ///
 
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

//优先级队列：采用的是堆排序;当添加新的元素时
//堆顶元素要跟新元素进行比较，如果返回值是true，
//则新元素跟堆顶元素进行交换;否则不交换
//如果比较器是<,则按降序排列；
//如果比较器是>,则按升序排列

int main(void)
{
	int arr[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};
	priority_queue<int, vector<int>, std::greater<int> > priQue;
	for(int idx = 0; idx != 10; ++idx)
	{
		priQue.push(arr[idx]);
		cout << priQue.top() 
			 << "是目前队列里面优先级别最高的"
			 << endl;
	}

	for(int idx = 0; idx != 10; ++idx)
	{
		cout << priQue.top() << " ";
		priQue.pop();
	}




}
