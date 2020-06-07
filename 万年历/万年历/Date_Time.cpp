#include"Date_Time.h"

#define ESC 0x1b

//隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO  cursor_info = { 100, 0 };
	HANDLE handle = GetStdHandle(STD_ERROR_HANDLE);
	SetConsoleCursorInfo(handle, &cursor_info);
}

//显示光标
void ShowCursor()
{
	CONSOLE_CURSOR_INFO  cursor_info = { 10, 1 };
	HANDLE handle = GetStdHandle(STD_ERROR_HANDLE);
	SetConsoleCursorInfo(handle, &cursor_info);
}

//时间初始化
Date_Time::Date_Time()
{
	m_date.m_year = 0000;
	m_date.m_month = 00;
	m_date.m_day = 00;

	m_time.m_hour = 00;
	m_time.m_minute = 00;
	m_time.m_second = 00;

	m_run = new int[13]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	m_ping = new int[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
}




/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//运算符重载
ostream& operator<<(ostream &out, const Date_Time &dt)
{
	out << dt.m_date.m_year << "年" << dt.m_date.m_month << "月" << dt.m_date.m_day << "日  ";
	out << dt.m_time.m_hour << "时" << dt.m_time.m_minute << "分" << dt.m_time.m_second << "秒";

	return out;
}

Date_Time& Date_Time::operator += (int n)
{
	assert(n>=0);
	int sum = 0;
	int m = n;
	int s = Getsum_day(m_date.m_year,m_date.m_month,m_date.m_day);

	if (!(Judgment_Leap_year(m_date.m_year)))
	{
		 sum = 365 - s;
	}
	else sum = 366 - s;


	if (n > sum)
	{
		m_date.m_year++;
		n = n - sum;
	}
	while (n >= 365)
	{
		m_date.m_year++;
		n = n - 365;
		
		if (Judgment_Leap_year(m_date.m_year))
		{
			n--;
		}
	}

	
	if (Judgment_Leap_year(m_date.m_year))
	{
		int m_sum = m_run[m_date.m_month] - m_date.m_day;
		if (n > m_sum)
		{
			m_date.m_month ++;
			n -= m_sum;
		}

		while (n >= m_run[m_date.m_month])
		{
			m_date.m_month++;
			n -= m_run[m_date.m_month];
		}
	}

	else
	{
		int m_sum = m_ping[m_date.m_month] - m_date.m_day;
		if (n > m_sum)
		{
			m_date.m_month++;
			n -= m_sum;
		}

		while (n >= m_ping[m_date.m_month])
		{
			m_date.m_month++;
			n -= m_ping[m_date.m_month];
		}

	}
	if (n == m)
	{
		m_date.m_day = m_date.m_day+n;
	}
	else
	m_date.m_day = n;
	return *this;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//功能函数

//获取当前时间
Date_Time Date_Time::getcordatetime()
{
	time_t te;
	time(&te);
	struct tm *ptm = localtime(&te);

	Date_Time  dtm;
	dtm.m_date.m_year = ptm->tm_year + 1900;
	dtm.m_date.m_month = ptm->tm_mon + 1;
	dtm.m_date.m_day = ptm->tm_mday;

	dtm.m_time.m_hour = ptm->tm_hour;
	dtm.m_time.m_minute = ptm->tm_min;
	dtm.m_time.m_second = ptm->tm_sec;
	return dtm;
}

//显示当前时间
void Date_Time::showdatetime()
{
	HideCursor();
	Date_Time tmp;

	while (1)
	{
		if (_kbhit())
		{
			int v = getch();
			if (v == ESC)
			{
				break;
				ShowCursor();
			}
		}
		tmp = tmp.getcordatetime();

		cout << tmp << endl;
		Sleep(1000);
		system("cls");
	}
	ShowCursor();
}


void Date_Time::cin_date()
{
	int a= 1;
	while (a>0)
	{
		cin >> m_date.m_year >> m_date.m_month >> m_date.m_day;

		if (m_date.m_year < 1900 || m_date.m_month<1 || m_date.m_month>12 || m_date.m_day < 1 || m_date.m_day>m_run[m_date.m_month])
		{
			cout << "您输入的日期不合法，请重新输入！" << endl;
		}
		else if (!(Judgment_Leap_year(m_date.m_year)) && m_date.m_month == 2 && m_date.m_day>28)
		{
			cout << "您输入的日期不合法，请重新输入！" << endl;
		}

		else a = -1;
	}

		

}

//判断某年是否是闰年
bool Judgment_Leap_year(int year)
{
	if ((year % 400 == 0)|| (year % 4 == 0 && year % 100 != 0))
	{
		return true;
	}
	return false;
}
//判断输入日期的合法性
bool Date_Time::Legitimacy_day(int year, int month, int day)
{
	if (year < 1900 || month<1 || month>12 || day<1)
	{
		return  false;
	}
	bool s = Judgment_Leap_year(year);
	if (false == s)
	{
		if (day>m_ping[month])
		{
			return false;
		}
	}
	else
	{
		if (day>m_run[month])
		{
			return false;
		}
	}
}


//求某年某月某日是星期几
int Date_Time::GetWeekByYMD(int year, int month, int day)
{
	//判断日期合法性
	
	if (!(Legitimacy_day(year, month, day)))
	{
		cout << "日期不合法！" << endl;
		return -1;
	}


	//计算总天数
	int sum = 0;
	for (int i = 1900; i < year; ++i)
	{
	
		if (!(Judgment_Leap_year(i)))
		{
			sum += 365;
		}
		else sum += 366;
	}

	if (!(Judgment_Leap_year(year)))
	{
		for (int j = 1; j <= month - 1; ++j)
		{
			sum+= m_ping[j];
		}
	}
	else
	{
		for (int j = 1; j <= month - 1; ++j)
		{
			sum+=m_run[j];
		}
	}
	
	sum += day;

	int w = sum % 7;
	if (0 == w)
		return 7;
	else return w;
}

//求某年某月某日是本年的第几天
int  Date_Time::Getsum_day(int year, int month, int day)
{
	//判断日期合法性
	if (!(Legitimacy_day(year, month, day)))
	{
		cout << "日期不合法！" << endl;
		return -1;
	}

	int sum = 0;
	if (Judgment_Leap_year(year))
	{
		for (int i = 0; i <= month - 1; ++i)
		{
			sum += m_run[i];
		}
	}
	else
	{
		for (int i = 0; i <= month - 1; ++i)
		{
			sum += m_ping[i];
		}
	}
	sum += day;
	return sum;
}



//动态显示万年历和时间
void Date_Time::DateCalendar_Time()
{

	char Week[10][7] = { "一", "二", "三", "四", "五", "六", "日" };

	cout << "请输入要显示的年月:>" << endl;
	while (cin >> m_date.m_year >> m_date.m_month, (m_date.m_year < 1900 || m_date.m_month<1 || m_date.m_month>12))
		cout << "您输入的日期不合法，请重新输入！" << endl;

	system("cls");
	//判断是否为闰年
	//判断当月第一天是星期几
	int w = GetWeekByYMD(m_date.m_year, m_date.m_month, 1);

	Date_Time tmp;
	
	/////////////////////////////////////////////////////////////
	//显示
	HideCursor();
	while (1)
	{
		if (_kbhit())
		{
			int v = getch();
			if (v == ESC)
			{
				break;
				ShowCursor();
			}
		}
	
		cout << "\n\t\t\t  万年历\t\t\t\n";
		cout << endl;
		tmp = tmp.getcordatetime();
		cout << "\t当前时间为：";
		cout << tmp << endl;

		cout << endl;
		cout << "\t"<<m_date.m_year << "年" << m_date.m_month << "月：" << endl;
		cout << "\t*************************************************\n\n";
		cout << "\t";
		for (int i = 0; i < 7; ++i)
		{
			cout << Week[i] << "\t";
		}
		cout << endl << endl;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		//显示日期

		//显示每月一号前面的空
		for (int i = 1; i < w; ++i)
		{
			cout << " \t";
		}
		if (Judgment_Leap_year(m_date.m_year) && 2 == m_date.m_month)//如果是闰年2月，则单独处理显示
		{
			cout << "\t";
			for (int i = 1; i <= 29; ++i)
			{
				int j = 7 - w + 1;

				if (i < 10)  { cout << "0" << i << "\t"; }
				else { cout << i << "\t"; }

				if (i >= j && ((i - j) % 7 == 0))
				{
					cout << endl;
					cout << "\t";
				}
			}
		}
		else
		{
			cout << "\t";
			for (int i = 1; i <= m_ping[m_date.m_month]; ++i)
			{
				int j = 7 - w + 1;

				if (i < 10)  { cout << "0" << i << "\t"; }
				else { cout << i << "\t"; }
				
				if (i >= j && ((i - j) % 7 == 0))
				{
					cout << endl<<endl;
					cout << "\t";
				}
			}
		}
		Sleep(1000);
		system("cls");
	}
	ShowCursor();		
	}
	

//求后n天是几月几号
void NextDateTime()
{
	Date_Time d;
	int n = 0;
	cout << "输入你要计算的日期和天数：>" << endl;
	d.cin_date();
	cin >> n;
	cout << d.m_date.m_year << "年" << d.m_date.m_month << "月" << d.m_date.m_day << "日之后"<<n<<"天是 ： " ;
	d +=n;


	cout << d.m_date.m_year << "年" << d.m_date.m_month << "月" << d.m_date.m_day << "日" << endl;
}