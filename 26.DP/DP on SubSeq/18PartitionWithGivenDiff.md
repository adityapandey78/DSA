## Recursive Memoization

```cpp
#include <bits/stdc++.h> 
const int MOD = 1e9 + 7;

int f(int n, int d, vector<int> &arr, vector<vector<int>> &dp){
    if (n == 0) {
        if (d == 0 && arr[0] == 0) return 2; // include and exclude 0
        if (d == 0 || d == arr[0]) return 1;
        return 0;
    }

    if (dp[n][d] != -1) return dp[n][d];

    int notPick = f(n - 1, d, arr, dp);
    int pick = 0;
    if (arr[n] <= d) pick = f(n - 1, d - arr[n], arr, dp);

    return dp[n][d] = (pick + notPick) % MOD;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    
    if ((totSum - d) < 0 || (totSum - d) % 2 != 0) return 0;

    int s2 = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    return f(n - 1, s2, arr, dp);
}
```
