#ifndef _AVL_H
#define _AVL_H
#include<stack>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////BST：高度平衡化的二叉搜索树

////AVL树类
template <typename Type>
class AVL;

////节点类
template <typename Type>
class AVLNode
{
public:
	friend class AVL<Type>;
public:
	////构造函数
	AVLNode(Type d = Type(), AVLNode<Type> *lf=nullptr, AVLNode<Type> *rg=nullptr)
		:data(d), left(lf), right(rg), bf(0)
	{}

	////析构函数
	~AVLNode()
	{}
private:
	Type data;
	AVLNode<Type> *left;
	AVLNode<Type> *right;
	int bf;//平衡因子

};

////AVL树类
template <typename Type>
class AVL
{
public:
	////构造函数
	AVL() :root(nullptr)
	{}

public:
	/////////////////////////////////////
	////函数声明

	bool Insert(const Type& x);//插入



protected: 
	void RotateR(AVLNode<Type>*& ptr);////右旋转
	void RotateL(AVLNode<Type>*& ptr);////左旋转
	void RotateLR(AVLNode<Type>*& ptr);////先左后右旋转
	void RotateRL(AVLNode<Type>*& ptr);////先右后左旋转
	bool _Insert(AVLNode<Type> *&t, const Type& x);


private:
	AVLNode<Type>* root;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////函数实现接口



//////////////////////////////////////////////////////////////
////右旋转
template <typename Type>
void AVL<Type>::RotateR(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* R = ptr;
	ptr = R->left;
	R->left = ptr->right;
	ptr->right = R;
	ptr->bf = R->bf = 0;


}


//////////////////////////////////////////////////////////////
////左旋转
template <typename Type>
void AVL<Type>::RotateL(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* L = ptr;
	ptr = L->right;
	L->right = ptr->left;
	ptr->left = L;
	ptr->bf = L->bf = 0;
}

//////////////////////////////////////////////////////////////
////先左后右旋转
template <typename Type>
void AVL<Type>::RotateLR(AVLNode<Type>*& ptr)
{
	//定义节点
	AVLNode<Type>* L = ptr->left;
	AVLNode<Type>* R = ptr;
	ptr = L->right;

	//左转
	L->right=ptr->left;
	ptr->left = L;

	//右转
	R->left = ptr->right;
	ptr->right = R;

	//调节平衡因子
	//左树
	if (ptr->bf == 1)
		L->bf = -1;
	else
		L->bf = 0;

	//左树
	if (ptr->bf == -1)
		R->bf = 1;
	else
		R->bf = 0;

	//根
	ptr->bf = 0;

}



//////////////////////////////////////////////////////////////
////先右后左旋转
template <typename Type>
void AVL<Type>::RotateRL(AVLNode<Type>*& ptr)
{
	//定义节点
	AVLNode<Type>* R= ptr->right;
	AVLNode<Type>* L = ptr;
	ptr = R->left;

	//右转
	R->left = ptr->right;
	ptr->right = R;

	//左转
	L->right = ptr->left;
	ptr->left= L;

	//调节平衡因子
	//右树
	if (ptr->bf == -1)
		R->bf = 1;
	else
		R->bf = 0;

	//左树
	if (ptr->bf == 1)
		L->bf = -1;
	else
		L->bf = 0;

	//根
	ptr->bf = 0;
}


//////////////////////////////////////////////////////////////
//插入
template <typename Type>
bool AVL<Type>:: Insert(const Type& x)
{
	return _Insert(root, x);
}

template <typename Type>
bool AVL<Type>:: _Insert(AVLNode<Type> *&t, const Type& x)
{
	////////////////////////////////
	//1、按照BST规则插入
	AVLNode<Type> *pr = nullptr;//父节点
	AVLNode<Type> *p = t;

	stack<AVLNode<Type>*> st;

	while (p != nullptr)
	{
		////用于查找x的插入位置
		if (x == p->data)
			return false;

		pr = p;
		st.push(pr);

		if (x < p->data)
			p = p->left;
		else
			p = p->right;
		
	}

	p = new AVLNode<Type>(x);
	if (pr == nullptr)
	{
		t = p;
		return true;
	}
	////节点连接
	else if (x < pr->data)
	{
		pr->left = p;
	}
	else
		pr->right = p;
	
	////////////////////////////////
	////////////////////////////////
	//2、如果不平衡，则进行调整
	while (!st.empty())
	{
		pr = st.top();
		st.pop();
		if (p == pr->left)
			pr->bf--;
		else
			pr->bf++;
		if (pr->bf == 0)
			break;
		if (pr->bf == 1 || pr->bf == -1)////  |bf|==1,向上回溯
			p = pr;
		else
		{
			////   |bf|==2   发生了不平衡，调整！
			if (p == pr->left)////左分支
			{
				if (p->bf < 0)
				{
					////右旋转
					RotateR(pr);
				}
				else
				{
					////先左后右旋转
					RotateLR(pr);
				}

			}

			else//右分支
			{
				if (p->bf > 0)
				{
					////左旋转
					RotateL(pr);
				}
				else
				{
					////先右后左旋转
					RotateRL(pr);
				}
				
			}
			break;
		}
		
	}
	if (st.empty())
		t = pr;
	else
	{
		AVLNode<Type>* ppr = st.top();
		if (ppr->data > pr->data)
			ppr->left = pr;
		else
			ppr->right = pr;

	}
	
	return true;
}

//////////////////////////////////////////////////////////////
//template <typename Type>
//template <typename Type>

//////////////////////////////////////////////////////////////
//template <typename Type>
//template <typename Type>


//////////////////////////////////////////////////////////////
//template <typename Type>
//template <typename Type>
//template <typename Type>



#endif /*_AVL_H*/