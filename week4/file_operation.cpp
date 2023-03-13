#include <iostream>
using namespace std;
#include <fstream> //头文件包含

// 写文件
void test(){
    //1.包含头文件 fstream
    // 2.创建流对象
    ofstream ofs;
    // 3.指定打开方式
    ofs.open("test.txt", ios::out);
    // 4.写内容
    ofs<<"姓名: 张三"<<endl;
    ofs<<"性别: 男"<<endl;
    ofs<<"年龄: 18"<<endl;
    // 5.关闭文件
    ofs.close();
}

// 读文件
void test2(){
    // 1.包含头文件
    // 2.创建流对象
    ifstream ifs;
    // 3.打开文件
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    // 4.读数据
    // 法一:
    // char buf[1024]={0};
    // while(ifs>>buf){
    //     cout<<buf<<endl;
    // }
    // // 法二:
    // char buf[1024]={0};
    // while(ifs.getline(buf,sizeof(buf))){
    //     cout<<buf<<endl;
    // }
    // 法三:
    string buf;
    while(getline(ifs,buf)){
        cout<<buf<<endl;
    }
    // 法四:
    // char c;
    // while((c=ifs.get()) !=EOF){ //EOF end of file
    //     cout<<c;
    // }
    // 5.关闭文件
    ifs.close();
}

int main(){
    test();
    test2();
}
