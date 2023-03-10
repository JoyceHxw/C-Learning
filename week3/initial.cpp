#include <iostream>
using namespace std;

// 对象的初始化和清理
class Person
{
public:
    int age;
    // 构造函数
    // 没有返回值，不用写void
    // 函数名 与类名相同
    // 构造函数可以有参数，可以发生重载
    // 创建对象的时候，构造函数会自动调用，且只调用一次

    // 构造函数按照参数分类：无参构造，有参构造
    // 按照类型分类，普通构造，拷贝构造

    // 构造函数的调用规则
    // 创建一个类，编译器会给每个类都添加至少3个函数（默认，有参，拷贝（值拷贝））
    // 如果写了有参构造函数，编译器就不再提供默认构造函数，依然提供拷贝构造
    // 如果写了拷贝构造，编译器不再提供其他构造函数
    Person(){
        cout<<"initial"<<endl;
    }
    Person(int a){
        age=a;
        cout<<"initial parameter"<<endl;
    }
    // 拷贝构造
    Person(const Person &p){
        age=p.age;
        cout<<"initial copy"<<endl;
    }
    
    // 析构函数，进行清理操作
    // 没有返回值，不写void
    // 函数名和类名相同，在名称前加~
    // 析构函数不可以有参数，不可以重载
    // 对象在销毁前，会自动调用析构函数，且只调用一次
    ~Person(){
        cout<<"delete"<<endl;
    }
};

// 构造和析构都是必须有的实现，如果自己不提供，编译器会提供空实现的构造和析构
// 调用
void test1(){
    // 1.构造法
    // 调用默认构造函数时，不要加()，不然编译器会认为是一个函数的声明
    // Person p; //在栈上的数据，test1执行完毕后，释放这个对象  默认构造函数调用
    // Person p2(10);  //有参构造函数
    // Person p3(p2);

    // 2.显示法
    // Person p1;
    // Person p2=Person(10); //等号右边是匿名对象，执行结束后，匿名对象会被释放
    // Person p3=Person(p2); //不要利用拷贝构造函数初始化匿名对象

    // 3.隐式转换法
    // Person p4=10;  //相当于Person p4=Person(10); 有参构造
    // Person p5=p4; //拷贝构造


    // 拷贝函数的调用时机
    // 1.使用一个已经创建完毕的对象来初始化一个新对象
    Person p1(20);
    Person p2(p1);
    cout<<"p2的年龄"<<p2.age<<endl;
}

// 2.值传递的方式给函数参数传值
void doWork(Person p){

}
void test2(){
    Person p;
    doWork(p);
}

// 3.值方式返回局部对象 (结果是一样的，编译器返回值优化了)
Person doWork2(){
    Person p1;
    cout<<&p1<<endl;
    return p1;
}
void test3(){
    Person p=doWork2();
    cout<<&p<<endl;
}

int main(){
    // test1();
    // Person p;  //程序执行结束后释放
    // system("pause");
    // return 0;

    // test2();
    test3();
}