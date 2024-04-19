/*coloumn wise print*/

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
    //coloumn wise print
    for (int j  = 0; j <=n-1; j++)
    {
        int i;
       if ( i%2==0)
       {
        for (int i = 0; i < m; i++)
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
       
        
        
    }

    
    return 0;
}