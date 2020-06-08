#include<iostream>
#include<assert.h>
#include<vld.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//c语言申请空间
//int main()
//{
//	int *p;
//	int n = 10;
//
//	p = (int*)malloc(sizeof(int)*n);
//	assert(p!=nullptr);
//
//	for (int i = 0; i < n; i++)
//	{
//		p[i] = i;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << p[i] << " ";
//	}
//	cout << endl;
//
//	free(p);
//    return 0;
//}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//c++申请空间  new
//int main()
//{
//
//	//申请空间
//	int *p1 = new int;//无初始值
//	cout << *p1 << endl;
//
//
//	int *p2 = new int(10);  //赋初值10
//	cout << *p2 << endl;
//
//	int *p3 = new int[10]{10,9,8,7,6,5,4,3,2,1};  //申请10个整形空间并赋值
//	
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << *(p3+i)<<" ";
//	}
//	cout << endl;
//
//
//	//释放空间 delete
//	delete p1;
//	delete p2;
//	delete[] p3;
//	return 0;
//}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//申请对象空间

class test
{
public:

	test(int data=0) :m_data(data)
	{
		cout << "调用构造函数" << endl;
	}

	~test()
	{
		cout << "调用析构函数" << endl;
	}

public:
	void showtest()
	{
		cout << m_data << endl;
	}

private:
	int m_data;

};

int main()
{




	//C
	test *p = (test*)malloc(sizeof(test));
	p->showtest();//结果为随机值     申请空间 
	free(p);//                       释放空间
	//结论：用malloc开辟空间，只负责申请，free只是单纯的释放空间

	//C++    如果构造函数有参数，要用new申请空间的话，必须给出默认初始值
	test *p1 = new test;
	p1->showtest();//结果为0    1、申请空间    2、构造对象
	delete p1;    //            1、析构对象    2、释放空间
	//结论：用new开辟空间，申请空间后，会调用构造函数，用delete释放空间会先调用析构函数，再释放对象空间。

	return 0;
}