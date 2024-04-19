/* Write a program to print the matrix in wave form*/

#include <iostream>
using namespace std;
int main()
{

    int m;
    cout << "Enter the number of rows:";
    cin >> m;
    int n;
    cout << "Enter the number of columns:";
    cin >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // print array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout<<endl;
    //wave print
    for (int i = 0; i <=m-1; i++)
    {
       if (i%2==0)
       {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";

        }
        
       }
       else{
        for (int  j =n; j >=0; j--)
        {
            cout<<arr[i][j]<<" ";
        }
        
       }
       cout<<endl;
        
        
    }

    
    return 0;
}