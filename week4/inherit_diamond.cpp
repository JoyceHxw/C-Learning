#include <iostream>
using namespace std;

class Animal
{
public:
    int m_age;
};

// 利用虚继承解决菱形继承的问题（虚基类指针，只指向一个数据）
// Animal类称为虚基类
class Sheep: virtual public Animal{};

class Camel: virtual public Animal{};

class Sheep_Camel: public Sheep, public Camel {};

void test(){
    Sheep_Camel sc;
    sc.Sheep::m_age=18;
    sc.Camel::m_age=30;

    cout<<sc.Sheep::m_age<<endl;
    cout<<sc.Camel::m_age<<endl;
    cout<<sc.m_age<<endl;
}

int main(){
    test();
}