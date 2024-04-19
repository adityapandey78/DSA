#include<iostream>
using namespace std;
void removeChar(string ans, string original, int idx){
if(idx==original.length()){
    cout<<ans;
    return;
} char ch =original[idx];
if(ch=='a') removeChar(ans,original,idx+1);  //agar wo letter mil gya toh wapas se call lga, bina kuchh add huye
else removeChar(ans+ch,original,idx+1);//milen ke baad add kr diya use ans wale array

}
int main(){
    string str="aditya pandey";
    removeChar("", str,0);
    return 0;
}