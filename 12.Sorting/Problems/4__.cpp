/*
given an array, arr[] containing 'n' integers, the task is to find the range of integer (say k) such as after replacing each and every index of the arra by |ai-k|  where i belongs to [1,n], results in a sorted array. If no such integer exists that satisfies the above condition then return -1
*/
#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;
float max(float a,float b){
    if(a>=b) return a;
    else return b;
}
float min(float a,float b){
    if(a<b) return a;
    else return b;
}
int main(){
    int arr[]={5,3,10,3};
    int n=4;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    float kmin=(float)(INT16_MIN);
    float kmax=(float)(INT16_MAX);  
    bool flag=true;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>=arr[i+1]){ //kmin
            kmin= max(kmin,(arr[i]+arr[i+1])/2.0);
        }
        else{//kmax
            kmax=min(kmin,(arr[i]+arr[i+1]/2.0));
        }
        if (kmin>kmax)
        {
            flag=false;
            break;
        }
        
    }
    if(flag==false) cout<<-1;
    else if(kmin==kmax){
        if(kmin-(int)kmin==0){
            //kmin and kmax are integers
            cout<<"There is only one value of k: "<<kmin;
        }
        else cout<<-1;
    }
    else{
        if(kmin-(int)kmin>0){
            kmin=(int) kmin+1;
        }
    
        cout<<"Range of K is: ["<<kmin<<" , "<<kmax<<"]";
    }
      
    return 0;
}

