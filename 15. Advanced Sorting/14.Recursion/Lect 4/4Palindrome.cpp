//check if palindrome or not using recursion
#include<iostream>
#include<string>
using namespace std;
bool isPalindrome(string s, int i, int j){
    //base case
    if(i>j) return true;

    // if found
    if(s[i]!=s[j]) return false;
    else return isPalindrome(s,i+1,j-1);
}
int main(){
    string s="Aditya";
    cout<<isPalindrome(s,0,s.length()-1);
    //return 0;
}