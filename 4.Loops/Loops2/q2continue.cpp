#include<iostream>
/*print the odd numbers upto n */
using namespace std;
int main(){
    for (int i = 1; i <=20; i++)
    {
        if (i%2==0) continue;
        cout<<i<<endl;
       //continue skips the particular round/interation and proceeds furthur in the loop, that's why loop me bs odd print honge... whereas break pura loop hi tod deta hai
        
    }
    
    return 0;
}