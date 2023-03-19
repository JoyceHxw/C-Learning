#include <iostream>
using namespace std;
#include <string>

// 如果要使用类模板的头文件，将.h和.cpp文件写到一起，将后缀名改为.hpp文件


// 类模板对象做函数参数
template <typename T1, typename T2>
class Person
{
public:
    T1 m_name;
    T2 m_age;

    Person(T1 name, T2 age){
        m_name=name;
        m_age=age;
    }

    void showPerson(){
        cout<<m_name<<endl;
        cout<<m_age<<endl;
    }
};

// 构造函数类外实现
// template <typename T1, typename T2>
// Person<T1,T2>::Person(T1 name, T2 age){

// }

// 成员函数类外实现
// template <typename T1, typename T2>
// void Person<T1,T2>::showPerson(){

// }

// 1.指定传入类型
void printPerson1(Person<string, int>&p){
    p.showPerson();
}

void test1(){
    Person<string, int>p("孙悟空",100);
    printPerson1(p);
    // p.showPerson();
}

// 2.参数模板化
template<typename T1, typename T2>
void printPerson2(Person<T1,T2>&p){
    p.showPerson();
}
void test2(){
    Person<string,int>p("猪八戒",88);
    printPerson2(p);
}

// 3.整个类模板化
template <typename T>
void printPerson3(T &p){
    p.showPerson();
    cout<<typeid(T).name()<<endl;
}
void test3(){
    Person<string,int>p("唐僧",200);
    printPerson3(p);
}

int main(){
    test1();
    test2();
    test3();
}