#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0,int y = 0)
	:_ix(x)
	,_iy(y)
	{
		cout<<"Point(int x,int y)"<<endl;
	}

	Point(const Point& rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		cout<<" Point(const Point& rhs) "<<endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

Point func()
{
	Point tmp(1,2);
	return tmp;
}

int main()
{
	//Point p = func();
	Point p = 1;
	
	return 0;
}