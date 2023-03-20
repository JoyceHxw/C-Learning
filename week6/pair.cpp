#include <iostream>
using namespace std;

// pair对组的创建
void test1(){
    pair<string, int>p("Tom",20);
    cout<<p.first<<p.second<<endl;

    pair<string, int>p2=make_pair("Jerry",30);
    cout<<p2.first<<p2.second<<endl;

}
int main(){
    test1();
}