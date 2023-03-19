#include <iostream>
using namespace std;

class Person1
{
public:
    void showPerson1(){
        cout<<"Person1"<<endl;
    }
};

class Person2
{
public:
    void showPerson2(){
        cout<<"Person2"<<endl;
    }
};

template <typename T>
class MyClass
{
public:
    T obj;

    // 类模板中的成员函数
    void func1(){
        obj.showPerson1();
    }

    void func2(){
        obj.showPerson2();
    }
};

void test(){
    MyClass<Person1>m;
    m.func1();
    // m.func2();
}

int main(){
    test();
}