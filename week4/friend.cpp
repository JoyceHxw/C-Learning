#include <iostream>
using namespace std;

class Building
{
    //goodFriend全局函数是Building好朋友，可以访问Building中私有成员
    friend void goodFriend(Building *building);
    // GoodFriend类是本类的好朋友，可以访问本类
    friend class GoodFriend;
    // GoodFriend下的visit成员函数作为本类的好朋友，可以访问私有成员
    // friend void GoodFriend::visit2();
public:
    string m_SittingRoom;

    Building(){
        m_SittingRoom="客厅";
        m_BedRoom="卧室";
    }

private:
    string m_BedRoom;

};

// 类做友元
class GoodFriend
{
public:
    Building * building;

    GoodFriend(){
        building=new Building;
    }

    void visit(){
        cout<<"好朋友访问"<<building->m_SittingRoom<<endl;
        cout<<"好朋友访问"<<building->m_BedRoom<<endl;
    }

    // void visit2(){
    //     cout<<"好朋友访问"<<building->m_SittingRoom<<endl;
    //     cout<<"好朋友访问"<<building->m_BedRoom<<endl;
    // }
};

// 全局函数做友元
void goodFriend(Building *building){
    cout<<"好朋友访问"<<building->m_SittingRoom<<endl;
    cout<<"好朋友访问"<<building->m_BedRoom<<endl;
}



void test(){
    Building building;
    goodFriend(&building);
}

void test2(){
    GoodFriend gf;
    gf.visit();
    // gf.visit2();
}

int main(){
    // test();
    test2();
}