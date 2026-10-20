#include <iostream>

using namespace std;

class Factorial{
    public:
    int a , i;
    int fact = 1;

    void getdata(){
        cout<<"Enter a number : ";
        cin>>a;
    }

    void findFactorial(){
        for(i=1; i<=a; i++){
            fact = fact * i;
        }

        cout<<"Factorial of given number is :"<<fact;
    }
};

int main(){
    Factorial obj;

    obj.getdata();
    obj.findFactorial();

    return 0;
}