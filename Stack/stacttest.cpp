#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename T,int NUM = 10>
class Stack
{
public:
	Stack():top(-1),elem(new T[NUM]){}
	~Stack();

	int GetStackSize();
	T& GetTopElem();

	bool full();
	bool empty();
	
	void push(const T& data);
	void pop();
private:
	
	//int _size;
	int top;
	T* elem;
};


template<typename T,int NUM>
Stack<T,NUM>::~Stack()
{
	if(elem != NULL)
	{
		delete [] elem;
	}
}

template<typename T,int NUM>
int Stack<T,NUM>::GetStackSize()
{
	return NUM;
}

template<typename T,int NUM>
T& Stack<T,NUM>::GetTopElem()
{
	if(!empty())
	{
		return elem[top];
	}
}

template<typename T,int NUM>
bool Stack<T,NUM>::full()
{
	return top == NUM - 1;
}

template<typename T,int NUM>
bool Stack<T,NUM>::empty()
{
	return top == -1;	
}

template<typename T,int NUM>
void Stack<T,NUM>::push(const T& data)
{
	if(full())
	{
		cout<<"stack is full"<<endl;
		return ;
	}
	top++;
	elem[top] = data;
}

template<typename T,int NUM>
void Stack<T,NUM>::pop()
{
	if(empty())
	{
		cout<<"Stack is empty"<<endl;
		return ;
	}
	
	top--;
}


int main()
{
	Stack<string,20> st;
	cout<<"stack capbility is : "<<st.GetStackSize()<<endl;

	cout<<"stack is empty: "<<st.empty()<<endl;

	st.push("test");
	cout<<"get top elem: "<<st.GetTopElem()<<endl;

	for(int i = 0;i<31;i++)
	{
		ostringstream oss;
		oss<<"index: "<<i;
		st.push(oss.str());
	}
	cout<<"stack is full: "<<st.full()<<endl;

	while(!st.empty())
	{
		cout<<st.GetTopElem()<<"  ";
		st.pop();
	}

	cout<<endl;
	cout<<"stack is empty: "<<st.empty();
	
	return 0;
}
