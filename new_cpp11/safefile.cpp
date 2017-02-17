#include <iostream>
#include <stdio.h>
//1,保证文件句柄在构造函数中初始化，2,析构时释放资源
//3，一般不允许复制拷贝或赋值（对象语义） 4,提供若干访问资源的方法

//RAII对象本质使用栈对象来管理资源，栈对象在离开作用域，自动调用析构函数
using namespace std;

class Safefile
{
public:
	Safefile(const char* filename)
	:_fileHandle(fopen(filename,"w+"))
	{	
		cout<<"Safefile(const char* filename)"<<endl;
		if(_fileHandle == NULL)
		{
			cout<<"file open error"<<endl;
			return ;
		}
	}

	void write(const char* str)
	{
		if(fputs(str, _fileHandle)==EOF)
		{
			cout << "to the file end" << endl;
			return ;
		}
	}
	void write(const char* buf,size_t num)
	{
		if(num != 0 && 
			fwrite(buf,sizeof(char),num,_fileHandle) == 0)
		{
			cout<<"write file error"<<endl;
			return ;
		}
	}
	~Safefile()
	{
		cout<<"~Safefile()"<<endl;
		if(_fileHandle)
			fclose(_fileHandle);
	}
private:
		SafeFile(const SafeFile & rhs);
		SafeFile & operator=(const SafeFile & rhs);

private:
	FILE* _fileHandle;
};

int main()
{
	Safefile sf("yc.txt");
	sf.write("hello RAII");

	char ch[10] = {'2','3','s','s','2','3','s','s','3','s'};
	sf.write(ch,10);

	return 0;
}
