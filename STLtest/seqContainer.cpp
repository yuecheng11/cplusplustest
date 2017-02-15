#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

void dispvec(vector<int> &vec)
{
	cout<<"print vector elem"<<endl;
	for(vector<int>::iterator it = vec.begin();it != vec.end();++it)
	{
		cout<<" "<<*it;
	}

	cout<<endl<<endl;
}
int main()
{
	vector<int> obv(5,1);
	cout<<"obv elem number is : "<<obv.size()<<endl<<endl;
	dispvec(obv);
	vector<int>::iterator it = obv.end();
	obv.insert(it,3);//在尾部插入一个元素
	dispvec(obv);
	
	it = obv.end();
	obv.insert(it,2,3);//在为不插入两个元素
	dispvec(obv);


	int arr[3] = {1,2,3};
	it = obv.begin();
	obv.insert(it,arr,arr+3);//在头部插入从arr到arr+3地址之间的元素，迭代起失效
	dispvec(obv);
	/*double sz[5] = {2,1,3,5,4};
	deque<double> obD(sz,sz+5);

	cout<<"print deque elem use operator[]"<<endl;
	for(int i = 0;i<obD.size();++i)
	{
		cout<<" "<<obD[i];
	}
	cout<<endl;
	
	cout<<"print deque elem use iterator"<<endl;
	for(deque<double>::iterator it = obD.begin();it != obD.end();++it)
	{
		cout<<" "<<*it<<endl;
	}
	cout<<endl;

	
	list<double> obl(sz,sz+5);
	cout<<"print list ob1 elem use"<<endl;
	for(list<double>::iterator it = obl.begin();it != obl.end();++it)
	{
		cout<<" "<<*it<<endl;
	}
	cout<<endl;

	list<double> oblcopy(10,2.1);
	cout<<"print oblcopy elem use iterator"<<endl;
	for(list<double>::iterator it = oblcopy.begin();it != oblcopy.end();++it)
	{
		cout<<" "<<*it<<endl;
	}
	cout<<endl;

	obl.swap(oblcopy);

	cout<<"exchange ob1 and ob2 elem"<<endl;
	
	cout<<"print list ob1 elem use"<<endl;
	for(list<double>::iterator it = obl.begin();it != obl.end();++it)
	{
		cout<<" "<<*it<<endl;
	}
	cout<<endl;

	cout<<"print oblcopy elem use iterator"<<endl;
	for(list<double>::iterator it = oblcopy.begin();it != oblcopy.end();++it)
	{
		cout<<" "<<*it<<endl;
	}
	cout<<endl;
	*/
	return 0;
}
