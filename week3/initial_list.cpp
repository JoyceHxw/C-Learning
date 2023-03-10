#include <iostream>
using namespace std;

class Person
{
public:
    int a;
    int b;
    int c;

    Person(int x, int y, int z):a(x), b(y), c(z){

    }
};

void test(){
    // 初始化列表
    Person p1(40,20,30);
    cout<<p1.a<<endl;
    cout<<p1.b<<endl;
    cout<<p1.c<<endl;
}

int main(){
    test();
}
