#include <iostream>

using namespace std;

class Area{
    public:
    int r , d ; 
    float area , circum , pie = 3.14;

    void getdata(){
        cout<<"Enter raduis of a circle :";
        cin>>r;
        cout<<"Enter Diameter of a circle : ";
        cin>>d;
    }

    void action(){
        area = pie * r * r;
        circum = pie * d;

        cout<<"Area of a circle is : "<<area<<endl;
        cout<<"Circumference of a circle is : "<<circum<<endl;

    }
};

int main(){
    Area obj;

    obj.getdata();
    obj.action();

    return 0;
}