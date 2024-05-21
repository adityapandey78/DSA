//Print subsets of a string with uniques characters. Follow up DO it for arrays as well
//leetcode-78
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void storeSubset(string ans,string original,vector<string>&v){
    if(original==""){
        v.push_back(ans); //pushback krke  store kra rahe hain
        return;
    }
    char ch=original[0];
    storeSubset(ans+ch,original.substr(1),v);  //sub string(1) liya hai....jo tyha use chhod ke  uska next....
    storeSubset(ans,original.substr(1),v);
}
int main(){
    string str="abc";
    vector<string>v;
    storeSubset("",str,v);
    for(string ele:v){
        cout<<ele<<endl;
    }
    return 0;
}