//with using the sliding windows algorithm
#include<iostream>
using namespace std;
int main(){
int arr[]={7,1,2,5,8,4,9,3,6};
int n =sizeof(arr)/sizeof(arr[0]);
 int k=4;
 int maxSum= INT16_MIN;
 int maxIdx=0;
 int sum=0;
 //us STATRTING window ka sum nikal liya
 for (int i = 0; i < k; i++)
 {
    sum+=arr[i];
 }
 maxSum=sum;

 //sliding window
 int i=1;
 int j=k;
 while(j<n){
    sum=sum+arr[j]-arr[i-1];
    if (maxSum<sum)
    {
        maxSum=sum;
        maxIdx=i;
    }
    i++;j++;
    
 }
 cout<<maxSum<<" "<<maxIdx;
 

return 0;
}