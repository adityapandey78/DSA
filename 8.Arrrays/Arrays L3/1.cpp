/*
sort the array of 0 and 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sort01(vector<int> &a)
{
    int n = a.size();
    int no0 = 0;
    int noZ = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            noZ++;
        }
        else
            no0++;
    }
    // filling element
    for (int i = 0; i < n; i++)
    {
        if (i < noZ)
            a[i] = 0;
        else
            a[i] = 1;
    }
}
// for method 2
void sort01m2(vector<int> &b)
{
    int n = b.size();
    int j = 0;
    int k = n - 1;
    while (j < k)
    {
        if (b[j] == 0)
            j++;
        if (b[k] == 1)
            k--;
        if (j > k)
            break; // ye likha to not getting errors
        if (b[j] == 1 && b[k] == 0)
        {
            b[j] = 0;
            b[k] = 1;
            j++;
            k--;
        }
    }
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}