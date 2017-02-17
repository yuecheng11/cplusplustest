//智能指针技术
#include <iostream>
using std::cout;
using std::endl;


template <typename T>
class RAII
{
public:
	RAII(T * p) : _p(p)
	{
		cout << "RAII()" << endl;
	}
	T * get() const
	{
		return _p;
	}
	T & operator*()const
	{
		return *_p;
	}
	void reset(T * p)
	{
		delete _p;
		_p = p;
	}
	~RAII()
	{
		cout << "~RAII()" << endl;
		delete _p;
	}
private:
	RAII(const RAII & rhs);
	RAII & operator=(const RAII & rhs);
private:
	T * _p;
};

class SomeResource
{

};

class Example
{
public:
	Example()
	: _p1(new SomeResource)
	, _p2(new SomeResource)
	{
		cout << "Example()" << endl;
	}

	Example(const Example & rhs)
	: _p1(new SomeResource(*rhs._p1))
	, _p2(new SomeResource(*rhs._p2))
	{
		cout << "Example(const Example & rhs)" << endl;
	}

	Example & operator=(const Example & rhs)
	{
		if(this != &rhs)
		{
			*_p1 =  *rhs._p1;
			*_p2 =  *rhs._p2;
		}
		return *this;
	}

	~Example()
	{
		cout << "~Example()" << endl;
		//delete _p1;
		//delete _p2;
	}


private:
	RAII<SomeResource> _p1;
	RAII<SomeResource> _p2;
};

int main(void)
{
	//Example example;

	cout<<endl;
	int *p1 = new int(5);
	delete p1;
	cout << endl << endl;
	
	//RAII<int> raiiInt(new int(3));

	cout<<endl<<endl;

	int *ptest = new int[3];
	*ptest = 1;
	*(ptest+1) = 2;
	*(ptest+2) = 3;
	int *p = ptest;
	cout<<*p<<endl;
	cout<<*(p+1)<<endl;
	cout<<*(p+2)<<endl;
	//输出指针地址
	cout<<"ptest address : "<<static_cast<const void *>(ptest)<<endl;
	cout<<"p address : "<<static_cast<const void *>(p)<<endl;

	//new 的指针不需要手动释放，RAII 技术调用析构函数自动释放刚申请的空间
	RAII<int> raiitest(ptest);

	int *p2 = raiitest.get();
	cout<<*p2<<endl;
	cout<<*(p2+1)<<endl;
	cout<<*(p2+2)<<endl;

	cout<<"ptest address : "<<static_cast<const void *>(ptest)<<endl;
	cout<<"p2 address : "<<static_cast<const void *>(p2)<<endl;


	
	return 0;
}

