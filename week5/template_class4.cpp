#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Person;

// 类外实现
template <typename T1, typename T2>
void printPerson2(Person<T1,T2>p){
    cout<<"类外实现"<<p.m_name<<p.m_age<<endl;
}


template<typename T1, typename T2>
class Person 
{
    // 全局函数 类内实现
    friend void printPerson(Person <T1,T2> p){
        cout<<p.m_name<<p.m_age<<endl;
    }

    // 全局函数 类外实现
    // 加空模板参数列表
    // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person <T1,T2> p);

public:
    Person(T1 name, T2 age){
        this->m_name=name;
        this->m_age=age;
    }
private:
    T1 m_name;
    T2 m_age;
};



void test(){
    Person<string, int>p("Tom",20);
    printPerson(p);
    printPerson2(p);
}

int main(){
    test();
}