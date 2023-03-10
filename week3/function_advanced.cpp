#include <iostream>
using namespace std;

// 函数的默认参数
// 如果自己传了用自己的，如果没有，用默认值
// 默认参数变量必须放在最后
int func(int a, int b=20, int c=20){
    return a+b+c;
}

// 函数声明和函数实现只能一个有默认参数
int func2(int a=10, int b=20);

int func2(int a, int b){
    return a*b;
}


// 占位参数
// 占位参数可以有默认值
void func3(int a, int){
    cout<<"this is func3"<<endl;
} 


// 函数重载
// 必须在同一作用域下
// 函数名称相同
// 函数参数类型不同，或者个数不同，或者顺序不同
// 函数的返回值不可以作为函数重载的条件
void func3(char a){
    cout<<"this is func33"<<endl;
}

// 引用作为重载的条件
void func4(int &a){
    cout<<"func4"<<endl;
}

void func4(const int &a){
    cout<<"func4 const"<<endl;
}

// 重载和默认参数
void func5(int a, int b=10){
    cout<<"func5 default";
}

void func5(int a){
    cout<<"func5";
}

int main(){
    cout<<func(10)<<endl;
    cout<<func(10,30)<<endl;
    cout<<func2()<<endl;

    func3(10,20); //占位参数必须填补
    func3('^');

    int a=10;
    func4(a);
    func4(20);

    // func5(10); //二义性报错
    func5(10,40);
}