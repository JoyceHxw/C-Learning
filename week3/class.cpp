#include <iostream>
using namespace std;


const double PI=3.14;
class Circle{
    // 权限 
    // public 类内可以访问，类外可以访问
    // protected  类内可以访问，类外不可以访问，子类可以访问
    // private  类内可以访问，类外不可以访问，子类不可以访问
public:
    // 类中的属性和行为，统一称为成员
    // 属性
    int r;
protected:
    string name;

    // 成员属性设置为私有
    // 可以自己控制读写权限
    // 对于写可以检测数据的有效性
private:
    int age;

public:
    // 行为
    double get_c(){
        return 2*PI*r;
    }

    // 对私有变量提供可读可写权限
    int get_age(){
        return age;
    }
    void set_age(int a){
        if (a<0||a>150){
            age=0;
            cout<<"wrong age"<<endl;
        }
        else{
            age=a;
        }
    }
};

int main(){
    // 实例化
    Circle c;
    c.r=2;
    // c.name="圆";
    // c.age=12;
    cout<<c.get_c()<<endl;

    c.set_age(1000);
    cout<<c.get_age()<<endl;
}