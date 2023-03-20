#include <iostream>
using namespace std;
#include <stack>

// 不允许遍历
void test1(){
    stack<int>s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    cout<<s.size()<<endl;
}

int main(){
    test1();
}