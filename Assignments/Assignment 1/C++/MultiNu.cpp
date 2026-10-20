#include <iostream>

using namespace std;

class Table{
    public:
    int n,i;

    void getdata(){
        cout<<"enter a number :";
        cin>>n;
    }

    void  printTable(){

        for(i=1; i<=10; i++){
            cout<<n<<" * "<<i<<"="<<n * i<<"\n";
        }
    }
};

int main(){
    Table obj;

    obj.getdata();
    obj.printTable();

    return 0;
}