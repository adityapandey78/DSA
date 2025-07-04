## Method 1: Memoized recursion

```cpp
#include <bits/stdc++.h> 
bool f(int ind, int target, vector<int> &arr, vector<vector<int>>&dp){
    if(target==0) return true;
    if(ind==0) return( arr[0]==target); 
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake= f(ind-1, target,arr,dp);
    bool take= false;
    if(target>=arr[ind]){
         take=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]= {take || notTake};
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n +1,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
    
}
```

## Method 2: Tabulation

```cpp
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<int>>dp(n +1,vector<int>(k+1,-1));
    // return f(n-1,k,arr,dp);
    vector<vector<bool>>dp(n +1,vector<bool>(k+1,0));
    for( int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake= dp[ind-1][target];
            bool take= false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target]= {take || notTake};
        }
    }
    return dp[n-1][k];
    
}
```

## Method 3: Space Optimized Tabulation  

```cpp
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    
    prev[0] = true;  // sum 0 is always possible
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        curr[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
}
```