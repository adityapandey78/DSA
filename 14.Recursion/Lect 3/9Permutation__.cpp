//find all the permuation of the sequence of a string

#include<iostream>
using namespace std;
void permutation(string ans,string original){
    if(original==""){
        cout<<ans<<endl;
        return;
    }
    for (int i = 0; i < original.length(); i++)
    {
        char ch= original[i]; //apmna char le rahe hainj append krne ke lye
        string left=original.substr(0,i); //usse left substring liya taaki left +right add kr ske
        string right= original.substr(i+1);
        permutation(ans+ch,left+right); //ans me append krte jaa rhe hain nd baaad me unhe print kr denge
    }
    
}
int main(){
    string str="123";
    permutation("",str);
    return 0;
}
