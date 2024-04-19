 #include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the no. of rows:";
    cin>>n;
    int m= n-1; // new line
    int nsp= 1;
    for (int i = 1; i <= 2*n-1; i++)
    {
        cout<<"*";
    }
    cout<<endl;
    
    for (int i = 1; i <=m; i++)
    {
        //stars
        for (int k = 1; k <=m+1-i;k++)
        {
            cout<<"*";
        }
       
        //spaces
        for (int j = 1; j <=nsp; j++)
        {
            cout<<" ";
        }
        
        nsp+=2;
        

         //stars
        for (int k = 1; k <=m+1-i;k++)
        {
            cout<<"*";
        }
        
        
        cout<<endl;
    }
    

      
    return 0;
 }