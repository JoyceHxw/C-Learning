#include <iostream>
using namespace std;
#include "MyArray.hpp"


void printIntArray(MyArray<int>& arr){
    for(int i=0;i<arr.getSize();i++){
        cout<<arr[i]<<endl;
    }
}

void test(){
    MyArray <int>arr1(5);
    // MyArray<int>arr2(arr1);
    // MyArray<int>arr3(100);
    // arr3=arr1;

    for (int i=0; i<5; i++){
        arr1.Push_Back(i);
    }
    printIntArray(arr1);
    cout<<"容量"<<arr1.getCapacity()<<endl;
    cout<<"大小"<<arr1.getSize()<<endl;

    arr1.Pop_Back();
    printIntArray(arr1);
    cout<<"容量"<<arr1.getCapacity()<<endl;
    cout<<"大小"<<arr1.getSize()<<endl;
}

// 测试自定义数据类型
class Person
{
public:
    Person(){};
    Person(string name, int age){
        m_Name=name;
        m_Age=age;
    }
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person>& arr){
    for(int i=0; i<arr.getSize(); i++){
        cout<<arr[i].m_Name<<arr[i].m_Age<<endl;
    }
}

void test2(){
    MyArray<Person> arr(10);
    Person p1("sam",10);
    Person p2("Mary",30);
    Person p3("Henry",30);

    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);

    printPersonArray(arr);
}

int main(){
    test();
    test2();
}