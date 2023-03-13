#include <iostream>
using namespace std;

// 多态好处:
// 1.组织结构清晰
// 2.可读性强
// 3.对于前期和后期扩展及维护性高
class Calculator
{
public:
    int m_num1;
    int m_num2;
    virtual int getResult(){
        return 0;
    }
};

class CalculatorAdd: public Calculator
{
public:
    int getResult(){
        return m_num1+m_num2;
    }
};

class CalculatorMinus: public Calculator
{
public:
    int getResult(){
        return m_num1-m_num2;
    }
};

class CalculatorMultiple: public Calculator
{
public:
    int getResult(){
        return m_num1*m_num2;
    }
};

void test(){
    Calculator cal;
    cal.m_num1=10;
    cal.m_num2=20;

    // cout<<cal.m_num1<<"+"<<cal.m_num2<<"="<<cal.getResult("+")<<endl;
}

void test2(){
    Calculator *cal=new CalculatorAdd;
    cal->m_num1=102;
    cal->m_num2=38;
    cout<<cal->m_num1<<"+"<<cal->m_num2<<"="<<cal->getResult()<<endl;
    delete cal;

    cal=new CalculatorMinus;
    cal->m_num1=102;
    cal->m_num2=38;
    cout<<cal->m_num1<<"-"<<cal->m_num2<<"="<<cal->getResult()<<endl;
    delete cal;

    cal=new CalculatorMultiple;
    cal->m_num1=102;
    cal->m_num2=38;
    cout<<cal->m_num1<<"*"<<cal->m_num2<<"="<<cal->getResult()<<endl;
    delete cal;
}

int main(){
    // test();
    test2();
}