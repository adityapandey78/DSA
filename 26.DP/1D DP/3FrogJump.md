## Memoization - Frog Jump

```cpp
#include <bits/stdc++.h> 
int f(int idx, vector<int>&heights, vector<int>&dp){
    if(idx==0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int left=f(idx-1,heights,dp)+abs(heights[idx]-heights[idx-1]);
    int right=INT_MAX;
    if(idx>1){
         right=f(idx-2,heights,dp)+abs(heights[idx]-heights[idx-2]);
    }
    return dp[idx]= min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return f(n-1,heights,dp);

}
```

## Tabulation - Frog Jump

```cpp
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
   
}

```
## Space Optimized - Frog Jump

```cpp
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)ss=prev2+abs(heights[i]-heights[i-2]);
        int curr=min(fs,ss);
        prev2=prev;
        prev=curr;
    }
    return prev;
   
}
```