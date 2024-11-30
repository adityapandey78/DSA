//Leetcode 239
/**

#include<vector>
#include<stack>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        // //Brute Force
        // vector<int>ans;
        // int n=arr.size();
        // for(int i=0;i<n-k+1;i++){
        //     int mx=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         mx=max(mx,arr[j]);
        //     }
        //     ans.push_back(mx);
        // }
        // return ans;

        //Code for next greter index
        int n= arr.size();
        int ngi[n]; //storing the next greater index
        stack<int>st;
        ngi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        vector<int> ans;

        for(int i=0;i<n-k+1;i++){ //n-k+1 hi windows banengi
            int mx=arr[i]; //starting at index se idhr se window start krenge
            int j=i;
            while(j<i+k){ //it means if the NGE is inside of the inside of the window
            mx=arr[j]; //pehle assign kr diya and
            j=ngi[j];//and fir j ko ngi assign kr diya 
            //and iske baad ye next loop ne check krega agar hoga toh
            }
            ans.push_back(mx);
        }
        return ans;
         
    }
};
 */