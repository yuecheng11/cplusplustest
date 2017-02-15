//13-11 insert函数的使用1,2

#include <iostream>

#include <map>  //使用map必须要使用的头文件

#include <string>

using namespace std;

//#define T pair<int,string>

//#define MT map<int,string>

//#define MMT multimap<int,string>

int main()

{

  //insert()用法

  pair<int,string> sz[2] = { pair<int,string>(1,"A"), pair<int,string>(2,"B")};

  //创建一个pair<int,string>数组sz

  pair<int,string> t(2,"X");  //待插入的pair对象

  map<int,string> obM(sz,sz+2);  //基于sz创建map对象obM

  map<int,string>::iterator itM = obM.begin();  //创建map<int,string>类内迭代器itM

  pair<map<int,string>::iterator,bool> res = obM.insert(t);  //将t插入obM中，返回结果保存在对象res中

  //其类型为pair<map<int,string>::iterator,bool>

  if (res.second)  //判断是否插入成功

  cout << "插入成功" << endl;

  else

  cout << "map中已包含关键字与t相同的元素：" << (*res.first).first << " " << (*res.first).second << endl;

 
  for(map<int,string>::iterator it = obM.begin(); it != obM.end(); ++it)
  {
  	cout<<it->first<<" : "<<it->second<<endl;
  }

  cout<<endl;
  //insert()用法

  multimap<int,string> obDM(sz, sz+2);  //基于sz创建multimap对象obDM

  multimap<int,string>::iterator itDM = obDM.begin();  //创建multimap<int,string>类内迭代器itDM

  itDM=obDM.insert(t);  //执行插入操作

  cout<<"向multimap插入的元素为：" << (*itDM).first << " " << (*itDM).second << endl;

  for(multimap<int,string>::iterator it= obDM.begin(); it != obDM.end(); ++it)
  {
	  cout<<it->first<<" : "<<it->second<<endl;
  }

  //

  //getchar();

  return 0;
}
