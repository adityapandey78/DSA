## Memoization Approach
```cpp
const int mod = 1e9 + 7;
int f(vector<int>& nums, int idx, int k, vector<vector<int>>& dp) {
    if(idx < 0) return (k == 0);

    if(dp[idx][k] != -1) return dp[idx][k];

    int notPick = f(nums, idx - 1, k, dp);
    int pick = 0;
    if(nums[idx] <= k) pick = f(nums, idx - 1, k - nums[idx], dp);

    return dp[idx][k] = (pick + notPick) % mod;
}

int findWays(vector<int>& nums, int k) {
    vector<vector<int>> dp(nums.size(), vector<int>(k + 1, 0));
    
    // Base case: sum 0 is always possible with empty subset
    for(int i = 0; i < nums.size(); i++){
        dp[i][0] = 1;
    }
    
    // Handle first element
    if(nums[0] <= k) {
        dp[0][nums[0]] = 1;
    }
    // If first element is 0, we need to handle it specially
    if(nums[0] == 0) {
        dp[0][0] = 2; // Both taking and not taking 0 give sum 0
    }
    
    // Fill the DP table
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j <= k; j++){
            int notPick = dp[i - 1][j];
            int pick = 0;
            if(nums[i] <= j) pick = dp[i - 1][j - nums[i]];
            dp[i][j] = (pick + notPick) % mod;
        }
    }
    
    return dp[nums.size() - 1][k];
}
```

## tabulation Approach
```cpp

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    
    if ((totSum - d) < 0 || (totSum - d) % 2 != 0) return 0;

    int s2 = (totSum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    // Initialize base cases
    if (arr[0] == 0)
        dp[0][0] = 2; // two options: pick or not pick zero
    else
        dp[0][0] = 1; // only one option: don't pick anything to get sum 0

    if (arr[0] != 0 && arr[0] <= s2)
        dp[0][arr[0]] = 1;

    // Build DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= s2; j++) {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = (pick + notPick) % MOD;
        }
    }

    return dp[n - 1][s2];
}

```

## Space Optimized Approach
```cpp
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    
    if ((totSum - d) < 0 || (totSum - d) % 2 != 0) return 0;

    int s2 = (totSum - d) / 2;
    vector<int> prev(s2 + 1, 0), curr(s2 + 1, 0);

    // Base case initialization
    if (arr[0] == 0)
        prev[0] = 2; // pick or not pick
    else
        prev[0] = 1; // don't pick anything

    if (arr[0] != 0 && arr[0] <= s2)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        curr = prev; // Start by copying previous row
        for (int j = 0; j <= s2; j++) {
            int notPick = prev[j];
            int pick = 0;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = (pick + notPick) % MOD;
        }
        prev = curr;
    }

    return prev[s2];
}
```