#include <iostream>
using namespace std;

// 浅拷贝与深拷贝
class Person 
{
public:
    int age;
    int *m_height;

    Person(){
        cout<<"defaut"<<endl;
    }
    Person(int a, int height){
        age=a;
        m_height=new int(height);
        cout<<"parameter"<<endl;
    }
    Person(const Person &p){
        cout<<"深拷贝"<<endl;
        age=p.age;
        // m_height=p.m_height; //这是编译器默认实现的浅拷贝
        m_height=new int(*p.m_height);
    }

    ~Person(){
        // 将堆区开辟的数据释放
        if(m_height!=NULL){
            delete m_height;
            m_height=NULL;
        }
        cout<<"delete"<<endl;
    }
};

void test1(){
    Person p1(18,160);
    cout<<"p1的年龄"<<p1.age<<"身高为"<<*p1.m_height<<endl;

    // 如果利用编译器提供的拷贝函数，会做浅拷贝操作
    // 两个对象指向堆区同一个区域，析构时会出现重复释放
    // 需要自己实现拷贝构造函数，利用深拷贝重新开辟一个区域
    Person p2(p1); 
    cout<<"p2的年龄"<<p2.age<<"身高为"<<*p2.m_height<<endl;
}


int main(){
    test1();
}