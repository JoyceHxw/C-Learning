#include <iostream>
using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;
};

// 数组默认地址传递
void bublleSort(Hero h[], int len){
    for (int i=0; i<len-1; i++) {
        for (int j=0; j<len-1-i; j++) {
            if(h[j].age>h[j+1].age){
                Hero temp=h[j];
                h[j]=h[j+1];
                h[j+1]=temp;
            }
        }
    }
}

void print(Hero h[], int len){
    for (int i=0;i<len;i++){
        cout<<h[i].name<<h[i].age<<h[i].gender<<endl;
    }
}

int main() {
    Hero h[5]={
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"}
    };
    int len=sizeof(h)/sizeof(h[0]);
    bublleSort(h,len);
    print(h,len);

}