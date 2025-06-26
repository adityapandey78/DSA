```c++
// https://leetcode.com/problems/non-overlapping-intervals/

//This problem is similar to the meeting rooms problem, but here we need to find the minimum number of intervals to remove so that no two intervals overlap.

//Method 1: USingh the greedy approach and sorting the last end time of the intervals
bool cmp(vector<int>v1, vector<int>v2){
    return v1[1]<v2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime= intervals[0][1]; //checkingh the end time of the first interval
        //we will always keep the interval with the least end time
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEndTime){
                ans++;

            }else{
                lastEndTime=intervals[i][1]; //updating the end time of the last interval
            }
        }
        return ans;
    }
};
```
## Method 2: Using the greedy approach and sorting the first start time of the intervals

```c++
bool cmp(vector<int>v1, vector<int>v2){
    return v1[0]<v2[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEndTime= intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEndTime){
                ans++;
                lastEndTime=min(lastEndTime,intervals[i][1]);
            }else{
                lastEndTime=intervals[i][1];
            }
        }
        return ans;
    }
};
// This method is less efficient than Method 1, as it may lead to more removals.
```