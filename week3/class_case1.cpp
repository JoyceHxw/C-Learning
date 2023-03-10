#include <iostream>
using namespace std;

class Cube
{
private:
    int l;
    int w;
    int h;

public:
    void setL(int a){
        l=a;
    }
    int getL(){
        return l;
    }
    void setW(int b){
        w=b;
    }
    int getW(){
        return w;
    }
    void setH(int c){
        h=c;
    }
    int getH(){
        return h;
    }

    int getSize(){
        return 2*(l*w+l*h+w*h);
    }
    int getVolume(){
        return l*w*h;
    }
    bool isSame(Cube &c2){
        if (l==c2.getL() && w==c2.getW() && h==c2.getH()){
            return true;
        }
        else{
            return false;
        }
    }
    
};



int main(){
    Cube c1;
    Cube c2;

    c1.setL(5);
    c1.setW(2);
    c1.setH(3);

    c2.setL(2);
    c2.setW(3);
    c2.setH(3);

    cout<<c1.getL()<<endl;

    cout<<"c1的面积为"<<c1.getSize()<<endl;
    cout<<"c1的体积为"<<c1.getVolume()<<endl;

    cout<<"c2的面积为"<<c2.getSize()<<endl;
    cout<<"c2的体积为"<<c2.getVolume()<<endl;

    cout<<c1.isSame(c2);
}