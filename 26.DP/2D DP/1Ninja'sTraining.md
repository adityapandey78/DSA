`https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003?leftPanelTabValue=PROBLEM`

## Memoization Solution
```cpp

int f(int day, int last, vector<vector<int>>&points, vector<vector<int>>&dp){
    // Base case: if we're at day 0, find the maximum points from tasks not equal to 'last'
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    
    // If already computed, return the memoized result
    if(dp[day][last]!=-1) return dp[day][last];
    
    // Try all tasks for current day, excluding the 'last' task performed
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            // Points for current task + maximum points from previous day with current task as 'last'
            int point=points[day][task]+f(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    
    // Store and return the result
    return dp[day][last]= maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    // DP table: dp[day][last_task] where last_task can be 0,1,2,3 (3 means no restriction)
    vector<vector<int>>dp(n,vector<int>(4,-1));
    // Start from last day with no previous task restriction (3 means any task can be chosen)
    return f(n-1,3,points,dp);
}
```

## Tabulation Solution
```cpp
int ninjaTraining(int n, vector<vector<int>> &points){
    // DP table: dp[day][last_task] where last_task can be 0,1,2,3
    vector<vector<int>>dp(n,vector<int>(4,-1));

    // Base case: Initialize day 0 - maximum points when specific tasks are restricted
    dp[0][0]=max(points[0][1],points[0][2]); // Can't do task 0, so choose max of task 1 or 2
    dp[0][1]=max(points[0][0],points[0][2]); // Can't do task 1, so choose max of task 0 or 2
    dp[0][2]=max(points[0][0],points[0][1]); // Can't do task 2, so choose max of task 0 or 1
    dp[0][3]=max(points[0][1],max(points[0][1],points[0][2])); // No restriction, choose max of all tasks

    // Fill the DP table for remaining days
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){ // For each possible last task performed
            dp[day][last]=0;

            // Try all tasks for current day
            for(int task=0;task<3;task++){
                if(task!=last){ // Can't perform the same task as previous day
                    // Current task points + maximum points from previous day with current task as restriction
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                } 
            }
        }

    }
    // Return maximum points on last day with no task restriction
    return dp[n-1][3];
}
```


## Space Optimized Tabulation Solution
```cpp
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> prev(4, 0); // prev[0..2] = last task, prev[3] = no restriction

    // Base case for day 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2])); // ? fixed

    // Loop for day 1 to n-1
    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }

    return prev[3]; // max points with no restriction on last task
}
```cpp
## Explanation
This problem is about maximizing the points a ninja can earn over `n` days by performing tasks, with the restriction that the same task cannot be performed on consecutive days. The solution involves dynamic programming techniques, specifically memoization, tabulation, and space optimization.
The ninja can choose from three tasks each day, and the points for each task are given in a 2D array `points` where `points[i][j]` represents the points earned for task `j` on day `i`. The ninja must ensure that the task performed on day `i` is different from the task performed on day `i-1`.
