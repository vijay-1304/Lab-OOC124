#include <iostream>

using namespace std;

class Swap{
    public:
    int a,b,temp;

    void getdata(){
        cout<<"Enter First Number :";
        cin>>a;
        cout<<"Enter Second number:";
        cin>>b;
    }
    void swapnu(){

        cout << "A is "<<a<<"& b is"<<b;
        temp = a;
        a = b;
        b = temp;
 
        cout<<"\n New A is "<<a<<" & new B is "<<b;
    }
};

int main(){
    Swap obj;

    obj.getdata();
    obj.swapnu();

    return 0;
}