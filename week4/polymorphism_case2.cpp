#include <iostream>
using namespace std;

// 零件
class CPU
{
public:
    virtual void calculate()=0;
};

class VC
{
public:
    virtual void display()=0;
};

class Memory
{
public:
    virtual void store()=0;
};


// 电脑
class Computer
{
public:
    Computer(CPU *cpu, VC *vc, Memory *mem){
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
    void work(){
        m_cpu->calculate();
        m_vc->display();
        m_mem->store();
    }
    ~Computer(){
        if(m_cpu!=NULL){
            delete m_cpu;
            m_cpu=NULL;
        }
        if(m_vc!=NULL){
            delete m_vc;
            m_vc=NULL;
        }
        if(m_mem!=NULL){
            delete m_mem;
            m_mem=NULL;
        }
    }
private:
    CPU *m_cpu;
    VC *m_vc;
    Memory *m_mem;
};


// 厂商
class IntelCPU: public CPU
{
public:
    virtual void calculate(){
        cout<<"Intel CPU开始计算"<<endl;
    }
};

class IntelVC: public VC
{
public:
    virtual void display(){
        cout<<"Intel 显卡开始显示"<<endl;
    }
};

class IntelMem: public Memory
{
public:
    virtual void store(){
        cout<<"Intel 内存开始存储"<<endl;
    }
};


class LenovoCPU: public CPU
{
public:
    virtual void calculate(){
        cout<<"Lenovo CPU开始计算"<<endl;
    }
};

class LenovoVC: public VC
{
public:
    virtual void display(){
        cout<<"Lenovo 显卡开始显示"<<endl;
    }
};

class LenovoMem: public Memory
{
public:
    virtual void store(){
        cout<<"Lenovo 内存开始存储"<<endl;
    }
};


void test(){
    // 第一台电脑零件
    CPU * intelcpu=new IntelCPU;
    VC * intelvc=new IntelVC;
    Memory * intelmem=new IntelMem;

    Computer * computer1=new Computer(intelcpu, intelvc, intelmem);
    computer1->work();
    delete computer1;

    Computer * computer2=new Computer(new LenovoCPU, new LenovoVC, new LenovoMem);
    computer2->work();
    delete computer2;

    Computer * computer3=new Computer(new IntelCPU, new LenovoVC, new LenovoMem);
    computer3->work();
    delete computer3;
}


int main(){
    test();
}