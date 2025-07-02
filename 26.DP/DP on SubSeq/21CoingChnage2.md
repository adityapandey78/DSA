## Memoized Solution for Coin Change II

```cpp
class Solution {
public:
    int f(int amt,int n ,vector<int>& coins,vector<vector<int>>&dp){
        if(n==0){
            if (amt % coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[n][amt]!=-1) return dp[n][amt];
        int notTake= 0+f(amt, n-1, coins, dp);
        int take=0;
        if(coins[n]<=amt) take= f(amt-coins[n],n, coins, dp);

        return dp[n][amt]= (take+notTake);
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        return f(amt,n-1,coins,dp);
        
    }
};
```
## Tabulated Solution for Coin Change II

```cpp
class Solution {
public:
    int f(int amt,int n ,vector<int>& coins,vector<vector<int>>&dp){
        if(n==0){
            if (amt % coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[n][amt]!=-1) return dp[n][amt];
        int notTake= 0+f(amt, n-1, coins, dp);
        int take=0;
        if(coins[n]<=amt) take= f(amt-coins[n],n, coins, dp);

        return dp[n][amt]= (take+notTake);
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        return f(amt,n-1,coins,dp);
        
    }
};
```