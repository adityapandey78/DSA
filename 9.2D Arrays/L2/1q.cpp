/* matrix multiplication*/

#include <iostream>
using namespace std;
int main()
{
    int m, n, p, q;
    cout << "Enter the values of m , n ,p, q"<<endl;
    cin >> m >> n >> p >> q;
    if (n == p)
    {
        cout << "Enter the first matrix:";
        int arr[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        // second matrix
        cout << "Enter the second matrix:";
        int brr[p][q];
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cin >> brr[i][j];
            }
        }
        //resultant matrix
        int res[m][q];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                res[i][j]=0; //to initialise the sum;
                for (int k = 0; k < p; k++)
                {
                    res[i][j] += arr[i][k] * brr[k][j];
                }
            }
        }
        // print
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Multiplication not possible.";

    return 0;
}