//largest subsequence with limited sum leetcode 2389 easy++
/*
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m);

        //sorting the nums array 
        sort(nums.begin(),nums.end());

        //now converting the nums array into the prefix sum
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];

        }
        //now searching and comparisons
        for(int i=0;i<m;i++){
            int Len=0;
            for(int j=0;j<n;j++){
                if(nums[j]>queries[i]) break;
                //else
            Len++;

            }
            
            ans[i]=Len;
            
        
        }
        return ans;

    }
};
*/