#include<iostream>
/* WAP to check if a number is composite or not? */
using namespace std;
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n; //using boolean we can save the state
    bool flag=true;  // true = prime
    for (int i = 2; i <= n-1; i++)
    {
        if (n%i==0)
        {
            flag=false;
            break; //false means composite
        } 
    }
    if(flag==true) cout << n<<" is a prime number";
       else cout<<n<<" is a composite number";
    
    return 0;
}