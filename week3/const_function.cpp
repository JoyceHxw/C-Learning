#include <iostream>
using namespace std;

//常函数
class Person
{
public:
    int m_a;
    mutable int m_b;  //特殊变量可以修改

    Person(){
        
    }
    // this指针的本质是指针常量，指针的指向是不可以修改的
    // 在成员函数后面加const，修饰的是this指向，不可以修改指针指向值
    void showPerson() const{
        // m_a=100; 
        this->m_b=100;
    }
};

void test(){
    Person p;
    p.showPerson();
}

// 常对象
void test2(){
    const Person p;
    // p.m_a=100;
    p.m_b=100; // mutable修饰，在常对象下也可以修改

    // 常对象只能调用常函数
    p.showPerson();
}

int main(){
    test();
    test2();
}