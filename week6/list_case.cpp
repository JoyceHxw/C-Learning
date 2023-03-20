#include <iostream>
using namespace std;
#include <list>

class Person
{
public:
    string m_name;
    int m_age;
    int m_height;

    Person(string name, int age, int height){
        m_name=name;
        m_age=age;
        m_height=height;
    }
};

// 年龄升序
bool compareAge(Person& p1, Person& p2){
    if(p1.m_age==p2.m_age){
        // 年龄相同,身高降序
        return p1.m_height>p2.m_height;
    }
    else{
        return p1.m_age<p2.m_age;
    }
}

void test(){
    list<Person> l;
    Person p1("刘备",35,175);
    Person p2("曹操",45,180);
    Person p3("孙权",30,185);
    Person p4("赵云",35,180);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);

    for(list<Person>::iterator it=l.begin(); it!=l.end(); it++){
        cout<<(*it).m_name<<" "<<(*it).m_age<<" "<<(*it).m_height<<endl;
    }

    l.sort(compareAge);
    for(list<Person>::iterator it=l.begin(); it!=l.end(); it++){
        cout<<(*it).m_name<<" "<<(*it).m_age<<" "<<(*it).m_height<<endl;
    }

}

int main(){
    test();
}
