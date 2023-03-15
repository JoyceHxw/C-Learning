// 给定一个主串S和子串P，使用KMP算法查找子串P在主串S中存在的位置，若子串P在主串S中存在，则输出与子串P中第一字符相等的字符在主串S中的序号；若不存在则输出“no”
#include <iostream>
using namespace std;

int * nextBuild(string p){
    int i=1;
    int j=0;
    int len_p=p.length();
    int *next=new int[len_p];
    next[0]=-1;
    next[1]=0;
    while(i<len_p){
        if(j==-1 || p[i]==p[j]){
            j++;
            i++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
    // for(int i=0; i<len_p; i++){
    //     cout<<next[i];
    // }
    return next;
}

void KPM(string s, string p){
    int * next=nextBuild(p);
    int i=0;
    int j=0;
    int len_s=s.length();
    int len_p=p.length();
    while (j<len_p && i<len_s){
        if(j==-1 || s[i]==p[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j<len_p-1){
        cout<<"no";
    }
    else{
        cout<<(i-len_p);
    }
}

int main(){
    string s;
    string p;
    cin>>s>>p;
    int len_s=s.length();
    int len_p=p.length();
    KPM(s,p);
}