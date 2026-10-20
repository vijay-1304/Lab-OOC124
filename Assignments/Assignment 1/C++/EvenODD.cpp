#include <iostream>

using namespace std;

class EvenOdd{
    public:
    int a;
     
    void getdata(){
        cout<<"Enter a number : ";
        cin>> a;
    }

    void execute(){
        if(a % 2 == 0){
            cout<<a<<" is Even number\n";
        }
        else{
            cout<<a<<" is odd number\n";
        }
    }
};

int main(){
    EvenOdd obj;

    obj.getdata();
    obj.execute();

    return 0;
}