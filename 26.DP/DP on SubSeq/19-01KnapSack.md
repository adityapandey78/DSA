```cpp
#include <bits/stdc++.h> 

// Method 1: Memoization (Top-Down DP)
int solveRecursive(int ind, int W, vector<int>&wt, vector<int>&val, vector<vector<int>>&dp) {
    // Base case: if we're at the first item
    if(ind == 0) {
        if(wt[0] <= W) return val[0];
        return 0;
    }
    
    // If already computed, return cached result
    if(dp[ind][W] != -1) return dp[ind][W];
    
    // Option 1: Don't take current item
    int notTake = solveRecursive(ind-1, W, wt, val, dp);
    
    // Option 2: Take current item (if weight allows)
    int take = INT_MIN;
    if(wt[ind] <= W) {
        take = val[ind] + solveRecursive(ind-1, W-wt[ind], wt, val, dp);
    }
    
    // Store and return the maximum value
    return dp[ind][W] = max(take, notTake);
}

// Method 2: Tabulation (Bottom-Up DP)
int solveTabulation(vector<int>&wt, vector<int>&val, int n, int W) {
    // Create DP table
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    // Base case: fill first row for item 0
    for(int w = wt[0]; w <= W; w++) {
        dp[0][w] = val[0];
    }
    
    // Fill the DP table
    for(int ind = 1; ind < n; ind++) {
        for(int w = 0; w <= W; w++) {
            // Don't take current item
            int notTake = dp[ind-1][w];
            
            // Take current item (if weight allows)
            int take = INT_MIN;
            if(wt[ind] <= w) {
                take = val[ind] + dp[ind-1][w-wt[ind]];
            }
            
            dp[ind][w] = max(take, notTake);
        }
    }
    
    return dp[n-1][W];
}

// Method 3: Space Optimization
int knapsack(vector<int> wt, vector<int> val, int n, int W) {
    // Use only two arrays instead of 2D table
    vector<int> prev(W+1, 0), curr(W+1, 0);
    
    // Base case: initialize for first item
    for(int w = wt[0]; w <= W; w++) {
        prev[w] = val[0];
    }
    
    // Process remaining items
    for(int ind = 1; ind < n; ind++) {
        for(int w = 0; w <= W; w++) {
            // Don't take current item
            int notTake = prev[w];
            
            // Take current item (if weight allows)
            int take = INT_MIN;
            if(wt[ind] <= w) {
                take = val[ind] + prev[w-wt[ind]];
            }
            
            curr[w] = max(take, notTake);
        }
        // Move current to previous for next iteration
        prev = curr;
    }
    
    return prev[W];
}

// Usage example:
// For memoization: 
// vector<vector<int>> dp(n, vector<int>(W+1, -1));
// return solveRecursive(n-1, W, wt, val, dp);

// For tabulation:
// return solveTabulation(wt, val, n, W);

// For space optimized:
// return knapsack(wt, val, n, W);
```