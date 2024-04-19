//maximum sum subarray of size K
//without using the sliding window algorithm
#include<iostream>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n =sizeof(arr)/sizeof(arr[0]);
    int k =3; //size of the window
    int maxSum= INT16_MIN;
    for (int i = 0; i <=n-k; i++)
    {
        int sum=0;
        for (int j = i; j < i+k; j++)
        {
            //i ki conditions hain ki har baar i se leke i+k size tk jaayega i.e. same length
            sum+=arr[j];
        }
        maxSum= max(maxSum,sum);
    }
    cout<<maxSum;
    

return 0;
}