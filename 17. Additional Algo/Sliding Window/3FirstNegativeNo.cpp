#include<iostream>
using namespace std;
int main(){
    int arr[]={2,3,4,4,-7,-1,4,-2,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"Entered array is:"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k=4; //window
    int prevIdx=-1; //the previous index
    int ans[n-k+1];
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            prevIdx=i;
            break;
        }
    }


    //base case if the first window does not  have any -ve index itself and updatung the ans array
    if(prevIdx==-1) ans[0]=1;
    else ans[0]=arr[prevIdx];

    int i=1;
    int j=k;
    while(j<n){
        prevIdx=-1;
        for (int x = i; x <=j; x++){
            if (arr[x]<0)
            {
                prevIdx=x;
                break;
            }
            
        }
        if(prevIdx!=-1) ans[i]=arr[prevIdx];
        else
        {
            ans[i]=1;
        }
        i++;
        j++;
    }
    cout<<"Required arrays is:"<<endl;
    for (int i = 0; i < n-k+1; i++)
    {
        cout<<ans[i]<<" ";
    }
    
return 0;
}