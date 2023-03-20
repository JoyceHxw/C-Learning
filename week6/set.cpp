#include <iostream>
using namespace std;
#include <set>

void printSet(set<int>& s){
    for(set<int>:: iterator it=s.begin(); it!=s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

// set容器构造和赋值
// 去重和排序
void test1(){
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);

    printSet(s1);

    set<int>s2(s1);
    printSet(s2);

    set<int>s3;
    s3=s2;
}

// set大小和交换
void test2(){
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);

    cout<<s1.empty()<<endl;
    cout<<s1.size()<<endl;

    set<int>s2;
    s2.insert(100);
    s2.insert(400);
    s2.insert(200);
    s2.insert(300);

    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}

// set插入和删除
void test3(){
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);

    s1.insert(100);
    s1.insert(1);

    printSet(s1);

    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(100);
    printSet(s1);

    s1.clear();
}

// set查找和统计
void test4(){
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);

    set<int>:: iterator pos=s1.find(30);
    if(pos!=s1.end()){
        cout<<*pos<<endl;
    }
    else{
        cout<<"未找到"<<endl;
    }

    int num=s1.count(30);
    cout<<num<<endl;
}

// set和multiset区别
void test5(){
    set<int>s1;
    s1.insert(10);
    s1.insert(10);

    multiset<int>m1;
    m1.insert(10);
    m1.insert(10);

    printSet(s1);

    for (multiset<int>::iterator it=m1.begin(); it!=m1.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

// set排序
class MyCompare
{
public:
    bool operator()(int v1, int v2){
        return v1>v2;
    }
};
void test6(){
    // 指定排序规则为从大到小
    set<int,MyCompare>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);

    for(set<int,MyCompare>::iterator it=s1.begin(); it!=s1.end(); it++){
        cout<<*it<<" ";
    }
    
}

// set排序，存放自定义数据类型
class Person
{
public:
    string m_name;
    int m_age;
    Person(string name, int age){
        m_name=name;
        m_age=age;
    }
};

class PersonCompare
{
public:
    bool operator()(const Person& p1, const Person& p2){
        return p1.m_age>=p2.m_age;
    }
};

void test7(){
    set<Person,PersonCompare>s;
    Person p1("刘备",35);
    Person p2("曹操",45);
    Person p3("孙权",30);
    Person p4("赵云",35);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for(set<Person,PersonCompare>::iterator it=s.begin(); it!=s.end(); it++){
        cout<<(*it).m_name<<(*it).m_age<<endl;
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