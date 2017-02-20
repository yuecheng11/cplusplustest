#include <iostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int y,int m,int d);
	//~Date();
	void printDate();
	void addOneday();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
private:
	int year;
	int month;
	int day;
};
Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}
Date::Date(int y,int m,int d)
	:year(y),month(m),day(d)
{
	
}

void Date::printDate()
{
	cout<<year<<"."<<month<<"."<<day<<endl;
}

void Date::addOneday()
{
	switch(month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if(day == 30)
		{
			day = 1;
			month++;
		}
		else
			day++;
	};
	break;
	
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
    case 10:
	case 12:
	{
		if(day == 31)
		{
			if(month == 12)
			{
				year++;
				month = 1;
			}
			else
			{
				month++;
			}
			day = 1;
		}
		else
			day++;
	};
	break;
	
	case 2:
	{
		if(((year % 4 == 0)&&(year % 100) != 0) || ((year % 400) == 0))
		{
			if(day == 28)
			{
				day = 1;
				month ++;
			}
			else
				day++;
		}
		else
		{
			if(day == 29)
			{
				day = 1;
				month ++;
			}
			else
				day++;
		}
	};
	break;
	}
}
void Date::setYear(int y)
{
	year = y;
}
void Date::setMonth(int m)
{
	month = m;
}
void Date::setDay(int d)
{
	day = d;
}

int main()
{
	Date date(2004,12,31);
	cout<<"init date: "<<endl;
	date.printDate();
	cout<<"ad one day: "<<endl<<endl;
	date.addOneday();
	date.printDate();
	cout<<endl<<endl;

	cout<<"modify date"<<endl;
	date.setYear(2000);
	date.setMonth(2);
	date.setDay(28);
	cout<<"date: "<<endl;
	date.printDate();

	cout<<endl<<endl;

	cout<<"ad one day: "<<endl<<endl;
	date.addOneday();
	date.printDate();

	return 0;
	
}