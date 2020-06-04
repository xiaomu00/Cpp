#define _CRT_SECURE_NO_WARNINGS 1

//类与对象（下）

#include<iostream>
#include<stdlib.h>
using namespace std;



//
//class test
//{
//public:
//
//	//构造函数
//	test()//名字必须和类名相同
//	{
//		cout << "Create test Obj:" << this << endl;
//	}
//	test(int data)//名字必须和类名相同
//	{
//		m_data = data;
//		cout << "Create test Obj:" << this << endl;
//	}
//	//拷贝析构函数
//	test(const test &t)//语法要求，必须要引用 
//	{
//		m_data = t.m_data;
//		cout << "copy   test Obj:" << this << endl;
//	}//用法：
//	 //用对象初始化对象时
//	//函数参数为对象传递时
//	//以对象作为返回值时
//
//
//
//	//析构函数
//	~test()
//	{
//		cout << "Free test Obj:" << this << endl;
//	}
//
//
//
//	int getdata()
//	{
//		return m_data;
//	}
//
//	void print()
//	{
//		cout << m_data << endl;
//	}
//private:
//	int m_data;
//
//};
//
//
//
//
//
//test fun(test t)
//{
//	int m = t.getdata();
//	//cout <<"m="<<m << endl;
//	test n(m);
//	return n;
//}
//
//int main()
//{
//    test t0;
//    test t1(100);
//	test t2(t1);
//	/*
//	test t2 = t1;  等价于 test t2(t1);   用t1 初始化t2
//	
//	test t2;
//	t2 = t1;//赋值
//	*/
//
//	//fun(t1);
//
//   return 0;
//}




//
//class test
//{
//public:
//	explicit test(int d = 0) :m_data(d)//加上explicit后(只能用于构造函数和拷贝构造函数)，不允许隐式转换（比如t=200），要想赋不同类型的值，必须显式转换（t=(test)200）
//	{
//		cout << "Create tset Obj : " << this << endl;
//	}
//
//	test(const test &t)
//	{
//		m_data = t.m_data;
//		cout << "Copy   tset Obj : " << this << endl;
//	}
//
//	//赋值——等号重载
//	test& operator=( const test &t)
//	{
//		cout << "Assign : " << this <<"="<< &t << endl;
//		if (this != &t)
//		{
//			m_data = t.m_data;
//		}
//		return *this;
//	}
//
//
//	~test()
//	{ 
//		cout << "Free   test Obj : " << this << endl;
//	}
//private:
//	int m_data;
//};
//
//int main()
//{
//	test t1(10);//构造函数初始化对象t
//
//	//test t2(t1);//拷贝构造
//
//	//t1 = (test)200;//加上 explicit后，只能用显式转换。
//
//	//test t3;
//	//t3 = t1;  //用t给t3赋值，等价于  t3.operator=(t);
//
//	test t3, t4;
//	t4 = t3 = t1;//连等赋值，需要赋值函数以类的引用(当前对象)返回
//	
//	return 0;
//}










class data
{
public:
	//无参构造函数
	data()
	{
		m_year = 2000;
		m_month = 00;
		m_day = 00;
	}
	//带参构造函数
	data(int year,int month,int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	void Show()const
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	data d1;//调用无参构造函数，注意：不能加括号
	data d2(2020, 6, 4);//调用带参构造函数
	
	d1.Show();
	d2.Show();
}
