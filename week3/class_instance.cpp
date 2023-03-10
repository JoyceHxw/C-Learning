#include <iostream>
using namespace std;

// 类对象作为类成员
// 先构造类对象，再构造自身
// 析构顺序与构造相反
class Phone
{
public:
    string name;

    Phone(string n){
        name=n;
        cout<<"Phone构造函数"<<endl;
    }

    ~Phone(){
        cout<<"Phone析构函数"<<endl;
    }
};

class Person
{
public:
    string name;
    Phone phone;

    // 相当于隐式转换法 Phone phone=np;
    Person(string n, string pn): name(n), phone(pn){
        cout<<"Person构造函数"<<endl;
    }
    ~Person(){
        cout<<"Person析构函数"<<endl;
    }
};

void test(){
    Person p("张三","iphone");
    cout<<p.name<<p.phone.name<<endl;
}

int main(){
    test();
}