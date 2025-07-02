```cpp
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    
    prev[0] = true;  // sum 0 is always possible
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        curr[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        for(int i=0;i<n;i++) totSum+=nums[i];
        if(totSum%2) return false;
        int target= totSum/2;
        return subsetSumToK(n,target,nums);
    }
};
```