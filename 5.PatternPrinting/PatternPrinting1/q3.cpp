/*print the given pattern 1234
1234
1234*/

#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the no. of rows:";
    cin>>n;
    cout<<"Enter the no. of columns:";
    cin>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
           cout<<j;
        }
        cout<<endl;

    }
    

    return 0;
}