#include <iostream>
#include <string>

using namespace std;
 
class Student{
    private:
    int rollno;
    string name;
    float marks;
    
    public:
    void inputdetails(){
        cout<<"Enter student name : ";
        getline(cin>>ws,name);
        cout<<"Enter roll no : ";
        cin>>rollno;
        cout<<"Enter marks : ";
        cin>>marks;
    }

    void DisplayDetails(){
        cout<<"---\nStudent Details :---\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Rollno : "<<rollno<<endl;
        cout<<"Marks : "<<marks<<endl;
    }

};

int main(){
Student s;
s.inputdetails();
s.DisplayDetails();
return 0;
}

