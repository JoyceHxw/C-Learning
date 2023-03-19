#include <iostream>
using namespace std;

// 类模板与继承
template <typename T>
class Base
{
    T m;
};

// 必须要知道父类中T类型，才能继承给子类
class Son: public Base<int>{

};

// 如果想灵活指定父类中T类型，子类也需要变类模板
template <typename T1, typename T2>  //T2为父类中的模板，T1为子类自己的
class Son2: public Base<T2>{
    T1 obj;
};

void test1(){
    Son s;
}

void test2(){
    Son2<int,char>s;
}

int main(){
    test1();
    test2();
}