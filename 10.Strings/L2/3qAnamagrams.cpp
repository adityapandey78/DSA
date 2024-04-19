/* Given two strings S and T , return True if t is an anagrma of s , otherwise false 
INPUT S= physicswallah, T=Wallahphysics
OUTPUT: True*/

//leetcode 242:Valid ANAGRAM
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="physicswallah";
    string t="wallahphysics";
    //dono strings ko alphabetically arrange kar do and then compare kr do
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t)cout<<true;
    else cout<<false;
    return 0;
}