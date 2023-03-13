#include <iostream>
using namespace std;

// 继承
// class 子类: 继承方式 父类
// 继承方式：公共继承，保护继承，私有继承

class BasePage{
public:
    void header(){
        cout<<"头部"<<endl;
    }
    void footer(){
        cout<<"底部"<<endl;
    }
    void left(){
        cout<<"左侧"<<endl;
    }
};

class JAVA: public BasePage
{
public: 
    void content(){
        cout<<"java"<<endl;
    }
};

class Python: public BasePage
{
public: 
    void content(){
        cout<<"python"<<endl;
    }
};


void test(){
    JAVA ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
}


class Base1
{
public:
    int m_a;
    Base1(){
        m_a=100;
        cout<<"Base1构造函数"<<endl;
    }
    ~Base1(){
        cout<<"Base1析构函数"<<endl;
    }
protected:
    int m_b;
private:
    int m_c;
};

class Son1: public Base1
{
public:
    int m_a;
    //先构造父类，再构造子类，析构的顺序与构造的顺序相反 
    Son1(){
        m_a=200;
        cout<<"Son1构造函数"<<endl;
    }
    ~Son1(){
        cout<<"Son1析构函数"<<endl;
    }
    void func(){
        m_a=10;
        m_b=10;
        // m_c=10;  //父类中的私有权限成员，子类访问不到
    }
};

class Son2: protected Base1
{
public:
    void func(){
        m_a=10; //protected
        m_b=10; //protected
        // m_c=10;  //父类中的私有权限成员，子类访问不到
    }
};

class Son3: private Base1
{
public:
    void func(){
        m_a=10; //private
        m_b=10; //private
        // m_c=10;  //父类中的私有权限成员，子类访问不到
    }
};

class GrandSon3: public Son3
{
public:
    void func(){
        // m_a=100; //孙子类访问不到
        // m_b=100; //孙子类访问不到
    }
};


// 多继承
class Son4: public BasePage, public Base1
{

};

void test2(){
    Son1 s1;
    s1.m_a=300;
    // s1.m_b=100; //到son1中，m_b是保护权限，类外访问不到

    // Son2 s2;
    // s2.m_a=100; //到son2中，m_a是保护权限，类外访问不到

    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性是被编译器隐藏了，因此是访问不到的，但确实被继承了
    cout<<"size of Son1="<<sizeof(s1)<<endl;

    cout<<"Son1 m_a="<<s1.m_a<<endl;
    // 如果通过子类对象访问父类中同名成员，需要加父类作用域
    cout<<"Base1 m_a="<<s1.Base1::m_a<<endl;
    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数，需要加父类作用域
    // 同名静态成员处理类似
}




int main(){
    test();
    test2();
}