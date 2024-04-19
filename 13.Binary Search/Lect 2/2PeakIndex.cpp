/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        //finding the pivot element/index
        int pivot=-1; //smallest element
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<nums[mid+1] &&nums[mid]<nums[mid-1]){
                pivot=mid;
                break;
            }
            else if(nums[mid]>nums[mid+1] &&nums[mid]>nums[mid-1]){
                pivot=mid+1; //coz largest ele mil gya thga to uske aage ek kr diya
            }
            else if(nums[mid]>nums[hi]) lo=mid+1;
            else hi =mid-1;

        }  

        //after finding the pivot

        //checking the codnition element lie in which region
        //for the first region
        if(target>=nums[0] && target <=nums[pivot-1]){
            lo=0;
            hi=pivot-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;

            }
        }
        if(pivot==-1){//already sorted no rotation
            lo
        }
        else{
            //2nd region
            
            lo=pivot;
            hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;

            }
        }
        return -1;
        


    }
};*/