#include <iostream>
#include <string>
using namespace std;

struct Info
{
    int number;
    string name;
    string gender;
    int age;
    string phone_number;
};


void add(Info info[],int cnt, int number, string name, string gender, int age, string phone_number){
    Info information;
    information.number=number;
    information.name=name;
    information.gender=gender;
    information.age=age;
    information.phone_number=phone_number;
    info[cnt]=information;
}

void show(Info info[], int cnt){
    for(int i=0; i<cnt; i++) {
        cout<<info[i].number<<"\t"<<info[i].name<<"\t"<<info[i].gender<<"\t"<<info[i].age<<"\t"<<info[i].phone_number<<"\t"<<endl;
    }
}

int del(Info info[], int cnt, int number){
    if (number<=cnt){
        for(int i=number-1;i<cnt;i++) {
            info[i+1].number--;
            info[i]=info[i+1];
        }
        cout<<"删除成功！"<<endl;
        return 1;
    }
    else {
        cout<<"查无此人"<<endl;
        return 0;
    }
    
}

void find(Info info[], int cnt, int number){
    int isfind=0;
    if(number<=cnt){
        cout<<info[number-1].number<<"\t"<<info[number-1].name<<"\t"<<info[number-1].gender<<"\t"<<info[number-1].age<<"\t"<<info[number-1].phone_number<<"\t"<<endl;
        isfind=1;
    }
    // cout<<"查"<<endl;
    // for (int i=0; i<cnt; i++) {
    //     if(info[i].name==name){
    //         cout<<info[i].number<<"\t"<<info[i].name<<"\t"<<info[i].gender<<"\t"<<info[i].age<<"\t"<<info[i].phone_number<<"\t"<<endl;
    //         isfind=1;
    //     }
    // }
    if(!isfind) {
        cout<<"查无此人！"<<endl;
    }
}

void renew(Info info[], int cnt, int number){
    int isfind=0;
    if(number<=cnt){
        int choice;
        cout<<"修改联系人"<<endl;
        cout<<"1.修改名字"<<endl;
        cout<<"2.修改性别"<<endl;
        cout<<"3.修改年龄"<<endl;
        cout<<"4.修改电话"<<endl;
        cout<<"请输入选择：";
        cin>>choice;
        if (choice==1){
            string name;
            cout<<"请输入新名字：";
            cin>>name;
            info[number-1].name=name;
        }
        else if (choice==2){
            string gender;
            cout<<"请输入新性别：";
            cin>>gender;
            info[number-1].gender=gender;
        }
        else if (choice==3){
            int age;
            cout<<"请输入新年龄：";
            cin>>age;
            info[number-1].age=age;
        }
        else if (choice==4){
            string phone_number;
            cout<<"请输入新电话：";
            cin>>phone_number;
            info[number-1].phone_number=phone_number;
        }
        else{
            cout<<"不修改"<<endl;
        }
        cout<<info[number-1].number<<"\t"<<info[number-1].name<<"\t"<<info[number-1].gender<<"\t"<<info[number-1].age<<"\t"<<info[number-1].phone_number<<"\t"<<endl;
        isfind=1;
    }
    if(!isfind) {
        cout<<"查无此人！"<<endl;
    }
}

int main() {
    int choice;
    int len=1000;  //最大储存量
    Info info[len];
    int cnt_people=0; //统计登记的人数
    while(choice!=0){
        cout<<"通讯录管理系统"<<endl;
        cout<<"1.添加联系人"<<endl;
        cout<<"2.显示联系人"<<endl;
        cout<<"3.删除联系人"<<endl;
        cout<<"4.查找联系人"<<endl;
        cout<<"5.修改联系人"<<endl;
        cout<<"6.清空联系人"<<endl;
        cout<<"0.退出通讯录"<<endl;
        cout<<"请输入你的选择：";
        cin>>choice;
        if (choice==1){
            int number=cnt_people+1;
            string name;
            string gender;
            int age;
            string phone_number;
            cout<<"请输入姓名：";
            cin>>name;
            cout<<"请输入性别：";
            cin>>gender;
            cout<<"请输入年龄：";
            cin>>age;
            cout<<"请输入电话：";
            cin>>phone_number;
            add(info,cnt_people,number,name,gender,age,phone_number);
            cnt_people++;
            cout<<"总人数为："<<cnt_people<<endl;
        }
        else if(choice==2){
            show(info,cnt_people);
        }
        else if(choice==3){
            int number;
            cout<<"请输入要删除的人员编号：";
            cin>>number;
            int r=del(info,cnt_people,number);
            if(r){
                cnt_people--;
            }
        }
        else if(choice==4){
            int number;
            cout<<"请输入要查找的人员编号：";  //string名字作为参数要崩溃？
            cin>>number;
            find(info,cnt_people,number);
        }
        else if(choice==5){
            int number;
            cout<<"请输入要修改的人员编号："; 
            cin>>number;
            renew(info,cnt_people,number);
        }
        else if(choice==6){
            char c;
            cout<<"您确认要清空所有联系人吗？（Y/N)"; 
            cin>>c;
            if (c=='Y'){
                // while(cnt_people>0){
                //     del(info,cnt_people,1);
                //     cnt_people--;
                // }
                cnt_people=0;
                cout<<"已清空"<<endl;
            }
        }
    }
}