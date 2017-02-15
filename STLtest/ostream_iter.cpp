#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//流输出迭代器
	int arr[6] = {2,1,4,3,6,5};
	vector<int> ob(arr,arr+6);
	ostream_iterator<int, char> osi(cout," ");   //创建输出流迭代器osi
	copy(ob.begin(),ob.end(),osi);               //将Ob复制到流中，copy泛型算法
	cout<<endl;

	//流输入迭代器
	vector<int> vec;
	istream_iterator<int,char> isi(cin);
	copy(isi,istream_iterator<int,char>(),back_inserter(vec)); //将输入流插入到ob中

	for(auto & elem : vec)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	return 0;
	
}
