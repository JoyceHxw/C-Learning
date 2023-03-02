#include <iostream>
using namespace std;
#include <ctime>

struct Student
{
    string name;
    int score;
};

struct Teacher
{
    string name;
    Student stuArray[5];
};

void allocateSpace(Teacher teaArray[], int len){
    string namelist="ABCDE";
    for (int i=0;i<len;i++){
        teaArray[i].name="Teacher_";
        teaArray[i].name+=namelist[i];
        for (int j=0;j<5;j++){
            teaArray[i].stuArray[j].name="Student_";
            teaArray[i].stuArray[j].name+=namelist[j];

            int random=rand()%61+40; //0-60的随机数+40
            teaArray[i].stuArray[j].score=random;
        }
    }
}

void printInfo(Teacher teaArray[],int len){
    for (int i=0;i<len;i++){
        cout<<teaArray[i].name;
        for (int j=0;j<5;j++){
            cout<<teaArray[i].stuArray[j].name<<teaArray[i].stuArray[j].score<<endl;
        }
    }
}

int main() {

    // 随机数种子
    srand((unsigned int)time(NULL));

    Teacher teaArray[3];
    int len=sizeof(teaArray)/sizeof(teaArray[0]);
    allocateSpace(teaArray,len);
    printInfo(teaArray,len);
}