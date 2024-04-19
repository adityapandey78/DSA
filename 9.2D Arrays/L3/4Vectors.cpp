#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int> >v(3,vector<int>(4,2));
    //arr [3][4]
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<v.size()<<endl; //prints the number of row
    cout<<v[1].size();  //prints the number of coloumns

    return 0;
}