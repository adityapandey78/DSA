/* 
Given n strings consisting of lowercase English Alphabets. Print the charatacter that is occuring most number of times.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="physicswallah";
    int max=0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        int count=1;
        for (int j = i+1 ; j <s.length(); j++)         {
            if(s[j]==s[i]) count++;
        }
        if(max<count) max=count;
    }

        //dusre loop me konm sa letter kitni baar print ho ra hai

    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        int count=1;
        for (int j = i+1 ; j <s.length(); j++)         {
            if(s[j]==s[i]) count++;
        }
        if(count==max) 
        cout<<ch<<" "<<max<<endl;
    }    

    

    return 0;
}