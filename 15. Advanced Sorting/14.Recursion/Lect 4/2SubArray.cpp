// solving using recursive approach
#include <iostream>
#include <vector>
using namespace std;

void subArray(vector<int> v, int arr[], int n, int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << endl;
        return;
    }
    // 1st case idhr append nahi krunga
    subArray(v, arr, n, idx + 1);

    // ab check krn ahai ki kise krn ahai append

    if (v.size() == 0||arr[idx-1]==v[v.size()-1])
    {   //agar vector khali hai tb push kr do 
        v.push_back(arr[idx]);
        subArray(v, arr, n, idx + 1);
    }
    // else if(arr[idx-1]==v[v.size()-1]){
    // v.push_back(arr[idx]);
    // subArray(v,arr,n,idx+1);
    // }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    subArray(v, arr, n, 0);
    return 0;
}