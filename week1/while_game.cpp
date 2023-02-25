#include<iostream>
using namespace std;

int main()
{
    int num=rand()%100;
    int guess=0;
    while(guess!=num)
    {
        cin>>guess;
        if (guess>num)
        {
            cout<<"猜大了"<<endl;
        }
        else if(guess<num)
        {
            cout<<"猜小了"<<endl;
        }
        else
        {
            cout<<"猜对了!"<<endl;
        }
    }
}