 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-11 14:55:40
 ///
 
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

class SafeFile
{
public:
	SafeFile(const char * filename)
	: _fileHandler(fopen(filename, "w+"))
	{
		cout << "SafeFile(const char * )" << endl;
		if(_fileHandler == NULL)
		{
			cout << "fileopen error!" << endl;
			return;
		}
	}

	void write(const char * str)
	{
		if(fputs(str, _fileHandler)==EOF)
		{
			cout << "to the file end" << endl;
			return ;
		}
	}

	void write(const char * buf, size_t num)
	{
		if(num != 0 && fwrite(buf, num, 1, _fileHandler)==0)
		{
			cout << "write error!" << endl;
			return;
		}
	}

	~SafeFile()
	{
		cout << "~SafeFile()" << endl;
		if(_fileHandler)
			fclose(_fileHandler);
	}

private:
	SafeFile(const SafeFile & rhs);
	SafeFile & operator=(const SafeFile & rhs);
private:
	FILE * _fileHandler;
};


int main(void)
{
	SafeFile sf("foo.test");
	sf.write("Hello RAII");
	return 0;
}
