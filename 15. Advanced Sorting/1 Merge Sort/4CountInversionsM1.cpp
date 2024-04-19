//two elements of an array a, a[i] and a[j] form an inversion if a[i]<a[j] and i<j. Given an array of integers. find the inversion count in the array.
/*
n-> 0 1 2 3 4 
a-> 5 1 8 2 3
(5,1),(5,2),(5,3),(8,2),(8,3)
*/

//Method 1- Brute Force
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={5,1,3,0,4,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    for(int i=0;i<n-1;i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;
    int count=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i]>v[j]) count++;
        }
        
    }
    cout<<count;
return 0;
}

//TC- O(n2)
//S.C-O(1)