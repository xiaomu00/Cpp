#include<iostream>
#include<list>
#include <functional>  
#include<stdbool.h>
using namespace std;

//int main()
//{
//	list<int>  lt;
//	list<int>  lt2(10,5);
//	list<int>  lt3 = lt2;
//
//	int a[] = {1,2,3,4,5,6,7,8,9};
//	list<int>  lt4(a, a + 9);
//	list<int>  lt5={1,2,3,4,5,6,7,8,9};
//	list<int> lt6(lt4.begin(), lt4.end());
//
//
//	cout << "lt2: ";
//	for (const auto &e : lt2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << "lt3: ";
//	for (const auto &e : lt3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << "lt2: ";
//	for (const auto &e : lt4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << "lt3: ";
//	for (const auto &e : lt5)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//
//
//int main()
//{
//
//	list<int> lt = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	/*for (const auto &e : lt)
//	{
//		cout << e << " ";
//	}*/
//
//	//自己定义迭代器
//	list<int>::iterator i = lt.begin();
//	while (i != lt.end())
//	{
//		cout << *i << " ";
//		i++;
//	}
//	cout << endl;
//
//
//	//自动推倒迭代器
//
//	auto it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//
//	//反向访问
//	auto it1 = lt.end();
//	while (it1 != lt.begin())
//	{
//		it1--;
//		cout << *it1 << " ";    //注意：it1--；必须放到	cout << *it1 << " ";前面。因为list迭代器end()指向的是头结点（最后一个元素的选一个节点）
//		
//	}
//	cout << endl;
//
//
//	//反向迭代器
//	list<int>::reverse_iterator ri = lt.rbegin();
//	while(ri!=lt.rend())
//	{
//		cout << *ri << " ";
//		ri++;
//	}
//	cout << endl;
//
//	 return 0;
//}
template <typename type>
void show(type lt)
{
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}



//插入删除
//bool my_if(const int& value)
//{
//	return   value > 5;
//}
//int main()
//{
//	list<int> lt{1,2,3,4,5,6,7,8,9};
//	show(lt);
//
//	/*cout << "请输入要插入的值,以-1结束" << endl;
//	int x;
//	while (cin >> x, x != -1)
//	{
//		lt.push_front(x);
//	}
//*/
//
//	cout << "请输入要删除的值：" << endl;
//	int x;
//	cin >> x;
//	//list<int>::iterator ir = find(lt.begin(), lt.end(), x);
//	lt.remove(x);
//	cout << "删除后的链表为：";
//	show(lt);
//
//	cout << "请输入要插入的位置，以及要插入的值：" << endl;
//	int i,m;
//	cin >> i>>m;
//	list<int>::iterator ir = find(lt.begin(), lt.end(), i);
//	lt.insert(ir, m);
//	cout << "插入后的链表为：";
//	show(lt);
//
//
//	//条件删除
//	
//
//	lt.remove_if(my_if);
//	cout << "删除后的链表为：";
//	show(lt);

//	return 0;
//}


//交换  拼接  排序  清除
//int main()
//{
//	list<int> lt1{ 1, 2, 3, 4, 5 };
//	list<int> lt2{ 4,43,45,2,54,35,5767,234,35,134 };
//
//	cout << "lt1: ";
//	show(lt1);
//	cout << "lt2: ";
//	show(lt2);
//
//
//	//交换
//	lt1.swap(lt2);
//	cout << "交换后：" << endl;
//	cout << "lt1: ";
//	show(lt1);
//	cout << "lt2: ";
//	show(lt2);
//
//	///拼接
//	list<int> ::iterator i=lt1.begin();
//	lt1.splice(i, lt2);
//	cout << "拼接后：" << endl;
//	cout << "lt1: ";
//	show(lt1);
//	cout << "lt2: ";
//	show(lt2);
//
//
//	//排序
//	lt1.sort();
//	cout << "从小到大排序后：" << endl;
//	cout << "lt1: ";
//	show(lt1);
//
//
//	lt1.sort(greater<int>());
//	cout << "从大到小排序后：" << endl;
//	cout << "lt1: ";
//	show(lt1);
//	
//
//	//清除
//	lt1.clear();
//	lt2.clear();
//	cout << "清除后：" << endl;
//	cout << "lt1: ";
//	show(lt1);
//	cout << "lt2: ";
//	show(lt2);
//	return 0;
//}
//

//
//int main()
//{
//
//	return 0;
//}















//int main()
//{
//
//	return 0;
//}