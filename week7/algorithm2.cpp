#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

void print01(int val){
    cout<<val<<" ";
}

// copy
void test1(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>v2;
    v2.resize(v.size());
    copy(v.begin(),v.end(),v2.begin());
    for_each(v2.begin(),v2.end(),print01);
    cout<<endl;
}

// replace
void test2(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    replace(v.begin(),v.end(),2,20);
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
}

// replace_if
class GreaterFive
{
public:
    bool operator()(int v){
        return v>5;
    }
};
void test3(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    replace_if(v.begin(),v.end(),GreaterFive(),100);
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
}

// swap
void test4(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>v2;
    for (int i=0; i<10; i++){
        v2.push_back(10-i);
    }
    swap(v,v2);
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    for_each(v2.begin(),v2.end(),print01);
    cout<<endl;
}

// accumulate
void test5(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    int sum=accumulate(v.begin(),v.end(),0);  //起始累加值
    cout<<sum<<endl;
}

// fill
void test6(){
    vector<int>v;
    v.resize(10);
    
    // 重新填充默认值
    fill(v.begin(),v.end(),100);
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
}

// set_intersection/set_union/set_difference
// 两个集合必须是有序序列
void test7(){
    vector<int>v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>v2;
    for (int i=0; i<10; i++){
        v2.push_back(i+5);
    }
    vector<int>v3;
    v3.resize(min(v.size(),v2.size()));
    vector<int>::iterator itEnd=set_intersection(v.begin(),v.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),itEnd,print01);
    cout<<endl;
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