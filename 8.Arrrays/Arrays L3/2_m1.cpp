/* leetcode 75 search colors*/ 
//TWO PASS SOLUTION
#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &a){
    int n=a.size();
    int no0=0;
    int no1=0;
    int no2=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==0) no0++;
        else if(a[i]==1) no1++;
        else no2++;
    }

    //filling and sorting takes place
    for (int i = 0; i < n; i++)
    {
        if(i<no0) a[i]=0;
        else if(i<(no0+no1)) a[i]=1;
        else a[i]=2;
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