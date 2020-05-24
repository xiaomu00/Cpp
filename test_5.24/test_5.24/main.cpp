#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>//输入输出流
using namespace std;//命名空间


//1.输入输出
//int main()
//{
//	int a;
//	char b;
//	double c ;
//
//	cout << "请分别输入a b c 的值:"<< endl;
//	//输入
//	cin >> a;//cout:插入符
//	cin >> b;
//	cin >> c;
//
//	//输出
//	cout << "a=" << a << endl;//提取符
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//	return 0;
//}
//

//2.命名空间
//namespace A
//{
//	void fun()
//	{
//		cout << "123";
//	}
//};
//namespace B
//{
//	void fun()
//	{
//		cout << "456";
//	}
//};
//
//using namespace A;//想用哪个就调用哪个
//int main()
//{
//	fun();
//}

//3.全缺省参数
//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//int main()
//{
//	TestFunc();
//}



//4.函数重载

//int Max(int a, int b)//编译器重命名为：?Max@@YAHHH@Z 
//{
//	return a>b?a:b;
//}
//char Max(char a,char b)//编译器重命名为：?Max@@YADDD@Z  
//{
//	return a>b ? a : b;
//}
//double Max(double a, double b)
//{
//	return a>b ? a : b;
//}
//int main()
//{
//	Max(5,8);
//	Max('a', 'h');
//	Max(1.45, 3.45);
//	return 0;
//}


//5.引用
//int main()
//{
//	int a = 10;
//	int &b = a;//给a取了另外的一个名字b,b和a代表同一块内存空间，并没有给b开辟空间
//	//a=100;和 b=100;等价，a和b都可以改变此内存块中的内容
//}

//用法举例——交换两变量的值
////C语言实现方法
//void Exchange(int *a, int* b)
//{
//	int m = *a;
//	*a = *b;
//	*b = m;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Exchange(&a,&b);
//}
//引用变量实现方法
//void Exchange(int &a, int &b)
//{
//	int m = a;
//	a = b;
//	b = m;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Exchange(a, b);
//	cout << "a=" << a << endl;
//	cout << "b=" << b<< endl;
//}


//常引用 const
//int main()
//{
//	const int a = 10;
//
//}

//
//struct student
//{
//	char name[10];
//	int age;
//};
//
//int main()
//{
//	int a = 10;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//指针的引用
//	int *p = &a;
//	int* &q = p;
//
//	//数组的引用
//	int(&brr)[10] = arr;//&brr要加括号，因为&优先级没有[]高。
//
//	//结构体引用
//	student s;
//	student &rs = s;
//
//}

//内联函数
//inline void Exchange(int *a, int* b)
//{
//	int m = *a;
//	*a = *b;
//	*b = m;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Exchange(&a,&b);
//}

//auto关键字
int main()
{
	int a = 10;
	auto b = a;//此时b也为int型

	auto p = &a;//等价于  auto *p = &a;
	auto& c = a;//引用

	int s[] = {0,1,2,3,4,5,6,7,8,9};

	for (const auto &b:s)
	{
		cout << b << " ";
	}
	cout << endl;
}