// 内存中的四区
// 1.代码区（程序运行前）：存放函数体的二进制代码，由操作系统进行管理
    // 存放CPU执行的机器指令
    // 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
    // 代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令
// 2.全局区（程序运行前）：存放全局变量和静态变量以及常量
    // 全局变量和静态变量存放在此
    // 包含常量区，字符串常量和const修饰的全局常量
    // 该区域的数据在程序结束后由操作系统释放
// 3.栈区（程序运行后）：由编译器自动分配释放，存放函数的参数值，局部变量
    // 不要返回局部变量的地址
// 4.堆区（程序运行后）：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
    // 在c++中主要利用new在堆区开辟内存
    // 释放利用操作符delete

#include <iostream>
using namespace std;

// 全局变量
int g_a=10;

const int c_g_a=10;

int * func(){
    // 利用new关键字，将数据开辟到堆区
    // new返回的是该数据类型的指针
    int *p=new int(10);
    return p;
}

int * func2(){
    // 创建数组
    int * arr=new int[10];
    for (int i=0; i<10; i++){
        arr[i]=i+100;
    }
    for (int i=0; i<10; i++){
        cout<<arr[i]<<endl;
    }
    return arr;
}

int main() {
    // 普通局部变量
    int a=10;
    cout<<"局部变量a的地址为："<<&a<<endl;
    cout<<"全局变量g_a的地址为："<<&g_a<<endl;

    // 静态变量
    static int s_a=10;
    cout<<"全局变量s_a的地址为："<<&s_a<<endl;

    // 常量
    // 字符串常量
    cout<<"字符串常量的地址为："<<&"Hello"<<endl;
    // const修饰的常量
    // const修饰的全局变量，const修饰的局部变量
    cout<<"全局常量c_g_a的地址为："<<&c_g_a<<endl;
    const int c_l_a=10;
    cout<<"局部常量c_l_a的地址为："<<&c_l_a<<endl;


    // 在堆区开辟数据
    int *p=func();
    cout<<*p<<endl;
    cout<<*p<<endl;
    // 用 delete释放
    delete p;
    // 释放数组
    int *arr=func2();
    delete[] arr;



}