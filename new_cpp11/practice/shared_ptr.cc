 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-11 16:33:05
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class Child;
class Parent
{
public:
	Parent(){	cout << "Parent()" << endl;	}
	~Parent(){	cout << "~Parent()" << endl;	}

	std::shared_ptr<Child> _childPtr;

};

class Child
{
public:
	Child(){	cout << "Child()" << endl;	}
	~Child(){	cout << "~Child()" << endl;	}
	std::shared_ptr<Parent> _parentPtr;
};

int main(void)
{
	std::shared_ptr<Child> childPtr(new Child);
	std::shared_ptr<Parent> parentPtr(new Parent);
	cout << "Child's use_count() = " << childPtr.use_count() << endl;
	cout << "Parent's use_count() = " << parentPtr.use_count() << endl;
	childPtr->_parentPtr = parentPtr;
	parentPtr->_childPtr = childPtr;

	cout << "Child's use_count() = " << childPtr.use_count() << endl;
	cout << "Parent's use_count() = " << parentPtr.use_count() << endl;

	return 0;
}

