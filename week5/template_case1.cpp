#include <iostream>
using namespace std;
#include <math.h>

template <typename T>
void sort(T arr[], int len){
    for(int i=0; i<len; i++){
        int m=i; //认定最大值的下标
        for(int j=i+1; j<len; j++){
            // 认定的最大值比遍历出的数值要小，说明j下标的元素才是真正的最大值
            if(arr[m]<arr[j]){
                m=j;
            }
        }
        if(m!=i){
            T temp=arr[m];
            arr[m]=arr[i];
            arr[i]=temp;
        }
    }
}

template <typename T>
void print(T arr[], int len){
    for (int i=0; i<len; i++){
        cout<<arr[i];
    }
}

void test(){
    // 测试char数组
    char charArr[]="badcfe";
    int len=sizeof(charArr)/sizeof(char);
    sort(charArr,len);
    print(charArr,len);

    // 测试int数组
    int intArr[]={4,2,5,3,7,4,3};
    int num=sizeof(intArr)/sizeof(int);
    sort(intArr,num);
    print(intArr,num);
}

int main(){
    test();
    cout<<"--------";
    cout<<pow(0.8,10)<<endl;
}