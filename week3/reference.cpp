#include <iostream>
using namespace std;

// 引用传递
// 交换函数
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

// 引用做函数的返回值
// 不要返回局部变量的引用
// int& test01(){
//     int a=10;
//     return a;
// }
// 函数的调用可以作为左值
int& test02(){
    static int a=10;  //静态变量，存放在全局区，结束后系统释放
    return a;
}

void show(const int &value){
    // value=1000; //不能修改
    cout<<value<<endl;
}


int main() {
    // 引用基本语法：数据类型 &别名=原名
    // 引用必须初始化
    // 引用一旦初始化后就不可以更改了
    // 引用的本质是指针常量

    int a=10;
    int &b=a;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    b=100;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    int n1=10;
    int n2=20;
    swap(n1, n2);
    cout<<"n1="<<n1<<endl;
    cout<<"n2="<<n2<<endl;

    int &ref=test02();
    cout<<ref<<endl;
    test02()=1000;  //如果函数的返回值是引用，这个函数调用可以作为左值
    cout<<ref<<endl;

    // 常量引用，修饰形参防止误操作
    const int & ref1=10;  //不可修改
    show(a);
    cout<<a<<endl;

}