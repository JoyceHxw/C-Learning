#include <iostream>
using namespace std;
#include <map>

void printMap(map<int,int>&m){
    for(map<int,int>::iterator it=m.begin(); it!=m.end(); it++){
        cout<<"key="<<(*it).first<<" value="<<(*it).second<<endl;
    }
}
// map构造和赋值
// 不允许有重复的key
void test1(){
    map<int,int>m;
    // 按照key排序
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    printMap(m);

    map<int,int>m2(m);
    printMap(m2);

    map<int,int>m3;
    m3=m2;
    printMap(m3);
}

// map大小和交换
void test2(){
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    
    cout<<m1.empty()<<endl;
    cout<<m1.size()<<endl;

    map<int,int>m2;
    m2.insert(pair<int,int>(1,100));
    m2.insert(pair<int,int>(2,200));
    m2.insert(pair<int,int>(3,300));

    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

// map插入和删除
void test3(){
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(make_pair(2,20));  //不用写模板参数
    m1.insert(map<int,int>::value_type(3,30));
    m1[4]=40;
    printMap(m1);
    // 不存在则自动创建值
    cout<<m1[5]<<endl;

    m1.erase(m1.begin());
    printMap(m1);

    m1.erase(3);  //按照key删除
    printMap(m1);

    m1.clear();
}

// map查找和统计
void test4(){
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    map<int,int>::iterator pos=m1.find(3);
    if(pos!=m1.end()){
        cout<<(*pos).first<<" "<<(*pos).second<<endl;
    }
    else{
        cout<<"未找到"<<endl;
    }

    cout<<m1.count(3)<<endl;

    cout<<m1[1]<<endl;
}

// map排序
class MyCompare
{
public:
    bool operator()(int v1, int v2){
        return v1>v2;
    }
};

void test5(){
    map<int,int, MyCompare>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    for(map<int,int,MyCompare>::iterator it=m1.begin(); it!=m1.end(); it++){
        cout<<"key="<<(*it).first<<" value="<<(*it).second<<endl;
    }
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
}