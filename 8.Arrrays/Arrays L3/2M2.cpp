//using Dutch Flag Algorithm
//3 pointer algorithm

/* leetcode 75 search colors*/ 
//ONE PASS SOLUTION
#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &a){
    int lo=0;
    int mid=0;
    int hi=a.size()-1;
    //1)mid ke baareme socho
    //2) 0 to low-1 -> 0, mid+1 to hi ->2
    //3 lo to mid ->1
    while (mid<=hi)
    {
        if(a[mid]==2){
        int temp=a[mid];
        a[mid]=a[hi];
        a[hi]=temp;
        hi--;}
        else if (a[mid]==0)
        {
        int temp=a[mid];
        a[mid]=a[lo];
        a[lo]=temp; 
        lo++; 
        mid++;
        }
        else mid++;
        
    }
    
    

}
int main(){
    
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    sort(v);


    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}