## Memoized Recursion Solution 
```cpp
class Solution {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Out of bounds check
        if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
            return -1e9;
        }
        
        // Base case: reached last row
        if(i == r-1) {
            if(j1 == j2) return grid[i][j1]; // Both robots at same position
            else return grid[i][j1] + grid[i][j2]; // Different positions
        }
        
        // Return memoized result
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        // Try all 9 possible moves (3 for each robot)
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if(j1 == j2) {
                    value = grid[i][j1]; // Same position, count once
                } else {
                    value = grid[i][j1] + grid[i][j2]; // Different positions
                }
                value += f(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // dp[row][col1][col2] - maximum cherries from (row,col1) and (row,col2)
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        
        return f(0, 0, c-1, r, c, grid, dp);
    }
};
```

## Tabulation Solution
```cpp
int cherryPickup(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    
    // Base case: fill last row
    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // Fill dp table from bottom to top
    for(int i = r-2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int maxi = -1e9;
                // Try all 9 possible moves
                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if(j1 == j2) {
                            value = grid[i][j1];
                        } else {
                            value = grid[i][j1] + grid[i][j2];
                        }
                        
                        // Check bounds for next positions
                        if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c) {
                            value += dp[i+1][j1+dj1][j2+dj2];
                        } else {
                            value += -1e8; // Invalid move penalty
                        }
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
}
```

## Space Optimized Tabulation Solution
```cpp
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        // Use only two 2D arrays instead of 3D array
        vector<vector<int>> front(c, vector<int>(c, 0));
        vector<vector<int>> curr(c, vector<int>(c, 0));

        // Base case: initialize last row
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                if(j1 == j2) front[j1][j2] = grid[r-1][j1];
                else front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        // Fill from bottom to top
        for(int i = r-2; i >= 0; i--) {
            for(int j1 = 0; j1 < c; j1++) {
                for(int j2 = 0; j2 < c; j2++) {
                    int maxi = -1e9;
                    // Try all 9 possible moves
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            if(j1 == j2) {
                                value = grid[i][j1];
                            } else {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            
                            // Check bounds and add value from next row
                            if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c) {
                                value += front[j1+dj1][j2+dj2];
                            } else {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr; // Move to next iteration
        }
        return front[0][c-1];
    }
};
```
