#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//类定义
class CGonds
{
public:
	void RegisterGond(char *name, size_t count, float price);
	float GetTotalPrice();
	char *GetName();
	size_t GetCount();
	float GetPrice();

private:
	char m_name[20];
	size_t m_count;
	float m_price;
	float m_total_price;
};
//类接口函数实现
void CGonds::RegisterGond(char *name, size_t count, float price)
{
	strcpy(m_name, name);
	m_count=count;
	m_price=price;
	m_total_price = m_price*m_count;

}
 float CGonds::GetTotalPrice()
{
	return m_total_price;
}
char* CGonds::GetName()
{
	return m_name;
}
size_t CGonds::GetCount()
{
	return m_count;
}
float CGonds::GetPrice()
{
	return m_price;
}

int main()
{
	CGonds c1;
	c1.RegisterGond("上邪", 5, 30);
	cout << "name:" << c1.GetName() << endl;
	cout << "price:" << c1.GetPrice ()<< endl;
	cout << "count :" << c1.GetCount() << endl;
	cout << "totalPrice:" << c1.GetTotalPrice() << endl;
	return 0;
}