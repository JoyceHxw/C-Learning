#include <iostream>
using namespace std;
#include <fstream>

// 二进制文件 写文件
class Person
{
public:
    char m_name[64];
    int m_age;
};

void test(){
    ofstream ofs;
    ofs.open("person.txt",ios::out | ios::binary);
    Person p={"张三",18};
    ofs.write((const char *) &p, sizeof(Person));
    ofs.close();
}

void test2(){
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout<<"fail"<<endl;
        return;
    }
    Person p;
    ifs.read((char *) &p,sizeof(Person));
    cout<<p.m_name<<p.m_age<<endl;
    ifs.close();

}

int main(){
    // test();
    test2();
}