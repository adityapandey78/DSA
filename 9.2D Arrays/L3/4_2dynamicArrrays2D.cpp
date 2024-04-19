
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the values of m,n";
    cin>>m>>n;
   // vector<vector <int> >arr;
    
    // for (int i = 0; i < m; i++)
    // {
    //     vector <int> brr;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int x;
    //         cin>>x;
    //        brr.push_back(x);
    //     }
    //     arr.push_back(brr);
    // }

    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    //printinfg the entered vector
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}

/* 
Reason why  not to initialise the arra in this case
vector<vector <int> >arr(m);
    
    for (int i = 0; i < m; i++)
    {
        vector <int> brr(n);
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
           brr.push_back(x);
        }
        arr.push_back(brr);
    }

    The issue in your code is that you are initializing arr with a size of m, but then you are using push_back to add rows to it. This results in m empty rows being added initially, and then you add another m rows with push_back, effectively doubling the size of your vector.

To fix this issue, you can either initialize the vector with the correct size and directly set values in it, as shown in previous examples, or you can remove the initial vector<int> brr(n); line and use push_back without initializing brr. Here's an updated version using push_back without initialization:

cpp
*/

/* 
If you want to assign the size earlier then you must use this 
vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
*/