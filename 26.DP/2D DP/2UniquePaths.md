## Unique Paths Leetcode Problem 62 

## Memoized Recursion Solution
```cpp
class Solution {
public:
    // Recursive function with memoization to find unique paths
    int f(int m, int n, vector<vector<int>>&dp){
        // Base case: reached destination (0,0)
        if(m == 0 && n == 0){
            return dp[m][n] = 1;
        }
        // Out of bounds check
        if(m < 0 || n < 0) return 0;
        
        cout << "Calling f(" << m << "," << n << ")" << endl;

        // Return memoized result if already computed
        if(dp[m][n] != -1) return dp[m][n]; 
        
        // Calculate paths from top and left
        int up = f(m-1, n, dp);
        int left = f(m, n-1, dp);
        
        // Store and return total paths
        return dp[m][n] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        // Initialize DP table with -1
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // Start from bottom-right corner (m-1, n-1)
        return f(m-1, n-1, dp);
    }
};
```

## Tabulation Solution
```cpp
int uniquePaths(int m, int n) {
    // Initialize DP table
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    // Fill DP table bottom-up
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Base case: starting point
            if (i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            else{
                int up = 0, left = 0;
                // Paths from above cell
                if (i > 0) {
                    up = dp[i - 1][j];
                }
                // Paths from left cell
                if (j > 0) {
                    left = dp[i][j-1];                        
                }
                // Total paths = paths from above + paths from left
                dp[i][j] = up + left;
            }
        }
    }
    // Return paths to bottom-right corner
    return dp[m - 1][n - 1];
};
```

## Space Optimized Tabulation Solution
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use only two 1D arrays instead of 2D array
        vector<int>prev(n, 0);  // Previous row
        
        for (int i = 0; i < m; i++) {
            vector<int>temp(n, 0);  // Current row
            for (int j = 0; j < n; j++) {
                // Base case: starting point
                if (i == 0 && j == 0){
                    temp[j] = 1;
                }
                else{
                    int up = 0, left = 0;
                    // Paths from above (previous row)
                    if (i > 0) {
                        up = prev[j];
                    }
                    // Paths from left (current row)
                    if (j > 0) {
                        left = temp[j-1];                        
                    }
                    // Total paths = paths from above + paths from left
                    temp[j] = up + left;
                }
            }
            // Update previous row for next iteration
            prev = temp;
        }
        // Return paths to bottom-right corner
        return prev[n - 1];
    }
};
```
