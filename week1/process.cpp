#include<iostream>
using namespace std;

// 顺序结构
// 选择结构
// 循环结构

int main()
{
    // if语句
    int score=0;
    cout<<"请输入一个分数:"<<endl;
    cin>>score;
    cout<<"您输入的分数是:"<<score<<endl;
    if(score>=90){
        if(score==100){
            cout<<"您的成绩是卓越"<<endl;
        }
        else{
            cout<<"您的成绩很优秀"<<endl;
        }
    }
    else if(score>=80){
        cout<<"您的成绩是良"<<endl;
    }
    else{
        cout<<"您需要更努力"<<endl;
    }

    // 三目运算符
    int a=10;
    int b=20;
    int c=0;
    c=a>b?a:b;
    cout<<c<<endl; 

    // 三目运算符返回的是变量,可以继续赋值
    (a>b?a:b)=100;
    cout<<a<<endl;
    cout<<b<<endl;


    // switch语句,不能表示区间
    switch (score)
    {
    case 10:
        cout<<"优秀"<<endl;
        break; //退出当前分支
    case 9:
        cout<<"优秀"<<endl;
        break;
    case 8:
        cout<<"良"<<endl;
    default:
        cout<<"继续努力"<<endl;
        break;
    }


    // 循环语句
    int num=0;
    while(num<10)
    {
        cout<<num<<endl;
        num++;
    }
    
    // do...while先执行一遍,再判断
    int number=0;
    do
    {
        cout<<number<<endl;
        number++;
    }
    while(number<10);

    // for循环
    for(int i=0;i<10;i++)
    {
        cout<<i<<endl;
    }

    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout<<"* ";
        }
        cout<<endl;   //endl是换行
    }

    system("pause");
    return 0;
}
