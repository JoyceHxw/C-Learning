#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 谓词：仿函数返回值类型是bool类型
// 一元谓词
class GreaterFive
{
public:
    bool operator()(int val){
        return val>5;
    }
};
void test1(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(), v.end(), GreaterFive());
    if(it==v.end()){
        cout<<"未找到"<<endl;
    }
    else{
        cout<<*it<<endl;
    }
}

// 二元谓词
class MyCompare
{
public:
    bool operator()(int val1, int val2){
        return val1>val2;
    }

};
void test2(){
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);


    // 使用函数对象，改变算法策略
    sort(v.begin(), v.end(), MyCompare());
    for(int i=0; i<5; i++){
        cout<<v[i]<<endl;
    }
}

int main(){
    test1();
    test2();
}