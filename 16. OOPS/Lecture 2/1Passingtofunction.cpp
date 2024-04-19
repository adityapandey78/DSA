#include<iostream>
using namespace std;
class Player{
private:
    int health,age,score;
    bool alive;

public:
    int getHealth(){
        return health;
    }
    int getAge(){
        return age;
    }
    int getscore(){
        return score;
    }
    int isAlive(){
        return alive;
    }



    void setHealth(int health){
       this->health= health;
    }
    void setAge(int age){
        this->age=age;
    }
    void setscore(int score){
        this->score= score;
    }
    void setisAlive(bool alive){
        this->alive= alive;
    }
};

int addScore(Player a,Player b){
    return a.getscore()+b.getscore();
}

Player getMaxPlayer(Player a,Player b){
    if(a.getscore()>b.getscore())
    return a;
    else return b;
}
int main(){
    Player Aditya; //object creation ,statically
    Player Raghav;

    Aditya.setHealth(200);
    Aditya.setAge(22);
    Aditya.setscore(110);
    Aditya.setisAlive(true);


    Raghav.setHealth(100);
    Raghav.setAge(28);
    Raghav.setscore(70);
    Raghav.setisAlive(true);


    cout<<addScore(Aditya,Raghav)<<endl; //passing the object as parameter and getting the result

    //cout<<getMaxPlayer(Aditya,Raghav);
    //ye ni kr skte coz object print ni krta compiler

    //so, lets store the result into another object 
    Player Result=getMaxPlayer(Aditya,Raghav);
    cout<<Result.getscore()<<endl;
    cout<<Result.getHealth()<<endl;
return 0;
}