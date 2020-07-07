#ifndef _BST_H
#define _BST_H
#include<iostream>
#include<vld.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////BST：二叉搜索树




template <typename Type>
class BST;

//////////////////////////////////////////////////////////////
////定义树节点类
template <class Type>
class BSTNode
{

	friend class BST<Type>;
public:
	BSTNode(Type d = Type(), BSTNode<Type>* _left = nullptr, BSTNode<Type>* _right = nullptr)
		:data(d), left(_left), right(_right)
	{}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type>* left;
	BSTNode<Type>* right;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////定义搜索二叉树类
template <typename Type>
class BST
{
public:
	////构造函数
	BST() :root(nullptr)
	{}
	BST(Type a[], int n) :root(nullptr)
	{
		for (int i = 0; i < n; ++i)
		{
			Insert(a[i]);
		}
	}

	////析构函数
	~BST()
	{
		_EakeEmpty(root);
	}
public:
	/////////////////////////////////////
	////函数声明

	bool Insert(const Type& x);//插入
	void sort();//排序
	int min_SBT();//求最小值
	int max_SBT();//求最大值
	BSTNode<Type>* Search(const Type &key);	//搜索某个值
	bool erase(const Type x);	//删除某个值
	void EakeEmpty();//释放二叉树
	
protected:
	bool _Insert(BSTNode<Type>*& t, const Type& x);
	void _sort(BSTNode<Type>*& t);
	int min_SBT(BSTNode<Type>* t);
	int max_SBT(BSTNode<Type>* t);
	void _EakeEmpty(BSTNode<Type>* t);
	BSTNode<Type>* _Search(BSTNode<Type>* t, const Type &k);
	bool _erase(BSTNode<Type>*& t, const Type &k);

private:
	BSTNode<Type>* root;

};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////函数实现接口


////////////////////////////////////////////////////////////
////插入
template <typename Type>
bool BST<Type>:: Insert(const Type& x)
{
	return _Insert(root, x);
}

template <typename Type>
bool BST<Type>::_Insert(BSTNode<Type>*& t, const Type& x)
{
	if (t == nullptr)
	{
		t = new BSTNode<Type>(x);
		return true;
	}
	else if (x < t->data)
		_Insert(t->left, x);
	else if (x>t->data)
		_Insert(t->right, x);
	return false;
}


////////////////////////////////////////////////////////////
////排序
template <typename Type>
void BST<Type>::sort()
{
	_sort(root);
}

template <typename Type>
void BST<Type>::_sort(BSTNode<Type>*& t)
{
	if (t != nullptr)
	{
		_sort(t->left);
		cout << t->data << " ";
		_sort(t->right);
	}

}


////////////////////////////////////////////////////////////
//求最小值
template <typename Type>
int BST<Type>:: min_SBT()
{
	return min_SBT(root);
}

template <typename Type>
int BST<Type>::min_SBT(BSTNode<Type>* t)
{
	while (t->left != nullptr)
		t = t->left;
	return t->data;
}

////////////////////////////////////////////////////////////
//求最大值
template <typename Type>
int BST<Type>::max_SBT()
{
	return max_SBT(root);
}

template <typename Type>
int BST<Type>::max_SBT(BSTNode<Type>* t)
{
	while (t->right != nullptr)
		t = t->right;
	return t->data;
}

////////////////////////////////////////////////////////////
//搜索某个值
template <typename Type>
BSTNode<Type>* BST<Type>::Search(const Type &key)
{
	return _Search(root, key);
}

template <typename Type>
BSTNode<Type>* BST<Type>::_Search(BSTNode<Type>* t, const Type &k)
{
	if (t == nullptr)
		return nullptr;
	else if (t->data == k)
		return t;
	else if (t->data > k)
		return _Search(t->left, k);
	else if (t->data < k)
		return _Search(t->right, k);
}


////////////////////////////////////////////////////////////
//删除某个值
template <typename Type>
bool BST<Type>::erase(const Type x)
{
	return _erase(root, x);
}


template <typename Type>
////方法一
bool BST<Type>::_erase(BSTNode<Type>*& t, const Type &k)
{
	if (t != nullptr)
	{
		BSTNode<Type>* p;
		if (k < t->data)
			_erase(t->left, k);
		else if (k>t->data)
			_erase(t->right, k);
		else if (t->left == nullptr&&t->right != nullptr)//删除有左右子树的节点
		{
			p = t->left;
			while (p->right != nullptr)
				p = p->right;
			t->data = p->data;
			_erase(t->left, p->data);
		}
		else//删除最多有一个子树的节点
		{
			p = t;
			if (t->left != nullptr)
				t = p->left;
			else
				t = p->right;
			delete p;
			return true;
		}
	}
	return false;

}

////方法二
//template <typename Type>
//bool BST<Type>::  _erase(BSTNode<Type>*& t, const Type &k)
//{
//	if (t != nullptr)
//	{
//		if (k < t->data)
//			_erase(t->left,k);
//		else if (k>t->data)
//			_erase(t->right, k);
//		else
//		{
//			if (t->left == nullptr&&t->right == nullptr)
//			{
//				//删除叶子结点
//				delete t;
//				t = nullptr;
//			}
//			else if (t->left != nullptr&&t->right == nullptr)
//			{
//				//删除有左子树的节点
//				BSTNode<Type>* p = t;
//				t = p->left;
//				delete p;
//				
//			}
//			else if (t->left == nullptr&&t->right != nullptr)
//			{
//				//删除有右子树的节点
//				BSTNode<Type>* p = t;
//				t = p->right;
//				delete p;
//			}
//			
//			else
//			{
//				//删除有左右子树的节点
//				BSTNode<Type>* p = t->left; 
//				while (p->right != nullptr)
//					p = p->left;
//				t->data = p->data;
//				_erase(t->left, p->data);
//			}
//			return true;
//		}
//	}
//	return false;
//
//}




////////////////////////////////////////////////////////////
//释放二叉树
template <typename Type>
void BST<Type>:: EakeEmpty()
{
	_EakeEmpty(root);
}

template <typename Type>
void BST<Type>::_EakeEmpty(BSTNode<Type>* t)
{
	if (t != nullptr)
	{
		_EakeEmpty(t->left);
		_EakeEmpty(t->right);
		delete t;
	}
}


#endif /*_BST_H*/