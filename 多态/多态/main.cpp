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

class A
{
public:
	A(int a = 0) :_a(a)
	{}
	virtual void show()//将基类函数声明成虚函数
	{
		cout << _a << endl;
	}
private:
	int _a;
};
class B :public A
{
public:
	B(int a, int b = 0) :A(a), _b(b)
	{}
	void show()
	{
		cout << _b << endl;
	}
private:
	int _b;
};
int main()
{
	A a(10);
	A *p;
	p = &a;
	p->show();

	B b(20, 30);
	p = &b;
	p->show();//通过输出结果可以发现，当基类函数声明成虚函数的时候，再让p指向B的时候，会去调动B里面的show()函数。
	          //一般情况下，基类的指针只能调用基类的函数。当在基类中定义了虚函数后，可以通过基类的指针去调用派生类的函数。
	          //即可以通过同一种方法去调动同一类族中不同类的虚函数，实现不同的功能，这就是多态性。     
}