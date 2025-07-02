## leetcode 2035
```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int totSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) totSum+=arr[i];
        int k=totSum;
        
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    
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
    //dp[n-1][0-> totalSum]
    int mini=1e9;
    for(int s1=0;s1<totSum/2;s1++){
        if(dp[n-1][m1]==true){
            mini=min(mini,abs((totSum-s1)-s1))
        }
    }
    return mini;
};
```