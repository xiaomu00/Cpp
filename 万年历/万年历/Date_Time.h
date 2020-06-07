#ifndef _DATE_TIME_H_
#define _DATE_TIME_H_

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<assert.h>
using namespace std;


//日期
struct Date
{
	int m_year;
	int m_month;
	int m_day;
};
//时间
struct Time
{
	int m_hour;
	int m_minute;
	int m_second;
};



//函数声明
class Date_Time;
ostream& operator<<(ostream &out, const Date_Time &dt);
//求后n天是几月几号
void NextDateTime();
//判断某年是否是闰年
bool Judgment_Leap_year(int year);



class Date_Time
{
	//友元函数声明
public:
	friend ostream& operator<<(ostream &out, const Date_Time &dt);
	friend void NextDateTime();

public:
	Date_Time();



	//运算符重载函数声明
public:
	int operator-(const Date_Time& dt);
	Date_Time& operator++();
	Date_Time& operator--();
	Date_Time operator++(int);
	Date_Time operator--(int);
	Date_Time& operator+=(int n);
	Date_Time& operator-=(int n);


	bool operator==(const Date_Time& dt);
	bool operator!=(const Date_Time& dt);
	bool operator>(const Date_Time& dt);
	bool operator<(const Date_Time& dt);
	bool operator>=(const Date_Time& dt);
	bool operator<=(const Date_Time& dt);



	//功能函数声明
public:
	//获取当前时间
	Date_Time getcordatetime();

	void cin_date();

	//显示当前时间
	void showdatetime();

	//判断输入日期的合法性
	bool Legitimacy_day(int year, int month, int day);

	//求某年某月某日是星期几
	int GetWeekByYMD(int year, int month, int day);

	//求某年某月某日是本年的第几天
	int Getsum_day(int year, int month, int day);

	//动态显示万年历和时间
	void DateCalendar_Time();



	
	//求前n天是几月几号
	Date_Time PrevDateTime(int n);
	



	//类成员
private:
	Date m_date;
	Time m_time;
	int* m_run;
	int* m_ping;
};

#endif /*DATE_TIME_H_*/