#include <iostream>
using namespace std;
#include <string>

// 1.整型
// short(短整型)，2字节
// int(整型)，4字节
// long(长整型)，4字节
// long long(长长整型)，8字节

// 2.浮点型
// float单精度，4字节，7位有效数字
// double双精度，8字节，15-16位有效数字
// 默认情况下，输出一个小数，会显示6位有效数字

// 3.字符型
// char ch='a'; 1字节，单引号，只能有一个字母

// 4.转义字符
// 换行符，制表符

// 5.字符串
// string

// 6.布尔类型
// 非零值都为真

int main()
{
    // sizeof求出数据类型占用内存的大小
    // sizeof(数据类型/变量)
    short num=10;
    cout<<"short占用内存空间为 "<<sizeof(short)<<endl;
    cout<<"short占用内存空间为 "<<sizeof(num)<<endl;

    float f1=3.14f;
    // 科学计数法
    float f2=3e2;
    cout<<f2<<endl;

    // 字符型变量对应的ASCII编码
    char ch ='a';
    char ch2='A';
    cout<<(int)ch<<endl;
    cout<<(int)ch2<<endl;

    cout<<"hello word\n";
    cout<<"aaa\thello"<<endl;
    cout<<"a\thello"<<endl;
    cout<<"aaaa\thello"<<endl;

    char str[]="hello";  //双引号
    cout<<str<<endl;  //头文件#include <string>

    string str2="world";
    cout<<str2<<endl;


    // 数据的输入cin>>变量
    int a=1;
    cout<<"请赋值："<<endl;
    cin>>a;
    cout<<a<<endl;

    system("pause");
    return 0;
}