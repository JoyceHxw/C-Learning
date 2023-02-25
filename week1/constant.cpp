#include <iostream>
using namespace std;

// 常量的定义方式
// 1.#define宏常量
// 2.const修饰的变量

#define Day 7

int main()
{
    // Day=14; 常量不可修改

    cout <<"A week has "<<Day<<" days"<<endl;

    const int month =12;
    // month=24; 
    cout <<"A year has "<<month<<" months"<<endl;

    system("pause");
    return 0;
}