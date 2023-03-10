#include <iostream>
#include <math.h>
using namespace std;

#include "point.h"
#include "circle.h"

// class Point
// {
// private:
//     int x;
//     int y;
// public:
//     void setX(int a){
//         x=a;
//     }
//     int getX(){
//         return x;
//     }
//     void setY(int a){
//         y=a;
//     }
//     int getY(){
//         return y;
//     }
// };

// class Circle
// {
// private:
//     int r;
//     Point p;
// public:
//     void setR(int a){
//         r=a;
//     }
//     int getR(){
//         return r;
//     }
//     void setP(Point p1){
//         p=p1;
//     }
//     Point getP(){
//         return p;
//     }
// };

void CirclePoint(Circle c, Point p){
    double distance= pow(pow(c.getP().getX()-p.getX(),2)+pow(c.getP().getY()-p.getY(),2),0.5);
    if (distance>c.getR()){
        cout<<"out"<<endl;
    }
    else if (distance==c.getR()){
        cout<<"on"<<endl;
    }
    else if (distance<c.getR()){
        cout<<"in"<<endl;
    }
}

int main(){
    Point p1;
    p1.setX(2);
    p1.setY(4);

    Point center;
    center.setX(1);
    center.setY(1);

    Circle c;
    c.setR(1);
    c.setP(center);

    CirclePoint(c,p1);
}