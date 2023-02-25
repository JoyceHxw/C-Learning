#include<iostream>
using namespace std;

int main(){
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            if(j==5)
            {
                break; //退出内层循环,不影响外层循环
            }
            cout<<"* ";
        }
        cout<<endl;   //endl是换行
    }

    for(int i=0;i<=10;i++)
    {
        if(i%2==0)
        {
            continue; //后面语句不再执行,开始下一次循环
        }
        cout<<i<<endl;
    }

    //goto 直接跳转到标记处开始执行
    cout<<1<<endl;
    cout<<2<<endl;
    goto FLAG;
    cout<<3<<endl;
    cout<<4<<endl;
    FLAG:
    cout<<5<<endl;
}