#include <iostream>

using namespace std;

class SwapT{
    
    public:
    int a,b;

    void getdata(){
        cout<<"Enter First number :";
        cin>>a;
        cout<<"Enter Second number :";
        cin>>b;
    }
    
    void SwapNumber(){
        cout<<"Numbers before swapping A : "<<a<<" and B : "<<b<<endl;

        a = a+b;
        b = a-b;
        a = a-b;

        cout<<"Numbers after swapping A : "<<a<<" and B : "<<b<<endl;
    }
};

int main(){
    SwapT obj;

    obj.getdata();
    obj.SwapNumber();

    return 0;
}