/**
 class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes){
         int k=minutes;
         vector<int>&arr=customers;
         //isse arrray hi costumer ban jaata hai
         int maxLoss=0;
         int prevLoss=0;
         int n=arr.size();
         //us window ka loss nikal liya
        for(int i=0;i<k;i++){
            if(grumpy[i]==1)prevLoss+=arr[i];
        }
          maxLoss=prevLoss;
         int maxIdx=0;
         int i=1,j=k;
        while(j<n){
            int currLoss=prevLoss;
            if(grumpy[j]==1) currLoss+=arr[j];
            if(grumpy[i-1]==1) currLoss-=arr[i-1];
            if(maxLoss<currLoss){
                maxLoss=currLoss;
                maxIdx=i;
            }
            prevLoss= currLoss;
            i++;
            j++;
           
        }
        //filling 0s in the grumpy array window
        for(int i=maxIdx;i<maxIdx+k;i++){
            grumpy[i]=0;

        }
        //calculating the sum of satisfaction
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=arr[i];
        }
        return sum;
    }
};

*/