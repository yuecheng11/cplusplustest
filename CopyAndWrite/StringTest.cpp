#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	~String();
	String & operator=(const String & rhs);

	char & operator[](int idx);
	const char & operator[](int idx) const;

	int size();

	int use_count();

	const char * c_str() const
	{
		return _pstr;
	}

	void print() const
	{
		cout << _pstr << endl;
	}

private:
	char * _pstr;
};

String::String()
: _pstr(new char [2])
{
	cout << "String()" << endl;
	_pstr[1] = 1;//引用计数初始值为１
}

String::String(const char * pstr)
{
	cout << "String(const char * pstr)" << endl;
	int len = strlen(pstr);
	_pstr = new char[len + 2];
	strcpy(_pstr, pstr);
	_pstr[len + 1] = 1;//引用计数初始值为１
}


String::String(const String & rhs)
: _pstr(rhs._pstr)
{
	cout << "String(const String & rhs)" << endl;
	++_pstr[size()+ 1];
}

String & String::operator=(const String & rhs)
{
	cout << "String & operator=(const String &)" << endl;
	if(this == &rhs)
		return *this;
	if(--_pstr[size() + 1] == 0)
		delete [] _pstr;

	_pstr = rhs._pstr;
	++_pstr[size() + 1];

	return *this;
}

String::~String()
{
	if(--_pstr[size() + 1] == 0)	
	{	
		delete [] _pstr;
		cout << "~String()" << endl;
	}
}

const char & String::operator[](int idx) const
{
	cout << "const operator[]()" << endl;
	return _pstr[idx];
}

//该函数无法区分读操作和写操作
char & String::operator[](int idx)
{
	if(idx >= 0 && idx < size())
	{
		if(_pstr[size() + 1] == 1)
			return _pstr[idx];
		else
		{
			--_pstr[size() + 1];
			char * ptmp = _pstr;
			_pstr = new char[size() + 2];
			strcpy(_pstr, ptmp);
			_pstr[size() + 1] = 1;
			return _pstr[idx];
		}
	}
	else
	{
		static char nullchar = '\0';
		cout << "下标越界" << endl;
		return nullchar;
	}
}

int String::size()
{
	return strlen(_pstr);
}

int String::use_count()
{
	return _pstr[size()+ 1];
}


int main(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	String s3;
	s3 = s2;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());
	s1.print();
	s2.print();
	s3.print();

	String s4 = "test";

	s2 = s4;

	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;
	cout << "s4's use_count = " << s4.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());
	printf("s4's address = %p\n", s4.c_str());
	s1.print();
	s2.print();
	s3.print();
	s4.print();
/*
	s3[0] = 'H';
	cout << endl;
	cout << "修改s3之后" << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());
	s1.print();
	s2.print();
	s3.print();

	cout << endl << "执行读操作" << endl;
	cout << s1[0] << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	printf("s1's address = %p\n", s1.c_str());
	printf("s2's address = %p\n", s2.c_str());
	printf("s3's address = %p\n", s3.c_str());
	s1.print();
	s2.print();
	s3.print();

	cout << endl << endl;
	const String s4 = "wangdao";
	cout << s4[0] << endl;
	*/


return 0;
}
