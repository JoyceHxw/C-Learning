#include <iostream>
using namespace std;

// 加号运算符重载

class Person
{
public:
    int m_a;
    int m_b;

    // 成员函数重载+
    // Person operator+(Person &p){
    //     Person temp;
    //     temp.m_a=this->m_a+p.m_a;
    //     temp.m_b=this->m_b+p.m_b;
    //     return temp;
    // }

};

// 全局函数重载+号
Person operator+(Person &p1, Person &p2){
    Person temp;
    temp.m_a=p1.m_a+p2.m_a;
    temp.m_b=p1.m_b+p2.m_b;
    return temp;
}


// 只能利用全局函数重载左移运算符
// ostream & operator<<(ostream &cout, Person &p){
//     cout<<"m_a="<<p.m_a<<"m_b="<<p.m_b;
//     return cout;
// }


// 重载递增运算符
class MyInteger
{
    friend ostream & operator<<(ostream &cout, MyInteger myint);
private:
    int m_Num;
public:
    MyInteger(){
        m_Num=0;
    }

    // 重载前++
    // 返回引用为了一直对一个数据进行递增
    MyInteger &operator++(){
        m_Num++;
        return *this;
    }
    // 重载后++
    // operator++(int) int代表占位参数，可以用于区分前置和后置递增
    // 返回值
    MyInteger operator++(int){
        MyInteger temp=*this;
        m_Num++;
        return temp;
    }
};

ostream & operator<<(ostream &cout, MyInteger myint){
    cout<<myint.m_Num;
    return cout;
}


// 重载赋值运算符
class PersonEqual
{
public:
    int *m_age;

    PersonEqual(int age){
        m_age=new int(age);
    }

    ~PersonEqual(){
        if(m_age!=NULL){
            delete m_age;
            m_age=NULL;
        }
    }

    PersonEqual & operator=(PersonEqual &pe){
        // 应该先判断是否有属性在堆区，如果有，先释放，再深拷贝
        if (m_age!=NULL){
            delete m_age;
            m_age=NULL;
        }
        m_age=new int(*pe.m_age);
        return *this;
    }

};


// 函数调用运算符重载
class MyPrint
{
public:
    void operator()(string test){
        cout<<test<<endl;
    }
};

void test(){
    Person p1;
    p1.m_a=10;
    p1.m_b=10;
    Person p2;
    p2.m_a=20;
    p2.m_b=20;

    // Person p3=p1+p2;
    // 成员函数重载本质调用
    // Person p3=p1.operator+(p2);
    // 全局函数重载本质调用
    // Person p3=operator+(p1,p2);
    // cout<<p3.m_a<<endl;
    // cout<<p3.m_b<<endl;


    // 重载<<
    // cout<<p1<<endl;
    
    MyInteger myint;
    cout<<++(++myint)<<endl;
    cout<<myint++<<endl;
    cout<<myint<<endl;


    PersonEqual pe1(20);
    PersonEqual pe2(38);
    PersonEqual pe3(49);
    pe3=pe2=pe1;
    cout<<*pe1.m_age<<endl;
    cout<<*pe2.m_age<<endl;
    cout<<*pe3.m_age<<endl;


    MyPrint myprint;
    myprint("Hello"); //由于使用起来非常类似于函数调用，因此称为仿函数
}


int main(){
    test();
}