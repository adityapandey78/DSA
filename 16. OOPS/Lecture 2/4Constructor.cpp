#include<iostream>
using namespace std;
int main(){
class Student{
public:
    int rno;
    string name;
    float gpa;

    Student (){
        //default constructer 
        //ye hmesha banega hi
    }
    Student (string x,int y,float z){
        //constructer having its attributes in order
        gpa=z;
        rno=y;
        name=x; 
    }
    Student (int y,string x,float z){
        //we can have many constructes as well
       
        gpa=z;
        rno=y;
        name=x;
        
    }
    Student(int rno,string name, float gpa){
        (*this).rno=rno;
        this->name=name;
        this->gpa=gpa;
    }



} ;
Student s1; //declaration Method 1
s1.rno=76;
s1.name="Aditya";
s1.gpa=8.5;
//declaration method 2

Student s2={403,"Raghav",8.7};//for constructer 2
//declaration method 3
Student s3= Student("Aditya",90,9.2);

cout<<s1.rno<<" "<<s1.name<<" "<<s1.gpa<<endl;
cout<<s2.rno<<" "<<s2.name<<" "<<s2.gpa;






return 0;
}