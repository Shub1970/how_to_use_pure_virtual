#include<iostream>
#include<string>
using namespace std;
class Employee{
    protected: 
     string name_;
    public:
     virtual void salaryprocessing()=0;
};
class Engineer:public Employee{
    public:
     Engineer(const string &name){name_=name;}
     void salaryprocessing(){cout<<name_<<" : process salary for Engineer"<<endl;}
};
class Manager:public Engineer{
    Engineer* reports[10];
    public:
     Manager(const string &name):Engineer(name){}
     void salaryprocessing(){cout<<name_<<" : process salary for Manager"<<endl;}
};
class Director:public Manager{
     Manager* reports[10];
    public:
     Director(const string &name): Manager(name){}
     void salaryprocessing(){cout<<name_<<" : process salary for Director"<<endl;}   
};
class SalesExecutive :public Employee{
    public:
    SalesExecutive(const string &name){name_=name;}
    void salaryprocessing(){cout<<name_<<" : process salary for SalesExecutive"<<endl;}
};
int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    std::ios::sync_with_stdio(false);
    //--------------------------------------------------------------------------//

    Engineer e1("Rohit"),e2("shuhbham"),e3("kavita"),e4("shambhu");
    Manager  m1("kamal"),m2("rajib");
    Director d1("ranjana"),d2("shivam");
    SalesExecutive s1("hari"),s2("bishnu");
    Employee *staff[]{&e1,&e2,&e3,&e4,&m1,&m2,&d1,&d2,&s1,&s2};
    for(int i{};i<sizeof(staff)/sizeof(Employee*);i++){
         staff[i]->salaryprocessing();
    }
return 0;
}