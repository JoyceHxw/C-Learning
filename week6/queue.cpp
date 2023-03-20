#include <iostream>
using namespace std;
#include <queue>

// 不允许遍历
void test1(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while(!q.empty()){
        cout<<q.front()<<" ";
        cout<<q.back()<<endl;
        q.pop();
    }

    cout<<q.size()<<endl;
}

int main(){
    test1();
}