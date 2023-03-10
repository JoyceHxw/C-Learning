#include <iostream>
using namespace std;

class C{
    int a;
};

struct S
{
    int a;
};

int main(){
    // struct默认权限是public
    // class默认权限是private
    C c;
    S s;
    // c.a=100;
    s.a=100;
}