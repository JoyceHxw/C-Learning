#include <iostream>
using namespace std;
#include <functional>
#include <vector>
#include <algorithm>

// 函数对象（仿函数）

// 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2){
        return v1+v2;
    }
};

void test1(){
    MyAdd myAdd;
    cout<<myAdd(10,10)<<endl;
}

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint(){
        count=0;
    }
    void operator()(string test){
        cout<<test<<endl;
        count++;
    }

    int count;
};

void test2(){
    MyPrint myPrint;
    myPrint("hello");
    myPrint("hello");
    myPrint("hello");
    cout<<myPrint.count<<endl;
}


// 函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test){
    mp(test);
}
void test3(){
    MyPrint myPrint;
    doPrint(myPrint,"hello C++");
}


// 内建函数对象 
// 算数仿函数
// negate 一元仿函数 取反仿函数
void test4(){
    negate<int>n;
    cout<<n(50)<<endl;
}

// plus 一元仿函数 加法
void test5(){
    plus<int>p;
    cout<<p(10,20)<<endl;
}

// 关系仿函数
// 大于greater
void test6(){
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);

    // 降序
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0; i<5; i++){
        cout<<v[i]<<endl;
    }
}

// 逻辑仿函数
void test7(){
    vector<bool>v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);

    // 利用逻辑非，将容器v搬运到容器v2中，并取反
    vector<bool>v2;
    v2.resize(v.size());

    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for(int i=0; i<4; i++){
        cout<<v2[i]<<endl;
    }
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}