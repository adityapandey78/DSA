/*spiral printing of matrix*/
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

    

    cout << endl;

    //spiral
    int minr=0, minc=0;
    int maxr=m-1,maxc=n-1;
    while (minr<=maxr &&minc<=maxc)
    {
       // right
       for (int i = minc; i <=maxc; i++)
       {
        cout<<arr[minr][i]<<" ";
       }
       minr++;
       if(minr>maxr|| minc>maxc) break;
       // down
       for (int j = minr; j <=maxr; j++)
       {
        cout<<arr[j][maxc]<<" ";
       }
       maxc--;
        if(minr>maxr|| minc>maxc) break;

       //left
       for (int j = maxc; j >=minc; j--)
       {
        cout<<arr[maxr][j]<<" ";
       }
       maxr--;
        if(minr>maxr|| minc>maxc) break;

       //up

       for (int i = maxr; i >= minr; i--)
       {
        cout<<arr[i][minc]<<" ";
       }
       minc++;

    }
    

}//if(minr>maxr|| minc>maxc) break; ye condition lgai hai kyuki extra print na ho elements 
//method 2- int total no of elements le lo, and fir jab bhi aap koi elemnent print kra rahe ho to count padha do, agart count exceed krega to loop break kr do