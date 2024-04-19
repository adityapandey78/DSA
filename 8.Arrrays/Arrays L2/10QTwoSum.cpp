/*Find the doublet in the array whose sum is equal to the given value x.  LeetCode 1 -(Two Sum)*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x;
    cout<<"Enter target: ";
    cin>>x;
    vector<int>v;
    int n;
    cout<<"Enter array size:";
    cin>>n;

    cout<<"Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        int q;
        cin>>q;
        v.push_back(q);
    }
    
    for (int i = 0; i <=v.size()-2; i++)
    {
        for (int j= i+1; j <=v.size(); j++)
        {
            if (v[i]+v[j]==x)
            {
                cout<<"("<<i<<","<<j<<")";

            }
            cout<<endl;
            
        }
        
    }
    

    return 0;
}