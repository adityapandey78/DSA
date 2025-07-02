## Method 1: Memoized recursion

```cpp
#include <bits/stdc++.h> 

// Recursive function to check if subset with given sum exists
// ind: current index, target: remaining sum needed, arr: input array, dp: memoization table
bool f(int ind, int target, vector<int> &arr, vector<vector<int>>&dp){
    // Base case: if target becomes 0, we found a valid subset
    if(target==0) return true;
    
    // Base case: if we're at first element, check if it equals target
    if(ind==0) return( arr[0]==target); 
    
    // Return memoized result if already computed
    if(dp[ind][target]!=-1) return dp[ind][target];
    
    // Option 1: Don't take current element
    bool notTake= f(ind-1, target,arr,dp);
    
    // Option 2: Take current element (only if it doesn't exceed target)
    bool take= false;
    if(target>=arr[ind]){
         take=f(ind-1,target-arr[ind],arr,dp);
    }
    
    // Store and return result: true if either option works
    return dp[ind][target]= {take || notTake};
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Create memoization table: dp[i][j] = can we get sum j using first i elements
    vector<vector<int>>dp(n +1,vector<int>(k+1,-1));
    
    // Start recursion from last index with target sum k
    return f(n-1,k,arr,dp);
}
```

## Method 2: Tabulation

```cpp
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Create DP table: dp[i][j] = can we achieve sum j using elements 0 to i
    vector<vector<bool>>dp(n +1,vector<bool>(k+1,0));
    
    // Base case: sum 0 is always achievable (empty subset)
    for( int i=0;i<n;i++){
        dp[i][0]=true;
    }
    
    // Base case: only first element can achieve sum equal to arr[0]
    if(arr[0] <= k) dp[0][arr[0]]=true;
    
    // Fill DP table for all elements and all possible sums
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            // Option 1: Don't include current element
            bool notTake= dp[ind-1][target];
            
            // Option 2: Include current element (if it fits)
            bool take= false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            
            // Current state is true if either option works
            dp[ind][target]= {take || notTake};
        }
    }
    
    // Answer is whether we can achieve sum k using all n elements
    return dp[n-1][k];
}
```

## Method 3: Space Optimized Tabulation  

```cpp
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Use only two arrays instead of 2D table: previous and current row
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    
    // Base case: sum 0 is always achievable
    prev[0] = true;
    
    // Base case: first element can only achieve its own value as sum
    if (arr[0] <= k) prev[arr[0]] = true;

    // Process each element one by one
    for (int ind = 1; ind < n; ind++) {
        // Sum 0 is always achievable
        curr[0] = true;
        
        // Check all possible target sums
        for (int target = 1; target <= k; target++) {
            // Option 1: Don't take current element
            bool notTake = prev[target];
            
            // Option 2: Take current element (if it doesn't exceed target)
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
                
            // Store result for current target
            curr[target] = take || notTake;
        }
        
        // Move current row to previous for next iteration
        prev = curr;
    }

    // Return whether target sum k is achievable
    return prev[k];
}
```