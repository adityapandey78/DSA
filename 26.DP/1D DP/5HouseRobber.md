## Recursive Solution
```cpp
class Solution {
public:
    int fun(vector<int>&nums,int idx,vector<int>dp){
        if(idx==0){
            dp[idx]=nums[idx];
            return dp[idx];
        } 
        if(idx<0) return 0;
        int pick= nums[idx]+fun(nums,idx-2,dp);
        int notPick=0+fun(nums,idx-1,dp);
        return dp[idx]= max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return fun(nums,nums.size()-1,dp);
    }
};
```
## Tabular Solution
```cpp
class Solution {
public:
    int fun(vector<int>&nums,int idx,vector<int>dp){
        if(idx==0){
            dp[idx]=nums[idx];
            return dp[idx];
        } 
        if(idx<0) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int pick= nums[idx]+fun(nums,idx-2,dp);
        int notPick=0+fun(nums,idx-1,dp);
        return dp[idx]= max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=dp[i-2];

            int noTake=0+dp[i-1];
            dp[i]=max(take,noTake);
        }
        return dp[nums.size()-1];                      
    }
};
```
## Space Optimized Solution
```cpp
int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=prev2;

            int noTake=0+prev;
             int curr=max(take,noTake);
            prev2=prev;
            prev=curr;

        }
        return prev;                      
    }
};
```