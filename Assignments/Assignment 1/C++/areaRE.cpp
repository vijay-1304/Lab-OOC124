#include <iostream>

using namespace std;

class Area{
    public:
    float l , w ; 
    float area , perimeter;

    void getdata(){
        cout<<"Enter length of a rectangle :";
        cin>>l;
        cout<<"Enter width of a rectangle : ";
        cin>>w;
    }

    void action(){
        area = l * w;
        perimeter = 2 * (l + w);

        cout<<"Area of a rectangle is : "<<area<<endl;
        cout<<"Perimeter of a rectangle is : "<<perimeter<<endl;

    }
};

int main(){
    Area obj;

    obj.getdata();
    obj.action();

    return 0;
}