// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
//Brute force approach 
//worst tiem complexity
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={3,1,2,7,4,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //: Using the trick (Pop, Ans, Push )
    //Next greater element array 
    int nge[n];
    nge[n-1]=-1;
    stack<int> st;
    st.push(arr[n-1]);
    //peeche se leke aaunga
    for (int i = n-2; i >=0; i--)
    {
        while(st.size()>0 &&  st.top()<=arr[i]){
            st.pop(); //!pop
        }
        //mark the ans in the nge array
        if (st.size()==0)nge[i]=-1;//!ans
        else nge[i]=st.top();
        //stack push kr do
        st.push(arr[i]); //!Push
    }
    

    
    cout<<"Next Greater:"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<nge[i]<<" ";
    }
return 0;
}