```c++
bool cmp(vector<int>v1, vector<int>v2){
    return v1[1]<v2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end(),cmp);
        int lastEndTime= points[0][1]; //checkingh the end time of the first interval
        //we will always keep the interval with the least end time
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=lastEndTime){
                ans++;

            }else{
                lastEndTime=points[i][1]; //updating the end time of the last interval
            }
        }
        //the ans is non-overlappingintervals
        // so total overlappingintervals = total - ans
        return points.size()-ans;
    }
};
```
// This problem is similar to the meeting rooms problem, but here we need to find the minimum number of arrows to burst all balloons.
// The greedy approach is used to sort the intervals based on their end times, and then we iterate through the intervals to count how many arrows are needed.
// The key is to always keep the interval with the least end time, which allows us to maximize the number of balloons that can be burst with a single arrow.
// The final answer is the total number of intervals minus the number of non-overlapping intervals found