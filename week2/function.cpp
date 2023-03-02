#include <iostream>
using namespace std;
#include "swap.h"

// 函数
// 1.返回值类型
// 2.函数名
// 3.参数列表
// 4.函数体语句
// return表达式

int add(int num1, int num2)
{
    int sum=num1+num2;
    return sum;
}

// void swap(int num1, int num2)
// {
//     int temp=num1;
//     num1=num2;
//     num2=temp;
//     cout<<num1<<endl;
//     cout<<num2<<endl;
// }

// 函数的声明：提前告诉编译器函数的存在，可以利用函数的声明
// 可以把函数的定义放在调用后面
// 声明可以有多次，定义只能有一次
int max(int num1,int num2);

int main()
{
    int a=10;
    int b=34;
    int sum=add(a,b);
    cout<<sum<<endl;

    // 当进行值传递时，函数的形参发生改变，并不会影响实参
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    // 函数中的形参是新创建的地址
    swap(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    cout<<max(a,b)<<endl;
}

int max(int num1, int num2)
{
    return num1>num2?num1:num2;
}
