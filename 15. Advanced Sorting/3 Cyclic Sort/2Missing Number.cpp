//leetcode 268
//missing number
//Method 1
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         //n=5, 0 to 5 -> 0,1,3,4,5: 2 Missing
//         int n=nums.size();
//         vector<bool>check(n+1,false);
//         for(int i=0;i<n;i++){
//             int ele=nums[i];
//             check[ele]=true;
//         }
//         for(int i=0;i<=n;i++){
//             if(check[i]==false) return i;
//         }
//         return 100;
//     }
// };
/*
nums {9,6,4,2,3,5,7,0,1}
check{1,1,1,1,1,1,1,0,1}

*/

//method 2
//using cyclic sort without using extra space
  