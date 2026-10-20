#include <iostream>

using namespace std;

class FindLargest{

    public:
    int a,b;

    void getdata(){
        cout<<"Enter first number : ";
        cin>> a ;
        cout<<"Enter second number : ";
        cin>> b ;
    }

    void findlargest(){
    if(a>b){
        cout<<a<<"is the largest number\n";
    }
    else{
        cout<<b<<"is the largest number\n";
      }
    }

};

int main(){
    FindLargest obj;

    obj.getdata();
    obj.findlargest();

    return 0;
}