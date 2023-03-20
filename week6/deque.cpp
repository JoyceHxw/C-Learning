#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

void printDeque(const deque<int>& d){  //const迭代器，不可以修改
    for(deque<int>:: const_iterator it=d.begin(); it!=d.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

// deque构造函数
void test1(){
    deque<int>d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,100);
    printDeque(d3);

    deque<int>d4(d3);
    printDeque(d4);
}

// deque赋值
void test2(){
    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2=d1;
    printDeque(d2);

    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);
}

// deque大小操作
void test3(){
    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    cout<<d1.empty()<<endl;
    cout<<d1.size()<<endl;

    d1.resize(15);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

// deque插入和删除
void test4(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);

    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    d1.pop_back();
    printDeque(d1);

    d1.pop_front();
    printDeque(d1);

    d1.insert(d1.begin(),1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 200);
    printDeque(d1);

    // 按照区间插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);

    d1.erase(++d1.begin());
    printDeque(d1);

    d1.erase(d1.begin(), d1.end());
    printDeque(d1);
    d1.clear();
}

// deque数据存取
void test5(){
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    for(int i=0; i<d1.size(); i++){
        cout<<d1[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<d1.size(); i++){
        cout<<d1.at(i)<<" ";
    }
    cout<<endl;

    // 第一个元素
    cout<<d1.front()<<endl;
    // 最后一个元素
    cout<<d1.back()<<endl;
    
}

// deque排序
void test6(){
    deque<int>d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    // 对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序，vector也可以
    sort(d1.begin(),d1.end());
    printDeque(d1);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}