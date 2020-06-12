#ifndef _SIMULATE_LIST_H_
#define _SIMULATE_LIST_H_
//list 模拟实现

#include<iostream>
#include<stdlib.h>
using namespace std;



namespace xiaomu
{
	template <class T>
	class list;
	//节点类
	template <class T>
	class listnode
	{
		
	public:
		friend class list<T>;


	public:
		listnode(T date = T()) :_next(nullptr), _prev(nullptr), value(date)
		{}
		~listnode()
		{}

	private:
		listnode *_next;
		listnode *_prev;
		T        value;
	};





	//list类
	template <class T>
	class list
	{
		typedef  listnode<T>* PNode;
		//迭代器类
		template <class T>
		class listiterator
		{
			
		public:
			listiterator( PNode p) :_ptr(p)
			{}

		public:
			PNode mynode()const
			{
				return _ptr;
			}


			//重载
			bool operator !=(const listiterator<int> & it)
			{
			
				return _ptr != it._ptr;
			}

			listiterator<int>& operator ++()
			{
				_ptr = _ptr->_next;
			
				return *this;
			}

			T& operator *()const
			{
				return _ptr->value;
			}

		public:
			PNode  _ptr;
		};
		typedef listiterator<int>   iterator;

		//构造
	public:
		list()
		{
			_Head = new listnode<T>;
			_Head->_next = _Head->_prev = _Head;
		}
	
		list(int n,int x=0)
		{
			_Head = new listnode<T>;
			_Head->_next = _Head->_prev = _Head;

			for (int i = 0; i < n; ++i)
			{
				pushback(x);
			}
		}
		list(initializer_list<T> il)
		{
			_Head = new listnode<T>;
			_Head->_next = _Head->_prev = _Head;
			for (const auto &e : il)
				pushback(e);
			
		}

		list( list<T> &lt)
		{

			_Head = new listnode<T>;
			_Head->_next = _Head->_prev = _Head;
			for (const auto &e: lt)
				pushback(e);
		}



	public:
		iterator begin()
		{
			return iterator(_Head->_next);
		}
		iterator end()
		{
			return iterator(_Head);
		}
	


		iterator insert(iterator t,const T &x)
		{
			PNode S = new listnode<int>(x);
			S->_next = t._ptr;
			S->_prev = t._ptr->_prev;
		
			S->_prev->_next = S;
			S->_next->_prev = S;
			return iterator(S);
		}

		void pushback(T x)
		{
			insert(end(), x);	
		}
		void pushfront(T x)
		{
			insert(begin(), x);
		}

		void  swap( list<int>& b)
		{
			std::swap(_Head, b._Head);
		}

		iterator erase(iterator pos)
		{
			PNode p = pos.mynode();
			PNode q = pos._ptr->_next;
			pos._ptr->_prev->_next = pos._ptr->_next;
		    pos._ptr->_next->_prev = pos._ptr->_prev;
			delete p;
			return iterator(q);
		}
		iterator erase(iterator a, iterator b)
		{
			while (a != b)
			{
				a = erase(a);
			}
			return a;
		}
		void clear()
		{
			erase(begin(), end());
		}
	private:
		PNode  _Head;
	};

}






#endif  /*_SIMULATE_LIST_H_*/