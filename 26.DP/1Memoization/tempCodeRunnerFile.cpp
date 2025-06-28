        //base case
        if(idx==0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mmSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(idx-j>=0){
                int jump= fun(idx-j,heights,k,dp)+abs(heights[idx]-heights[idx-j]);
                //update the minimu energy
                mmSteps=min(jump,mmSteps);
            }
        }
        return dp[idx]= mmSteps;
    }
    int frogJumpKSteps(vector<int>& heights, int k) {
        // Your implementation here
        int idx=heights.size()-1;
        vector<int>dp(idx+1,-1);
        return fun(idx,heights,k,dp);
    }
};
