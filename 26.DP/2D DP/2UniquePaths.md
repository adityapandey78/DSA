## Unique Paths Leetcode Problem 62 

## Momoized Recursion Solution
```cpp
class Solution {
public:

    int f(int m, int n,vector<vector<int>>&dp){
        if( m==0 && n==0){
            return dp[m][n]=1;
        }
        if(m<0 || n<0)return 0; //since going out of bound of the matrx
        cout << "Calling f(" << m << "," << n << ")" << endl;

        if(dp[m][n]!=-1) return dp[m][n];
        int up= f(m-1,n,dp);
        int left= f(m,n-1,dp);
        return dp[m][n]= up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));

        return f(m-1,n-1,dp);
    }
};
```
## Tabulation Solution
```cpp

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;

                }
                else{
                    int up=0,left=0;
                    if (i > 0) {
                         up = dp[i - 1][j];
                    }
                    if (j > 0) {
                         left = dp[i][j-1];                        
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
        // return f(m-1,n-1,dp); //for recursive momoization
    }
};
```
## Space Optimized Tabulation Solution
```cpp
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int>prev(n,0);
        for (int i = 0; i < m ; i++) {
            vector<int>temp(n,0);
            for (int j = 0; j < n ; j++) {
                if (i == 0 && j == 0){
                    temp[j]=1;
                }
                else{
                    int up=0,left=0;
                    if (i > 0) {
                         up = prev[j];
                    }
                    if (j > 0) {
                         left = temp[j-1];                        
                    }
                   temp[j] = up + left;
                }
            }
            prev=temp;
        }
        return prev[n - 1];
        
    }
};
```
