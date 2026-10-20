#include <iostream>

using namespace std;

class Natural{
    public:
    int a,i=1;

    void getdata(){
        cout<<"Enter a number :";
        cin>>a;
    }

    void naturalnumbers(){

        while(i<=a){
            cout<<i<<endl;
            i++;
        }
    }
};

int main(){
    Natural obj;

    obj.getdata();
    obj.naturalnumbers();
    
    return 0;
}