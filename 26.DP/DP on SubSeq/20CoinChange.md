## DP on Subsequence - Coin Change Problem Leetcode:322
```cpp

class Solution {
public:
int f(vector<int>& coins, int n, int amt,vector<vector<int>>&dp){
    //base case
    if(n==0){
        if(amt%coins[n]==0) return amt/coins[n];
        else return 1e9;
    }
    if(dp[n][amt]!=-1) return dp[n][amt];
    int notTake=0+f(coins,n-1,amt,dp); //not take
    int take=1e9;
    if(coins[n]<=amt)  take=1+ f(coins,n,amt-coins[n],dp);
    
    return dp[n][amt]= min(take,notTake);
}
    int coinChange(vector<int>& coins, int amt) {
        // int n=coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // int ans= f(coins,n-1,amount,dp);
        // if(ans>=1e9)return -1; else return ans;


        // Tabulation Soln
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        vector<int> prev(amt+1,0), curr(amt+1,0);
        for(int i=0;i<=amt;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }


        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int notTake=0+prev[j]; //not take
                int take=1e9;
                if(coins[i]<=j)  take=1+ curr[j-coins[i]];
                curr[j]= min(take,notTake);
            }
            prev=curr;
        }
        int ans= prev[amt];
        if(ans>=1e9)return -1; else return ans;
    }
};
```