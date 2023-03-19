#include <iostream>
using namespace std;

// 函数模板

// 与普通模板的区别：
// 1.普通函数调用可以发生隐式类型转换
// 2.函数模板：用自动类型推导，不可以发生隐式类型转换
// 3.函数模板：用显示指定类型，可以发生隐式类型转换

// 普通函数与函数模板调用规则：
// 1.如果函数模板和普通函数都可以调用，优先调用普通函数
// 2.可以通过空模板参数列表强调调用函数模板
// 3.函数模板可以发生函数重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板 
// 既然提供了模板函数，最好就不要提供普通函数了

template <typename T> //声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}

template <typename T>
T Plus(T a, T b){
    return a+b;
}

void print(int a, int b){
    cout<<"普通函数"<<endl;
}

template <typename T>
void print(T a, T b){
    cout<<"模板函数"<<endl;
}

template <typename T>
void print(T a, T b, T c){
    cout<<"重载的模板函数"<<endl;
}

void test(){
    int a=10;
    int b=20;
    
    char c='a';
    cout<<Plus<int>(a,c)<<endl;

    // 利用函数模板交换
    // 1.自动类型推导
    // 必须要推导出一致的数据类型T才可以使用
    // mySwap(a,b);
    // 2.显示指定类型
    // 模板必须确定T的数据类型，才可以使用
    mySwap<int>(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    print(a,b);
    print<>(a,b);
    print(a,b,20);
    char d='b';
    print(c,d);
    
}

int main(){
    test();
}