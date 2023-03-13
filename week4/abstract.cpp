#include <iostream>
using namespace std;

// 纯虚函数和抽象类
class Base
{
public:
    // 纯虚函数
    // 只要有一个纯虚函数,这个类称为抽象类
    // 抽象类特点:
    // 1.无法实例化对象
    // 2.抽象类的子类必须要重写父类中的纯虚函数
    Base(){
        cout<<"Base构造函数"<<endl;
    }
    virtual void func()=0;

    // 利用虚析构解决父类指针释放子类对象时不干净的问题
    // virtual ~Base(){
    //     cout<<"Base的析构函数"<<endl;
    // }

    // 纯虚析构需要声明和实现
    // 有了纯虚析构后,这个类也属于抽象类,无法实例化对象
    virtual ~Base()=0;
};

Base::~Base(){
    cout<<"Base纯虚析构函数调用"<<endl;
}

class Son: public Base
{
public:
    string *m_name;

    Son(string name){
        cout<<"Son构造函数"<<endl;
        m_name=new string(name);
    }

    void func(){
        cout<<*m_name<<"func"<<endl;
    }

    ~Son(){
        cout<<"Son的析构函数"<<endl;
    }

};

void test(){
    Base *base=new Son("Tom");
    base->func();
    // 父类指针在析构时,不会调用子类中析构函数,导致子类如果有堆区属性,出现内存泄漏
    delete base;
}

int main(){
    test();
}