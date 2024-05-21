//print all increasing sub- sequences of  length kfrom first n natural numbers.
/*
 hint:
 Iske subsets bna lo and then jo required hai  use le lo nahi to chhod do!

 subseque k length ke array honge but wo order me honge
 and subsets to sreder me hi aate hain, thayt si why its very useful here
*/
#include<iostream>
#include<vector>
using namespace std;
void printsubset(int arr[],int n, int idx, vector<int> ans, int k){
    if(idx==n){
        if(ans.size()==k){
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(ans.size()+(n-idx)<k) return; //coz jb overall length  and bachi hui elements hi km hongi to kya faayda hai, chlao hi mat
    printsubset(arr,n,idx+1,ans,k);
    ans.push_back(arr[idx]);
    printsubset(arr,n,idx+1,ans,k);


}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    int k=3;
    printsubset(arr,n,0,v,k);
    return 0;
}