#include <iostream>
using namespace std;
#include <fstream>


class Employee
{
public:
    int m_id;
    string m_name;
    string m_title;
    string m_job;

    // virtual void setJob()=0;
};

class Worker: public Employee
{
public:
    Worker(int id, string name){
        this->m_id=id;
        this->m_name=name;
        setJob();
    }
    void setJob(){
        this->m_title="员工";
        this->m_job="完成经理交给的任务";
    }
};

class Manager: public Employee
{
public:
    Manager(int id, string name){
        this->m_id=id;
        this->m_name=name;
        setJob();
    }
    void setJob(){
        this->m_title="经理";
        this->m_job="完成老板交给的任务，并下发任务给员工";
    }
};

class CEO: public Employee
{
public:
    CEO(int id, string name){
        this->m_id=id;
        this->m_name=name;
        setJob();
    }
    void setJob(){
        this->m_title="总裁";
        this->m_job="管理公司所有事务";
    }
};


void addEmployee(Employee *employee_list, int number){
    int id;
    string name;
    int choice;
    cout<<"请输入职工编号：";
    cin>>id;
    cout<<"请输入职工姓名：";
    cin>>name;
    cout<<"请选择岗位："<<endl;
    cout<<"1.员工"<<endl<<"2.经理"<<endl<<"3.总裁"<<endl;
    while(true){
        cin>>choice;
        if(choice==1){
            employee_list[number]=Worker(id,name);
            break;
        }
        else if(choice==2){
            employee_list[number]=Manager(id,name);
            break;
        }
        else if(choice==3){
            employee_list[number]=CEO(id,name);
            break;
        }
        else{
            cout<<"输入错误，请重新输入：";
        }
    }
}

void showEmployee(Employee *employee_list, int number){
    for(int i=0; i<number; i++){
        cout<<employee_list[i].m_id<<'\t'<<employee_list[i].m_name<<'\t'<<employee_list[i].m_title<<'\t'<<employee_list[i].m_job<<'\t'<<endl;
    }
}

bool deleteEmployee(Employee *employee_list,int number){
    int id;
    cout<<"请输入要删除的职工编号：";
    cin>>id;
    bool isFind=false;
    for(int i=0; i<number; i++){
        if(employee_list[i].m_id==id){
            isFind=true;
            for (int j=i; j<number; j++){
                employee_list[j]=employee_list[j+1];
            }
            break;
        }
    }
    if (isFind==false){
        cout<<"查无此人！"<<endl;
        return false;
    }
    else{
        cout<<"删除成功"<<endl;
        return true;
    }
}

void renewEmployee(Employee * employee_list, int number){
    int id;
    cout<<"请输入要修改的职工编号：";
    cin>>id;
    bool isFind=false;
    for(int i=0; i<number; i++){
        if(employee_list[i].m_id==id){
            isFind=true;
            int choice;
            cout<<"请输入要修改的信息："<<endl;
            cout<<"1.编号"<<endl<<"2.姓名"<<endl<<"3.岗位"<<endl;
            while(true){
                cin>>choice;
                if(choice==1){
                    int new_id;
                    cout<<"请输入新的编号：";
                    cin>>new_id;
                    employee_list[i].m_id=new_id;
                    break;
                }
                else if(choice==2){
                    string new_name;
                    cout<<"请输入新的名字：";
                    cin>>new_name;
                    employee_list[i].m_name=new_name;
                    break;
                }
                else if(choice==3){
                    int choice1;
                    cout<<"请选择岗位："<<endl;
                    cout<<"1.员工"<<endl<<"2.经理"<<endl<<"3.总裁"<<endl;
                    while(true){
                        cin>>choice1;
                        if(choice1==1){
                            employee_list[i]=Worker(employee_list[i].m_id,employee_list[i].m_name);
                            break;
                        }
                        else if(choice1==2){
                            employee_list[i]=Manager(employee_list[i].m_id,employee_list[i].m_name);
                            break;
                        }
                        else if(choice1==3){
                            employee_list[i]=CEO(employee_list[i].m_id,employee_list[i].m_name);
                            break;
                        }
                        else{
                            cout<<"输入错误，请重新输入：";
                        }
                    }
                    break;
                }
                else{
                    cout<<"输入错误，请重新输入：";
                }
            }
            break;
        }
    }
    if (isFind==false){
        cout<<"查无此人！"<<endl;
    }
    else{
        cout<<"修改成功"<<endl;
    }
}

void findEmployee(Employee *employee_list, int number){
    int choice;
    cout<<"请选择查找方式："<<endl;
    cout<<"1.通过编号查找"<<endl<<"2.通过姓名查找"<<endl;
    while(true){
        cin>>choice;
        if(choice==1){
            bool isFind=false;
            int find_id;
            cout<<"请输入编号：";
            cin>>find_id;
            for(int i=0; i<number; i++){
                if(find_id==employee_list[i].m_id){
                    isFind=true;
                    cout<<"查找成功"<<endl;
                    cout<<employee_list[i].m_id<<'\t'<<employee_list[i].m_name<<'\t'<<employee_list[i].m_title<<'\t'<<employee_list[i].m_job<<'\t'<<endl;
                    break;
                }
            }
            if (isFind==false){
                cout<<"查无此人！"<<endl;
            }
            break;
        }
        else if(choice==2){
            bool isFind=false;
            string find_name;
            cout<<"请输入姓名：";
            cin>>find_name;
            for(int i=0; i<number; i++){
                if(find_name==employee_list[i].m_name){
                    isFind=true;
                    cout<<"查找成功"<<endl;
                    cout<<employee_list[i].m_id<<'\t'<<employee_list[i].m_name<<'\t'<<employee_list[i].m_title<<'\t'<<employee_list[i].m_job<<'\t'<<endl;
                    break;
                }
            }
            if (isFind==false){
                cout<<"查无此人！"<<endl;
            }
            break;
        }
        else{
            cout<<"输入错误，请重新输入：";
        }
    }
    
}

void sortEmployee(Employee * employee_list, int number){
    int choice;
    cout<<"请选择顺序："<<endl;
    cout<<"1.升序"<<endl<<"2.降序"<<endl;
    cin>>choice;
    while(true){
        if(choice==1){
            for(int i=0; i<number-1;i++){
                for(int j=0;j<number-i-1;j++)
                {
                    if (employee_list[j].m_id>employee_list[j+1].m_id)
                    {
                        Employee temp=employee_list[j];
                        employee_list[j]=employee_list[j+1];
                        employee_list[j+1]=temp;
                    }
                }
            }
            break;
        }
        else if(choice==2){
            for(int i=0; i<number-1;i++){
                for(int j=0;j<number-i-1;j++)
                {
                    if (employee_list[j].m_id<employee_list[j+1].m_id)
                    {
                        Employee temp=employee_list[j];
                        employee_list[j]=employee_list[j+1];
                        employee_list[j+1]=temp;
                    }
                }
            }
            break;
        }
        else{
            cout<<"输入错误，请重新输入：";
        }
    }
    for (int i=0; i<number; i++){
        cout<<employee_list[i].m_id<<'\t'<<employee_list[i].m_name<<'\t'<<employee_list[i].m_title<<'\t'<<employee_list[i].m_job<<'\t'<<endl;
    }
}

void write_file(Employee *employee_list, int number){
    ofstream ofs;
    ofs.open("Employee_Information.txt", ios::out);
    for (int i=0; i<number; i++){
        ofs<<"编号："<<employee_list[i].m_id<<'\t'<<"姓名："<<employee_list[i].m_name<<'\t'<<"岗位："<<employee_list[i].m_title<<'\t'<<"岗位职责："<<employee_list[i].m_job<<'\t'<<endl;
    }
    ofs.close();
}

void clear_file(){
    ofstream ofs;
    ofs.open("Employee_Information.txt", ios::out);
    ofs.close();
}

//改进：释放空间delete[]；从文件中读取数据
int main(){
    int choice;
    int number=0;
    Employee *employee_list=new Employee[1000];   
    while(true){
        cout<<"职工管理系统"<<endl;
        cout<<"0.退出管理系统"<<endl;
        cout<<"1.增加职工信息"<<endl;
        cout<<"2.显示职工信息"<<endl;
        cout<<"3.删除离职职工"<<endl;
        cout<<"4.修改职工信息"<<endl;
        cout<<"5.查找职工信息"<<endl;
        cout<<"6.按照编号排序"<<endl;
        cout<<"7.清空所有文档"<<endl;
        cout<<"请输入您的选择：";
        cin>>choice;
        if (choice==0){
            cout<<"退出系统！"<<endl;
            break;
        }
        else if(choice==1){
            addEmployee(employee_list,number);
            number++;
            write_file(employee_list,number);
        }
        else if (choice==2){
            showEmployee(employee_list,number);
        }
        else if(choice==3){
            bool isDelete=deleteEmployee(employee_list,number);
            if (isDelete){
                number--;
            }
            write_file(employee_list,number);
        }
        else if(choice==4){
            renewEmployee(employee_list,number);
            write_file(employee_list,number);
        }
        else if(choice==5){
            findEmployee(employee_list,number);
        }
        else if(choice==6){
            sortEmployee(employee_list,number);
            write_file(employee_list,number);
        }
        else if(choice==7){
            number=0;
            clear_file();
        }
        else{
            cout<<"输入错误，请重新输入：";
        }
        
    }
}