// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class cMyTime
{
public:
	cMyTime();
	cMyTime(int x, int y, int z);
	int setTime(int x,int y,int z);
	void disPlay();
private:
	int year;
	int mounth;
	int day;
	int check();

};
cMyTime::cMyTime()
{
	year = 2019;
	mounth = 6;
	day = 17;

}
cMyTime::cMyTime(int x, int y, int z)
{
	year = x;
	mounth = y;
	day = z;
	if (check() == 1 || check() == -1)
	{
		mounth = 1;
		day = 1;
		cout << "WRONG" << endl;
	}
}
int  cMyTime::setTime(int x, int y, int z)
{
	year = x;
	mounth = y;
	day = z;
	if (check() == 1 || check() == -1)
	{
		mounth = 1;
		day = 1;
		cout << "WRONG" << endl;
		return -1;
	}
	return 0;
}
int cMyTime::check()
{
	int flatYearDays[12] = { 31,29,31,30,31,30,31,30,31,30,31,30 };
	int leapYearDays[12] = { 31,28,31,30,31,30,31,30,31,30,31,30 };
	if (mounth > 12 || mounth < 1)
	

		return -1;
	
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
	{
		if (flatYearDays[mounth - 1] < day || day < 1)
			
		return 1;
	}
	else 
	{
			if (leapYearDays[mounth - 1] < day || day < 1)
			
				return 1;
		}
		
	return 0;
	
	}
void cMyTime::disPlay()
{
	cout << year << " " << mounth << " " << day << " " << endl;
}



int main()
{
	cMyTime obj;
	obj.setTime(2019, 6, 71);
	obj.disPlay();
    return 0;
}

