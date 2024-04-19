/* 
1
23
456
78910
*/

//bahar ek a lunga and then hr iteration kew baad use ek increase kr dunga
#include<iostream>
using namespace std;
int main(){
    int n;
    int a=1;
    cout<<"Enter the no. of rows:";
    cin>>n;
     for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
           cout<<a<<" ";
           a++;
        }
        cout<<endl;

    }
    return 0;
}