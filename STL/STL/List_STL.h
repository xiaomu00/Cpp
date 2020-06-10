#ifndef _LIST_STL_H_
#define _LIST_STL_H

#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<vector>
using namespace std;

namespace xiaomu
{


	template <typename _Ty>

	class List
	{
	public:
		typedef  _Ty             value_type;
		typedef  _Ty*            pointer_type;
		typedef  _Ty&            reference_type;
		typedef const  _Ty*      const_pointer_type;
		typedef const  _Ty&      const_reference_type;
		typedef size_t            size_type;
		struct _Node;
		typedef _Node*            _Nodeptr;

	public:
		struct _Node
		{
			_Nodeptr   _Next;
			_Nodeptr   _Prev;
			_Ty        _Value;
		};
	public:
		struct ACC
		{
			typedef _Nodeptr& _Npdepref;
			typedef _Ty&  _Vref;
			static  _Npdepref _Next(_Nodeptr  _P)
			{return _P->_Next;}
			static  _Npdepref _Prev(_Nodeptr  _P)
			{return _P->_Prev;}
			static _Vref _Value(_Nodeptr  _P)
			{return _P->_Value;}
		};
	public:
		//µü´úÆ÷Àà
		class iterator
		{
		public:
			iterator(_Nodeptr _P) :_Ptr(_P)
			{}

			bool operator!=(const iterator &it)
			{return _Ptr != it._Ptr;}
			bool operator==(const iterator &it)
			{return _Prt == it._Ptr;}

			iterator& operator++()
			{
				_Ptr=ACC::_Next(_Ptr);
				return *this;
			}
			_Ty& operator* ()
			{
				return ACC::_Value(_Ptr);
			}
		private:
			_Nodeptr _Ptr;
		};

	public:
		_Nodeptr _BuyNode(_Nodeptr _N = 0, _Nodeptr _P = 0)
		{
			_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
			assert(_S != nullptr);
			ACC::_Next(_S) = _N != 0 ?_N : _S;
			ACC::_Prev(_S) = _P != 0 ?_P : _S;
		
			return _S;
		}
		
	public:
		List() :_Head(_BuyNode()), _Size(0)
		{}

		iterator begin()
		{
			return iterator(ACC::_Next(_Head));
		}
		iterator end()
		{
			return iterator(_Head);
		}
	public:
		
		void push_back(_Ty x)
		{
			_Nodeptr _S = _BuyNode(_Head, ACC::_Next(_Head));
			ACC::_Value(_S)=x;
			ACC::_Next(ACC::_Prev(_Head)) = _S;
			ACC::_Prev(_Head) = _S;
			_Size++;
		}
		
		void push_front(_Ty x)
		{
			_Nodeptr _S = _BuyNode(ACC::_Next(_Head), _Head);
			ACC::_Value(_S) = x;
			ACC::_Next(_Head) = _S;
			ACC::_Prev(ACC::_Next(_S)) = _S;
			_Size++;
		}

	private:
		_Nodeptr   _Head;
		size_type  _Size;
	};

};


#endif /*_LIST_STL_H*/