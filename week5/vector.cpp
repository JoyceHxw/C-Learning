#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// vector容器存放内置数据类型
void myPrint(int val){
    cout<<val<<endl;
}

void test(){
    // 创建一个vector容器，数
    vector<int> v;

    // 向容器中插入数组
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin=v.begin();  //起始迭代器，指向容器中第一个元素
    // vector<int>::iterator itEnd=v.end();  //结束迭代器，指向容器中最后一个元素的下一个位置
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout<<*it<<endl;  //it本身是指针
    }
    // 利用stl提供的遍历算法
    for_each(v.begin(),v.end(),myPrint);
}


// vector中存放自定义数据类型
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

void test2(){
    vector<Person>v;
    Person p1("aaa",20);
    Person p2("fsda",70);
    Person p3("adfa",30);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for(vector<Person>:: iterator it=v.begin(); it!=v.end(); it++){
        cout<<(*it).m_name<<(*it).m_age<<endl;
    }

}


// 存放自定义数据类型 指针
void test3(){
    vector<Person*>v;
    Person p1("aaa",20);
    Person p2("fsda",70);
    Person p3("adfa",30);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for(vector<Person*>:: iterator it=v.begin(); it!=v.end(); it++){
        cout<<(*it)->m_name<<(*it)->m_age<<endl;
    }
}


// vector容器嵌套容器

void test4(){
    vector<vector<int>> v;
    // 创建小容器
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    // 向小容器中添加数据
    for (int i=0; i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(vector<vector<int>>:: iterator it=v.begin(); it!=v.end(); it++){
        for(vector<int>::iterator vit =(*it).begin(); vit!=(*it).end(); vit++){
            cout<<*vit<<endl;
        }
    }

}

// vector与普通数组的区别：
// 数组是静态空间，vector可以动态扩展
// 不是在原有空间后续新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间

void printVector(vector<int>& v){
    for(vector<int>:: iterator it=v.begin(); it!=v.end(); it++){
        cout<<*it<<' ';
    }
    cout<<endl;
}

// vector构造
void test5(){
    vector<int> v1;
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);

    vector<int> v3(10,100);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}

// vector赋值
void test6(){
    vector<int> v1;
    for (int i=0; i<10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    v2=v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);
}

//vector容量和大小
void test7(){
    vector<int> v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }

    cout<<v1.empty()<<endl;
    cout<<v1.capacity()<<endl;
    cout<<v1.size()<<endl;  //容量大于等于大小

    v1.resize(15);
    cout<<v1.size()<<endl;  //默认0填充，可以替换
    v1.resize(4); //如果比原来短，超出部分被删除
    printVector(v1);
}

// vector插入和删除
void test8(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    
    printVector(v1);

    v1.pop_back();
    printVector(v1);

    v1.insert(v1.begin(),100);
    printVector(v1);

    v1.insert(v1.begin(),2,1000);
    printVector(v1);

    v1.erase(v1.begin());
    printVector(v1);

    // 清空
    v1.erase(v1.begin(),v1.end());
    printVector(v1);

    v1.clear();
}

// vector数据存取
void test9(){
    vector<int> v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    for (int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i=0; i<v1.size(); i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;

    // 获取第一个元素
    cout<<v1.front()<<endl;
    // 获取最后一个元素
    cout<<v1.back()<<endl;
}

// vector互换容器
void test10(){
    vector<int> v1;
    for(int i=0; i<10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for(int i=0; i<10; i++){
        v2.push_back(10-i);
    }
    printVector(v2);

    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    // 巧用swap可以收缩内存空间
    vector<int>v3;
    for(int i=0; i<10000; i++){
        v3.push_back(i);
    }
    cout<<v3.capacity()<<endl;
    cout<<v3.size()<<endl;

    v3.resize(3);  //浪费空间
    cout<<v3.capacity()<<endl;
    cout<<v3.size()<<endl;

    vector<int>(v3).swap(v3);  //匿名对象，交换容器
    cout<<v3.capacity()<<endl;
    cout<<v3.size()<<endl;
}

// vector预留空间
void test11(){
    vector<int> v1;

    // 利用reserve预留空间
    v1.reserve(10000); // 不用开辟新空间

    int num=0; //统计开辟次数 本来要开辟15次
    int *p=NULL;
    for(int i=0; i<10000; i++){
        v1.push_back(i);

        if(p!=&v1[0]){
            p=&v1[0];
            num++;
        }
    }
    cout<<num<<endl;
}

int main(){
    // test();
    // test2();
    // test3();
    // test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
}