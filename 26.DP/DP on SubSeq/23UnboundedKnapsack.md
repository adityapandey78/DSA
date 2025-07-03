```cpp

int f(int n, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>&dp){
    if(n==0){
        return (w/weight[0])*profit[0];}
        if(dp[n][w]!=-1) return dp[n][w];
        int noTake=0+f(n-1,w,profit,weight,dp);
        int take= -1e9;
        if(weight[n]<=w) take=profit[n]+ f(n,w-weight[n],profit,weight,dp);

        return dp[n][w]= max(take,noTake);
    
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> prev(w + 1, 0), curr(w + 1, 0);

    for (int j = 0; j <= w; j++) {
        prev[j] = (j / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            int noTake = prev[j];
            int take = 0;
            if (weight[i] <= j)
                take = profit[i] + curr[j - weight[i]];

            curr[j] = max(take, noTake);
        }
        prev = curr;
    }

    return prev[w];
}

```