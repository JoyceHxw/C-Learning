#include <iostream>
using namespace std;

class Person
{
public:
    int m_age;

    void showClassName(){
        cout<<"Person class"<<endl;
    }
    void showPersonAge(){
        if(this==NULL){
            return;
        }
        cout<<this->m_age<<endl;
    }
};

void test(){
    Person *p=NULL;
    p->showClassName();
    // 报错是因为传入的指针是空，加if语句
    p->showPersonAge();
}

int main(){
    test();
}