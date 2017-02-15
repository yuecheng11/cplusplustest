#include <iostream>
#include <set>
using namespace std;

int main()
{
	int arr[9] = {2,1,3,4,4,6,5,3,7};
	set<int> sz(arr,arr+9);
	cout<<"sz size is : "<<sz.size()<<endl;
	cout<<"print sz elem"<<endl;
	for(set<int>::iterator it = sz.begin();it != sz.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	set<int,greater<int> > sz1(arr,arr+9);
	cout<<"print sz1 elem"<<endl;
	for(set<int>::iterator it = sz1.begin();it != sz1.end();++it)
        {
                cout<<*it<<" ";
        }
        cout<<endl;


	multiset<int> mulsz(arr,arr+9);
	cout<<"print multisz elem"<<endl;
        for(set<int>::iterator it = mulsz.begin();it != mulsz.end();++it)
        {
                cout<<*it<<" ";
        }
        cout<<endl;	
	return 0;
}
