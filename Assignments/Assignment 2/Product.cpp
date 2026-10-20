#include <iostream>
#include <string>

using namespace std;
 
class Product{
    private:
    int productid, price;
    string name;
    
    public:
    void inputdetails(){
        cout<<"Enter Product name : ";
        getline(cin>>ws,name);
        cout<<"Enter Product id : ";
        cin>>productid;
        cout<<"Enter price : ";
        cin>>price;
    }

    void DisplayDetails(){
        cout<<"---\nProduct Details :---\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Product id : "<<productid<<endl;
        cout<<"Price : "<<price<<endl;
    }

};

int main(){
Product obj;
obj.inputdetails();
obj.DisplayDetails();
return 0;
}

