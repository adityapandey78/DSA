#include<iostream>
#include<vector>
using namespace std;

int f(int n, vector<int>&dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1, dp)+f(n-2,dp);
}
int main(){
    int n;
    cout<<"Enter the no:"<<endl;
    cin>>n;
    int prev2=0;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int curi=prev1+prev2;
        prev2=prev1;
        prev1=curi;
    }
    cout<<prev1;
    
return 0;
}