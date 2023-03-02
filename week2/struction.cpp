#include <iostream>
using namespace std;

// 结构体：自定义数据类型
struct Student
{
    string name;
    int age;
    int score;
} s3;

struct Teacher {
    int id;
    string name;
    int age;
    struct Student stu;
};

// 值传递
// 拷贝所有数据，增加内存
void printStudent(struct Student s){
    cout<<s.name<<s.age<<s.score<<endl;
}

// 地址传递
// 减少内存空间，不会复制新的副本
// const防止误操作
void printStudent2(const Student *s){
    // s->age=200;
    cout<<s->name<<s->age<<s->score<<endl;
}


int main() {
    // 方式一
    struct Student s1;  //struct关键字可以省略
    s1.name="张三";
    s1.age=18;
    s1.score=100;
    cout<<"姓名："<<s1.name<<"年龄："<<s1.age<<"分数："<<s1.score<<endl;

    // 方式二
    struct Student s2={"李四",19,90};
    cout<<"姓名："<<s2.name<<"年龄："<<s2.age<<"分数："<<s2.score<<endl;

    // 方式三
    s3.name="王五";
    s3.age=20;
    s3.score=48;
    cout<<"姓名："<<s3.name<<"年龄："<<s3.age<<"分数："<<s3.score<<endl;

    // 结构体数组
    struct Student stuArray[3]=
    {
        {"Mary",12,59},
        {"Mike",44,69},
        {"Jane",22,78}
    };
    stuArray[2].name="Sam";
    for(int i=0;i<3;i++){
        cout<<stuArray[i].name<<stuArray[i].age<<stuArray[i].score<<endl;
    }

    // 通过指针访问结构体变量
    Student *p=&s1;
    cout<<p->name<<p->age<<p->score;

    // 结构体嵌套结构体
    Teacher t;
    t.id=19913;
    t.name="王老师";
    t.age=50;
    t.stu.name="小王";
    t.stu.age=20;
    t.stu.score=100;
    cout<<t.name<<t.age<<t.id<<t.stu.name<<t.stu.age<<t.stu.score<<endl;

    // 结构体做函数参数
    // 将学生传入函数，打印学生信息
    printStudent(s1);
    printStudent2(&s1);

    
}
