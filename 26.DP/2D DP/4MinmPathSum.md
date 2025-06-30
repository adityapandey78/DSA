## leetcdode 64. Minimum Path Sum

```cpp
class Solution {
public:
    int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base Case
        if (m == 0 && n == 0) return grid[0][0];
        if (m < 0 || n < 0) return 1e9;

        // Memoized result
        if (dp[m][n] != -1) return dp[m][n];

        // Recursive calls
         int up = grid[m][n]+ f(m - 1, n, grid, dp);
         int left =grid[m][n]+ f(m, n - 1, grid, dp);

        return dp[m][n] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize memoization table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start from bottom-right cell
        // return f(m - 1, n - 1, grid, dp);
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                //base case
            if(i==0 && j==0){
                curr[j]=grid[i][j];
                continue;
            }else{
                int up =INT_MAX, left = INT_MAX;

                if (i > 0) {
                    up =grid[i][j]+ prev[j];
                }
                // Paths from left cell
                if (j > 0) {
                    left = grid[i][j]+ curr[j-1];                        
                }

                curr[j]=min(left,up);

            }
            }
                prev=curr;
        }
        return prev[n-1];
    }
};
```