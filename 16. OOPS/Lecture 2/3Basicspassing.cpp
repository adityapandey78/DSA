#include<iostream>
using namespace std;
class Car{
    public:
    int price;
    string name;
};


void change (Car*x){
    (*x).name="Honda Amaze";
    //idhr pointer ko*x me rkhna pad raha hai
    (*x).price=800000;

    //2nd way to signify
    //x->name="Honda Amaze";
    //x->price=1200000;
    //a->b means (*a).b
}
int main(){
    Car c1={1200000,"Kia Sonnet"};
    cout<<c1.name<<" "<<c1.price<<endl;

    //c++ me hme classes ko ass a ref pass krna pdta hai
    //so as a ref pass krne ke liye uske  add ki jarurat pdegi and usk aaddress store krega uska pointer
    //that is why pointer ka funn bnaya
    change(&c1);
    cout<<c1.name<<" "<<c1.price<<endl;
return 0;
}