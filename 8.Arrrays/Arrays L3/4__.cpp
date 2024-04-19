//leetcode 31 Next permutation of arrays
// note- if not possible then print the sorted order in ascending order. 
/*(1,2,3)->  123, ,132, 321, 312, 213, 231
in permutations ko ascending order me lga do to use sort krna hai
*/
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n=nums.size();
//         //finding pivot indx
//         int idx=-1;
//         for(int i=n-2;i>=0;i--){
//             if(nums[i]<nums[i+1]){
//                 idx=i;
//                 break;
//             }
//             if(idx==-1){
//                 reverse(nums.begin(),nums.end());
//                 return ;
//             }
//         }
//         //sorting reverse after pivot
//         reverse(nums.begin()+idx+1,nums.end());
//         //find the greatest just after idx
//         int j=-1;
//         for(int i=idx+1;i<n;i++){
//             if(nums[i]>nums[idx]){
//                 j=i;
//                 break;
//             }
//         }

//         //swapping idx and idx+1

//         int temp=nums[idx];
//         nums[idx]=nums[idx+1];
//         nums[idx+1]=temp;
//         return;
//     }
// };
