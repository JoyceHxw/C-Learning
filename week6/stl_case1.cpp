#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class Person
{
public:
    string m_name;
    int m_score;

    Person(string name, int score){
        m_name=name;
        m_score=score;
    }
};


void score(vector<Person>& v){
    for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
        deque<int>d;
        for(int i=0; i<10; i++){
            int score=rand()%41+60;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();

        for(deque<int>::iterator it=d.begin(); it!=d.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;

        int s=0;
        for(deque<int>::iterator it=d.begin(); it!=d.end(); it++){
            s+=*it;
        }
        int avg=s/d.size();

        it->m_score=avg;
    }
}

int main(){
    srand((unsigned  int) time (NULL));

    vector<Person>v;

    string nameSeed="ABCDE";
    for(int i=0; i<5; i++){
        string name="选手";
        name+=nameSeed[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }

    // for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
    //     cout<<(*it).m_name<<" "<<(*it).m_score<<endl;
    // }

    score(v);

    for(vector<Person>::iterator it=v.begin(); it!=v.end(); it++){
        cout<<(*it).m_name<<" "<<(*it).m_score<<endl;
    }


}