#include<iostream>
#include<stack>
using namespace std;

void print(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> st;

    // Printing the original array
    cout << "OriginalArray     : ";
    print(arr, n);

    int nextSmallerElem[n], PrevSmallerElem[n];
    
    // Calculating the NSE first
    nextSmallerElem[n - 1] = -1;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--){
        while(st.size() > 0 && st.top() >= arr[i]){
            st.pop(); // Pop if greater
        }
        if(st.size() == 0) nextSmallerElem[i] = -1;
        else nextSmallerElem[i] = st.top();

        st.push(arr[i]);
    }

    cout << "NextSmallestElem  : ";
    print(nextSmallerElem, n);
    
    // Clearing the stack
    while(st.size() > 0) st.pop();

    // Previous smaller element
    PrevSmallerElem[0] = -1;
    st.push(arr[0]);

    for (int i = 1; i < n; i++){
        while(st.size() > 0 && st.top() >= arr[i]){
            st.pop(); // Pop if greater
        }
        if(st.size() == 0) PrevSmallerElem[i] = -1;
        else PrevSmallerElem[i] = st.top();

        st.push(arr[i]);
    }

    cout << "PrevSmallestElem  : ";
    print(PrevSmallerElem, n);
    
    return 0;
}
//in place of the previous elements we hacve to print that of previous indices and the ans would be as I have mentioned in the below code 

/*
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
         int n=arr.size();
         int nsi[n];
         stack<int>st;
         nsi[n-1]=n;
         st.push(n-1);
         for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0)nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
         }

        int psi[n];
        stack<int>gt;
        psi[0]=-1;
        gt.push(0);
        for(int i=1;i<n;i++){
            while(gt.size()>0&& arr[gt.top()]>=arr[i]) gt.pop();
            if(gt.size()==0) psi[i]=-1;
            else psi[i]=gt.top();
            gt.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int height=arr[i];
            int breadth= nsi[i]-psi[i]-1;
            int area= height*breadth;
            maxArea=max(maxArea,area);
        }
        return maxArea;

    }
};
 */