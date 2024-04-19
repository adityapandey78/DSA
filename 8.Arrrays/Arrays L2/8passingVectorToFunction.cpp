#include<iostream>
#include<vector>
using namespace std;
void change(vector<int>& a){ //&a to pass by address i.e value at that address nahi to kaam ni krega
        a[0]=100;
    }
int main(){
    
    
        vector<int>v;
        v.push_back(9);
        v.push_back(10);
        v.push_back(6);
        v.push_back(1);
        for (int i = 0; i < v.size(); i++)
        {
           cout<<v[i]<<" ";
        }
        cout<<endl;
        //passing for change
        //since it passed by value so
        change(v);
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";

        }
        
        
   
    return 0;
}