
#include<iostream>
#include<stdbool.h>
using namespace std;

//class date
//{
//public:
//	date()
//	{
//	}
//
//	date(int year, int month, int day) 
//		:
//		m_year(year), 
//		m_month(month),
//		m_day(day)           //初始化列表
//	{
//	}
//
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};

//
//int main()
//{
//	date d0;
//	date d1(2020, 6, 5);
//    return 0;
//}



//static 修饰的静态成员

//class test
//{
//public:
//	test()
//	{
//	}
//
//	int  gettest()
//	{
//		return m_a;
//	}
//
//private:
//	static int m_a;//当同一个类实例化了不同的对象时，静态变量不属于任何对象，只有一份，但可以被任何对象共享
//	               //静态变量不需要实例化对象就可以调动
//	               //静态函数只能调用静态变量，不能调动普通变量，静态函数没有this指针
//
//
//};
//int test::m_a = 10;//静态成员必须在类外进行初始化
//
//int main()
//{
//	 test t1;
//	 cout << "a:" << t1.gettest() << endl;
//
//	 return 0;
//} 




//运算符的重载

//class test;
//test operator+(int a, test& t);
//
//
//class test
//{
//	friend test operator+(int a, test& t);
//public:
//	test()
//	{
//		cout << "调用构造函数" << this << endl;
//	}
//
//	test(int a = 0, int b=0 ):m_a(a),m_b(b)
//	{
//		cout << "调用构造函数" << this << endl;
//	}
//	test(test &t)
//	{
//		cout << "调用拷贝构造函数" << this << endl;
//		m_a = t.m_a;
//		m_b = t.m_b;
//	}
//
//	~test()
//	{
//		cout << "调用析构函数" << this << endl;
//	}
//
//public://运算符重载
//
//	//“=”重载
//	test& operator=(const test &t)
//	{
//		cout << "调用赋值函数" << this << endl;
//		if (&t != this)
//		{
//			m_a = t.m_a;
//			m_b = t.m_b;
//		}
//		return *this;
//	}
//
//	//“+”重载  类+类
//	test operator+(test &t)
//	{
//		cout << "调用加法重载函数" << this << endl;
//		return test(m_a + t.m_a, m_b + t.m_b);
//	}
//	//“+”重载  类+整数
//	test operator+(int a)
//	{
//		cout << "调用加法重载函数" << this << endl;
//		return test(m_a + a, m_b + 0);
//	}
//
//
//
//
//public:
//	void gettest()const
//	{
//		cout << m_a << "  " << m_b << endl;
//	}
//private:
//	int m_a;
//	int m_b;
//
//};
//
////“+”重载  整数+类
//test operator+(int a, test& t)
//{
//	cout << "调用加法重载函数" << &t << endl;
//	return test(t.m_a+a,t.m_b+0);
//}
//
//
//
//int main()
//{
//	test t1(10, 20);
//	test t2(5,25);
//
//	cout << "t1= "; t1.gettest();
//	cout << "t2= "; t2.gettest();
//
//	//test t3 = t2 + t1;
//	//test t3 = t2 + 10;
//	test t3 = 10 + t2;
//	cout << "t3= "; t3.gettest();
//
//	
//	return 0;
//}
//
//class Int;
//ostream& operator<<(ostream &out, const Int &i);
//istream& operator>>(istream &in, const Int &i);
//
//class Int
//{
//public:
//
//	friend ostream& operator<<(ostream &out, const Int &i);
//	friend istream& operator>>(istream &out, Int &i);
//	Int(int a = 0) : m_a(a)
//	{}
//	~Int()
//	{}
//
//private:
//	int m_a;
//};
//
//ostream& operator<<(ostream &out, const Int &i)
//{
//	cout << i.m_a;
//	return out;
//}
//
//istream& operator>>(istream &in,  Int &i)
//{
//	cin >> i.m_a;
//	return in;
//}
//
//int main()
//{
//
//	Int a = 10;
//	Int b;
//
//	//输出运算符重载
//	cout << "a="<<a <<endl;
//	//输入运算符重载
//
//	
//	cin >> b;
//	cout << "b=" << b << endl;
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//总结

////日期类的实现
//class date
//{
////6个默认成员函数
//public:
//	date()
//	{}
//	date(int year, int month, int day)
//		:
//		m_year(year),
//		m_month(month),
//		m_day(day)
//	{}
//	~date()
//	{
//	}
//	date(const date &d)
//	{
//		m_year = d.m_year;
//		m_month = d.m_month;
//		m_day = d.m_day;
//	}
//	date& operator=(const date d)
//	{
//		m_year = d.m_year;
//		m_month = d.m_month;
//		m_day = d.m_day;
//		return *this;
//	}
//
//	date* operator&()
//	{
//		return this;
//	}
//	const date* operator&()const
//	{
//		return this;
//	}
//
////////////////////////////////////////////////////////////////////////////////////
////运算符重载
//
//public:
//	// 日期+天数 
//	date operator+(int day)
//	{
//		return date(m_year, m_month, m_day + day);
//	}
//
//	// 日期-天数  
//	date operator-(int day)
//	{
//		return date(m_year, m_month, m_day - day);
//	}
//
//	// 日期+=天数    
//	date& operator+=(int day)
//	{
//		m_day = m_day + day;
//		return *this;
//	}
//
//	// 日期-=天数 
//	date& operator-=(int day)
//	{
//		m_day = m_day - day;
//		return *this;
//	}
//
//	
//	// 前置++ 
//	date& operator++()
//	{
//		m_day++;
//		return *this;
//	}
//
//	// 后置++    
//	date operator++(int)
//	{
//		date th = *this;
//		++*this;
//		return th;
//	}
//	// 前置--    
//	date& operator--()
//	{
//		m_day--;
//		return *this;
//	}
//
//	// 后置--
//	date operator--(int)
//	{
//		date th = *this;
//		--*this;
//		return th;
//	}
//	
//	// >运算符重载 
//	bool operator>(date &d)
//	{
//		return m_day > d.m_day;
//	}
//
//	// <运算符重载   
//	bool operator < (date &d)
//	{
//		return !(*this>d);
//	}
//
//	// ==运算符重载  
//	bool operator ==(date &d)
//	{
//		return m_day ==d.m_day;
//	}
//
//	// !=运算符重载     
//	bool operator !=(date &d)
//	{
//		return !(*this == d);
//	}
//
//
//	// >=运算符重载         
//	bool operator>=(date &d)
//	{
//		return m_day >= d.m_day;
//	}
//
//	// <=运算符重载   
//	bool operator<=(date &d)
//	{
//		return m_day <= d.m_day;
//	}
//
//
//public:
//	void getdate()const
//	{
//		cout << m_year << "-" << m_month << "-" << m_day << endl;
//	}
//
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//
//};
//
//int main()
//{
//	date d1(2020, 6, 11);
//	d1.getdate();
//	date d2(2020, 6, 10);
//	d2.getdate();
//
//	if (d1!=d2)
//	{
//		cout << "d1!=d2" << endl;
//	}
//	else 
//		cout << "d1==d2" << endl;
//	return 0;
//}