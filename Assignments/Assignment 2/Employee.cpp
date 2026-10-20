#include <iostream>
#include <string>

using namespace std;
 
class Employee{
    private:
    int empid, salary;
    string name;
    
    public:
    void inputdetails(){
        cout<<"Enter Employee name : ";
        getline(cin>>ws,name);
        cout<<"Enter Employee id no : ";
        cin>>empid;
        cout<<"Enter salary : ";
        cin>>salary;
    }

    void DisplayDetails(){
        cout<<"---\nEmployee Details :---\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Employee id : "<<empid<<endl;
        cout<<"Salary : "<<salary<<endl;
    }

};

int main(){
Employee obj;
obj.inputdetails();
obj.DisplayDetails();
return 0;
}

