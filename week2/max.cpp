#include <iostream>
using namespace std;
int main()
{
    int arr[5]={300,350,500,400,250};
    int m=0;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
    {
        if(arr[i]>=m)
        {
            m=arr[i];
        }
    }
    cout<<"最大值为"<<m<<endl;
}