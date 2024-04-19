#include<iostream>
using namespace std;
int main(){
class Student{
public:
    int rno;
    string name;
    float gpa;
} ;
Student s1; //decleration
s1.rno=76;
//cin>>s1.name;
s1.name="Aditya";
s1.gpa=8.5;
//hum ise ese bhi initialis ekr skte hain but dhyan rahe ki class ke order me hi hona chaiye
//jis seq me diya hai usi seq me
Student s2={403,"Raghav",8.7};

cout<<s1.rno<<" "<<s1.name<<" "<<s1.gpa<<endl;
cout<<s2.rno<<" "<<s2.name<<" "<<s2.gpa;






return 0;
}