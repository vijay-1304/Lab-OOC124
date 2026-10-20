#include <iostream>

using namespace std;

class Factorial{
    public:
    int n,i;
    long long fact = 1;

    void getdata(){
        cout<<"Enter a number :";
        cin>>n;
    }
    
    void findfact(){

        for(i=2; i<=n; i+=2){
            fact = fact * i;
        }
    
        cout<<"Factorial of given number is : "<<fact;
    }
};

int main(){
    Factorial obj;

    obj.getdata();
    obj.findfact();

    return 0;
}