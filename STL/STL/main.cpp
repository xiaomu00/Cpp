#include"List_STL.h"



int main()
{
	xiaomu::List<int> mlist;

	/*mlist.push_back(1);
	mlist.push_back(2);
	mlist.push_back(3);
	mlist.push_back(4);
	mlist.push_back(5);
	mlist.push_back(6);
	mlist.push_back(7);
	mlist.push_back(8);
	mlist.push_back(9);*/

	mlist.push_front(1);
	mlist.push_front(2);
	mlist.push_front(3);
	mlist.push_front(4);
	mlist.push_front(5);
	mlist.push_front(6);
	mlist.push_front(7);
	mlist.push_front(8);
	mlist.push_front(9);


	//迭代器访问链表
	xiaomu::List<int>::iterator it=mlist.begin();
	while (it != mlist.end())
	{

		cout << *it << "<=>";
		++it; 
	}
	cout << "Over"<< endl;



	//标准模板库迭代器
	vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	vector<int>::iterator t = v.begin();
	while (t != v.end())
	{
		cout << *t << "->";
		++t;
	}
	cout << "Over" << endl;
    return 0;
}



