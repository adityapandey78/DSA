#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int rno;
    float marks;

    Student( string name , int rno,float marks){
        //constructer bnaya taaki ek baar me hi sbko define kr paaye
        this->name=name;
        this->rno=rno;
        this->marks=marks;

    }
};

void change( Student *s){
 s->name="Pandey";
}


int main(){
    Student* s=new Student("Aditya", 76, 92.8);
    cout<<s->name<<endl;
    //passing by address
    change(s);
    cout<<s->name<<endl;
return 0;
};