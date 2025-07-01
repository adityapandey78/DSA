```cpp

class Solution {
public:
int f(vector<vector<int>>& arr,int i, int j,vector<vector<int>>&dp){
    if(i==arr.size()-1 ) {
        return dp[i][j]=arr[arr.size()-1][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];    
    int d= arr[i][j]+ f(arr,i+1,j,dp);//down
    int dg= arr[i][j]+ f(arr,i+1,j+1,dp);//diagonally down
    return dp[i][j]= min(d,dg);
}
    int minimumTotal(vector<vector<int>>& arr) {
        //vector<vector<int>>dp(arr.size(),vector<int>(arr[arr.size()-1].size(),-1));
    //  return f(arr,0,0,dp); 
    int n = arr.size();
    vector<vector<int>> dp = arr;
             //dp[0][0]=arr[0][0];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=1e9,dg=1e9;
                d=arr[i][j]+dp[i+1][j];
                dg=arr[i][j]+ dp[i+1][j+1];
                dp[i][j]=min(d,dg);
                
            }
        } 
        return dp[0][0];
    }
};
```

```cpp

class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev = arr[n - 1];  // Initialize with bottom row

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(i + 1, 0);  // Only need i+1 elements
            for (int j = i; j >= 0; j--) {
                int down = arr[i][j] + prev[j];
                int diag = arr[i][j] + prev[j + 1];
                curr[j] = min(down, diag);
            }
            prev = curr;
        }

        return prev[0];
    }
};

```