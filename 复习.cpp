// ConsoleApplication8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class cCopy
{
public:
	void disPlay();
	void setDate(int x,int y,int z);
	 cCopy();
	 cCopy(int x, int y, int z);
private:
	int year;
	int mounth;
	int day;
	int check();
};

cCopy::cCopy()
{
	year = 2019;
	mounth = 7;
	day = 9;
	
}
int cCopy:: check()
{
	int flatYearDays[12] = { 31,29,31,31,30,31,30,31,30,31,30,31 };
	int leapYearDays[12] = { 31,28,31,30,31,30,31,30,31,30,31,30 };
	if (mounth > 12 || mounth < 1)
	{
		mounth = 1;
		day++;
		return -1;
	}
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
void cCopy::setDate(int x, int y, int z)
{
	year = x;
	mounth = y;
	day = z;
	if (mounth < day || day < 1)
	{
		mounth = 1;
		day = 1;
		cout << "WRONG" << endl;
	}
}
cCopy::cCopy(int x, int y, int z)
{
	year = x;
	mounth = y;
	day = z;
	if (check() == 1 || check() == -1)
	{
		mounth = 1;
		day = -1;
		cout << "WRONG" << endl;
	}
}void cCopy::disPlay()
{
	cout << year << " " << mounth << " " << day << " " << endl;
}
int main()
{
	cCopy od;
	od.setDate(2019,13,39);
	od.disPlay();
	return 0;
}
