#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    // 解决名称冲突
    Person(int age){
        // this指针指向被调用的成员函数 所属的对象
        this->age=age; //同名不加this会出错 
    }

    // 返回对象本身用*this
    Person& PersonAdd(Person &p){
        this->age+=p.age;

        // this指向p2的指针，*this指向的就是p2这个对象本体
        return *this;
    }
};

void test(){
    Person p1(18);
    cout<<p1.age<<endl;
}

void test2(){
    Person p1(10);
    Person p2(10);
    // 链式编程思想
    p2.PersonAdd(p1).PersonAdd(p1).PersonAdd(p1);
    cout<<p2.age<<endl;
}

int main(){
    test();
    test2();
}