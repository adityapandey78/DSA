/*write a program to print the transpose of the matric emtered by the user and stor eit in a new matrix
*/
#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the number of rows:";
    cin>>m;
    int n;
    cout<<"Enter the number of columns:";
    cin>>n;
     int arr[m][n];
     for (int  i = 0; i < m; i++)
     {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];

        }
        
     }
     
     cout<<endl;

     //print array
    for (int  i = 0; i < m; i++)
     {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
        
     }
     //storing transpose matrix
     int t[n][m];
     //this will also trabspose the matrix which is required
    //  for (int  i = 0; i < n; i++)
    //  {
    //     for (int j = 0; j < m; j++)
    //     {
    //         t[i][j]=arr[j][i];
    //         cout<<t[i][j];
    //     }
    //     cout<<endl;
    //  }
     
    //printing transpose
    //bs bahar j lga diya and andar i lga diya


     for (int  j = 0; j < n; j++)
     {
        for (int i = 0; i < m; i++)
        {
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
     }

     
    return 0;
}