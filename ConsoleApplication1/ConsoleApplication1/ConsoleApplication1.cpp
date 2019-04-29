// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class COnir
{
public:
	COnir();
	COnir(int x, int y, int z, int h, int w, int r);
	void setDate(int x, int y, int z);
	void setTime(int h, int w, int r);
	void addOneDay();
	void addOneSecond();
	void putOut();
private:
	int year;
	int mounth;
	int day;
	int hour;
	int minute;
	int second;
	int check();
	int list();
};
COnir::COnir()
{
	year = 2019;
	mounth = 2;
	day = 23;
	hour = 9;
	minute = 03;
	second = 01;
}
COnir::COnir(int x, int y, int z, int h, int w, int r)
{
	year = x;
	mounth = y;
	day = z;
	hour = h;
	minute = w;
	second = r;
	if (check() == 1 || check() == -1)
	{
		mounth = 1;
		day = 1;
		cout << "WRONG" << endl;
	}

}
void COnir::setDate(int x, int y, int z)
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
void COnir::setTime(int h, int w, int r)
{
	hour = h;
	minute = w;
	second = r;
	if (check() == 1 || check() == -1)
	{
		minute = 4;
		second = 30;
		cout << "WRONG" << endl;

	}

}
int COnir::list()
{
	if (hour < 1 || hour>24)
		return 1;
	if (minute < 1 || minute>60)
		return 1;
	if (second < 1 || second>60)
		return 1;
}
int COnir::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,30,31,30,31,30 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,30,31,30,31,30 };
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
void COnir::putOut()
{
	cout << year << " " << mounth << " " << day << " " << endl << hour << " " << minute << " " << second << " " << endl;
}
void COnir::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,30,31,30,31,30 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,30,31,30,31,30 };
	day++;
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
	{
		if (flatYearDays[mounth - 1] < day)
			mounth++;
		day = 1;
	}
	else
	{
		if (leapYearDays[mounth - 1] < day)
			mounth++;
		day = 1;
	}
	if (mounth > 12)
	{
		year++;
		mounth = 1;
	}
}
void COnir::addOneSecond()
{

}

int main()
{
	COnir W;
	W.setDate(2019, 4, 56);
	W.setTime(6, 32, 35);
	W.putOut();
	return 0;
}

