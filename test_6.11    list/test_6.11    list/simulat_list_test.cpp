#include"simulat_list.h"


template <typename type>
void show(type lt)
{
	auto it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}



int main()
{
	/*xiaomu::list<int> ls;
	ls.pushback(1);
	ls.pushback(2);
	ls.pushback(3);
	ls.pushback(4);
	ls.pushfront(5);
	ls.pushfront(6);
	ls.pushfront(7);
	ls.pushfront(8);
	ls.pushfront(9);
	show(ls);*/


	/*xiaomu::list<int> ls2(10, 5);
	xiaomu::list<int> ls3{1,2,3,4,5,6,7,8,9};
	show(ls2);	show(ls3);
	ls2.swap(ls3);
	show(ls2);	show(ls3);*/
	
	xiaomu::list<int> ls2{1,2,3,4,5,6,7,8,9};
	cout << "ls2: "; show(ls2);
	ls2.erase(ls2.begin());
	cout << "ls2: "; show(ls2);
	ls2.clear();
	cout << "ls2: "; show(ls2);

	return 0;
}   
