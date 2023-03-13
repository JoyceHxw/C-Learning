#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak(){
        cout<<"说话"<<endl;
    }
};

class Cat: public Animal
{
public:
    void speak(){
        cout<<"小猫说话"<<endl;
    }
};

class Dog: public Animal
{
public:
    void speak(){
        cout<<"小狗说话"<<endl;
    }
};

// 地址早绑定，再编译阶段确定函数地址
// 如果想执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

// 动态多态满足条件：
// 1.有继承关系
// 2.子类要重写父类的虚函数

// 动态多态使用：
// 父类的指针或引用,指向子类对象

void doSpeak(Animal &animal){
    animal.speak();
}

void test1(){
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test2(){
    cout<<"sizeof Animal="<<sizeof(Animal)<<endl;
}

int main(){
    test1();
    test2();
}