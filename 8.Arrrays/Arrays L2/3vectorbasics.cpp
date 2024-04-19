#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(6); //pushback capacity ko double kr deta hai
    //v[1]=1; // it does not work here, gives error coz array to abhi bna bhi nahi hai and ise uska size bhi ni pta, so kese access krega 2nd element ye 
    v.push_back(1);
    v.push_back(9);
    cout<<v.capacity()<<" ";  //ye bta rha hai ki yhn tk push back hone ke baad 4 elements ki arrray bni hui hai
    v.push_back(10);
    cout<<v.size()<<endl; //yhn tk ki size bta rha ye




    //if you want to update//access
    cout<<v[0]<<" ";
    cout<<v[1]<<" ";
    cout<<v[2]<<" ";
    cout<<v[3]<<" ";
    return 0;
}