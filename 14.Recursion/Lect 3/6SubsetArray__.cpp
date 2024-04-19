//Print subsets of a string with uniques characters. Follow up DO it for arrays as well
//leetcode-78
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printSubset(int arr[],int n,int idx,vector<int>ans){ //idhr vector<int>&v nahi hoga coz har baar nya vector ban raha hai and pushbackj ho raha hai
if(idx==n){
    for (int  i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;   
}
printSubset(arr,n,idx+1,ans);
ans.push_back(arr[idx]); //idhar pushback ho jaa rha hai
printSubset(arr,n,idx+1,ans);//not same as previous coz ans updated ho gya hai
}
int main(){
    int arr[]={1,2,3};
    vector<int>v;
    int n=sizeof(arr)/sizeof(arr[0]);
    printSubset(arr,n,0,v);
    for(int ele:v){
        cout<<ele<<endl;
    }
    return 0;
}

/*
//Leetcode Solution
class Solution {
public:
void helper(vector<int>&nums,vector<int>ans,vector<vector<int>>&finalAns,int idx){
    if(idx==nums.size()){
        finalAns.push_back(ans);
        return;
    }
    helper(nums,ans,finalAns,idx+1);
    ans.push_back(nums[idx]);
    helper(nums,ans,finalAns,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int> > finalAns;
        helper(nums,ans,finalAns,0);
        return finalAns;
    }
};
*/