#include <iostream>

using namespace std;

class Poss{
    public:
    int a;

    void getdata(){
        cout<<"Enter a number : ";
        cin>>a;
    }
    void checknum(){
        if(a=0){
            cout<<a<<" is Zero !";
        }
        else if(a<0){
            cout<<a<<" is a Positive number !";
        }
        else{
            cout<<a<<" is a Negative number !";
        }
    }
};

int main(){
    Poss obj;

    obj.getdata();
    obj.checknum();

    return 0;
}