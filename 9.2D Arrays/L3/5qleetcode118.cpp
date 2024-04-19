#include<iostream>
#include<vector>
using namespace std;

//given an integer 'numrows' generate pascal triangle

/* 
1
11
121
1331
14641
*/
int main(){
    int m=7;
    vector<vector <int> > v;
    for (int i = 0; i < m; i++) // outermost
    {
        vector<int>a(i+1); //generating vector inside vector
        v.push_back(a);  //pushing back the vector
        //a(i+1) coz 0th row me mujhe  1 vector chaiye
    }

    //generate
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            if(j==0||j==i)
            v[i][j]=1;
            else v[i][j]=v[i-1][j]+v[i-1][j-1];
        }
        
    }
    //print

    for (int i = 0; i < m; i++)

    {
        
        for (int j = 0; j <=i; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    
    
    return 0;
}