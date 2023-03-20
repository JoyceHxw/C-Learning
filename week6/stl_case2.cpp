#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <map>

#define Operation 0
#define Decoration 1
#define Research 2

class Worker
{
public:
    string m_name;
    int m_salary;
};

void createWorker(vector<Worker>& v){
    for(int i=0; i<10; i++){
        string nameSeed="ABCDEFGHIJ";
        Worker worker;
        worker.m_name="员工";
        worker.m_name+=nameSeed[i];
        worker.m_salary=rand() % 10001+10000;
        v.push_back(worker);
    }
}

void setGroup(vector<Worker>& v, multimap<int,Worker>& m){
    for(vector<Worker>::iterator it=v.begin(); it!=v.end(); it++){
        int deptId=rand()%3;
        m.insert(make_pair(deptId,*it));
    }
}

void showWorkerByGroup(multimap<int,Worker>& m){
    cout<<"Operation"<<endl;
    multimap<int,Worker>::iterator pos=m.find(Operation);
    int index=0;
    for(;pos!=m.end() && index<m.count(Operation); pos++, index++){
        cout<<pos->second.m_name<<" "<<pos->second.m_salary<<endl;
    }

    cout<<"Decoration"<<endl;
    multimap<int,Worker>::iterator pos1=m.find(Decoration);
    int index1=0;
    for(;pos1!=m.end() && index1<m.count(Decoration); pos1++, index1++){
        cout<<pos1->second.m_name<<" "<<pos1->second.m_salary<<endl;
    }

    cout<<"Research"<<endl;
    multimap<int,Worker>::iterator pos2=m.find(Research);
    int index2=0;
    for(;pos2!=m.end() && index2<m.count(Research); pos2++, index2++){
        cout<<pos2->second.m_name<<" "<<pos2->second.m_salary<<endl;
    }
}

int main(){
    srand((unsigned int) time(NULL));
    vector<Worker>v;
    createWorker(v);
    for(vector<Worker>::iterator it=v.begin(); it!=v.end(); it++){
        cout<<it->m_name<<" "<<it->m_salary<<endl;
    }

    multimap<int,Worker>m;
    setGroup(v,m);

    showWorkerByGroup(m);
}