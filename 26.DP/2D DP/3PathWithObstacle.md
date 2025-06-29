# Path with obstacles in a 2D grid LEETCODE 63

## Tabular Solution
```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(obstacleGrid, dp, m - 1, n - 1);

        // if(obstacleGrid[0][0]!=1) dp[0][0]=1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                if (obstacleGrid[i][j] != 1 && i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }  

                int up = 0, left = 0;
                cout << "Calling f(" << i << "," << j << ")" << endl;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

## recursive Solution
```cpp
int f(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int m,
          int n) {
        if (m == 0 && n == 0 && obstacleGrid[m][n] != 1)
            return 1;
        if ((m < 0 || n < 0))
            return 0;
        if (obstacleGrid[m][n] == 1)
            return 0;
        cout << "Calling f(" << m << "," << n << ")" << endl;
        if (dp[m][n] != -1)
            return dp[m][n];
        int up = f(obstacleGrid, dp, m - 1, n);
        int left = f(obstacleGrid, dp, m, n - 1);
        return dp[m][n] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(obstacleGrid, dp, m - 1, n - 1);
    }
```

## Space Optimized Tabulation Solution

```cpp 

// basically  dp[i] ko hum prev[i] se replace karte hain
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(obstacleGrid, dp, m - 1, n - 1);
        vector<int>prev(n,0);
        // if(obstacleGrid[0][0]!=1) dp[0][0]=1;
        for (int i = 0; i < m; i++) {
                vector<int>temp(n,-1);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                    continue;
                }

                if (obstacleGrid[i][j] != 1 && i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }  

                int up = 0, left = 0;
                cout << "Calling f(" << i << "," << j << ")" << endl;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
            prev=temp;
        }
        return prev[n - 1];
    }
```