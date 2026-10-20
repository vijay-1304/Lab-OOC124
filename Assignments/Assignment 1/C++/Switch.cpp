#include <iostream>

using namespace std;

class Switch{

    public:
    int a,b,add,sub,mul,div,mod,choice;

    void getdata(){
        cout<<"Enter first number :";
        cin>>a;
        cout<<"Enter second number :";
        cin>>b;
    }
    void perform(){
        cout<<"Which action you want to perform : \n1. Addition \n2. Substraction \n3. Multiplication \n4. Division \n5. Mod of two Numbers\n";
        cin>>choice;

        switch(choice){
            case 1:
            add = a+b;
            cout<<"Addition of given numbers is : "<<add;
            break;

            case 2:
            sub = a-b;
            cout<<"Substraction of given numbers is : "<<sub;
            break;

            case 3:
            mul = a*b;
            cout<<"Multiplication of given numbers is : "<<mul;
            break;

            case 4:
            div = a/b;
            cout<<"Division of given numbers is : "<<div;
            break;

            case 5:
            mod = a % b;
            cout<<"Mod of two numbers is : "<<mod;
            break;

            default:
            cout<<"Please Re-consider your choice !!!";
        }
    }
};

int main(){
    Switch obj;

    obj.getdata();
    obj.perform();

    return 0;
}