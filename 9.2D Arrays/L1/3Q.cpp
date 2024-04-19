/*you are given a sq matrix of size nxn. change this matrix into its transpose.*/
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

    //transpose in the same matrix
    for (int i = 0; i <=m-1; i++)
    {
        for (int  j=i+1 ; j <=m-1; j ++)//col
        {
           //swapping of i and j and j,i
           int temp=arr[i][j];
           arr[i][j]=arr[j][i];
           arr[j][i]=temp;
        }
        
    }
     // print array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}