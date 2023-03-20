#include <iostream>
using namespace std;
#include <list>

// stl中的链表是一个双向循环链表

void printList(const list<int> &l){
    for(list<int>::const_iterator it=l.begin(); it!=l.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

// list构造函数
void test1(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    list<int>l2(l1.begin(),l1.end());
    printList(l2);

    list<int>l3(l2);
    printList(l3);

    list<int>l4(10,100);
    printList(l4);
}

// list赋值和交换
void test2(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    list<int>l2;
    l2=l1;
    printList(l2);

    list<int>l3;
    l3.assign(l2.begin(),l2.end());
    printList(l3);

    list<int>l4;
    l4.assign(10,100);
    printList(l4);

    l1.swap(l4);
    printList(l1);
    printList(l4);

}

// list大小操作
void test3(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout<<l1.empty()<<endl;
    cout<<l1.size()<<endl;

    l1.resize(10);
    printList(l1);

    l1.resize(2);
    printList(l1);
}

// list插入和删除
void test4(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    printList(l1);

    l1.pop_back();
    printList(l1);

    l1.pop_front();
    printList(l1);

    l1.insert(++l1.begin(),1000);
    printList(l1);

    l1.erase(l1.begin());
    printList(l1);

    // 移除（删除所有匹配）
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    printList(l1);
    l1.remove(10000);
    printList(l1);

    l1.clear();
}

// list数据存取
void test5(){
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    // 不能用[]和at访问
    // 不支持随机访问
    cout<<l1.front()<<endl;
    cout<<l1.back()<<endl;
}

bool myCompare(int v1, int v2){
    return v1>v2;
}
// list 反转和排序
void test6(){
    list<int>l1;
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(10);
    l1.push_back(40);

    // 反转
    l1.reverse();
    printList(l1);

    // 排序
    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // 内部提供算法
    l1.sort();
    printList(l1);
    l1.sort(myCompare); //降序
    printList(l1);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}