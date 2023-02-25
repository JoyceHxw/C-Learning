#include<iostream>
using namespace std;

// 算术运算符
// 赋值运算符
// 比较运算符
// 逻辑运算符

int main()
{
    // 两个整数相除，结果是整数，去除小数部分
    int a=10;
    int b=3;
    float c=3.3f;
    cout<<a/b<<endl;  //输出3
    cout<<a/c<<endl;  //输出3

    // 前置递增/递减：变量先+1，然后进行表达式运算
    int a1=10;
    int b1=++a1*10;
    cout<<b1<<endl;
    // 后置递增/递减：先进性表达式运算，再+1
    int a2=10;
    int b2=a2++*10;
    cout<<b2<<endl;
    system("pause");
    return 0;
}
