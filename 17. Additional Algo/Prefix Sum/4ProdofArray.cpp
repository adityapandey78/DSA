//leetcode 238
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>prep(n);
//         vector<int>suffp(n);
//        // vector<int>ans(n);
//         //prefix prod array (as per requirement here)
//         int p=nums[0];
//         prep[0]=1;

//         for(int i=1;i<n;i++){
//             prep[i]=p;
//             p*=nums[i];
//         }
//     //suffix prod array
        
//         p= nums[n-1];
//         suffp[n-1]=1;
//         for(int i=n-2;i>=0;i--){
//             suffp[i]=p;
//             p*=nums[i];
//         }
//         //ans array
//         for(int i=0;i<n;i++){
//            nums[i]=prep[i]*suffp[i];
//         }
//         return nums;
//     }
// };