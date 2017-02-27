
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;


const float PI = 3.14159f;

class Figure
{
public:
	typedef std::function<void()> DispCallback;
	typedef std::function<float()> AreaCallback;
public:
	Figure()
	{}

	Figure(DispCallback dispCb, AreaCallback areaCb)
	: _dispCb(dispCb)
	, _areaCb(areaCb)
	{}

	void setDispCallback(DispCallback dispCb)
	{
		_dispCb = dispCb;
	}

	void setAreaCallback(AreaCallback areaCb)
	{
		_areaCb = areaCb;
	}

	void runDispCallback()
	{
		if(_dispCb)
			_dispCb();
	}

	float runAreaCallback()
	{
		if(_areaCb)
		{
			return _areaCb();
		}
	}

private:
	DispCallback _dispCb;
	AreaCallback _areaCb;
};


class Circle
{
public:
	Circle(int radius)
	: _radius(radius)
	{}

	void display()
	{
		cout << "Circle:";
	}

	float area()
	{
		
		return  PI * _radius * _radius;

	}
	
private:
	int _radius;
};


class Rectangle
{
public:
	Rectangle(int x, int y)
	: _x(x)
	, _y(y)
	{}

	void print()
	{
		cout << "Rectangle:";
	}

	float calcArea()
	{
		return _x * _y;
	}

private:
	int _x;
	int _y;
};


int main(void)
{
	Figure figure;
	Circle circle(3);

	figure.setDispCallback(std::bind(&Circle::display, &circle));
	figure.setAreaCallback(std::bind(&Circle::area, &circle));

	figure.runDispCallback();
	cout << figure.runAreaCallback() << endl;

	Rectangle rectangle(4, 5);
	figure.setDispCallback(std::bind(&Rectangle::print, &rectangle));
	figure.setAreaCallback(std::bind(&Rectangle::calcArea, &rectangle));

	figure.runDispCallback();
	cout << figure.runAreaCallback() << endl;

	return 0;
}
