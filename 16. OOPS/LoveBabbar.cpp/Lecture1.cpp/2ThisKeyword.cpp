#include<iostream>
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
    
return 0;
}