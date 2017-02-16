 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-11 15:56:17
 ///
 
#include <stdio.h>
#include <iostream>
#include <memory>


using std::cout;
using std::endl;

int main(void)
{
	double * pd = new double(77.77);
	
	std::auto_ptr<double> apd(pd);
	cout << "*apd = " << *apd << endl;
	//cout << "ap = " << apd << endl;//没有这种用法
	//cout << "ap.get() = " << std::hex << apd.get() << endl;
	//cout << "pd = " << std::hex << pd << endl;


	cout << endl;
	int *pi = new int(10);
	printf("pi = %p\n", pi);
	std::auto_ptr<int> api(pi);
	std::auto_ptr<int> api2(api);//进行复制构造,发生了所有权的转移
	cout << "*api2 = " << *api2 << endl;
	printf("api2.get() = %p\n", api2.get());
	//cout << "*api = " << *api << endl;//segment error,显示是auto_ptr的缺陷
	
	cout << endl << endl;

	float * pf = new float(0.77f);
	std::auto_ptr<float> apf;
	//apf = pf;//error
	apf.reset(pf);
	cout << *apf << endl;

}
