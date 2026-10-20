#include <iostream>

using namespace std;

class FindLargest{

    public:
    int a,b,c;

    void getdata(){
        cout<<"Enter first number : ";
        cin>> a ;
        cout<<"Enter second number : ";
        cin>> b ;
        cout<<"Enter third number : ";
        cin>> c ;
    }

    void findlargest(){
    if(a>b && a>c){
        cout<<a<<"is the largest number\n";
    }
    else if(b>a && b>c){
        cout<<b<<"is the largest number\n";
      }
      else{
        cout<<c<<" is the largest number\n";
      } 
    }
};

int main(){
    FindLargest obj;

    obj.getdata();
    obj.findlargest();

    return 0;
}