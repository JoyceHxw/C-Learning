#include <iostream>
using namespace std;

// 成员变量和成员函数分开储存
// 空对象占用内存空间为1，为了区分空对象占内存的位置
// 非静态成员变量属于类的对象
// 静态成员变量不属于类对象上
class Person
{
public:
    // 静态成员变量
    // 所有对象都共享同一份数据
    // 编译阶段就分配内存
    // 类内声明,类外初始化操作
    static int age;

    // 静态成员函数
    // 所有对象共享同一个函数
    // 静态成员函数只能访问静态成员变量
    static void func(){
        age=100;
        cout<<"static func"<<endl;
        cout<<age<<endl;
    }

    // 访问权限
private:
    static int weight;
};

int Person::age=20;

void test(){
    Person p;
    cout<<p.age<<endl;
    p.func();

    Person p2;
    p2.age=39;
    cout<<p.age<<endl;
}

void test2(){
    // 静态成员变量不属于某个对象,所有对象都共享同一份数据
    // 静态成员变量有两种访问方式
    // 1.通过对象进行访问
    // 2.通过类名进行访问
    cout<<Person::age<<endl;
    Person::func();

    // cout<<Person::height<<endl; 类外访问不到私有静态成员变量
}

int main(){
    test();
    test2();
}