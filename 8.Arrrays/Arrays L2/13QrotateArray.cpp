/*rotate the array k times*/
#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &a){
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}
void reverseArray(int i, int j ,vector<int>&v){
while (i<=j)
{
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
    i++;
    j--;
}

}
int main(){
    
    vector<int>v;
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int q;
    for (int i = 0; i < n; i++)
    {
        cin>>q;
        v.push_back(q);
    }
    cout<<"Entered array is:";
    display(v);
    int k=k%n; //in case the k is greater than n
    cout<<"Enter the number of times you want to rotate:";
    cin>>k;

    //rotation
    reverseArray(0,n-k-1,v);
    reverseArray(n-k,n-1,v);
    reverseArray(0,n-1,v);
    display(v);

    return 0;
}