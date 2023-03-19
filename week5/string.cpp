#include <iostream>
using namespace std;


// string 的构造函数
void test1(){
    // 1.默认构造
    string s1;
    // 2.使用字符串s初始化
    const char* str="helloword";
    string s2(str);
    // 3.拷贝构造
    string s3(s2);
    // 4.使用n个字符c初始化
    string s4(10,'f');
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
}

// string赋值操作
void test2(){
    string str1;
    str1="hello";
    cout<<str1<<endl;

    string str2;
    str2=str1;
    cout<<str2<<endl;

    string str3;
    str3='a';
    cout<<str3<<endl;

    string str4;
    str4.assign("C++");
    cout<<str4<<endl;

    string str5;
    str5.assign("C++",2);  //前几个字符
    cout<<str5<<endl;

    string str6;
    str6.assign(str5);
    cout<<str5<<endl;

    string str7;
    str7.assign(10,'d');
    cout<<str7<<endl;
}

// 字符串拼接
void test3(){
    string str1="我";
    str1+="爱写代码";
    cout<<str1<<endl;    

    str1+=':';
    cout<<str1<<endl;

    string str2="C++";
    str1+=str2;
    cout<<str1<<endl;

    string str3="I ";
    str3.append("love ");
    cout<<str3<<endl;

    str3.append("programming",7);
    cout<<str3<<endl;

    str3.append(str2);
    cout<<str3<<endl;

    str3.append(str2,0,1);  //截取
    cout<<str3<<endl;
}

// string查找和替换
void test4(){
    string str1="abcdefg";
    int pos=str1.find("de");  //没有返回-1
    cout<<pos<<endl;

    int pos2=str1.rfind("c");  // 从右往左查找
    cout<<pos2<<endl;

    str1.replace(1,3,"1111");  //从1号位置起，3个字符替换为1111
    cout<<str1<<endl;
}

// 字符串比较
void test5(){
    string str1="hellp";
    string str2="hello";
    cout<<str1.compare(str2)<<endl;  
    // 0表示相等,1表示第一个大，-1表示第一个小

}

// 字符存取
void test6(){
    string str="hello";
    // 1.通过[]访问单个字符
    for(int i=0; i<str.size(); i++){
        cout<<str[i]<<endl;
    }
    // 2.通过at方式
    for(int i=0; i<str.size(); i++){
        cout<<str.at(i)<<endl;
    }

    str[0]='s';
    cout<<str<<endl;
}

// string插入和删除
void test7(){
    string str="hello";
    str.insert(1,"111");
    cout<<str<<endl;

    str.erase(1,3);
    cout<<str<<endl;
}

// string字串
void test8(){
    string str="abcdef";
    string subStr=str.substr(1,4);
    cout<<subStr<<endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}