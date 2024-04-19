/*
Method 1
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();

        vector<int> run(n);
        run[0]=nums[0];
        for(int i=1;i<=n-1;i++){
            run[i]=run[i-1]+nums[i];
        }
        return run;
    }
};
*/