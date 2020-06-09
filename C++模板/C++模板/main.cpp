#include<iostream>
using namespace std;

//通过函数重载实现类型不同但功能相同的函数
//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}
//char Max(char a, char b)
//{
//	return a > b ? a : b;
//}
//double Max(double a, double b)
//{
//	return a > b ? a : b;
//}
//
//int main()
//{
//	cout << Max(20,436) << endl;
//	cout << Max('F', 'V') << endl;
//	cout << Max(20.434, 436.545) << endl;
//		return 0;
//}
//缺点：代码冗余程度太高



//用模板来实现

//template <class type>
template<typename type>

type Max(type a, type b)
{
	cout << typeid(type).name() << endl;//输出type的类型
	return a > b ? a : b;
}


class student
{
public:
	student(char* name, int age)
	{
		strcpy(m_name, name);
		m_age = age;
	}
public:
	friend ostream& operator<<(ostream& out, const student& s);

	bool operator>(const student& s)
	{
		return m_age > s.m_age;
	}

private:
	char m_name[20];
	int m_age;
};

 ostream& operator<<(ostream& out, const student& s)
{
	 cout <<s.m_name << "：" << s.m_age << endl;
	 return out;
}

int main()
{
	cout << Max(20, 436) << endl;
	cout << Max('F', 'V') << endl;
	cout << Max(20.434, 436.545) << endl;
	cout<<Max(student("张三",18),student("李四",20))<<endl ;
	return 0;
}