// //leetcode 39
// #include<iostream>
// #include<vector>
// using namespace std;
// void combination(vector<int>v,int arr[],int n,int target){
//     if(target==0){ //when target  becomes 0, then return
//         for(int i=0;i<v.size();i++){
//             cout<<v[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     if(target<0){
//         return;
//     }
//     //jitne elements honge arr me utni baar call lgengi and fir target check krenge kitni bachi hai that is why har call kw baad sbke ke liye target uske hisaabn se km ho raha hai
//     for(int i=0;i<n;i++){
//         v.push_back(arr[i]);
//         combination(v,arr,n,target-arr[i]); //
//         v.pop_back();//idhr pop back kr rhe hain ki ab 2 wala case ho jaane ke baad ye new array me staore ho, so jo 2 ke sath bana tha wo chalta hi rah eas we hae already called that but ab 3 wala ek new bane
//         ///without this pushaback ye {2,3} jesa bn jaata after after that {2},{3} ese alag alag ban rah ahai
//     }
// }
// int main(){
//     int arr[]={2,3,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     vector<int>v;
//     combination(v,arr,n,8);
//     return 0;
//}
//but isse problem hai ki idhr duplicate hi aa ri hain! jo ham eni chaiye

//so how to make it more optimised??
//to uske liye ek index pass klr dunga...taaki jb bhi calls lage to uske aage se lagein

//leetcode 39
#include<iostream>
#include<vector>
using namespace std;
void combination(vector<int>v,int arr[],int n,int target, int idx){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0){
        return;
    }
    
    for(int i=idx;i<n;i++){
        v.push_back(arr[i]);
        combination(v,arr,n,target-arr[i],i); //
        v.pop_back();
    }
}
int main(){
    int arr[]={2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    combination(v,arr,n,8,0);
    return 0;
}