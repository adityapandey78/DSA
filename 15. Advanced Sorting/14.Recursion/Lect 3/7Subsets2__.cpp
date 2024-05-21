//leetcode 90
//print the subset containing  the duplicate character
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void storeSubset(string ans, string original , vector<string>&v,bool flag){
    if(original==""){
        v.push_back(ans);
        return;
    }
    char ch=original[0];
    if(original.length()==1){
        if(flag==true) storeSubset(ans+ch,original.substr(1),v,true);
        storeSubset(ans,original.substr(1),v,true);
        return; //taaki neeche ke conditions na chalein
    }
    char dh=original[1];
    if(ch==dh)//duplicate characters milein to
    {
        if(flag==true) storeSubset(ans+ch,original.substr(1),v,true);
        storeSubset(ans,original.substr(1),v,false);//left wale ko false chlana hai
    }
    else
    {
        if(flag==true) storeSubset(ans+ch,original.substr(1),v,true);
        storeSubset(ans,original.substr(1),v,true);
    }
    
}
int main(){
    string str="abcd";
    vector<string> v;
    storeSubset("",str,v,true); //pehlse true krke hi bheja
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}