#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

// for_each
// 普通函数
void print01(int val){
    cout<<val<<" ";
}
// 仿函数
class print02
{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test1(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
}

// transform
class Transform
{
public:
    int operator()(int v){
        return v+100;
    }
};
void test2(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>v2;
    v2.resize(v.size()); //目标容器需要提前开辟空间
    transform(v.begin(),v.end(),v2.begin(),Transform());
    for(int i=0; i<10; i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}

// find
// 查找内置数据类型
void test3(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    vector<int>::iterator it=find(v.begin(),v.end(),5);
    if(it==v.end()){
        cout<<"没找到"<<endl;
    }
    else{
        cout<<(*it)<<endl;
    }
}

// 查找自定义数据类型
class Person
{
public:
    Person(string name, int age){
        m_name=name;
        m_age=age;
    }
    // 重载==，让find知道如何对比person数据
    bool operator==(const Person& p){
        if(this->m_name==p.m_name && this->m_age==p.m_age){
            return true;
        }
        else{
            return false;
        }
    }
    string m_name;
    int m_age;
};

void test4(){
    vector<Person>v;
    Person p1("a",10);
    Person p2("b",20);
    Person p3("c",30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    Person pp("b",20);
    vector<Person>::iterator it=find(v.begin(),v.end(),pp);
    if(it==v.end()){
        cout<<"没找到"<<endl;
    }
    else{
        cout<<(*it).m_name<<(*it).m_age<<endl;
    }
}

// find_if
class GreaterFive
{
public:
    bool operator()(int v){
        return v>5;
    }
};
void test5(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(), v.end(), GreaterFive());
    if(it==v.end()){
        cout<<"没找到"<<endl;
    }
    else {
        cout<<(*it)<<endl;
    }
}

// adjacent_find 查找相邻重复元素
void test6(){
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator it=adjacent_find(v.begin(),v.end());
    if(it==v.end()){
        cout<<"没找到相邻重复元素"<<endl;
    }
    else {
        cout<<(*it)<<endl;
    }
}

// binary_search
// 在无序序列中不可用
void test7(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }

    bool r=binary_search(v.begin(),v.end(),9);
    cout<<r<<endl;
}

// count
// 统计内置数据类型
void test8(){
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);

    int num=count(v.begin(),v.end(),20);
    cout<<num<<endl;
}

// 统计自定义数据类型
void test9(){
    vector<Person>v;
    Person p1("刘备",35);
    Person p2("关羽",30);
    Person p3("张飞",33);
    Person p4("赵云",30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person p("赵云",30);
    int num=count(v.begin(),v.end(),p);
    cout<<num<<endl;

}

// count_if
void test10(){
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    v.push_back(6);
    v.push_back(9);
    v.push_back(2);

    int num=count_if(v.begin(),v.end(),GreaterFive());
    cout<<num<<endl;
}

// random_shuffle
void test11(){
    vector<int>v;
    for(int i=0; i<10; i++){
        v.push_back(i);
    }
    // 打乱顺序
    srand((unsigned int)time(NULL));
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),print01);
}

// merge
void test12(){
    // 顺序要是一致的
    vector<int>v1;
    vector<int>v2;
    for(int i=0; i<10; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    vector<int>v3;
    v3.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),v3.end(),print01);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
}