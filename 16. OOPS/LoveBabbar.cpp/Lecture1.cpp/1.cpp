#include<iostream>
//we can include a file as well
#include"Hero2.cpp"

using namespace std;


class Hero1{
    //propereties
    public:
    int size;

    int get_health(){
        return health;
    }

    int get_level(){
        return level;
    }

    void setHealth(int h){
        health=h;
    }

    void setLevel(char ch ){
        level=ch;
    }


    private:
    int health;
    int level;

};
int main(){
    
//Static Allocation
Hero1 a;

cout<<"level is "<<a.get_level()<<endl;
cout<<"Health is "<<a.get_health()<<endl;

//dynamically 
Hero1 *b= new Hero1;

cout<<"level is "<<(*b).get_level()<<endl;
cout<<"Health is "<<(*b).get_health()<<endl;



    

return 0;
}