//Capacity to ship package within D Days
/*class Solution {
public:
bool check(int mid, vector<int>&weights, int days){
    //3,2,2,4,1,4
    int n=weights.size();
    int m=mid;
    int count =1;
    for(int i=0;i<n;i++){
        if(m>=weights[i]){  //agar mid weight se jyada hai
            m-=weights[i];  //weight jke array se ghata rha hai
        }else{
            count++;  //count badha de rhe hai ki days pta chle
            m=mid;
            m-=weights[i]; //jo weights chle gye unhe minus kr rhe hain
        }
    }
    if(count>days) return false;
    else return true;

}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int max=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            if(max<weights[i]) max=weights[i];
            sum+=weights[i];
        }
        int lo=max;
        int hi=sum;
        int minCapacity=sum;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,weights,days)){
                minCapacity=mid;
                hi=mid-1;
            }else{
                lo=mid+1;

            }
        }
        return minCapacity;

    }
   // return false;
    
};*/