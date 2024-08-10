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
    //Previous  greater idx array 
    int pgi[n];
    pgi[0]=1;
    stack<int> st;
    st.push(0); //0 days push kr denge
    //aage se chalunga
    for (int i = 1; i<=n-1; i++)
    {
        while(st.size()>0 &&  arr[st.top()]<=arr[i]){
            st.pop(); //!pop
        }
        //mark the ans in the pgi array
        if (st.size()==0)pgi[i]=-1;//!ans
        else pgi[i]=st.top();
        pgi[i]=i-pgi[i];
        //stack push kr do
        st.push(i); //!Push
    }
    //now pgi holds the idxs of the Prev Greatest elems

    
    cout<<"Next Greater:"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<pgi[i]<<" ";
    }
return 0;
}