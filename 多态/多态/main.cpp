#include<iostream>
using namespace std;


////点坐标类
//class Point
//{
//public:
//	friend ostream& operator<<(ostream&out, Point &p);
//public:
//	Point(float x = 0, float y = 0) :_x(x), _y(y)
//	{}
//	void setPoint(float a, float b)//设置坐标值
//	{
//		_x = a;
//		_y = b;
//	}
//	float getx()
//	{ return _x; }
//	float gety()
//	{return _y;}
//private:
//	float _x, _y;
//};
//ostream& operator<<(ostream&out, Point &p)
//{
//	cout << "[" << p._x << "," << p._y << "]";
//	return out;
//}
//
//
////圆类
//class Circle :public Point
//{
//public:
//	friend ostream& operator<<(ostream&out, Circle c);
//public:
//	Circle(float x, float y, float r) :Point(x, y), _r(r)
//	{}
//	Circle(Point& p, float r) :Point(p.getx(),p.gety()), _r(r)
//	{}
//	void setC(float x, float y, float r)
//	{
//		setPoint(x,y);
//		_r = r;
//	}
//	float getr()
//	{return _r;}
//	float S()//计算圆面积
//	{return  3.14 * _r*_r;}
//private:
//	float _r;
//};
//ostream& operator<<(ostream&out, Circle c)
//{
//	cout << "O：" << c.getx()<<" "<<c.gety()<<endl;
//	cout << "H：" << c._r << endl;
//	return out;
//}
//
//
//
////圆柱体类
//class Cylinder :public Circle
//{
//public:
//	friend ostream& operator<<(ostream&out, Cylinder cy);
//public:
//	Cylinder(float x, float y, float r, float h) :Circle(x, y, r), _h(h)
//	{}
//	Cylinder(Circle c, float h) :Circle(c.getx(), c.gety(), c.getr()), _h(h)
//	{}
//
//	void setCy(float x, float y, float r, float h)
//	{
//		setC(x,y,r);
//		_h = h;
//	}
//	float geth()
//	{
//		return _h;
//	}
//	float S()//计算表面积
//	{
//		return 2 * 3.14*getr()*getr() + 2 * 3.14*getr()*_h;
//	}
//private:
//	float _h;
//};
//ostream& operator<<(ostream&out, Cylinder cy)
//{
//	cout << "O：" << cy.getx() << " " << cy.gety() << endl;
//	cout << "R：" << cy.getr() << endl;
//	cout << "H：" << cy._h << endl;
//	return out;
//}
//int main()
//{
//	Cylinder cy(1.1,2.2,3.3,4.4);
//	cout << cy.getx() << " " << cy.gety() << " " << cy.getr() << " " << cy.geth() << endl;
//	cy.setCy(5.5,6.6,7.7,8.8);
//	cout << cy << endl;
//	Point p(1.3, 2.4);
//	Circle c(p,6.8);
//	Cylinder cy1(c, 9.9);
//
//	cout << "底圆面积：" << cy.Circle::S() << endl;
//	cout << cy1 << endl;
//	cout << "表面积：" << cy.S() << endl;//注意：此处的S()函数和上述S()函数不是重载，他们的函数名，参数表都相同，在不同的类中，属于同名覆盖。
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//多态的体现
//class A
//{
//public:
//	A(int a = 0) :_a(a)
//	{}
//	void show()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//class B:public A
//{
//public:
//	B(int a,int b = 0) :A(a),_b(b)
//	{}
//	void show()
//	{
//		cout << _b << endl;
//	}
//private:
//	int _b;
//};
//int main()
//{
//	A a(10);
//	A *p;
//	p = &a;
//	p->show();
//
//	B b(20,30);
//	p = &b;
//	p->show();//通过输出结果可以发现，当让p指向B的时候，并没有去调动B里面的show()函数
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	A(int a = 0) :_a(a)
//	{}
//	virtual void show()//将基类函数声明成虚函数
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//class B :public A
//{
//public:
//	B(int a, int b = 0) :A(a), _b(b)
//	{}
//	void show()
//	{
//		cout << _b << endl;
//	}
//private:
//	int _b;
//};
//int main()
//{
//	A a(10);
//	A *p;
//	p = &a;
//	p->show();
//
//	B b(20, 30);
//	p = &b;
//	p->show();//通过输出结果可以发现，当基类函数声明成虚函数的时候，再让p指向B的时候，会去调动B里面的show()函数。
//	          //一般情况下，基类的指针只能调用基类的函数。当在基类中定义了虚函数后，可以通过基类的指针去调用派生类的函数。
//	          //即可以通过同一种方法去调动同一类族中不同类的虚函数，实现不同的功能，这就是多态性。     
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//实现原理
class A
{
public:
	A()
	{}
	virtual void fun()//将基类函数声明成虚函数 ,构造基类虚函数时，会构造一个虚函数指针，只想一张虚表，续表里面存放的是虚函数的地址
	{
		cout << "A:：fun()" << endl;
	}
	virtual void show()
	{
		cout << "A::show()" << endl;
	}
	virtual void print()
	{
		cout << "A::print()" << endl;
	}
private:
	int _a;
};


class A1
{
public:
	A1()
	{}
	virtual void fun()
	{
		cout << "A1:：fun()" << endl;
	}
	virtual void show()
	{
		cout << "A1::show()" << endl;
	}
	virtual void print()
	{
		cout << "A1::print()" << endl;
	}
private:
	int _a1;
};



class B :public A,public A1
{
public:

	B()
	{}
	//void show()//在构造派生类时，如果基类的某个函数重写了，就会用重写的这个函数的地址去替换掉基类中相应函数的地址。
	//{
	//	cout << _b << endl;
	//}
	virtual void fun()
	{
		cout << "D:：fun()" << endl;
	}
	virtual void show()
	{
		cout << "D::show()" << endl;
	}
	virtual void print()
	{
		cout << "D::print()" << endl;
	}

private:
	int _b;
};


typedef void(*vfptr)();

void printvtable(vfptr vtable[])
{
	cout << "虚表地址：" << vtable << endl;
	for (int i = 0; vtable[i]; ++i)
	{
		vtable[i]();
	}
}
int main()
{
	B b;
	vfptr* _vfptr = (vfptr*) *(int*)&b;
	printvtable(_vfptr);
}





////1、什么是多态？
///////////多态是不同继承关系的类对象，去调用同一函数，产生不同结果的行为。
////2、什么是重载、重写(覆盖)、重定义(隐藏)?
////////////重载：在一个类中，函数名相同，参数列表不同
////////////重写（覆盖）：在同一类族，不同类之间，有vritual，函数名，参数列表，返回值都相同。（协变和析构函数除外）
////////////重定义（隐藏）：在同一类族，不同类之间，无vritual，函数名相同，参数列表不做考虑。
////3、多态的实现原理？
////////////当基类中的函数声明为虚函数，构造派生类时会构造出一个虚函数指针，指向一个虚表。表中存放的是虚函数的地址。当在派生类中对某个
////////虚函数进行重写时，会用重写的函数地址去替换虚表中相应函数的地址。从而达到可以调用重写后的函数的功能。
////4、inline函数可以是虚函数吗？
////////////答：不能，因为inline函数没有地址，无法把地址放到虚函数表中。
////5. 静态成员可以是虚函数吗？
////////////答：不能，因为静态成员函数没有this指针，使用类型::成员函数的调用方式无法访问虚函数表，所以静态成员函数无法放进虚函数表。
////6. 构造函数可以是虚函数吗？
////////////答：不能，因为对象中的虚函数表指针是在构造函数初始化列表阶段才初始化的