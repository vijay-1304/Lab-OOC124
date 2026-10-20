#include <iostream>

using namespace std;

class Add{
    public:
    int a,b,sum;

    void getdata(){
        cout<<"Enter first number : ";
        cin>>a;
        cout<<"Enter Second number : ";
        cin>>b;
    }

    void addition(){
        sum = a+b;
        cout<<"Addition is "<<sum;
    }

};

int main(){
    Add a;
    a.getdata();
    a.addition();

    return 0;
}