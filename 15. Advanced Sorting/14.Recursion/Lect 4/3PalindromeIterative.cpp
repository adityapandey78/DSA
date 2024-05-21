
#include<iostream>
using namespace std;
bool isPalindrome(string s){
    int i=0;
    int j=s.length();
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;

}
int main(){
    string s= "racecar";
    cout<<isPalindrome(s);
    return 0;
}