#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<int>arr(26,0);
    string s="leetcode";
    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        int ascii=(int)ch;
        arr[ascii-97]++;  // element ko 1 se upgrade kr diya i.e., uske frequency badh rahi hai
    }

    //assigning the maximum no of occurance to a digit
    int mx=0;
    for (int i = 0; i < 26; i++)
    {
        if(arr[i]>mx) mx=arr[i];
    }



    for (int i = 0; i < 26; i++)
    {
        if(arr[i]==mx){
            int ascii=i+97; //assigning again the asii value
            char ch=(char)ascii;
            cout<<ch<<" "<<mx<<endl;

        }
    }
    

    return 0;
}