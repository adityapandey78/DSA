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
        cout<<i;
    }
    cout<<endl;
    
    for (int i = 1; i <=m; i++)
    {
        //numbers
        int a=1;
        for (int k = 1; k <=m+1-i;k++)
        {
            cout<<a;
            a++;
        }
       
        //spaces
        for (int j = 1; j <=nsp; j++)
        {
            cout<<" ";
           a++;  //spaces ke andar a ko increse kr rhe hain coz hum chahte hain ki right side wala bridge thoda ek extra number se start ho
            
        }
        
        nsp+=2;
        

         //stars
        for (int k = 1; k <=m+1-i;k++)
        {
            cout<<a;
            a++;
        }
        
        
        cout<<endl;
    }
    

      
    return 0;
 }
 /* output without a++ in spaces 
123456789
1234 5678
123   456
12     34
1       2
SO humne a ko ek badha diya
*/